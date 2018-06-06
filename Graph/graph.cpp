#include<bits/stdc++.h>

using namespace std;

class Graph
{
	int V;
	int E;
	list<int> *adj;
	bool isCyclicUtil(int v,bool visited[],bool *recStack);
	void DFSUtil(int v,bool visited[]);
	public:
		Graph(int V);
		void addEdge(int a,int b,int w);
		bool isCyclic();
		void printGraph();
		void DFS(int v);
		void BFS();
};


void Graph::BFS(int v)
{
	//bool visited[V]={false};
	bool *visited=new bool[V];
	for(int i=0;i<V;i++)
	{
		visited[i]=false;
	}
	
	list<int> queue;

	visited[v]=true;
	queue.push_back(v);
	while(!queue.empty())
	{
		v=queue.front();
		cout<<v<<" ";
		queue.pop_front();
		list<int>::iterator i;
		for(i=adj[v].begin();i!=adj[v].end(),i++)
		{
			if(!visited[*i])
			{
				queue.push_back(*i);
			}
		}
	}
	
}


void Graph::DFSUtil(int v,bool visited[])
{
	visited[v]=true;
	cout<<v<<" ";
	
	list<int>::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();i++)
	{
		if(!visited[*i])
		{
			DFSUtil(*i,visited);
		}
	}
}
void Graph::DFS(int v)
{
	//bool visited[V]={false};
	bool *visited=new bool[V];
	for(int i=0;i<V;i++)
	{
		visited[i]=false;
	}
	DFSUtil(v,visited);
}

Graph::Graph(int V)
{
	this->V=V;
	adj=new list<int>[V];
}

void Graph::addEdge(int a,int b,int w)
{
	adj[a].push_back(b);
}
bool Graph::isCyclicUtil(int v,bool visited[],bool *recStack)
{
	if(visited[v]==false)
	{
		visited[v]=true;
		recStack[v]=true;
		
		list<int>::iterator i;
		for(i=adj[v].begin();i!=adj[v].end();i++)
		{
			if(!visited[*i] && isCyclicUtil(*i,visited,recStack))
				return true;
			else if(recStack[*i])
				return true;
				
		}
	}
	recStack[v]=false;
	return false;
}
bool Graph::isCyclic()
{
	bool *visited= new bool[V];
	bool *recStack= new bool[V];
	
	for(int i=0;i<V;i++)
	{
		visited[i]=false;
		recStack[i]=false;
	}
	
	for(int i=0;i<V;i++)
	{
	if(isCyclicUtil(i,visited,recStack))
	    return true;
	    
	return false;
	}
}
int main()
{
	Graph g(4);
    g.addEdge(0, 1, 5);
    //g.addEdge(1, 0, 5);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 0, 3);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 3, 5);
    
    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    
	cout<<endl;
	
    cout<<"The DFS Traversal is as follows:";
    g.DFS(2);
	
	cout<<endl;
	
	cout<<"The DFS Traversal is as follows:";
    g.BFS(2);
    
	return 0;
    
}
