#include<bits/stdc++.h>

using namespace std;

string tab[1010],direc[4]={"D","U","L","R"};
int row,col,coor[4]={1,-1,0,0},flag=0,len[1010][1010],pre[1010][1010];
pair <int,int> beg,fin,cur;

bool isvalid(int cr,int cc){
    return cr>=0&&cr<row&&cc>=0&&cc<col;
}

void bfs(int cr,int cc){
    if(tab[cr][cc]=='B'){
        flag=1;
    }
    for(int i=0;i<4;i++){
        if(isvalid(cr+coor[i],cc+coor[3-i])){
            if(tab[cr+coor[i]][cc+coor[3-i]]!='#'){
                if(len[cr+coor[i]][cc+coor[3-i]]>len[cr][cc]+1){
                    len[cr+coor[i]][cc+coor[3-i]]=len[cr][cc]+1;
                    pre[cr+coor[i]][cc+coor[3-i]]=i;
                    bfs(cr+coor[i],cc+coor[3-i]);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>row>>col;
    for(int i=0;i<row;i++){
        cin>>tab[i];
        for(int j=0;j<col;j++){
            if(tab[i][j]=='A'){
                beg={i,j};
            }
            else if(tab[i][j]=='B'){
                fin={i,j};
            }
        }
    }
    memset(pre,-1,sizeof(pre));
    memset(len,1,sizeof(len));
    len[beg.first][beg.second]=0;
    pre[beg.first][beg.second]=-1;
    bfs(beg.first,beg.second);
    if(!flag){
        cout<<"NO";
    }
    else{
        cout<<"YES\n"<<len[fin.first][fin.second]<<endl;
        string dis="";
        cur=fin;
        int temp;
        while(pre[cur.first][cur.second]!=-1){
            dis=direc[pre[cur.first][cur.second]]+dis;
            temp=pre[cur.first][cur.second];
            cur.first-=coor[temp];
            cur.second-=coor[3-temp];
        }
        cout<<dis;
    }
    return 0;
}