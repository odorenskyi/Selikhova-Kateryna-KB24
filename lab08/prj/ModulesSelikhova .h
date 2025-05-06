#ifndef MODULESSELIKHOVA_H_INCLUDED
#define MODULESSELIKHOVA_H_INCLUDED

struct Temperature {
    double celsius;
    double fahrenheit;
};


double s_calculation(double x, double y, double z);
double calculateElectricityBill(double kWh);
Temperature calculateAverageTemperature(const double temps[12]);
int countBits(int N);


#endif // MODULESSELIKHOVA_H_INCLUDED
