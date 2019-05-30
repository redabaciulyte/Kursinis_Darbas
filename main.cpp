#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "LaivuMusis.h"
#include <Windows.h>

using namespace std;


int main()
{
    int cpu, zm, x;
    int cpulaivai;
    int zmlaivai;

    int LaivaiKompiuterio;
    int LaivaiZmogaus;

    cout << "                                    SVEIKI ATVYKE I GERIAUSIA PASAULYJE ZAIDIMA" << endl;
    cout << "\n";
    cout << "\n";
    cout << "                                      IVESKITE NORIMA LAIVU SKAICIU ( max20 ):";
    cin >> x;
    if (x > 20 || x <=0){
        x = 10;
    }
    cpu = x;
    zm = x;

    system("CLS");

    LaivuMusis laivai(cpu, zm);

    laivai.pradzia();

    laivai.spam(x);
    bool pabaiga=true;
    while(pabaiga)
    {
        laivai.Spausdinti();
        laivai.Saudymas();
        laivai.SaudymasComputer();
        LaivaiKompiuterio=laivai.GetLaivaiComputer();
        LaivaiZmogaus=laivai.GetLaivaiZmogaus();
        if(LaivaiKompiuterio==0 || LaivaiZmogaus==0)
            pabaiga=false;
    }
    if(LaivaiKompiuterio==0)
    {
        cout << "Laimejo Kompiuteris" << endl;
    }
    else
        cout << "Laimejai!" << endl;

}
