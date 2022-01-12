#include<iostream>

#define MININT -32768
#define MAXINT 32767
using namespace std;


//structure of linkedlist
struct node{
    int data;
    node *next;
}*head,*temp;


//1.function to insert elements into linkedlist

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

//2.function to display elements of linkedlist

void display(node *np){
    while(np!=NULL){
        cout<<np->data<<"->";
        np=np->next;
    }
}

//3.function to count elements of linkedlist

int count(node *np){
    int c=0;
    while(np!=NULL){
        c++;
        np=np->next;
    }
    return c;
}


//4.recursive function to count elements of linkedlist

int count_recursive(node *np){
    int c=0;
    if(np==NULL)
        return 0;
    else{
        return count_recursive(np->next)+1;
    }
}

//5.function to add elements of linkedlist

int add(node *np){
    int sum=0;
    
    while(np){
        sum+=np->data;
        np=np->next;
    }
    return sum;
}

//6.recursive function to add elements of  linkedlist

int add_recursive(node *np){
    int sum=0;
    if(np==NULL){
        return 0;
    }else{
        return add_recursive(np->next)+np->data;
    }
    return sum;
}

//7.function to find largest of all elements of linkedlist
int max(node *np){
    int m=MININT;
    while(np){
        if(np->data>m)
            m=np->data;
        np=np->next;
    }
    return m;
}

//8. recursive function to find largest of all elements of linkedlist

int max_recursive(node *np){
    int m;
    if(np==0)
        return MININT;
    m=max_recursive(np->next);
    return m>np->data?m:np->data;
}


//9.function to find smallest of all elements of linkedlist

int min(node *np){
    int m=MAXINT;
    while(np){
        if(np->data<m)
            m=np->data;
        np=np->next;
    }
    return m;
}

//10.recursive function to find smallest of all elements of linkedlist

int min_recursive(node *np){
    int m;
    if(np==0)
        return MAXINT;
    m=min_recursive(np->next);
    return m<np->data?m:np->data;
}


//main function

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
    cout<<"Using recursion,total number of element is:"<<count_recursive(head)<<endl;
    cout<<"Total sum of all element is:"<<add(head)<<endl;
    cout<<"Using recursion,total sum of all element is:"<<add_recursive(head)<<endl;
    cout<<"The maximum of all numbers is:"<<max(head)<<endl;
    cout<<"Using recursion,the maximum of all numbers is:"<<max_recursive(head)<<endl;
    cout<<"The minimum of all numbers is:"<<min(head)<<endl;
    cout<<"Using recursion,the minimum of all numbers is:"<<min_recursive(head)<<endl;
    return 0;
}