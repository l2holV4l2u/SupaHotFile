#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
ll num,x,dat[1000010],dp[1000010]={0};
 
int main(){
    cin>>num>>x;
    for(int i=1;i<=num;i++){
        cin>>dat[i];
        dp[dat[i]]=1;
    }    
    sort(dat+1,dat+num+1);
    for(int i=1;i<=x;i++){
        for(int j=1;j<=num;j++){
            if(i-dat[j]<0){
                break;
            }
            dp[i]+=dp[i-dat[j]];
        }
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    cout<<dp[x];
    return 0;
}