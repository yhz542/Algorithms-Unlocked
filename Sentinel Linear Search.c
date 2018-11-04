#define NOTFOUND -1
int SentinelLinearSearch( int Data[] , int Length , int Target )
{
        int Tem = Data[ Length - 1 ] ;//将数组最后一位放入Tem中暂时存储起来。
        Data[ Length - 1] = Target ; //将目标对象放入数组的最后一个位置。
        int i ;
        for ( i = 0 ; Data[ i ] != Target ; ++i );//因为数组最后一个位置为目标对象，所以最终一定会退出循环
        if ( i < Length - 1 || Tem == Target )
                return i ;
        else
                return NOTFOUND ;
} 
