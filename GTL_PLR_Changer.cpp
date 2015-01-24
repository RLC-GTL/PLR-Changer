//      GTL_PLR_Changer.cpp
//      
//      Copyright 2009 Ramon Hofer <ramonhofer@bluewin.ch>
//      
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//      
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//      
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	// Enough aruments?
	if (argc < 4)
		return -1;	// Too few arguments
	
	// Open input file
	ifstream iFile(argv[1]);
	if (!iFile.is_open())
		return -2;			// Couldn't open file
	if (iFile.peek() == EOF)
		return -3;			// Empty file
	
	// Variables
	string sLine;
	vector<string> vLines;
	vector<string>::iterator it;
	
	// Read file
	while (getline(iFile, sLine))
		vLines.push_back(sLine);
	iFile.close();
	
	// Modify lines
	for (int i = 2; i < argc-1; i=i+2)
	{
		for (it = vLines.begin(); it < vLines.end(); it++)
		{
			stringstream ssLine(*it);
			string sTitle;
			getline(ssLine, sTitle, '=');
			if (sTitle == argv[i])
			{
				string sValue;
				string sComment;
				getline(ssLine, sValue, '"');	// Empty between = and "
				getline(ssLine, sValue, '"');
				getline(ssLine, sComment);
				*it = sTitle + "=\"" + argv[i+1] + "\"" + sComment;
			}
		}
	}
	
	// Open output file
	ofstream oFile(argv[1]);
	if (!oFile.is_open())
		cout << "Error opening file\n";//return -4;			// Couldn't open file
	
	// Write file
	for (it = vLines.begin(); it < vLines.end(); it++)
		//~ cout << *it << endl;
		oFile << *it << endl;
	oFile.close();
	
	// No control whether each line was found or not!!!
	
	return 0;
}
