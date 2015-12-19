// EditorException.hpp
//
// ICS 45C Fall 2015
// Project #4: People Just Love to Play with Words
//
// An EditorException is thrown by a Command object (or, quite often, by the
// EditorModel object that the Command object calls into) when an attempt to make
// some kind of change in the editor (e.g., moving the cursor down when
// already on the last line) fails.  EditorExceptions have a "reason" stored
// in them, which is a brief message describing the nature of the problem
// (e.g., "At bottom").

#ifndef EDITOREXCEPTION_HPP
#define EDITOREXCEPTION_HPP

#include <string>



class EditorException
{
public:
    explicit EditorException(const std::string& reason)
        : reason{reason}
    {
    }


    std::string getReason() const
    {
        return reason;
    }


private:
    std::string reason;
};



#endif // EDITOREXCEPTION_HPP

