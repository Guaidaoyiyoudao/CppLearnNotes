#include <iostream>
#include <vector>
using namespace std;


void bubleSort(vector<int>& nums,int beg,int end)
{
    for(int i=beg;i<end;i++)
    {
        for(int j=beg;j<end-i;j++)
        {
            if(nums[j]>nums[j+1])
            {
                int tmp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = tmp;
            }
        }
    }

}

int main()
{
    std::vector<int> arr = {2,1,4,3,8,5,9,6,10,7};
    std::cout<<"before select sort:";
    for(auto e: arr)
        std::cout<<e<<" ";
    bubleSort(arr,0,arr.size()-1);
    std::cout<<"\nafter select sort:";
    for(auto e: arr)
        std::cout<<e<<" ";
    std::cout<<std::endl;
    return 0;
}