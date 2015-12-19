// EditorModel.cpp
//
// ICS 45C Fall 2015
// Project #4: People Just Love to Play with Words
//
// Implementation of the EditorModel class

#include "EditorModel.hpp"
#include "EditorException.hpp"


EditorModel::EditorModel()
	: currentLine{1}, currentColumn{1}, text{""}, errorMsg{""}
{
}


int EditorModel::cursorLine() const
{
    return currentLine;
}


int EditorModel::cursorColumn() const
{
    return currentColumn;
}


int EditorModel::lineCount() const
{
    return text.size();
}


const std::string& EditorModel::line(int lineNumber) const
{
    return text.at(lineNumber-1);
}


const std::string& EditorModel::currentErrorMessage() const
{
    return errorMsg;
}


void EditorModel::setErrorMessage(const std::string& errorMessage)
{
	errorMsg = errorMessage;
}


void EditorModel::clearErrorMessage()
{
	errorMsg = "";
}

void EditorModel::moveCursor(int line, int column)
{
	currentLine = line;
	currentColumn = column;
}

void EditorModel::insertChar(char ch)
{
	text.at(currentLine-1) = text.at(currentLine-1).insert(currentColumn-1,1,ch);
}

void EditorModel::deleteFront()
{
	text.at(currentLine-2) += text.at(currentLine-1);
	text.erase(text.begin()+currentLine-1);
}

void EditorModel::deleteChar()
{
	text.at(currentLine-1) = text.at(currentLine-1).erase(currentColumn-2,1);
}

void EditorModel::newLine()
{
	std::string s = text.at(currentLine-1).substr(currentColumn-1);
	text.at(currentLine-1) = text.at(currentLine-1).substr(0,currentColumn-1);
	text.insert(text.begin()+currentLine, s);
}

void EditorModel::deleteLine()
{
	oldLine = text.at(currentLine-1);
	if (lineCount() != 1)
	{
		text.erase(text.begin()+currentLine-1);
		if (currentLine > 1)
		{
			currentLine--;
		}
		if (currentColumn > text.at(currentLine-1).length()+1)
		{
			currentColumn = text.at(currentLine-1).length()+1;
		}
	}
	else
	{
		text.erase(text.begin()+currentLine-1);
		text.push_back("");
		currentLine = 1;
		currentColumn = 1;
	}
}

void EditorModel::undoDeleteLine(std::string s)
{
	if (lineCount() == 1)
	{
		text.at(0) = s;
	}
	else
	{
		text.insert(text.begin()+currentLine-1, s);
	}
}

char EditorModel::getOldChar()
{
	return oldChar;
}

std::string EditorModel::getOldLine()
{
	return oldLine;
}

std::vector<std::string> EditorModel::getText()
{
	return text;
}

