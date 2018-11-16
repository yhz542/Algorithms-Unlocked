int *CountKeysEqual( int *Data , int n , int m )//n为长度 m为数组元素的取值范围
{
        int *Equal = ( int * )malloc( sizeof( int )* m ) ;//创建数组
        memset( Equal , 0 , sizeof( int ) * m ) ;//初始化为0
        for ( int i = 0 , key ; i < n ; ++i )//记录元素的个数 equal数组的下标代表元素的值 存储的值代表元素的个数
        {
                key = Data[ i ] ;
                ++Equal[ key ] ;
        }
        return Equal ;
}
int *Rearrange1( int Equal[] , int n, int m )
{
        int *B = ( int *)malloc( sizeof( int ) * n ) ;//创建一个新数组
        for ( int i = 0 , cnt = 0 ; cnt != n ; ++i ) //遍历equal数组中的元素，当读入数目达到 n 时，即代表所有元素都已排序完毕，跳出循环
        {                                            //因为m的取值范围可能还没到m-1就已读入完毕，所以以n作为判断条件。
                for ( int  j = 0 ; j < Equal[ i ] ; ++j )//equal元素代表每个i的个数，将其按顺序全部读入新数组中。
                {
                        B[ cnt ] = i ;
                        ++cnt ;
                }
        }
        free( Equal ) ;
        return B ;
}
