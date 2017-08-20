#include <iostream>
#include "InputFile.h"
#include <sstream>
#include <fstream>

using namespace std;

bool InputFile::Read(std::string filename)
{
	char output[100];
	std::ifstream _contents;
	_contents.open(filename);
	if (_contents.fail()) {
		return false;
	}
	else
		while (!_contents.eof()) {
			_contents >> output;
			cout << output << endl;

		}
	_contents.close();
	return true;
}


std::string InputFile::GetContents()
{

	std::string c = _contents;
	return std::string();
}
