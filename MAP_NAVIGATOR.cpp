#include<bits/stdc++.h>
using namespace std;
//#define INT_MAX 100000
void relax(priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >& p_q,int node,int distance)
{
    vector<pair<int,int>> vec;
    while(p_q.top().second != node){
        pair<int,int> ans=p_q.top();
        p_q.pop();
        vec.push_back(ans);
    }
    pair<int,int>ans=p_q.top();
    p_q.pop();
    if(distance<ans.first){
        ans=make_pair(distance,node);
    p_q.push(ans);
    }
    else
    p_q.push(ans);
    for(int i=0;i<vec.size();i++)
    p_q.push(vec[i]);
    return ;
}

void Dijkstra(vector<vector<int> >& adj,vector<int>& answer,int node)
{
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > p_q;
    pair<int,int> a=make_pair(0,0);
    p_q.push(a);
    for(int i=1;i<adj.size();i++){
        pair<int,int> ans=make_pair(INT_MAX,i);
        p_q.push(ans);
    }
    
    vector<bool> visited(adj.size(),0);
    while(!p_q.empty())
    {
        int nd=p_q.top().second;
        int distance=p_q.top().first;
        p_q.pop();
        if(visited[nd]==true)continue;
        visited[nd]=true;
        answer[nd]=distance;
        for(int i=0;i<adj[nd].size();i++)
        {
        if(adj[nd][i]!=0 && !visited[i]){
            relax(p_q,i,distance+adj[nd][i]);
        }
        }
    }
    return;
}

int main(){
    
    int n;
    
    cin>>n;
    vector<vector<int> > adj(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        }
    }
    vector<int> answer(adj.size(),0);
    Dijkstra(adj,answer,0);
    for(int i=0;i<adj.size();i++)
    cout<<answer[i]<<" ";
}