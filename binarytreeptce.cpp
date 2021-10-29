#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;
//template< size_t N >

int findTarget( int arr[], int target, int size){

int start = 0;
int end = size - 1;

    
while( start<=end){
int mid = start + (end -start)/2;
//cout <<  mid << endl;

    if(arr[mid] == target){
      //  cout <<  mid << endl;

        return mid;
    }

    else if(arr[mid]>target){
        end = mid -1;
    }

    else{
        start = mid+1;
    }


}


return -1;

}

int partition ( int arr[], int start, int end){

  int pivot = arr[end];
    int pIndex = start;

    for (int i = start; i < end; i++){

        if(arr[i]<= pivot){
            swap(arr[i],arr[pIndex]);
            pIndex++;
        }
    }

    swap(arr[pIndex],arr[end]);

    return pIndex;


}
void insertionSort(int arr[], int n)
{
    // start from the second element (the element at index 0
    // is already sorted)
    for (int i = 1; i < n; i++)
    {
        int value = arr[i];
        int j = i;
 
        // find index `j` within the sorted subset `arr[0…i-1]`
        // where element `arr[i]` belongs
        while (j > 0 && arr[j - 1] > value)
        {
            swap(arr[j],arr[j-1]);
            j--;
        }
     
        // note that the subarray `arr[j…i-1]` is shifted to
        // the right by one position, i.e., `arr[j+1…i]`
 
        //arr[j] = value;
    }
}

void quickSort (int arr[], int start, int end){

  if (start>=end){
      return;
  }

  int pivot = partition(arr, start, end);

  quickSort(arr, start, pivot -1);

  quickSort(arr, pivot + 1, end);



}

 void printArr (int arr[], int size){

     for (int i = 0; i< size; i++){
         cout << arr[i] << " ";
     }

     cout << endl;
 }

int main(){

    srand(time(NULL));
    int size = 0;
  

    cout<< "How many numbers would you like in the guessing game? " << endl;
    cin >> size;
    cout<< "Ok great! Will now generate " << size << " numbers..."<< endl;

  int firstArr[size];
    for (int i =0; i < size; i++){

            firstArr[i] = rand()%100 + 1;         
    }

    printArr(firstArr, size);
    insertionSort(firstArr,size);

    //quickSort(firstArr, 0 , size -1);

    printArr(firstArr,size);

string str = "";
do{
    cout <<"Great! Now then make your guess: "<< endl;

int target = 0;

cin >> target;

int indexMID = findTarget(firstArr,target,size);

if(indexMID== -1){

    cout << "Sorry that number was not in there"<< endl;
    cout <<  "Would you like to try another guess? yes or no"<< endl;
    cin >> str;
}
else{
    cout << "Nice! we found that number in the index: " <<indexMID << endl;
    cout <<  "Would you like to try another number? yes or no"<< endl;
    cin >> str;
}


}while (str== "yes");


system("PAUSE");
    return 0;
}

