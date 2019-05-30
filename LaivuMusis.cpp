#include "LaivuMusis.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

using namespace std;


LaivuMusis::LaivuMusis()
{
    LaivaiKompiuterio = 9;
    LaivaiZmogaus = 9;
}

LaivuMusis::LaivuMusis(int cpu, int man)
{
    LaivaiKompiuterio=cpu;
    LaivaiZmogaus=man;
}

LaivuMusis::~LaivuMusis()
{

}

void LaivuMusis::pradzia()
{
    for(int i=0; i<stulpeliai; i++)
    {
        for(int j=0; j<eilutes; j++)
        {
            TableMan[j][i]='O';
        }
    }

    for(int i=0; i<stulpeliai; i++)
    {
        for(int j=0; j<eilutes; j++)
        {
            TableComputer[j][i]='O';
            NewTableComputer[j][i]='O';
        }
    }
}

void LaivuMusis::spam(int x)
{
    srand(time(NULL));
    for(int i=0; i<x; i++)
    {
        int x = rand() %9+0;
        int y = rand() %9+0;

        if(TableMan[x][y]=='1')
        {
            while(TableMan[x][y]=='1')
            {
                x = rand() %9+0;
                y = rand() %9+0;
            }
            TableMan[x][y]='1';
        }
        else
            TableMan[x][y]='1';
    }

    for(int i=0; i<20; i++)
    {
        int x = rand() %9+0;
        int y = rand() %9+0;

        if(TableComputer[x][y]=='1')
        {
            while(TableComputer[x][y]=='1')
            {
                x = rand() %9+0;
                y = rand() %9+0;
            }
            TableComputer[x][y]='1';
        }
        else
            TableComputer[x][y]='1';
    }

}

void LaivuMusis::Saudymas()
{
    cout << " " << endl;
    cout << "Iveskite x ir y pozicijas:" << endl;
    cin >> xpoz >> ypoz;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "Blogas ivedimas, iveskite skaicius ";
        cin >> xpoz >> ypoz;
    }

    if (xpoz > eilutes || xpoz < 0)
    {
        while (true)
        {
            cout << "Bloga koordinate x, bandykite dar karta: ";
            cin >> xpoz;
            if (xpoz <= eilutes && xpoz >= 0)
            {
                break;
            }
        }
    }

    if (ypoz > eilutes || ypoz < 0)
    {
        while (true)
        {
            cout << "Bloga koordinate y, bandykite dar karta: ";
            cin >> ypoz;
            if (ypoz <= eilutes && ypoz >= 0)
            {
                break;
            }
        }
    }

    bool vienodi=true;

    if(TableComputer[xpoz][ypoz]!='X' && TableComputer[xpoz][ypoz]!='N')
    {
        if(TableComputer[xpoz][ypoz]=='1')
        {
            TableComputer[xpoz][ypoz]='X';
            NewTableComputer[xpoz][ypoz]='X';
            LaivaiKompiuterio--;
        }
        else
        {
            TableComputer[xpoz][ypoz]='N';
            NewTableComputer[xpoz][ypoz]='N';
        }
    }
    else
        while(vienodi)
        {
            cout << "Cia jau sauta" << endl;
            cout << "Iveskite x ir y pozicijas:" << endl;
            cin >> xpoz >> ypoz;

            if(TableComputer[xpoz][ypoz]!='X' && TableComputer[xpoz][ypoz]!='N')
            {
                vienodi=false;
                if(TableComputer[xpoz][ypoz]=='1')
                {
                    TableComputer[xpoz][ypoz]='X';
                    NewTableComputer[xpoz][ypoz]='X';
                    LaivaiKompiuterio--;
                }
                else
                    TableComputer[xpoz][ypoz]='N';
                NewTableComputer[xpoz][ypoz]='N';
            }
        }

    system("CLS");
}

void LaivuMusis::SaudymasComputer()
{
    srand(time(NULL));
    bool vienodi=true;
    int xp = rand() %9+0;
    int yp = rand() %9+0;

    if(TableMan[xp][yp]!='X' && TableMan[xp][yp]!='N')
    {
        if(TableMan[xp][yp]=='1')
        {
            TableMan[xp][yp]='X';
            LaivaiZmogaus--;
        }
        else
            TableMan[xp][yp]='N';
    }
    else
        while(vienodi)
        {
            xp = rand() %9+0;
            yp = rand() %9+0;

            if(TableMan[xp][yp]!='X' && TableMan[xp][yp]!='N')
            {
                vienodi=false;
                if(TableMan[xp][yp]=='1')
                {
                    TableMan[xp][yp]='X';
                    LaivaiZmogaus--;
                }
                else
                    TableMan[xp][yp]='N';
            }
        }

    system("CLS");
}

int LaivuMusis::GetLaivaiZmogaus()
{
    return LaivaiZmogaus;
}

int LaivuMusis::GetLaivaiComputer()
{
    return LaivaiKompiuterio;
}

void LaivuMusis::Spausdinti()
{
    cout << "       Tavo lenta" << endl;
    cout << "      Turi laivu " << LaivaiZmogaus << endl;
    cout << "   0 1 2 3 4 5 6 7 8 9" << endl;
    cout << "  --------------------" << endl;
    for(int i=0; i<stulpeliai; i++)
    {
        cout << i << "| ";
        for(int j=0; j<eilutes; j++)
        {
            cout <<TableMan[j][i] << " ";
        }
        cout << endl;
    }

    cout << "  " << endl;
    cout << "       CPU lenta" << endl;
    cout << "      Cpu laivai " << LaivaiKompiuterio << endl;
    cout << "   0 1 2 3 4 5 6 7 8 9" << endl;
    cout << "  --------------------" << endl;
    for(int i=0; i<stulpeliai; i++)
    {
        cout << i << "| ";
        for(int j=0; j<eilutes; j++)
        {
            cout <<NewTableComputer[j][i] << " ";
        }
        cout << endl;
    }

}






