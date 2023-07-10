cmake_minimum_required(VERSION 2.7)
project(correntropy_dict)

set(CMAKE_CXX_STANDARD 14)

include_directories(./src)

add_executable(run_random
        src/DictionaryGeneration.h
        src/LR.h
        src/SampleNormalization.h
        src/SCC.h
        src/run_random.cpp)
