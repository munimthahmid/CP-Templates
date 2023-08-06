#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define all(x) x.begin(),x.end()
const int N=10e5+10;
const int INF=1e9+10;
typedef long long int ll;
void print(vector<ll>&num)
{
    for(int i=0;i<num.size();i++)
    {
        cout<<num[i]<<" "; 
    }
    cout<<endl;

}
void dfs(ll vertex,vector<bool>&visited,vector<vector<ll>>&graph)
{
    visited[vertex]=true;
    for(auto child:graph[vertex])
    {
        if(!visited[child]) dfs(child,visited,graph);
    }
}
void dfstree(ll vertex,ll parent,vector<vector<ll>>&graph)
{
    for(ll child:graph[vertex])
    {
        if(child==parent) continue;
        dfstree(child,vertex,graph);
    }
 
}
void bfs(int source,vector<bool>&visited,vector<vector<ll>>&graph,vector<ll>&level)
{
    queue<ll>q;
    q.push(source);
    visited[source]=true;
    while(!q.empty())
    {
        ll cur_v=q.front();
        q.pop();
        for(auto child:graph[cur_v])
        {
            if(!visited[child])
            {
                q.push(child);
                visited[child=true];
                level[child]=level[cur_v]+1;
            }

        }
    }
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
    ll n;
    cin>>n;
    vector<int>leaf(n+1,0);
   vector<vector<int>>graph(n+1);
   for(int i=0;i<n-1;i++)
   {
    int u, v;
    cin>>u>>v;
    graph[u].push_back(v);
    graph[v].push_back(u);
   }
   dfs(1,0,graph,leaf);
   int q;
   cin>>q;
   for(int i=0;i<q;i++)
   {
    int u,v;
    cin>>u>>v;
    ll a=leaf[u];
    ll b=leaf[v];
    ll ans=a*b;
    cout<<ans<<endl;
   }
   
 
 
 
 
 
    }
    
 
}