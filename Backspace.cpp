#include "Backspace.hpp"
#include "EditorException.hpp"

void Backspace::execute(EditorModel& model)
{
	line = model.cursorLine();
	column = model.cursorColumn();

	if (line == 1 && column == 1)
	{
		throw EditorException("Already at beginning");
	}
	else if (column == 1)
	{
		int col = model.getText().at(line-2).length()+1;
		int l = line-1;
		model.deleteFront();
		model.moveCursor(l,col);
	}
	else
	{
		c = model.getText().at(line-1).at(column-2);
		model.deleteChar();
		model.moveCursor(line,column-1);
	}
}

void Backspace::undo(EditorModel& model)
{
	if (column != 1)
	{
		model.insertChar(c);
		model.moveCursor(line,column);
	}
	else
	{
		model.newLine();
	}
}