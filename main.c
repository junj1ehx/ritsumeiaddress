#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
//define basic headfiles
#include "functions.h"
//define custom headfiles

int main(int argc,char const *argv[])
{
  	struct task *top = NULL;
  	struct task *end = NULL;
  	int filestatus;
  	int inputcode = -1;
  	int count;
	DIR *dir;

  	filestatus = 0;//check file status,0 = null,1 = exist
	if ((dir=opendir("./data")) == NULL){  
        		perror("Open dir error...");
		return 0;         
	}
	
  	while (inputcode != 0)
    {
    	printf("      *               ********          ********\n");
    	printf("     * *             *                  *       \n");
    	printf("    *   *           *                   *       \n");
    	printf("   *******          *                   ********\n");
    	printf("  *       *         *                          *\n");
    	printf(" *         *         *                         *\n");
    	printf("*           *         ********          ********\n");
    	printf("\n\n------------------------------------------------\n\n");
    	printf("       Welcome to Alpaca Contact System -0-\n\n\n");
    	printf("(1)繝・・繧ｿ蜈･蜉帙・霑ｽ蜉\n");
    	printf("(2)繝・・繧ｿ邱ｨ髮・・erase\n");
    	printf("(3)print input data(just add the sort system plz!)\n");
      	printf("(4)save file\n");
      	printf("(5)load file\n");
      	printf("(6)delete data in file\n");
      	printf("(7)output file to readable format\n");
      	printf("(8)load file of readable format\n");
      	printf("(9)exit\n");


      	printf("\n\n************************************************\n\n");
      	inputcode = get_input();
      	if (inputcode == 1){
			if (filestatus == 0){
	  		printf("no data existed,do you want to create a new one?(y/n)\n ");
	  		inputcode = get_input();
	  		if (inputcode == 1){
	    		add(&top,&end);
	    		return_menu();
	    		filestatus = 1;
	  		}
	  		if (inputcode == 2){
	    		return_menu();
	  		}
		
		} else if (filestatus == 1){
	  		add(&top,&end);
	  		return_menu();
		}
				
      	}
      //create new data

      	else if (inputcode == 2){
			if (filestatus == 0){
	  			printf("no data existed.\n ");
	  			return_menu();		     		
			} else if (filestatus == 1){
	  			printf("it can't be restored,continue anyway?((1)y/(2)n)\n");
	  			inputcode = get_input();

	  			if (inputcode == 1){
	    			printf("(1) edit (2) delete\n");
	    			inputcode = get_input();
	    		if (inputcode == 2){
	      			printf("1 for delete part of file, 2 for all\n");
	      			inputcode = get_input();
	      			if (inputcode == 1){
						printf("insert the id you want to delete\n");
						inputcode = get_input();
						delete_list(&top,&end,inputcode);
						return_menu();
						if (top == NULL){
		  					filestatus = 0;
						}	
	      			} else if  (inputcode == 2){
						clear_list(&top,&end);
						filestatus = 0;	
						return_menu();
	      			}
	    			} else if (inputcode == 1){
	      				printf("(1)edit name (2)edit email\n");
	      				inputcode = get_input();
	      				if (inputcode == 1){
							update_name(&top,&end);
	      				} else if (inputcode == 2){
							update_mail(&top,&end); 
	      				} else {
							printf("wrong code!");
	      				}
	      				return_menu();
	    			}
	  			} else if (inputcode == 2){
	    			return_menu();
	  			} else {
	    			printf("wrong code!");
	    			return_menu(); 
	  			}			
			}
      	}
      //erase input data
      	else if (inputcode == 3){
			if (filestatus == 1){
	  			printf("(1)show all \n(2)search a member (search members of a group) \n(3)search all member in group \n");
	  			inputcode = get_input();
	  			if (inputcode == 1){
	    			printf("(1)sort by id \n(2)sort by name \n");
	    			inputcode = get_input();
	    			if (inputcode == 1){
	      				print_list(top,end);
	   			} else if (inputcode == 2){
	      				az_sort(&top,&end);
							
	    			} else {
	      				printf("wrong code!");
	      				return_menu(); 
	    			}
	  			} else if (inputcode == 2){			
	    			printf("(1)search by id \n(2)search by name \n(3)search by group \n(4)search by sex \n");
	    			inputcode = get_input();
	    			if (inputcode == 1){
	      				id_find(&top,&end);
	    			} else if (inputcode == 2){
	      				name_find(&top,&end);	
	    			} else if (inputcode == 3){
	      				group_find(&top,&end);
	    			} else if (inputcode == 4){
	      				printf("sort by sex\n");
	      				sex_find(&top,&end);
	    			}
	  			} else if (inputcode == 3){
	    			group_sort(&top,&end);
	  			}
	  			return_menu();
			} else if (filestatus == 0) {
	  			printf("no data existed.\n");
	  			return_menu();
			}	else {
	  			printf("ERROR!\n");
	  			return_menu();
			}
				
      	}
      //print input data
      	else if (inputcode == 4){
			if (filestatus == 1){
	  			raw_export(top,end);
	  			return_menu();
			} else if (filestatus == 0){
	  			printf("no data existed.\n");
	  			return_menu();
			}
    	}
      //save file
      	else if (inputcode == 5){
			raw_import(&top,&end);
			return_menu();
			if (top != NULL){
	  			filestatus = 1;	
			}
      	}
      //load file
      	else if (inputcode == 6){
			fdelete();
			return_menu();
      	}
      //delete data in file
      	else if (inputcode == 7){
			if (filestatus == 1){
	  			printf("(1)output file to csv format\n(2)output file to txt format\n");
	  			inputcode = get_input();
	  			if (inputcode == 2){
	    			txt_export(top,end);
	    			return_menu();
	  			} else if (inputcode == 1){
	    			csv_export(top,end);
	    			return_menu();
	  			} else {
	    			printf("wrong code!\n");
	    			return_menu();
	  			}
			} else if (filestatus == 0){
	  			printf("no data existed.\n");
	  			return_menu();
			}
      	}
      //output file to readable format
      	else if (inputcode == 8){			

			printf("(1)load file to csv format\n(2)load file to txt format\n");
			inputcode = get_input();
			if (inputcode == 2){
	  			txt_import(&top,&end);
	  			filestatus = 1;
	  			return_menu();
			} else if (inputcode == 1){
	  			csv_import(&top,&end);
	  			filestatus = 1;
	  			return_menu();
			} else {
	  			printf("wrong code!\n");
	  			return_menu();
			}
		
	//load file of readable format
      	} else if(inputcode == 9){
			printf("Thank you for using!\n");
			return 0;
      	}

      //exit
      	else {
			printf("error! please insert correct control code.");
			return_menu();
      	}

    }
  	return 0;
}

int get_input()
{
  	int inputcode;
  	printf("insert inputcode:\n");
  	scanf("%d",&inputcode);
  	getchar();
  	return inputcode;
}

void return_menu()
{
  	char inputcode = ' ';
  	printf("                press q to continue;");
  	while(inputcode != 'q'){
    	inputcode = getchar();
  	}
  	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}


