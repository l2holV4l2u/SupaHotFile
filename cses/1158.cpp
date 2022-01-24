#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"

int main(){
    ll dis=0,num,dat[1010][2],x,dp[1010][2]={0};//money page
    cin>>num>>x;
    for(int i=1;i<=num;i++){
        cin>>dat[i][0];
    }
    for(int i=1;i<=num;i++){
        cin>>dat[i][1];
    }
    for(int i=1;i<=num;i++){
        for(int j=0;j<i;j++){
            if(dp[j][0]+dat[i][0]<=x){
                if(dp[j][1]+dat[i][1]>dp[i][1]){
                    dp[i][1]=dp[j][1]+dat[i][1];
                    dp[i][0]=dp[j][0]+dat[i][0];
                }
            }
        }
        dis=max(dis,dp[i][1]);
    }
    cout<<dis;
    return 0;
}
/*
10 10
1 2 10 6 5 1 7 4 10 4
6 3 8 1 7 3 8 6 5 6
*/