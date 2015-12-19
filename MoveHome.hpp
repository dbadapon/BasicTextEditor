#ifndef MOVEHOME_HPP
#define MOVEHOME_HPP

#include "Command.hpp"

class MoveHome: public Command
{
public:
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);
private:
	int line;
	int column;
};

#endif // MOVEHOME_HPP