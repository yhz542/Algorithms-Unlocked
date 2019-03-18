#include<stdio.h>
#include<stdlib.h>
#define Max 65535
typedef struct node *pos;
typedef struct node
{
        int nodeIndex;
        int weight;
        pos next;
}Node;
typedef struct
{
        Node *AdjList;
        int nodeNumber ;
        int edgeNumber ;
}Graph;
void Initialize(Graph *);
void Display(Graph *);
void Dijkstra( Graph * , int );
int Extract_Min( int * , int * , int *);
int main(void)
{
        Graph G;
        scanf("%d %d",&G.nodeNumber,&G.edgeNumber);//输入点数和边数 这里使用的是有向边
        Initialize(&G);
        Dijkstra(&G,0);
        return 0 ;
}
void Initialize(Graph *G)
{
        G->AdjList = (Node *)malloc(sizeof(Node)*G->nodeNumber);
        for( int i = 0 ; i < G->nodeNumber ; ++i)
                G->AdjList[i].next=NULL;
        int node1,node2,weight;
        Node *New;
        for( int i = 0 ; i < G->edgeNumber ; ++i )
        {
                scanf("%d%d%d",&node1,&node2,&weight);//输入两个点和他们之间的权重值
                New = (Node *)malloc(sizeof(Node));
                New->next=G->AdjList[node1].next;
                New->nodeIndex=node2;
                New->weight=weight;
                G->AdjList[node1].next=New;
        }
}
void Dijkstra( Graph *G , int vertex)
{
        int shortest[G->nodeNumber],pred[G->nodeNumber] ;
        for( int i = 0 ; i < G->nodeNumber ; ++i )
        {
                shortest[i] = Max;
                pred[i] = -1 ;
        }
        shortest[vertex]=0;
        int nodeSet[G->nodeNumber];
        for( int i = 0 ; i < G->nodeNumber ; ++i )
                nodeSet[i]=i;
        int numOfSet = G->nodeNumber;
        int curNode = 0;
        Node *nodeLinked = NULL;
        while(numOfSet>0)
        {
                curNode = Extract_Min(nodeSet,shortest,&numOfSet);
                nodeLinked = G->AdjList[curNode].next;
                while(nodeLinked)
                {
                        if( shortest[nodeLinked->nodeIndex]>shortest[curNode]+nodeLinked->weight)
                        {
                                shortest[nodeLinked->nodeIndex]=shortest[curNode]+nodeLinked->weight;
                                pred[nodeLinked->nodeIndex]=curNode;
                        }
                        nodeLinked = nodeLinked->next ;
                }
        }
        for( int i = 0 ; i < G->nodeNumber ; ++i )
                printf("%d ",shortest[i]);

}
int Extract_Min( int *nodeSet , int *shortest , int *numOfSet )
{
        int minValue = Max ;
        int minNode=-1,minIndex=0;
        for( int i = 0 , vertex ; i < *numOfSet ; ++i )
        {
                vertex = nodeSet[i];
                if(shortest[vertex]<minValue)
                {
                        minValue=shortest[vertex];
                        minNode = vertex;
                        minIndex = i ;
                }
        }
        //删除minIndex
        nodeSet[minIndex] = nodeSet[--(*numOfSet)];
        return minNode;
}
void Display(Graph* G)
{
        for( int i = 0 ; i < G->nodeNumber ; i++)
        {
                pos curNode = G->AdjList[i].next;
                while(curNode)
                {
                        printf("%d ",curNode->nodeIndex);
                        curNode=curNode->next;
                }
                putchar('\n');
        }
}
