#include <iostream>
using namespace std;

class Employer
{
public:

    virtual void Print() const = 0;
    virtual ~Employer() {}
};

class President : public Employer
{
    char* name;

public:

    President(const char* input)
    {
        int length = 0;
        while (input[length] != '\0') ++length;
        name = new char[length + 1];

        for (int i = 0; i < length; ++i)
        {
            name[i] = input[i];
        }
        name[length] = '\0';
    }

    void Print() const override
    {
        cout << "President: " << name << endl;
    }

    ~President()
    {
        delete[] name;
    }
};

class Manager : public Employer
{
    char* name;

public:

    Manager(const char* input)
    {
        int length = 0;
        while (input[length] != '\0') ++length;
        name = new char[length + 1];

        for (int i = 0; i < length; ++i)
        {
            name[i] = input[i];
        }
        name[length] = '\0';
    }

    void Print() const override
    {
        cout << "Manager: " << name << endl;
    }

    ~Manager()
    {
        delete[] name;
    }
};

class Worker : public Employer
{
    char* name;

public:

    Worker(const char* input)
    {
        int length = 0;
        while (input[length] != '\0') ++length;
        name = new char[length + 1];

        for (int i = 0; i < length; ++i)
        {
            name[i] = input[i];
        }
        name[length] = '\0';
    }

    void Print() const override
    {
        cout << "Worker: " << name << endl;
    }

    ~Worker()
    {
        delete[] name;
    }
};

int main()
{
    Employer* employees[3];

    employees[0] = new President("Annet");
    employees[1] = new Manager("David");
    employees[2] = new Worker("Joe");

    for (int i = 0; i < 3; ++i)
    {
        employees[i]->Print();
    }

    for (int i = 0; i < 3; ++i)
    {
        delete employees[i];
    }

    return 0;
}