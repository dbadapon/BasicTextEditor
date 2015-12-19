// BooEditLog.hpp
//
// ICS 45C Fall 2015
// Project #4: People Just Love to Play with Words
//
// Functionality for writing a log file, which can be used during the debugging
// of your program.  The problem, fundamentally, is that the typical debugging
// technique of writing output to the console is problematic in the context of
// trying to debug something like a text editor, which otherwise needs precise
// control over that console.  So it's best to write our debug output to a file
// instead.
//
// YOU SHOULD NOT NEED TO MODIFY THIS FILE

#ifndef BOOEDITLOG_HPP
#define BOOEDITLOG_HPP

#include <string>



// booEditLog() writes a single message to the "booedit.log" file, including
// a timestamp (e.g., "2015-11-24 15:58:15") at the beginning of that message.
// You can call this function anywhere you'd like, as a useful tool for letting
// you write debug output to a log file.
void booEditLog(const std::string& message);



#endif // BOOEDITLOG_HPP

