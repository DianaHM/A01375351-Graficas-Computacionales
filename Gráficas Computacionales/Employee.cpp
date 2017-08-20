#include "Employee.h"
#include <string>
#include <iostream>

Employee::Employee(int id, std::string firstName, std::string lastName, int salary)
{
	_id = id;
	_salary = salary;
	FirstName = firstName;
	LastName = lastName;
}

int Employee::GetId()
{
	return _id;
}

std::string Employee::GetFirstName()
{
	return FirstName;
}

std::string Employee::GetLastName()
{
	return LastName;
}

std::string Employee::GetName()
{
	return std::string(FirstName + " " + LastName);
}

int Employee::GetSalary()
{
	return _salary;
}

void Employee::SetSalary(int salary)
{
}

int Employee::GetAnnualSalary()
{
	return _salary * 12;
}

int Employee::RaiseSalary(int percent)
{
	return ((_salary*percent) / 100) + _salary;
}

std::string Employee::Print()
{
	std::string name;
	name = FirstName + " " + LastName;
	return std::to_string(_id) + " " + name + " " + std::to_string(_salary);
}
