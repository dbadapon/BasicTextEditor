#ifndef MOVEDOWN_HPP
#define MOVEDOWN_HPP

#include "Command.hpp"

class MoveDown: public Command
{
public:
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);
private:
	int line;
	int column;
};

#endif // MOVEDOWN_HPP