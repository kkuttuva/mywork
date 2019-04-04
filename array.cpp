#include <iostream>

using namespace std;

void foo( char (*a)[5]) {
   cout << "foo " << sizeof(a) << endl;
}

void foo2( char a[5][5]) {
   cout << "foo2" << sizeof(a) << endl;
   a[1][1] = 'a';
}
int main() {
   char a[5][5];
   foo(a);
   cout << a[1][1] << endl;
   foo2(a);
   cout << a[1][1] << endl;
   return 0;
}
