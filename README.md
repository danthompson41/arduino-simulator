# Arduino Simulator
This program simulates the functionality of the Arduino hardware by writing sleep data over a COMPort. This enables developers to contribute to [Sleep Analyzer](https://github.com/hospital-sleep-tracker/live-sleep-analyzer) code without having an Arduino handy.

The compiled executable can by run by command line, and requires the slp filename and COMPort number (Windows only, for now) to be passed by command line. For example, to send 'sleep-file-1.slp' over COMPort-9, you would run the executable as follows:
`arduino-simulator.exe sleep-file.slp 9`