#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <chrono>

using namespace std;

// Few important points to remember about the unique_lock is as follows:
// 1. The class unique_lock is a mutex ownership wrapper.
// 2. It Allows:
//     a. Can Have Different Locking Strategies
//     b. time-constrained attempts at locking (try_lock_for, try_lock_until)
//     c. recursive locking
//     d. transfer of lock ownership (move not copy)
//     e. condition variables. (See this in coming videos)

// Locking Strategies
//    TYPE           EFFECTS(S)
// 1. defer_lock  do not acquire ownership of the mutex.
// 2. try_to_lock  try to acquire ownership of the mutex without blocking.
// 3. adopt_lock  assume the calling thread already has ownership of the mutex.

// unlock happens in the destrucotr of the object we make;

// lock_guard has more restrictions, but is also lighter

std::mutex m1;
int buffer = 0;

// EXAMPLE 2
void task(const char *threadNumber, int loopFor)
{
	std::unique_lock<mutex> lock(m1, defer_lock);
	lock.lock();
	for (int i = 0; i < loopFor; ++i)
	{
		buffer++;
		cout << threadNumber << buffer << endl;
	}
}

int main()
{
	thread t1(task, "T1: ", 10);
	thread t2(task, "T2: ", 10);
	t1.join();
	t2.join();

	return 0;
}
