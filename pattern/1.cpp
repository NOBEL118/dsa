// lvl 1 , Basic square

#include <iostream>
using namespace std;

void square(int n){
    for ( int i = 0 ; i< n ; i++){
        for (int j = 0 ; j<n ; j++){
            cout << "*" << " ";
        }
        cout<< "\n" ;
    }
}

void triangle (int n){
    for(int i = 0 ; i < n ;i++){
        for (int j = 0 ; j <= i ; j++){
            cout<< "*" << " ";
        }
        cout<< "\n" ;
    }
}

void reverse_triangle (int n){
    for( int i = 0 ; i<n ; i++){
        for (int j = i ; j < n-i ; j++){
            cout<< j+1 << " ";
        }
        cout<< "\n" ;
    }
}

void reverse_number_triangle(int n) {
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n - i; j++) {
            cout << j + 1 << " ";
        }

        cout << "\n";
    }
}

int main(){
    reverse_number_triangle(5);
}