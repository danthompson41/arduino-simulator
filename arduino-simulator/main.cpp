/*
 * main.cpp
 *
 *  Created on: Feb 28, 2014
 *      Author: Dan
 */
#include <string>
#include <iostream>
#include <fstream>
#include <arduino-simulator.h>
#include <serial.h>

int main (int argc, char* argv[])
{
	// welcome
	std::cout << "\n\n*** Arduino Simulator ***\n";

	// command line args initial check
	if (argc <= 2)
	{
		std::cout << "\n* FORMAT: arduino-simulator.exe [filename.txt] [COMX]";
		return 1;
	}

	// Get Comport Number
	int iComport;
	if (sscanf (argv[2], "%i", &iComport) != 1)
	{
		std::cout << "ERROR: Comport must be an integer";
	}

	// Get Filename
	char filename[1024];
	strcpy(filename, argv[1]);

	std::cout << "  COMPort: COM" << iComport << std::endl;
	std::cout << "SleepFile: " << filename << std::endl;


	// prepare file reading
	std::ifstream sleepFileHdl (filename);
	// TODO: Error check


	// prepare serial
	CSerial serial;
	if (!serial.Open(iComport,9600))
	{
		std::cout << "ERROR: Could not open serial";
		return 0;
	}

	std::string line;
	while (std::getline (sleepFileHdl, line))
	{
		// serial functions require a char*, so convert string to array
		char charbuff[256];
		memcpy(charbuff, line.c_str(), line.size());

		// send string on serial
		int nBytesSent = serial.SendData(charbuff, strlen(charbuff));

		if (nBytesSent <= 0)
		{
			std::cout << "ERROR: Could not write data";
		}
		serial.SendData("\n", strlen("\n"));
	}

	return 1;
}
