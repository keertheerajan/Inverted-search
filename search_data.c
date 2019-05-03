#include "main.h"

int search(Slist *head, data_t *string)
{
	if (head == NULL)
		printf("No List");

	Slist *temp = head;
	while (temp)
	{
		if(!strcmp(string,temp->word))
		{

		Slist_file_table *temp1 = temp->file_table;
		while (temp1)
		{
			printf("File:%s ", temp1->file_name);
			temp1 = temp1->tab_link;
			puts("");
		}
		temp = temp->link;
		}
	}
}
