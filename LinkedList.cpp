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
        node* next;

        node(T n=0){
            data=n;
            next=nullptr;
        }
};

template<class T>
class LinkedList 
{
private:
    

    node<T>* head;
    int sz;

public:
    LinkedList(){
        head=nullptr;
        sz=0;
    }

    void push_back(T x){
        node <T>*nw=new node(x);
        sz++;
        if(!head){ // if head is null
            head=nw;
        }
        else{
            node <T>*cur=head;
            while(cur->next){
                cur=cur->next;
            }
            cur->next=nw;
        }
    }

    int getData(T idx){
        if (idx>=sz)return -1;
        
        int d=0;
        node<T> *cur=head;
        while (d < idx){
            cur = cur->next;
            d++;
        }
        return cur->data;
    }

    void removeData(T x){
        if (!head)return ;
        
        node <T>*cur=head;
        if(cur->data==x){  //check if what we want to delete is in first node
            head=head->next;
            delete cur;
        }
        else{
            while(cur->next && cur->next->data!=x){ //cur->next : to make sure that you have next node to avoid run time error
                cur=cur->next;
            }
            if(!cur->next)return;
            if(cur->next){
                node <T>*temp=cur->next;
                cur->next=cur->next->next;
                delete temp;
            }
        }
        sz--;
    }

    void removeidx(int idx){
        if (idx>=sz)return ;
        if(idx==0){
            head=head->next;
        }
        else{
            node<T> *cur=head;
            int d=0;
            while(d<idx-1){
                cur=cur->next;
                d++;
            }
            cur->next=cur->next->next;
        }
        sz--;
    }

    void print(){
        node <T>*cur=head;
        while(cur){
            cout<<cur->data<<"-->";
            cur=cur->next;
        }
        cout<<"null"<<endl;
    }

    void reverseList(LinkedList &ls) {
        // Initialize current, previous and next pointers
        node <T>*current = head;
        node <T>*prev = NULL, *next = NULL;
 
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
    }

    //it is important to delete all nodes
    //because all linked list is created in heap
    ~LinkedList(){
        node <T>*cur =head;
        while(cur){
            node <T>*temp=cur;
            cur=cur->next;
            delete temp;
        }
    }

};


int main(){
    LinkedList <double>l;
    l.push_back(1.0);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    // cout<<l.getData(0)<<endl;   //1
    // l.removeData(1);   //2-->3-->4-->null
    // l.removeidx(2);    //2-->3-->null
    l.print();
    l.reverseList(l);
    l.print();
    return 0;
}