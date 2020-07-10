#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
//this algorithm works once
// disjoint_sets to make sure there is no cycle forming
// priority queue which always gives the minimum element from the queue

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

//Disjoint_sets for cycle detection
class disjoint_sets
{

	unordered_map<int,int> parent;
	unordered_map<int,int> rank; //ranking is done so that optimized tree is maintained

public:
	void make_set(int vertex)
	{
		parent[vertex] = vertex; //defining itself as as parent
		rank[vertex] = 0;
	}

	int find_set(int vertex) //recursive function to find the parent of disj_element
	{
		if(parent[vertex] == vertex)
		{
			return vertex;
		}
		else
		{
			parent[vertex] = find_set(parent[vertex]);
			return parent[vertex];
		}
	}

	void do_union(int m,int n) //i.e. making the parents same of these elements
	{
		int x = find_set(m); //find parent of m;
		int y = find_set(n); //find parent of n;
		if(rank[x] == rank[y]) //if ranks are equal
		{
			parent[y] = x; //now parent of y is x
			rank[y] = 0; //make rank of y as zero
			rank[x]++; //increment the rank of x
		}
		else
		{
			if(rank[x]>rank[y])
			{
				parent[y] = x;
				rank[y] = 0;
			}
			else
			{
				parent[x] = y;
				rank[x] = 0;
			}
		}

	}
};
//end of disjoint sets

//priority queue class for edges
class Edge
{
   int edge_a; //vertex 1
   int edge_b; //vertex 2
   int dist;//there intermediate distances
public:
   Edge(int _x, int _y, int _dist) //constructor
   {
      edge_a = _x;
      edge_b = _y;
      dist = _dist;
   }
   int get_first() //get first vertex
   {
     return edge_a;
   }
   int get_second() //get second vertex
   {
     return edge_b;
   }
   int get_dist() //get intermediate distance
   {
     return dist;
   }
};

// To compare the edges
class myComparator //comparator function for priority_queue
{
public:
    int operator() (Edge& p1, Edge& p2) //compare edges in increasing order
    {
      return p1.get_dist() > p2.get_dist();
    }
};


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
    map<int,vector<pair<int,int>>> m; //vector creation using map & vector int
    cout << "implementation of bfs \n";
    add_edge(m,0,1,3);
    add_edge(m,0,3,1);
    add_edge(m,1,3,3);
    add_edge(m,1,2,1);
    add_edge(m,3,2,1);
    add_edge(m,3,4,6);
    add_edge(m,2,4,5);
    add_edge(m,2,5,4);
    add_edge(m,5,4,2);
    //inserting all edges to priority priority_queue
    priority_queue <Edge, vector<Edge>, myComparator > pq; //priority_queue of class Edge
    set<int> visited;
    for(int i=0;i<6;i++)
    {
      for(auto j: m[i])
      {
        if(visited.count(j.first)<1)
        {
          pq.push(Edge(i,j.first,j.second));
        }
      }
      visited.insert(i);
    }

    //having 5 vertices make sets
    disjoint_sets dis;
    for(int i=0;i<6;i++)
    {
      dis.make_set(i);
    }

    int sum=0;
    //implementation
    while(!pq.empty())
    {
      Edge temp = pq.top();
      if(dis.find_set(temp.get_first()) != dis.find_set(temp.get_second()))
      {
        dis.do_union(temp.get_first(),temp.get_second());
        cout << temp.get_first() << "-" << temp.get_second() << "= " << temp.get_dist() << "\n";
        sum += temp.get_dist();
      }
      pq.pop();
    }
    cout << "minimum spanning tree sum: " << sum << "\n";
}
