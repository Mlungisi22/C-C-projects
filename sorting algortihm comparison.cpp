#include<iostream>
#include<string>
#include<time.h>
#include<ctime>
#include<fstream>
#include<chrono>
#include<vector>
#include<random>
#include<stdlib.h>

using namespace std;

vector<long long> geninput(int number){
    vector<long long> store;
    int randomnumber;
    int max=10000;
    srand(time(0));
    for(int i=0;i<number;i++){
         randomnumber=rand()%max;
         store.push_back(randomnumber);
    }
    return store;
    
}


void insertionsort(vector<long long> &numbers,int n){
    for(int j=1 ; j < n ; j++) {
        int Key = numbers[j]; 
        int i = j-1; 
        while(i >= 0 && numbers[i] > Key){
            numbers[i + 1] = numbers[i];
            i = i - 1;
        }
        numbers[i + 1] = Key;
    }
}


void swapping(int &a, int &b) {         //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void selectionSort(vector<long long> &vec, int size) {
   int i, j, imin;
   for(i = 0; i<size-1; i++) {
      imin = i;   //get index of minimum data
      for(j = i+1; j<size; j++)
         if(vec[j] < vec[imin])
            imin = j;
         //placing in correct position
         swap(vec[i], vec[imin]);
   }
}

void bubblesort(vector<long long> &numbers,int n){
    for(int i = 0; i < n; i++) {
         for(int j=1; j < (n-i); j++) {
            if(numbers[j-1] > numbers[j]) {
                swap(numbers[j-1],numbers[j]);
            }
         }
      }
}
  
void print(vector<long long> numbers){
    for(long i:numbers){
        cout<<i<<"\t";
    }
}

void merge(vector<long long > &array, int l, int m, int r) {
   int i, j, k, nl, nr;
   //size of left and right sub-arrays
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   //fill left and right sub-arrays
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   //marge temp arrays to real array
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //extra element in left array
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //extra element in right array
      array[k] = rarr[j];
      j++; k++;
   }
}
void mergeSort(vector<long long> &array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second arrays
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}
void elementSwap(long long* ele1, long long* ele2)
{
int temp = *ele1;
*ele1 = *ele2;
*ele2 = temp;
}

long elementPartition (vector<long long> array, int less, int more){
    long pivotelement = array[more];
    long indexSmaller = (less - 1);
    for (int qs = less; qs <= more - 1; qs++){
        if (array[qs] < pivotelement){
            indexSmaller++;
            elementSwap(&array[indexSmaller], &array[qs]);
        }
    }
    elementSwap(&array[indexSmaller + 1], &array[more]);
    return (indexSmaller + 1);
    }
void demoquickSort(vector<long long> &array, int less, int greater){
    if (less < greater){
        long parInd = elementPartition(array, less, greater);
        demoquickSort(array, less, parInd - 1);
        demoquickSort(array, parInd + 1, greater);
    }
}

void bubblesortEscapeClause(vector<long long> &Integers,int n)
{
    int i = Integers.size() - 1;
    bool sorting = true;
    bool swopped;
    while (i >= 1 && sorting == true)
    {
        swopped = false;
        for (int j = 0; j <= i - 1; j++)
        {
            if (Integers[j] > Integers[j + 1])
            {
                //swap
                int temp = Integers[j];
                Integers[j] = Integers[j + 1];
                Integers[j + 1] = temp;
                swopped = true;
            }
        }
        if (swopped == false)
        {
            sorting = false;
        }
        else
        {
            i = i - 1;
        }
    }
}


int main(){
    int runs=5;
    vector<long> selectiontime,bubbletime,bubescapetime,insertion,mergee,quicki;
    for(int n=1000;n<=20000;n+=1000){
        vector<long long> algo1,algo2,algo3,algo4,algo5,algo6;
        algo1=geninput(n);
        algo2=algo1;algo3=algo1;algo4=algo1;algo5=algo1;algo6=algo1;
        //time selection sort
        long avg1,avg2,avg3,avg4,avg5,avg6;
        long totime1=0;long totime2=0;long totime3=0;long totime4=0;long totime5=0;long totime6=0;
        for(int i=0;i<runs;i++){
            auto start = chrono::high_resolution_clock::now();
            selectionSort(algo1,n);
            auto finish = chrono::high_resolution_clock::now();
            long long nanoseconds = chrono::duration_cast<chrono::nanoseconds>(finish - start).count();
            totime1 = totime1 + nanoseconds;
        }
        avg1=totime1/runs;
        selectiontime.push_back(avg1);
    
        //time bubblesort sort
        for(int i=0;i<runs;i++){
            auto start = chrono::high_resolution_clock::now();
            bubblesort(algo2,n);
            auto finish = chrono::high_resolution_clock::now();
            long long nanoseconds = chrono::duration_cast<chrono::nanoseconds>(finish - start).count();
            totime2 = totime2 + nanoseconds;
        }
        avg2=totime2/runs;
        bubbletime.push_back(avg2);
    
        //time bubblesortEscapeClause sort
        for(int i=0;i<runs;i++){
            auto start = chrono::high_resolution_clock::now();
            bubblesortEscapeClause(algo3,n);
            auto finish = chrono::high_resolution_clock::now();
            long long nanoseconds = chrono::duration_cast<chrono::nanoseconds>(finish - start).count();
            totime3 = totime3 + nanoseconds;
        }
        avg3=totime3/runs;
        bubescapetime.push_back(avg3);
        //time insertion sort
        for(int i=0;i<runs;i++){
            auto start = chrono::high_resolution_clock::now();
            insertionsort(algo4,n);
            auto finish = chrono::high_resolution_clock::now();
            long long nanoseconds = chrono::duration_cast<chrono::nanoseconds>(finish - start).count();
            totime4 = totime4 + nanoseconds;
        }
        avg4=totime4/runs;
        insertion.push_back(avg4);
        //time for mergeSort
        for(int i=0;i<runs;i++){
            auto start = chrono::high_resolution_clock::now();
            mergeSort(algo5,0,n);
            auto finish = chrono::high_resolution_clock::now();
            long long nanoseconds = chrono::duration_cast<chrono::nanoseconds>(finish - start).count();
            totime5 = totime5 + nanoseconds;
        }
        avg5=totime5/runs;
        mergee.push_back(avg5);
        for(int i=0;i<runs;i++){
            auto start = chrono::high_resolution_clock::now();
            demoquickSort(algo6,0,n);
            auto finish = chrono::high_resolution_clock::now();
            long long nanoseconds = chrono::duration_cast<chrono::nanoseconds>(finish - start).count();
            totime6 = totime6 + nanoseconds;
        }
        avg6=totime6/runs;
        quicki.push_back(avg6);
    }    
    for(long avg:selectiontime){cout<<avg<<",";}
    cout<<"\n";
    for(long avg:bubbletime){cout<<avg<<",";}
    cout<<"\n";
    for(long avg:bubescapetime){cout<<avg<<",";}
    cout<<"\n";
    for(long avg:insertion){cout<<avg<<",";}
    cout<<"\n";
    for(long avg:mergee){cout<<avg<<",";}
    cout<<"\n";
    for(long avg:quicki){cout<<avg<<",";}
    cout<<"\n";
    
    return 0;
}
