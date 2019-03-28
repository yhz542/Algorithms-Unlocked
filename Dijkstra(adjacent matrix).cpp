#include <iostream>
#include <vector>
#define Infinity 65535
using namespace std;
void Initialize(vector<vector<int>>&);
void Assignment(vector<vector<int>>&, int);
void Dijkstra(vector<vector<int>> &, int);
int FindMin(vector<int>&, vector<int>&);
int main()
{
	int numNode, numEdge;
	cin >> numNode >> numEdge;
	vector<vector<int>> graph(numNode);
	Initialize(graph);
	Assignment(graph, numEdge);
	Dijkstra(graph, 0);
}
void Initialize(vector<vector<int>> &graph)
{
	for (auto beg = graph.begin(); beg != graph.end(); ++beg)
	{
		(*beg).resize(graph.size(), 0);
	}
}
void Assignment(vector<vector<int>> &graph , int numEdge)
{
	int node1, node2, weight;
	for (int i = 0; i < numEdge; ++i)
	{
		cin >> node1 >> node2 >> weight;
		graph[node1][node2] = weight;
	}
}
void Dijkstra(vector<vector<int>> &graph, int start)
{
	int N = graph.size();
	vector<int> shortest(N,Infinity);
	shortest[start] = 0;
	vector<int> pred(N, -1);
	vector<int> nodeSet(N);
	for (int i = 0; i < N; ++i)
		nodeSet[i] = i;
	int u=0;
	while (!nodeSet.empty())
	{
		u = FindMin(shortest, nodeSet);
		for (int v = 0 ; v<N;++v)
		{
			if (graph[u][v])
			{
				if (shortest[v] > shortest[u] + graph[u][v])
				{
					shortest[v] = shortest[u] + graph[u][v];
					pred[v] = u;
				}
			}
		}
	}
	for (auto beg = shortest.cbegin(); beg != shortest.cend(); ++beg)
		cout << *beg << ' ';
}

/*
5 10
0 1 6
0 3 4
1 2 3
1 3 2
2 4 4
3 1 1
3 2 9
3 4 3
4 2 5
4 0 7

正确输出 0 5 8 4 7
*/
