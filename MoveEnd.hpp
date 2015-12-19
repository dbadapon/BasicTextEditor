#ifndef MOVEEND_HPP
#define MOVEEND_HPP

#include "Command.hpp"

class MoveEnd: public Command
{
public:
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);
private:
	int line;
	int column;
};

#endif // MOVEEND_HPP