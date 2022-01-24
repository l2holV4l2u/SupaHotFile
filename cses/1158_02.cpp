#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int num,x,temp,dat[100010][2]={0},dis=0,price[1010],page[1010];
    cin>>num>>x;
    for(int i=0;i<num;i++){
        cin>>price[i];
    }
    for(int i=0;i<num;i++){
        cin>>page[i];
    }
    for(int i=0;i<num;i++){
        temp=i%2;
        for(int j=0;j<=x;j++){
            dat[j][temp]=dat[j][!temp];
        }
        if(price[i]<=x){
            dat[price[i]][temp]=max(dat[price[i]][temp],page[i]);
            dis=max(dis,dat[price[i]][temp]);
        }
        for(int j=price[i]+1;j<=x;j++){
            if(dat[j-price[i]][!temp]){
                dat[j][temp]=max(dat[j][temp],dat[j-price[i]][!temp]+page[i]);
                dis=max(dis,dat[j][temp]);
            }
        }
    }
    cout<<dis;
    return 0;
}