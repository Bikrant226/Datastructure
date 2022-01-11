#include<iostream>

using namespace std;

struct node{
    int data;
    node *next;
}*head,*temp;


void insert(int val){
    node *newnode=new node;
    newnode->data=val;
    
    if(head==NULL){
        newnode->next=head;
        head=newnode;
    }else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}


void display(node *np){
    while(np!=NULL){
        cout<<np->data<<"->";
        np=np->next;
    }
}

int count(node *np){
    int c=0;
    while(np!=NULL){
        c++;
        np=np->next;
    }
    return c;
}



int count_recursive(node *np){
    int c=0;
    if(np==NULL)
        return 0;
    else{
        return count_recursive(np->next)+1;
    }
}

int add(node *np){
    int sum=0;
    
    while(np){
        sum+=np->data;
        np=np->next;
    }
    return sum;
}

int add_recursive(node *np){
    int sum=0;
    if(np==NULL){
        return 0;
    }else{
        return add_recursive(np->next)+np->data;
    }
    return sum;
}

int main(){
    head=NULL;
    insert(25);
    insert(40);
    insert(20);
    insert(11);
    insert(100);
    insert(33);
    cout<<"Elements are:\n";
    display(head);
    cout<<"\n";
    cout<<"Total number of element is:"<<count(head)<<endl;
    cout<<"Total number of element recursively is:"<<count_recursive(head)<<endl;
    cout<<"Total sum of all element is:"<<add(head)<<endl;
    cout<<"Total sum of all element using recursion  is:"<<add_recursive(head)<<endl;
    return 0;
}