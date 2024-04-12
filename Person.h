#ifndef _PERSON_H
#define _PERSON_H

#include <string>
#include <format>

namespace HR
{
	class Person
	{
	private:
		std::string m_firstName;
		std::string m_lastName;
		std::string m_initials;

	public:
		Person() = default;

		// Two-parameter constructor automatically creates initials and
		// delegates the work to the three-parameter constructor.
		Person(std::string firstName, std::string lastName);

		Person(std::string firstName, std::string lastName, std::string initials);

		virtual ~Person() = default; // A virtual destructor!

		virtual const std::string &getFirstName() const;
		virtual void setFirstName(std::string firstName);

		virtual const std::string &getLastName() const;
		virtual void setLastName(std::string lastName);

		virtual const std::string &getInitials() const;
		virtual void setInitials(std::string initials);

		operator std::string() const;

		bool operator<(const HR::Person &other) const;
		bool operator>(const HR::Person &other) const;
		bool operator<=(const HR::Person &other) const;
		bool operator>=(const HR::Person &other) const;
		bool operator==(const HR::Person &other) const;
		bool operator!=(const Person &otherPerson) const;
	};
}
std::ostream &operator<<(std::ostream &os, const HR::Person &person);

#endif
