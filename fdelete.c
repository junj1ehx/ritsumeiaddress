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
    printf("¥Õ¥¡¥¤¥ë¤¬ÒŠ¤Ä¤«¤ê¤Þ¤»¤ó\n");
	} else {
    		fprintf(fp," ");
			printf("¥Õ¥¡¥¤¥ë %s ¤òÏ÷³ý¤·¤Þ¤·¤¿.\n",filename);//Ï÷³ý¤·¤¿¤³¤È¤òˆó¸æ
			fclose(fp);      //¥Õ¥¡¥¤¥ë¤òé]¤¸¤ë
	}    
}
  
  
                 
  



