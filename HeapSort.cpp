#include <iostream>
#include <vector>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int maximum = root;  //Assign the position of root to maximum
   int left = 2*root + 1;  //position of Left child node
   int right = 2*root + 2;  //position of Right child node

   //If value of left node is larger than the value of maximum
   //Assign the position of left node as the maximum 
   maximum = arr[left] > arr[maximum] && left < n ? left : maximum;

   //If the value of right node is larger than the value of maximum
   //Assign the position of right node as the maximum 
   maximum = (right < n && arr[right] > arr[maximum]) ? right : maximum;

   //If maximum is not the root
    if (maximum != root) {
        swap(arr[root], arr[maximum]);
        heapify(arr, n, maximum != -1 && maximum != root ? maximum : root);
    }
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   int i = n/2-1;
   while (i >= 0) {
     heapify(arr, n, i);
     i--;
   }
  
   // extracting elements from heap one by one
   int j = 0;
   while (j < n) {
       swap(arr[0], arr[n-j-1]);
       heapify(arr, n-j-1, 0);
        j++;
   }

}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   vector<int> arr;
   
   cout<<"Input array"<<endl;
   cout<<"Enter * to finish inputting elements to the array"<<endl;
   int num;
   while (cin >> num && num != '*') {
       arr.push_back(num);
   }   
   
   int n = arr.size();
   int heap_arr[n];

   copy(arr.begin(), arr.end(), heap_arr);
   
   cout<<"Given Array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}