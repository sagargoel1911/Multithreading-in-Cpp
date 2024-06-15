#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

// Just like mutex's try lock, but waits foor a certain amount of time for mutex to unlock before returning true / false;

timed_mutex m;

void num()
{
	if (m.try_lock_for(chrono::seconds(3))) // if 1 sec here, only 1 Hi will be there, else if 3 sec, 2 Hi will be there
	{
		this_thread::sleep_for(chrono::seconds(2));
		cout << "Hi" << endl;
		m.unlock();
	}
}

int main()
{
	thread t1(num), t2(num);
	t1.join();
	t2.join();

	return 0;
}