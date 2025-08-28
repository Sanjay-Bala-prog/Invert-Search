#include "main.h"
main_list *hashtable[27] = {NULL};
int validation(int argc,char *argv[],file_list **head)
{
       for(int i=0;i<argc;i++)
       {
            int j=0;
           while(argv[i][j]!='\0')
           {
            if(argv[i][j]=='.' && argv[i][j+1]=='t' && argv[i][j+2]=='x' && argv[i][j+3]=='t' && argv[i][j+4]=='\0')
            {
                FILE *fp=fopen(argv[i],"r");   //if the file is existing or not
                if(fp==NULL)
                {
                    printf("-------------------------FILE NOT FOUND--------------------------\n");
                    printf("|The %s is not founded                                   |\n",argv[i]);
                    printf("-----------------------------------------------------------------\n"); 
                    break;
                }

                fseek(fp,0,SEEK_END);
                int size=ftell(fp);        //In that file they contain any of the content
                fclose(fp);

                if(size==0)
                {
                     printf("-----------------FILE NOT HAVING ANY CONTENT--------------------\n");
                    printf("|The %s is not having any content                       |\n",argv[i]);
                    printf("----------------------------------------------------------------\n"); 
                    break;
                }
                
                if(insert_at_last(head,argv[i])==FAILURE)   //The all the condition is true insert the filename to SLL in insertlast
                {
                     printf("Failed to add %s to the list\n", argv[i]);
                    return FAILURE;
                }
                break;
            }
            j++;
           }
       }

    if (*head == NULL)
    {
        printf("No valid files provided\n");
        return FAILURE;
    }
    return SUCCESS;
}
int main(int argc,char *argv[])
{
    file_list *head = NULL;
  

    if(argc>=2)
    {
         if (validation(argc,argv,&head) == FAILURE)
		  {
                   return FAILURE;
		  }
          print_list(head);
          
          if(create_database(head)==SUCCESS)
           {
               printf("Database created successfully.\n");
            }
           else
           {
             printf("Failed to create database.\n");
           }


          printf("-----------------------------MENU---------------------------------\n");
          printf(" 1.Display database\n 2.Search database\n 3.Save database\n 4.Updata database\n");
          printf("------------------------------------------------------------------\n");
          int num;
          printf("Enter which operation do you want to do\n");
          scanf("%d",&num);
          
          switch(num)
          {
             case 1:
                     display();
                     break;

            case 2:
                    char word[50];
                    printf("Enter word to search: ");
                    scanf("%s", word);
                    search(word);
                     break;
              
            case 3:
                   save("backup.txt");;
                   break;
                   
            case 4:
                   update_database(head);
                   break;


            default:
                  printf("Invalid input\n");
                  break;
          }



    }
    else
    {
        printf("Enter atleast 2 argument to perform the operation\n");
    }
}