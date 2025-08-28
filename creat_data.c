#include "main.h"

int create_database(file_list *head)
{
    file_list *cur=head;
    char word[50];
    FILE *fp;

    while(cur != NULL)
    {
        fp=fopen(cur->filename,"r");   //opening the file in read mode
        if(fp == NULL)
        {
            printf("Error to open %s\n",cur->filename);
            cur=cur->link;
            continue;
        }
        
        while(fscanf(fp,"%49s",word)!=EOF)  //insert a content in file by word 
        {
             for(int i=0;word[i];i++)  //convert the given all word to lower
             {
                word[i]=tolower(word[i]);
             }   
                
             int index = g_index(word);  //finding the index
             if(index==-1)               //if index is -1 means move to next word
             {
                continue;
             }

             main_list *m_cur=hashtable[index];   //allocating a words to that perticulare index
             main_list *m_prev=NULL;
             int found=0;

             while(m_cur != NULL)  //if the index is not null means comaparing the first words 
             {
                if(strcmp(m_cur->word,word)==0)      //traversing 
                {
                    found=1;
                    break;
                }
                m_prev=m_cur;
                m_cur=m_cur->next;
             }

             if(!found)
             {
                main_list *new_m=malloc(sizeof(main_list));   //if word not founded.creat a new node
                if(new_m==NULL)
                {                                                   //it is a main node
                    printf("Memory allocation is failed\n");
                    fclose(fp);
                    return FAILURE;
                }
                strcpy(new_m->word,word);
                new_m->wcount=1;
                new_m->next=NULL;

                sub_list *new_s=malloc(sizeof(sub_list));              //it is a sub node
                 if(new_s==NULL)
                 {
                    printf("Memory allocation is failed\n");
                    free(new_m);
                    fclose(fp);
                    return FAILURE;
                 }
                 
                  strcpy(new_s->file1,cur->filename);            //here allocating a file name and count and link of the subnode
                  new_s->count=1;
                  new_s->link=NULL;
                  
                  new_m->current = new_s;   //linking subnode to mainnode

                  if(m_prev !=NULL)        //here checking the main previous is null.if it is null means update a new main to hashtable.
                  {                    
                    m_prev->next=new_m;      //otherwise update with previous to previous next
                  }
                  else
                  {
                    hashtable[index]=new_m;
                  }
             }
             else                     //if word founded means
             {
                     sub_list *s_cur=m_cur->current;
                     sub_list *s_prev=NULL;
                     int f_found=0;


                     while (s_cur != NULL)                   //here also checking the word by word which one is matching
                     {
                        if(strcmp(s_cur->file1,cur->filename)==0) // if it present update value in sub node
                        {
                             s_cur->count++;
                             f_found=1;
                             break;
                        }
                        s_prev=s_cur;
                        s_cur=s_cur->link;    //updating the next word
                     }

                     if(!f_found)                       
                     {                               //if the word id not found
                        sub_list *new_sub=malloc(sizeof(sub_list));     //creat a new subnode
                        if(new_sub==NULL)
                        {
                            printf("Memeory allocation is failed\n");
                            fclose(fp);
                            return FAILURE;
                        }
                         strcpy(new_sub->file1,cur->filename);   //update that into the subnode 
                         new_sub->count=1;
                         new_sub->link=NULL;

                         s_prev->link=new_sub;    //then check the next value
                         m_cur->wcount++;

                     }     
             }

        }
       fclose(fp);
       cur=cur->link;  //every time we need to update the node to next node
    }
    return SUCCESS;
}

int g_index(char *word)  //to allocate the index in hash table
{
      if(isalpha(word[0]))
      {
       return tolower(word[0]) - 'a';
      }
      else if (isdigit(word[0]))
      {
        return 26; // store numbers at last index
      }
     else
     {
        return -1; // skip special chars
     }   
}
