#include <iostream>
#include <thread>

using namespace std;

class Base
{
public:
	static void run(int num)
	{
		cout << num << endl;
	}
};

int main()
{
	thread t(&Base::run, 10);
	t.join();
	return 0;
}