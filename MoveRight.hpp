#ifndef MOVERIGHT_HPP
#define MOVERIGHT_HPP

#include "Command.hpp"

class MoveRight: public Command
{
public:
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);
private:
	int line;
	int column;
};

#endif // MOVERIGHT_HPP