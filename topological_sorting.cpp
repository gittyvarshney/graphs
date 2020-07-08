#include<bits/stdc++.h>
using namespace std;
#define MAX 100005

//The topological sorting is used to ordering the dependency of nodes
//such that nodes are come in order to satify their dependencies
//for topological sorting the graph should be directed obiously
//and there should not be any cycle (in that case we get ciruclar dependency problem)
//first chcek if the graph is cyclic or acyclic if acyclic then we do topological sort in that

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
	set<int> grey;
  set<int> black;
	for(auto i: m)
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

//topological same as depth first search in directed graph but storing the deepest vertex to stack
//storing the visited vertices to set
void topological_utility(map<int,vector<int>>& m, set<int>& visited, stack<int>& st,int i)
{
  for(auto j: m[i])
  {
    if(visited.count(j)< 1)
    {
      visited.insert(j);
      topological_utility(m, visited, st,j);
    }
  }
  st.push(i); //pushing the deepest vertex to stack
}

void topological(map<int,vector<int>>& m,stack<int>& st)
{
  set<int> visited; //for storing visited vertices
  for(auto i: m)
  {
    if(visited.count(i.first)< 1)
    {
      visited.insert(i.first);
      topological_utility(m, visited, st,i.first);
    }
  }
}
//end of implementation

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
  add_edge(m,0,2);
  add_edge(m,1,2);
  add_edge(m,1,3);
  add_edge(m,2,4);
  add_edge(m,3,5);
  add_edge(m,4,7);
  add_edge(m,4,5);
  add_edge(m,5,6);
  cout << "Now traversing the graph using dfs: \n";
  set<int> visited;
  stack<int> st; //for storing vertices in preference order
  if(!dfs_cycle_directed(m))
  {
    topological(m,st);
    cout << "\nToppological order is: ";
    while(!st.empty())
    {
      cout << st.top() << " ";
      st.pop();
    }
  }
  else
  {
    cout << "\ncannot make topological order";
  }

}
