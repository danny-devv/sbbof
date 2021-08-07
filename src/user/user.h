#ifndef SBBOF_USER_H
#define SBBOF_USER_H

#include <string>
#include <iostream>
#include <iomanip>  
#include <map>
#include "../utils/utils.h"
#include "httplib.h"
#include <nlohmann/json.hpp>
#pragma once

struct Account {
    std::string name;
    int id;
    int amount;
    double price;
};

class User {
    public:
        User() {
            Account ethereum_account = {"Ethereum", 0, 1, 3065.96};
            Account bitcoin_account = {"Bitcoin", 0, 1, 43699.60};
            ledger[0] = ethereum_account;
            ledger[1] = bitcoin_account;
        }
        int id;
        bool auth;
        std::map<int, Account> ledger;
        void show_account_details();
        void sign_out();
    private:
        void show_accounts();
        double get_account_balance();
    

};

#endif