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
    Parser/src/Node.cpp
    Parser/src/Node.h
    Parser/src/Parser.cpp
    Parser/src/Parser.h
    Parser/src/ProgramNode.cpp
    Parser/src/ProgramNode.h
    Parser/src/TestParser.cpp
        Parser/src/Visitor.cpp Parser/src/Visitor.h Parser/src/PrintingVisitor.cpp Parser/src/PrintingVisitor.h)


add_executable(AutomatTest ${SOURCE_FILES_BASE} ${SOURCE_FILES_AUTOMAT} Automat/src/TestAutomat.cpp)
add_executable(BufferTest ${SOURCE_FILES_BASE} ${SOURCE_FILES_BUFFER} Buffer/src/TestBuffer.cpp)
#//add_executable(SymboltableTest ${SOURCE_FILES_BASE} ${SOURCE_FILES_SYMBOLTABLE} Symboltable/src/TestSymboltable.cpp)

add_library(AutomatLib ${SOURCE_FILES_AUTOMAT})
add_library(BufferLib ${SOURCE_FILES_BUFFER})
add_library(SymboltableLib ${SOURCE_FILES_SYMBOLTABLE})
add_library(ScannerLib ${SOURCE_FILES_SCANNER})

add_executable(ScannerTest ${SOURCE_FILES_BASE} ${SOURCE_FILES_SCANNER} Scanner/src/TestScanner.cpp)
target_link_libraries (ScannerTest AutomatLib BufferLib SymboltableLib)

add_executable(ParserTest ${SOURCE_FILES_BASE} ${SOURCE_FILES_PARSER} Parser/src/TestParser.cpp)
target_link_libraries (ParserTest AutomatLib BufferLib SymboltableLib ScannerLib)