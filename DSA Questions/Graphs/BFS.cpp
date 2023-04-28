// Copyrights are reserved by Amir Saudagar
// push() function is used to insert an element at the back of the queue.
// pop() function is used to remove an element from the front of the queue(oldest element in the queue). 
// push() --> 0 1 2        pop() ---> Will give output : 0 1 2



#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
// #include <dequeue>
#include <vector>

using namespace std;

class Graph{
public:
	int n, e;
	bool direction;   // direction = 0 -->undirected graph      direction = 1 ---> directed graph
	unordered_map<int, list<int>> adj;

	Graph(int n, int e, bool direction)
	{
		this->n = n;
		this->e = e;
		this->direction = direction;
	}


	void addEdges(int u, int v)
	{
		adj[u].push_back(v);
		if(direction == 0)
		{
			adj[v].push_back(u);
		}
	}

	void printAdj()
	{
		for(auto i : adj)
		{
			cout<<i.first<<"->";
			int count = 0;

			for(auto j : i.second)
			{
				cout<<j;
				if(++count < i.second.size())
				{
					cout<<",";
				}
			}
			cout<<endl;
		}
	}

	void BFS(int s)
	{
		vector<bool> visited(n,false);
		queue<int> q;

		q.push(s);
		visited[s] = true;

		while(!q.empty())
		{
			s = q.front();
			cout<<s<<" ";

			q.pop();

			for(auto i : adj[s])
			{
				if(!visited[i])
				{
					visited[i] = true;
					q.push(i);
				}
			}
		}

	}
};


int main()
{
	int n, e, u, v;
	bool direction;
	cout<<"Enter number of vertices : ";
	cin>>n;

	cout<<"Enter number of edges : ";
	cin>>e;

	cout<<"Enter 1 -> directed and 0 -> undirected";
	cin>>direction;

	Graph g1(n,e,direction);

	for(int i = 0; i<e; i++)
	{
		cin>>u>>v;
		g1.addEdges(u,v);
	}

	cout<<"-------------- Adjecency Matrix ------------------"<<endl;
	g1.printAdj();


	cout<<"---------------- BFS --------------------"<<endl;
	g1.BFS(1);

	return 0;
}



// Enter number of vertices : 5
// Enter number of edges : 5
// Enter 1 -> directed and 0 -> undirected0
// 1 2
// 2 4
// 4 5
// 5 3
// 3 2
// -------------- Adjecency Matrix ------------------
// 3->5,2
// 5->4,3
// 4->2,5
// 2->1,4,3
// 1->2
// ---------------- BFS --------------------
// 1 2 4 3 5 