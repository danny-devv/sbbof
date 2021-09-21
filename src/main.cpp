#include <string>
#include <iostream>
#include "auth/auth.h"
#include "utils/utils.h"
#include "user/user.h"
#include "menu/menu.h"

int main() {
    // Welcome banner
    std::string welcome = "eSoftware Wallet";
    banner(welcome);

    // Auth loop
    int auth = authenticate();

    if (!auth)
        // Authentication failed
        return 0;
    
    // Instantiate User and create main menu loop for user
    User user;
    user.id = auth;
    user.auth = true;

    while (user.auth) {
        // Enter main menu loop
        /*
        Options:
        - show account details 
        - deposit
        - withdraw
        - sign out
        Functions:
        Prompt user input and 
        Case statement for options above
        get_account_details()
        deposit_funds()
        withdraw_funds()
        sign_out()
        */
        // Try enum for menu options
        switch(get_menu_option()) {
            case 0:
                clear_screen();
                user.show_account_details(user);
                break;
            case 1:
                clear_screen();
                user.deposit_funds(user);
                break;
            case 2:
                clear_screen();
                user.withdraw_funds(user);
                break;
            case 3:
                clear_screen();
                std::cout << "Signed Out - Goodbye." << std::endl;
                user.sign_out();
                break;
            default:
                std::cout << "Invalid Option" << std::endl;
                // Show Menu
                get_menu_option();
                break;
        }
    }
    return 0;
}

extern "C" {
    int Main() {
        return main();
    }
}
