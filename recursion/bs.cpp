#include <iostream>
using namespace std;

int check(int start, int end , int mid){
    int arr[5] = {1,2,3,4,5};
    int size = 5;
    int target = 4;

    if (arr[mid] == target){
        return mid;
    };

    if (arr[mid] > target){
        return check(start, mid-1 , (start + mid - 1)/2);
    };
    
    return check(mid+1 , end , (mid + 1 + end)/2);
};

int main()
{
    cout <<check(0, 4, 2);
    return 0;
}