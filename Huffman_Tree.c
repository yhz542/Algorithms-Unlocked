#include <stdlib.h>//输入：待压缩的字符总数 ， 待压缩的字符和其出现频率。
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MinData -65535
typedef struct HeapStruct *PriorityQueue ;
typedef struct Node ElementType ;
typedef struct Node *pos;
struct Node
{
        float freq;
        char c;
        pos Left;
        pos Right;
};
struct HeapStruct
{
        ElementType *Elements ;//存储堆元素的数组
        int Size ;//堆的当前元素个数
        int Capacity ;//堆的最大容量
};
PriorityQueue CreatePQueue( int MaxSize )
{
        PriorityQueue H = ( PriorityQueue )malloc( sizeof( struct HeapStruct ) ) ;
        H->Elements = ( ElementType *)malloc ( sizeof( ElementType )*( MaxSize + 1 ) ) ;//空出下标为0的空间用于存放哨兵
        H->Size = 0 ;
        H->Capacity = MaxSize ;
        H->Elements[ 0 ].freq = MinData ;
        return H ;
}
bool IsFull( PriorityQueue H )
{
        return ( H->Size == H->Capacity ) ;
}
ElementType ExtractMin( PriorityQueue H );
void InsertPQueue( PriorityQueue H , ElementType item );
bool IsEmpty( PriorityQueue H )
{
        return H->Size == 0 ;
}
ElementType BuildHuffmanTree(char * , float * , int );
void Traversal(pos,char**,char[],int);
int cnt = 0;
char *word;//用于存储压缩的字符
int main(void)
{
        int n ;
        scanf( "%d" , &n ) ;
        word = (char *)malloc(sizeof(char)*n);
        char **code;//压缩字符的编码
        code = (char **)malloc(sizeof(char *)*n);
        for( int i = 0 ; i < n ; ++i )
                code[i]=(char *)malloc(sizeof(char)*n);
        char str[n];
        float freq[n];
        for( int i = 0 ; i < n ; ++i )
        {
                getchar();
                scanf("%c %f",&str[i],&freq[i]);
        }
        ElementType tree = BuildHuffmanTree(str,freq,n);
        Traversal(&tree,code,str,0);
        for( int i = 0 ; i < n ; ++i )
                printf("%c %s\n",word[i],code[i]);
        return 0 ;
}
void Traversal(pos node,char **code,char str[],int index )
{
        if(node->Left)
        {
                str[index]='0';
                Traversal(node->Left,code,str,index+1);
        }
        if(node->Right)
        {
                str[index]='1';
                Traversal(node->Right,code,str,index+1);
        }
        if(!(node->Left)&&!(node->Right))
        {
                word[cnt]=node->c;
                str[index]='\0';
                strcpy(code[cnt],str);
                ++cnt;
        }
}
ElementType BuildHuffmanTree(char str[] , float freq[] , int n)
{
        PriorityQueue Q = CreatePQueue(n) ;
        ElementType New ;
        for( int i = 0 ; i < n ; ++i )
        {
                New.c=str[i];
                New.freq=freq[i];
                New.Left=NULL;
                New.Right=NULL;
                InsertPQueue(Q,New);
        }
        pos tem1,tem2;
        for( int i = 0 ; i < n-1 ; ++i )
        {
                tem1 = (pos)malloc(sizeof(struct Node));
                *tem1 = ExtractMin(Q);
                tem2 = (pos)malloc(sizeof(struct Node));
                *tem2 = ExtractMin(Q);
                New.freq=tem1->freq+tem2->freq;
                New.c = -1;
                New.Left = tem1;
                New.Right = tem2;
                InsertPQueue(Q,New);
        }
        return ExtractMin(Q);
}
void InsertPQueue( PriorityQueue H , ElementType item )
{
        int i ;
        if ( IsFull( H ) )
        {
                printf("PriorityQueue had been full\n") ;
                return;
        }
        i = ++H->Size ;
        for ( ; H->Elements[ i / 2 ].freq  >  item.freq ; i /= 2 )
                H->Elements[ i ] = H->Elements[ i / 2 ] ;
        H->Elements[ i ] = item ;
}
ElementType ExtractMin( PriorityQueue H )
{
        int Parent , Child ;
        ElementType MinItem , temp ;
        if ( IsEmpty( H ) )
        {
                printf("PriorityQueue had been empty\n") ;
                temp.freq=-1;
                return temp;
        }
        temp = H->Elements[ H->Size-- ] ;
        MinItem = H->Elements[ 1 ] ;
        for ( Parent = 1 ; Parent * 2 <= H->Size ; Parent = Child )
        {
                Child = Parent * 2 ;
                if ( ( Child != H->Size ) &&
                ( H->Elements[ Child ].freq  >  H->Elements[ Child + 1 ].freq ) )
                        ++Child ;
                if (  temp.freq  <=  H->Elements[ Child ].freq  )
                        break ;
                H->Elements[ Parent ] = H->Elements[ Child ] ;
        }
        H->Elements[ Parent ] = temp ;
        return MinItem ;
}
/*
哈夫曼编码思路：
利用最小堆（优先队列）处理：
将所有字母按照出现的频率大小放入最小堆中。
每次从最小堆中取出两个最小频率的结点，并生成一个父节点。两个最小频率的结点分别为父节点的左右子结点。同时父节点的频率等于左右子结点的频率之和。
将父节点放入最小堆之中。
重复以上步骤，直到最小堆中只剩一个结点为止。
返回该父节点。该父节点也是整颗哈夫曼树的根结点。
*/
