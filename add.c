#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void add(struct task **top,struct task **end){
	struct task *temp; 
	int id;
 	int sex;
	int count;
	if ((*top) == NULL){
		count = 1;
    	temp = (struct task *)malloc(sizeof(struct task));
		temp->id = count;
		(*top) = temp;
		(*end) = temp;
	} else {
		temp = (*end);
		count = ((*end)->id) + 1;
    	temp->next = (struct task *)malloc(sizeof(struct task));
		temp = temp->next;
		}
		//value for giving id 
    printf("insert name:\n");
    gets(temp->name);
    printf("insert mail:\n");
    gets(temp->mail);
    printf("insert group:\n");
    gets(temp->group);
	printf("insert sex (1)male (2)female\n");
	scanf("%d",&sex);
	temp->next = NULL;
	temp->sex = sex;
    temp->id = count;
	*end = temp;
	print_list(*top,*end);

}

