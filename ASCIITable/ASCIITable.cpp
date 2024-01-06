#include <iostream>  
#include <stdlib.h> 
#include <fstream>
#include <climits> 
#include <string> 
#include <vector> 
#include <sstream> 

using namespace std;

int menuOption, menuAux;

int main()
{
    do {
        system("clear");

        cout << "ASCII Table Lookup" << endl << endl;

        cout << "1. Symbol to ASCII" << endl;
        cout << "2. ASCII to Symbol" << endl;
        cout << "3. ASCII Table list" << endl;
        cout << "4. Exit program" << endl << endl;
        cout << "Choose an option: ";
        cin >> menuOption;

        switch (menuOption) {

        case 1:
        {
            break;
        }

        case 2:
        {
            break;
        }

        case 3:
        {
            break;
        }

        case 4:
        {
            cout << "Do you want to close the program? - y/n" << endl;
            cin >> menuAux;
            if (menuAux == 'y' || menuAux == 'Y')
            {
                //reescribirArchivo();
                break;
            }
            else
            {
                menuOption = 0;
                system("clear");
                break;
            }
            break;
        }

        }

    } while (menuOption != 4);

    return 0;
}
