// InteractionProcessor.cpp
//
// ICS 45C Fall 2015
// Project #4: People Just Love to Play with Words
//
// Implementation of the InteractionProcessor class

#include "InteractionProcessor.hpp"
#include "EditorException.hpp"
#include "Interaction.hpp"

#include <vector>


// This function implements command execution, but does not handle "undo"
// and "redo"; you'll need to add that handling.

void InteractionProcessor::run()
{
    std::vector<Command*> undoCommands;
    std::vector<Command*> redoCommands;
    view.refresh();

    while (true)
    {
        Interaction interaction = interactionReader.nextInteraction();

        if (interaction.type() == InteractionType::quit)
        {
            std::for_each(undoCommands.begin(), undoCommands.end(), [](Command* c) {delete c;});
            std::for_each(redoCommands.begin(), redoCommands.end(), [](Command* c) {delete c;});
            break;
        }
        else if (interaction.type() == InteractionType::undo)
        {
            if (!undoCommands.empty())
            {
                undoCommands.back()->undo(model);
                redoCommands.push_back(undoCommands.back());
                undoCommands.pop_back();
                model.clearErrorMessage();
                view.refresh();
            }
        }
        else if (interaction.type() == InteractionType::redo)
        {
            if (!redoCommands.empty())
            {
                redoCommands.back()->execute(model);
                undoCommands.push_back(redoCommands.back());
                redoCommands.pop_back();
                model.clearErrorMessage();
                view.refresh();
            }
        }
        else if (interaction.type() == InteractionType::command)
        {
            Command* command = interaction.command();

            try
            {
                command->execute(model);
                model.clearErrorMessage();
                undoCommands.push_back(command);
            }
            catch (EditorException& e)
            {
                delete command;
                model.setErrorMessage(e.getReason());
            }
            view.refresh();

            // Note that you'll want to be more careful about when you delete
            // commands once you implement undo and redo.  For now, since
            // neither is implemented, I've just deleted it immediately
            // after executing it.  You'll need to wait to delete it until
            // you don't need it anymore.
            //delete command;
        }
    }
}

