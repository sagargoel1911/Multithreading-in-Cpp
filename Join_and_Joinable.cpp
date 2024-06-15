#include <iostream>
#include <thread>

using namespace std;

void run()
{
	cout << "Sagar" << endl;
}

int main()
{
	thread t(run);
	cout << "before" << endl;
	t.join(); // Whenever we encounter this statement, we wait for this thread to finish execution and join in the main thread
	// t.join();				 // adding a second join statement will result in program termination
	if (t.joinable())
	{ // So, it is a convention to check if the thread is joinable before calling join
		t.join();
	}
	cout << "after" << endl; // this will come after the thread has finished executing
	return 0;
}