//#ifndef _FUNCTION_H_
//#define _FUNCTION_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//define basic headfiles
#include "functions.h"
//define custom headfiles

void print_list(struct task *head,struct task *end)
{
	struct task *p = head;
  while(p != ((end)->next)){
    printf("%d,%s,%s,%s,%d",p -> id,p -> name,p-> mail,p -> group,p -> sex);
  printf("\n");
    p = p -> next;
  }
}

void delete_list(struct task **top,struct task **end,int num)
{
	struct task *temp = (*top);
	struct task *temp_front = NULL;
	
	if (temp -> id == num){
		(*top) = temp->next;
		free(temp);
		printf("delete %d success\n",num);
		return;
	} else {
		while ((temp != NULL) && (temp->id != num)){
			temp_front = temp;
			temp = temp -> next;
		}		
		if (temp == NULL){
			printf("cant find\n");
			return;
		} else {
			temp_front -> next = temp -> next;
			free(temp);
			printf("delete %d success\n",num);
		}
	}
}
	

    
 

void clear_list(struct task **head,struct task **end)
{
	struct task *p = NULL;
  while((*head) != NULL)
    {
		  p = (*head);
      (*head) =(*head) -> next;
      free(p);
    }
    (*head) == NULL;
    (*end) == NULL;
  if (*head == NULL){
	printf("clear\n");
	}
} 
