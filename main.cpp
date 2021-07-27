#include <iostream>
#include <fstream>
#include <vector>
#include <getopt.h>
#include "cstring"
#include "map"
#include "Process.h"
#include "list"
#include "PageTable.h"
#include "Frame.h"
#include "Pager.h"
#include "Fifo.h"
#include "Random.h"
#include "Clock.h"
#include "Aging.h"
#include "NRU.h"
#include "WorkingSet.h"

using namespace std;

fstream InputFile;
char tempStr[1024];
char *strPointer;
int LineCount = 0, maxFrame = 16, maxPages = 63;
int cxSwitch = 0, instCount = 0, processExit = 0, cost = 0, ofs = 0;
int index_ = 0;
string line, file;
string rfile;
string ln;
bool newLine = true, addProcess = true, commentCheck = true, clock_ = false, aging_= false, execute= true, nru_= false, workingSet_= false;
FrameManager fmanager;
vector<int> randvals;

list<Process *> processes;
vector<pair<char, int>> instructions;

Frame frame;
Frame * frame_ = new Frame();
pageTable ptee;
Pager *pager;

//list<int> sequencePages;


void readRFile() {
    InputFile.open(rfile, ios::in);
    int count;
    InputFile >> count;
    int tmp;
    for (int a = 0; a < count; a++) {
        InputFile >> tmp;
        randvals.push_back(tmp);
    }
    InputFile.close();
}

void readLine(fstream *InputFile, string *line, int *LineCount) {
    while (commentCheck) {
        fill_n(tempStr, sizeof tempStr, 0);
        getline(*InputFile, *line);
        if (InputFile->eof()) {
            fill_n(tempStr, sizeof tempStr, 0);
            return;
        }
        if (line->at(0) != '#') {
            commentCheck = false;
            while (line->empty()) {
                if (InputFile->eof()) {
                    fill_n(tempStr, sizeof tempStr, 0);
                    return;
                }
                getline(*InputFile, *line);
                (*LineCount)++;
            }
            line->copy(tempStr, line->size());
            (*LineCount)++;
        }
    }
    commentCheck = true;
}

char *getToken() {
    while (1) {
        int i = 0;
        if (newLine == true) {
            readLine(&InputFile, &line, &LineCount);
            if (strlen(tempStr) == 0) {
                return "";
            }
            strPointer = strtok(tempStr, " \t\n");
            if (strPointer == NULL) {
                newLine = true;
            } else {
                newLine = false;
                return strPointer;
            }

        } else {
            strPointer = strtok(NULL, " \t\n");
            if (strPointer != NULL) { // found a token
                return strPointer;
            } else {
                newLine = true;
            }
        }
    }
}

int readInt() {
    char *tok = getToken();
    if (strlen(tok) == 0) {
        return -1;
    }
    int value = atoi(tok);
    return value;
}

char *readSym() {
    char *tok = getToken();
    if (!isalpha(*tok)) {
        return tok;
    }
    return tok;
}

void addSpecifications() {
    int noOfProcess, noOfVmas, temp;
    char *temp2;
    InputFile.open(file, ios::in);
    while (!InputFile.eof()) {
        if (addProcess) {
            noOfProcess = readInt();
            for (int i = 0; i < noOfProcess; i++) {
                Process *proc = new Process();
                noOfVmas = readInt();
                for (int j = 0; j < noOfVmas; j++) {
                    Vmas *vmas = new Vmas();
                    proc->processId = i;
                    vmas->startVpage = readInt();
                    vmas->endVpage = readInt();
                    vmas->writeProtected = readInt();
                    vmas->fileMapped = readInt();
                    proc->vmas.push_back(vmas);
                }
                processes.push_back(proc);
            }
            addProcess = false;
        } else {
            temp2 = readSym();
            temp = readInt();
            if (temp != -1) {
                instructions.emplace_back(*temp2, temp);
            }
        }
    }
    InputFile.close();
}

Process *findCurrentRunningProcess(int value) {
    Process *currentRunningProcess = nullptr;
    for (const auto &process:processes) {
        if (process->processId == value) {
            currentRunningProcess = process;
            //cout<<"Process Id: "<< currentRunningProcess->processId<<endl;
        }
    }
    return currentRunningProcess;
}


Frame* clockHelper() {
    Frame *frame_;
    for (const auto &process:processes) {
        if (process->processId == pager->processToMapAgain()) {
            while (true) {
                if (process->pte[pager->pageToMapAgain()].refrenced) {
                    process->pte[pager->pageToMapAgain()].refrenced = 0;
                    frame_ = pager->selectVictimFrame();
                } else {
                    break;
                }
            }
        }
    }
    return frame_;
}

