#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <stdexcept>

using namespace std;

// Returns false on error
void changeNumberForID(string_view filename, int id, string_view newNumber);

int main()
{
	try
	{
		changeNumberForID("data.txt", 263, "415-555-3333");
	}
	catch (const runtime_error &caughtException)
	{
		cerr << "An error occurred: " << caughtException.what() << endl;
	}
}

void changeNumberForID(string_view filename, int id, string_view newNumber)
{
	fstream ioData{filename.data()};
	if (!ioData)
	{
		throw runtime_error("Error while opening file " + string(filename));
	}

	// Loop until the end of file
	while (ioData)
	{
		// Read the next ID.
		int idRead;
		ioData >> idRead;
		if (!ioData)
			break;

		// Check to see if the current record is the one being changed.
		if (idRead == id)
		{
			// Seek the write position to the current read position.
			ioData.seekp(ioData.tellg());
			if (!ioData)
			{
				throw runtime_error{"Failed to seek to the proper position in the output stream."};
			}
			// Output a space, then the new number.
			ioData.close();
			ioData << " " << newNumber;
			if (!ioData)
			{
				throw runtime_error{"Failed to write to the output stream."};
			}
			break;
		}

		// Read the current number to advance the stream.
		string number;
		ioData >> number;
		if (!ioData)
		{
			throw runtime_error{"Failed to read next number from the input stream."};
		}
	}
	if (!ioData)
	{
		throw runtime_error("ID not found in the file.");
	}
}
