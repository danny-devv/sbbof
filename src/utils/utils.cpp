#include "utils.h"
using namespace std;

void clear_screen() {
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || (__APPLE__)
        std::system("clear");
    #endif
}

void banner(string banner_message) {
    string banner_case = "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    string banner_message_f = "\t" + banner_message + "\t\n";
    // string banner_message = "       Login Successful      \n";
    string banner = banner_case + banner_message_f + banner_case;
    cout << banner << endl;
}