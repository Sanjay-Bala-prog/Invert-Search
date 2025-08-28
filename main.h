#ifndef MAIN_H
#define MAIN_H
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define SIZE 27
#define SUCCESS 0
#define FAILURE -1

typedef int data_t;
typedef struct filename_node
{
	char filename[50];
    struct filename_node *link;
}file_list;

typedef struct sub_node
{
    int count;             // Number of times word appears in this file
    char file1[30];        //file name
    struct sub_node *link;   //next file node
}sub_list;

typedef struct main_node
{
    int wcount;        //Total occurrences of word across all files
    char word[30];      // Word text
    struct main_node *next;     // Next word node
    sub_list *current;        // Pointer to first sub_list node
}main_list;

extern main_list *hashtable[SIZE];    //hashtable to store the index


/*checking the validation*/
int validation(int argc,char *argv[],file_list **head);

/*Insert at last in single linkedlist*/
int insert_at_last(file_list **head, char *data);

/*creating a database*/
int create_database(file_list *head);

/*printing the arguments*/
void print_list(file_list *head);

/*display the content what ever in the hashtable*/
void display();

/*use to find the index*/
int g_index(char *word);

/*search the user input word is present or not in hastable*/
int search(char *word);

/*Save the data from another file for easy access*/
void save(const char *file);

/*updating the file*/
void update_database(file_list *head);

/*free the database*/
void free_database();
#endif