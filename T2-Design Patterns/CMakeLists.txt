cmake_minimum_required(VERSION 3.16)
project(T2_Design_Patterns)

set(CMAKE_CXX_STANDARD 14)

add_executable(T2_Design_Patterns main.cpp
        "Adapter Pattern/Adapter"
        "Adapter Pattern/Blender"
        "Adapter Pattern/CRSocketInterface"
        "Adapter Pattern/EuropeanSocketInterface"
        "Adapter Pattern/Socket"

        "Observer Pattern/Bookshop"
        "Observer Pattern/Observer"
        "Observer Pattern/Product"
        "Observer Pattern/Subject"

        )