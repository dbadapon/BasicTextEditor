// BooEdit.hpp
//
// ICS 45C Fall 2015
// Project #4: People Just Love to Play with Words
//
// The BooEdit class encapsulates a running instance of BooEdit.  Its
// constructor takes three parameters:
//
// * An EditorModel, which keeps track of the current state of the editor
//   (e.g., what text is on what lines, where the cursor is, etc.)
// * An EditorView, which visualizes that model
// * An InteractionReader, which is how BooEdit determines what to do next
//   (e.g., by waiting for the user to press a key on the keyboard)
//
// Note that, since EditorView and InteractionReader are abstract base
// classes, it's possible to create radically different instances of
// BooEdit by passing different kinds of EditorViews or InteractionReaders
// to its constructor.  For example, you could pass an EditorView that
// does nothing, if you wanted a version of BooEdit with no visible user
// interface; or you could pass an InteractionReader that reads its input
// from a file instead of from the keyboard.  (Importantly, we can make
// use of this to unit test BooEdit.)
//
// DO NOT MODIFY THIS FILE

#ifndef BOOEDIT_HPP
#define BOOEDIT_HPP

#include "EditorModel.hpp"
#include "EditorView.hpp"
#include "InteractionReader.hpp"



class BooEdit
{
public:
    BooEdit(
        EditorModel& model, EditorView& view,
        InteractionReader& interactionReader)
        : model{model}, view{view}, interactionReader{interactionReader}
    {
    }

    ~BooEdit();

    void run();

private:
    EditorModel& model;
    EditorView& view;
    InteractionReader& interactionReader;
};



#endif // BOOEDIT_HPP

