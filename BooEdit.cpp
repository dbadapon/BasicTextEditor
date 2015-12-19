// BooEdit.cpp
//
// ICS 45C Fall 2015
// Project #4: People Just Love to Play with Words
//
// Implementation of the BooEdit class
//
// DO NOT MODIFY THIS FILE

#include "BooEdit.hpp"
#include "InteractionProcessor.hpp"


void BooEdit::run()
{
    view.start();

    InteractionProcessor processor{model, view, interactionReader};
    processor.run();
}


BooEdit::~BooEdit()
{
    view.stop();
}

