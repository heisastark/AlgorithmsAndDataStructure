#include<bits/stdc++.h>
using namespace std;

void showSubset(int subSet[], int size) {
   for(int i = 0; i < size; i++) {
      cout << subSet[i] << " ";
   }
   cout << endl;
}

void subsetSum(int set[], int subSet[], int n, int size, int total, int elementscount ,int sum) {
   if( total == sum) {

      //print the subset
      showSubset(subSet, size);

      //recurse for the other subsets
      subsetSum(set,subSet,n,size-1,total-set[elementscount],elementscount+1,sum);
      return;
   }
   else {
      for( int i = elementscount; i < n; i++ ) {
         //find the element to be added in subset
         subSet[size] = set[i];

         //pass the newly made subset for the possibility
         subsetSum(set,subSet,n,size+1,total+set[i],i+1,sum);
      }
   }
}

void findSubset(int set[], int size, int sum) {

   //subset array
   int *subSet = new int[size];
   subsetSum(set, subSet, size, 0, 0, 0, sum);
   delete[] subSet;
}

int main(){

   //Number of elements in the array
   int n;
   cin >> n;
   int arr[n];

   //Elements of the array
   for(int i=0; i<n; i++){
      cin >> arr[i];
   }

   //Sum whose subsets is to be found
   int sum;
   cin >> sum;

   findSubset(arr, n, sum);

   /*
   Input:
   7
   10 7 5 18 12 20 15
   35

   Output:
   10 7 18 
   10 5 20 
   5 18 12 
   20 15 
   */
   
}