cmake_minimum_required(VERSION 3.3)
project(sysCompiler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES_BASE
    String.cpp
    String.h
    Token.cpp
    Token.h
    TType.h
    )

set(SOURCE_FILES_AUTOMAT
    Automat/src/Automat.cpp
    Automat/src/Automat.h
    )

set(SOURCE_FILES_BUFFER
    Buffer/src/Buffer.cpp
    Buffer/src/Buffer.h
    Buffer/src/BufferHalf.cpp
    Buffer/src/BufferHalf.h
    Buffer/src/TestBuffer.cpp
    )

set(SOURCE_FILES_SYMBOLTABLE
    Symboltable/src/HashMap.cpp
    Symboltable/src/HashMap.h
    Symboltable/src/ILinkedList.h
    Symboltable/src/LinkedList.cpp
    Symboltable/src/LinkedList.h
    Symboltable/src/Symboltable.cpp
    Symboltable/src/Symboltable.h
    Symboltable/src/TestHashMap.cpp
    Symboltable/src/TestSymboltable.cpp
    Symboltable/src/TokenNode.cpp
    Symboltable/src/TokenNode.h
    )

set(SOURCE_FILES_SCANNER
    Scanner/src/DummyBuffer.cpp
    Scanner/src/DummyBuffer.h
    Scanner/src/Scanner.cpp
    Scanner/src/Scanner.h
    Scanner/src/TestScanner.cpp
)

set(SOURCE_FILES_PARSER
    Parser/src/ParseVariables/vProg.cpp
    Parser/src/ParseVariables/vProg.h
    Parser/src/Parser.cpp
    Parser/src/Parser.h
    Parser/src/ParseTreeObject.cpp
    Parser/src/ParseTreeObject.h
    Parser/src/ParseVariable.cpp
    Parser/src/ParseVariable.h
    Parser/src/TestParser.cpp
    )


add_executable(AutomatTest ${SOURCE_FILES_BASE} ${SOURCE_FILES_AUTOMAT} Automat/src/TestAutomat.cpp)
add_executable(BufferTest ${SOURCE_FILES_BASE} ${SOURCE_FILES_BUFFER} Buffer/src/TestBuffer.cpp)
add_executable(SymboltableTest ${SOURCE_FILES_BASE} ${SOURCE_FILES_SYMBOLTABLE} Symboltable/src/TestSymboltable.cpp)

add_library(AutomatLib ${SOURCE_FILES_AUTOMAT})
add_library(BufferLib ${SOURCE_FILES_BUFFER})
add_library(SymboltableLib ${SOURCE_FILES_SYMBOLTABLE})

add_executable(ScannerTest ${SOURCE_FILES_BASE} ${SOURCE_FILES_SCANNER} Scanner/src/TestScanner.cpp)
target_link_libraries (ScannerTest AutomatLib BufferLib SymboltableLib)