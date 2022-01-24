#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"

ll num,cnt=0;

int main(){
    cin>>num;
    while(num){
        ll temp=num,maxi=0;
        while(temp!=0){
            maxi=max(maxi,temp%10);
            temp/=10;
        }
        cnt++;
        num-=maxi;
    }
    cout<<cnt;
    return 0;
}