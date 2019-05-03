#include "main.h"

int file_table(Slist_file_table	**head,char *filename)
{
    if(*head==NULL)
    {
	*head = malloc(sizeof(Slist));
	if(*head == NULL)
	    perror("malloc_filetable");

	(*head)->word_count = 1;
	strcpy((*head)->file_name,filename);
	(*head)->tab_link = NULL;
	return 0;
    }

     Slist_file_table *temp = *head;
     while(temp)
     {
	 if(!strcmp(temp->file_name,filename))
	 {
	     temp->word_count = temp->word_count + 1;
	     return 0;
	 }
	 temp = temp->tab_link;
     }

     file_table(&temp,filename);
}

