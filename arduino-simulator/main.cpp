/*
 * main.cpp
 *
 *  Created on: Feb 28, 2014
 *      Author: Dan
 */
#include <iostream>
#include <arduino-simulator.h>
#include <serial.h>

int main (void)
{
	CSerial serial;
	if (!serial.Open(7,9600))
	{
		std::cout << "ERROR: Could not open serial";
		return 0;
	}

	char szMessage[] = "This is test data";

	int nBytesSent = serial.SendData(szMessage, strlen(szMessage));


}
