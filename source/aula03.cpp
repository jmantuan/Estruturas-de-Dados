#include <iostream>
using namespace std;

int main(){
    int v[3] = {1,2,3};
    int *prim = &v[0], *ult = &v[2], *p;

    for (p=prim; p <= ult; p++ ){
	//cout << p << '\n';
	cout << "v[" << p-prim << "]:" << *p << '\n';
    }
}
