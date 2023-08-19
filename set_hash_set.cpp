#include <bits/stdc++.h>
using namespace std;

//by using hash function we can map very large values like 1e10 to small values
//collisions mean that two or more values have the same hash
//there is no optimal solution for collisions
// but we can use vector of vectors to add the numbers

// In the average case, the time complexity of the hash set 
// operations is O(1), 
// but in the worst case (when there are many hash collisions)
// , the time complexity can be as bad as O(n).

const int T_size=15299;
#define endl "\n"

class HashSet{
private:
    // if we put the size of array as prime number that reduces the collisions
    vector<int>table[T_size];
    int hash_func(int x){return ((x+T_size)%T_size)%T_size;} 

public:

    void insert(int x){
        int hash=hash_func(x);
        for(auto v:table[hash]){
            if(v==x)return;
        }
        table[hash].push_back(x);
    }

    bool contain(int x){
        int hash=hash_func(x);
        for(auto v:table[hash]){
            if(v==x)return true;
        }
        return false;
    }

    void remove(int x){
        int hash=hash_func(x);
        for(auto v:table[hash]){
            if(v==x){
                table[hash].erase(find(table[hash].begin(),table[hash].end(),x));
                return;
            }
        }
    }
     
};
int main(){
    HashSet st;

    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(4);
    st.insert(5);
    st.remove(1);
    if(st.contain(1)){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }

    return 0;
}