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
    printf("�ե����뤬Ҋ�Ĥ���ޤ���\n");
	} else {
    		fprintf(fp," ");
			printf("�ե����� %s ���������ޤ���.\n",filename);//�����������Ȥ���
			fclose(fp);      //�ե�������]����
	}    
}
  
  
                 
  



