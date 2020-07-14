#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
int vertices;
stack<int> st;
//implementation of n-queen problem with graphs backtracking with graphs
//this problem is created using directed graph where all vertices must be
//connected to next valid vertex, so we have to build the graph that way
//we have to do above implementation upto vertex-1 rows as last row
//does not have any valid next vertex
//so this is a top down graph connection approach
//another thing to be noted that we have to make the downwards and aligned path
//as invalid which is donw using make_invalid function


void add_edge(map<int,vector<int>> &m, int a, int b)
{
	for(auto i: m[a])
	{
		if(i == b)
		{
			return ;
		}
	}
	m[a].emplace_back(b);
	//cout << a <<  " -> " << b << "\n";
}

void build_graph(map<int,vector<int>>& m) //giving valid vertices to vertex
{
	int i=0;
	int rem;
	int j;
	int temp;
	while(i<(vertices*(vertices-1))) //making relations for edges upto vertex-1
	{
		rem = i%vertices;
		for(j=0;j<vertices;j++)
		{
			temp = ((i+j)%vertices) + vertices*(1 + (i/vertices));
			if(temp%vertices != rem && temp%vertices != rem+1 && temp%vertices != rem-1)
			{
				add_edge(m,i,temp); //add edge if it is not strictly downward or aligned
			}
		}
		i++;
	}
}

void make_invalid(vector<vector<int>>& vec,int ver)
{
	int temp_i = ver/vertices; //get x coordinates
	int temp_j = ver%vertices; //get y coordinates

	//making downward invalid
	int i = temp_i;
	int j = temp_j;
	while(i<vertices)
	{
		vec[i][j] = 0;
		i = i+1;
	}

	//making aligned vertical left invalid
	i = temp_i;
	while(j-1>=0 && i+1<vertices)
	{
		vec[i+1][j-1] = 0;
		i = i+1;
		j = j-1;
	}

	//making aligned vertical right invalid
	i = temp_i;
	j= temp_j;
	while(j+1<vertices && i+1<vertices)
	{
		vec[i+1][j+1] = 0;
		i = i+1;
		j = j+1;
	}
}

bool n_queen_util(map<int,vector<int>>& m, vector<vector<int>> vec, int i)
{//vector is not passed by reference because if backtracking happens the value
//must get destroyed
	if(i/vertices == vertices-1)
	{
		return true;
	}

	make_invalid(vec,i);

	for(auto j: m[i])
	{
		st.push(j);
		if(vec[j/vertices][j%vertices] == -1)
		{
			if(n_queen_util(m,vec,j))
			{
				return true;
			}
		}
		st.pop();
	} //if returned false than loop travesrse other connected nodes;

	return false; //backtracking to previous state by returning false
}

bool n_queen(map<int,vector<int>>& m, vector<vector<int>>&vec)
{

	for(int i=0;i<vertices;i++)
	{
		st.push(i);
		if(n_queen_util(m,vec, i))
		{
			return true;
		}
		st.pop();
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
    cout << "enter the input m of mxm square: ";
    cin >> vertices;
    vector<vector<int>> vec( vertices , vector<int> (vertices, -1));
    build_graph(m); //adding edges
    n_queen(m,vec); //N_queen function
    cout << "The valid places are: \n";
		int n;
		while(!st.empty())
		{
			n = st.top();
			cout << "(" << n/vertices << "," << n%vertices << ")" << "\n";
			st.pop();
		}

}
