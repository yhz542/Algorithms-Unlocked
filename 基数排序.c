#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Size 10 //排序的字符串总个数
#define Digit 3 //需要排序的次数 ，每个字符串的字符个数
int *Position ;
void Output( char Data[][4] ,int length )
{
        for ( int i = 0 ; i < length ; ++i )
        {
                printf("%s ",Data[Position[i] ] );
        }
        putchar('\n') ;
}
void *CountKeysEqual( char Data[][4] , int *Equal ,  int n , int digit)//n为长度 m为数组元素的取值范围
{
        char key ;
        int index ;
        for ( int i = 0 ; i < n ; ++i )//记录元素的个数 equal数组的下标代表元素的值 存储的值代表元素的个数
        {
                index = Position[ i ] ;
                key = Data[ index ][digit] ;
                key -= 'a' ;
                ++Equal[ key ] ;
        }
}
void *CountKeysLess( int Equal[] , int m )
{//less代表待排序数组中小于下标值的元素个数
        int cur = Equal[ 0 ];
        Equal[ 0 ] = 0 ;
        int next ;
        for ( int j = 1 ; j < m ; ++j )
        {
                next = Equal[ j ] ;
                Equal[ j ] = Equal[ j - 1 ] + cur ;
                cur = next ;
        }
}
void Rearrange( char Data[][Digit + 1] , int Equal[] , int n , int m , int digit )
{
        int copyindex[ n ] ;
        for ( int i = 0 ; i < n ; ++i )
                copyindex[ i ] = Position[ i ] ;
        for ( int i = 0 , key , index , position ; i < n ; ++i )
        {
                position = copyindex[ i ] ;
                key = Data[ position ][ digit ] ;
                key -= 'a' ;
                index = Equal[ key ] ;
                Position[ index ] = position ;
                ++Equal[ key ];
        }
}
void BaseSort( char Data[][ Digit + 1 ] , int n )
{
        Position = ( int * )malloc( sizeof( int ) * n ) ;
        for ( int i = 0 ; i < n ; ++i )
                Position[ i ] = i ;
        Output( Data , Size ) ;
        int m = 'Z' - 'A' + 1 ;
        int Equal[ m ] ;
        for ( int i = Digit - 1  ; i >= 0 ; --i )
        {
                memset( Equal , 0 , sizeof( int ) * m ) ;
                CountKeysEqual( Data , Equal , n  , i ) ;
                CountKeysLess( Equal , m ) ;
                Rearrange( Data , Equal , n , m , i ) ;
                Output( Data , n ) ;//显示每次排序完毕的结果
        }
}
int main( void )
{
        char Data[Size][Digit+1] = {"akc","acd","zkc","zcd","fbc","eqr","uio","poq","aqz","opi"} ;
        BaseSort( Data , Size ) ;
        return 0 ;
}
