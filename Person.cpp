#include <iostream>
#include "Person.h"
#include <sstream>

using std::string;

HR::Person::Person(string firstName, string lastName)
    : m_firstName(std::move(firstName)), m_lastName(std::move(lastName)), m_initials(m_firstName.substr(0, 1) + m_lastName.substr(0, 1))
{
}

HR::Person::Person(string firstName, string lastName, string initials)
    : m_firstName{std::move(firstName)}, m_lastName{std::move(lastName)}, m_initials{std::move(initials)}
{
}

const string &HR::Person::getFirstName() const
{
    return m_firstName;
}

void HR::Person::setFirstName(string firstName)
{
    m_firstName = std::move(firstName);
}

const string &HR::Person::getLastName() const
{
    return m_lastName;
}

void HR::Person::setLastName(string lastName)
{
    m_lastName = std::move(lastName);
}

const string &HR::Person::getInitials() const
{
    return m_initials;
}

void HR::Person::setInitials(string initials)
{
    m_initials = std::move(initials);
}

HR::Person::operator string() const
{
    std::stringstream ss;
    ss << "Name(" << m_firstName << ", " << m_lastName << ", " << m_initials << ")";
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const HR::Person &person)
{
    os << (string)person;
    return os;
}

bool HR::Person::operator<(const Person &other) const
{
    if (m_lastName != other.m_lastName)
        return m_lastName < other.m_lastName;
    return m_firstName < other.m_firstName;
}

bool HR::Person::operator>(const Person &other) const
{
    return other.m_lastName < m_lastName || (other.m_lastName == m_lastName && other.m_firstName < m_firstName);
}

bool HR::Person::operator<=(const Person &other) const
{
    return !(m_lastName < other.m_lastName || (m_lastName == other.m_lastName && m_firstName < other.m_firstName));
}

bool HR::Person::operator>=(const Person &other) const
{
    return !(m_lastName > other.m_lastName || (m_lastName == other.m_lastName && m_firstName > other.m_firstName));
}

bool HR::Person::operator==(const Person &other) const
{
    return m_firstName == other.m_firstName && m_lastName == other.m_lastName;
}

bool HR::Person::operator!=(const Person &otherPerson) const
{
    return (m_firstName != otherPerson.m_firstName && m_lastName != otherPerson.m_lastName);
}
