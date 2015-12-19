#include "DeleteLine.hpp"

void DeleteLine::execute(EditorModel& model)
{
	line = model.cursorLine();
	column = model.cursorColumn();

	model.deleteLine();
	s = model.getOldLine();
}

void DeleteLine::undo(EditorModel& model)
{
	model.moveCursor(line, column);
	model.undoDeleteLine(s);
}