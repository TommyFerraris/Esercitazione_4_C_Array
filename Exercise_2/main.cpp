#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp"
#include "iomanip"

using namespace std;


int main()
{
    string inputFileName = "./data.csv";
    double S = 0;
    size_t n = 0;
    double* w = nullptr;
    double* r = nullptr;
    double V = 0;

    if (!ImportVector(inputFileName, S, n, w, r))
    {
        cerr<< "Something goes wrong with import"<< endl;
        return -1;
    }
    else
        cout << "Valore di S: " << fixed << setprecision(2) << S << "; valore di n: " << n << "; w = " << ArrayToString(n, w) << "; r = " << ArrayToString(n, r) << endl;

    double dotProduct = DotProduct(n, w, r, V, S);
    cout <<fixed << setprecision(4) << "dot product: "<< dotProduct << "; V = " << setprecision(2) << V << endl;

    string outputFileName = "./result.txt";
    if (!ExportResult(outputFileName, n, w, r, dotProduct, S, V))
    {
        cerr<< "Something goes wrong with export"<< endl;
        return -1;
    }
    else
        cout<< "Export successful"<< endl;

    delete[] w;
    delete[] r;

    return 0;
}
