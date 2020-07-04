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

void dfs_util(map<int,vector<int>> &m, set<int> &s,int i)
{
	for(auto j: m[i])
	{
		if(s.count(j)<1)
		{
			cout << j << " ";
			s.insert(j);
			dfs_util(m,s,j);
		}
	}
}


void dfs(map<int,vector<int>> &m)
{
	set<int> s;
	for(auto i: m)
	{
		if(s.count(i.first)<1)
		{
			cout << i.first << " ";
			s.insert(i.first);
			dfs_util(m,s,i.first);
		}
	}
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
    int in;
    //implementation of undirected graph
    map<int,vector<int>> m; //vector creation using map & vector int
    cout << "implementation of undirected graph \n";
    do{
    	cout << "to add an edge press 1 or exit press 0: ";
    	cin >> in;
    	if(in == 1)
    	{
    		int a,b;
    		cout << "source: ";
    		cin >> a;
    		cout << "destination: ";
    		cin >> b;
    		if(add_edge(m,a,b))
    		{
    			cout << "edge added \n";
    		}
    		else
    		{
    			cout << "edge already exits \n";
    		}
    	}
    }while(in != 0);

    cout << "Now traversing the graph using dfs: \n";
    dfs(m);


}