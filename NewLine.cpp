#include "NewLine.hpp"

void NewLine::execute(EditorModel& model)
{
	line = model.cursorLine();
	column = model.cursorColumn();
	model.newLine();
	model.moveCursor(line+1, 1);
}

void NewLine::undo(EditorModel& model)
{
	model.deleteFront();
	model.moveCursor(line, column);
}