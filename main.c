/*
Author: Karan Maniar
Email ID: karan.maniar@hotmail.com
*/

#include "threads.h"

void main()
{	
	struct TCB_t *temp;
	
	temp->a = 1;
	AddQ(&(RunQ), temp);
	
	temp->a = 2;
	AddQ(&(RunQ), temp);
	
	temp->a = 3;
	AddQ(&(RunQ), temp);
	
	InitQ(&RunQ);
	
	run();
}
