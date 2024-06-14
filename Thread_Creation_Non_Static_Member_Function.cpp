#include <iostream>
#include <thread>

using namespace std;

class Base
{
public:
	void run(int num)
	{
		cout << num << endl;
	}
};

int main()
{
	Base b;
	thread t(&Base::run, &b, 10);
	t.join();
	return 0;
}