#include <iostream>
#include <string>
using namespace std;
#include "H.h"
#include <ctime>

void print(ostream &out, long arr[], long n)
{
    for (long i = 0; i < n; i++)
    {
        out << "Arr[" << i+1 << "]: " << arr[i] << endl;
    }
    return ;
}

Zz1 selectSort(long arr[], long n) {
    Zz1 P;
    P.z = 0;
    P.z1 = 0;
    long i, j, k, x;
    for(i = 0; i < n; i++)
    {   	
        k = i; x = arr[i]; // i - number of the current step
        for(j = i+1; j < n; j++) // loop selection the smallest element
        {
            P.z += 1;
            if (arr[j] < x)
            {
                k = j; x = arr[j]; // k - index of the smallest element
            }
        }
    arr[k] = arr[i]; arr[i] = x; // swap the smallest with a[i]
    P.z1 += 1;
    }
    return P;
}

Zz1 heapify(long arr[], long n, long i)
{
    Zz1 P;
    P.z = 0;
    P.z1 = 0;
    long largest = i; // Initialize largest as root
    long l = 2 * i + 1; // left = 2*i + 1
    long r = 2 * i + 2; // right = 2*i + 2
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
    {
        P.z += 1;
        largest = l;
    }
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
    {
        P.z += 1;
        largest = r;
    }
    // If largest is not root
    if (largest != i)
    {
        P.z1 += 1;
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
    // cout << P.z << " - P.z. P.z1 - " << P.z1 << endl;
    return P;
}

Zz1 heapSort(long arr[], long n)
{
    Zz1 P1;
    P1.z = 0;
    P1.z1 = 0;
    long p = 0;
    // Build heap (rearrange array)
    for (long i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    // One by one extract an element from heap
    for (long i = n - 1; i >= 0; i--)
    {
        p += 1;
        // Move current root to end
        swap(arr[0], arr[i]);
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
    P1 = heapify(arr, n, 0);
    P1.z1 += p;
    return P1;
}

void downHeap(long arr[], long k, long n)
{
  long a = arr[k];
  long child;
  while(k <= n/2)
  {
    child = 2*k;
    if( child < n && arr[child] < arr[child+1] ) 
    child++;
    if( a >= arr[child] ) break; 
    arr[k] = arr[child];
    k = child;
  }
    arr[k] = a;
}

void hpSort(long a[], long size)
{
  long i;
  long b;
  for(i=size/2-1; i >= 0; i--) downHeap(a, i, size-1);
  for(i=size-1; i > 0; i--)
  {
    b=a[i]; a[i]=a[0]; a[0]=b;
    downHeap(a, 0, i-1);
  }
}

void createRandArrS(ostream &out, long arr[],long n, long r, long r1, long s)
{
    for (long i = 0; i <= n; i += s)
    {
        arr = new long[i];
        for (long j = 0; j < i; j++)
        {
            arr[j] = rand()%(r1-r+1) + r;
        }
        clock_t t0 = clock();
        selectSort(arr,i);
        clock_t t1 = clock();
        print(cout,arr,i); cout << endl;
        delete[] arr;
        out << "Elements[" << i << "] Time: " << (long double)(t1 - t0) / CLOCKS_PER_SEC << endl;
    }
    return ;
}

void createRandArrH(ostream &out, long arr[],long n, long r, long r1, long s)
{
    for (long i = 0; i <= n; i += s)
    {
        arr = new long[i];
        for (long j = 0; j < i; j++)
        {
            arr[j] = rand()%(r1-r+1) + r;
        }
        clock_t t0 = clock();
        heapSort(arr,i);
        clock_t t1 = clock();
        print(cout,arr,i); cout << endl;
        delete[] arr;
        out << "Elements[" << i << "] Time: " << (long double)(t1 - t0) / CLOCKS_PER_SEC << endl;
    }
    return ;
}

void createStrArrS(ostream &out, long arr[],long n, long r, long r1, long s)
{
    long z, z1;
    for (long i = 0; i <= n; i += s)
    {
        z = r;
        z1 = r1;
        arr = new long[n];
        for (long i = 0; i < n; i++)
        {
            if (z < z1){ arr[i] = z++; }
            else arr[i] = z1;
        }
        clock_t t0 = clock();
        selectSort(arr,i);
        clock_t t1 = clock();
        print(cout,arr,i); cout << endl;
        delete[] arr;
        out << "Elements[" << i << "] Time: " << (long double)(t1 - t0) / CLOCKS_PER_SEC << endl;
    }
    return ;
}

void createStrArrH(ostream &out, long arr[],long n, long r, long r1, long s)
{
    long z, z1;
    for (long i = 0; i <= n; i += s)
    {
        z = r;
        z1 = r1;
        arr = new long[n];
        for (long i = 0; i < n; i++)
        {
            if (z < z1){ arr[i] = z++; }
            else arr[i] = z1;
        }
        clock_t t0 = clock();
        heapSort(arr,i);
        clock_t t1 = clock();
        print(cout,arr,i); cout << endl;
        delete[] arr;
        out << "Elements[" << i << "] Time: " << (long double)(t1 - t0) / CLOCKS_PER_SEC << endl;
    }
    return ;
}

void createRevArrS(ostream &out, long arr[],long n, long r, long r1, long s)
{
    long z, z1;
    for (long i = 0; i <= n; i += s)
    {
        z = r;
        z1 = r1;
        arr = new long[n];
        for (long i = 0; i < n; i++)
        {
            if (z1 > z){ arr[i] = z1--; }
            else arr[i] = z;
        }
        clock_t t0 = clock();
        selectSort(arr,i);
        clock_t t1 = clock();
        print(cout,arr,i); cout << endl;
        delete[] arr;
        out << "Elements[" << i << "] Time: " << (long double)(t1 - t0) / CLOCKS_PER_SEC << endl;
    }
    return ;
}

void createRevArrH(ostream &out, long arr[],long n, long r, long r1, long s)
{
    long z, z1;
    for (long i = 0; i <= n; i += s)
    {
        z = r;
        z1 = r1;
        arr = new long[n];
        for (long i = 0; i < n; i++)
        {
            if (z1 > z){ arr[i] = z1--; }
            else arr[i] = z;
        }
        clock_t t0 = clock();
        heapSort(arr,i);
        clock_t t1 = clock();
        print(cout,arr,i); cout << endl;
        delete[] arr;
        out << "Elements[" << i << "] Time: " << (long double)(t1 - t0) / CLOCKS_PER_SEC << endl;
    }
    return ;
}