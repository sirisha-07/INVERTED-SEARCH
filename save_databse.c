#include "inverted_search.h"

void save_database( Wlist *head[])
{
    int i;
    char file_name[FNAME_SIZE];
    printf("enter the file name\n");
    scanf("%s" , file_name);

    // open file
    FILE *fptr = fopen(file_name , "w" );

    for(i = 0; i< 27; i++)
    {
	    if(head[i] != NULL)
	    {
	        write_databasefile(head[i] , &fptr, i);
	    }
    }
    fclose(fptr);
    printf("Database saved\n");
}

void write_databasefile(Wlist *head, FILE** databasefile, int index)
{
    //........TODO............
    
    // #[index]  word is [word] : file count is [ %d ] : file is [file_name] : word count [%d] 
    
    while(head != NULL)
    {
        Wlist *temp=head;
        Ltable *ltable=temp->Tlink;
        fprintf(*databasefile,"#[%d]\n", index);
        fprintf(*databasefile,"word is [%s]: file count is %d:file/s: ",head->word, head->file_count);
        Ltable *Fhead = head->Tlink;
        while(Fhead)
        {
            fprintf(*databasefile,"file is %s: word count is %d\n", Fhead->file_name, Fhead->word_count);
            Fhead = Fhead->table_link;
        }
            //printf("\n");
        head = head->link;
    }
    //printf("\n");
}