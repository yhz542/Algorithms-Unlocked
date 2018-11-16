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
int *CountKeysLess( int Equal[] , int m )
{
        int *Less = ( int *)malloc( sizeof( int ) * m ) ;//less代表待排序数组中小于下标值的元素个数
        Less[ 0 ] = 0 ;//小于0的元素个数为0
        for ( int j = 1 ; j < m ; ++j )
                Less[ j ] = Less[ j - 1 ] + Equal[ j - 1 ] ;
        return Less ;
}
int *Rearrange( int Data[] , int Less[] , int n , int m )
{
        int *B = ( int * )malloc( sizeof( int ) * n ) ;
        for ( int i = 0 , key , index ; i < n ; ++i )
        {
                key = Data[ i ] ;//待排元素的位置为less[i]，less[i]存储的为小于i的元素个数，所以less[i]为i开始的地址
                index = Less[ key ] ;
                B[ index ] = Data[ i ] ;
                ++Less[ key ];//less[i]输出一次后，下一个i的位置要后移一个单位，所以需要自加一
        }
        return B ;
}
int *Counting_Sort( int Data[] , int n , int m ) //这个排序当数组长度 n 远比 取值范围 m 小时 比较好。
{
        int *Equal = CountKeysEqual( Data , n , m ) ;
        int *Less = CountKeysLess( Equal , m ) ;
        free( Equal ) ;
        int *B = Rearrange( Data , Less , n , m ) ;
        free( Less ) ;
        return B ;
}
