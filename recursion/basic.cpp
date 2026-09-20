#include <iostream>
using namespace std;

// Function to print numbers from n to 1 using recursion

void printNums(int n){
    if ( n == 1 ){
        cout << "1\n";
        return;
    };
    cout << n << " ";
    printNums(n-1);
};

int factorial( int n ) {
    if ( n == 0 ) {
        return 1;
    };
    return n * factorial(n-1);
};

int sum(int n) {
    if ( n == 0 ){
        return 0 ;
    };
    return n + sum(n-1);
};

int fun(int n) {
    if (n == 1)
        return 1;

    return n * fun(n - 1);
};

int fab(int n){
    if ( n == 0 || n == 1 ){
        return n;
    };
    return fab(n-1) + fab(n-2);
};

int check() {
    int arr[5] = {1,2,3,3,0};
    int n = sizeof(arr)/sizeof(arr[0]);
        cout << "n : "<< n <<endl;
        bool sorted = true;
        for (int i = 0 ; i < n ; i++){
            for (int j = i ; j < n ; j++){
                if ( arr[i] > arr[j])
                sorted = false;
            };
        };
        return sorted;
    };

int main()
{   
    
    // printNums(10);
    // cout << factorial(1) << endl;
    // cout << sum(10) << endl;
    // cout << fun(5) << endl;
    //cout << fab(3) << endl;
    cout << check();
    return 0;
}