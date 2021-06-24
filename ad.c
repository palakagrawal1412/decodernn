#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void push(char x);
char pop();
int len();

struct node{
    char data;
    struct node *next;
};
struct node *root=NULL;

void push(char x)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=x;
    struct node *p=root;
    if(len()==0)
    {
        root=new_node;
    }
    else
    {
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=new_node;
    }
}

int len(){
    int l=0;
    struct node *p=root;
    while(p!=NULL)
    {
        l++;
        p=p->next;
    }
    return l;
}

char pop()
{
    char x='\0';
    if(len()==0)
    {
        printf("Queue is empty");
    }
    else if(len()==1)
    {
        struct node *p=root;
        x=p->data;
        free(p);
    }
    else
    {
        struct node *p=root;
        struct node *q=root;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        while(q->next!=p){
            q=q->next;
        }
        x=p->data;
        free(p);
        q->next=NULL;
    }
    return x;
}

int main(void)
{
    char a[40];
    char b[40];
    printf("enter the string : ");
    scanf("%s",a);
    int l=strlen(a);
    for(int i=0;i<l;i++)
    {
        push(a[i]);
    }
    for(int i=0;i<l;i++)
    {
        b[i]=pop();
    }
    if(strcmp(a,b))
    {
        printf("No, string is not a palindrome\n");
    }
    else
    {
        printf("Yes, string is a palindrome\n");
    }
}
