#include <string>
#include <vector>
#include "Person.h"
#include <fstream>
#include <iostream>
#include "Database.h"

using namespace std;

void Database::add(const HR::Person &person)
{
    m_persons.push_back(person);
}

void Database::save(const string &filename)
{
    ofstream file(filename, ios::trunc);
    if (file.is_open())
    {
        try
        {
            for (const HR::Person &person : m_persons)
            {
                file << person.getFirstName() << " " << person.getLastName() << "\n";
            }
        }
        catch (const ios_base::failure &caughtException)
        {
            cerr << "Error writing to file: " << caughtException.what() << endl;
            throw;
        }

        file.close();
    }
    else
    {
        cerr << "Could not open file for writing." << endl;
        throw runtime_error("Failed to open file for writing: " + filename);
    }
}

void Database::load(const string &filename)
{
    ifstream file(filename);
    if (file.is_open())
    {
        try
        {
            clear();
            string firstName, lastName, initials;
            while (file >> firstName >> lastName >> initials)
            {
                add(HR::Person(firstName, lastName, initials));
            }
        }
        catch (const ios_base::failure &caughtException)
        {
            cerr << "Error reading from file: " << caughtException.what() << endl;
            throw;
        }

        file.close();
    }
    else
    {
        cerr << "Could not open file for reading." << endl;
        throw runtime_error("Failed to open file for reading: " + filename);
    }
}

void Database::clear()
{
    m_persons.clear();
}

void Database::outputAll() const
{
    for (const HR::Person &person : m_persons)
    {
        cout << person << endl;
    }
}
