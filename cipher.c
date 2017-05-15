#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

  	void shift(char c[SIZE]){
  		char ch;
  		int i;
  		for (i = 0;i < strlen(c);i++){
  			ch = *(c+i);
  			ch = ch + 5;
  			*(c+i) = ch;
  		}

  	}

  	void unshift(char c[SIZE]){ 
  		char ch;
  		int i;
  		for (i = 0;i < (strlen(c));i++){
  			ch = *(c+i);
  			ch = ch - 5;
  			*(c+i) = ch;
  		}

  	}

	void code(struct task **top)
	{
		int id;
	    char name[SIZE];
	    char mail[SIZE];
	    char group[SIZE];
		int sex;//male = 1,female = 2,undefined = 3

	    strcpy(name,(*top)->name);
    	strcpy(mail,(*top)->mail);
    	strcpy(group,(*top)->group);
    	sex = (*top)->sex;
    	shift(name);
    	shift(mail);
    	shift(group);

	    strcpy((*top)->name,name);
    	strcpy((*top)->mail,mail);
    	strcpy((*top)->group,group);
    	(*top)->sex = sex;

	}

	void decode(struct task **top)
	{
		int id;
	    char name[SIZE];
	    char mail[SIZE];
	    char group[SIZE];
		int sex;//male = 1,female = 2,undefined = 3

	    strcpy(name,(*top)->name);
    	strcpy(mail,(*top)->mail);
    	strcpy(group,(*top)->group);
    	sex = (*top)->sex;
    	unshift(name);
    	unshift(mail);
    	unshift(group);

	    strcpy((*top)->name,name);
    	strcpy((*top)->mail,mail);
    	strcpy((*top)->group,group);
    	(*top)->sex = sex;

	}
	
void raw_import(struct task **top, struct task **end){
	//load save raw file
	FILE *fp; //ファイル宣言
	char filename[SIZE];//filename
	printf("filename:");
	gets(filename);//input filename
	struct task *temp = NULL;
	int inputcode;
	struct task *temp_front = NULL;
	int count;
	int id;

	int filename_count = 0;
	char pot = '.';
	char l = 'l';
	char o = 'o';
	filename_count = strlen(filename);
	filename[filename_count] = pot;
	filename[filename_count+1] = l;
	filename[filename_count+2] = o;
	filename[filename_count+3] = l;
	filename[filename_count+4] = '\0';
	printf("loading %s\n",filename);

	if ((*top) == NULL){

		count = 1;
		printf("loading data from file...\n");
    	temp = (struct task *)malloc(sizeof(struct task));
		temp->id = count;
		(*top) = temp;
		(*end) = temp;

	} else {

		printf("buffer data existed,(1)overwrite (2) write after existed data in file\n");
		inputcode = get_input();
		if (inputcode == 1){
			clear_list(&(*top),&(*end));
			(*top) = NULL;
			(*end) = NULL;
			(*top) = (struct task *)malloc(sizeof(struct task));
			temp = (*top);
			(*end) = temp;
			count = 1;
		} else if (inputcode == 2){
			temp = (*top);
			count = (*end)->id;
			count++;
			while(temp->next != NULL){
			temp = temp->next;
			}
		}
	}

 	if ((fp =fopen(filename,"r")) == NULL){
    	fprintf(stderr,"ファイルが開けません\n");
	} else {
  		while(fscanf(fp,"%d %s %s %s %d \n",&id,temp->name,temp->mail,temp->group,&(temp->sex))!= EOF){
    		temp-> id = count;
			decode(&temp);
			temp_front = temp;
    		temp->next = (struct task *)calloc(1,sizeof(struct task));
     		temp = temp->next;
     		count++;
     		printf(".");
  		}
  		(*end) = temp_front; 
		printf("\n%d members load successfully.\n",count-1); 
		fclose(fp);
	}
  


}

void raw_export(struct task *top,struct task *end){
	//save raw file
  	FILE *fp;
	char filename[SIZE];
	struct task *buffer = (top);
	char pot = '.';
	char l = 'l';
	char o = 'o';
	int count = 0;
	printf("filename:");
	gets(filename);
	count = strlen(filename);
	
	filename[count] = pot;
	filename[count+1] = l;
	filename[count+2] = o;
	filename[count+3] = l;
	filename[count+4] = '\0';
	printf("saving raw file %s\n",filename);
	 
	if ((fp = fopen(filename,"w")) == NULL)
	{
		fprintf(stderr,"file %s cant not open.\n",filename);	
	} else {
		if (buffer == NULL){
			printf("no data existed.\n");
			return;
		}
		count = 0;
		while (buffer != ((end)->next)){
		code(&buffer);
		fprintf(fp,"%d %s %s %s %d \n",buffer->id,buffer->name,buffer->mail,buffer->group,buffer->sex);
		decode(&buffer);
		buffer = buffer->next;
		printf(".");
		count++;	
	}
	printf("\n%d member saved successfully.\n",count);
	printf("ファイルの書き込みが終わりました\n");
	fclose(fp);
	}
}


#endif
