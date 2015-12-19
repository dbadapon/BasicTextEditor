// NcursesKeypressReader.cpp
//
// ICS 45C Fall 2015
// Project #4: People Just Love to Play with Words
//
// Implementation of the NcursesKeypressReader class
//
// DO NOT MODIFY THIS FILE

#include <ncurses.h>
#include "NcursesKeypressReader.hpp"


namespace
{
    char ctrlLetter(int keypress)
    {
        if (keypress >= 1 && keypress <= 26)
        {
            return keypress + 'A' - 1;
        }
        else
        {
            return 0;
        }
    }
}


Keypress NcursesKeypressReader::nextKeypress()
{
    while (true)
    {
        int key = getch();

        char ctrlkey = ctrlLetter(key);

        if (ctrlkey != 0)
        {
            return Keypress::ctrl(ctrlkey);
        }

        if (key >= 32 && key < 127)
        {
            return Keypress::normal(static_cast<char>(key));
        }
    }
}

