#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define LL long long
#define endl "\n"

using namespace std ;

const int es_tak_max = 1e3 ;

struct es_tak {

    int sz ;

    char a[es_tak_max] ;

} ;

void dhukao( es_tak *p , char item )
{

    if( p->sz < es_tak_max )  {

        p->a[ p->sz ] = item ;

        p->sz = p->sz + 1 ;

    }

    else  {

        cout << " Stack is full ! " << endl ;

    }

}

char bair_ho( es_tak *p )
{

    char item = 'F' ;

    if( p->sz == 0 )  {

        return item ;

    }

    else  {

        p->sz = p->sz - 1 ;

        item = p->a[ p->sz ] ;

    }

    return item ;

}

bool solve( string s )
{

    string khali = "" ;

    if( s == khali )  return true ;

    es_tak starting , ending ;

    starting.sz = ending.sz = 0 ;



    for( int i = 0 ; i < s.size() ; i++ )  {

        if( s[i] == '(' || s[i] == '[' )  {

            dhukao( &starting , s[i] ) ;

        }

        else if( s[i] == ')' || s[i] == ']' )  {

            char val = bair_ho( &starting ) ;

            if( val == 'F' )  {

              //  cout << " val : " << val << endl ;

                return false ;

            }

            if( ( s[i] == ')' && val != '(' ) || ( s[i] == ']' && val != '[' ) )  {

               // cout << " val holo  : " << val << endl ;

                return false ;

            }

        }

    }

    if( starting.sz == 0 )  return true ;

    else  return false ;

}

int main( void )
{

    #ifndef ONLINE_JUDGE
        freopen( "input.txt" , "r" , stdin ) ;
        freopen( "output.txt" , "w" , stdout ) ;
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio( false ) ;

    cin.tie( NULL ) ;

    cout.tie( NULL ) ;

    int n ;

    cin >> n ;

    cin.ignore() ;

    while( n-- )  {

        string s ;

        getline( cin , s ) ;

       // cout << " string is : " << s << endl ;

        if( solve( s ) || s.size() == 0 )  cout << "Yes\n" ;

        else  cout << "No\n" ;

    }

    return 0 ;

}

