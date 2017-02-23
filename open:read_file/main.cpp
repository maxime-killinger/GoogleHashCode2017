//
// Created by Maxime Killinger on 23/02/2017.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int                             main(int  ac, char **av)
{
    ifstream                    file(av[1], ios::in);
    string                      buff;

    if (!file)
        return (-1);
    while (getline(file, buff))
    {
        istringstream      iss(buff);
        string             token;

        while (getline(iss, token, ' '))
        {
            cout << token << endl;
        }
    }
    file.close();
    return (0);
}

