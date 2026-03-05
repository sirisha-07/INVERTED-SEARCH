#include "inverted_search.h"

void search( Wlist *head, char (*word)[WORD_SIZE])
{
	//check list is empty or not
	int flag;
    if(head == NULL)
    {
		printf("List is empty , search not possible\n");
		//return 0;
    }

    //non empty , traverse through Wlist
    while(head)
    {

		//compare the search word with each node word
		int len = 3;
		
		for(int i = 0; i < len; i++) {
		if(!strcmp(head->word , word[i]))
		{
	    	printf("Word %s is present in %d file/s\n" , word[i] , head->file_count);
			flag = 1;
	    	Ltable *Thead = head->Tlink;

	    	while(Thead)
	    	{
				printf("In file : %s    %d time/s \n" , Thead->file_name , Thead->word_count);
				flag = 1;
				Thead = Thead->table_link;
			}
		
			//return 0;
	    }
		head = head->link;
	}
	
	if(flag == 0)
	{
    	printf("Search word not found\n");
	}
}
}



