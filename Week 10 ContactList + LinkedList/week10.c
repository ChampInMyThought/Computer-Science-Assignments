// From Uncle Great, Thank you very much!

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char name[50];
    char tel[11];
    struct node *next;
    struct node *prev;
} data;

int main()
{
    int n, i = 0, j, c;
    char temp[50];
    data *head, *p, *now, *it, *dhead, *dnow;
    do
    {
        printf("1. Add new contact 2. Search contact 3. Exit 4. Display all contacts 5. Delete contact\n");
        printf("What do you want to do?: ");
        scanf("%d", &n);
        if(n == 1)
        {
            p = malloc(sizeof(data));
            if(i == 0)
            {
                head = p;
            }
            else
            {
                now->next = p;
            }
            printf("Enter name: ");
            scanf("%s", p->name);
            printf("Enter phone number: ");
            scanf("%s", p->tel);
            p->next = NULL;
            now = p;
            i++;
        }
        else if(n == 2)
        {
            c = 0;
            p = malloc(sizeof(data));
            dhead = p;
            dnow = p;
            dnow->next = NULL;
            printf("Enter name or phone number: ");
            scanf("%s", temp);
            it = head;
            for(j = 0; j < i; j++)
            {
                if(!strcmp(it->name, temp))
                {
                    c++;
                    p = malloc(sizeof(data));
                    strcpy(dnow->name, it->name);
                    strcpy(dnow->tel, it->tel);
                    p->prev = dnow;
                    dnow->next = p;
                    dnow = p;
                }
                else if(!strcmp(it->tel, temp))
                {
                    c++;
                    p = malloc(sizeof(data));
                    strcpy(dnow->name, it->name);
                    strcpy(dnow->tel, it->tel);
                    p->prev = dnow;
                    dnow->next = p;
                    dnow = p;
                }
                it = it->next;
            }
            printf("%d contact(s) found.\n", c);
            it = dhead;
            for(j = 0; j < c; j++)
            {
                printf("%s %s\n", it->name, it->tel);
                if(it->next != NULL)    it = it->next;
            }
            for(j = 0; j < c; j++)
            {
                p = it;
                it = it->prev;
                free(p);
            }
        }
        else if(n == 4)
        {
            printf("Total %d contact(s)\nContact list: \n", i);
            it = head;
            for(j = 0; j < i; j++)
            {
                printf("%s %s\n", it->name, it->tel);
                it = it->next;
            }
        }
        else if(n == 5)
        {
            c = 0;
            it = head;
            printf("Enter name or phone number: ");
            scanf("%s", temp);
            for(j = 0; j < i; j++)
            {
                if(!strcmp(it->name, temp))
                {
                    c++;
                    p = it;
                    if(it == head)
                    {
                        head = head->next;
                    }
                    else
                    {
                        dnow = it->next;
                    }
                    free(p);
                }
                else if(!strcmp(it->tel, temp))
                {
                    c++;;
                    p = it;
                    if(it == head)
                    {
                        head = head->next;
                    }
                    else
                    {
                        dnow = it->next;
                    }
                    free(p);
                }
                dnow = it;
                it = it->next;
            }
            i = i - c;
        }
    }while(n != 3);
    return 0;
}
