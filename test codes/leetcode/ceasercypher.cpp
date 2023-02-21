#include <iostream>
#include <string>

using namespace std;

string encrypt(string text, int shift);
string decrypt(string cipher, int shift);

int main() {
    string message;
    int shift;

    cout << "Enter a message: ";
    getline(cin, message);

    cout << "Enter a shift value: ";
    cin >> shift;

    string encrypted = encrypt(message, shift);
    string decrypted = decrypt(encrypted, shift);

    cout << "Encrypted message: " << encrypted << endl;
    cout << "Decrypted message: " << decrypted << endl;

    return 0;
}

string encrypt(string text, int shift) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                result += char(int(text[i] + shift - 65) % 26 + 65);
            } else {
                result += char(int(text[i] + shift - 97) % 26 + 97);
            }
        } else {
            result += text[i];
        }
    }
    return result;
}

string decrypt(string cipher, int shift) {
    string result = "";
    for (int i = 0; i < cipher.length(); i++) {
        if (isalpha(cipher[i])) {
            if (isupper(cipher[i])) {
                result += char(int(cipher[i] - shift - 65 + 26) % 26 + 65);
            } else {
                result += char(int(cipher[i] - shift - 97 + 26) % 26 + 97);
            }
        } else {
            result += cipher[i];
        }
    }
    return result;
}
