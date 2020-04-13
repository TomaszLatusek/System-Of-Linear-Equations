#include "Matrix.hh"
#include <iostream>

using namespace std;

/*!
 * Operator indeksowania macierzy.
 * Argumenty:
 *      row - nr wiersza - 1,
 *      column - nr kolumn - 1.
 * Zwraca:
 *      wartosc danego wyrazu macierzy
 */
const double &Matrix::operator()(int row, int column) const
{
    if (row < 0 || row >= SIZE || column < 0 || column >= SIZE)
    {
        cerr << "Warning! Matrix index out of range" << endl;
    }
    return data[column][row];
}

/*!
 * Operator indeksowania macierzy.
 * Argumenty:
 *      row - nr wiersza - 1,
 *      column - nr kolumn - 1.
 * Zwraca:
 *      wartosc danego wyrazu macierzy
 */
double &Matrix::operator()(int row, int column)
{
    return const_cast<double &>(const_cast<const Matrix *>(this)->operator()(row, column));
}

/*!
 * Operator indeksowania kolumn macierzy.
 * Argumenty:
 *      index - nr kolumny -1.
 * Zwraca:
 *      wektor kolumny macierzy
 */
Vector &Matrix::operator[](int index)
{
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

    for (int i = 0; i < SIZE; i++)
    {
        stream << "     ";
        for (int j = 0; j < SIZE; j++)
        {
            stream << matrix(i, j) << " ";
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
        stream >> matrix.data[i];
    }
    return stream;
}

/*!
 * Realizuje obliczanie wyznacznika macierzy.
 * Argumenty:
 *    w domysle macierz
 * Zwraca:
 *    wyznacznik macierzy
 */
double Matrix::determinant() const
{
    Matrix copy = *this;

    double temp1, temp2; //pomocnicze
    double det = 1;      //wyznacznik
    int i, j;

    /* Zamiana wierszy w przypadku,
     * gdy pierwszy element jest zerem */
    if (copy(0, 0) == 0)
    {
        for (i = 0; i < SIZE; i++)
        {
            if (copy(i, 0) != 0)
            {
                det *= -1;
                for (j = 0; j < SIZE; j++)
                {
                    temp1 = copy(i, j);
                    temp2 = copy(0, j);
                    copy(0, j) = temp1;
                    copy(i, j) = temp2;
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
                copy(m, n) -= (copy(m, j) / copy(i, j) * copy(i, n));
            }
        }
    }

    /* Obliczzenie wyznacznika */
    for (i = j = 0; i < SIZE && j < SIZE; i++, j++)
    {
        det *= copy(i, j);
    }

    return det;
}


/*!
 * Realizuje mnozenie macierzy przez wektor.
 * Argumenty:
 *    niejawny wskaznik na klase Matrix - pierwszy skladnik mnozenia,
 *    vec - wektor, drugi skladnik mnozenia.
 * Zwraca:
 *    result - wektor wynikowy.
 */
Vector Matrix::operator*(Vector vec) const
{
    Vector result;

    for (int i = 0; i < SIZE; i++)
    {
        result[i] = 0;
        for (int j = 0; j < SIZE; j++)
        {
            result[i] += this->operator()(i, j) * vec[j];
        }
    }

    return result;
}