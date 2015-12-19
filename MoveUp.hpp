#ifndef MOVEUP_HPP
#define MOVEUP_HPP

#include "Command.hpp"

class MoveUp: public Command
{
public:
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);
private:
	int line;
	int column;
};

#endif // MOVEUP_HPP