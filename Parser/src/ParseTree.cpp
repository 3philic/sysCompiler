//
// Created by Kishor Rana on 07/01/2017.
//

#include <assert.h>
#include "ParseTree.h"


ParseTree::ParseTree() {
}

ParseTree::~ParseTree() {
    // TODO Auto-generated destructor stub
}

bool ParseTree::parse(Parser &parser) {
    assert(false);	// overwrite in subclasses of ParseTree!
}

void ParseTree::accept(class Visitor &visitor) {
    assert(false);	// overwrite in subclasses of ParseTree!
}

void ParseTree::print() {
    assert(false);	// overwrite in subclasses of ParseTree!
}