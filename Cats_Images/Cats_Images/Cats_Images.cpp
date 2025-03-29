#include <iostream>
#include <string>
#include <windows.h>
#include <urlmon.h>
#include <ctime>
#pragma comment(lib, "urlmon.lib")
using namespace std;

int main()
{
    system("chcp 1251 > nul");
    srand(time(0));
    int imageCount = 1;
    cout << "Press Enter to open and save a random cat (Press 'Q' to exit) :" << endl;
    while (true)
    {
        string input;
        getline(cin, input);
        if (input == "Q")
        {
            break;
        }
        string url = "https://cataas.com/cat?random=" + to_string(rand());
        string filename = "cat_" + to_string(imageCount) + ".jpg";
        HRESULT hr = URLDownloadToFileA(NULL, url.c_str(), filename.c_str(), 0, NULL);
        if (SUCCEEDED(hr))
        {
            cout << "Image saved as " << filename << endl;
        }
        else
        {
            cout << "Failed to save image ." << endl;
        }
        ShellExecuteA(NULL, "open", filename.c_str(), NULL, NULL, SW_SHOWNORMAL);
        imageCount++;
        cout << "Press Enter for the next random cat (Press 'Q' to exit) :" << endl;
    }
    cout << "The program is complete." << endl;
    return 0;
}