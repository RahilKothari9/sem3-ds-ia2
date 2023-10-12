#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct node {
    struct node * arr[MAX_SIZE];
    char name[MAX_SIZE];
    int hours;
    int children;
    int marks;
} node;

void displaynode(node * n){
     printf("The subject name is:  ");
}


int main(){
    node *head = (node *)malloc(sizeof(node));
    printf("Enter the name of the subject\n");
    scanf("%s", head->name);
    printf("Enter the number of hours or -1 if you want to calculate it automatically later");
    scanf("%d",head->hours);
    printf("Enter the number of marks or -1 if you want to calculate it automatically later");
    scanf("%d",head->marks);


    
} 