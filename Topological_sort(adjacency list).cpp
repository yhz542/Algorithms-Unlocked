shared_ptr<vector<int>> TopLogical_Sort(vector<vector<int>> &graph)//C++ 邻接表版本
{
	int N = graph.size();
	vector<int> indegree(N, 0);
	for (int i = 0; i < N; ++i)
		for (auto beg = graph[i].cbegin(), end = graph[i].cend(); beg != end; ++beg)
			++indegree[*beg];
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
			--indegree[*beg];
			if (!indegree[*beg])
				next.push_back(*beg);
		}
	}
	return seq;
}
