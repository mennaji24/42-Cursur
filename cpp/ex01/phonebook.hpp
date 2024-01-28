#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <cstdlib> 

class Contact {
public:
    std::string firstName;
    std::string lastName;
    std::string phoneNbr;
    std::string nickName;
    std::string darkestSecret;

    // Add any other necessary member functions or declarations here
};

class phonebook {
private:
    static const int MAX_CONTACTS = 8; // Adjust the maximum number of contacts as needed
    Contact Cons[MAX_CONTACTS];
    int num; // Track the current number of contacts

public:
    phonebook() : num(0) {}; // Constructor, if needed

    void displayContactDetails(const Contact& contact);
    int getSelector() const;
    void put(const std::string& tmp) const;
    void AddContact();
    void displayContact() const;
    void ToMainMenu();
};

#endif