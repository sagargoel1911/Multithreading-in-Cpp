#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

// Just like mutex, but it unlocks itself whenever control goes out of scope.
// Used mostly when the code would returning something early or throws an excception

// You cannot unlock/copy lock_guard
mutex m;

void run()
{
	// acquires mutex lock the moment you create the object of lock_guard
	//  it is a very light weight wrapper for owning mutex on scope basis
	lock_guard<mutex> lock(m); // even when we are not explicitly unblocking it, both the threads are still able to run the function
	cout << "Hi" << endl;
}

int main()
{
	thread t1(run), t2(run);
	t1.join();
	t2.join();
	return 0;
}
