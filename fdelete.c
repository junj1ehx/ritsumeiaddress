#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


void fdelete(){
	FILE *fp;                      //¥Õ¥¡¥¤¥ëÐûÑÔ
	char filename[SIZE];//filename
	printf("file to delete:");
	gets(filename);//input filename
	if((fp = fopen(filename, "w")) == NULL) {  //¥Õ¥¡¥¤¥ë"filename"¤òºô¤Ó³ö¤·
    printf("file was not found.\n");
	} else {
    		fprintf(fp," ");
			printf("file %s was deleted successfully.\n",filename);//Ï÷³ý¤·¤¿¤³¤È¤òˆó¸æ
			fclose(fp);      //¥Õ¥¡¥¤¥ë¤òé]¤¸¤ë
	}    
}
  
  
                 
  



