#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <cmath>

void histogram(int N, int seed, double a, double b, double Xmin, double Xmax, int Ncajas);

int main(int argc, char** argv)
{
    int N = std::stoi(argv[1]); //Tamaño del vector, cantidad de numeros a generar
    int seed = std::stoi(argv[2]); //semilla
    double a = std::stod(argv[3]); //parametro 1 weibull
    double b = std::stod(argv[4]); //parametro 2 weibull
    double Xmin = std::stod(argv[5]);
    double Xmax = std::stod(argv[6]);
    int Ncajas = std::stoi(argv[7]);

    histogram(N, seed, a , b, Xmin, Xmax, Ncajas);
    return 0;
}


void histogram(int N, int seed, double a, double b, double Xmin, double Xmax, int Ncajas)
{
    std::mt19937 gen(seed);
    std::weibull_distribution<> weibull_dis(a, b);

    std::vector <double> histo(Ncajas);
    double dx = (Xmax - Xmin)/Ncajas;

    for(int ii = 0; ii < N; ii = ii + 1){
        
        double r = weibull_dis(gen);  //genera aleatorio

        if(r > Xmax) continue;
        int bin = int((r - Xmin)/dx);  //elige la caja a la que pertenece, bin es numero de la caja
        histo[bin] = histo[bin] + 1;  //contar cuantos caen en cada caja
    }

    //Imprimir histograma
    std::ofstream fout("histo.txt");

    for(int ii = 0; ii < Ncajas; ii = ii + 1){
        double x = Xmin + (ii * dx);
        fout << x << "\t" << histo[ii]/(dx * N) << "\n";
    }

    fout.close();
}