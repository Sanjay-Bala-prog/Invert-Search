#include "main.h"

void save(const char *file)
{
    FILE *fp=fopen(file,"w");         //opening the file
    if(fp==NULL)
    {
        printf("Error to open the file\n");
        return;
    }
    for(int i=0;i<SIZE;i++)         //run upto the hashtable size
    {
        main_list *m_cur=hashtable[i];    //assigning the hashtable to m_cur
        while(m_cur!=NULL)
        {
            fprintf(fp, "#%d;%s;%d;",i,m_cur->word,m_cur->wcount);  //print the values in file
            sub_list *s_cur=m_cur->current;                    //next traves throw the subnode
            while(s_cur!=NULL)
            {
                fprintf(fp, "%s;%d;",s_cur->file1,s_cur->count);     //printing the subnode content into the file
                s_cur=s_cur->link;
            }
            fprintf(fp,"#\n");
            m_cur=m_cur->next;
        }
    }
    fclose(fp);         //finally close the file
    printf("Database is saves %s\n",file);
}