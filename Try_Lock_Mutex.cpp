#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

// There are atleast 9 types of try_lock in cpp
// Here is the demonstration of mutex's try lock
// try_lock is a non blocking lock
// Meaning: In normal mutex lock, if you are trying to lock and the mutex is locked by someone else, the thread is now blocked and it waits the mutex to unlock
// But here, if we cannot lock a mutex currently, try_lock just returns false and the code moves on
// Since it does not make the code to stop, it is known as non blocking
// If a try_lock is called by a thread that has already locked the mutex, it is deadlock situation and undefined behaviour
// If you want to do this, go for recursive mutex

int num = 0;
mutex m;

void run()
{
	for (int i = 0; i < 100; i++)
	{
		if (m.try_lock())
		{
			num++;
			m.unlock();
		}
	}
}

int main()
{
	thread t1(run), t2(run);
	t1.join();
	t2.join();
	cout << num << endl; // output can be any number between 1 and 200
}