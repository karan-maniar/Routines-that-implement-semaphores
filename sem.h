#include "threads.h"

struct Semaphore_t
{
	int count;
	TCB_t *sq;
};

Semaphore_t CreateSem(int InputValue)
{
	struct Semaphore_t *s;
	s = malloc(sizeof(Semaphore_t));
	s->count = InputValue;
	InitQ(&(s->sq));
	return s;
}

void P(Semaphore_t *sem)
{
	TCB_t *temp;
	ucontext_t parent;
	sem->count -= 1;
	if(sem->count < 0)
	{
		temp = DelQ(&(RunQ));
		if( RunQ != NULL )
			swapcontext(&(temp->context), &(RunQ->context));  // start the first thread
		AddQ(&(s->sq), temp);
	}
}

void V(Semaphore_t *sem)
{
	TCB_t *temp;
	sem->count += 1;
	if(sem->count <= 0)
	{
		temp = DelQ(&(sem->sq));
		AddQ(&RunQ, temp);
	}
	yield();
}