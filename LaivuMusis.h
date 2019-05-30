#pragma once

class LaivuMusis
{
public:
    LaivuMusis();
    LaivuMusis(int cpu, int man);
    ~LaivuMusis();
    void pradzia();
    void spam(int x);
    void Saudymas();
    void SaudymasComputer();
    int GetLaivaiZmogaus();
    int GetLaivaiComputer();
    void Spausdinti();

private:
    int const eilutes = 10;
    int const stulpeliai = 10;
    char TableMan[11][11];
    char TableComputer[11][11];
    char NewTableComputer[11][11];
    int LaivaiKompiuterio;
    int LaivaiZmogaus;
    int xpoz, ypoz;
};

