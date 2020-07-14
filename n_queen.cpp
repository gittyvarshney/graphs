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
	return true;
}

void build_graph(map<int,vector<int>>& m, int vertices)
{
	int i=0;
	int rem;
	int j;
	int temp;
	while(i<(vertices*(vertices-1))) //making relations for edges upto 0->11
	{
		rem = i/vertices;
		for(j=0;j<vertices;j++)
		{
			temp = ((i+j)%vertices) + vertices*(1 + (i/vertices));
			if(temp%vertices != rem && temp%vertices != rem+1 && temp%vertices != rem-1)
			{
				add_edge(m,i,temp);
			} 
		}
	}
}

void make_invalid(vector<vector<int>>& vec, int vertices, int ver)
{
	int temp_i = ver/2;
	int temp_j = ver%2;

	//downward
	int i = temp_i;
	int j = temp_j;
	while(i+1 <vertices)
	{
		vec[i][j] = 0;
		i = i+1;
	}

	//vertical left
	i = temp_i;
	while(j-1>=0 && i+1<vertices)
	{
		vec[i+1][j-1] = 0;
		i = i+1;
		j = j-1;
	}

	//vertical right
	i = temp_i;
	j= temp_j;
	while(j+1<vertices && i+1<vertices)
	{
		vec[i+1][j+1] = 0;
		i = i+1;
		j = j+1;
	}
}

bool n_queen_util(map<int,vector<int>>& m, vector<vector<int>> vec, int vertices, int i)
{
	if(i/vertices == vertices-1)
	{
		return true;
	}

	make_invalid(vec,vertices,i);

	for(auto j: m[i])
	{
		if(vec[j/vertices][j%vertices] == -1)
		{
			if(n_queen_util(m,vec,vertices,j))
			{
				return true;
			}
		}
	}

	return false;
}

bool n_queen(map<int,vector<int>>& m, vector<vector<int>>&vec, int vertices)
{

	for(int i=0;i<vertices;i++)
	{
		if(n_queen_util(m,vec,vertices, i))
		{
			return true;
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
    int vertices;
    //implementation of undirected graph
    map<int,vector<int>> m; //vector creation using map & vector int
    cout << "enter the input m of mxm square: ";
    cin >> vertices;
    vector<vector<int>> vec( vertices , vector<int> (vertices, -1)); 
    build_graph(m,vertices);
    n_queen(m,vec,vertices);
    cout << "Now traversing the graph using dfs: \n";

}