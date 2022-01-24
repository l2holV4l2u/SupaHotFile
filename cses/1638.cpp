#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
#define mod 1000000007

ll num,dp[1010][1010]={0};
string tab[1010];

int main(){
    cin>>num;
    dp[1][1]=1;
    cin>>tab[1];
    for(int j=2;j<=num;j++){
        if(tab[1][j-1]=='.'){
            dp[1][j]=dp[0][j]+dp[1][j-1];
        }
    }
    for(int i=2;i<=num;i++){
        cin>>tab[i];
        for(int j=1;j<=num;j++){
            if(tab[i][j-1]=='.'){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
                dp[i][j]%=mod;
            }
        }
    }
    if(tab[1][0]=='*'){
        cout<<0;
        return 0;
    }
    cout<<dp[num][num];
    return 0;
}