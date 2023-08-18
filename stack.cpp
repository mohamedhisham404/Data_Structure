#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

//any thing in the stack is auto deleted at the end of the scope
//any local varaible is located in the stack
// int *arr = new int[n];    to create object in heap
//you should delete heap object(you can do it by destructor or delete keyword)
// pointers deal with heap  


template<class T>//for string ,int,....
struct node{
        T data;
        node* next,*pre;

        node(T n=0){
            data=n;
            next=nullptr;
            pre=nullptr;
        }
};

template<class T>
class Stack 
{
private:
    

    node<T>* head,*tail;
    int sz;

public:
    Stack(){
        head=nullptr;
        sz=0;
    }

    void push(T x){
        node <T>*nw=new node(x);
        sz++;
        if(!head){ // if head is null
            head=nw;
            tail=nw;
        }
        else{
            tail->next=nw;
            nw->pre=tail;
            tail=nw;
        }
    }

    void pop(){
        if(tail){
            node <T>*temp=tail;
            tail=tail->pre;
            tail->next=nullptr;
            delete temp;
        }
    }

    T top(){
        if(tail) return tail->data;
        else return -1;
    }
    void print(){
        node <T>*cur=head;
        while(cur){
            cout<<cur->data<<"-->";
            cur=cur->next;
        }
        cout<<"null"<<endl;
    }

    int size(){
        return sz;
    }

    //it is important to delete all nodes
    //because all linked list is created in heap
    ~Stack(){
        node <T>*cur =head;
        while(cur){
            node <T>*temp=cur;
            cur=cur->next;
            delete temp;
        }
    }

};


int main(){
    Stack <int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.print();
    s.pop();
    s.print();
    cout<<s.top()<<endl;

    return 0;
}