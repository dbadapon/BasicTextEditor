#ifndef NEWLINE_HPP
#define NEWLINE_HPP

#include "Command.hpp"

class NewLine: public Command
{
public:
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);
private:
	int line;
	int column;
};

#endif // NEWLINE_HPP