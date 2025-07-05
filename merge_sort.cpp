#include<iostream>
#include<vector>
using namespace std;

 void merge(int arr[],int low, int mid,int high ){
        vector<int>temp;
        int l = low;
        int r = mid + 1;

        while(l<=mid && r<=high ){
            if(arr[l]<=arr[r]){
                temp.push_back(arr[l]);
                l++;
            }
            else{
                temp.push_back(arr[r]);
                r++;
            }
        }

        while(l<=mid){
            temp.push_back(arr[l]);
            l++;
        }

        while(r<=high){
            temp.push_back(arr[r]);
            r++;
        }

        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
    }

void mergeSort(int arr[],int low,int high){
    if(low>=high) return;
    int mid=(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);

}
   
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int low=0;
    int high=n-1;

    mergeSort(arr,low,high);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}