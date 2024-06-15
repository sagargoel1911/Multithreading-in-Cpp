#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

// Same as mutex but we can lock it using the same thread multiple times also
// We have to unlock the mutex that many times as well
//  The max number of times you can do varies system to system, then it will give std::error for lock and false for try_lock
// Try to avoid it.

recursive_mutex m;

void run(int num)
{
	if (num >= 5)
		return;
	m.lock();
	cout << 1 << endl;
	run(num + 1);
	m.unlock();
}

int main()
{
	thread t(run, 0);
	t.join();
	return 0;
}
