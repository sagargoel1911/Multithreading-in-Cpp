#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int num = 0;
mutex m;

void increment()
{
	m.lock(); // if the mutex is not there, RACE condition can happen, where both threads will read 0 value and increment it. Then 1 will be the final answer.
	num++;
	m.unlock();
}

int main()
{
	thread t1(increment), t2(increment);
	t1.join();
	t2.join();
	cout << num << endl;
	return 0;
}