#include <iostream>
#include <vector>



std::vector<int>& selectSort(std::vector<int> &arr,int beg,int end){

    int minIndex = beg;
    for(int i=0;i<end;i++){
        int min = arr[i];
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<=min){
                minIndex = j;
                min = arr[j];
            }
        }
        arr[minIndex] = arr[i];
        arr[i] = min;
    }
    return arr;
}



int main()
{
    std::vector<int> arr = {2,1,4,3,8,5,9,6,10,7};
    std::cout<<"before select sort:";
    for(auto e: arr)
        std::cout<<e<<" ";
    selectSort(arr,0,arr.size()-1);
    std::cout<<"\nafter select sort:";
    for(auto e: arr)
        std::cout<<e<<" ";
    std::cout<<std::endl;
    return 0;
}