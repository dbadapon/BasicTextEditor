// InteractionType.hpp
//
// ICS 45C Fall 2015
// Project #4: People Just Love to Play with Words
//
// An InteractionType specifies one kind of interaction that the user
// undertakes with BooEdit.
//
// DO NOT MODIFY THIS FILE

#ifndef INTERACTIONTYPE_HPP
#define INTERACTIONTYPE_HPP



// An "enum class" defines a type that has one of the constant values specified,
// but can't have any other values.  So, in this case, a variable of type
// InteractionType could have the value InteractionType::command,
// InteractionType::undo, and so on.

enum class InteractionType
{
    command,
    undo,
    redo,
    quit
};



#endif // INTERACTIONTYPE_HPP

