#include "user.h"
using json = nlohmann::json;

void User::show_accounts() {
	std::cout << "0 - Ethereum" << std::endl;
	std::cout << "1 - Bitcoin" << std::endl;
}

Account User::select_account() {
	std::cout << "Select Account: " << std::endl;

	show_accounts();

	std::string account_option;
	std::cout << "> ";
	int selected_account;

	getline(std::cin >> std::ws, account_option);
	selected_account = std::stoi(account_option);
	Account account_selected = ledger[selected_account];
	clear_screen();
	return account_selected;
}

double User::get_token_price(std::string symbol) {
	// Price
	double price;
	try {
		httplib::Client cli("https://api.nomics.com");
		if (!check_crypto_api_key()) {
			throw std::runtime_error("API Key Not Set");
		}
		std::string api_key = std::getenv("CRYPTO_API_KEY");
		std::string endpoint = "/v1/currencies/ticker?key=" + api_key + "&ids=" + symbol + "&interval=365d";
		auto res = cli.Get(endpoint.c_str());
		std::cout << res->status << std::endl;
		if (res->status == 200) {
			std::string response_body = res->body;
			json j = json::parse(response_body);
			for (auto& element : j.items()) {
				auto crypto_breakdown = element.value();
				if (crypto_breakdown["id"] == symbol) {
					std::string price_s = crypto_breakdown["price"];
					price = std::stod(price_s);
					return price;
				}
			}
		} else {
			throw std::runtime_error("Unable to fetch price data");
		}
	} catch (std::exception& e) {
	  std::cout << "Exception Caught: " << e.what() << std::endl;
	}
	return price;
}

std::map<std::string, double> User::get_token_prices() {
	// Price
	std::map<std::string, double> resultMap;
	try {
		httplib::Client cli("https://api.nomics.com");
		if (!check_crypto_api_key()) {
			throw std::runtime_error("API Key Not Set");
		}
		std::string api_key = std::getenv("CRYPTO_API_KEY");
		std::string endpoint = "/v1/currencies/ticker?key=" + api_key + "&ids=BTC,ETH&interval=365d";
		auto res = cli.Get(endpoint.c_str());
		std::cout << res->status << std::endl;
		if (res->status == 200) {
			std::string response_body = res->body;
			json j = json::parse(response_body);
			for (auto& element : j.items()) {
				auto crypto_breakdown = element.value();
				std::string price_s = crypto_breakdown["price"];
				double price = std::stod(price_s);
				std::string id = crypto_breakdown["id"];
				resultMap[id] = price;
			}
		} else {
			throw std::runtime_error("Unable to fetch price data");
		}
	} catch (std::exception& e) {
		std::cout << "Exception Caught: " << e.what() << std::endl;
	}
	return resultMap;
}

void User::show_account_details() {
	/*
	Method print account details
	*/
	Account account_selected = select_account();
	std::string account_name = account_selected.name;

	int tokens = account_selected.amount;
	double balance = account_selected.price * tokens;

	// Scene
	std::string account_details_banner = "Account Details:";
	banner(account_details_banner);
	std::cout << "Account Type: " + account_name << std::endl;
	std::cout << "Tokens: " + std::to_string(tokens) << std::endl;
	std::cout << "Price Per Token: " << account_selected.price << std::endl;
	std::cout <<  "Balance: " << std::setprecision (2) << std::fixed << balance << "\n" << std::endl;
}

bool User::check_crypto_api_key() {
	if(const char* env_p = std::getenv("CRYPTO_API_KEY"))
		return true;
	return false;
}

void User::sign_out() {
	if (auth) {
		auth = false;
	}
}

void User::deposit_info() {
	// Input depoist info
	// - Transaction Hash
	// - Num Tokens
}

void User::deposit_funds() {
	/*
	Method deposit funds
	*/
	Account account_selected = select_account();
	Account *accountPtr = &account_selected;

	// int *test = account_selected->amount;
	std::cout << accountPtr->amount << std::endl;

}