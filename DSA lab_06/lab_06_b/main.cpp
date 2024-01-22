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

void QuickSort(int arr[],int left,int right)
{
    if (right>left)
    {
    int center = (left+right)/2;
    if(arr[center]<arr[left])
        swap(arr[center],arr[left]);
    if(arr[left]>arr[right])
        swap(arr[left],arr[right]);
    if(arr[center]>arr[right])
        swap(arr[center],arr[right]);
    swap(arr[center],arr[right-1]);
    int pivot=arr[right-1];
    int i=left ,j=right-1;
    for(;;)
    {
        while(arr[++i] < pivot){}
        while(pivot < arr[--j]){}
        if(i<j)
            swap(arr[i],arr[j]);
        else
            break;
    }
    swap(arr[i],arr[right - 1]);
    QuickSort(arr,left,i-1);
    QuickSort(arr,i+1,right);
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
   cout<<endl<<"Average value : "<<avg<<"ms";
   delete[] arry;
 return 0;
}
