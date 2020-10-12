#include <iostream>
#include <vector>

using namespace std;

struct List{
    List *next=nullptr;
    int data{};
};
void insert(List *l,int element);
void print(List *l);
void insert(List **l,int element,int index);
void pop(List **l,int index);
void reverse(List **l,List *node);
int main() {
     List *l=nullptr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        if(l==nullptr)
        {
            List *temp=new List{nullptr,data};
            l=temp;
            continue;
        }
        insert(l,data);/* *call to insert fucntion at the end
                           *you can take user input and*/
    }
    print(l);
    insert(&l,6,1);/* *call to insert fucntion
                                      *at a index you can take user input and cll this fucntion*/
    cout<<endl;
    print(l);
    pop(&l,6);
    cout<<endl;
    print(l);
    reverse(&l,l);
    cout<<endl;
    print(l);
    return 0;
}
void print(List *l)
{
    List *temp=l;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void insert(List *l,int element)
{
    List *temp=l;
    while(temp->next!=nullptr)
    {
     temp=temp->next;
    }
    (*temp).next=new List{nullptr,element};
}
void insert(List **l,int element,int index)
{
    List *temp=*l;
    if(index==1)
    {
        *l=new List{temp,element};
        return;
    }
    index--;
    while(index!=1&&temp!=nullptr){
        temp=temp->next;
        index--;
    }
    if(index==1)
    {
        List *t=temp->next;
        temp->next=new List{t,element};
        return;
    }

    insert(*l,element);
}
void pop(List **l,int index)
{
    List *temp=*l;
    List *last;
    if(index==1)
    {
        *l=temp->next;
        return;
    }
    while(index!=1&&temp!=nullptr)
    {
        if(index==2)
        {
            last=temp;
        }
        index--;
        temp=temp->next;
    }
    if(index==1)
    {
        last->next=temp->next;
    }
}
void reverse(List **l,List *node)
{
    if(node->next==nullptr)
    {
      *l=node;
      return;
    }
    reverse(l,node->next);
    List *q=node->next;
    q->next=node;
    node->next=nullptr;

}