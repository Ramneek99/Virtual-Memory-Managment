main: Vmas.h Vmas.cpp PageTable.h PageTable.cpp Frame.h Frame.cpp Process.h Process.cpp Pager.h Pager.cpp Fifo.h Fifo.cpp Random.h Random.cpp Clock.h Clock.cpp NRU.h NRU.cpp Aging.h Aging.cpp WorkingSet.h WorkingSet.cpp main.cpp
	g++ -o main Vmas.cpp PageTable.cpp Frame.cpp Process.cpp Pager.cpp Fifo.cpp Random.cpp Clock.cpp NRU.cpp Aging.cpp WorkingSet.cpp main.cpp