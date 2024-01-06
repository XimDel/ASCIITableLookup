#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <climits>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

int menuOption, menuAux, confirmOption;
string input;

vector<vector<string>> table;
vector<string> row;
string line, word;

void SymbolToASCII();

void optionFail();
void fileCheck();
void rewriteFile();

int main() {
    fileCheck();
    do
    {
        cout << "\n ASCII Table Lookup" << endl << endl;
        cout << "1. Symbol to ASCII" << endl;
        cout << "2. ASCII to Symbol" << endl;
        cout << "3. ASCII Table list" << endl;
        cout << "4. Exit program" << endl << endl;
        cout << "Choose an option: ";
        cin >> menuOption;
        cin.ignore(INT_MAX, '\n');

        system("cls");
        switch (menuOption)
        {
        case 1:
        {
            system("cls");
            cout << "Symbol to ASCII" << endl;
            cout << "Enter a character: ";
            getline(cin, input);
            optionFail();
            SymbolToASCII();

            menuOption = 0;
            break;
        }

        case 2:
        {
            
            menuOption = 0;
            break;
        }

        case 3:
        {
            
            menuOption = 0;
            break;
        }

        case 4:
        {
            /*cout << "Do you want to close the program?" << endl;
            cout << "Yes: Y" << endl;
            cout << "No: N" << endl;
            cin >> confirmOption;
            if (confirmOption == 'y' || confirmOption == 'Y')
            {
                rewriteFile();
                break;
            }
            else if (confirmOption == 'n' || confirmOption == 'N')
            {
                menuOption = 0;
                system("cls");
                break;
            }
            else if (confirmOption != 'n' || confirmOption != 'N')
            {
                menuOption = 0;
                cout << "This option is not available" << endl;
                system("pause");
                break;
            }*/
            break;
        }

        default:
        {
            cout << "This option is not available" << endl;
            system("pause");
            break;
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

void fileCheck()
{
    fstream Database("Database.txt", ios::in);
    if (Database.is_open())
    {
        while (getline(Database, line))
        {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            table.push_back(row);
        }
    }
    else
    {
        Database.open("Database.txt", ios::out);

        Database << "Code,\n";
        Database << "Symbol,\n";
        Database << "Description,\n";

        Database.close();
        fstream Database("Database.txt", ios::in);

        while (getline(Database, line))
        {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            table.push_back(row);
        }
    }

    Database.close();
}

void optionFail() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Invalid option" << endl;
        getchar();
    }
}

void rewriteFile()
{
    ofstream Database;

    Database.open("Database.txt", ios::out);

    for (int i = 0, j = 0; i < table.size(); i++)
    {
        for (; j < table[0].size(); j++)
        {
            if (j == table[0].size() - 1)
            {
                Database << table[i][j] << "," << endl;
                break;
            }
            else
            {
                Database << table[i][j] << ",";
            }
        }
        j = 0;
    }

    Database.close();
}