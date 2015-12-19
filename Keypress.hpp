// Keypress.hpp
//
// ICS 45C Fall 2015
// Project #4: People Just Love to Play with Words
//
// A Keypress describes one key pressed on the keyboard.  Each keypress
// is described by what character the key corresponds to, along with an
// boolean value specifying whether the Ctrl key was down at the time
// or not.  (No other special keys on the keyboard are supported.)
//
// You may notice that this class has only a private constructor, which
// might seem like a strange design choice.  How do you create an object
// of a class with a private constructor?  What this means is that the
// only code capable of calling that constructor is code in the Keypress
// class.  However, you'll also notice that the Keypress class has two
// static methods, ctrl() and normal(), that create and return Keypress
// objects.  So if you want to create, say, a normal 'a' keypress
// (i.e., the key 'a' was pressed on the keyboard with Ctrl being down),
// you would write this:
//
//     Keypress::normal('a')
//
// DO NOT MODIFY THIS FILE

#ifndef KEYPRESS_HPP
#define KEYPRESS_HPP



class Keypress
{
public:
    static Keypress ctrl(char code) { return Keypress{code, true}; }
    static Keypress normal(char code) { return Keypress{code, false}; }

public:
    char code() const { return code_; }
    bool ctrl() const { return ctrl_; }

private:
    Keypress(char code, bool ctrl)
        : code_{code}, ctrl_{ctrl}
    {
    }

private:
    char code_;
    bool ctrl_;
};



#endif // KEYPRESS_HPP

