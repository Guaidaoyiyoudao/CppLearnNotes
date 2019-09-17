#include <iostream>
#include <vector>
using namespace std;
// 资料： https://zhuanlan.zhihu.com/p/41446726
//采用挖坑法
void quickSort(vector<int>& nums,int beg,int end){

    if(beg==end)
        return;
    int index = beg;
    int pivot = nums[index];
    int left = beg;
    int right = end - 1;
    while(left<right){
        
        while(left<right){
            if(nums[right]<pivot){
                nums[index] = nums[right];
                index = right;
                left++;
                break;
            }else
                right--; 
        }

        while(left<right){
            if(nums[left]>pivot){
                nums[index] = nums[left];
                index = left;
                right--;
                break;
            }else
                left++; 
        }

    }

    nums[index] = pivot;

    quickSort(nums,beg,index);
    quickSort(nums,index+1,end);
}
//采用指针交换法
void quickSort_ptr(vector<int>& nums,int beg,int end){

    if(beg<=end)
        return;
    int index = beg;
    int pivot = nums[index];
    int left = beg;
    int right = end - 1;

    while(left<right){

        while(left<right){

            if(nums[right]>=pivot)
                right--;
            else
                break;
        }
        while(left<right){

            if(nums[left]<=pivot)
                left++;
            else
                break;
        
        }
        if(left<right){
            int tmp = nums[left];
            nums[left]  = nums[right];
            nums[right] =  tmp;
        }



    }

    nums[index] = nums[left];//nums[right] left==right
    nums[left] = pivot;

    quickSort_ptr(nums,beg,left-1);
    quickSort_ptr(nums,left+1,end);

}


int main()
{
    std::vector<int> arr = {4,7,6,5,3,2,8,1};
    std::cout<<"before select sort:";
    for(auto e: arr)
        std::cout<<e<<" ";
    quickSort_ptr(arr,0,arr.size());
    std::cout<<"\nafter select sort:";
    for(auto e: arr)
        std::cout<<e<<" ";
    std::cout<<std::endl;
    return 0;
}
