#include <fstream>
#include <iostream>
using namespace std;
#include "H.h"
#include "C.cpp"

// Вариант №20.
// Don't work HeapSort and comparisons&swaps of HeapSort

int main()
{
  long* A = nullptr;
  int key = 0;
  while (key != 10)
  {
    cout << "\n1 - Sorting one random array.\n2 - Accumulation of statistical data.\n";
    cout << "10 - EXIT.\nEnter: ";
    cin >> key;
    cout << endl;
    switch (key)
    {
      case 1:
      {
        long n = 0, r = 0, r1 = 0;
        int keyy = 0;
        while (keyy != 10)
        {
          cout << "\n1 - Create an array.\n2 - Sorting an array by SelectSort.\n3 - Sorting an array by HeapSort.\n";
          cout << "10 - BACK.\nEnter: ";
          cin >> keyy;
          cout << endl;
          switch (keyy)
          {
            case 1:
            {
              if (A != nullptr) { delete[] A; n = 0; r = 0; r1 = 0; }
              cout << "Enter number of the Array: ";
              cin >> n;
              cout << "Specify the range of values of the array elements.\nEnter the smallest number: ";
              cin >> r;
              cout << "Enter the biggest number: ";
              cin >> r1; cout << endl;
              A = new long[n];
              for (long i = 0; i < n; i++)
              {
                A[i] = rand()%(r1-r+1) + r;
              }
              print(cout,A,n);
              cout << "\nThe Array is created.\n" << endl;
            }
            break;

            case 2:
            {
              if (A == nullptr) { cout << "Create an array first!\n"; break;}
              Zz1 P;
              ofstream fout;
              string f;
              cout << "Enter the name of the file, which you need to print: " << endl;
              cin >> f; // 1.txt
              fout.open(f, ios::trunc);
              if (!fout) { cout << "\n No file"; return 1; }
              print(fout,A,n);
              selectSort(A, n);
              P = selectSort(A,n);
              cout << "\nNumber of the comparisons = " << P.z << "\nNumber of the swaps = " << P.z1 << endl;
              fout << endl;
              print(fout,A,n);
              fout.close();
              cout << "\nDone!\n";
            }
            break;

            case 3:
            {
              if (A == nullptr) { cout << "Create an array first!\n"; break;}
              Zz1 P;
              ofstream fout;
              string f;
              cout << "Enter the name of the file, which you need to print: " << endl;
              cin >> f; // 1.txt
              fout.open(f, ios::trunc);
              if (!fout) { cout << "\n No file"; return 1; }
              print(fout,A,n);
              heapSort(A, n);
              P = heapSort(A, n);
              cout << "\nNumber of the comparisons = " << P.z << "\nNumber of the swaps = " << P.z1 << endl;
              fout << endl;
              print(fout,A,n);
              fout.close();
              cout << "\nDone!\n";
            }
            break;
          }
        }
      }
      break;

      case 2:
      {
        long n = 0, r = 0, r1 = 0, s = 0;
        int keyy = 0;
        while (keyy != 10)
        {
          cout << "\n1 - Create an array(random) + range&step + choose method of sorting.";
          cout << "\n2 - Create an array(straight order) + range&step + choose method of sorting.";
          cout << "\n3 - Create an array(reversed order) + range&step + choose method of sorting.";
          cout << "\n10 - BACK.\nEnter: ";
          cin >> keyy;
          cout << endl;
          switch (keyy)
          {
            case 1:
            {
              ofstream fout;
              string f;
              int answer = 0;
              if (A != nullptr) { delete[] A; n = 0; r = 0; r1 = 0; s = 0; }
              cout << "Enter number of the Array: " << endl;
              cin >> n;
              cout << "Specify the range of values of the array elements.\nEnter the smallest number: ";
              cin >> r;
              cout << "Enter the biggest number: ";
              cin >> r1; cout << endl;
              cout << "Enter the step of the creation an array: ";
              cin >> s; cout << endl;
              cout << "Enter 1 - if you want to sort by SelectSort\nEnter 2 - if you want to sort by HeapSort\nAnswer: ";
              cin >> answer; cout << endl;
              cout << "Enter the name of the file, which you need to print: " << endl;
              cin >> f; // 1.txt
              fout.open(f, ios::trunc);
              if (!fout) { cout << "\n No file"; return 1; }
              if (answer == 1) createRandArrS(fout,A,n,r,r1,s);
              if (answer == 2) createRandArrH(fout,A,n,r,r1,s);
              if (answer != 1 && answer != 2) { cout << "Error\n"; break; };
              // print(cout,A,n);
              fout.close();
              cout << "\nDone!\n";
            }
            break;

            case 2:
            {
              ofstream fout;
              string f;
              int answer = 0;
              if (A != nullptr) { delete[] A; n = 0; r = 0; r1 = 0; s = 0; }
              cout << "Enter number of the Array: " << endl;
              cin >> n;
              cout << "Specify the range of values of the array elements.\nEnter the smallest number: ";
              cin >> r;
              cout << "Enter the biggest number: ";
              cin >> r1; cout << endl;
              cout << "Enter the step of the creation an array: ";
              cin >> s; cout << endl;
              cout << "Enter 1 - if you want to sort by SelectSort\nEnter 2 - if you want to sort by HeapSort\nAnswer: ";
              cin >> answer; cout << endl;
              cout << "Enter the name of the file, which you need to print: " << endl;
              cin >> f; // 1.txt
              fout.open(f, ios::trunc);
              if (!fout) { cout << "\n No file"; return 1; }
              if (answer == 1) createStrArrS(fout,A,n,r,r1,s);
              if (answer == 2) createStrArrH(fout,A,n,r,r1,s);
              if (answer != 1 && answer != 2) { cout << "Error\n"; break; };
              // print(cout,A,n);
              fout.close();
              cout << "\nDone!\n";
            }
            break;

            case 3:
            {
              ofstream fout;
              string f;
              int answer = 0;
              if (A != nullptr) { delete[] A; n = 0; r = 0; r1 = 0; s = 0; }
              cout << "Enter number of the Array: " << endl;
              cin >> n;
              cout << "Specify the range of values of the array elements.\nEnter the smallest number: ";
              cin >> r;
              cout << "Enter the biggest number: ";
              cin >> r1; cout << endl;
              cout << "Enter the step of the creation an array: ";
              cin >> s; cout << endl;
              cout << "Enter 1 - if you want to sort by SelectSort\nEnter 2 - if you want to sort by HeapSort\nAnswer: ";
              cin >> answer; cout << endl;
              cout << "Enter the name of the file, which you need to print: " << endl;
              cin >> f; // 1.txt
              fout.open(f, ios::trunc);
              if (!fout) { cout << "\n No file"; return 1; }
              if (answer == 1) createRevArrS(fout,A,n,r,r1,s);
              if (answer == 2) createRevArrH(fout,A,n,r,r1,s);
              if (answer != 1 && answer != 2) { cout << "Error\n"; break; };
              // print(cout,A,n);
              fout.close();
              cout << "\nDone!\n";
            }
            break;
          }
        }
      }
      break;
    }
  }
  delete[] A;
  return 0;
}