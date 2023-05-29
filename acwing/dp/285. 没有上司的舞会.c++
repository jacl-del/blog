/**
 *    author:  jacl
 *    created: 29.05.2023 18:23:28       
**/
#include<iostream>
#include<cstring>
using namespace std;
const int N=60010;
int h[N],e[N],ne[N],idx;
int happy[N];
bool has_fa[N];
int f[N][2];
void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void dfs(int u)
{
    f[u][1]=happy[u];
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        dfs(j);
        f[u][1]+=f[j][0];
        f[u][0]+=max(f[j][0],f[j][1]);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>happy[i];
    memset(h,-1,sizeof h);
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        has_fa[a]=true;
        add(b,a);
    }
    int root=1;
    while(has_fa[root]) root++;
    dfs(root);
    cout<<max(f[root][0],f[root][1])<<endl;
}