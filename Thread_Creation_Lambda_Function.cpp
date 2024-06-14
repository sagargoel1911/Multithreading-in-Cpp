#include <iostream>
#include <thread>

using namespace std;

// this is the syntax for lambda functions
//[](param_list){body};

// C++ 11 introduced lambda expressions to allow inline functions which can be used for short snippets of code that are not going to be reused and therefore do not require a name. In their simplest form a lambda expression can be defined as follows:

// [ capture clause ] (parameters) -> return-type
// {
//    definition of method
// }
// Generally, the return-type in lambda expressions is evaluated by the compiler itself and we don’t need to specify it explicitly. Also the -> return-type part can be ignored.  However, in some complex cases e.g. conditional statements, the compiler can’t determine the return type and explicit specification is required.
auto fun = [](int num)
{
	cout << num << endl;
};
int main()
{
	// thread t(fun, 10);

	// we can also inject the lambda function directly into the thread call
	thread t([](int num)
			 { cout << num << endl; }, 10);
	t.join();
	return 0;
}
