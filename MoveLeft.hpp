#ifndef MOVELEFT_HPP
#define MOVELEFT_HPP

#include "Command.hpp"

class MoveLeft: public Command
{
public:
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);
private:
	int line;
	int column;
};

#endif // MOVELEFT_HPP