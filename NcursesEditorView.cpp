// NcursesEditorView.cpp
//
// ICS 45C Fall 2015
// Project #4: People Just Love to Play with Words
//
// DO NOT MODIFY THIS FILE
//
// There are some low-level gymnastics being done here, particularly in dealing
// with problems like resizing the terminal window and refreshing various areas
// of the view.  The resizing functionality, in particular, required the use of
// signal handlers from the C Standard Library.

#include <csignal>
#include <sstream>
#include <string>
#include <ncurses.h>
#include "NcursesEditorView.hpp"


NcursesEditorView::NcursesEditorView(EditorModel& model)
    : model{model}, topVisibleLine{1}, leftVisibleColumn{1}
{
}


namespace
{
    NcursesEditorView* registeredView = nullptr;


    void handleWindowSizeChange(int signum)
    {
        if (registeredView != nullptr)
        {
            endwin();
            ::refresh();
            registeredView->refresh();
        }
    }


    void registerSignalHandlers(NcursesEditorView* view)
    {
        registeredView = view;
        std::signal(SIGWINCH, handleWindowSizeChange);
    }


    void unregisterSignalHandlers()
    {
        std::signal(SIGWINCH, SIG_DFL);
        registeredView = nullptr;
    }
}


void NcursesEditorView::start()
{
    initscr();
    raw();
    noecho();
    keypad(stdscr, 1);
    registerSignalHandlers(this);
}


void NcursesEditorView::stop()
{
    unregisterSignalHandlers();
    echo();
    endwin();
}


namespace
{
    struct Coordinate
    {
        int x;
        int y;
    };


    struct Area
    {
        Coordinate tlxy;
        Coordinate brxy;
    };


    struct EditorAreas
    {
        Area lineNumberArea;
        Area statusBarArea;
        Area editorArea;
        Area scrollArea;
    };


    EditorAreas determineEditorAreas(int lineCount)
    {
        int xsize;
        int ysize;
        getmaxyx(stdscr, ysize, xsize);

        int lineNumberLength = std::to_string(lineCount).length();

        EditorAreas areas;

        areas.lineNumberArea.tlxy = {0, 0};
        areas.lineNumberArea.brxy = {lineNumberLength + 2, ysize - 3};

        areas.statusBarArea.tlxy = {lineNumberLength + 3, ysize - 2};
        areas.statusBarArea.brxy = {xsize - 1, ysize - 1};

        areas.editorArea.tlxy = {lineNumberLength + 3, 0};
        areas.editorArea.brxy = {xsize - 1, ysize - 3};

        areas.scrollArea.tlxy = {0, ysize - 2};
        areas.scrollArea.brxy = {lineNumberLength + 2, ysize - 1};

        return areas;
    }


    void redrawLineNumberArea(
        const Area& lineNumberArea, const EditorModel& model,
        int topVisibleLine)
    {
        int currentLine = topVisibleLine;

        for (int y = lineNumberArea.tlxy.y; y <= lineNumberArea.brxy.y; ++y)
        {
            mvaddch(y, lineNumberArea.brxy.x, '|');

            for (int x = lineNumberArea.tlxy.x; x <= lineNumberArea.brxy.x - 1; ++x)
            {
                mvaddch(y, x, ' ');
            }

            if (currentLine <= model.lineCount())
            {
                std::string lineNumber = std::to_string(currentLine);

                mvaddstr(
                    y, lineNumberArea.brxy.x - 1 - lineNumber.length(),
                    lineNumber.c_str());
            }

            ++currentLine;
        }
    }


    void redrawStatusBar(const Area& statusBarArea, const EditorModel& model)
    {
        for (int y = statusBarArea.tlxy.y; y <= statusBarArea.brxy.y; ++y)
        {
            for (int x = statusBarArea.tlxy.x; x <= statusBarArea.brxy.x; ++x)
            {
                if (y == statusBarArea.tlxy.y)
                {
                    mvaddch(y, x, '-');
                }
                else
                {
                    mvaddch(y, x, ' ');
                }
            }
        }

        std::ostringstream pos;
        pos << "Ln " << model.cursorLine() << " Col " << model.cursorColumn();

        std::string posStr = pos.str();

        mvaddstr(
            statusBarArea.brxy.y, statusBarArea.brxy.x - posStr.length(),
            posStr.c_str());

        if (model.currentErrorMessage().length() > 0)
        {
            int maxErrorMessageWidth =
                (statusBarArea.brxy.x - statusBarArea.tlxy.x + 1) - (posStr.length() + 4);

            mvaddstr(
                statusBarArea.brxy.y, statusBarArea.tlxy.x,
                model.currentErrorMessage().substr(0, maxErrorMessageWidth).c_str());
        }
    }


