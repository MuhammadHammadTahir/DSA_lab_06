#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

using namespace std;

void swap(int& a, int& b)
{
    int temp = b;
    b = a;
    a = temp;
}

int partition(int a[],int left,int  right,int pivotIndex)
{
    int pivotValue = a[pivotIndex];
    swap(a[pivotIndex], a[right]); // Move pivot to end
                                // move all smaller (than pivotValue) to the begining
    int storeIndex = left;
    for (int i= left;i< right;i++)
    {
        if (a[i] < pivotValue)
        {
        swap(a[storeIndex], a[i]);
        storeIndex = storeIndex + 1;
        }
    }
    swap(a[right], a[storeIndex]); // Move pivot to its final place
    return storeIndex;
}

void QuickSort(int arr[],int left,int right)
{
    if (right>left)
    {
    int pivotIndex = (left+right)/2;
    int pivotNewIndex=partition(arr,left,right,pivotIndex);
    QuickSort(arr,left,pivotNewIndex-1);
    QuickSort(arr,pivotNewIndex+1,right);
    }
}

int main()
{
   double sum=0.0;
   double avg;
   int size;
   int value,result;
   cout<<"Please enter the size of array=";
   cin>>size;
   int* arry = new int[size];
   for(int j=0;j<3;j++)
   {
       for(int i=0; i<size; i++)
       {
        value=std::rand()%10000000;
        arry[i]=value;
       }
       using std::chrono::high_resolution_clock;
       using std::chrono::duration_cast;
       using std::chrono::duration;
       using std::chrono::milliseconds;
       auto t1= high_resolution_clock::now();
       QuickSort(arry,0,size);
       auto t2=high_resolution_clock::now();
       auto ms_int_1 = duration_cast<milliseconds>(t2-t1);
       duration<double, std::milli> ms_double_1=t2-t1;
       cout<<"Quick sort by better partition "<<endl;
       std::cout <<ms_int_1.count() <<"ms\n";
       std::cout <<ms_double_1.count() <<"ms"<<endl;
       sum+=ms_double_1.count();
   }
   avg=sum/3;
   cout<<avg<<"ms";
   delete[] arry;
 return 0;
}
