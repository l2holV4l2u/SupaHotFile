#include<bits/stdc++.h>

using namespace std;

int row,col,visit[1010][1010]={0},coor[4]={1,-1,0,0};
string tab[1010];

bool isvalid(int cr,int cc){
    return cr>=0&&cr<row&&cc>=0&&cc<col;
}

void dfs(int cr,int cc){
    visit[cr][cc]=1;
    for(int i=0;i<4;i++){
        if(isvalid(cr+coor[i],cc+coor[3-i])&&!visit[cr+coor[i]][cc+coor[3-i]]&&tab[cr+coor[i]][cc+coor[3-i]]=='.'){
            dfs(cr+coor[i],cc+coor[3-i]);
        }
    }
}

int main(){
    cin>>row>>col;
    for(int i=0;i<row;i++){
        cin>>tab[i];
    }
    int cnt=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(!visit[i][j]&&tab[i][j]=='.'){
                cnt++;
                dfs(i,j);  
            }
        }
    }
    cout<<cnt;
    return 0;
}