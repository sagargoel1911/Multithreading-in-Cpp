#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

// std:: try_lock tries to lock all the mutexes given to it in given order
//  on success returns -1
//  on failure to lock any one of the mutex, it returns the 0 based index of the mutex which has failed
// in case of failure, all the mutexes locked till now are released

int main()
{
	mutex m1, m2, m3;
	int num = try_lock(m1, m2, m3);
	cout << num << endl;
	num = try_lock(m1, m2, m3);
	cout << num << endl;
	m1.unlock();
	m2.unlock();
	num = try_lock(m1, m2, m3);
	cout << num << endl;
	num = try_lock(m1, m2, m3);
	cout << num << endl;

	// Output:
	// -1
	//  0
	//  2
	//  2
	return 0;
}