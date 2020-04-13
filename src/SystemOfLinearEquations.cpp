#include <iomanip>
#include "SystemOfLinearEquations.hh"

using namespace std;

/*!
 * Realizuje wczytywanie macierzy i wektora wyrazow wolnych
 * ze standardowego wejscia.
 * Argumenty:
 *    stream - input stream,
 *    system - uklad rownan.
 * Uwaga:
 *    na wejscie nalezy podac postac transponowana macierzy
 *    z wektorem wyrazow wolnych 
 */
istream &operator>>(istream &stream, SystemOfLinearEquations &system)
{
    stream >> system.matrix;
    stream >> system.vector;

    return stream;
}

/*!
 * Realizuje wyswietlnie ukladu rownan na ekranie.
 * Argumenty:
 *    stream - output stream,
 *    system - uklad rownan.
 * Uwaga:
 *    -wyswietla macierz oryginalna, nie transponowana 
 *     jak ta podana na wejsiu,
 *    -zeby macierz zostala wyswietlona ladnie i prosto
 *     jej wyrazy powinny skladac sie z nie wiecej niz 4 znakow.
 *      
 * 
 * (kod dosc brzydki ale pierwszy raz bawie sie z formatowaniem
 * outputu, prosze o wyrozumialosc)
 */
ostream &operator<<(std::ostream &stream, const SystemOfLinearEquations &system)
{
    // cout << fixed << setprecision(0) << setfill(' ');

    for (int i = 0; i < SIZE; i++)
    {
        cout << "|";
        for (int j = 0; j < SIZE; j++)
        {
            cout << setw(4) << system.matrix(i, j) << " ";
        }
        cout << "||x" << i + 1 << "|";
        if (SIZE % 2 == 1)
        {
            if (i == SIZE / 2)
            {
                cout << " = "
                     << "|" << setw(4) << system.vector[i] << " |";
            }
            else
            {
                cout << "   "
                     << "|" << setw(4) << system.vector[i] << " |";
            }
        }
        else if ((i == SIZE / 2) || (i == SIZE / 2 - 1))
        {
            cout << " - "
                 << "|" << setw(4) << system.vector[i] << " |";
        }
        else
        {
            cout << "   "
                 << "|" << setw(4) << system.vector[i] << " |";
        }
        cout << endl;
    }

    return stream;
}

/*!
 * Realizuje rozwiazywanie ukladu rownan
 * Argumenty:
 *    w domysle uklad rownan
 * Uwaga:
 *    jezeli wyznacznik macierzy glownej jest rowny 0,
 *    program nie jest w stanie wyliczyc ukladu,
 *    bo bazuje na metodzie Cramera
 */
Vector SystemOfLinearEquations::solve()
{
    SystemOfLinearEquations copy = *this;
    Matrix temp;
    double mainDeterminant = copy.matrix.determinant();

    if (mainDeterminant == 0)
    {
        cerr << "[!] Determinant = 0. Cannot solve the system." << endl;
    }

    for (int i = 0; i < SIZE; i++)
    {
        temp = copy.matrix;
        temp[i] = copy.vector;
        this->solution[i] = temp.determinant() / mainDeterminant;
    }
    return this->solution;
}

/* Wyswietla rozwiazania ukladu rownan */
void SystemOfLinearEquations::showSolution() const
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << "x" << i + 1 << " = " << this->solution[i] << endl;
    }
}

/* 
 * Realizuje obliczenie wektora bledu
 *  */
void SystemOfLinearEquations::countErrorVector()
{
    this->error = this->matrix * this->solution - this->vector;
}


/* 
 * Wyswietla oraz interpretuje wektor bledu
 *  */
void SystemOfLinearEquations::showErrorVector() const
{
    
    cout << "Error vector: " << this->error;
    cout << "Error vector length: " << this->error.length() << endl;

    if (this->error.length() > 0.00001)
    {
        cerr << "[!] Error may be significant." << endl;
    }
}
