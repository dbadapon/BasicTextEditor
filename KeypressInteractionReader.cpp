// KeypressInteractionReader.cpp
//
// ICS 45C Fall 2015
// Project #4: People Just Want to Play with Words
//
// Implementation of the KeypressInteractionReader
//
// YOU WILL NEED TO IMPLEMENT SOME THINGS HERE

#include "KeypressInteractionReader.hpp"
#include "MoveRight.hpp"
#include "MoveLeft.hpp"
#include "InsertChar.hpp"
#include "NewLine.hpp"
#include "MoveUp.hpp"
#include "MoveDown.hpp"
#include "MoveHome.hpp"
#include "MoveEnd.hpp"
#include "Backspace.hpp"
#include "DeleteLine.hpp"


// You will need to update this member function to watch for the right
// keypresses and build the right kinds of Interactions as a result.
//
// The reason you'll need to implement things here is that you'll need
// to create Command objects, which you'll be declaring and defining
// yourself; they haven't been provided already.
//
// I've added handling for "quit" here, but you'll need to add the others.

Interaction KeypressInteractionReader::nextInteraction()
{
    while (true)
    {
        Keypress keypress = keypressReader.nextKeypress();

        if (keypress.ctrl())
        {
            // The user pressed a Ctrl key (e.g., Ctrl+X); react accordingly

            switch (keypress.code())
            {
            case 'X':
                return Interaction::quit();
            case 'Z':
            {
                return Interaction::undo();
            }
            case 'A':
            {
                return Interaction::redo();
            }
            case 'O':
            {
                Command* mr = new MoveRight;
                return Interaction{Interaction::command(mr)};
            }
            case 'U':
            {
                Command* ml = new MoveLeft;
                return Interaction{Interaction::command(ml)};
            }
            case 'I':
            {
                Command* mu = new MoveUp;
                return Interaction{Interaction::command(mu)};
            }
            case 'K':
            {
                Command* md = new MoveDown;
                return Interaction{Interaction::command(md)};
            }
            case 'Y':
            {
                Command* mh = new MoveHome;
                return Interaction{Interaction::command(mh)};
            }
            case 'P':
            {
                Command* me = new MoveEnd;
                return Interaction{Interaction::command(me)};
            }
            case 'J':
            {
                Command* nlj = new NewLine;
                return Interaction{Interaction::command(nlj)};
            }
            case 'M':
            {
                Command* nlm = new NewLine;
                return Interaction{Interaction::command(nlm)};
            }
            case 'H':
            {
                Command* bs = new Backspace;
                return Interaction{Interaction::command(bs)};
            }
            case 'D':
            {
                Command* dl = new DeleteLine;
                return Interaction{Interaction::command(dl)};
            }


            }
        }
        else
        {
            // The user pressed a normal key (e.g., 'h') without holding
            // down Ctrl; react accordingly
            Command* ic = new InsertChar(keypress.code());
            return Interaction{Interaction::command(ic)};
        }
    }
}

