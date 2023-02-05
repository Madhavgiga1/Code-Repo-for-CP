#include <bits/stdc++.h>
using namespace std;
void swap(int* a,int* b){
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(int l,int h,vector<int> &a){
	int pivot=a[l];
	int i=l;int j=h;
	while(i<j){
		while(a[i]<=pivot)i++;
		while(a[j]>pivot)j--;//for 4,8,7,12,15,16 j bilkul 4 ke index pe aakar rukega
		//element apni sahi position pe tha tu uski sahi jagah return karna chahta h to agar 4 se chote ko mila hi nhi matlab wo apni sahi jagah pe h
		if(i<j)swap(a[i],a[j]);
	}
	swap(a[j],a[l]);
	return j;
}
void quicksort(int l,int h,vector<int> &a){
	if(l<h){
		int pivot=partition(l,h,a);
		quicksort(l,pivot-1,a);
		quicksort(pivot+1,h,a);
	}
}
void bubblesort(vector<int> &a){
	int n=a.size();
	for(int i =0;i<n-1;i++){//4 passes for 5 elements
		for(int j=0;j<n-i-1;j++){//for(int j=i;j<=n-2;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
}
int main(){
	vector<int> a={4,8,7,12,15,16};
	//quicksort(0,4,a);
	bubblesort(a);
	for (int i = 0; i < a.size(); ++i)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}