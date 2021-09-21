#ifndef SBBOF_USER_H
#define SBBOF_USER_H
#define CPPHTTPLIB_OPENSSL_SUPPORT

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
    double amount;
    double price;
    double balance;
};

class User {
    public:
        User() {
            Account ethereum_account = {"Ethereum", "ETH", 0, 0, 0, 0.0};
            Account bitcoin_account = {"Bitcoin", "BTC", 0, 0, 0, 0.0};

            int eth_id = 0;
            int bit_id = 1;
            ethereum_account.id = eth_id;
            bitcoin_account.id = bit_id;

            std::map<std::string, double> priceMap;
            priceMap = get_token_prices();

            double eth_price = priceMap["ETH"];
            ethereum_account.price = eth_price;

            double bit_price = priceMap["BTC"];
            bitcoin_account.price = bit_price;

            ledger[eth_id] = ethereum_account;
            ledger[bit_id] = bitcoin_account;
        }
        int id;
        bool auth;
        std::map<int, Account> ledger;
        void show_account_details(User& user);
        void deposit_funds(User& user);
        void withdraw_funds(User& user);
        void sign_out();
    private:
        Account& select_account(User& user);
        void show_accounts();
        double deposit_info(Account& account_selected);
        double withdraw_info(Account& account_selected);
        bool check_crypto_api_key();
        double get_token_price(std::string symbol);
        std::map<std::string, double> get_token_prices();
};

#endif