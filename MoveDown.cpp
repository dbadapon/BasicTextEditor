#include "MoveDown.hpp"
#include "EditorException.hpp"

void MoveDown::execute(EditorModel& model)
{
	line = model.cursorLine();
	column = model.cursorColumn();

	if (line == model.lineCount())
	{
		throw EditorException("Already at bottom");
	}
	else
	{
		unsigned int l = line+1;
		unsigned int c = column;
		if (column > model.getText().at(l-1).length()+1)
		{
			c = model.getText().at(l-1).length()+1;
		}
		model.moveCursor(l, c);
	}
}

void MoveDown::undo(EditorModel& model)
{
	model.moveCursor(line, column);
}