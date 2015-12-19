// Interaction.hpp
//
// ICS 45C Fall 2015
// Project #4: People Just Love to Play with Words
//
// An Interaction describes one interaction that the user undertakes
// with BooEdit.  There are four different kinds of interactions:
//
// * Commands, which attempt to affect some kind of change on the editor
// * Undo, which asks for the previous change to be undone
// * Redo, which asks for the most-recently-undone change to be redone
// * Quit, which asks for the editor to be stopped altogether
//
// A Command* is included for the case where InteractionType::command
// is specified type; otherwise, it will be nullptr.
//
// You may notice that this class has only a private constructor, which
// might seem like a strange design choice.  How do you create an object
// of a class with a private constructor?  What this means is that the
// only code capable of calling that constructor is code in the Keypress
// class.  However, you'll also notice that the Interaction class has
// a few static methods that create and return Interaction objects.  So
// if you want to create, say, an undo interaction, you would write this:
//
//     Interaction::undo()
//
// DO NOT MODIFY THIS FILE

#ifndef INTERACTION_HPP
#define INTERACTION_HPP

#include "Command.hpp"
#include "InteractionType.hpp"



class Interaction
{
public:
    static Interaction command(Command* command)
    {
        return Interaction{InteractionType::command, command};
    }

    static Interaction undo() { return Interaction{InteractionType::undo, nullptr}; }
    static Interaction redo() { return Interaction{InteractionType::redo, nullptr}; }
    static Interaction quit() { return Interaction{InteractionType::quit, nullptr}; }

public:
    InteractionType type() const { return type_; }
    Command* command() const { return command_; }

private:
    // A private constructor may seem like a strange thing to include in
    // a class, but I've done this so that the only way to create an
    // Interaction is using the static, public member functions defined
    // above.
    Interaction(InteractionType type, Command* command)
        : type_{type}, command_{command}
    {
    }

private:
    InteractionType type_;
    Command* command_;
};



#endif // INTERACTION_HPP

