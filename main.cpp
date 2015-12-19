// main.cpp
//
// ICS 45C Fall 2015
// Project #4: People Just Love to Play with Words
//
// This is the main() function that launches BooEdit, along with some
// additional things that are fairly hairy-looking.  The goal here is
// to be sure that the program, whenever possible, crashes in a way that
// leaves the Linux shell window available and fully operative afterward.
// For example, I'm calling into functions from the C Standard Library
// that set up "signal handlers" that are called just before the program
// crashes due to problems like segmentation faults, so I can shut down
// the "ncurses" library used to handle things like cursor manipulation,
// and return the Linux shell to a usable state.
//
// DO NOT MAKE CHANGES TO THIS FILE

#include <csignal>
#include <sstream>
#include "BooEdit.hpp"
#include "BooEditLog.hpp"
#include "EditorModel.hpp"
#include "KeypressInteractionReader.hpp"
#include "NcursesEditorView.hpp"
#include "NcursesKeypressReader.hpp"



namespace
{
    BooEdit* booEdit = nullptr;
    EditorModel model;
    NcursesEditorView view{model};
    NcursesKeypressReader keypressReader;
    KeypressInteractionReader interactionReader{keypressReader};


    void logStarted(const std::string& programName)
    {
        std::ostringstream oss;
        oss << "Started " << programName;
        
        booEditLog(oss.str());
    }


    void logStopped(const std::string& programName)
    {
        std::ostringstream oss;
        oss << "Stopped " << programName;

        booEditLog(oss.str());
    }


    void startBooEdit()
    {
        booEdit = new BooEdit{model, view, interactionReader};
        booEdit->run();
    }


    void stopBooEdit()
    {
        if (booEdit != nullptr)
        {
            delete booEdit;
            booEdit = nullptr;
        }
    }


    int signals[6] { SIGTERM, SIGSEGV, SIGILL, SIGINT, SIGABRT, SIGFPE };


    void unregisterSignalHandlers()
    {
        for (int signal : signals)
        {
            std::signal(signal, SIG_DFL);
        }
    }


    void signalHandler(int signum)
    {
        unregisterSignalHandlers();
        stopBooEdit();
    }


    void registerSignalHandlers()
    {
        for (int signal : signals)
        {
            std::signal(signal, signalHandler);
        }
    }
}



int main(int argc, char** argv)
{
    std::string programName{argv[0]};

    try
    {
        logStarted(programName);

        registerSignalHandlers();
        startBooEdit();

        unregisterSignalHandlers();
        stopBooEdit();

        logStopped(programName);
    }
    catch (...)
    {
        unregisterSignalHandlers();
        stopBooEdit();

        logStopped(programName);

        throw;
    }

    return 0;
}

