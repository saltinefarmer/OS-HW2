/*
 * heapsort.c
 *
 *  Created on: 1/27/24
 *      Author: Silver Lippert, David Chiu
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"

/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void heapSort(Employee *A, int n)
{
	// BuildHeap on the heap
	buildHeap(A, n);

	// TODO - while n > 0:
	while(n > 0){
		swap(&A[n-1], &A[0]); // swap sorted element with item at end of list
		n--; // decrement size to disinclude sorted item from further actions
		heapify(A, 0, n); // recurse
	}
}

/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void buildHeap(Employee *A, int n)
{
	// heapify() every element from A[n/2] down-to A[0]
	for (int i = n/2; i >= 0; i--){
		heapify(A, i, n);	
	}
}

/**
 * We want to start with A[i] and percolate it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the heap
 */
void heapify(Employee *A, int i, int n)
{
	// get index of left child of element i
	int l_child = (i * 2) + 1;
	// get index of right child of element i
	int r_child = (i * 2) + 2;

	
	// set index to -1 if the index is out of array's bounds
	if (l_child >= n){ // if left child DNE
		l_child = -1;
	}
	if (r_child >= n){ // if right child DNE
		r_child = -1;
	}

	// determine which child has a smaller salary. We'll call the index of this
	//		element: "smaller"
	int smaller = -1;
	if (r_child == -1 && l_child == -1){ // if both l and r chlid DNE, end recursion
		return;
	} else if (r_child == -1 || (A[r_child].salary > A[l_child].salary)){
		smaller = l_child;
	} else{
		smaller = r_child;
	}

	// recursively check if the salary at A[i] > the salary at A[smaller]. If it is, swap the two.
	//			Then recursively heapify A[smaller].
	if (smaller != -1 && (A[i].salary > A[smaller].salary)){
		swap(&A[i], &A[smaller]);
		heapify(A, smaller, n);
	}
}

/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(Employee *e1, Employee *e2)
{
	Employee B = *e1;
	*e1 = *e2;
	*e2 = B;
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(Employee *A, int n)
{
	for(int i = 0; i < n; i++){
		if(i == 0){
			printf("[id=%s sal=%d]", A[i].name, A[i].salary);
		} else{
			printf(", [id=%s sal=%d]", A[i].name, A[i].salary);
		}
	}
}

