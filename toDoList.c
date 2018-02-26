#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


/*  Create a task from the description and the priority

    param:  priority    priority of the task
    param:  desc    	pointer to the description string
    pre:    none
    post:   none
	ret: 	a task with description and priority
*/
TYPE createTask (int priority, char *desc) 
{
	TYPE newTask;
	newTask.priority = priority;
	strcpy(newTask.description, desc);
	return newTask;
}

/*  Save the list to a file

    param:  heap    pointer to the list
    param:  filePtr	pointer to the file to which the list is saved
    pre:    The list is not empty
    post:   The list is saved to the file in tab-delimited format.
			Each line in the file stores a task, starting with the 
			task priority, followed by a tab character (\t), and 
			the task description.
			
			The tasks are not necessarily stored in the file in 
			priority order. 
	
*/
void saveList(DynArr *heap, FILE *filePtr)
{
    assert(sizeDynArr(heap) > 0);
    filePtr = fopen("file.txt", "w");
    if (filePtr == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    for (int i = 0; i < heap->size; i++) {
        fprintf(filePtr, "%d\t%s\n",heap->data[i].priority, heap->data[i].description);
    }
    
}

/*  Load the list from a file

    param:  heap    pointer to the list
    param:  filePtr	pointer to the file
    pre:    none
    post:   The tasks are retrieved from the file and are added to the list.
			Refer to the saveList() function for the format of tasks in the file				
*/
void loadList(DynArr *heap, FILE *filePtr)
{
  	filePtr = fopen("file.txt", "r");
    int priority;
    char *description;
    while (fscanf(filePtr, "%d, %s", priority, description) != EOF) {
        fscanf(filePtr, "%d, %s", priority, description);
        
    }
}

/*  Print the list

    param:  heap    pointer to the list
    pre:    the list is not empty
    post:   The tasks from the list are printed out in priority order.
			The tasks are not removed from the list.
*/
void printList(DynArr *heap)
{
    DynArr *ascendingOrder;
    initDynArr(ascendingOrder, heap->capacity);
    copyDynArr(heap, ascendingOrder);
    
    // reverse the sort order to ascending
    for (int i = 0; i < ascendingOrder->size / 2; i++) {
        swapDynArr(ascendingOrder, i, ascendingOrder->size - i - 1);
    }
    
    for (int i = 0; heap->size; i++) {
        printf("%s\n\n\n\n",heap->data[i].description);
    }
}

/*  Compare two tasks by priority

    param:  left    first task
    param:  right 	second task
    pre:    none
    post:   none
	ret: 	-1 if priority of left < priority of right
			1 if priority of left > priority of right
			0 if priority of left = priority of right
*/
int compare(TYPE left, TYPE right)
{
	if (left.priority < right.priority)
		return -1;
	else if (left.priority > right.priority)
		return 1;
	else
		return 0;
}
