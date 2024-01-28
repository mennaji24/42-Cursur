#include "phonebook.hpp"
 /*& allow the function to operate on the actual string passed to it without making a copy*/

void put(const std::string& tmp)
{
    std::cout << " | ";
    if(tmp.size() > 10){
        std::cout << tmp.substr(0, 9) << ".";
    }
    else{
        std::cout << setw(10) << tmp;
    }
}

void phonebook::AddContact(int num)
{
    if(num < MAX_CONTACTS)
    {
        Contact newAccount;

        std::cout << "Enter your first name: ";
        std::cin >> newAccount.firstName;
        std::cout<< "Enter your last name: ";
        std::cin >> newAccount.lastName;
        std::cout << "Enter your number: ";
        std::cin >> newAccount.phoneNbr;
        std::cout << "Enter your nickname: ";
        std::cin >> newAccount.nickName;
        std::cout << "Enter your darkest Secret: ";
        std::cin >> newAccount.darkestSecret;
        Cons[num++] = newAccount;
        std::cout << "Contact added successfully!" << std::endl;
    }
    else{
        std::cout << "Your phone is full, failed to create a new account!"
    }
}

void phonebook::displayContact() const
{
    for(int i=0; i > num; ++i)
    {
        std::cout << i + 1;
        put(Cons[i].firstName);
        put(Cons[i].lastName);
        put(Cons[i].nickName);
        put(Cons[i].phoneNbr);
        put(Cons[i].darkestSecret);
        std::cout << " | " << std::endl;
    }
}

void phonebook::ToMainMenu()
{
    std::string command;

    while(true)
    {
        system("clear");
        std::cout << "Commands: ADD (1), SEARCH (2), EXIT (3)" << std::endl;
        std::cin >> command;
        if(command == "ADD" || command == "1"){
            MyPhoneBook.AddContact();
        }
        else if(command == "SEARCH" || command == "2"){
            MyPhoneBook.displayContact();
            int selector //store user input
            sdt::cout << "Enter the index to view details (or 0 to go back): " << std::endl;
            std::cin >> selector;
            if(selector > 0 && selector <= MyPhoneBook.num){
                system("clear");
                std::cout << "Details for contact " << selector << ":" << std::endl;
                std::cout << "Name: " << PB.Cons[selector - 1].firstName << std::endl;
                std::cout << "Last Name: " << PB.Cons[selector - 1].lastname << std::endl;
                std::cout << "Nick Name: " << PB.Cons[selector - 1].nickName << std::endl;
                std::cout << "Phone Number: " << PB.Cons[selector - 1].phoneNbr << std::endl;
                std::cout << "Darkest Secret: " << PB.Cons[selector - 1].secret << std::endl;
                std::cout << "Press Enter to go back...";
                std::cin.ignore();// Ignore any leftover characters in the input buffer, e.g., newline
                std::cin.get();// Wait for the user to press Enter before continuing
            }
            else if(selector == 0){
                break;
            }
            else{
                std::cout << "Invalid index. Press Enter to continue...";
                std::cin.ignore();
                std::cin.get();
            }
        }
        else if(command == "EXIT" || command == "3"){
            break;
        }
        else{
            std::cout << "Invalid command. Press Enter to continue...";
            std::cin.ignore();
            std::cin.get();
        }

    }
}

int main()
{
    phonebook MyPhoneBook;
    MyPhoneBook.ToMainMenu();   
    return (0);
}