CSN-232 GROUP PROJECT
Cigarette Smoker Problem
Solved by:Jayesh Vyas(21114044)



PROBLEM STATEMENT:

Suppose a cigarette requires three ingredients, tobacco, paper and match. There are N number of chain smokers. 
They are of 3 types. Each has only one ingredient in infinite supply.
There is an agent who has infinite supply of all three ingredients.
To make a cigarette, the smoker who has tobacco (resp., paper and match) must have the other two ingredients paper and match (resp., tobacco and match, and tobacco and paper). 
The agent and smokers share a table. The agent randomly generates two ingredients and notifies the smoker who needs these two ingredients.
Once the ingredients are taken from the table, the agent supplies another two. On the other hand, each smoker waits for the agent's notification.
Once it is notified, the smoker picks up the ingredients, makes a cigarette, smokes for a while, and goes back to the table waiting for his next ingredients.


SOLUTION:

From the above problem statement, we came to find out that every smoker has to wait for other 2 ingredients to smoke.

To avoid deadlock & starvation for the above problem we have to add a restriction that the smoker will only pick the ingredient when both of the required ingredient are present on table 
 
The same type of smokers will remain in queue such that after a smoker smokes his cigarette he will leave the queue and join back the queue at last  to wait for his turn to come again. So, for the above problem we must maintain 3 queues as there are 3 types of smokers.

Now to implement the above solution we will need to assume an Intermediator which will pass the signal based on the available Ingredients in pair i.e., if paper & match is available then it will pass a signal so that Smoker with 3rd Ingredient which is Tobacco in this case can pick up the ingredients and smoke them, similarly for other cases.

So here we will be having 5 threads executing (3 types of smokers,1 Agent,1 Intermediator).

