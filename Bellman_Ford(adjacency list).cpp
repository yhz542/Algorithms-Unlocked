#include <iostream>
#include <vector>
#include <forward_list>
#define Infinity 65535
struct edge
{
	int weight;
	int node;
};
using namespace std;
void Bellman_Ford(vector<forward_list<edge>> &,int);
int main()
{
	int numOfNode, numOfEdge;
	cin >> numOfNode >> numOfEdge;
	vector<forward_list<edge>> graph(numOfNode);
	int node1;;
	edge tem;
	for (int i = 0; i < numOfEdge; ++i)
	{
		cin >> node1 >> tem.node >> tem.weight;
		graph[node1].insert_after((graph[node1]).before_begin(),tem);
	}
	Bellman_Ford(graph, 0);
}
void Bellman_Ford(vector<forward_list<edge>> &graph,int start)
{
	size_t n = graph.size();
	vector<int> shortest(n,Infinity);
	shortest[start] = 0;
	vector<int> pred(n, -1);
	for (size_t i = 0; i < n - 1; ++i)
	{
		for (size_t u = 0 ; u < n ; ++u )
		{
			for (auto beg = graph[u].cbegin(); beg != graph[u].cend(); ++beg)
			{
				if (shortest[(*beg).node] > shortest[u] + (*beg).weight)
				{
					shortest[(*beg).node] = shortest[u] + (*beg).weight;
					pred[(*beg).node] = u;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
		cout << shortest[i] << ' ';
}
