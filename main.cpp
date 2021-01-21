#include <iostream>
#include <fstream>
#include <windows.h>
#include <direct.h>
#include <winbase.h>
#include <conio.h>


using namespace std;

string plik,candidate;

void FolderExist()
{
    if(!CreateDirectory("logs",0)){}
    else
    {
        _mkdir("logs");
    }

    if(!CreateDirectory("config",0)){}
    else
    {
        _mkdir("config");
        FILE *file;
        if (file = fopen("./config/config.txt",0))
        {
            fclose(file);
        }
        else
        {
            ofstream Config("./config/config.txt");
        }

    }
}


int main()
{
        FolderExist();

    cout<<"MENU"<<endl;
    cout<<"1. Zmiana nazwy glownego configu"<<endl;
    cout<<"2. Usun logi"<<endl;
    cout<<"3. Kontynuacja"<<endl;

        char Choose=getch();

    switch(Choose){
        case '1': {
            fstream outfile;
            outfile.open("./config/config.txt", ios::out);
            cout<<"Podaj nazwe pliku z rozszerzeniem: ";

                cin>>plik;
                outfile<<plik;
                outfile.close();

            break;
        }
        case '2':
        {
            system("powershell rm ./logs/*.log");
        }
        case '3':{

            fstream outfile2;
            outfile2.open("./config/config.txt");
            outfile2>>plik;
            outfile2.close();
            break;

        }
    }

    system("cls");
        ifstream file(plik);

    if (file.is_open())
    {
        system("cls");
        cout << "Wpisz ID/slowo/date:";
        string word;
        cin >> word;
        cout<<endl;
            ofstream Zapis("./logs/"+word+".log");
        string line;
        cout<<"Pls wait!"<<endl;

        while (!file.eof())
        {
            getline(file, line);
            size_t found = line.find(word);
            if (found != string::npos)

                Zapis<<line<<endl;
        }
        file.close();
        Zapis.close();
         }
    else{
        cout<<"Te majster zla nazwa pliku :C";
    }
}
