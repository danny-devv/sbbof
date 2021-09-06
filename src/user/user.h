#ifndef SBBOF_USER_H
#define SBBOF_USER_H

#include <string>
#include <iostream>
#include <iomanip>  
#include <map>
#include "../utils/utils.h"
#include "httplib.h"
#include <cstdlib>
#include <nlohmann/json.hpp>
#pragma once

struct Account {
    std::string name;
    std::string symbol;
    int id;
    int amount;
    double price;
};

class User {
    public:
        User() {
            Account ethereum_account = {"Ethereum", "ETH", 0, 1, 0};
            Account bitcoin_account = {"Bitcoin", "BTC", 0, 1, 0};

            int eth_id = 0;
            int bit_id = 1;
            ethereum_account.id = eth_id;
            bitcoin_account.id = bit_id;

            double eth_price = get_token_price("ETH");
            ethereum_account.price = eth_price;

            double bit_price = get_token_price("BTC");
            bitcoin_account.price = bit_price;

            ledger[eth_id] = ethereum_account;
            ledger[bit_id] = bitcoin_account;
        }
        int id;
        bool auth;
        std::map<int, Account> ledger;
        void show_account_details();
        void deposit_funds();
        void sign_out();
    private:
        Account select_account();
        void show_accounts();
        void deposit_info();
        bool check_crypto_api_key();
        double get_token_price(std::string symbol);
};

#endif