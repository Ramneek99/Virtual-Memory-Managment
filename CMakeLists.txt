cmake_minimum_required(VERSION 3.19)
project(VMM)

set(CMAKE_CXX_STANDARD 14)

add_executable(VMM main.cpp Process.cpp Process.h Vmas.cpp Vmas.h PageTable.cpp PageTable.h Frame.cpp Frame.h Pager.cpp Pager.h Fifo.cpp Fifo.h Random.cpp Random.h Clock.cpp Clock.h NRU.cpp NRU.h Aging.cpp Aging.h WorkingSet.cpp WorkingSet.h)