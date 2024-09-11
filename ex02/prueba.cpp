/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 07:21:09 by anurtiag          #+#    #+#             */
/*   Updated: 2024/09/10 15:41:57 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iterator>

void Merge(std::list<int> _list1, std::list<int> _list2)
{
    std::list<int>::iterator i1 = _list1.begin();
    std::list<int>::iterator i2 = _list2.begin();
    std::list<int> _end;
    std::cout << "entramoa aqui?\n";
    for(;i1 != _list1.end() || i2 != _list2.end();)
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
    for(std::list<int>::iterator i = _end.begin(); i != _end.end(); i++)
        std::cout << "patata" << *i << " ";
    std::cout << std::endl;
}

void MergeSort(std::list<int> _list, std::string control)
{
    // std::cout << "la lista de: " << control << " viene con: ";
    // for(std::list<int>::iterator i = _list.begin(); i != _list.end(); i++)
    //     std::cout << *i << " ";
    // std::cout << "\n\n\n";
    control += "a";
    if(_list.size() > 1)
    {
        std::list<int>::iterator mid = _list.begin();
        for(size_t i = 0; i < _list.size() / 2; i++)
            mid++;
        // std::cout << "el mid es: " << *mid << std::endl;
        std::list<int> _list1(_list.begin(), mid);
        std::list<int> _list2(mid, _list.end());
        std::cout << "llegamos hasta aqui?patata\n";
        MergeSort(_list1, "list1");
        MergeSort(_list2, "list2");
        Merge(_list1, _list2);
    }
    // for(std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
    //     std::cout << *it << std::endl;
}

int main(int argc, char** argv)
{
    std::list<int> _list;
    std::list<int>::iterator it;
    for(int i = 1; i < argc; i++)
    {
        _list.push_back(std::atoi(argv[i]));
    }
    // for(it = _list.begin(); it != _list.end(); it++)
    //     std::cout << *it << std::endl;
    // std::cout << "\n\n\n";
    MergeSort(_list, "first");
    return(0);
}
