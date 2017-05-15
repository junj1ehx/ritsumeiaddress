#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include "functions.h"



void swap(struct task *x, struct task *y){
struct task temp = *x;
 *x = *y;
 *y = temp;
}

void bubblesort_name(struct task s[], int len){

  int i,j;

for(i = 0;i<len; i++){
    for(j = i+1; j<len-1;j++){

  if(strcmp(s[j-1].name,s[j].name)>0){
    swap(&s[j-1],&s[j]);
  }
    }
 }
}


void bubblesort_group(struct task s[], int len){

  int i,j;

for(i = 0;i<len; i++){
    for(j = i+1; j<len-1;j++){

  if(strcmp(s[j-1].group,s[j].group)>0){
    swap(&s[j-1],&s[j]);
  }
    }
 }
}



void az_sort(struct task **head, struct task **end ){
  

  struct task p[SIZE];
  struct task *q = *head;
 
  int i;
  int len = 0;
  char *temp;

  while(q!= ((*end)->next)){
    p[len]= (*q);
    len++;
    q = q->next;

  }

  bubblesort_name(p,len);

  for(i = 0;i<len-1;i++){
	printf("%d,%s,%s,%s,%d\n",p[i].id,p[i].name,p[i].mail,p[i].group,p[i].sex);
  }
}

void group_sort(struct task **head, struct task **end){



  struct task p[SIZE];
  struct task *q = *head;
 
  int i;
  int len = 0;
  char *temp;

  while(q!= ((*end)->next)){
    p[len]= (*q);
    len++;
    q = q->next;

  }

  bubblesort_group(p, len);

  int cnt = 1;

  printf("グループ毎に表示\n");

  //printf("%s\n", p[1].group);
  //printf("%d,%s,%s,%s,%d\n",p[0].group,p[0].id,p[0].name,p[0].mail,p[0].group,p[0].sex);

   for(i = 0;i<len-1;i++){
    if(p[i].group == '\0')
      break;
    if(strcmp(p[i].group,p[i+1].group)== 0 && cnt == 1){
      printf("グループ名 : %s     %d,%s,%s,%s,%d\n",p[i].group,p[i].id,p[i].name,p[i].mail,p[i].group,p[i].sex);
      cnt = 0;
    }else if(strcmp(p[i].group,p[i+1].group) == 0 && cnt == 0){
      printf("                  %d,%s,%s,%s,%d\n",p[i].id,p[i].name,p[i].mail,p[i].group,p[i].sex);

    }
    else if(strcmp(p[i].group,p[i+1].group)!=0 && cnt == 1 ){
      printf("グループ名 : %s    %d,%s,%s,%s,%d\n",p[i].group,p[i].id,p[i].name,p[i].mail,p[i].group,p[i].sex);
 
	}  else if(strcmp(p[i].group,p[i+1].group)!=0 && cnt == 0){
      printf("                   %d,%s,%s,%s,%d\n",p[i].id,p[i].name,p[i].mail,p[i].group,p[i].sex);
      cnt = 1;
    }
    }
}


void group_find(struct task **top, struct task **end){

 

  struct task *p = *top;
  struct task *q = *end;

 
  int cnt = 0;
  char sname[SIZE]; /*検索する名前*/
  char xname[SIZE];



  printf("グループ名を入力してください\n");
  scanf("%s",sname); 

  while(p!= ((*end)->next)){
    if(strstr(p->group,sname) != NULL){ 
      printf("%d,%s,%s,%s,%d\n", p->id,p->name,p->mail,p->group,p->sex); 
      p=p->next;  
      cnt = 1;
    }else{
      p=p->next;
      if(p==NULL && cnt == 0){
	printf("見つかりませんでした\n");
    }
    }
  }
}

 




void name_find(struct task **top, struct task **end){

  int id;
  char name[SIZE];
  char mail[SIZE];
  char group[SIZE];
  int sex;


  struct task *p = *top;
  struct task *q = *end;
 

  
  int cnt = 0;
  char sname[SIZE]; /*検索する名前*/
  char xname[SIZE];
  




  printf("名前を入力してください\n");
  scanf("%s",sname);

while(p!= ((*end)->next)){
    if(strstr(p->name,sname) != NULL){ 
      printf("%d,%s,%s,%s,%d\n", p->id,p->name,p->mail,p->group,p->sex); 
      p=p->next;  
      cnt = 1;
    }else{
      p=p->next;
      if(p==NULL && cnt == 0){
	printf("見つかりませんでした\n");
    }
    }
  }
}



void sex_find(struct task **top, struct task **end){

  int id;
  char name[SIZE];
  char mail[SIZE];
  char group[SIZE];
  int sex;



  struct task *new = *top;
  struct task *head = *top;
 

  

  struct task *p;
  p  = (struct task *)malloc(sizeof(struct task));

  int cnt = 0;
  char sname[SIZE]; /*検索する名前*/
  char xname[SIZE];
  int co;




  printf("性別を入力してください\n");
  scanf("%d",sname);

  p = new;


  while(p!= ((*end)->next)){
    if(strstr(p->name,sname) != NULL){ 
      printf("%d,%s,%s,%s,%d\n", p->id,p->name,p->mail,p->group,p->sex); 
      p=p->next;  
    }else{
      p=p->next;
    }
  }
}
  


