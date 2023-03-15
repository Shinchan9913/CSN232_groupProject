# Circular Buffer Producer-Consumer Problem
This program demonstrates the solution for the Circular Buffer Producer-Consumer Problem using pthreads and semaphores. In this problem, a fixed size buffer is shared between a producer and multiple consumers. The producer inserts items into the buffer, and the consumers remove items from the buffer.

The solution uses a circular buffer implementation, where the buffer wraps around at the end, allowing for efficient use of memory. It also uses pthreads for multi-threading and semaphores for synchronization.

## Implementation
The program creates two conditional variables, `pro` and `con`, and two integer variables, `in` and `out`, to keep track of the buffer indices. The pro variable is used by the producer to signal that an item has been added to the buffer, and the con variable is used by the consumers to signal that an item has been removed from the buffer.

The program also creates a mutex, mutex, which is used to protect the buffer and the indices from concurrent access by multiple threads.

The program then creates multiple producer and consumer threads, which use the producer and consumer functions to insert and remove items from the buffer.

The producer function generates a random item, locks the mutex, checks if the buffer is full, and waits on the pro variable if it is full. If there is space in the buffer, it inserts the item into the buffer, updates the index, signals the con variable to wake up a consumer thread, and unlocks the mutex.

The consumer function locks the mutex, checks if the buffer is empty, and waits on the con variable if it is empty. If there are items in the buffer, it removes an item from the buffer, updates the index, signals the pro variable to wake up a producer thread, and unlocks the mutex.

## Usage
To run the program, compile the code using a C compiler and run the resulting executable file.

```
gcc circular_buffer.c -o circular_buffer -pthread
./circular_buffer
```
The program will create 9 producer threads and 9 consumer threads. Each producer thread will insert a random item into the buffer, and each consumer thread will remove an item from the buffer. The program will print out messages indicating when an item is inserted or removed from the buffer.

## Conclusion
This program demonstrates a solution to the Circular Buffer Producer-Consumer Problem using pthreads and semaphores. The solution provides thread-safe access to a shared buffer, allowing for multiple producers and consumers to work concurrently. The program can be easily modified to handle different buffer sizes, different numbers of producers and consumers, and different item types.
