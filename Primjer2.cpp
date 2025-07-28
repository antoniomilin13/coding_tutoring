#include <iostream>
using namespace std;


int main() {

	/*int a = 1;
	int b = 2;
	int temp;
	

	temp = a;
	a = b;
	b = temp;

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
*/

	int a = 1, b = 2, c = 3, temp;

	// a->b->c->a    zad

	temp = b;
	b = a;
	a = c;
	c = temp;
	
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout <<"c: " << c << endl;

	return 0;
}