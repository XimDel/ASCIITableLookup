#include <iostream>  
#include <stdlib.h> 
#include <fstream>
#include <climits> 
#include <string> 
#include <vector> 
#include <sstream> 

using namespace std;

int menuOption, menuAux;
string input;
//char characters[];

void optionFail();
void SymbolToASCII();

int main()
{
    do {
        //system("clear");

        cout << "\n ASCII Table Lookup" << endl << endl;
        cout << "1. Symbol to ASCII" << endl;
        cout << "2. ASCII to Symbol" << endl;
        cout << "3. ASCII Table list" << endl;
        cout << "4. Exit program" << endl << endl;
        cout << "Choose an option: ";
        cin >> menuOption;
        cin.ignore(INT_MAX, '\n');

        switch (menuOption) {

        case 1:
        {
            system("cls");
            cout << "Symbol to ASCII" << endl;
            cout << "Enter a character: ";
            getline(cin, input);
            optionFail();
            SymbolToASCII();
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

        default:
        {
            cout << "Option is not available" << endl;
            system("pause");
            break;
        }

        }

        }

    } while (menuOption != 4);

    return 0;
}


void SymbolToASCII() {
    /*char characters[input.length()];

    for (int i = 0; i < input.length(); ++i) {
        characters[i] = input[i];
    }*/

    vector<char> characters(input.begin(), input.end());

    cout << "\nASCII Values:" << std::endl;
    for (int i = 0; i < input.length(); ++i) {
        std::cout << "ASCII of Character " << characters[i] << ": " << static_cast<int>(characters[i]) << std::endl;
    }
}

void optionFail() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Invalid option" << endl;
        getchar();
    }
}