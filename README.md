# OS LAB

This repository consists of programs done during the OS Lab in the sixth semester of BTech in Computer Science from CUSAT according to the 2019 Scheme syllabus.

To run Linux commands on Windows, turn on WSL(Windows Subsystem for Linux) from Apps and Features and install Ubuntu app from the Microsoft store. 
Detailed videos on how to do the same are available on YouTube. 

## Shell Programs

To create a file and run a shell program, first navigate to the working directory, then type the following commands:

touch filename.sh

chmod +x filename.sh

./filename.sh


Some programs may show carriage return errors since they are being typed in a windows system. To eliminate those errors, do either of the following:

1. Install dos2unix and do the additional step of converting before running the code.
   To install type the following command

   sudo apt install dos2unix

   After installing to run a program the steps will look like this:
   
   chmod +x filename.sh

   dos2unix filename.sh

   ./filename.sh

3. Write a command to remove carriage return errors
   In that case running a program will look something like this

   chmod +x filename.sh

   sed -i 's/\r//' filename.sh

   ./filename.sh


   ## System Call and Process Scheduling

   System Call and Process Scheduling programs can be run like the normal C programs

   to compile:
   gcc filename.c

   to run:
   ./a.out
