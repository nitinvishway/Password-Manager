#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string encryptDecrypt(string password) {
    char key = 'X';
    string output = password;
    
    for (int i = 0; i < password.size(); i++) {
        output[i] = password[i] ^ key;
    }
    return output;
}


void addPassword() {
    string account, password;
    cout << "Enter account name: ";
    cin >> account;
    cout << "Enter password: ";
    cin >> password;


    string encryptedPassword = encryptDecrypt(password);

    ofstream file;
    file.open("passwords.txt", ios::app);
    file << account << " " << encryptedPassword << endl;
    file.close();

    cout << "Password added successfully!\n";
}


void viewPasswords() {
    string account, password;

    ifstream file("passwords.txt");
    if (file.is_open()) {
        while (file >> account >> password) {

            string decryptedPassword = encryptDecrypt(password);
            cout << "Account: " << account << ", Password: " << decryptedPassword << endl;
        }
        file.close();
    } else {
        cout << "No passwords found.\n";
    }
}

int main() {
    int choice;
    
    do {
        cout << "\nPassword Manager\n";
        cout << "1. Add new password\n";
        cout << "2. View passwords\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}

