# Infinite Buffer Producer Consumer Problem
This program solves the infinite buffer producer consumer problem using a linked list to implement an infinite buffer.

## Problem Statement
The producer-consumer problem involves two threads that share a common buffer (in this case, a linked list), where the producer thread generates data and inserts it into the buffer, and the consumer thread removes the data from the buffer. The problem arises when the buffer is of a finite size, and the producer produces data faster than the consumer can consume it, or when the consumer consumes data faster than the producer can produce it. This results in the buffer becoming either full or empty, and the threads being blocked.

In this program, we implement an infinite buffer, where the buffer can never become full or empty. The producer thread keeps adding data to the buffer without waiting for the consumer, and the consumer thread keeps consuming data from the buffer without waiting for the producer.

## Solution
The program uses two functions producer and consumer, which are executed by producer and consumer threads, respectively. The producer function generates a random number and inserts it into the buffer using the buff_insert function, while the consumer function removes an item from the buffer using the buff_remove function.

The program uses semaphores to ensure that the producer and consumer threads do not access the buffer at the same time. The program uses a binary semaphore called full to signal the availability of data in the buffer. The wait function is used to block the consumer thread until there is data available in the buffer, while the signal function is used to notify the consumer thread when data is added to the buffer.

The program creates 9 producer and 9 consumer threads using the createThread function, which creates a new thread and returns a pointer to it. The pthread_join function is used to wait for the threads to complete before the program terminates.

## Running the program
To compile and run the program, use the following commands:

```
gcc -o infinite_buff infinite_buff.c -pthread
./infinite_buff.out
```
## Conclusion
The infinite buffer producer consumer problem is a classic synchronization problem that arises in multi-threaded programming. The solution presented in this program uses semaphores to ensure that the producer and consumer threads access the buffer in a mutually exclusive manner. The program creates multiple threads to simulate a real-world scenario, where multiple producers and consumers are working concurrently.
