#include<bits/stdc++.h>
using namespace std;

//Disjoint sets basically works on the funda of having 
//a same identity or relationship among serveral elements
//which can be done by making same parent for all elements
//In disjoint_sets mainly 3 operations are performed:-
//1- make set i.e. defining the parent of a particular node (itself)
//2- union i.e. if do sets having different parent then making them same
//3- find set finds the parent of an element
//Tushar roy disjoint sets for reference
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

int main()
{
	vector<int> nodes{1,2,3,4,5,6};
	disjoint_sets dis;
	for(int i=0;i<6;i++)
	{
		dis.make_set(i+1);
	}

	dis.do_union(1,2);
	dis.do_union(2,3);
	dis.do_union(4,5);
	dis.do_union(5,6);
	dis.do_union(2,5);

	if(dis.find_set(6) == dis.find_set(3))
	{
		cout << "In the same set " << endl;
	}
}