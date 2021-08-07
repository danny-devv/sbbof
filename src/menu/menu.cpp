#include "menu.h"

void show_menu() {
    /*
    Options:
        - show account details 
        - deposit
        - withdraw
        - sign out
    */
   std::cout << "0 - Show Account Details" << std::endl;
   std::cout << "1 - Deposit" << std::endl;
   std::cout << "2 - Withdraw" << std::endl;
   std::cout << "3 - Sign Off" << std::endl; 
}

int get_user_option() {
    std::cout << "Enter Option: ";

    std::string user_option;

    getline(std::cin >> std::ws, user_option);
    
    return std::stoi(user_option);
}

int get_menu_option() {
    show_menu();
    int user_option = get_user_option();
    return user_option;
}