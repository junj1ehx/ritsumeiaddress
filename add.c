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
    printf("名前を入力してください\n");
    gets(temp->name);
    printf("メールアドレスを入力してください\n");
    gets(temp->mail);
    printf("グループを入力してください\n");
    gets(temp->group);
	printf("性別を入力してください(１は男性、２は女性で)\n");
	scanf("%d",&sex);
	temp->next = NULL;
	temp->sex = sex;
    temp->id = count;
	*end = temp;
	print_list(*top,*end);

}

