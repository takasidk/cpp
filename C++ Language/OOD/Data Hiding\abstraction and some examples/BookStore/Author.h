#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>
using namespace std;

class Author
{
private:
    string name;
    string email;
    char gender; // 'm', 'f', or 'u' for unknown

public:
    // pass by value which reduces the performance by clone copying
    //Author(string name, string email, char gender);
    Author(const std::string &name, const std::string &email, char gender);
    // & specifies pass by reference, const for non-mutable
    string getName() const;
    string getEmail() const;
    //void setEmail(string email);
    // pass by reference
    void setEmail(const string &email);
    char getGender() const;
    void print() const;
};

#endif