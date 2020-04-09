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
 *    wyswietla macierz oryginalna, nie transponowana 
 *    jak ta podana na wejsiu.
 */
ostream &operator<<(std::ostream &stream, const SystemOfLinearEquations &system)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << "| ";
        for (int j = 0; j < SIZE; j++)
        {
            cout << system.matrix[j][i] << " ";
        }
        cout << "||x" << i + 1 << "|";

        if (SIZE % 2 == 1)
        {
            if (i == SIZE / 2)
            {
                cout << " = "
                     << "| " << system.vector[i] << " |";
            }
            else
            {
                cout << "   "
                     << "| " << system.vector[i] << " |";
            }
        }
        else if ((i == SIZE / 2) || (i == SIZE / 2 - 1))
        {
            cout << " - "
                 << "| " << system.vector[i] << " |";
        }
        else
        {
            cout << "   "
                 << "| " << system.vector[i] << " |";
        }
        cout << endl;
    }

    return stream;
}

Vector SystemOfLinearEquations::solve() 
{
    SystemOfLinearEquations copy = *this;
    Matrix temp;
    double mainDeterminant = copy.matrix.determinant();

    for (int i = 0; i < SIZE; i++)
    {
        temp = copy.matrix;
        temp[i] = copy.vector;
        this->solution[i] = temp.determinant() / mainDeterminant;
    }
    return this->solution;
}


void SystemOfLinearEquations::showSolution() const
{
    for(int i=0;i<SIZE;i++){
        cout << "x" << i+1 << " = " << this->solution[i] << endl;
    }
}