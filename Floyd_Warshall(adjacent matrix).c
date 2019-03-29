#include <stdio.h>
#include <stdlib.h>
#define Infinity 65535
#define NumNode 4
void Initialize(int [][NumNode]);
void Assignment(int [][NumNode]);
void Floyd_Warshall(int [][NumNode]);
int main(void)
{
        int graph [ NumNode ] [ NumNode ] ;
        Initialize(graph);
        Assignment(graph);
        Floyd_Warshall(graph);
        return 0 ;
}
void Initialize(int graph[][NumNode])
{
        for( int i = 0 ; i < NumNode ; ++i )
                for( int j = 0 ; j < NumNode ; ++j )
                        graph[i][j] = Infinity;
        for( int i = 0 ; i < NumNode ; ++i )
                graph[i][i]=0;
}
void Assignment(int graph[][NumNode])
{
        int node1,node2,weight;
        while( scanf("%d%d%d",&node1,&node2,&weight) != EOF )
        {
                graph[node1][node2] = weight;
        }
}
void Floyd_Warshall(int graph[][NumNode])
{
        int shortest[NumNode][NumNode];
        int pred[NumNode][NumNode];
        for( int u = 0 ; u < NumNode ; ++u )
        {
                for( int v = 0 ; v < NumNode ; ++v)
                {
                        shortest[u][v]=graph[u][v];
                        if(graph[u][v]!=Infinity)
                        {
                                pred[u][v] = u;
                        }
                        else
                                pred[u][v] = -1;
                }
        }
        for( int i = 0 ; i < NumNode ; ++i )
        {
                for( int u = 0 ; u < NumNode ; ++u )
                {
                        for( int v = 0 ; v < NumNode ; ++v )
                        {
                                if( shortest[u][v]>shortest[u][i]+graph[i][v])
                                {
                                        shortest[u][v]=shortest[u][i]+graph[i][v];
                                        pred[u][v]=pred[i][v];
                                }
                        }
                }
        }
        for( int i = 0 ; i< NumNode ; ++i )//输出shortest最短路径
        {
                for( int j = 0 ; j < NumNode ; ++j )
                        printf("%d ",shortest[i][j]);
                putchar('\n');
        }
}
/*
测试数据
0 1 3
0 2 8
1 3 1
2 1 4
3 0 2
3 2 -5

输出:

0  3 -1  4
3  0 -4  1
7  4  0  5
2 -1 -5  0
*/

/*
程序输入:graph:一个n行、m列利用加权邻接矩阵表示的图。如果两点之间不存在边，则权重设置为无穷大。
输出：对于每个由顶点 u 和顶点 v 组成的顶点对，shortest[u][v]表示从 u 到 v 的最短路径权重，而pred[u] [v]表示从顶点u到顶点v最短路径上v之前的一个顶点
算法流程：
1.创建两个n*n的数组shortest,pred.
2.令u,v分别从0~n-1取值：
  A.将shortest[u][v]赋值为graph[u][v]
  B.如果(u,v)是一条边，那么将pred[u][v]赋值为u，否则赋值为Null
3.令i 从 0~n-1取值：
  A.令u 从0~n-1取值：
    i.令 v 从0~n-1取值：
      a.如果shortest[u,v]>shortest[u,i]+graph[i,v],那么将shortest[u,v]赋值为shortest[u,i]+graph[i,v],将pred[u,v]赋值为pred[i,v]
4.返回shortest和pred.


本算法用到的思想是动态规划，将最短路径分为 u 到 v 经过 顶点值最大为 0 的最短路径。 u 到 v 经过 顶点值最大为1 的最短路径.....
因为经过顶点值最大为0的最短路径是由初始最短路径 shortest[u][0] + graph[0][v]决定的。
而经过顶点值最大为 1 的最短路径结果是由经过顶点最大值为 0 的最短路径和 经过顶点值为 1 的最大路径共同组成。而计算了顶点值最大为 0 的最短路径后，
我们只需要计算经过顶点值为 1 的最短路径即可。
同理经过顶点值最大为 2 的最短路径 是由上一步的结果和 经过顶点值为 2 的最短路径共同组成。求出上一步 ，这一部只需要比较上一步和经过顶点值为2的最短路径
的值的大小即可。
详情请看算法基础 p108
*/
