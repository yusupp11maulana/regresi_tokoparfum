#include<iostream>
using namespace std;

int totaly(int y[], int n);
int totalx(int x[], int n);
int kuadratx(int x[], int n);
int kalixy(int x[], int y[], int n);
double konstanta(double x, double y, double xy, double x2, double n);
double koefisien(double x, double y, double xy, double x2, double n);

int main(){
    int n, i, sigma_x, sigma_y,sigma_xy, sigma_x2;
    double nilai;
    int x[] = {12, 14, 13, 12, 15, 13, 14, 15, 13, 14};
    int y[] = {56, 62, 60, 61, 65, 66, 60, 63, 65, 62};
    n = sizeof(x)/sizeof(x[0]);
    sigma_x = totalx(x, n);
    sigma_y = totaly(y, n);
    sigma_xy = kalixy(x, y, n);
    sigma_x2 = kuadratx(x, n);
    double konstantanya = konstanta(sigma_x, sigma_y, sigma_xy, sigma_x2, n);
    double koefisiennya = koefisien(sigma_x, sigma_y, sigma_xy, sigma_x2, n);
    cout << "Masukkan Biaya : ";
    cin >> nilai;
    double prediksi = konstantanya + koefisiennya * nilai;
    cout << "Maka Volume Penjualannya adalah " << prediksi;
}

int totalx(int x[], int n){
    int i;
    int total_x = 0;
    for (i = 0; i < n;i++){
        total_x = total_x + x[i];
    }
    return total_x;
}

int totaly(int y[], int n){
    int i;
    int total_y = 0;
    for (i = 0; i < n;i++){
        total_y = total_y + y[i];
    }
    return total_y;
}

int kalixy(int x[], int y[], int n){
    int i, jumlah;
    jumlah = 0;
    for (i = 0; i < n;i++){
        jumlah = jumlah + (x[i] * y[i]);
    }
    return jumlah;
}

int kuadratx(int x[], int n){
    int i, jumlah;
    jumlah = 0;
    for (i = 0; i < n;i++){
        jumlah = jumlah + (x[i] * x[i]);
    }
    return jumlah;
}

double konstanta(double x, double y, double xy, double x2, double n){
    double kons = ((y * x2) - (x * xy)) / ((n * x2) - (x * x));
    return kons;
}

double koefisien(double x, double y, double xy, double x2, double n){
    double koef = ( ( n * xy ) - ( x * y ) ) / ( ( n * x2 ) - ( x * x ) );
    return koef;
}