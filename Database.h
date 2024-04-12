#ifndef DATABASE_H
#define DATABASE_H

#include "Person.h"

class Database
{
private:
    std::vector<HR::Person> m_persons;

public:
    void add(const HR::Person &person);

    void save(const std::string &filename);

    void load(const std::string &filename);

    void clear();

    void outputAll() const;
};

#endif