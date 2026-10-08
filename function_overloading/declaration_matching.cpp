#include <iostream>

using namespace std;

void func( int i )
{
    cout << "Called file-scoped func : " << i << endl;
}

void func( char *sz )
{
    cout << "Called locally declared func : " << sz << endl;
}

int main()
{
    extern void func( char *sz );
    // func( 3 );
    func( "s" );
}