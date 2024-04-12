#include "AssociativeArray.h"
#include <iostream>

using namespace std;

int main()
{
	try
	{
		AssociativeArray<int> associativeArray;
		associativeArray["key1"] = 11;
		associativeArray["key2"] = 22;
		associativeArray["key3"] = 33;

		cout << "Accessing existing keys:" << endl;
		cout << associativeArray["key1"] << endl;
		cout << associativeArray["key2"] << endl;

		// Test const operator[]
		const AssociativeArray<int> &constAssociativeArray{associativeArray};
		cout << "Accessing existing keys through const reference:" << endl;
		cout << constAssociativeArray["key3"] << endl;
		cout << constAssociativeArray["key6"] << endl;
	}
	catch (const invalid_argument &exception)
	{
		cout << "Caught exception: " << exception.what() << endl;
	}

	return 0;
}