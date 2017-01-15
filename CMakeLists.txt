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
        Symboltable/src/TokenLinkedList.cpp
        Symboltable/src/TokenLinkedList.h
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
        Parser/src/Node/ProgramNode.cpp
        Parser/src/Node/ProgramNode.h
    Parser/src/TestParser.cpp
        Parser/src/Visitor.cpp Parser/src/Visitor.h Parser/src/Node/DeclsNode.cpp Parser/src/Node/DeclsNode.h Parser/src/Node/StatementsNode.cpp Parser/src/Node/StatementsNode.h Parser/src/Node/Leaf.cpp Parser/src/Node/Leaf.h Parser/src/Node/DeclNode.cpp Parser/src/Node/DeclNode.h Parser/src/Node/EpsilonNode.cpp Parser/src/Node/EpsilonNode.h Parser/src/Node/ArrayNode.cpp Parser/src/Node/ArrayNode.h Parser/src/ParseTree.cpp Parser/src/ParseTree.h LinkedList.h Parser/src/Node/StatementNode.cpp Parser/src/Node/StatementNode.h Parser/src/Node/IndexNode.cpp Parser/src/Node/IndexNode.h Parser/src/Node/ExpNode.cpp Parser/src/Node/ExpNode.h Parser/src/Node/Exp2Node.cpp Parser/src/Node/Exp2Node.h Parser/src/Node/OpExpNode.cpp Parser/src/Node/OpExpNode.h Parser/src/Node/OpNode.cpp Parser/src/Node/OpNode.h Parser/src/TypeCheckVisitor.cpp Parser/src/TypeCheckVisitor.h)


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