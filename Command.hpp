// Command.hpp
//
// ICS 45C Fall 2015
// Project #4: People Just Love to Play with Words
//
// This header file declares the base class for commands that occur in BooEdit.
// Each different command -- moving the cursor, inserting a character, splitting
// or merging lines of text, etc. -- will be a different class derived from this
// one.
//
// Commands can do two things:
//
// * Be executed, which means that they make the appropriate changes to the
//   editor (e.g., if it's a command that moves the cursor down, the execute()
//   member function would make that change).
// * Be undone, which means that whatever change they made to the editor is
//   reversed (e.g., if it's a command that moves the cursor down, the undo()
//   member function would move the cursor back up).
//
// This means that Command objects have two overlapping jobs to do:
//
// * Know how to make the right kinds of changes to the editor.
// * Remember enough about what they did so they can undo their changes.
//   For example, a command that delete a character (because the user
//   pressed Ctrl+H) needs to remember the character that it deleted,
//   so that the character can be put back into the editor if the
//   command is undone.
//
// When the execute() or undo() member functions fail to do their job (e.g.,
// when moving the cursor down and you're already on the last line), they
// throw an EditorException, with the "reason" in that exception briefly
// describing why they failed (e.g., "At bottom").
//
// Write your individual command classes in separate header and source files;
// don't write them all in this file.  In general, we're sticking to the
// sensible design convention of keeping every class in a separate "module",
// so the class X is declared in the header file X.hpp and, if necessary,
// implemented in the source file X.cpp.

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "EditorModel.hpp"



class Command
{
public:
    virtual ~Command() = default;

    virtual void execute(EditorModel& model) = 0;
    virtual void undo(EditorModel& model) = 0;
};



#endif // COMMAND_HPP

