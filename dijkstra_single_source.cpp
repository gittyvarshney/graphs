#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
vector<vector<int> > vec( 9 , vector<int> (9, MAX)); //sepcify the number of vertices in the graph

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
	m[b].emplace_back(make_pair(a,dist));
	return true;
}

void bfs(map<int,vector<pair<int,int>>> &m, int source)
{
  set<int> min_node; //for storing minimum vertices;
  int temp,index,maxx;
  bool flag;
	set<int> s; //set for storing visited vertices
  queue<int> q; // bfs is implemented using queue so..
  q.push(source); //pushing it to queue
  vec[source][source] = 0;
  //Implementation
  while(!q.empty())
  {
    temp = q.front();
    cout << "at node:: " << temp << ":: ";
    q.pop();
  	for(auto j: m[temp]) // visiting all connected vertices of this vertex
    {
      if(s.count(j.first)<1) //if unvisited vertex
      {
        if(vec[source][temp]+j.second < vec[source][j.first])
        {
          vec[source][j.first] = vec[source][temp] + j.second;
          cout << j.first << "-> " << vec[source][j.first] << ", ";
        }
      }
    }
    cout << "\n";
    s.insert(temp);
    //selecting the minimum
    maxx = MAX;
    flag = false;
    for(int i=0;i<9;i++) //i=10 for 10 nodes in graph
    {
      if(s.count(i)<1 && vec[source][i] < maxx)
      {
        flag = true;
        index = i;
        maxx = vec[source][i];
      }
    }

    if(flag== true)
    {
    q.push(index);
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
    map<int,vector<pair<int,int>>> m; //vector creation using map & vector int
    cout << "implementation of bfs \n";
    add_edge(m,0,1,4);
    add_edge(m,0,4,8);
    add_edge(m,1,4,11);
    add_edge(m,1,2,8);
    add_edge(m,2,3,7);
    add_edge(m,2,6,4);
    add_edge(m,2,8,2);
    add_edge(m,3,6,14);
    add_edge(m,3,7,9);
    add_edge(m,4,8,7);
    add_edge(m,4,5,1);
    add_edge(m,5,8,6);
    add_edge(m,5,6,2);
    add_edge(m,6,7,10);
    int source;
    cout << "specify the source: ";
    cin >> source;
    bfs(m,source);
    cout << "Now Shortest distances to vertices are: \n";
    for(int i=0;i<9;i++)
    {
      cout << i << "->" << vec[source][i] << " :: ";
    }


}
