/*
Program to check whether given graph is bipartitie or not
If it is bipartite then print colour of each node
Else print Impossible
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100010];
int visited[100010];
int f=1;
void bfs(int s)
{	
	visited[s]=1;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int n=q.front();
		q.pop();
		for(auto x:adj[n])
		{
			if(visited[x]==visited[n])
			f=0;
			if(!visited[x])
			{
				visited[x]= 1+visited[n]%2;
				q.push(x);
			}
		}
	}
}
int main()
{
	int m,n;
	cin>>n>>m;
	memset(visited,0,sizeof(visited));
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		bfs(i);
	}
	if(f)
	{for(int i=0;i<n;i++)
	cout<<visited[i]<<" ";}
	else
	cout<<"IMPOSSIBLE";
	return 0;
}