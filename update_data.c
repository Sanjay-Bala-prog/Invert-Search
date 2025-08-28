#include "main.h"

void free_database()
{
    for (int i = 0; i < SIZE; i++)
    {
        main_list *main_curr = hashtable[i];
        while (main_curr != NULL)
        {
            sub_list *sub_curr = main_curr->current;
            while (sub_curr != NULL)
            {
                sub_list *temp_sub = sub_curr;
                sub_curr = sub_curr->link;
                free(temp_sub);
            }

            main_list *temp_main = main_curr;
            main_curr = main_curr->next;
            free(temp_main);
        }
        hashtable[i] = NULL;
    }
}

void update_database(file_list *head)
{
    printf("Updating database...\n");
    free_database();                              // Step 1: Clear old data
    if (create_database(head) == SUCCESS)        // Step 2: Rebuild from file list
    {
        printf("Database updated successfully.\n");
    }
    else
    {
        printf("Failed to update database.\n");
    }
}
