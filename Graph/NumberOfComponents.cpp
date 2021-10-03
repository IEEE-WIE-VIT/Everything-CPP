/*Progam to count number of edges to connect all connected component
To find number of connected component add 1 to number of egdes
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100010];
int visited[100010];
void dfs(int s)
{
	visited[s]=1;
	for(auto x:adj[s])
	{
		if(!visited[x])
		dfs(x);
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
    int ans=-1;
	vector<pair<int,int>> an;
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
		ans++;
		if(i!=0)
		an.push_back({i,i+1});
		dfs(i);
		}
	}
	cout<<ans<<"\n";
	for(auto x:an)
	cout<<x.first<<" "<<x.second<<"\n";
	return 0;
}