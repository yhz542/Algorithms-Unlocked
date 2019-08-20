#define NOTFOUND -1
int Binary_Search( int Data[] , int Length , int Target )//数组 ，数组长度，查找的目标
{
        int p = 0 , r = Length - 1 , q ; //p为子数组的首下标，r为子数组的尾下标 , q为二分的中间点
        while ( p <= r )//只要首下标不大于尾下标，就说明子数组中还有成员
        {
                q = ( p + r ) >> 1 ;
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
int *bsearch(int *t ,int n,int target)//查找目标，返回目标的指针，如果没找到返回空指针。采用不对称边界
{
        int *lo = t , *hi = t + n ;//注意 hi指向的是尾后指针，也是一个根本部存在于数组中的值，只能取地址，不能取值
        while( lo < hi )
        {
                int *mid = lo + ((hi-lo)>>1) ;
                if( x < *mid )
                        hi = mid ;//这里不能赋值为mid-1,因为hi指向的是一个尾后指针，尾后指针实际上并不存在于当前的数组中，
                else if( x > *mid )//mid-1还未检测，所以不能作为hi的值。注意判断条件是lo < hi ，hi的值永远不会被检测到
                        lo = mid + 1 ;
                else
                        return mid ;
        }
        return NULL ;
}
