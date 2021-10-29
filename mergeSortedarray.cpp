#include <vector>
#include <iostream>


using namespace std;

 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
   if (m==0){
       nums1.clear();    
   }
   else if(nums1.size()!= m){
       int diff = nums1.size()-m;
       while(diff !=0){
        nums1.pop_back();
        diff--;
       }
   }

   if (n==0){
     nums2.clear();    

   }   

    else if(nums2.size()!= n){
       int diff = nums2.size()-n;
       while(diff >=0){
        nums2.pop_back();
        diff--;
       }
   }

        for(int i = 0; i<nums2.size(); i++){
            nums1.push_back(nums2[i]);

            int value = nums1[nums1.size()-1];
            int j = nums1.size()-1;

            while(j>0&& nums1[j-1]>value){
                
                swap(nums1[j],nums1[j-1]);
                j--;
            }
       
        }


    }

  void printVector(vector<int> arr, int size){

     for (int i = 0; i< size; i++){
         cout << arr[i] << " ";
     }

     cout << endl;
 } 

    int main (){
        
        vector<int> arr1 = {1,2,3,0,0,0};
        vector<int> arr2 = {2,5,6};

        merge(arr1,3,arr2, 3);

        printVector(arr1, arr1.size());

system("PAUSE");

return 0;


    }