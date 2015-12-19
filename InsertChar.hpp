#ifndef INSERTCHAR_HPP
#define INSERTCHAR_HPP

#include "Command.hpp"

class InsertChar: public Command
{
public:
	InsertChar(char c);
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);

private:
	char c;
	int line;
	int column;
};

#endif // INSERTCHAR_HPP