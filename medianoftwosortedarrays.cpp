#include <iostream>
#include <vector>

    std::vector<int> findMedianSortedArrays(std::vector<int>& nums1,std::vector<int>& nums2) {
        std::vector<int> arrays;
            int size = nums1.size()+ nums2.size();
        
        for (int i = 0; i < size; i++){
            std::cout<< nums1[0]<< "\n";
            std::cout<< nums2[0]<< "\n";

            if(nums1.empty()){
                arrays.push_back(nums2[0]);
                nums2.erase(nums2.begin());
            }
            else if(nums2.empty()){
                arrays.push_back(nums1[0]);
                nums1.erase(nums1.begin());
            }
            else if(nums1[0]<= nums2[0]){
                arrays.push_back(nums1[0]);
                nums1.erase(nums1.begin());
            }
            else{
                arrays.push_back(nums2[0]);
                nums2.erase(nums2.begin());
            }
        }

        return arrays;
    }

void printVector(std::vector<int> v) {
  std::cout << "Vector: "; 
  for(auto it = v.begin(); it!= v.end(); ++it){//unsigned int i = 0; i < v.size(); i++) {
    std::cout << *it << ",";
  }
  std::cout << "\n";
} 

int main()
{

std::vector<int> array1 {1,2};
std::vector<int> array2 {0};


printVector(findMedianSortedArrays(array1, array2));

}