This repository consists of shell programs done during the OS Lab in the sixth semester of BTech in Computer Science from CUSAT according to the 2019 Scheme syllabus

To run linux commands on windows, turn on WSL from apps and features and install Ubuntu app from the Microsoft store. 
Detailed videos on how to do the same are available on YouTube. 

To create a file and run a program, first navigate to the working directory, then type the following commands:
touch filename.sh
chmod +x filename.sh
./filename.sh

Some programs may show carriage return errors since they are being typed in a windows system. To eliminate those errors, do either of the following:
1. install dos2unix and do the additional step of converting before running the code.
   to install type the following command

   sudo apt install dos2unix

   after installing to run a program the steps will look like this:
   
   chmod +x filename.sh
   dos2unix filename.sh
   ./filename.sh

2. write a command to remove carriage return errors
   in that case running a program will look something like this

   chmod +x filename.sh
   sed -i 's/\r//' filename.sh
   ./filename.sh
