#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <time.h>
#include "employee.h"
#include "heap.h"

#define MAX_EMPLOYEES 5

int main(int argc, char *argv[])
{
	// make array with size of MAX_EMPLOYEES
	Employee *e_list = malloc(MAX_EMPLOYEES * sizeof(Employee));
	
	//srand(time(NULL));	

	for (int i = 0; i < MAX_EMPLOYEES; i++){ // fill list
		Employee e;

		// user input
		printf("Name: ");
		scanf("%s", e.name);
		printf("Salary: ");
		scanf("%d", &e.salary);
		
		//e.salary = rand() % 300;
		//strcpy(e.name, "a");

		e_list[i] = e;
	}
	//printList(e_list, MAX_EMPLOYEES);

	heapSort(e_list, MAX_EMPLOYEES);
	printList(e_list, MAX_EMPLOYEES);

	return 0;
}
