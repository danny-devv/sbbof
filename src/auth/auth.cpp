#include "auth.h"

using namespace std;
using json = nlohmann::json;

bool check_authentication() {
    bool auth_flag = false;
    char input_buffer[16];
    cout << "Enter Secure Passcode: ";
    string secure_passcode;
    getline(cin >> std::ws, secure_passcode); 
    strcpy(input_buffer, secure_passcode.c_str());

    // TODO change debug password @dmiNP@s$woRd 
    if (strcmp(input_buffer, "test") == 0) 
        auth_flag = true;
    
    return auth_flag;
}

int login_info() {
    // Secure User Lookup
    httplib::Client cli("https://randomuser.me");
    auto res = cli.Get("/api");
    string response_body = res->body;
    json j = json::parse(response_body);
    map<string, string> name = j["results"][0]["name"];
    cout << "Welcome, " + name["title"] + " " + name["first"] + " " + name["last"] << endl;
    srand (time(NULL));
    int user_id = rand() % 1000 + 1;
    return user_id;
}

int authenticate() {
    // Auth variables 
    int tries_remaining = 5;
    while (tries_remaining > 0) {
        bool auth_check = check_authentication();
        if (auth_check) {
            clear_screen();
            // Show Auth'd Info
            string login = "Login Successful";
            banner(login);
            int id = login_info();
            return id;
        } else {
            // Should print warning message, wrong auth -> tries remaining
            tries_remaining -= 1;
        }
    }
    return 0;
}