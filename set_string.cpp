#include <bits/stdc++.h>
using namespace std;

const int T_size=15299;
#define endl "\n"

class HashSet{
private:
    // here we use polynomial rolling hash function to hash strings
    vector<string>table[T_size];
    int hash_func(string s){
        int n=s.size();
        int hash=0;
        int pow_p=1;
        for(int i = 0; i < n; i++){
            hash=(hash+((s[i]-'a'+1)*pow_p))%T_size;
            pow_p=(pow_p*7)%T_size; // % to avoid overflow
        }
        return hash;
    } 

public:

    void insert(string x){
        int hash=hash_func(x);
        for(auto v:table[hash]){
            if(v==x)return;
        }
        table[hash].push_back(x);
    }

    bool contain(string x){
        int hash=hash_func(x);
        for(auto v:table[hash]){
            if(v==x)return true;
        }
        return false;
    }

    void remove(string x){
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
    
    st.insert("abc");
    st.insert("bca");
    if(st.contain("cab")){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
    return 0;
}