void printStatmentsAndCalculateCost(int condition, char key, int value, Process* current, Frame* frame1){
    ofstream outputFile("output.txt", ofstream::out | ofstream::app);
    switch (condition) {
        case 0:{
            cout << index_ << ": ==> " << key << " " << value << endl;
            outputFile << index_ << ": ==> " << key << " " << value << endl;
            break;
        }
        case 1:{
            current->segvs = current->segvs + 1;
            cost = cost + 340;
            cout << " SEGV" << endl;
            outputFile << " SEGV" << endl;
            break;
        }
        case 2:{
            Process* f_pros = findCurrentRunningProcess(pager->processToMapAgain());
            if (f_pros == nullptr){
                cout << "Cannot find process for " << frame1 << endl;
                outputFile << "Cannot find process for " << frame1 << endl;
            }
            f_pros->unmaps = f_pros->unmaps + 1;
            cost = cost + 400;
            //current->pte[pager->pageToMapAgain()].pageDout = 1;
            cout << " UNMAP " << pager->processToMapAgain() << ":" << pager->pageToMapAgain() << endl;
            outputFile << " UNMAP " << pager->processToMapAgain() << ":" << pager->pageToMapAgain() << endl;
            break;
        }
        case 3:{
            Process* f_pros = findCurrentRunningProcess(pager->processToMapAgain());
            if (f_pros == nullptr){
                cout << "Cannot find process for " << frame1 << endl;
                outputFile << "Cannot find process for " << frame1 << endl;
            }
            f_pros->outs = f_pros->outs + 1;
            cost = cost + 2700;
            cout << " OUT" << endl;
            outputFile << " OUT" << endl;
            break;
        }
        case 4:{
            Process* f_pros = findCurrentRunningProcess(pager->processToMapAgain());
            if (f_pros == nullptr){
                cout << "Cannot find process for " << frame1 << endl;
                outputFile << "Cannot find process for " << frame1 << endl;
            }
            f_pros->fouts = f_pros->fouts + 1;
            cost = cost + 2400;
            cout << " FOUT" << endl;
            outputFile << " FOUT" << endl;
            break;;
        }
        case 5:{
            current->fins = current->fins + 1;
            cost = cost + 2800;
            cout << " FIN" << endl;
            outputFile << " FIN" << endl;
            break;
        }
        case 6:{
            current->zeros = current->zeros + 1;
            cost = cost + 140;
            cout << " ZERO" << endl;
            outputFile << " ZERO" << endl;
            break;
        }
        case 7:{
            current->ins = current->ins + 1;
            cost = cost + 3100;
            cout << " IN" << endl;
            outputFile << " IN" << endl;
            break;
        }
        case 8:{
            cost = cost + 300;
            cout << " MAP " << fmanager.framePosition(frame1) << endl;
            outputFile << " MAP " << fmanager.framePosition(frame1) << endl;
            break;
        }
        case 9:{
            current->segprouts = current->segprouts + 1;
            cost = cost + 420;
            cout << " SEGPROT" << endl;
            outputFile << " SEGPROT" << endl;
            break;;
        }
    }
    outputFile.close();
}
void resetRefrenced(){
    for (int i = 0; i < maxFrames; i++)
    {
        Frame *current = fmanager.frameTable[i];
        for(const auto &process: processes){
            if(process->processId==current->pID){
                if(process->pte[current->vpage].valid){
                    process->pte[current->vpage].refrenced=0;
                }
            }
        }
    }
}

Frame * NruHelper(){
    int threshH = 49, lClass = 100;
    Frame *frame_= nullptr;
    Frame *current;
    for(int i=0; i<maxFrames; i++) {
        current = pager->selectVictimFrame();
        Process * temp = findCurrentRunningProcess(current->pID);
        int eClass = (2 * temp->pte[current->vpage].refrenced) + temp->pte[pager->pageToMapAgain()].modified;

        for(const auto& process:processes){
            if(pager->processToMapAgain()==process->processId){
                if(process->pte[pager->pageToMapAgain()].refrenced){
                    current->ageCounter=current->ageCounter | 0x80000000;
                }
                if(frame_== nullptr || eClass < lClass){
                    frame_=current;
                    lClass=eClass;
                }
                if(lClass==100)
                    break;
            }
        }
    }
    pager->process5=frame_->pID;
    pager->page5=frame_->vpage;
    pager->temp5=fmanager.framePosition(frame_)+1;
    if(instCount >= threshH){
        threshH=instCount+50;
        resetRefrenced();
    }
    return frame_;
}

