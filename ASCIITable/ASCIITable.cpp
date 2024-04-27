#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <climits>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
//TEST
using namespace std;

int menuOption, menuAux, confirmOption, showLimit, aux, AsciiFound,location;
string input, printSpaces, AsciiNumber;

vector<vector<string>> table;
vector<string> row;
string line, word;

void symbolToASCII();
void findASCII();
void ASCIIToSymbol();
void showTable();

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
            symbolToASCII();
            menuOption = 0;
            break;
        }

        case 2:
        {
            system("cls");
            cout << "ASCII to symbol" << endl;
            cout << "Enter an ASCII number: ";
            cin >> AsciiNumber;
            findASCII();

            if (AsciiFound == 1)
            {
                cout << "\n" << endl;
                cout << "ASCII code found:" << endl;
                ASCIIToSymbol();
            }
            else if (AsciiFound == 0)
            {
                cout << "ASCII code not found, try again." << endl;
            }

            menuOption = 0;
            break;
        }

        case 3:
        {
            showTable();
            menuOption = 0;
            break;
        }

        case 4:
        {
            cout << "Goodbye" << endl;
            system("pause");
             rewriteFile();
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

void symbolToASCII() {

    vector<char> characters(input.begin(), input.end());

    cout << "\nASCII Values:" << std::endl;
    for (int i = 0; i < input.length(); ++i) {
        std::cout << "ASCII of Character " << characters[i] << ": " << static_cast<int>(characters[i]) << std::endl;
    }
}

void findASCII() {

    for (int i = 0, j = 0; j < table[0].size(); j++)
    {
        aux = 1;
        if (AsciiNumber == table[i][j])
        {
            AsciiFound = 1;
            location = j;
            break;
        }
        else
        {
            aux = 0;
        }
    }
    if (aux == 0)
    {
        AsciiFound = 0;
    }
}

void ASCIIToSymbol()
{
    cout << table[0][0] << "   ";
    cout << table[1][0] << "   "<<endl;
    cout << table[0][location] << "    ";
    cout << table[1][location] << " "<<endl;
    cout << endl;
}

void showTable(){
    for (int j = 0; j < row.size(); j++) {
        cout << table[0][j] << "    ";
        cout << table[1][j] << " ";
        cout << endl;
    }
    cout << endl;
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

void optionFail() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Invalid option" << endl;
        getchar();
    }
}
