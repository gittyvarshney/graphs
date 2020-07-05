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

void bfs(map<int,vector<int>> &m)
{
  int temp;
	set<int> s; //set for storing visited vertices
  queue<int> q; // bfs is implemented using queue so..
  map<int,vector<int>>::iterator it; // for starting with the first vertex of the graph
  it = m.begin(); //first vertex of graph
  cout << it->first << " "; //priting it
  s.insert(it->first); //inserting it to the set
  q.push(it->first); //pushing it to queue

  //Implementation
  while(!q.empty())
  {
    temp = q.front();
    q.pop();
  	for(auto j: m[temp]) // visiting all connected vertices of this vertex
    {
      if(s.count(j)<1) //if new vertex
      {
        q.push(j);
        s.insert(j);
        cout << j << " ";
      }
    }
  }
  //end of implementation
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
    cout << "implementation of bfs \n";
    add_edge(m,0,1);
    add_edge(m,0,2);
    add_edge(m,1,2);
    add_edge(m,1,3);
    add_edge(m,2,4);
    add_edge(m,4,5);
    cout << "Now traversing the graph using bfs: \n";
    bfs(m);


}