Frame * agingHelper(){
    Frame *frame_= nullptr;
    Frame *current;
    for(int i=0; i<maxFrames; i++) {
        current = pager->selectVictimFrame();
        current->ageCounter=current->ageCounter >> 1;
        for(const auto& process:processes){
            if(pager->processToMapAgain()==process->processId){
                if(process->pte[pager->pageToMapAgain()].refrenced){
                    current->ageCounter=current->ageCounter | 0x80000000;
                }
                if(frame_== nullptr || current->ageCounter < frame_->ageCounter){
                    frame_=current;
                }
            }
        }
    }
    resetRefrenced();
    pager->process5=frame_->pID;
    pager->page5=frame_->vpage;
    pager->temp5=fmanager.framePosition(frame_)+1;
    return frame_;
}

Frame * workingSetHelper(){
    Frame *frame_= nullptr;
    Frame *current;
    for(int i=0; i<maxFrames; i++) {
        current = pager->selectVictimFrame();
        Process * temp = findCurrentRunningProcess(current->pID);
        int age = instCount - current->tStamp;
        Process * tempW = findCurrentRunningProcess(current->pID);

        if(tempW->pte[current->vpage].refrenced){
            current->tStamp = instCount;
            tempW->pte[current->vpage].refrenced = 0;
            if (frame_ == nullptr)
            {
                frame_ = current;
            }
        } else {
            if (age >= 50)
            {
                frame_ = current;
                break;
            }
            else
            {
                if (frame_ == nullptr || current->tStamp < frame_->tStamp)
                {
                    frame_ = current;
                }
            }
        }
    }
    pager->process5=frame_->pID;
    pager->page5=frame_->vpage;
    pager->temp5=fmanager.framePosition(frame_)+1;
    return frame_;
}

