#include <stdio.h>
#include <memory.h>
#define Infinity 65535
#define NumNode 5 //顶点数目
void Initialize(int [][NumNode]);//初始化
void Assignment(int [][NumNode]);//给边赋值
void Bellman_Ford(int [][NumNode],int);
int main(void)
{
        int graph [ NumNode ] [ NumNode ] ;
        Initialize(graph);
        Assignment(graph);
        Bellman_Ford(graph,0);
        return 0 ;
}
void Initialize(int graph[][NumNode])
{
        for( int i = 0 ; i < NumNode ; ++i )
                for( int j = 0 ; j < NumNode ; ++j )
                        graph[i][j] = Infinity;//由于权重取值可以为负值可以为0，所以初始化为一个无穷大的值
}
void Assignment(int graph[][NumNode])
{
        int node1,node2,weight;
        while( scanf("%d%d%d",&node1,&node2,&weight) != EOF )
        {
                graph[node1][node2] = weight;
        }
}
void Bellman_Ford(int graph[][NumNode],int start)
{
        int shortest[NumNode];
        int pred[NumNode];
        for( int i = 0 ; i < NumNode ; ++i )
        {
                shortest[i]=Infinity;
                pred[i]=-1;
        }
        shortest[start]=0;
        for( int i = 0 ; i < NumNode-1 ; i++ )
        {
                for( int u = 0 ; u < NumNode ; u++ )
                {
                        for( int v = 0 ; v < NumNode; ++v)
                        {
                                if(graph[u][v]!=Infinity)
                                {
                                        if(shortest[u]+graph[u][v]<shortest[v])
                                        {
                                                pred[v]=u;
                                                shortest[v]=shortest[u]+graph[u][v];
                                        }
                                }
                        }
                }
        }
        for( int i = 0 ; i < NumNode;++i)//输出答案
                printf("%d ",shortest[i]);
}

/*
0 1 6
0 3 7
1 2 5
1 3 8
1 4 -4
2 1 -2
3 2 -3
3 4 9
4 2 7
4 0 2
测试数据 输出应该为0 2 4 7 -2 代表0点到个点的最短距离。
*/
/*程序
输入：
graph：一个有向图
start:源顶点
输出：与Dijkstra相同，都是源点start到各个顶点的最短距离。
核心算法步骤：
1.对于除了源点start以外的任意顶点v,shortest[v]被赋值为Infinity,shortest[start]赋值为0,对所有顶点v，pred[v]赋值为NULL
2.i从1~n-1依次取值：
        对图graph中的所有边( u , v )依次遍历：
                对每一条边检测shortest[v] > shortest[u]+graph[u][v]
                        如果满足条件就对shortest[v] 和 pred[v]进行赋值
