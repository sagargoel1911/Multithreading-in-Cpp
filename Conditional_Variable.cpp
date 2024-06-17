#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

condition_variable cv;
mutex m;
long long balance = 0;

void addMoney(int money)
{
	lock_guard<mutex> lg(m);
	balance += money;
	cout << "Balance After Adding: " << balance << endl;
	cv.notify_one(); // after the other thread is notified, it becomes active and the condition of cv is calculated again
}

void withdrawMoney(int money)
{
	unique_lock<mutex> ul(m); // Here mutex m is locked by thread t1;
	cv.wait(ul, []
			{ return (balance != 0) ? true : false; }); // Here, if we return false, the thread releases the mutex, if it held it before
	// if the answer is true, the thread locks the mutex if it was not already locking it.
	if (balance >= money)
	{
		balance -= money;
		cout << "Balance after subtraction: " << balance << endl;
	}
	else
	{
		cout << "Money cannot be withdrawed\n";
	}
}

int main()
{
	thread t1(withdrawMoney, 500);
	thread t2(addMoney, 500);
	t1.join();
	t2.join();
	return 0;
}