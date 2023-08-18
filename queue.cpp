#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

template<class T>//for string ,int,....
struct node{
        T data;
        node* next;

        node(T n=0){
            data=n;
            next=nullptr;
        }
};

template<class T>
class Queue 
{
private:
    

    node<T>* head,*tail;
    int sz;

public:
    Queue(){
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
            tail=nw;
        }
    }

    void pop(){
        if(head){
            sz--;
            node <T>*temp=head;
            head=head->next;
            delete temp;
        }
    }

    T front(){
        if(head) return head->data;
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
    ~Queue(){
        node <T>*cur =head;
        while(cur){
            node <T>*temp=cur;
            cur=cur->next;
            delete temp;
        }
    }

};


int main(){
    Queue <int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.print();
    q.pop();
    q.print();
    cout<<q.front()<<endl;

    return 0;
}