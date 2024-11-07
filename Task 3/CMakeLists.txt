
cmake_minimum_required(VERSION 3.28)
project(OOP_Train)

set(CMAKE_CXX_STANDARD 17)

add_executable(OOP_Train main.cpp
        "Machine/CPU/Alu and Cu/Alu/Alu.h"
        "Machine/CPU/Alu and Cu/Alu/Alu.cpp"
        "Machine/CPU/Alu and Cu/CU/CU.h"
        "Machine/CPU/Alu and Cu/CU/CU.cpp"
        "Machine/CPU/CPU.h"
        Machine/CPU/CPU.cpp
        Machine/CPU/Register/Register.h
        Machine/CPU/Register/Register.cpp
        Machine/Memory/Memory.h
        Machine/Memory/Memory.cpp
        Machine/Machine.h
        Machine/Machine.cpp
        Machine/UI.cpp
)
