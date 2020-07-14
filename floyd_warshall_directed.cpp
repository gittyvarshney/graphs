#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
//flyod warshall all vertex shortest path (in form of matrix obiously) 
//can find shortest distances even for negative edges
// Implemented for directed graph but can be implemented for undirected also

bool add_edge(map<int,vector<pair<int,int>>> &m, int a, int b,int dist)
{
	for(auto i: m[a])
	{
		if(i.first == b)
		{
			return false;
		}
	}
	m[a].emplace_back(make_pair(b,dist));
	return true;
}

vector<vector<int>> floyd_warshall(map<int,vector<pair<int,int>>>& m)
{
	int i,it,j;
	int n = m.size();
	vector<vector<int>> vec(n,vector<int>(n,MAX)); //Creating matrix of (max_vertex x max_vertex)
	for(i=0;i<n;i++) //first traversing whole map to find linear distances
	{
		for(auto j: m[i]) //finding direct distances of connected vertices
		{
			vec[i][j.first] = j.second;
		}
		vec[i][i] = 0; //to itself is 0
	}

	for(it=0;it<n;it++) //every vertex must act as an intermediate vertex
	{
		for(i=0;i<n;i++) //doing this for every element of matrix
		{
			for(j=0;j<n;j++)
			{
				vec[i][j] = min(vec[i][j],vec[i][it] + vec[it][j]);
			}
		}
	}

	return vec;
}

int main()
{
	 /*
    #ifndef ONLINE_JUDGE
      freopen("D:\\Project Sunrise\\input.txt", "r", stdin);
      freopen("D:\\Project Sunrise\\output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    */
    map<int,vector<pair<int,int>>> m; 
    //building graph
    add_edge(m,0,1,9);
    add_edge(m,0,2,-4);
    add_edge(m,1,0,6);
    add_edge(m,1,3,2);
    add_edge(m,2,1,5);
    add_edge(m,3,2,1);

    vector<vector<int>> vec = floyd_warshall(m);

    //printing
    for(auto i: vec)
    {
    	for(auto j: i)
    	{
    		cout << j << "\t";
    	}
    	cout << "\n";
    }
    
    
}
