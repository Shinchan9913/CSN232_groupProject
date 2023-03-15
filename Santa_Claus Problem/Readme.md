# Santa Claus Problem

Suppose Santa Claus sleeps in his shop at the North Pole and can only be wakened by either all nine reindeer being back from their vacation in the South Pacific or some of the elves are having difficulties making toys; to allow Santa to get some sleep, the elves can only wake him when three have problems. When three elves are having their problems solved, any other elves wishing to visit Santa must wait for those elves to return. If Santa wakes up to find three elves waiting at his shop’s door, along with the last reindeer returning from the tropics, Santa has decided that the elves can wait until after Christmas because it is more important to get his sleigh ready. (It is assumed that the reindeer do not want to leave the tropics, so they stay there until the last moment.) The previous reindeer to arrive must get Santa while the others wait in a warming hut before being harnessed to the sleigh.

Solution:

+ Semaphores  Sem_santa, Sem_reindeer, and Sem_elve  are defined to synchronize the activities of Santa, reindeer, and elves, respectively. 
+ A mutex is defined to ensure that shared variables are accessed atomically.
+ Three functions are defined to initialize the semaphores, Create(), _wait(), and _signal().
+ Three functions are defined for the three types of threads – Santa Claus (), Elf(), and Reindeer(). 
+ When the Santa thread wakes up and finds that both the reindeer and elves need attention, it processes the requests of the reindeer first.
+ Similarly, when the elves request Santa's help, Santa helps the elves only after attending to the requests of the reindeer.
+ When elves request Santa's help, they wait on a semaphore. Santa is signaled if three elves are waiting and proceed to help them.
+ This ensures that the elves are helped only when their number reaches three, and in the meantime, Santa attends to the requests of the reindeer.
+ Similarly, when the reindeer go to the desired number, Santa is signaled, and the reindeer wait on a semaphore until Santa finishes processing their request.
+ Overall, the code ensures that every thread has a fair chance to execute and does not get stuck waiting indefinitely. Therefore, it is considered starve-free & deadlock-free.

## Usage

To run the program, compile the code using a C compiler and run the resulting executable file.

```js
gcc Santa_Claus_Problem.c -o Santa_Claus_Problem -pthread
./Santa_Claus_Problem 
```
