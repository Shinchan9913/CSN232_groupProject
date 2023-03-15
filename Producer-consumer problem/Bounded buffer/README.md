# Bounded Buffer Producer-Consumer Problem
This code implements the solution to the bounded buffer producer-consumer problem using semaphores and mutex locks in C programming language. The producer-consumer problem is a classic synchronization problem, in which there are two processes - producer and consumer - that share a common buffer. The producer produces data items and adds them to the buffer, and the consumer consumes these items from the buffer.

The problem arises when the producer produces items faster than the consumer can consume them, or the consumer consumes items faster than the producer can produce them. In such cases, the buffer can either overflow or underflow, causing synchronization issues.

To avoid these issues, semaphores are used in this code. A semaphore is a variable that is used to control access to a shared resource in a concurrent system. Semaphores allow multiple processes to access a shared resource concurrently while ensuring that only a limited number of processes can access it at any given time.

This code uses two semaphores - empty and full. empty semaphore is initialized with the buffer size and is used to represent the number of empty slots in the buffer. full semaphore is initialized with zero and is used to represent the number of filled slots in the buffer.

The code creates nine producer and nine consumer threads. Each producer thread generates a random item and inserts it into the buffer. The consumer threads remove items from the buffer and print them.

The buffer is implemented as an array of size BUFF_SIZE and is protected by a mutex lock. The in and out variables are used to keep track of the positions of the next item to be inserted and the next item to be removed, respectively.

The wait and signal functions are used to acquire and release semaphores. The wait function decrements the semaphore value and blocks the calling thread if the value becomes negative. The signal function increments the semaphore value and wakes up a blocked thread if there are any.

The main function initializes the semaphores and creates the producer and consumer threads. It waits for all threads to complete before destroying the semaphores and exiting the program.

Overall, the code implements a solution to the bounded buffer producer-consumer problem using semaphores and mutex locks to ensure synchronization between the producer and consumer threads.

## Usage
To run the program, compile the code using a C compiler and run the resulting executable file.

```
gcc bounded_buff.c -o bounded_buff -pthread
./bounded_buff.out
```
