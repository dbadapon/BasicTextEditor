#include "InsertChar.hpp"

InsertChar::InsertChar(char c)
	: c{c}
{
}

void InsertChar::execute(EditorModel& model)
{
	line = model.cursorLine();
	column = model.cursorColumn();

	model.insertChar(c);
	model.moveCursor(line, column+1);
}

void InsertChar::undo(EditorModel& model)
{
	model.deleteChar();
	model.moveCursor(line, column);
}