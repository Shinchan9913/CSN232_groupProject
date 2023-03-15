# Dining philosophers problem
## Problem Statement:
Five Philosophers are engaged in two activities: Thinking and Eating. Meals are taken communally on a table with five plates and five forks in a cyclic manner. Constraints and Condition for the problem: Every Philosopher needs two forks to eat. Every Philosopher may pick up the forks on the left or right but only one fork at once. Philosophers only eat when they have two forks. We have to design such a protocol i.e. pre and post-protocol which ensures that a philosopher only eats if he or she has two forks.

## Solution:
To simulate the problem, here the threads represent a philosopher. As a part of the solution, we have implemented the following functions: 
take_fork: This function is used by a philosopher to acquire two forks. When both the forks are free, the philosopher starts eating, otherwise, it waits.
put_fork: This function is used by a philosopher to release the forks it is holding. After releasing the forks, the philosopher changes his state to thinking and signals his neighbors to try to eat. 
test: This function is called by take_fork and checks if a philosopher can start eating. If the philosopher is hungry and his neighbors are not eating, he takes the forks and starts eating. 
In the main function we have created a thread for each philosopher and the control waits for them to finish. This solution ensures that each philosopher can eat only if two forks are available.
For the implementation of synchronization, we have created a user defined data structure named Philosopher which has the following elements:
Process id
Thread id
A variable which indicates whether the thread is waiting.
The control flows between the operations and at certain points in execution two philosophers are able to eat at one time.

