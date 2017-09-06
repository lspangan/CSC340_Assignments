#include <cstdlib>
#include <iostream>
using namespace std;

int func1(int a)
{
	a = a + 30;       // doesn't modify anything
	                  // outside func1
	return a - 10;
}

int func2(int *b)
{
	*b = 13;  // modifies what you passed!
	b += 10;  // only modifies the pointer
	return *b;
}

int func3(int &c)
{
	c += 3;
	return c - 5;
}

int main()
{
	int x = 10;
	func1(x);
	func2(&x);
	int y = func3(x);

	cout << "x: " << x << " and y: " << y << endl;

	return 0;
}
