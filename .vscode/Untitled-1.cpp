#include<bits/stdc++.h>
using namespace std;
const int N=410;
typedef pair<int,int> PII;
int n,m,x,y;
int dist[N][N];
int dx[]={1,2,2,1,-1,-2,-2,-1};
int dy[]={2,1,-1,-2,-2,-2,1,2};
void bfs(){
    memset(dist,-1,sizeof dist);
    queue<PII>q;
    q.push({x,y});
    dist[x][y]=0;
    while(q.size()){
        auto t=q.front();
        q.pop();
        int a=t.first,b=t.second;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(i==0&&j==0) continue;
                int x=a+i,y=b+j;
                if(x<0||x>=n||y<0||y>=m) continue;
                if(dist[x][y]!=-1) continue;
                dist[x][y]=dist[a][b]+1;
                q.push({x,y});
            }
        }
    }
}
int main(){
    cin>>n>>m>>x>>y;
    bfs();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}