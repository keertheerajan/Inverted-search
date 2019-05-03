#include "main.h"

void print_ht(Slist *head)
{
	if (head == NULL)
		printf("No List");

	Slist *temp = head;
	while (temp)
	{
		printf("[%s] ", temp->word);
		printf("%d file/s:", temp->file_count);

		Slist_file_table *temp1 = temp->file_table;

		while (temp1)
		{
			printf("File:%s ", temp1->file_name);
			printf("%d times\t", temp1->word_count);
			temp1 = temp1->tab_link;
		}
		temp = temp->link;
	}
	printf("\n\n");
}
