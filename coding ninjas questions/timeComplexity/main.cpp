
#include <iostream>
#include <algorithm>
using namespace std;
//Find the Unique Element
//    7
//    2 3 1 6 3 6 2
//    1    (2^3^1^6^3^6^2) == 1 (which is unique element)
int FindUnique(int * arr, int size){
    int c=0;
    for(int i=0;i<size;i++){
         c=c^arr[i];
    }
    return c;
}

//Duplicate in array
//    9
//    0 7 2 5 4 7 1 3 6
//    7  (7^7 will be zero)
int MissingNumber(int arr[], int size){
    int c=0,i=0;
    for(i=0;i<size;i++){
        c=c^arr[i];
        if(c==0)
            break;
    }
    return arr[i];
}

//Print Array intersection
void intersection(int input1[], int input2[], int size1, int size2) {
    sort(input1, input1+size1);
    sort(input2, input2+size2);
    int i = 0;
    int j = 0;
    while(i<size1 && j<size2){
        if(input1[i] == input2[j]){
            cout<<input1[i]<<endl;
            i++;
            j++;
        }
        else if(input1[i] > input2[j])
            j++;
        else
            i++;
    }
    
}
//Pair sum in array (sum of two no.s in an array resuting in a given no.)

void pairSum(int input[], int size, int x) {
  
for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++) // for triple sum add another loop with k = j+1
        {
            if((input[i]+input[j])==x)
            {
                if(input[i]<input[j])
                {
                    cout<<input[i]<<" "<<input[j]<<endl;
                }
                else
                {
                     cout<<input[j]<<" "<<input[i]<<endl;
                }
            }
        }
    }
}

//Rotate array
//    7
//    1 2 3 4 5 6 7
//    2
//    3 4 5 6 7 1 2
void Rotate(int arr[], int d, int size) {
   
     int*a= new int[d];
    for(int i=0;i<d;i++){
        a[i]=arr[i];
    }
    for(int i=d;i<size;i++){
        arr[i-d]=arr[i];
    }
    int j=0;
    for(int i=size-d;i<size;i++){
        arr[i]=a[j++];
    }
   delete [] a;
}
//or 1 2 3 4 5 6 7
void Rotate2(int arr[], int d, int size) {
    reverse(arr, arr+size);                 //  7 6 5 4 3 2 1
    reverse(arr, arr+size-d);               //  3 4 5 6 7 2 1
    reverse(arr+size-d, arr+size);          //  3 4 5 6 7 1 2
}

//Check Array Rotation
//6
//5 6 1 2 3 4
//2
int FindSortedArrayRotation(int arr[], int n) {
    int *temp= new int [n];
    for(int i=0; i<n; i++)
        temp[i]=arr[i];
    Sort(temp,temp+n);

    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==temp[0])
            return count;
        else
            count++;
    }

}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
