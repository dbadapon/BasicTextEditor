// InteractionReader.hpp
//
// ICS 45C Fall 2015
// Project #4: People Just Want to Play with Words
//
// An InteractionReader reads a user's interactions with BooEdit (e.g., by
// reading keypresses from the keyboard).  This is an abstract base class,
// so it's possible to swap in different implementations for different
// circumstances.  Two derived classes are provided already:
//
// * KeypressInteractionReader, which reads interactions by reading keypresses
//   from a KeypressReader.  (So, for example, if you combine a
//   KeypressInteractionReader with an NcursesKeypressReader, you'll be
//   reading keypresses from the keyboard using the "ncurses" library and
//   then determining which interactions they represent.)
// * MockInteractionReader, which is constructed with a vector of interactions
//   that you'd like it to return.  It dutifully returns these interactions,
//   in the order specified, rather than reading them from some kind of input
//   device.  This version is primarily useful for unit testing, so you'll
//   find it in your "gtest" directory.
//
// DO NOT MODIFY THIS FILE

#ifndef INTERACTIONREADER_HPP
#define INTERACTIONREADER_HPP

#include "Interaction.hpp"



class InteractionReader
{
public:
    virtual ~InteractionReader() = default;
    virtual Interaction nextInteraction() = 0;
};



#endif // INTERACTIONREADER_HPP

