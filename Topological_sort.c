int *TopLogical_Sort(int graph[][n])//邻接矩阵版本
{
        int indegree[ n ] ={ 0 } ;//声明入度并进行初始化
        for( int i = 0 ; i < n ; ++i )
        {
                for( int j = 0 ; j < n ; ++j )
                {
                        if( graph[ i ][ j ] )
                                ++indegree[ j ] ;//计算每个结点的入度
                }
        }
        int next[ n ] ;//创建next列表，用于存放所有入度为0的结点
        int posNextInsert = 0 ;//插入next列表的下标位置
        for( int node = 0 ; node < n ; ++node )
                if( !indegree[ node ] )
                       next[ posNextInsert++ ] = node ;//将所有入度为0的点放入next列表中，并记录插入位置。
        int *outputSeq = (int *)malloc( sizeof( int ) * n ) ;//输出序列
        int posSeqInsert = 0 ;//插入输出序列的下标位置
        while( posNextInsert )//插入位置不为0代表next列表不空
        {
                int selectedNode = next[ --posNextInsert ] ;//从next列表中抽出一个入度为0的结点
                outputSeq[ posSeqInsert++ ] = selectedNode ;//将选出的结点加入输出中.
                for( int i = 0 ; i < n ; ++i )
                        if( graph[ selectedNode ][ i ] )
                        {
                                --indegree[ i ] ;
                                if( !indegree[ i ] )
                                        next[ posNextInsert++ ] = i ;
                        }
        }
        return outputSeq ;
}
/*
0 2
2 3
2 4
1 3
3 5
4 5
5 6
6 7
7 12
5 10
8 9
9 10
10 11
11 12
12 13
测试数据 每行输入代表两点之间有一条有向边，前者指向后者
*/
/*
拓扑排序思路:
输入：有向无环图
输出：一个结点的顺序序列。时间序从左往右递增。
具体流程:
1.创建一个新数组indegree[n]并初始化所有元素的值为0，indegree代表所有结点的入度————即有多少结点连接着该结点。
2.利用有向无环图，遍历所有结点，对每个结点 U 做如下操作：
  对每个与 U 连接的结点 V , 增加该结点的入度 indegree[ V ]。
3.创建一个next列表，存放所有入度为 0 的结点 U ,即 indegree[U] == 0 。
4.创建一个序列 Seq 作为程序的输出序列，代表结点的输出顺序。
5.只要 next 列表不为空，执行一下操作:
  A.从next列表中删除一个结点 U .
  B.将 U 结点添加到 Seq序列的末尾。
  C.对于每个和 U 连接的结点 V :
    i.将结点 V 的入度indegree[V]的值减去 1 .
    ii.如果 indegree[ V ] == 0 ,将结点 V 加入 next列表中
6.将 Seq 序列作为结果返回。
