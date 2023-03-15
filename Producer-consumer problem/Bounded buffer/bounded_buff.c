#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#ifndef asysob_semaphore
#define asysob_semaphore

typedef void *semaphore_t;

semaphore_t create(int value);

void wait(semaphore_t semaphore);
void  signal(semaphore_t semaphore);

#endif

struct semaphore_state
{
	pthread_mutex_t mutex;
	int value;
	pthread_cond_t blocked_queue;
};

semaphore_t create(int value)
{
	struct semaphore_state *s = (struct semaphore_state *)malloc(sizeof(struct semaphore_state));
	int return_value= pthread_mutex_init(&s->mutex, NULL);
	s->value = value;
	return_value= pthread_cond_init(&s->blocked_queue, NULL);
	return (semaphore_t)s;
}

void wait(semaphore_t semaphore)
{
	struct semaphore_state *s = (struct semaphore_state *)semaphore;
	int return_value= pthread_mutex_lock(&s->mutex);
	s->value--;
	if (s->value < 0)
	{
		return_value= pthread_cond_wait(&s->blocked_queue, &s->mutex);
	}
	return_value= pthread_mutex_unlock(&s->mutex);
}

void signal(semaphore_t semaphore)
{
	struct semaphore_state *s = (struct semaphore_state *)semaphore;
	int return_value= pthread_mutex_lock(&s->mutex);
	s->value++;
	if (s->value <= 0)
	{
		return_value= pthread_cond_signal(&s->blocked_queue);
	}
	return_value= pthread_mutex_unlock(&s->mutex);
}

pthread_t *createThread(void *(*function)(void *), void *argument)
{
	pthread_t *pointer = malloc(sizeof(pthread_t));
	int return_value = pthread_create(pointer, NULL, function, argument);
	return pointer;
}

#define BUFF_SIZE 5

static semaphore_t empty;
static semaphore_t full;
static int in = 0;
static int out = 0;
int bounded_buff[BUFF_SIZE];
pthread_mutex_t mutex;


void *producer(void *arg)
{
    int item;
    item = rand(); 
    item = item % 100;
    wait(empty);
    pthread_mutex_lock(&mutex);
    bounded_buff[in] = item;
    printf("P%d Inserting item %d at   %d\n", *((int *)arg),item, in);
    in = (in + 1) % BUFF_SIZE;
    pthread_mutex_unlock(&mutex);
    signal(full);
}
void *consumer(void *arg)
{

    wait(full);
    pthread_mutex_lock(&mutex);
    int item = bounded_buff[out];
    printf("C%d Removing  item %d from %d\n",*((int *)arg), item, out);
    out = (out + 1) % BUFF_SIZE;
    pthread_mutex_unlock(&mutex);
    signal(empty);
}

int main()
{

    pthread_t *producer_threads[9], *consumer_threads[9];
    pthread_mutex_init(&mutex, NULL);
    // sem_init(&empty, 0, BUFF_SIZE);
    // sem_init(&full, 0, 0);
    empty = create(BUFF_SIZE);
    full = create(0);

    int arr[] = {1,2,3,4,5,6,7,8,9};
    for (int i = 0; i < 9; i++)
    {
        // pthread_create(&producer_threads[i], NULL, (void *)producer, (void *)&i);
        producer_threads[i] = createThread(producer, (void *)&arr[i]);
    }

    for (int i = 0; i < 9; i++)
    {
        // pthread_create(&consumer_threads[i], NULL, (void *)consumer, (void *)&i);
        consumer_threads[i] = createThread(consumer, (void *)&arr[i]);
    }

    for (int i = 0; i < 9; i++)
    {
        pthread_join(*producer_threads[i], NULL);
    }

    for (int i = 0; i < 9; i++)
    {
        pthread_join(*consumer_threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    // sem_destroy(&empty);
    // sem_destroy(&full);

    return 0;
}