void simulation() {
    addSpecifications();
    Process *currentRunningProcess;
    int num_inst = 0;
    for (const auto&[key, value]: instructions) {
        if (key == 'c') {
            cxSwitch = cxSwitch + 1;
            cost = cost + 130;
            currentRunningProcess = findCurrentRunningProcess(value);
            printStatmentsAndCalculateCost(0,key,value,currentRunningProcess,frame_);
        } else if (key == 'e') {
            int fileMappedBit=0;
            processExit = processExit + 1;
            cost = cost + 1250;
            ofstream outputFile("output.txt", ofstream::out | ofstream::app);
            printStatmentsAndCalculateCost(0,key,value,currentRunningProcess,frame_);
            cout << "EXIT current process "<<value<<endl;
            outputFile << "EXIT current process "<<value<<endl;
            for(const auto &process:processes) {
                if(process->processId==value){
                for (int i = 0; i < maxPages; i++) {
                        if(process->pte[i].valid) {
                            for (const auto &vmass:process->vmas) {
                                if (vmass->startVpage <= fmanager.frameTable[process->pte[i].noOfFrames]->vpage &&
                                    vmass->endVpage >= fmanager.frameTable[process->pte[i].noOfFrames]->vpage) {
                                    fileMappedBit = vmass->fileMapped;
                                }
                            }
                            cout << " UNMAP " << process->processId << ":" << fmanager.frameTable[process->pte[i].noOfFrames]->vpage << endl;
//                        if(fmanager.frameTable[i]->pID==process->processId) {
                            outputFile << " UNMAP " << process->processId << ":" << fmanager.frameTable[process->pte[i].noOfFrames]->vpage << endl;
//                            fmanager.frameTable[process->pte[i].noOfFrames] = nullptr;
//                            fmanager.sequencePages.push_back(process->pte[i].noOfFrames);
                            if (process->pte[i].modified && fileMappedBit==1) {
                                process->pte[i].modified = 0;
                                process->fouts = process->fouts + 1;
                                cost = cost + 2400;
                                cout << " FOUT" << endl;
                                outputFile << " FOUT" << endl;
                            }
                            process->unmaps=process->unmaps+1;
                            cost = cost + 400;
                            process->pte[i].modified=0;
                            fmanager.frameTable[process->pte[i].noOfFrames] = nullptr;
                            //process->pte[i].noOfFrames=0;
                            fmanager.sequencePages.push_back(process->pte[i].noOfFrames);
                            process->pte[i].noOfFrames=0;
                        }
                    process->pte[i].valid=0;
                    process->pte[i].pageDout=0;
                    process->pte[i].refrenced=0;
                    }
                }
            }
            outputFile.close();
            //do something
        } else {
            execute= true;
            cost = cost + 1;
            printStatmentsAndCalculateCost(0,key,value,currentRunningProcess,frame_);
            int fileMappedBitCurrent = -1, writeProtectedCurrent;
            pageTable *pte_ = &currentRunningProcess->pte[value];
//            if (!pte_->valid) {
                for (const auto &vmass:currentRunningProcess->vmas) {
                    if (vmass->startVpage <= value && vmass->endVpage >= value) {
                        fileMappedBitCurrent = vmass->fileMapped;
                        writeProtectedCurrent = vmass->writeProtected;
                        break;
                    } else if (vmass->endVpage == maxPages) {
                        printStatmentsAndCalculateCost(1,key,value,currentRunningProcess,frame_); //SEGV
                        execute= false;
                    }
                }
//            }
            if (!pte_->valid && execute) {
                Frame *frameTemp = fmanager.getFrame();
                int fileMappedBit = -1;
                if (frameTemp == nullptr) {
                    if(aging_){
                        frameTemp= agingHelper();
                    } else if(nru_){
                        frameTemp = NruHelper();
                    } else if(workingSet_){
                        frameTemp =workingSetHelper();
                    } else {
                        frameTemp = pager->selectVictimFrame();
                    }
                    if (clock_) {
                        frameTemp=clockHelper();
                    }
                    printStatmentsAndCalculateCost(2,key,value,currentRunningProcess,frameTemp); //UNMAP
                    for (const auto &process:processes) {
                        if (process->processId == pager->processToMapAgain()) {
                            for (const auto &vmass:process->vmas) {
                                if (vmass->startVpage <= pager->pageToMapAgain() &&
                                    vmass->endVpage >= pager->pageToMapAgain()) {
                                    fileMappedBit = vmass->fileMapped;
                                }
                            }
                            process->pte[pager->pageToMapAgain()].valid = 0;
                            if (process->pte[pager->pageToMapAgain()].modified && fileMappedBit==0 ) {
                                process->pte[pager->pageToMapAgain()].modified = 0;
                                process->pte[pager->pageToMapAgain()].pageDout = 1;
                                printStatmentsAndCalculateCost(3,key,value,currentRunningProcess,frameTemp); //OUT
                            } else if (process->pte[pager->pageToMapAgain()].modified && fileMappedBit==1) {
                                process->pte[pager->pageToMapAgain()].modified = 0;
                                printStatmentsAndCalculateCost(4,key,value,currentRunningProcess,frameTemp); //FOUT
                            }
                        }
                    }
                }
                if (fileMappedBitCurrent==1) {
                    printStatmentsAndCalculateCost(5,key,value,currentRunningProcess,frameTemp); //FIN
                } else if (!pte_->pageDout && fileMappedBitCurrent==0) {
                    printStatmentsAndCalculateCost(6,key,value,currentRunningProcess,frameTemp); //ZERO
                } else if (pte_->pageDout && fileMappedBitCurrent==0) {
                    printStatmentsAndCalculateCost(7,key,value,currentRunningProcess,frameTemp); //INS
                }
                frameTemp->pID = currentRunningProcess->processId;
                frameTemp->vpage = value;
                currentRunningProcess->maps = currentRunningProcess->maps + 1;
                currentRunningProcess->pte[value].noOfFrames = fmanager.framePosition(frameTemp);
                printStatmentsAndCalculateCost(8,key,value,currentRunningProcess,frameTemp);
                currentRunningProcess->pte[value].valid = 1;
//                currentRunningProcess->pte[value].refrenced = 1;
            }
            if(execute) {
                currentRunningProcess->pte[value].refrenced = 1;
                if (key == 'w') {
                    if (writeProtectedCurrent == 1) {
                        printStatmentsAndCalculateCost(9, key, value, currentRunningProcess, frame_);
                    } else {
                        currentRunningProcess->pte[value].modified = 1;
                    }
                }
            }
        }
        index_++;
    }
}

void inspectFrameTable() {
    ofstream outputFile("output.txt", ofstream::out | ofstream::app);
    cout << "FT: ";
    outputFile << "FT: ";
    for (const auto &frames: fmanager.frameTable) {
        if (frames == NULL) {
            cout << "* ";
            outputFile <<  "* ";
        } else {
            cout << frames->pID << ":" << frames->vpage << " ";
            outputFile << frames->pID << ":" << frames->vpage << " ";
        }
    }
    cout << endl;
    outputFile << endl;
    outputFile.close();
}

