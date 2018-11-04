#define NOTFOUND -1
int Binary_Search( int Data[] , int Length , int Target )//数组 ，数组长度，查找的目标
{
        int p = 0 , r = Length - 1 , q ; //p为子数组的首下标，r为子数组的尾下标 , q为二分的中间点
        while ( p <= r )//只要首下标不大于尾下标，就说明子数组中还有成员
        {
                q = ( p + r ) / 2 ;
                if ( Data[ q ] == Target )//如果找到，就返回下标
                        return q ;
                else
                {
                        if ( Data[ q ] > Target )//中间点的值大于目标对象
                                r = q - 1 ;
                        else//中间点的值小于目标对象
                                p = q + 1 ;
                }
        }
        return NOTFOUND ;//未找到目标
}
