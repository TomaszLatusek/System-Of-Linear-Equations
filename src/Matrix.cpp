#include "Matrix.hh"
#include <iostream>

using namespace std;

/*!
 * Operator indeksowania macierzy.
 * Argument:
 *      index - numer kolumny macierzy - 1
 * Zwraca:
 *      kolumne macierzy
 * Uwaga:
 *      aby dostac sie do [i][j]-ego elementu macierzy M
 *      nalezy uzyc M[i][j]. j-ty element i-tej kolumny 
 *      otrzymujemy dzieki operatorowi [] klasy Vector
 */
const Vector &Matrix::operator[](int index) const
{
    if (index < 0 || index >= SIZE)
    {
        cerr << "Warning! Matrix index out of range" << endl;
    }
    return data[index];
}

/*!
 * Operator indeksowania macierzy.
 * Argument:
 *      index - numer kolumny macierzy - 1
 * Zwraca:
 *      kolumne macierzy
 * Uwaga:
 *      aby dostac sie do [i][j]-ego elementu macierzy M
 *      nalezy uzyc M[i][j]. j-ty element i-tej kolumny 
 *      otrzymujemy dzieki operatorowi [] klasy Vector
 */
Vector &Matrix::operator[](int index)
{
    // return const_cast<Vector &>(const_cast<const Matrix *>(this)->operator[](index));
    if (index < 0 || index >= SIZE)
    {
        cerr << "Warning! Matrix index out of range" << endl;
    }
    return data[index];
}

/*!
 * Realizuje wyswietlnie macierzy na ekranie.
 * Argumenty:
 *    stream - output stream,
 *    matrix - macierz.
 * Uwaga:
 *    wyswietla macierz oryginalna, nie transponowana 
 *    jak ta podana na wejsiu.
 */
ostream &operator<<(ostream &stream, const Matrix &matrix)
{
    stream << "Matrix A:" << endl;

    for (int j = 0; j < SIZE; j++)
    {
        stream << "     ";
        for (int i = 0; i < SIZE; i++)
        {
            stream << matrix[i][j] << " ";
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
 *    na wejscie nalezy podac postac transponowana macierzy
 */
istream &operator>>(istream &stream, Matrix &matrix)
{
    for (int i = 0; i < SIZE; i++)
    {
        stream >> matrix[i];
    }
    return stream;
}

double Matrix::determinant() const
{
    Matrix copy = *this;

    double temp1, temp2; //pomocnicze
    double det = 1;      //wyznacznik
    int i, j;

    /* Zamiana kolumn w przypadku,
     * gdy pierwszy element jest zerem */
    if (copy[0][0] == 0)
    {
        for (i = 0; i < SIZE; i++)
        {
            if (copy[i][0] != 0)
            {
                det *= -1;
                for (j = 0; j < SIZE; j++)
                {
                    temp1 = copy[i][j];
                    temp2 = copy[0][j];
                    copy[0][j] = temp1;
                    copy[i][j] = temp2;
                }
            }
        }
    }
    /* Wlasciwa eliminacja */
    for (i = j = 0; i < SIZE - 1 && j < SIZE - 1; i++, j++)
    {
        for (int m = i + 1; m < SIZE; m++)
        {
            for (int n = SIZE - 1; n >= j; n--)
            {
                copy[m][n] -= (copy[m][j] / copy[i][j] * copy[i][n]);
            }
        }
    }
    /* Obliczzenie wyznacznika */
    for (i = j = 0; i < SIZE && j < SIZE; i++, j++)
    {
        det *= copy[i][j];
    }

    return det;
}


