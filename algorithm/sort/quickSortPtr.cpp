#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

template<typename T>
void quick_sort(vector<T>& arr,int beg,int end)
{
	
	T pivot = arr[beg];
	int index = beg;
	int left = beg;
	int right = end;
	if(beg>=end)
		return;
	while(left<right)
	{

		while(left<right)
		{
			if(arr[right]<pivot)
				break;
			else
				right--;
		}
		
		while(left<right)
		{
			if(arr[left]>pivot)
				break;
			else
				left++;
		}
		
		if(left<right)
			swap(arr[left],arr[right]);
	

	}
	arr[index] = arr[left];
	arr[left] = pivot;

	
	quick_sort(arr,beg,right-1);
	quick_sort(arr,right+1,end);
	
}	


int main()
{
	vector<int> arr{6,1,2,7,9,3,4,5,10,8};
	cout<<"Before sort: "<<endl;
	for(auto e: arr)
		cout<<" "<<e;
	cout<<endl;
	quick_sort(arr,0,arr.size()-1);
	cout<<"After sort:"<<endl;
	for(auto e: arr)
		cout<<" "<<e;
	return 0;
}

