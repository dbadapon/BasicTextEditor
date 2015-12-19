// BooEditLog.cpp
//
// ICS 45C Fall 2015
// Project #4: People Just Love to Play with Words
//
// Implementation of the logging functionality, including formatting the
// current date/time and appending messages to a text file.
//
// YOU SHOULD NOT NEED TO MODIFY THIS FILE

#include <ctime>
#include <fstream>
#include "BooEditLog.hpp"


namespace
{
    const std::string LOG_FILENAME{"booedit.log"};


    std::string formatTimestamp()
    {
        std::time_t result = std::time(nullptr);
        char timestamp[20];
        std::strftime(timestamp, 20, "%F %T", std::localtime(&result));
        return timestamp;
    }
}


void booEditLog(const std::string& message)
{
    std::ofstream logFile{LOG_FILENAME, std::ios::app};

    if (logFile.is_open())
    {
        logFile << formatTimestamp() << "  " <<  message << std::endl;
    }
}

