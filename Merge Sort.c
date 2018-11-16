#define Infinite 65535
void Merge_Sort( int Data[] , int p , int r )//待排序的数组，首元素下标，尾元素下标
{
        /*if ( r - p + 1 <= 10 )//插入排序处理小规模情况可以加快运行速度，这里的规模为子数组长度等于10
                Insertion_Sort( Data + p , r - p + 1 ) ;*/
        if ( p >= r )//基础情形,子数组中只有一个元素，直接返回
                return ;
        else
        {  //将数组分为两部分进行处理。
                int q = ( p + r ) / 2 ; //划分点
                Merge_Sort( Data , p , q ) ;//前半部分
                Merge_Sort( Data , q + 1 , r ) ;//后半部分
                Merge( Data , p , q , r ) ; //将前后两部分合并
        }
}
void Merge( int Data[] , int p , int q , int r ) //合并函数 三个整形参数分别是 前半部分的首元素下标 划分点下标 以及后半部分的尾下标
{
        int n1 = q - p + 1 , n2 = r - q ; //计算前后两部分的数组长度
        int B[ n1 + 1 ] , C[ n2 + 1 ] ;   //创建两个新的子数组用于拷贝原子数组的元素，注意长度分别比原子数组多1.用于存放无穷大的一个数
        for ( int i = 0 ; i < n1 ; ++i )  //拷贝前半部分
                B[ i ] = Data[ p + i ] ;
        for ( int i = 0 ; i < n2 ; ++i )  //拷贝后半部分
                C[ i ] = Data[ q + 1 + i ] ;
        B[ n1 ] = C[ n2 ] = Infinite ;  //将两个子数组的最后一个位置放置哨兵。
        int i = 0 , j = 0 ; 
        for ( int k = p ; k <= r ; ++k ) //比较两个子数组当前下标指向的数据，哪一个小就放入原数组中，同时下标后移一个单位。
        {
                if ( B[ i ] <= C[ j ] )
                {
                        Data[ k ] = B[ i ] ;
                        ++i ;
                }
                else
                {
                        Data[ k ] = C[ j ] ;
                        ++j ;
                }
        }
}
