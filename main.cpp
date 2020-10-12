#include <stdio.h>
struct node{
    int data{};
    node* next= nullptr;
    node* previous=nullptr;
}*l;
void insert(node* element);
void insert(node* element,int index);
void print();
void del(int index);
void reverse();
int main() {
    insert(new node{1});
    print();
    printf("\n");
    insert(new node{50},4);
    print();
    printf("\n");
    insert(new node{15},2);
    print();
    printf("\n");
    del(3);
    print();
    printf("\n");
    reverse();
    print();
    return 0;
}
void del(int index)
{
    if(l== nullptr)
    {return;}
    if(index==1)
    {
        l=l->next;
        l->previous= nullptr;
        return;
    }
    node*temp=l;
    index-=1;
    while(index!=1)
    {
        temp=temp->next;
        index--;
    }
    if(temp->next==nullptr)
    {return;}
    temp->next=temp->next->next;
    if(temp->next== nullptr){return;}
    temp->next->previous=temp;
}
 void reverse()
{
    node*temp=l;
    while(temp->next!= nullptr)
    {
        temp=temp->next;
    }
    l=temp;
    while(temp->previous!= nullptr)
    {
        node*q;
    q=temp->next;
    temp->next=temp->previous;
    temp->previous=q;
    temp=temp->next;
    }
    temp->previous=temp->next;
    temp->next= nullptr;
}
void print()
{
    node*temp=l;
    while(temp!= nullptr)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void insert(node* element){
    if(l==nullptr)
    {
        l=element;
        return;
    }
    node*temp=l;
    while(temp->next!= nullptr)
    {
        temp=temp->next;
    }
    temp->next=element;
    element->previous=temp;
}
void insert(node* element,int index)
{
    if(l==nullptr)
    {
        insert(element);
        return;
    }
    else if(index==1)
    {
        node *temp=l;
        l=element;
        element->next=temp;
        temp->previous=element;
        return;
    }
    node*temp=l;
    //index-=1;
    if(index!= 2&&temp!= nullptr)
    {
        temp=temp->next;
    }
    if(temp==nullptr)
    {insert(element);
    return;}
    temp->next->previous=element;
    element->next=temp->next;
    temp->next=element;
    element->previous=temp;
}

