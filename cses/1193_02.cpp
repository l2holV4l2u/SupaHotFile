#include<bits/stdc++.h>

using namespace std;

int row,col,cr,cc,ch,coor[4]={1,-1,0,0},dist[1010][1010];
string tab[1010],dis[1010][1010],temp;

bool isvalid(int cr,int cc){
    return cr>=0&&cr<row&&cc>=0&&cc<col;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>row>>col;
    for(int i=0;i<row;i++){
        cin>>tab[i];
    }
    memset(dist,1,sizeof(dist));
    temp="DULR";
    ch=dist[0][0];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(tab[i][j]=='A'){
                queue <pair <int,int>> bfs;
                bfs.push({i,j});
                dist[i][j]=0;
                while(bfs.size()){
                    tie(cr,cc)=bfs.front();
                    bfs.pop();
                    for(int k=0;k<4;k++){
                        if(isvalid(cr+coor[k],cc+coor[3-k])&&tab[cr+coor[k]][cc+coor[3-k]]!='#'){
                            if(dist[cr+coor[k]][cc+coor[3-k]]>dist[cr][cc]+1){
                                dist[cr+coor[k]][cc+coor[3-k]]=dist[cr][cc]+1;
                                bfs.push({cr+coor[k],cc+coor[3-k]});
                                dis[cr+coor[k]][cc+coor[3-k]]=dis[cr][cc]+temp[k];
                            }
                        }
                    }  
                }
            }
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(tab[i][j]=='B'){
                if(tab[i][j]==ch){
                    cout<<"NO";
                    return 0;
                }
                cout<<"YES\n"<<dist[i][j]<<endl<<dis[i][j];
            }
        }
    }
    return 0;
}