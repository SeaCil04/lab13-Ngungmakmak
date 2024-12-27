#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void updateImage(bool image[][M],int a,int b,int c){
    if(a == 1){
        image[b][c] = 1;
    }else{
        for(int i = 0;i<N;i++){
            for(int j = 0;j<M;j++){
                if(sqrt(pow(i-b,2)+pow(j-c,2)) <= a-1){
                    image[i][j] = 1;
                }
            }
        }
    }
}

void showImage(const bool image[][M]){
    cout << "------------------------------------------------------------------------" << endl;
    for(int i = 0;i < N;i++){
        cout << "|";
        for(int j=0;j<M;j++){
            if(image[i][j] == 1){
                cout << "*";
            }else {
                cout <<" ";
            }
        }
        cout << "|";
        cout << endl;
    }
    cout << "------------------------------------------------------------------------"<<endl;
}

