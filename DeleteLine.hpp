#ifndef DELETELINE_HPP
#define DELETELINE_HPP

#include "Command.hpp"

class DeleteLine: public Command
{
public:
    virtual void execute(EditorModel& model);
    virtual void undo(EditorModel& model);

private:
	int line;
	int column;
	std::string s;
};

#endif // DELETELINE_HPP