/* Realizado por Sergio Díaz 
1. Obtener los valores usados en las ecuaciones de m y b
2. Calcular m y b, con sus errores
3. Imprimir los errores
*/
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

void leer_datos_de(const std::string& filename, std::vector <double> & datosx, std::vector <double> & datosy);
double suma_x(const std::vector <double> & datosx, const std::vector <double> & datosy);
double suma_y(const std::vector <double> & datosx, const std::vector <double> & datosy);
double suma_xx(const std::vector <double> & datosx, const std::vector <double> & datosy);
double suma_yy(const std::vector <double> & datosx, const std::vector <double> & datosy);
double suma_xy(const std::vector <double> & datosx, const std::vector <double> & datosy);

int main(int argc, char** argv)
{
    std::vector <double> datosx;
    std::vector <double> datosy;
    std::string filename;
    filename = argv[1];

    leer_datos_de(filename, datosx, datosy);
    size_t size = std::min(datosx.size(), datosy.size());
    double e = (1.602176634 * 10e-19); // Valores constantes
    double h = (6.62607015 * 10e-34);
    double N = static_cast <double>(size);
    double Ex = suma_x(datosx, datosy);
    double Ey = suma_y(datosx, datosy);
    double Exx = suma_xx(datosx, datosy);
    double Eyy = suma_yy(datosx, datosy);
    double Exy = suma_xy(datosx, datosy);

    //Las siguientes variables son las solicitadas en el problema 

    double d = (1/(Exx - std::pow(Ex, 2)));
    double m = d * (Exy - (Ex*Ey));
    double b = d * ((Exx*Ey) - (Ex*Exy));
    double s2 = (N/(N-2))*(Eyy - (std::pow(Ey, 2)) - (std::pow(m, 2)*(Exx - std::pow(Ex, 2))));

    double delta_m = std::sqrt(d * (s2/N));
    double delta_b = std::sqrt((std::pow(delta_m, 2)) * Exx);

    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);
    std::cout << "Pendiente: " << m << "\n" << "Punto de corte: " << b << "\n" << "Delta m: " << delta_m << "\n" << "Delta b: " << delta_b << "\n" << "Valor de h: " << m*e << "\n"
        << "Error del valor de h: " << std::fabs(1 - (h/(m*e))) << "\n" << "Valor de phi: " << -b << "\n";

    return 0;
}


void leer_datos_de(const std::string& filename, std::vector <double> & datosx, std::vector <double> & datosy)
{
    std::ifstream fin(filename); //abre el archivo del que se van a leer los datos

    double x, y;
    while (fin >> x >> y) {
        datosx.push_back(x);
        datosy.push_back(y);
    }

    fin.close();
}

    //Las siguientes funciones son las que nos arrojarán Ex, Ey, Exx, Eyy, Exy necesarias para construir la regresión lineal de los datos

double suma_x(const std::vector <double> & datosx, const std::vector <double> & datosy)
{
    double suma = 0.0;
    size_t size = std::min(datosx.size(), datosy.size());
    double N = static_cast <double>(size);

    for(double val : datosx){
        suma = suma + val;
    }
    double Ex = (suma/N);
    return Ex;
}

double suma_y(const std::vector <double> & datosx, const std::vector <double> & datosy)
{
    double suma = 0.0;
    size_t size = std::min(datosx.size(), datosy.size());
    double N = static_cast <double>(size);

    for (double val : datosy) {
        suma = suma + val;
    }
    double Ey = (suma/N);
    return Ey;
}

double suma_xx(const std::vector <double> & datosx, const std::vector <double> & datosy)
{
    double suma = 0.0;
    size_t size = std::min(datosx.size(), datosy.size());
    double N = static_cast <double>(size);

    for(size_t i = 0; i < size; i = i + 1)
    {
        suma = suma + (datosx[i] * datosx[i]);
    }

    double Exx = suma/N;
    return Exx;
}

double suma_yy(const std::vector <double> & datosx, const std::vector <double> & datosy)
{
    double suma = 0.0;
    size_t size = std::min(datosx.size(), datosy.size());
    double N = static_cast <double>(size);

    for(size_t i = 0; i < size; i = i + 1)
    {
        suma = suma + (datosy[i] * datosy[i]);
    }

    double Eyy = suma/N;
    return Eyy;
}

double suma_xy(const std::vector <double> & datosx, const std::vector <double> & datosy)
{
    double suma = 0.0;
    size_t size = std::min(datosx.size(), datosy.size());
    double N = static_cast <double>(size);

    for(size_t i = 0; i < size; i = i + 1)
    {
        suma = suma + (datosx[i] * datosy[i]);
    }

    double Exy = suma/N;
    return Exy;
}