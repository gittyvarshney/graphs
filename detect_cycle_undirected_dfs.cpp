#include<bits/stdc++.h>
using namespace std;
#define MAX 100005

bool add_edge(map<int,vector<int>> &m, int a, int b)
{
	for(auto i: m[a])
	{
		if(i == b)
		{
			return false;
		}
	}
	m[a].emplace_back(b);
	m[b].emplace_back(a);
	return true;
}

//here k is used to tell that k is the source path so it doesnlt consider it in cycle
bool dfs_util(map<int,vector<int>> &m, set<int> &s,int i,int k)
{
  //int from = k;
	for(auto j: m[i])
	{
		if(s.count(j)<1)
		{
			s.insert(j);
			if(dfs_util(m,s,j,i)) //passing i as k to remember the souce vertex is not creating cycle
      {
        return true;
      }
		}
    else if(j != k) //it is the condition that k should not be considered as cycle
    { //other than k is considered to be cycle
      cout << "cycle found at edge : " << i << " to edge: " << j << "\n";
      return true;
    }
	}
  return false;
}


bool dfs_cycle(map<int,vector<int>> &m)
{
	set<int> s;
	for(auto i: m)
	{
		if(s.count(i.first)<1)
		{
			s.insert(i.first);
			if(dfs_util(m,s,i.first,-1)) //if cycle found return true
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
    add_edge(m,0,1);
    add_edge(m,1,2);
    add_edge(m,2,3);
    add_edge(m,3,4);
    add_edge(m,4,5);
    add_edge(m,5,2);
    cout << "Now traversing the graph using dfs: \n";
    dfs_cycle(m);


}
