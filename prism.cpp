#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
//this algorithm works one
// priority queue which always gives the minimum element from the queue
// visit a vertex and enter all its edges to the priorit queue
// then takes the minimum of the edges and enter all its edges to the priority queue

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
    int i = 0; //take any of the vertex as initial 
    visited.insert(i);
    int iterator = 0;
    int sum=0;
    while(iterator<5) // O(V*E) if edges equal 5 then terminate the loop
    {
      for(auto j: m[i]) // pushing all connected edges to the priority queue if not visited
      {
        if(visited.count(j.first)<1)
        {
          pq.push(Edge(i,j.first,j.second));
        }
      }

      while(true)
      {
        Edge temp = pq.top();
        if(visited.count(temp.get_second())<1) //if not visited edge then consider it
        {
          cout << temp.get_first() << "-" << temp.get_second() << "= " << temp.get_dist() << "\n";
          i = temp.get_second(); // make i the new vertex
          sum+= temp.get_dist(); //adding the edge distance
          visited.insert(i); //inserting the vertex of minimum distance
          pq.pop(); // pop out the used edge
          break;
        }
        else
        {
          pq.pop(); // pop the visited edge from priority queue
        }
      }
        iterator++; // increment the edges counter
    } 
    //having 5 vertices make sets
    cout << "minimum spanning tree sum: " << sum << "\n";
}
