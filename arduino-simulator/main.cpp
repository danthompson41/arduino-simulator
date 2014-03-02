/*
 * main.cpp
 *
 *  Created on: Feb 28, 2014
 *      Author: Dan
 */
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
	char filename[256];
	strcpy(filename, argv[1]);

	std::cout << "  COMPort: COM" << iComport << std::endl;
	std::cout << "SleepFile: " << filename << std::endl;

	return 1;








	CSerial serial;
	if (!serial.Open(7,9600))
	{
		std::cout << "ERROR: Could not open serial";
		return 0;
	}

	char szMessage[] = "This is test data";

	int nBytesSent = serial.SendData(szMessage, strlen(szMessage));

	if (nBytesSent <= 0)
	{
		std::cout << "ERROR: Could not write data";
	}

	return 1;
}
