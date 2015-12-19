#include "MoveHome.hpp"
#include "EditorException.hpp"

void MoveHome::execute(EditorModel& model)
{
	line = model.cursorLine();
	column = model.cursorColumn();
	model.moveCursor(line, 1);
}

void MoveHome::undo(EditorModel& model)
{
	model.moveCursor(line, column);
}