#include "Vector.hh"
#include <iostream>

using namespace std;

/*!
 * Realizuje dodawanie wektorow.
 * Argumenty:
 *    niejawny wskaznik na klase Vector - pierwszy skladnik dodawania,
 *    vec2 - drugi skladnik dodawania.
 * Zwraca:
 *    result - suma argumentow.
 */
Vector Vector::operator+(Vector vec2) const
{
    Vector result;

    for (int i = 0; i < SIZE; i++)
    {
        result.coordinates[i] = coordinates[i] + vec2.coordinates[i];
    }

    return result;
}


/*!
 * Realizuje odejmowanie wektorow.
 * Argumenty:
 *    niejawny wskaznik na klase Vector - pierwszy skladnik odejmowania,
 *    vec2 - drugi skladnik odejmowania.
 * Zwraca:
 *    result - roznica argumentow.
 */
Vector Vector::operator-(Vector vec2) const
{
    Vector result;

    for (int i = 0; i < SIZE; i++)
    {
        result.coordinates[i] = coordinates[i] - vec2.coordinates[i];
    }

    return result;
}


/*!
 * Realizuje mnozenie skalarne wektorow.
 * Argumenty:
 *    niejawny wskaznik na klase Vector - pierwszy skladnik mnozenia,
 *    vec2 - drugi skladnik mnozenia.
 * Zwraca:
 *    result - iloczyn skalarny wektorow.
 */
double Vector::operator*(Vector vec2) const
{
    double result = 0;

    for (int i = 0; i < SIZE; i++)
    {
        result += coordinates[i] * vec2.coordinates[i];
    }

    return result;
}


/*!
 * Realizuje mnozenie wektora przez liczbe.
 * Argumenty:
 *    niejawny wskaznik na klase Vector - pierwszy skladnik mnozenia,
 *    arg - drugi skladnik mnozenia.
 * Zwraca:
 *    result - wektor przemnozony przez wartosc arg.
 */
Vector Vector::operator*(double arg)
{
    Vector result;

    for (int i = 0; i < SIZE; i++)
    {
        result.coordinates[i] = coordinates[i] * arg;
    }

    return result;
}


/*!
 * Realizuje dzielenie wektora przez liczbe.
 * Argumenty:
 *    niejawny wskaznik na klase Vector - pierwszy skladnik dzielenia,
 *    arg - drugi skladnik dzielenia.
 * Zwraca:
 *    result - wektor podzielony przez wartosc arg.
 * Uwaga:
 *    w przypadku arg=0 zwraca wejsciowy wektor
 */
Vector Vector::operator/(double arg)
{
    Vector result;

    if (arg == 0.0)
    {
        cout << "[!] Dzielenie przez zero niedozwolone." << endl;
        arg = 1;
    }

    for (int i = 0; i < SIZE; i++)
    {
        result.coordinates[i] = coordinates[i] / arg;
    }

    return result;
}


/*!
 * Realizuje wyswietlnie wspolrzednych wektora na ekranie.
 * Argumenty:
 *    stream - output stream,
 *    vec - wektor.
 * Uwaga:
 *    wartosci wspolrzednych wektora (vec.coordinates[])
 *    moga byc tylko liczbami
 */
ostream &operator<<(ostream &stream, const Vector &vec)
{
    for (int i = 0; i < SIZE; i++)
    {
        stream << vec.coordinates[i] << " ";
    }
    stream << endl;

    return stream;
}


/*!
 * Realizuje wczytywanie wartosci wspolrzednych wektora
 * ze standardowego wejscia.
 * Argumenty:
 *    stream - input stream,
 *    vec - wektor.
 * Uwaga:
 *    wartosci wspolrzednych wektora (vec.coordinates[])
 *    moga byc tylko liczbami
 */
istream &operator>>(istream &stream, Vector &vec)
{
    for (int i = 0; i < SIZE; i++)
    {
        stream >> vec.coordinates[i];
        if (stream.fail())
        {
            stream.clear();
            stream.ignore(32767, '\n');
            cout << "Bledne dane wektora wyrazow wolnych" << endl;
            return stream;
        }
    }

    return stream;
}