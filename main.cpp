#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    ifstream                    file("GoogleFiles/kittens.in", ios::in);
    string                      buff;
    istringstream      iss(buff);
    string             token;

    if (!file) {
        cout << "Error opening file" << endl;
        return (-1);
    }
    getline(file, buff);
    while (getline(iss, token, ' '))
    {
        cout << token << endl;
    }
    file.close();
    return (0);
}