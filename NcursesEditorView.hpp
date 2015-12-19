// NcursesEditorView.hpp
//
// ICS 45C Fall 2015
// Project #4: People Just Love to Play with Words
//
// A derived class of EditorView, which visualizes the current state of
// BooEdit using a library called "ncurses".
//
// DO NOT MODIFY THIS FILE

#ifndef NCURSESEDITORVIEW_HPP
#define NCURSESEDITORVIEW_HPP

#include "EditorModel.hpp"
#include "EditorView.hpp"



class NcursesEditorView : public EditorView
{
public:
    explicit NcursesEditorView(EditorModel& model);

    virtual void start();
    virtual void stop();
    virtual void refresh();

private:
    EditorModel& model;

    int topVisibleLine;
    int leftVisibleColumn;
};



#endif // NCURSESEDITORVIEW_HPP

