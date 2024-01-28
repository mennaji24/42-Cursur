#include "phonebook.hpp"

void phonebook::displayContactDetails(const Contact& contact)
{
    std::cout << "Details for contact:" << std::endl;
    std::cout << "Name: " << contact.firstName << std::endl;
    std::cout << "LastName:" << contact.lastName << std::endl;
    std::cout << "Nick Name: " << contact.nickName << std::endl;
    std::cout << "Phone Number: " << contact.phoneNbr << std::endl;
    std::cout << "Darkest Secret: " << contact.darkestSecret << std::endl;
    std::cout << "Press Enter to go back...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore any leftover characters in the input buffer, e.g., newline
    std::cin.get();  // Wait for the user to press Enter before continuing
}

int phonebook::getSelector() const
{
    int selector;
    std::cout << "Enter the index to view details (or 0 to go back): ";
    std::cin >> selector;

    while(std::cin.fail() || (selector < 0 || selector > num)){
        std::cin.clear();
        /*clear the input buffer and discard any remaining chars up to including the newline*/
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid index: ";
        std::cin >> selector;
    }
    return selector;

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

void phonebook::put(const std::string& tmp) const
{
    std::cout << " | ";
    if(tmp.size() > 10){
        std::cout << tmp.substr(0, 9) << ".";
    }
    else{
        std::cout << std::setw(10) << tmp;
    }
}

void phonebook::AddContact()
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
        std::cout << "Your phone is full, failed to create a new account!";
    }
}

void phonebook::ToMainMenu(){
    std::string command;

    while(true)
    {
        system("clear");
        std::cout << "Commands: ADD (1), SEARCH (2), EXIT (3)" << std::endl;
        std::cout << "Enter command: ";
        std::cin >> command;
        if(command == "ADD" || command == "1"){
            AddContact();
        }else if(command == "SEARCH" || command == "2"){
            displayContact();
            int selector = getSelector();
            if(selector > 0 && selector <= num){
                displayContactDetails(Cons[selector-1]);
            }else if(selector == 0){
                break;
            }else{
                std::cout << "Invalid index. Press Enter to continue...";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get();
            }
        }else if(command == "EXIT" || command == "1"){
            break;
        }else{
             std::cout << "Invalid command. Press Enter to continue...";
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
             std::cin.get();
        }
    }
}

int main(){
    phonebook MyphoneBook;
    MyphoneBook.ToMainMenu();
    return (0);
}