#include <iostream>
#include <vector>
using namespace std;

void insertSort(vector<int>& nums,int beg,int end){

    if(end-beg<1)
        return;
    for(int i=beg;i<=end;i++){
        int preIndex = i+1;
        int current = nums[preIndex];
        while(preIndex>0&&current<nums[preIndex-1]){
            nums[preIndex] = nums[preIndex-1];
            preIndex--;
        }
        nums[preIndex] = current;

    }
}

int main()
{
    std::vector<int> arr = {2,1,4,3,8,5,9,6,10,7};
    std::cout<<"before select sort:";
    for(auto e: arr)
        std::cout<<e<<" ";
    insertSort(arr,0,arr.size()-1);
    std::cout<<"\nafter select sort:";
    for(auto e: arr)
        std::cout<<e<<" ";
    std::cout<<std::endl;
    return 0;
}