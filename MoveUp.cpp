#include "MoveUp.hpp"
#include "EditorException.hpp"

void MoveUp::execute(EditorModel& model)
{
	line = model.cursorLine();
	column = model.cursorColumn();

	if (line == 1)
	{
		throw EditorException("Already at top");
	}
	else
	{
		unsigned int l = line-1;
		unsigned int c = column;
		if (column > model.getText().at(l-1).length()+1)
		{
			c = model.getText().at(l-1).length()+1;
		}
		model.moveCursor(l,c);
	}
}

void MoveUp::undo(EditorModel& model)
{
	model.moveCursor(line, column);
}