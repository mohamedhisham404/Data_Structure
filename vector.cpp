#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

template<class T>
struct node{
        T data;
        node* next, *pre;

        node(T n=0){
            data=n;
            next=nullptr;
            pre=nullptr;
        }
};

template<class T>
class Vector 
{
private:
    

    node<T>* head,*tail;
    int sz;

public:
    Vector(){
        head=nullptr;
        sz=0;
        tail=nullptr;
    }

    void push_back(T x){
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

    void pop_back(){
        if(!sz)return;
        if(sz==1){
            delete head;
            head=nullptr;
            tail=nullptr;
        }
        else{
            node <T>*prev = tail->pre;
            delete tail;
            tail->next=nullptr;
            tail=prev;
        }
        sz--;
    }

    T &operator [](int idx){  //& to access the element to make something like l[1]++ work
        if (idx>=sz)return head->data;
        
        int d=0;
        node<T> *cur=head;
        while (d < idx){
            cur = cur->next;
            d++;
        }
        return cur->data;
    }
    
    void print(){
        node <T>*cur=head;
        while(cur){
            cout<<cur->data<<"-->";
            cur=cur->next;
        }
        cout<<"null"<<endl;
    }

    ~Vector(){
        node <T>*cur =head;
        while(cur){
            node <T>*temp=cur;
            cur=cur->next;
            delete temp;
        }
    }

};


int main(){
    Vector <double>l;
    l.push_back(1.0);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    // l.print();
    // l[2]=5;
    // cout<<l[2]<<endl;
    // l.print();
    return 0;
}