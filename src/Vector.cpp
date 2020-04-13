#include "Vector.hh"
#include <iostream>
#include <math.h>

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
        result[i] = coordinates[i] + vec2[i];
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
        result[i] = coordinates[i] - vec2[i];
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
        result += coordinates[i] * vec2[i];
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
        result[i] = coordinates[i] * arg;
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
        cerr << "[!] Cannot divide by zero." << endl;
        arg = 1;
    }

    for (int i = 0; i < SIZE; i++)
    {
        result[i] = coordinates[i] / arg;
    }

    return result;
}

/*!
 * Operator indeksowania wektora.
 * Argument:
 *      index - nr indeksu - 1.
 * Zwraca:
 *      wartosc danego indeksu wektora
 */
const double &Vector::operator[](int index) const
{
    if (index < 0 || index >= SIZE)
    {
        cerr << "Warning! Vector index out of range" << endl;
    }
    return coordinates[index];
}

/*!
 * Operator indeksowania wektora.
 * Argument:
 *      index - nr indeksu - 1.
 * Zwraca:
 *      wartosc danego indeksu wektora
 */
double &Vector::operator[](int index)
{
    return const_cast<double &>(const_cast<const Vector *>(this)->operator[](index));
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
    cout << "(";
    for (int i = 0; i < SIZE; i++)
    {
        stream << vec[i];
        if (i < SIZE - 1)
        {
            cout << ", ";
        }
    }
    stream << ")" << endl;

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
        stream >> vec[i];
        if (stream.fail())
        {
            stream.clear();
            stream.ignore(32767, '\n');
            cerr << "[!] Vector error." << endl;
            return stream;
        }
    }

    return stream;
}

/* 
 * Zwraca dlugosc wektora
 * Uwaga: 
 *      zeby to mialo sens SIZE nie moze byc wiekszy niz 3
 *      (chyba)
 *  */
double Vector::length() const
{
    return sqrt(*this * *this);
}