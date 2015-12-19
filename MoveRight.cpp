#include "MoveRight.hpp"
#include "EditorException.hpp"

void MoveRight::execute(EditorModel& model)
{
	line = model.cursorLine();
	column = model.cursorColumn();

	if (column < model.getText().at(line-1).length()+1)
	{
		model.moveCursor(line, column+1);
	}
	else if (line < model.lineCount())
	{
		model.moveCursor(line+1, 1);
	}
	else
	{
		throw EditorException("Already at end");
	}
}

void MoveRight::undo(EditorModel& model)
{
	model.moveCursor(line, column);
}