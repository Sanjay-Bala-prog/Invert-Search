#include "main.h"


int search(char *word)
{
    int index=tolower(word[0])-'a';     //find the which index is it is.

    if(index < 0 || index >=27)      
    {
        printf("Invalied starting character %c\n",word[0]);
        return FAILURE;
    }
    main_list *m_cur=hashtable[index];
    while(m_cur != NULL)      //then run the loop upto the main node is null
    {
        if(strcmp(m_cur->word,word)==0)    //comparing the main node to the given node
        {
             // Table header
            printf("\n%-7s %-15s %-12s %-20s %-10s\n","Index", "Word", "Word Count", "File Name", "File Count");
            printf("-------------------------------------------------------------------------------\n");
            printf("%-7d %-15s %-12d",index,m_cur->word, m_cur->wcount);

            int f_count=0;
            sub_list *s_cur=m_cur->current;
            int first_file = 1;

            while (s_cur != NULL)
            {
             if (!first_file) // empty columns for extra file rows
             {
                    printf("%-7s %-15s %-12s", "", "", "");
             }
                printf("%-20s %-10d\n", s_cur->file1, s_cur->count);
                s_cur = s_cur->link;
                first_file = 0;
            }
             printf("-------------------------------------------------------------------------------\n");
            return SUCCESS;
        }
        m_cur=m_cur->next;       //updating to the next main node
    }
    printf("The word '%s' was not found in the database.\n", word);
    return FAILURE;
}