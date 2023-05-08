cmake_minimum_required(VERSION 3.25)
project(AlgoritmosAFondo_EMPTY_v2_7_15)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/biblioteca)
include_directories(src/biblioteca/funciones)
include_directories(src/biblioteca/tads)
include_directories(src/biblioteca/tads/huffman)

add_executable(AlgoritmosAFondo_EMPTY_v2_7_15
        src/biblioteca/funciones/arrays.hpp
        src/biblioteca/funciones/files.hpp
        src/biblioteca/funciones/lists.hpp
        src/biblioteca/funciones/strings.hpp
        src/biblioteca/funciones/tokens.hpp
        src/biblioteca/tads/huffman/HuffmanSetup.hpp
        src/biblioteca/tads/huffman/Progress.hpp
        src/biblioteca/tads/Array.hpp
        src/biblioteca/tads/BitReader.hpp
        src/biblioteca/tads/BitWriter.hpp
        src/biblioteca/tads/Coll.hpp
        src/biblioteca/tads/List.hpp
        src/biblioteca/tads/Map.hpp
        src/biblioteca/tads/Queue.hpp
        src/biblioteca/tads/Stack.hpp
        src/principal.cpp)
