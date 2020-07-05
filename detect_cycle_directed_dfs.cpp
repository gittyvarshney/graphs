#include<bits/stdc++.h>
using namespace std;
#define MAX 100005

//black set implementation
//grey set implementation
bool add_edge(map<int,vector<int>> &m, int a, int b)
{
	for(auto i: m[a])
	{
		if(i == b)
		{
      cout << "node exits \n";
			return false;
		}
	}
	m[a].emplace_back(b); //for directed graph we can only have one relation
	return true;
}

bool dfs_util(map<int,vector<int>> &m, set<int> &grey, set<int> &black, int i)
{
	for(auto j: m[i])
	{
    cout << "at node: " << i << " to " << j << "\n";
		if(black.count(j)<1 && grey.count(j)<1)
		{
			grey.insert(j);
			if(dfs_util(m,grey,black,j))
      {
        return true;
      }
		}
    else if(grey.count(j) == 1)
    {
      cout << "cycle found at node: " << i << "to " << j;
      return true;
    }
	}
  grey.erase(i);
  black.insert(i);
  return false;
}


bool dfs_cycle_directed(map<int,vector<int>> &m)
{
	set<int> grey; //if found in grey set then there is a cycle
  set<int> black; //if all vertices connected to particular vertex visited then push it
	for(auto i: m)// to black set
	{
		if(black.count(i.first)<1)
		{
			grey.insert(i.first);
			if(dfs_util(m,grey,black,i.first)) //if cycle found return true
      {
        return true;
      }
		}
	}
  return false;
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
    //implementation of undirected graph
    map<int,vector<int>> m; //vector creation using map & vector int
    cout << "implementation of dfs \n";
    add_edge(m,1,2);
    add_edge(m,2,3);
    add_edge(m,1,3);
    add_edge(m,4,1);
    add_edge(m,4,5);
    add_edge(m,5,6);
    add_edge(m,6,4);
    cout << "Now traversing the graph using dfs: \n";
    dfs_cycle_directed(m);


}
