#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>

void leer_datos_de(const std::string& filename, std::vector <double> & datos);
double media(std::vector <double> & datos);
double percentil(std::vector <double> &datos, double P);
double minimo(std::vector <double> & datos);
double maximo(std::vector <double> & datos);

int main(int argc, char** argv)
{
    std::vector <double> datos;
    std::string filename;
    filename = argv[1];

    leer_datos_de(filename, datos);
    size_t size = datos.size();
    double N = static_cast <double>(size); //volvemos a size un double

    std::cout << "Media: " << media(datos) << "\n" << "Mediana: " << percentil(datos, 50) << "\n" << "Percentil 25: " << percentil(datos, 25) << "\n" <<
            "Percentil 50: " << percentil(datos, 50) << "\n" << "Percentil 75: " << percentil(datos, 75) << "\n" << "Máximo; " << maximo(datos) << "\n" << 
            "Minimo: " << minimo(datos) << "\n";

    return 0;
}

void leer_datos_de(const std::string& filename, std::vector <double> & datos)
{
    std::ifstream fin(filename); //abre el archivo del que se van a leer los datos

    double x;
    while (fin >> x) {
        datos.push_back(x);
    }

    fin.close();
}

double media(std::vector <double> & datos)
{
    double N = datos.size();
    int suma = 0;
    for(int ii = 0; ii < N; ii = ii + 1){
        suma = suma + datos[ii];
    }

    return (suma/N);
}

double percentil(std::vector <double> &datos, double P)
{
    std::sort(datos.begin(), datos.end());

    double percentil = ((P/100) * datos.size());
    return percentil;
}

double minimo(std::vector <double> & datos)
{
    double minimo = datos[0];

    for(auto val : datos){
        if(val < minimo){
            minimo = val;
        }
    }
    return minimo;
}

double maximo(std::vector <double> & datos)
{
    double maximo = datos[0];

    for(auto val : datos){
        if(val > maximo){
            maximo = val;
        }
    }
    return maximo;
}
