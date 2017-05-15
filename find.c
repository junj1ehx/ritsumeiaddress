#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"



void update(struct task **top, struct task **end){

  
  struct task *p = *top;
  struct task *q= *end;
 


  int cnt = 0;
  char sname[SIZE]; /*検索する名前*/
  char nstr[SIZE];

  printf("編集したい名前を入力してください\n");
  scanf("%s",sname);


  while(p !=NULL){
    if(strcmp(p->name,sname) == 0){ 
      printf("%d,%s,%s,%s,%d\n", p->id,p->name,p->mail,p->group,p->sex); 
      printf("新しい名前を入力してください\n");
      scanf("%s", nstr);
      strcpy(p->name,nstr);
      printf("%s\n",p->name);
      p->next;
      cnt = 1;
    }else {
      p = p->next;
if(p==NULL && cnt == 0){
	printf("見つかりませんでした\n");
 }
    }
  }
}
