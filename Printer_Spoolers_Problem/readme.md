# Printer Spooler Problem
## PROBLEM STATEMENT:

Let us consider a case where multiple processes and a printer are present.
 Here all these processes are needed to print a document each. 
The printer is a slower device as compared to CPU and memory. 
One solution to tackle this case is to use a spooler, a program that maintains a directory containing a list of files the printer has to print.
Spooler hands over the file to the printer one by one.


## SOLUTION:
When a process is ready to be executed (here it is to print a document) it sends the name of the document into the spooler directory with the help of 2 variables, one to store the empty location in the spooler directory and the other is for the processes to use this location to place their file name in it. 
This method is having a problem when two processes run simultaneously, i.e., one of the files is lost from the spooler directory. 
To rectify this error we are introducing a new semaphore named mutex. This allows only one of the processes to get executed when two processes come to the spooler simultaneously.
The process that acquires mutex first gets to run while the other one is forced to wait. In this way, we can resolve the aforesaid problem.

