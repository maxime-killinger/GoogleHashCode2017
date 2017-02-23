//
// Created by Maxime Killinger on 23/02/2017.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream file("file.in", ios::in);
    if(file)
    {
        string buff;
        getline(file, buff);
        cout << buff;
        fichier.close();
    }
    else
        cerr << "File not found" << endl;

    return 0;
}

