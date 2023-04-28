#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

class Graph
{
	public :
	unordered_map<int, list< pair<int,int> > > adj;

	int n, e;
	bool direction;

	Graph(int n, int e, bool direction)
	{
		this->n = n;
		this->e = e;
		this->direction = direction;
	}

	void addEdgesWithWeights(int u, int v, int w)
	{
		adj[u].push_back(make_pair(v,w));

		if(direction == 0)
		{
			adj[v].push_back(make_pair(u,w));
		}
	}

	void printAdj()
	{
		for(auto i : adj)
		{
			cout<<i.first<<" ->";
			for(auto j : i.second)
			{
				cout<<j.first<<" "<<" w = "<<j.second;
			}
			cout<<endl;
		}
	}

	void primsAlgo()
	{
		vector<int> key(n,INT_MAX);
		vector<int> parent(n,-1);
		vector<bool> mst(n, false);  //Minimum spanning tree.
		
		int u = 0;

		key[0] = 0;
		parent[0] = -1;
		mst[0] = true;

		for(int i = 0; i<n; i++)
		{
			int min = INT_MAX;
			int u;

			for(int v = 0; v<n; i++)
			{
				if(mst[v] == false && key[v] < min)
				{
					u = v;
					min = key[v];
				}
			}

			mst[u] = true;

			for(auto i : adj[u])
			{
				int v = i.first;
				int w = i.second;
				if(mst[v] == false && w < key[v])
				{
					parent[v] = u;
					key[v] = w;
				}
			}
		}

		for(int i = 1; i<n; i++)
		{
			cout<<parent[i]<<" -> "<<i<<" "<<"w = "<<key[i]<<endl;
		}

	}

};



int main()
{
	int n, e;
	int u,v,w;
	bool direction;
	
	cout<<"Enter number of vertices : ";
	cin>>n;
	cout<<"Enter number of edges : ";
	cin>>e;

	cout<<"Enter 1->Directed Graph and 0->Undirected Graph :";
	cin>>direction;

	Graph g1(n,e,direction);

	cout<<"Enter edges : "<<endl;
	for(int i = 0; i < e; i++)
	{
		cin>>u>>v>>w;
		g1.addEdgesWithWeights(u,v,w);
	}

	cout<<"Adjacent list : "<<endl;
	g1.printAdj();
	cout<<"Prims algo : "<<endl;
	g1.primsAlgo();

	return 0;
}

// #include <iostream>
// #include <vector>
// #include <list>
// #include <unordered_map>
// #include <vector>
// #include <climits>
// // #include <pair>

// using namespace std;

// class Graph
// {
// 	public :
// 	unordered_map<int, list< pair<int,int> > > adj;

// 	int n, e;
// 	bool direction;

// 	Graph(int n, int e, bool direction)
// 	{
// 		this->n = n;
// 		this->e = e;
// 		this->direction = direction;
// 	}

// 	void addEdgesWithWeights(int u, int v, int w)
// 	{
// 		adj[u].push_back(make_pair(v,w));

// 		if(direction == 0)
// 		{
// 			adj[v].push_back(make_pair(u,w));
// 		}
// 	}

// void printAdj() {
//     for (int u = 0; u < adj.size(); u++) {
//         cout << u << " -> ";
//         for (auto [v, w] : adj[u]) {
//             cout << "(" << v << "," << w << ") ";
//         }
//         cout << endl;
//     }
// }

// void primsAlgo()
// {
//     vector<int> key(n,INT_MAX);
//     vector<int> parent(n,-1);
//     vector<bool> mst(n, false);  //Minimum spanning tree.

//     int u = 0;

//     key[0] = 0;
//     parent[0] = -1;
//     mst[0] = true;

//     for(int i = 0; i < n; i++)
//     {
//         int min = INT_MAX;
//         int v;

//         for(int j = 0; j < n; j++)
//         {
//             if(mst[j] == false && key[j] < min)
//             {
//                 v = j;
//                 min = key[j];
//             }
//         }

//         u = v;
//         mst[u] = true;

//         for(auto i : adj[u])
//         {
//             int v = i.first;
//             int w = i.second;
//             if(mst[v] == false && w < key[v])
//             {
//                 parent[v] = u;
//                 key[v] = w;
//             }
//         }
//     }

//     for(int i = 1; i < n; i++)
//     {
//         cout<<parent[i]<<" -> "<<i<<" "<<"w = "<<key[i]<<endl;
//     }
// }


// };



// int main()
// {
// 	int n, e;
// 	int u,v,w;
// 	bool direction;
	
// 	cout<<"Enter number of vertices : ";
// 	cin>>n;
// 	cout<<"Enter number of edges : ";
// 	cin>>e;

// 	cout<<"Enter 1->Directed Graph and 0->Undirected Graph :";
// 	cin>>direction;

// 	Graph g1(n,e,direction);

// 	cout<<"Enter edges : "<<endl;
// 	for(int i = 0; i < e; i++)
// 	{
// 		cin>>u>>v>>w;
// 		g1.addEdgesWithWeights(u,v,w);
// 	}

// 	cout<<"Adjacent list : "<<endl;
// 	g1.printAdj();
// 	cout<<"Prims algo : "<<endl;
// 	g1.primsAlgo();

// 	return 0;
// }