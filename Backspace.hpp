#ifndef BACKSPACE_HPP
#define BACKSPACE_HPP

#include "Command.hpp"

class Backspace: public Command
{
public:
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);

private:
	char c;
	int line;
	int column;
};

#endif // BACKSPACE_HPP