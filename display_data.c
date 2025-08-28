#include "main.h"


void display()
{
    printf("\n%-7s %-15s %-12s %-20s %-10s\n", "Index", "Word", "Word Count", "File Name", "File Count");
    printf("-------------------------------------------------------------------------------\n");
    for(int i=0;i<SIZE;i++)          //traversing the loop for hashmapping times
    {
        if(hashtable[i] != NULL)          //checking onr by one
        {
            main_list *m_cur=hashtable[i];
            while(m_cur != NULL)                  //this is main node lopp to fetch the data
            {
                printf("%-7d %-15s %-12d", i,m_cur->word, m_cur->wcount);  //what is the word //word count


                int first_file = 1;
                sub_list *s_cur=m_cur->current;
                while(s_cur != NULL)               //if sub node is have means ruun upto the null
                {
                    if (!first_file)
                    { 
                        printf("%-7s %-15s %-12s", "", "", "");
                    }
                    printf("%-20s %-10d\n", s_cur->file1, s_cur->count);  //here file name is printed  //here how many file ae there which means file count
                    s_cur=s_cur->link;      //updating the subnode 
                    first_file=0;
                }
                m_cur=m_cur->next;    //updating the mainnode
            }
        }
    }
     printf("-------------------------------------------------------------------------------\n");
}