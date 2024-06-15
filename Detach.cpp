#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void run()
{
	cout << "Sagar" << endl;
	this_thread::sleep_for(chrono::seconds(5));
}

int main()
{
	thread t(run);

	cout << "before" << endl;
	t.detach(); // detaches the exexcution of the thread t from the main thread. Now the main program will not wait for the thread to complete
	// If the main program completes before the thread execution is complete, the thread executio is suspended
	// We should always put one of the join() or detach() commands in the thread, as the thread destructor sees if the thread is still joinable, it terminates the program

	// t.detach(); // Double detach terminates the program
	// So, we should always check if the thread iis joinable before detaching
	if (t.joinable())
	{
		t.detach();
	}
	cout << "after" << endl;
	return 0;
}