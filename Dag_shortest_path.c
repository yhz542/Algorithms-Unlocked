void Dag_Shortest_Paths( int graph[][n] , int node)
{
        int *seq = TopLogical_Sort(graph);//用拓扑排序输出结点遍历顺序
        int shortest[ n ] ;//node结点到各个结点的最短距离
        int pred[n];//到每个结点最近距离的前一个结点
        for( int i = 0 ; i < n ; ++i )//初始化
        {
                shortest[i] = Max ;
                pred[i] = -1 ;
        }
        shortest[node] = 0 ;//结点Node到自己的距离设置为0
        for( int i = 0,u,v ; i < n ; ++i )
        {
                u = seq[i];//从序列中依次取出点
                for( int v = 0 ; v < n ; ++v )
                {
                        if( graph[u][v] )//遍历和u结点相连接的其他点
                        {
                                if( shortest[ u ] + graph[ u ][ v ] < shortest[ v ])//满足条件 更新最短距离和最短距离的前一个结点
                                {
                                        shortest[v] = shortest[ u ] + graph[ u ][ v ];
                                        pred[v] = u ;
                                }
                        }
                }
        }
        for( int i = 0 ; i < n ; ++i )
                printf("%d ",shortest[i]);
        putchar('\n');
        for( int i = 0 ; i < n ; ++i )
                printf("%d ",pred[i]);
}
/*
输入:加权有向无环图以及一个结点s
输出:shortest[v] 表示从结点s到v的最短路径距离（权重和）.pred[v]表示最短路径上在结点v前面的一个结点.对于s而言 shortest[u]=0,pred[u]=NULL.如果s到v没有
路径，那么shortest[v]为正无穷.pred[v]=NULL。
具体流程:
1.调用Topological_sort(graph)，返回的顺序序列赋值给seq.
2.对s以外的所有结点v，shortest[v]全部赋值为正无穷.shortest[s]=0.对所有结点(包括s),pred赋值为NULL.
3.按照顺序序列seq，依次取出结点u:
  对每个与结点u向连接的结点v:
  如果shortest[u]+graph[u][v]<shortest[v],那么shortest[v]=shortest[u]+graph[u][v],pred[v]=u.
  */