void inspectProcesses() {
    char output[1000];
    ofstream outputFile("output.txt", ofstream::out | ofstream::app);
    for (const auto &process:processes) {
        printf("PROC[%d]: U=%d M=%d I=%d O=%d FI=%d FO=%d Z=%d SV=%d SP=%d\n",
               process->processId,
               process->unmaps, process->maps, process->ins, process->outs,
               process->fins, process->fouts, process->zeros,
               process->segvs, process->segprouts);
        sprintf(output, "PROC[%d]: U=%d M=%d I=%d O=%d FI=%d FO=%d Z=%d SV=%d SP=%d\n",
                process->processId,
                process->unmaps, process->maps, process->ins, process->outs,
                process->fins, process->fouts, process->zeros,
                process->segvs, process->segprouts);
        outputFile<<output;
    }
    outputFile.close();
}

void printCost() {
    char output[1000];
    ofstream outputFile("output.txt", ofstream::out | ofstream::app);
    instCount = instructions.size();
    printf("TOTALCOST %d %d %d %d %lu\n",
           instCount, cxSwitch, processExit, cost, sizeof(ptee));
    sprintf(output,"TOTALCOST %d %d %d %d %lu\n",
            instCount, cxSwitch, processExit, cost, sizeof(ptee));
    outputFile << output;
    outputFile.close();
}

void inspectPageTable() {
    char output[1000];
    ofstream outputFile("output.txt", ofstream::out | ofstream::app);
    int i = 0;
    for (const auto &process:processes) {
        i=0;
        printf("PT[%d]: ", process->processId);
        sprintf(output,"PT[%d]: ", process->processId);
        outputFile<<output;
        for (const auto &table:process->pte) {
            if (table.valid) {
                cout << i << ":";
                outputFile << i << ":";
                if (table.refrenced) {
                    cout << "R";
                    outputFile << "R";
                } else {
                    cout << "-";
                    outputFile << "-";
                }

                if (table.modified) {
                    cout << "M";
                    outputFile << "M";
                } else {
                    cout << "-";
                    outputFile << "-";
                }

                if (table.pageDout) {
                    cout << "S";
                    outputFile << "S";
                } else {
                    cout << "-";
                    outputFile << "-";
          }
            } else {
                if (table.pageDout) {
                    cout << "#";
                    outputFile << "#";
                } else {
                    cout << "*";
                    outputFile << "*";
                }
            }
            i++;
            cout << " ";
            outputFile << " ";
        }
        cout<<endl;
        outputFile<<endl;
    }
    outputFile.close();
//    cout << endl;
}
void takeArguments(int argc, char **argv){
    char *algoToUse;
    int options;
    char *OPFS;
    while ((options = getopt(argc, argv, "o:a:f:")) != -1)
    {
        switch (options)
        {
            case 'o': {
                OPFS = optarg;
                break;
            }
            case 'f': {
                int test = atoi(optarg);
                int maxFrames = test;
                fmanager.frameTable.resize(maxFrames);
                break;
            }
            case 'a': {
                algoToUse = optarg;
                string algo = algoToUse;
                if(algo.at(0)=='a'){
                    aging_= true;
                    pager = new Aging(&fmanager, maxFrames);

                } else if( algo.at(0)=='w'){
                    workingSet_= true;
                    pager = new WorkingSet(&fmanager, maxFrames);
                } else if(algo.at(0)=='e'){
                    nru_= true;
                    pager = new NRU(&fmanager, maxFrames);
                } else if(algo.at(0)=='f'){
                    pager = new Fifo(&fmanager);
                } else if(algo.at(0)=='c'){
                    clock_= true;
                    pager = new Clock(&fmanager, maxFrames);
                } else if(algo.at(0)=='r'){
                    pager = new Random(&fmanager,randvals, maxFrames);
                }
            }
        }
    }
}

int main(int argc, char **argv) {
//    maxFrames = 16;
    takeArguments(argc,argv);
//    file = "/Users/rimmyaulakh/CLionProjects/VMM/input.txt";
//    rfile = "/Users/rimmyaulakh/CLionProjects/VMM/rfile.txt";
    file = argv[optind];
    rfile=argv[optind + 1];
    readRFile();
    simulation();
    inspectPageTable();
    inspectFrameTable();
    inspectProcesses();
    printCost();
    return 0;
}
