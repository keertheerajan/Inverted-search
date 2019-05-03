#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define FAILURE -1
#define CREATE_DATABASE 1
#define DISPLAY_DATABASE 2
#define SEARCH 4
#define SAVE_DATABASE 5

typedef char data_t;

typedef struct node
{
	int file_count;
	struct node *link;
	char *word;
	struct fi_tab *file_table;
}Slist;

typedef struct fi_tab
{
	int word_count;
	char file_name[20];
	struct fi_tab *tab_link;
}Slist_file_table;

int create_database(Slist **head, data_t *string, data_t *filename);
int save_db(Slist **head,FILE *fd);
void print_ht(Slist *head);
int file_table(Slist_file_table **head,char *filename);
#endif

