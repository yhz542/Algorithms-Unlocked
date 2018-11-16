void Insertion_Sort( int Data[] , int Length )//输入 需要排序的数组首地址，以及数组的长度
{
        for ( int i = 1 , key , j ; i < Length ; ++i )
        {
                key = Data[ i ] ;
                for( j = i - 1 ; j >= 0 && Data[ j ] > key ; --j )//倒序比较，如果前面的值比要排序的值小，就把前面的值位置往后移一个单位。
                {
                        Data[ j + 1 ] = Data[ j ] ;
                }
                Data[ j + 1 ] = key ;//由于--j的存在，所以找到目标后，需要用j+1的下标进行交换
        }
}