    void redrawScrollArea(const Area& scrollArea, int leftVisibleColumn)
    {
        for (int y = scrollArea.tlxy.y; y <= scrollArea.brxy.y; ++y)
        {
            if (y == scrollArea.brxy.y)
            {
                for (int x = scrollArea.tlxy.x; x <= scrollArea.brxy.x - 1; ++x)
                {
                    mvaddch(y, x, leftVisibleColumn == 1 ? ' ' : '<');
                }

                mvaddch(y, scrollArea.brxy.x, ' ');
            }
            else
            {
                for (int x = scrollArea.tlxy.x; x <= scrollArea.brxy.x; ++x)
                {
                    mvaddch(y, x, ' ');
                }
            }
        }
    }


    void forceCursorVisible(
        const Area& editorArea, const EditorModel& model,
        int& topVisibleLine, int& leftVisibleColumn)
    {
        int bottomVisibleLine = topVisibleLine + (editorArea.brxy.y - editorArea.tlxy.y);

        if (model.cursorLine() < topVisibleLine)
        {
            topVisibleLine = model.cursorLine();
        }
        else if (model.cursorLine() > bottomVisibleLine)
        {
            topVisibleLine = model.cursorLine() - (editorArea.brxy.y - editorArea.tlxy.y);
        }

        int rightVisibleColumn = leftVisibleColumn + (editorArea.brxy.x - editorArea.tlxy.x);

        if (model.cursorColumn() < leftVisibleColumn)
        {
            leftVisibleColumn = model.cursorColumn();
        }
        else if (model.cursorColumn() > rightVisibleColumn)
        {
            leftVisibleColumn = model.cursorColumn() - (editorArea.brxy.x - editorArea.tlxy.x);
        }
    }

    
    void placeText(
        const Area& editorArea, const EditorModel& model,
        int& topVisibleLine, int& leftVisibleColumn)
    {
        int currentLine = topVisibleLine;

        for (int y = editorArea.tlxy.y; y <= editorArea.brxy.y; ++y)
        {
            if (currentLine <= model.lineCount())
            {
                int visibleColumns = editorArea.brxy.x - editorArea.tlxy.x + 1;

                const std::string& lineText = model.line(currentLine);
            
                std::string displayText = leftVisibleColumn <= lineText.length()
                    ? lineText.substr(leftVisibleColumn - 1, visibleColumns)
                    : "";

                mvaddstr(y, editorArea.tlxy.x, displayText.c_str());

                for (int x = editorArea.tlxy.x + displayText.length(); x <= editorArea.brxy.x; ++x)
                {
                    mvaddch(y, x, ' ');
                }
            }
            else
            {
                for (int x = editorArea.tlxy.x; x <= editorArea.brxy.x; ++x)
                {
                    mvaddch(y, x, ' ');
                }
            }

            ++currentLine;
        }
    }


    void placeCursor(
        const Area& editorArea, const EditorModel& model,
        int topVisibleLine, int leftVisibleColumn)
    {
        int cursorRelativeLine = model.cursorLine() - topVisibleLine;
        int cursorRelativeColumn = model.cursorColumn() - leftVisibleColumn;

        move(cursorRelativeLine + editorArea.tlxy.y, cursorRelativeColumn + editorArea.tlxy.x);
    }
}


void NcursesEditorView::refresh()
{
    EditorAreas areas = determineEditorAreas(model.lineCount());

    forceCursorVisible(areas.editorArea, model, topVisibleLine, leftVisibleColumn);
    placeText(areas.editorArea, model, topVisibleLine, leftVisibleColumn);
    redrawLineNumberArea(areas.lineNumberArea, model, topVisibleLine);
    redrawStatusBar(areas.statusBarArea, model);
    redrawScrollArea(areas.scrollArea, leftVisibleColumn);
    placeCursor(areas.editorArea, model, topVisibleLine, leftVisibleColumn);

    ::refresh();
}

