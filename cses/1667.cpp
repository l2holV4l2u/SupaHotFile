#include<bits/stdc++.h>

using namespace std;

long long num,m,a,b,cur,dist[100010],pre[100010],visit[100010]={0};
string dis="";
vector <long long> graph[100010];
    
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    memset(dist,1,sizeof(dist));
    cin>>num>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    priority_queue <pair <int,int>,vector <pair <int,int>>,greater <pair <int,int>>> pq;
    pq.push({1,1});
    dist[1]=1;
    pre[1]=-1;
    b=dist[2];
    while(pq.size()){
        tie(a,cur)=pq.top();
        pq.pop();
        if(visit[cur]){
            continue;
        }
        if(cur==num){
            cout<<dist[num]<<endl;
            while(cur!=-1){
                dis=to_string(cur)+" "+dis;
                cur=pre[cur];
            }
            cout<<dis;
            return 0;
        }
        visit[cur]=1;
        for(int i=0;i<graph[cur].size();i++){
            if(dist[cur]+1<dist[graph[cur][i]]){
                dist[graph[cur][i]]=dist[cur]+1;
                pq.push({dist[graph[cur][i]],graph[cur][i]});
                pre[graph[cur][i]]=cur;
            }
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}