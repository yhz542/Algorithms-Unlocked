void Find_Negative_Weight_Cycle(int graph[][NumNode],int shortest[],int pred[])
{
        int visited[NumNode]={0};
        for( int u = 0 ; u < NumNode ; ++u )
        {
                for( int v = 0 ; v < NumNode ; ++v )
                {
                        if(graph[u][v]!=Infinity)
                        {
                                if(shortest[u]+graph[u][v]<shortest[v])
                                {
                                        int x = v ;
                                        if(!visited[x])
                                        {
                                                visited[x]=1;
                                                x=pred[x];
                                        }
                                        v = pred[x];
                                        int *cycle=(int *)malloc(sizeof(int)*NumNode);
                                        for( int i = 0 ; i < NumNode ; ++i)
                                        {
                                                cycle[i]=-1;
                                        }
                                        int index = 0;
                                        cycle[index++]=x;
                                        while(v!=x)
                                        {
                                                cycle[index++]=v;
                                                v=pred[v];
                                        }
                                        for( int i = 0 ; i < NumNode ; ++i )//输出负值圈
                                        {
                                                if(cycle[i]!=-1)
                                                        printf("%d ",cycle[i]);
                                        }
                                        return;
                                }
                        }
                }
        }
        printf("无负值圈!");
}
/*
测试数据
0 1 1
0 3 2
1 3 4
1 2 6
2 1 -2
2 4 3
4 3 5
3 2 -3

输出的负值圈应该是 1 2 3.
本程序只输出查找并输出第一个负值圈
*/
/*
输入：一个有向图 graph , 源点到个点的最短路径 shortest ,最短路径到每个点经过的前一个点 pred(运行该算法的前提是已经运行过bellman_ford程序)
输出: 负权重环上的顶点表或者是一个空表.
算法流程:
1.遍历所有边寻找任意一条满足shortest[u]+weight[u][v]<shortest[v]的边.
2.如果不存在满足条件的边，返回一个空表（本程序无返回值。）
3.存在满足条件的边，执行一下操作：
  A.创建一个新数组visited,索引为各个顶点,将所有元素的visited值赋值为False
  B.x 赋值为 v
  C.只要visited[x]是False,执行以下操作：
    i.将visited[x]赋值为 true。
    ii.将 x 赋值为 pred[x]。
  D.v 赋值为 pred[x]。
  E.创建一个初始仅包含顶点 x 的表cycle。
  F.只要 v 不等于 x , 执行以下操作:
    i.将顶点 v 插入到cycle表的开始位置（本程序依次往数组后面进行插入，只影响输出顺序）。
    ii.将 v 赋值为 pred[v] 。
  G.返回cycle表。

如果只查找有无负值圈或者只输出第一个负值圈的话，那么 visited 可以省略，直接查找是否有可以减小 shortest 的边进行下一步操作。 
*/
