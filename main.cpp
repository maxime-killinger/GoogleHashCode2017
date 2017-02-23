#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    ifstream                    file("../GoogleFiles/kittens.in", ios::in);
    string                      buff;
    string             token;

    if (!file) {
        cout << "Error opening file" << endl;
        return (-1);
    }
    while (getline(file, buff)) {
        istringstream      iss(buff);
        while (getline(iss, token, ' ')) {
            cout << token << endl;
        }
    }
    file.close();
    return (0);
}