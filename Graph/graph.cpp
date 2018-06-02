#include<bits/stdc++.h>
 using namespace std;
 
 void addEdge(vector<vector <int> >& graph,int u,int v)
 {
 	graph[u].push_back(v);
 	graph[v].push_back(u);
 	return;
 }
 
 void removeEdge(vector<vector <int> >& graph,int u,int v)
 {
 	graph[u].erase(remove(graph[u].begin(),graph[u].end(),v),graph[u].end());
 	graph[v].erase(remove(graph[v].begin(),graph[v].end(),u),graph[v].end());
 	return;
 }
 
 void display(vector<vector <int> >& graph)
 {
 	for(int i=1;i<graph.size();i++)
 	{
 	cout<<i<<"is connected with"<<"=";
	 for(int j=0;j<graph[i].size();j++)
 	{
 		cout<<graph[i][j]<<" ";
	}
	cout<<endl;
		
	}
 }
 int main()
 {
 	int n=5,flag=1;
 	vector<vector <int> > graph(6);
 	addEdge(graph,2,3);
 	addEdge(graph,2,1);
 	addEdge(graph,4,3);
 	addEdge(graph,1,4);
 	addEdge(graph,1,5);
 	addEdge(graph,4,5);
 	addEdge(graph,1,3);
 	cout<<"before"<<endl;
 	display(graph);
 	removeEdge(graph,1,3);
 	//cout<<graph[1].size()<<endl;
 	cout<<"after"<<endl;
 	display(graph);
 	return 0;
 	
 }
 
