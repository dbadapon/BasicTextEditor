#include "MoveLeft.hpp"
#include "EditorException.hpp"

void MoveLeft::execute(EditorModel& model)
{
	line = model.cursorLine();
	column = model.cursorColumn();

	if (column > 1)
	{
		model.moveCursor(line, column-1);
	}
	else if (line > 1)
	{
		unsigned int c = model.getText().at(line-2).length()+1;
		model.moveCursor(line-1, c);
	}
	else
	{
		throw EditorException("Already at beginning");
	}
}

void MoveLeft::undo(EditorModel& model)
{
	model.moveCursor(line, column);
}