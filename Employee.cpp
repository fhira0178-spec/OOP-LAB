#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    string employeeName;
    int employeeNumber;
    string hireDate;

public:
    Employee()
    {
        employeeName = "";
        employeeNumber = 0;
        hireDate = "";
    }

    Employee(string name, int number, string date)
    {
        employeeName = name;
        employeeNumber = number;
        hireDate = date;
    }

    void setEmployeeName(string name)
    {
        employeeName = name;
    }

    void setEmployeeNumber(int number)
    {
        employeeNumber = number;
    }

    void setHireDate(string date)
    {
        hireDate = date;
    }

    string getEmployeeName() const
    {
        return employeeName;
    }

    int getEmployeeNumber() const
    {
        return employeeNumber;
    }

    string getHireDate() const
    {
        return hireDate;
    }
};

class ShiftSupervisor : public Employee
{
private:
    double annualSalary;
    double annualBonus;

public:
    ShiftSupervisor() : Employee()
    {
        annualSalary = 0.0;
        annualBonus = 0.0;
    }

    ShiftSupervisor(string name, int number, string date,
        double salary, double bonus)
        : Employee(name, number, date)
    {
        annualSalary = salary;
        annualBonus = bonus;
    }

    void setAnnualSalary(double salary)
    {
        annualSalary = salary;
    }

    void setAnnualBonus(double bonus)
    {
        annualBonus = bonus;
    }

    double getAnnualSalary() const
    {
        return annualSalary;
    }

    double getAnnualBonus() const
    {
        return annualBonus;
    }

    double getTotalIncome() const
    {
        return annualSalary + annualBonus;
    }
};

int main()
{
    string name, date;
    int number;
    double salary, bonus;

    cout << "Enter employee name: ";
    getline(cin, name);

    cout << "Enter employee number: ";
    cin >> number;

    cin.ignore();

    cout << "Enter hire date: ";
    getline(cin, date);

    cout << "Enter annual salary: ";
    cin >> salary;

    cout << "Enter annual production bonus: ";
    cin >> bonus;

    ShiftSupervisor supervisor(name, number, date, salary, bonus);

    cout << "\nShift Supervisor Information\n";
    cout << "Name: " << supervisor.getEmployeeName() << endl;
    cout << "Employee Number: " << supervisor.getEmployeeNumber() << endl;
    cout << "Hire Date: " << supervisor.getHireDate() << endl;
    cout << "Annual Salary: " << supervisor.getAnnualSalary() << endl;
    cout << "Annual Bonus: " << supervisor.getAnnualBonus() << endl;
    cout << "Total Annual Income: " << supervisor.getTotalIncome() << endl;

    return 0;
}