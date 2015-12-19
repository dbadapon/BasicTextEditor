#include "MoveEnd.hpp"

void MoveEnd::execute(EditorModel& model)
{
	line = model.cursorLine();
	column = model.cursorColumn();
	unsigned int c = model.getText().at(line-1).length()+1;
	model.moveCursor(line, c);
}

void MoveEnd::undo(EditorModel& model)
{
	model.moveCursor(line, column);
}