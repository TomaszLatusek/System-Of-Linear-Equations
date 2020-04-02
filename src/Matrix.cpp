#include "Matrix.hh"
#include <iostream>

using namespace std;



/*!
 * Realizuje wyswietlnie macierzy na ekranie.
 * Argumenty:
 *    stream - output stream,
 *    matrix - macierz.
 */
ostream &operator<<(ostream &stream, const Matrix &matrix)
{
    stream << "Macierz A:" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        stream << "     ";
        for (int j = 0; j < SIZE; j++)
        {
            stream << matrix.data[i][j] << " ";
        }
        stream << endl;
    }

    return stream;
}


/*!
 * Realizuje wczytywanie wartosci wyrazow macierzy
 * ze standardowego wejscia.
 * Argumenty:
 *    stream - input stream,
 *    matrix - macierz.
 * Uwaga:
 *    wartosci wyrazow macierzy (matrix.data[][])
 *    moga byc tylko liczbami
 */
istream &operator>>(istream &stream, Matrix &matrix)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            stream >> matrix.data[i][j];
            if (stream.fail())
            {
                stream.clear();
                stream.ignore(32767, '\n');
                cout << "Bledne dane macierzy" << endl;
                return stream;
            }
        }
    }
    return stream;
}