#include <iostream>
#include <limits>
using namespace std;

class Graph{
	public:
		unordered_map<int,list<int>> mp;
		int v, e;
		bool direction;
		static int i = 0, j = 0;

		Graph(int v, int e, bool direction)
		{
			this->v = v;
			this->e = e;
			this->direction = direction;
		}


		 int** a = new int*[v];
		 int** prev = new int*[v];
 
	    for (int i = 0; i < v; i++) {
	 
	        // Declare a memory block
	        // of size n
	        a[i] = new int[v];
	        temp[i] = new int[v];
	    }

		void addEdges()
		{
			cout<<"Enter edges and their weights"
			for(int i = 0; i < v; i = i+2)
			{
				for(int j = 0; j< v; j = j+2)
				{
					cin>>a[i][j]>>a[i+1][j+1];
				}
			}
		}



};

int main()
{






}
