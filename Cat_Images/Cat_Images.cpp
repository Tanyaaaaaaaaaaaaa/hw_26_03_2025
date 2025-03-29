#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main()
{
    system("chcp 1251 > nul");
    string url = "https://cataas.com/cat";
    cout << "Press Enter to open the cat (Press 'Q' to exit) :" << endl;
    bool firstRun = true;
    while (true)
    {
        string input;
        getline(cin, input);
        if (input == "Q")
        {
            break;
        }
        if (firstRun)
        {
            ShellExecuteA(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
            cout << "The page is open ." << endl;
            firstRun = false;
        }
        else
        {
            ShellExecuteA(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
            cout << "New cat is open ." << endl;
        }
        cout << "Press Enter for the next cat (Press 'q' to exit) :" << endl;
    }
    cout << "The program is complete ." << endl;
    return 0;
}