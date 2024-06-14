#include <iostream>
#include <thread>

using namespace std;

class Base
{
public:
	void operator()(int num)
	{
		cout << num << endl;
	}
};

int main()
{
	thread t((Base()), 10);
	t.join();
	return 0;
}