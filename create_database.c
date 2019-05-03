#include "main.h"

int create_database(Slist **head, data_t *string, data_t *filename)
{
    Slist *s;
    int len;
    if(*head == NULL)
    {
	s = malloc(sizeof(Slist));
	if(!s )
	    return FAILURE;

	*head = s;
	s->file_count = 1;
	len = (strlen(string)+1);
	s->word = calloc(len,1);
	strcpy(s->word,string);
	s->link = NULL;
	file_table(&s->file_table,filename);
	return 0;
    }

    Slist *temp = *head;
    while(temp)
    {
	if(!strcmp(temp->word,string))
	{
	    temp->file_count = temp->file_count+1;
	    file_table(&temp->file_table,filename);
	    return 0;
	}
	temp = temp->link;
    }
    
    temp = *head;
    while(temp->link!=NULL)
	temp = temp->link;
    create_database(&(temp->link),string,filename);
}
