#include<bits/stdc++.h>
using namespace std;
int bs(int l, int h, int target, std::vector<int> &a) {
	int mid;
	if (l <= h) { //{0,1,2,3,4,5} call bs(0,5,2)
		int mid = (l + h) / 2;
		if (a[mid] == target)return target;
		if (a[mid] > target) return bs(l, mid - 1, target, a); //notice the use of return statement
		if (a[mid] < target) return bs(mid + 1, h, target, a); //the value you are looking for lies after a[mid] to search space modfy kar uske liye
	}
	return -1;
}
int bsiter(int l, int h, int target, std::vector<int> &a) {
	int mid;
	while (l <= h) { //{0,1,2,3,4,5} call bs(0,5,2)
		int mid = (l + h) / 2;
		if (a[mid] == target)return target;
		if (a[mid] > target) h = mid - 1; //notice the use of return statement
		if (a[mid] < target) l = mid + 1; //the value you are looking for lies after a[mid] to search space modfy kar uske liye
	}
	return -1;
}
int lowerb(int l, int h, int target, vector<int> &a) {
	int mid;
	while (l < h) {
		mid = (l + h) / 2;
		if (a[mid] < target)l = mid + 1;

		
		else {
			h = mid;
		}
	}
	if (a[l] >= target)return l;
	if (a[h] >= target)return h;
	return -1;
}
int upperb(int l, int h, int target, vector<int> &a) {
	int mid;
	while (l < h) {
		mid = (l + h) / 2;
		if (a[mid] <= target){
			l = mid + 1;
		}
		else {
			h = mid;
		}
	}
	if (a[l] > target)return l;
	//if (a[h] > target)return h;
	return -1;
}
int laster(int l, int h, int target, vector<int> &a){
    int mid, last = -1;
    while (l <= h) {
        mid = (l + h) / 2;
        if (a[mid] <= target) {
            if (a[mid] == target) {
                last = mid;
            }
            l = mid + 1;
        }
        else {
            h = mid - 1;
        }
    }
    return last;
}
int findPeakElement(vector<int>& nums) {
	int l=0,high=nums.size()-1;
	int mid;
	while(l<h){
		mid=(l+h)/2;
	}

        
}
class singleinsorted
{
  public:
    int findOnce(int arr[], int n)
    {
        int low = 0, high = n - 1;
        while (low < high) 
        {
            // Find the middle point
            int mid = (low + high) / 2;
        
            // If mid is even and element next to mid is
            // same as mid, then output element lies on
            // right side, else on left side
            if (mid%2 == 0)
            {
                if (arr[mid] == arr[mid+1])
                    low = mid + 2;
                else
                    high = mid;
            }
            else  // If mid is odd
            {
                if (arr[mid] == arr[mid-1])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return arr[low];
    }

};
int main() {

	vector<int> a;
	a = {0, 1, 2,2, 3, 5, 6};
	int ans = a[lowerb(0, 5, 4, a)];
	int ans1 = a[upperb(0, 6, 4, a)];
	int ans3=laster(0,6,2,a);
	cout << ans1;
	return 0;
}
