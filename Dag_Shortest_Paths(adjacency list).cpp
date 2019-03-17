#include<vector>//邻接表版本，思路和邻接矩阵一样
#include<map>
#define Max 65535
shared_ptr<vector<int>> TopLogical_Sort(vector<map<int,int>> &graph)
{
	int N = graph.size();
	vector<int> indegree(N, 0);
	for (int i = 0; i < N; ++i)
		for (auto beg = graph[i].cbegin(), end = graph[i].cend(); beg != end; ++beg)
			++indegree[beg->first];
	vector<int> next;//创建next列表，用于存放所有入度为0的结点
	next.reserve(N);
	for (int node = 0; node < N; ++node)
		if ( !indegree[node])
			next.push_back(node);//将所有入度为0的点放入next列表中，并记录插入位置。
	shared_ptr<vector<int>> seq = make_shared<vector<int>>();//输出序列
	(*seq).reserve(N);
	while (!next.empty())//next列表不空
	{
		int selectedNode = next.back();//从next列表中抽出一个入度为0的结点
		next.pop_back();//删除该节点
		(*seq).push_back(selectedNode);//将选出的结点加入输出中.
		for (auto beg = graph[selectedNode].cbegin(); beg != graph[selectedNode].cend(); ++beg)
		{
			--indegree[beg->first];
			if (!indegree[beg->first])
				next.push_back(beg->first);
		}
	}
	return seq;
}
void Dag_Shortest_Paths(vector<map<int,int>> &graph, int node)
{
	int N = graph.size();
	shared_ptr<vector<int>> seq = TopLogical_Sort(graph);
	vector<int> shortest(N, Max);
	shortest[node] = 0;
	vector<int> pred(N, -1);
	for (auto beg = seq->cbegin(); beg != seq->cend(); ++beg)
	{
		int selectedNode = *beg;
		for (auto beg1 = graph[selectedNode].cbegin(); beg1 != graph[selectedNode].cend(); ++beg1)
		{
			int nodeLinked = beg1->first;
			int distance = beg1->second;
			if (shortest[selectedNode] + distance < shortest[nodeLinked])
			{
				shortest[nodeLinked] = shortest[selectedNode] + distance;
				pred[nodeLinked] = selectedNode;
			}
		}
	}
	for (int i = 0; i < N; ++i)
		cout << shortest[i] << ' ';
	cout << endl;
	for (int i = 0; i < N; ++i)
		cout << pred[i] << ' ';
	cout << endl;
}
