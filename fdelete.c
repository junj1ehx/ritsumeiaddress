#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


void fdelete(){
	FILE *fp;                      //�ե���������
	char filename[SIZE];//filename
	printf("file to delete:");
	gets(filename);//input filename
	if((fp = fopen(filename, "w")) == NULL) {  //�ե�����"filename"����ӳ���
    printf("file was not found.\n");
	} else {
    		fprintf(fp," ");
			printf("file %s was deleted successfully.\n",filename);//�����������Ȥ���
			fclose(fp);      //�ե�������]����
	}    
}
  
  
                 
  



