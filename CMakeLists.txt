cmake_minimum_required(VERSION 2.7)
project(correntropy_dict)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(run_new
        # Stochastic_Coordinate_Coding_master
        DictionaryGeneration.h
        LR.h
        # run.cpp
        SampleNormalization.h
        SCC.h
        run_new.cpp)
