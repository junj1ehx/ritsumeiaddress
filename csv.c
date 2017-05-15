#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void csv_import(struct task **top, struct task **end){
	//load csv
	FILE *fp; //ファイル宣言
	char filename[SIZE];//filename
	printf("filename (csv format):");
	gets(filename);//input filename
	struct task *temp = NULL;
	int inputcode;
	struct task *temp_front = NULL;	
	int id;
	int count;
	
	int filename_count = 0;
	char pot = '.';
	char c = 'c';
	char s = 's';
	char v = 'v';
	filename_count = strlen(filename);
	filename[filename_count] = pot;
	filename[filename_count+1] = c;
	filename[filename_count+2] = s;
	filename[filename_count+3] = v;
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
			//count++;
			}
		} else {
			printf("ERROR ,return to main menu.\n");
			return;
		}
	}

 	if ((fp =fopen(filename,"r")) == NULL){
    	fprintf(stderr,"ファイルが開けません\n");
	} else {
  		while(fscanf(fp,"%d,%[^,],%[^,],%[^,],%d\n",&id,temp->name,temp->mail,temp->group,&(temp->sex))!= EOF){
    		temp-> id = count;
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

void txt_import(struct task **top, struct task **end){
	//load txt
	FILE *fp; //ファイル宣言
	char filename[SIZE];//filename
	printf(" filename(txt format):");
	gets(filename);//input filename
	struct task *temp = NULL;
	int inputcode;
	struct task *temp_front = NULL;
	int count;
	int id;

	int filename_count = 0;
	char pot = '.';
	char t = 't';
	char x = 'x';
	filename_count = strlen(filename);
	filename[filename_count] = pot;
	filename[filename_count+1] = t;
	filename[filename_count+2] = x;
	filename[filename_count+3] = t;
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
		} else {
			printf("ERROR ,return to main menu.\n");
			return;
		}
	}

 	if ((fp =fopen(filename,"r")) == NULL){
    	fprintf(stderr,"ファイルが開けません\n");
	} else {
  		while(fscanf(fp,"%d %s %s %s %d \n",&id,temp->name,temp->mail,temp->group,&(temp->sex))!= EOF){
    		temp-> id = count;
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

void csv_export(struct task *top,struct task *end){
	//save csv
  	FILE *fp;
	char filename[SIZE];
	struct task *buffer = top;
	char pot = '.';
	char c = 'c';
	char s = 's';
	char v = 'v';
	int count = 0;
	printf("filename:");
	gets(filename);
	count = strlen(filename);
	
	filename[count] = pot;
	filename[count+1] = c;
	filename[count+2] = s;
	filename[count+3] = v;
	filename[count+4] = '\0';
	printf("saving csv file %s\n",filename);
	 
	if ((fp = fopen(filename,"w")) == NULL)
	{
		fprintf(stderr,"file %s cant not open.\n",filename);	
	} else {
		if (buffer == NULL){
			printf("no data existed.\n");
			return;
		}
		count = 0;
		while (buffer != (end->next)){
		fprintf(fp,"%d,%s,%s,%s,%d\n",buffer->id,buffer->name,buffer->mail,buffer->group,buffer->sex);
		buffer = buffer->next;
		printf(".");
		count++;	
	}
	printf("\n%d member saved successfully.\n",count);
	printf("ファイルの書き込みが終わりました\n");
	fclose(fp);
	}
}

void txt_export(struct task *top,struct task *end){
	//save txt
  	FILE *fp;
	char filename[SIZE];
	struct task *buffer = top;
	char pot = '.';
	char t = 't';
	char x = 'x';
	int count = 0;
	printf("filename:");
	gets(filename);
	count = strlen(filename);
	
	filename[count] = pot;
	filename[count+1] = t;
	filename[count+2] = x;
	filename[count+3] = t;
	filename[count+4] = '\0';
	printf("saving txt file %s\n",filename);
	 
	if ((fp = fopen(filename,"w")) == NULL)
	{
		fprintf(stderr,"file %s cant not open.\n",filename);	
	} else {
		if (buffer == NULL){
			printf("no data existed.\n");
			return;
		}
		count = 0;
		while (buffer != (end->next)){
		fprintf(fp,"%d %s %s %s %d \n",buffer->id,buffer->name,buffer->mail,buffer->group,buffer->sex);
		buffer = buffer->next;
		printf(".");
		count++;	
	}
	printf("\n%d member saved successfully.\n",count);
	printf("ファイルの書き込みが終わりました\n");
	fclose(fp);
	}
}

