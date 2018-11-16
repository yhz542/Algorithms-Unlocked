void Quick_Sort( int Data[] , int p , int r )//带排序数组，数组首元素下标，数组尾元素下标
{
        /*if ( r - p + 1 <= 10 ) //子数组规模小于10时 采用插入排序加快运算速度。
                Insertion_Sort( Data + p , r-p+1 ) ;*/
        if ( p >= r )
                return ; //基础情况,子数组只有一个元素
        else
        {
                int q = Partition( Data , p , r ) ;//将一个数排好位置，并以它为界，分为左右两块。
                Quick_Sort( Data , p , q - 1 ) ;//处理左边
                Quick_Sort( Data , q + 1 , r ) ;//处理右边
        }
}
int Partition( int Data[] , int p , int r )//同上一个函数接口
{  //算法思想，将数组的最后一个数作为分界点，最后将这个数放在正确的位置，同时返回这个下标。
        int q = p ;//q代表比分界点元素大的子序列中最左边的元素下标。
        int tem = 0 ;//用于交换值的临时变量
        for ( int u = p ; u < r ; ++u )//遍历数组，u代表还未处理的元素下标
        {
                if ( Data[ u ] <= Data[ r ] )//如果待处理的元素比作为分界点的元素小
                {  //交换 Data [ q ] 和 Data [ u ] 的值 ，同时让 比分界点元素大的子序列起始下标右移一个单位。
                        tem = Data[ q ] ;//当q=u时 用 加减法交换值会使值归零，不能用加减法直接来改变值，因为会出现自己和自己交换值的情况 
                        Data[ q ] = Data[ u ] ;
                        Data[ u ] = tem ;
                        ++q ;
                }//上面这一段就是将待处理元素加入比分界点小的组中，如果比分界点大，无需处理
        }
        tem = Data[ q ] ;//最后将分界点(数组最后一个元素)放入它应该所在的下标
        Data[ q ] = Data[ r ] ;
        Data[ r ] = tem ;
        return q ;
}
