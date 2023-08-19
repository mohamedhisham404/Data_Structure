#include <bits/stdc++.h>
using namespace std;

const int T_size=15299;
#define endl "\n"

class HashMap{
private:
    vector<pair<string,int>>table[T_size];
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

    void put(string key,int val){
        int hash=hash_func(key);
        for(auto v:table[hash]){
            if(v.first==key){
                v.second=val;
                return;
            }
        }
        table[hash].push_back({key,val});
    }

    bool contain(string key){
        int hash=hash_func(key);
        for(auto v:table[hash]){
            if(v.first==key)return true;
        }
        return false;
    }

    int get(string key){
        int hash=hash_func(key);
        for(auto v:table[hash]){
            if(v.first==key)return v.second;
        }
        return false;
    }

    int& operator [](string key){
        int hash=hash_func(key);
        for(auto &v:table[hash]){
            if(v.first==key)return v.second;
        }
        table[hash].push_back({key,0});
        return table[hash].back().second;
    }

    void remove(string key){
        int hash=hash_func(key);
        for(auto v:table[hash]){
            if(v.first==key){
                table[hash].erase(find(table[hash].begin(),table[hash].end(),v));
                return;
            }
        }
    }
     
};
int main(){
    HashMap mp;
    
    mp.put("a",1);
    mp.put("b",2);
    mp.put("c",3);
    mp.remove("b");
    cout<<mp.contain("b")<<endl;

    mp["c"]=4;
    cout<<mp["c"];
   
    return 0;
}