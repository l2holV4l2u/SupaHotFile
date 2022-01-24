#include<bits/stdc++.h>

using namespace std;

int num,m,a,b,cnt,visit[100010]={0};
vector <int> graph[100010],dis;

void dfs(int cur){
    for(int i=0;i<graph[cur].size();i++){
        if(!visit[graph[cur][i]]){
            visit[graph[cur][i]]=1;
            dfs(graph[cur][i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>num>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=num;i++){
        if(!visit[i]){
            dis.push_back(i);
            cnt++;
            dfs(i);
        }
    }
    cout<<max(0,cnt-1)<<endl;
    for(int i=1;i<dis.size();i++){
        cout<<dis[i-1]<<" "<<dis[i]<<endl;
    }
    return 0;
}