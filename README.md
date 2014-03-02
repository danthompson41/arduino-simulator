# Arduino Simulator
This program simulates the functionality of the Arduino hardware by writing sleep data over a COMPort. This enables developers to contribute to [Sleep Analyzer](https://github.com/hospital-sleep-tracker/live-sleep-analyzer) code without having an Arduino handy.

The compiled executable can by run by command line, and requires the slp filename and COMPort number (Windows only, for now) to be passed by command line. For example, to send 'sleep-file-1.slp' over COMPort-9, you would run the executable as follows:
`arduino-simulator.exe sleep-file.slp 9`

In order to effectively use this, you will need two available virtual COMPorts linked together. One of them receives its input from this program. The other reads the data piped through. This implementation allows for a 1:1 replacement of the Arduino.

In order to spawn a two sided comport, I reccomend using this [Virtual Serial Port Simulator](http://www.hhdsoftware.com/free-virtual-serial-ports) on Windows

This code uses a simple [C++ Serial Driver](http://www.codeguru.com/cpp/i-n/network/serialcommunications/article.php/c2503/CSerial--A-C-Class-for-Serial-Communications.htm), with slight modifications to better suit our needs.