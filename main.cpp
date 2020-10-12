#include <iostream>
using namespace std;
struct node{
int data;
node *next;
node *previous;
};
struct node *l=nullptr;
void print()
{
    if(l== nullptr)
        return;
    node *temp=l;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=l);
}
void insert(int data,int index)
{
    if(index==1)
    {
        node *temp=new node{data,NULL,NULL};
        temp->next=l;
        temp->previous=l->previous;
        temp->previous->next=temp;
        l->previous=temp;
        l=temp;
        return;
    }
    node* current=l;
    index-=1;
    while(index--)
    {current=current->next;}
    node *temp=new node{data,NULL,NULL};
    temp->next=current;
    temp->previous=current->previous;
    temp->previous->next=temp;
    current->previous=temp;
}
void del(int index)
{
    if(index==1)
    {
        node*temp=l->previous;
        l=l->next;
        l->previous=temp;
        temp->next=l;
        return;
    }
    node *current=l;
    index-=1;
    while(index--)
    {
        current=current->next;
    }

    node*temp=current->previous;
    current=current->next;
    current->previous=temp;
    temp->next=current;
}
int main() {
    int size=0;
    cin>> size;
    node *temp;
     while(size--)
     {
         int data=0;
          cin>> data;
          node *current=new node{data,NULL,NULL};
          if(l==NULL)
          {
              l=current;
              temp=current;
          }
          else{
              temp->next=current;
              current->previous=temp;
              temp=current;
          }
     }
     temp->next=l;
     l->previous=temp;
     print();
     cout<<endl;
     insert(5,1);
     print();
    cout<<endl;
    insert(6,2);
    print();
    cout<<endl;
    del(1);
    print();
    cout<<endl;
    del(5);
    print();
    return 0;
}
