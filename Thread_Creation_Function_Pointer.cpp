#include <iostream>
#include <thread>

using namespace std;

// // Declaring
// return_type (*FuncPtr) (parameter type, ....);

// // Referencing
// FuncPtr= function_name;

// // Dereferencing
// data_type x=*FuncPtr;

// if we create multiple threads at the same time it doesn't guarantee which will start first

void fun(int num)
{
	cout << num << endl;
}

int main()
{
	thread t(fun, 10);
	t.join();
	return 0;
}