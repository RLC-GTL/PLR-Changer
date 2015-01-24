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

int main(int argc, char** argv)
{
	if (argc < 4)
		return -1;	// Too few arguments

	for (int i = 1; i < argc; i++)
		
	
	// Open file
	ifstream file("arg");//arg[1]);
	if (!file.is_open())
		return -1;			// Couldn't open file
	if (file.peek() == EOF)
		return -2;			// Empty file
	
	
	return 0;
}
