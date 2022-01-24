#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007

ll num,dp[1000010];
    
int main(){
    cin>>num;
    for(int i=1;i<=6;i++){
        dp[i]=1;
    }
    for(int i=1;i<=num;i++){
        for(int j=1;j<=6&&i-j>=0;j++){
            dp[i]+=dp[i-j];
        }
        dp[i]%=mod;
    }
    cout<<dp[num];
    return 0;
}