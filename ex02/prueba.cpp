/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 07:21:09 by anurtiag          #+#    #+#             */
/*   Updated: 2024/09/11 16:13:41 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iterator>
#include <stdlib.h>

// void Merge(std::list<int>* _list1, std::list<int>* _list2)
// {
//     std::list<int>::iterator i1 = _list1.begin();
//     std::list<int>::iterator i2 = _list2.begin();
//     std::list<int> _end;
//     std::cout << "entramoa aqui?\n";
//     for(int i = 0; i < 10 && (i1 != _list1.end() && i2 != _list2.end()); i++)
//     {
//         // *i1 < *i2 ? _end.push_back(*i1) : _end.push_back(*i2);
//         if(*i1 < *i2)
//         {
//             std::cout << "garbanzo\n";
//             std::cout << "holuu\n";
//             i1++;
//         }
//         else
//         {
//             std::cout << "boniato\n";
//             // _end.push_back(*i2);
//             i2++;
//         }
//     }
//     std::cout << "\n\n\n";
//     // for(std::list<int>::iterator i = _end.begin(); i != _end.end(); i++)
//     //     std::cout << "patata" << *i << " ";
//     std::cout << std::endl;
// }

void Merge(std::list<int>* _list1, std::list<int>* _list2)
{
    std::list<int>::iterator i1 = (*_list1).begin();
    std::list<int>::iterator i2 = (*_list2).begin();
    std::list<int> _end;
    for(int i = 0; i < 10 && (i1 != (*_list1).end() && i2 != (*_list2).end()); i++)
    {
        // *i1 < *i2 ? _end.push_back(*i1) : _end.push_back(*i2);
        if(*i1 < *i2)
        {
            _end.push_back(*i1);
            i1++;
        }
        else
        {
            _end.push_back(*i2);
            i2++;
        }
    }
    std::cout << std::endl;
}

// void MergeSort(std::list<int> _list, std::string control)
// {
//     // std::cout << "la lista de: " << control << " viene con: ";
//     // for(std::list<int>::iterator i = _list.begin(); i != _list.end(); i++)
//     //     std::cout << *i << " ";
//     // std::cout << "\n\n\n";
//     std::list<int> _list1;
//     std::list<int> _list2;
//     control += "a";
//     if(_list.size() > 1)
//     {
//         std::list<int>::iterator mid = _list.begin();
//         for(size_t i = 0; i < _list.size() / 2; i++)
//             mid++;
//         // std::cout << "el mid es: " << *mid << std::endl;
//         std::list<int> _list1(_list.begin(), mid);
//         std::list<int> _list2(mid, _list.end());
//         // std::cout << "llegamos hasta aqui?patata\n";
//         MergeSort(_list1, "list1");
//         MergeSort(_list2, "list2");
//         Merge(&_list1, &_list2);
//     }
//     // for(std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
//     //     std::cout << *it << std::endl;
//     // std::cout << "\n\n\n";
// }

std::list<int>::iterator IterAddition(std::list<int>::iterator iter, const unsigned int nbr)
{
    for(unsigned int i = 0; i < nbr; i++)
        iter++;
    return(iter);
}

void Merge(std::list<int>* _list1, int size)
{
    std::list<int>::iterator it1 = _list1->begin();
    std::list<int>::iterator it2 = IterAddition(it1, (size));
    if((*_list1).empty() == true)
        size++;
    for(; it2 != _list1->end();)
    {
        for(int i = 0; i < size; i++)
        {
            if(*it1 > *it2)
            {
                _list1->insert(it1, *it2);
                _list1->erase(it2++);
            }
            else
                it1++;
        }
        it1 = IterAddition(it2, 1);
        it2 = IterAddition(it1, (size - 1));
    }
}

// void MergeSort(std::list<int> _list, int size)
// {
//     if(size > 1)
//     {
//         MergeSort(_list, size / 2);
//     }
//     Merge(&_list, size);
//     for(std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
//         std::cout << *it << std::endl;
//     std::cout << "\n\n\n";
// }

// int main(int argc, char** argv)
// {
//     std::list<int> _list;
//     std::list<int>::iterator it;
//     int size;
//     for(int i = 1; i < argc; i++)
//     {
//         _list.push_back(std::atoi(argv[i]));
//     }
//     size = _list.size();
//     MergeSort(_list, size);
//     return(0);
// }


#include <bits/stdc++.h>
using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void merge(vector<int>& arr, int left, 
                     int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back 
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Function to print a vector
void printVector(vector<int>& arr)
{
    for (size_t i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code
int main()
{
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int n = arr.size();

    cout << "Given vector is \n";
    printVector(arr);

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted vector is \n";
    printVector(arr);
    return 0;
}