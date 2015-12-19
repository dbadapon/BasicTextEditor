// KeypressReader.hpp
//
// ICS 45C Fall 2015
// Project #4: People Just Love to Play with Words
//
// A KeypressReader reads individual keypresses (e.g., from the keyboard).
// You'll notice that this is an abstract base class, which allows you to
// swap in a version (for unit testing purposes) that returns keypresses
// in some way other than reading them from the keyboard.  There are two
// derived classes of this class provided already:
//
// * NcursesKeypressReader, which reads keypresses from the keyboard using
//   a library called "ncurses"
// * MockKeypressReader, which you create by giving it a vector of keypresses
//   that you want it to generate; it then dutifully returns those keypresses
//   in that order, rather than reading them from the keyboard.  This is a
//   tool primarily useful for unit testing, so you'll find it in your
//   "gtest" directory.
//
// DO NOT MODIFY THIS FILE

#ifndef KEYPRESSREADER_HPP
#define KEYPRESSREADER_HPP

#include "Keypress.hpp"



class KeypressReader
{
public:
    virtual ~KeypressReader() = default;
    virtual Keypress nextKeypress() = 0;
};



#endif // KEYPRESSREADER_HPP

