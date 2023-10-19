#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct node {
    struct node * arr[MAX_SIZE];
    char name[MAX_SIZE];
    int hours;
    int children;
    int marks;
    int completed;
} node;

void displaynode(node * n){
     printf("The subject name is: %s \n The number of hours is: %d \n The marks alotted are %d", n->name, n->hours, n->marks);
     
}

void search(node * root, char s[MAX_SIZE], node ** found) {
    // printf("%s", root->name);
    if(strcmp(root->name, s) == 0)
    {
        *found = root;
        return;
    }
    for(int i = 0; i < root->children; i++)
    {
        search(root->arr[i], s, found);
    }
}

int isCompleted(node * root, char s[MAX_SIZE])
{
    if(strcmp(root->name, s) == 0)
    {
        //printf("TEST");
        if(root->completed == 1)return 1;
    }
    int isComp = 0;
    for(int i = 0; i < root->children; i++)
    {
        isComp += isCompleted(root->arr[i], s);
    }
    return isComp;
}

int buildHours(node * root)
{
    if(root->hours != -1)return root->hours;
    int h = 0;
    for(int i = 0; i < root->children; i++)
    {
        h += buildHours(root->arr[i]);
    }
    return h;
}

node * createNode()
{
    node *head = (node *)malloc(sizeof(node));
    //printf("Enter the name of the subject\n");
    scanf("%s", head->name);
    //printf("Enter the number of hours or -1 if you want to calculate it automatically later: ");
    scanf("%d",&head->hours);
    //printf("Enter the number of marks or -1 if you want to calculate it automatically later: ");
    scanf("%d",&head->marks);
    head->children = 0;
    head->completed = 0;
    return head;
}


int main(){
    node *head = createNode();

    char s[MAX_SIZE];
    scanf("%s", s);
    node **f;
    *f = NULL;
    search(head, s, f);
    if(*f == NULL)printf("Not found\n");
    else printf("Found\n");

    if(isCompleted(head, head->name))printf("Completed\n");
    else printf("Not Completed\n");

    head->completed = 1;

    if(isCompleted(head, head->name))printf("Completed\n");
    else printf("Not Completed\n");

    displaynode(head);

} 