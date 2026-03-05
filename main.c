/*
Name : S Sirisha
Date : 10-09-2024
Description : Inverted Search Project
*/
#include "inverted_search.h"

int main(int argc , char *argv[])
{
    system("clear");
	//har word[WORD_SIZE];
    Wlist *head[27] = { NULL};


    //validate CLA
    if(argc <= 1)
    {
		printf("Enter the valid no. arguments\n");
		printf("./Slist.exe file1.txt file2.txt .........\n");
		return 0;
    }

    //declare head pointer

    Flist *f_head = NULL;

    //file validation

    file_validation_n_file_list(&f_head , argv);
	
    if(f_head == NULL)
    {
		printf("No files added to file linked list\n");
		printf("Hence process got terminated\n");
		return -1;
    }

char choice;
do
{
	int option;
	printf("Select your choice among following options: \n");
	printf("1. Create Database\n");
	printf("2. Display Database\n");
	printf("3. Update Database\n");
	printf("4. Search\n");
	printf("5. Save Database\n");
	printf("Enter your choice : ");
	scanf("%d",&option);

	switch(option)
	{
		case 1:
			//create_database
			
			create_database(f_head , head);
			
			break;

		case 2:
			//display database
			display_database(head);
			break;

		case 3:
			//update database
			update_database(head,&f_head);
			break;

		case 4:
			//search
			{
				char word[3][WORD_SIZE];
				for(int i = 0; i < 3; i++) {
				printf("Enter the word name\n");
				scanf("%s" , word[i]);
				
				
				//find the index
				int index = tolower(word[i][0]) % 97;
				if(!(index >= 0 && index <= 25))
					index = 0;
				search(head[index] , word);
				}
			} 
			break;
		case 5:
			//save database
			save_database(head);
			break;
		default :
			printf("Enter valid option\n");
	}
		
	printf("Do you want to contine (y/n): ");
	getchar();
	scanf("%c",&choice);

} while(choice == 'y' || choice == 'Y');

}


































