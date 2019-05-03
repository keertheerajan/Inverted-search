#include "main.h"

int main()
{
    int size,i=0,op,index,flag;
    char *str,word[15]={0,},ch,*ext,ch1,str1[10]={0,};
    FILE *fptr,*dstptr;
    Slist *head[26]={NULL};

    do
    {
    	printf("1)create_data_base\n2)display_data_base\n4 )search_data_base\n5)save_data_base\n5)quit\nopt : ");
    	scanf("%d",&op);
    	switch(op)
    	{
    	    case CREATE_DATABASE :
    		printf("enter the size of i/p file : ");
  		scanf("%d",&size);
		getchar();
                str = calloc(size+1,sizeof(char));
		printf("enter the file name : ");
//		str = calloc(size+1,char);
		fgets(str,size,stdin);
		ext = (char *)(str + (strlen(str) - 4));
		if( !strcmp(ext,".txt") )
		{
		    printf("FILE TYPE MATCHED ....");
		    fptr = fopen(str,"r");
		    if(!fptr)
		    {
			perror("fopen");
		    }
		    
		    while((ch = fgetc(fptr)) != EOF)
		    {
			if(isspace(ch))
			{
			    word[i]=0;
			    index = (tolower(word[0])) % 'a';
			    create_database(&head[index],word,str);
			    i = 0;
			    continue;
			}
			word[i] = ch;
			i++;
		    }
		}
		else
		{
		    printf("FILE TYPE NOT MATCHED");
		}
		free(str);
		str = NULL;
		puts("DATA IS ADDED");
		break;
	    case DISPLAY_DATABASE : 
		    for(int i=0;i<26;i++)
		    {
			if(head[i])
			    print_ht(head[i]);
		    }
		break;
	    case SAVE_DATABASE :
		dstptr = fopen("output.txt","a");
		if(!dstptr)
		    perror("o/p-failure");

		for(int index=0;index<26;index++)
		{
		    save_db(&head[index],dstptr);
		}
		break;
	    case SEARCH:
		printf("enter the string : ");
		scanf("%s",str1);
		puts(str1);
		flag = 0;
		for(int i=0;i<26;i++)
		{
		    if(head[i])
		    {
			Slist *temp = head[i];
			while (temp)
			{
	    		    if(!strcmp(temp->word,str1))
			    {

	    		    Slist_file_table *temp1 = temp->file_table;
		    
			    while (temp1)
	    		    {
				printf("File:%s ", temp1->file_name);
				printf("%d times\t", temp1->word_count);
				temp1 = temp1->tab_link;
				flag = 1;
	    		    }
			    }
	    		    temp = temp->link;
			}
    		    }
		}
		if(flag == 0)
		    puts("data not present");
		break;
	    default:
		puts("invalid input");
	}
	getchar();
	printf("\ny or n : ");
	ch1 = getchar();
    }while(ch1 == 'y');
    return 0;

}
