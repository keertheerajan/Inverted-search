#include "main.h"
int save_db(Slist **head,FILE *fd)
{
    int i=0;
    char ch,*str;
    Slist *temp = *head;

    while(temp)
    {
	str = calloc(strlen(temp->word)+1,sizeof(char));
	strcpy(str,temp->word);
	//printf("%s\n",str);
	while(ch = str[i])
	{
	    i++;
	    fputc(ch,fd);
	}
	fputc(' ',fd);
	temp = temp->link;
	i=0;
	free(str);
    }
}
