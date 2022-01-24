//แต่ละค่าเกิดจากเลข dat แต่ละตัวประกอบขึ้นมา
#include<bits/stdc++.h>

using namespace std;

long long num,x,dat[110],tab[1000010];

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>num>>x;
    for(int i=0;i<num;i++){
        cin>>dat[i];
    }
    tab[0]=1;
    for(int i=0;i<num;i++){
        for(int j=dat[i];j<=x;j++){
            tab[j]+=tab[j-dat[i]];
            tab[j]%=1000000007;
        }
    }
    cout<<tab[x];
    return 0;
}