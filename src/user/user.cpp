#include "user.h"
using json = nlohmann::json;

double User::get_account_balance() {
    double account_balance = 0.0;
    return account_balance;
}

void User::show_accounts() {
    std::cout << "0 - Ethereum" << std::endl;
    std::cout << "1 - Bitcoin" << std::endl;
}

void User::show_account_details() {
    /*
    Method print account details
    */
    std::cout << "Select Account: " << std::endl;

    show_accounts();

    std::string account_option;
    std::cout << "> ";

    getline(std::cin >> std::ws, account_option);
    int selected_account = std::stoi(account_option);
    clear_screen();

    Account account_selected = ledger[selected_account];
    std::string account_name = account_selected.name;
    int tokens = account_selected.amount;
    double price = account_selected.price;
    double balance = price * tokens;

    std::string account_details_banner = "Account Details:";
    banner(account_details_banner);

    // TODO Implement Dynamic Price Analysis
    // httplib::Client cli("https://rest.coinapi.io/v1");
    // httplib::Headers headers = {
    //     {"X-CoinAPI-Key", "B120437C-01C0-4F3C-B716-65B5787C90A2"}
    // };
    // auto res = cli.Get("/assets", headers);
    // std::string response_body = res->body;
    // int response_body = res->status;
    // json j = json::parse(response_body);
    // std::cout << response_body << std::endl;

    std::cout << "Account Type: " + account_name << std::endl;
    std::cout << "Tokens: " + std::to_string(tokens) << std::endl;
    std::cout <<  "Balance: " << std::setprecision (2) << std::fixed << balance << "\n" << std::endl;
}

void User::sign_out() {
    if (auth) {
        auth = false;
    }
}