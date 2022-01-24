#include<bits/stdc++.h>

using namespace std;

long long tab[1000010]={0},num;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>num;
    tab[0]=1;
    for(int i=1;i<=num;i++){
        for(int j=1;j<=6&&i>=j;j++){
            tab[i]+=tab[i-j];
        }
        tab[i]%=1000000007;
    }
    cout<<tab[num];
    return 0;
}