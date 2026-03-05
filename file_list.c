#include "inverted_search.h"
#include <string.h>

void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int i = 1 , empty;
	while(argv[i] != NULL)
	{
		empty = isFileEmpty(argv[i]);
		if(empty == FILE_NOTAVAILABLE )
		{
			printf("Entered FIle : %s is no more available\n" , argv[i]);
			printf("Hence the %s is not adding into file linked list\n", argv[i]);
			i++;
			continue;
		}
		else if(empty == FILE_EMPTY)
		{
			printf("Entered FIle : %s doesnot have any contents in it\n" , argv[i]);
			printf("Hence the %s is not adding into file linked list\n", argv[i]);
			i++;
			continue;
		}
		else
		{
			int ret_val = to_create_list_of_files(f_head , argv[i]);

			if(ret_val == SUCCESS )
			{
				printf("Successfull : inserting the file name %s into file linked list\n" , argv[i]);
			}
			else if (ret_val == REPEATATION)
			{
				printf("THis file name : %s is repeated\n" , argv[i]);
				printf("Hence we are not adding that file\n");
			}
			else
			{
				printf("Failure\n");
			}
			i++;
			continue;
		}
	}
}

//fun will check for file availability anf checks for file content
int isFileEmpty(char *filename)
{
    FILE *fptr = fopen(filename , "r");

    if(fptr == NULL)
    {
		if(errno == ENOENT)
		{
	    	return FILE_NOTAVAILABLE;
		}
    }

    //check for contents
    fseek(fptr , 0 , SEEK_END);
    if(ftell(fptr) == 0)
    {
		return FILE_EMPTY;
    }
}

 int to_create_list_of_files(Flist **f_head, char *name)
{
    //........TODO........
    // check for duplicancy
	
	Flist *new = malloc(sizeof(Flist));
	if(new == NULL)
		return FAILURE;

	strcpy(new->file_name,name);
	if(*f_head==NULL)
		*f_head=new;
	else
	{
		Flist *temp = *f_head;
		// check for duplicancy and insert_last
		while(temp->link!=NULL && (strcmp(temp->file_name,name)))
		{
			temp=temp->link;		
		}
		if(strcmp(temp->file_name,name) == 0)
		{
			return REPEATATION;
		}
		else if(temp->link==NULL)
		{
			temp->link=new;
		}	
			
	}
	new->link=NULL; 
	return SUCCESS;  
}
















