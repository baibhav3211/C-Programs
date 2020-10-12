#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node *ptr,struct node *head)
{
    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
}

struct Node* Reverse(struct Node * head)
{
        struct Node* current = head; 
        struct Node *prev = NULL, *next = NULL; 
  
        while (current != NULL) { 
            // Store next 
            next = current->next; 
  
            // Reverse current node's pointer 
            current->next = prev; 
  
            // Move pointers one position ahead. 
            prev = current; 
            current = next; 
        } 
        head = prev;
        return head;
}



int main()
{
   struct Node * head=NULL;
   struct Node * current;
   struct Node * rev_head;
   struct Node *temp;
   int num=0;
   
    printf("Enter number of elements of linked list: \n");
    scanf("%d",&num);
    
    for(int i =0; i < num; i++)
    {
        struct Node* current = (struct Node *)malloc(sizeof(struct Node)); 
        scanf( "%d", &current->data);      
       // current->next = head; 
       if(i==0)
        {
            head = current;  
            temp=current;}
        else
        {
            temp->next=current;
            temp=current;
        }
    }
     temp->next = head;
    
    
    
    printf("Linked list before insertion\n");
    linkedListTraversal(head,head);
    // printf("Linked list After Reversal\n");
    // rev_head = Reverse(head);
    // linkedListTraversal(rev_head);
    
return 0;
    
    
}





