#include "inverted_search.h"

char *fname;

void create_database(Flist *f_head, Wlist *head[])
{
    //traverse through the file linked list
	
    while(f_head)
    {
		
	read_datafile(f_head , head , f_head->file_name);
	f_head = f_head->link;
    }
}

Wlist * read_datafile(Flist *file, Wlist *head[], char *filename)
{
    fname = filename;
    int flag = 1;
    //open the file read  mode 

    FILE *fptr = fopen(filename , "r");

    //declare an array to store the word
    char word[WORD_SIZE];

    while(fscanf(fptr , "%s" , word) != EOF)
    {
		flag=1;
	//index 
	int index = tolower(word[0]) % 97;

	//other than alphabet 
	if(!(index >= 0 && index <= 25))
	    index = 26;

	//word is repeated or not

	if(head[index] != NULL)
	{
	   Wlist *temp = head[index];
	   //compare the words of each node with new word
	   while(temp)
	   {
	       if(!strcmp(temp->word,word))
	       {
				update_word_count(&temp , filename);
		   		flag = 0;
		   		break;
	       }
	       temp = temp->link;
	   }
	}
	if(flag == 1)
	{
	    //if words are not repeated
    	    insert_at_last(&head[index] , word);
	}
    }
}

int update_word_count(Wlist ** head, char * file_name)
{
    
	Wlist *temp3 = *head;
	Ltable *temp4 = temp3->Tlink;
    int flag = 0;

    while(temp4)
    {
        if(strcmp(temp4->file_name,file_name) == 0)
        {
            (temp4->word_count)++;
            flag=1;
            break;
        }
        temp4 = temp4->table_link;
    }
    if(!flag)
    {
		(*head)->file_count++;
        Ltable *new = malloc(sizeof(Ltable));
        if (new == NULL)
        {
            return FAILURE;
        }
		new->word_count = 1;
        strcpy(new->file_name, file_name);
		Ltable *temp=(*head)->Tlink;
		while(temp->table_link != NULL)
		{
			temp=temp->table_link;
		}
		temp->table_link=new;
        new->table_link = NULL;
    }
    return SUCCESS;
}












