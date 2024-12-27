#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double a[],int n,double b[]){
    double mean = 0,SD = 0,meanG = 1,hmean = 0,max = 0,min =0;
    for(int i = 0;i<n;i++){
        mean += a[i];
    }
    b[0] = mean/n;
    for(int i = 0;i<n;i++){
        SD += pow(a[i]-b[0],2);
    }
    b[1] = sqrt(SD/n);
    for(int i = 0;i<n;i++) meanG *= a[i];
    b[2] = pow(meanG,1.0/n);
    for(int i = 0;i<n;i++) hmean += 1.0/a[i];
    b[3] = n/(hmean);
    for(int i = 0;i<n;i++){
        if(i == 0) {min = a[i];max = a[i];}
        if(a[i] > max) max = a[i];
        if(a[i] < min) min = a[i];
    }
    b[4] = max;
    b[5] = min;
}
