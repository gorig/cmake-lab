#include <my-math.h>
#include <math.h>

static const double MM_PI = 3.14159265358979323846;      // pi
static const double MM_2PI = 6.28318530717958647692;     // 2*pi
static const double MM_PI_2 = 1.57079632679489661923;    // pi/2

static const double EPS = 0.0001;         //Pozadovana presnost vypoctu
static const int MAX_ITERATION = 100000;  //Pocet iteraci pred nasilnym ukoncenim cyklu
static const double MIN_SIN = -1e15;      //Maximalni hodnota pro vypocet sinu
static const double MAX_SIN = 1e15;       //Maximalni hodnota pro vypocet sinu

/**
 * Funkce pro vypocet sinu pomoci vycisleni Taylorovy rady.
 * Jako parametr slouzi uhel v radianech a pozadovana presnost.
 * Pokud by melo dojit k zacykleni, funkce ukonci vypocet a vrati
 * v dany okamzik vycislenou hodnotu.
 * @param value Uhel v radianech, pro ktery se ma vypocitat sinus.
 * @return      Vypocitany sinus daneho uhlu
 */
double fsin(double value)
{
    //Sin(0) = 0
    if(value == 0.0f) return 0.0f;

    //Velmi nizke a vysoke hodnoty jsou jiz prilis nepresne, proto vraci nan
    if(value < MIN_SIN || value > MAX_SIN) return NAN;

    //Cislo musi byt v rozsahu (0,2PI)
    value = fmod(value, MM_2PI);

    //Sinus nejrychleji konverguje v 1. kvadrantu
    //proto vsechny hodnoty prevedeme do tohoto kvadrantu
    int prevod =  0;

    if(value >= 3*MM_PI_2)
    {
        prevod = 1;
        value = MM_2PI-value;
    }
    else if(value >= MM_PI)
    {
        prevod = 1;
        value = value-MM_PI;
    }
    else if(value >= MM_PI_2)
    {
        value = MM_PI-value;
    }

    double part = value;
    double result = part;
    int k = 1;
    //Pro usetreni casu vypoctu vypocitame 2. mocninu cisla pred cyklem
    double dvalue = value*value;

    //Samotny iteracni vypocet sinu pomoci vycisleni Taylorovy rady
    while(fabs(part) >= EPS*fabs(result))
    {
        k+=2;
        part = -part*(dvalue)/(k*(k-1));
        result = result+part;

        //Vypocet bude ukoncen po probehnuti 100000 iteraci.
        //Tento pocet je natolik vysoky, ze je jiz temer jiste,
        //ze se vypocet zacyklil.
        if(k > 2*MAX_ITERATION) break;
    }

    //Pokud jsme prevadeli v kvadrantech, musime provest zmenu znamenka
    //ve 3. a 4. kvadrantu.
    if(prevod == 1)
    {
        result = -result;
    }

    return result;
}
