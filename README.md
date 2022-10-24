# telemetry

Eagle low level telemetry project for recruiting.  
https://github.com/eagletrt/recruiting-sw/blob/master/telemetry/project_2/

## Usage
- project_2 executable located in ./bin
- \<path to telemetry folder\>/bin/project_2 will launch the program.
- You need a file "candump.log" inside the current working directory. It has to contain CAN messages separated by a new line.
- Each time you run the program a folder named "sessions_\<n\>" is created. Inside that you can find logged messages and statistics resulting from the last execution.
- The file ".session_count.txt" contains the number of the last sessions folder.
