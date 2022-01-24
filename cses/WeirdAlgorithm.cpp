#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    ll num;
    cin>>num;
    while(num!=1){
        cout<<num<<" ";
        if(num%2){
            num*=3;
            num++;
        }
        else{
            num/=2;
        }
    }
    cout<<1;
    return 0;
}