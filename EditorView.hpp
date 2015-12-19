// EditorView.hpp
//
// ICS 45C Fall 2015
// Project #4: People Just Love to Play with Words
//
// An EditorView visualizes the current state of BooEdit.  This is actually
// an abstract base class, so that this part of the program's functionality
// can be implemented differently.  Already provided are two derived classes
// that inherit from this base class:
//
// * NcursesEditorView, which visualizes the current state of BooEdit in
//   the Linux shell window using a library called "ncurses"
// * InvisibleEditorView, which has empty implementations of all of EditorView's
//   member functions.  This is useful for unit testing (so you can test BooEdit
//   without seeing its state displayed along the way), so you'll find this
//   class in your "gtest" directory.
//
// DO NOT MODIFY THIS FILE

#ifndef EDITORVIEW_HPP
#define EDITORVIEW_HPP

#include <string>



class EditorView
{
public:
    virtual ~EditorView() = default;

    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void refresh() = 0;
};



#endif // EDITORVIEW_HPP

