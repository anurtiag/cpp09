/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:51:08 by anurtiag          #+#    #+#             */
/*   Updated: 2024/09/11 12:44:51 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    
}

PmergeMe::PmergeMe(const PmergeMe& source)
{
    *this = source;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& source)
{
    if(this != &source)
    {
        _vec = source._vec;
        _list = source._list;
    }
    return(*this);
}

PmergeMe::~PmergeMe()
{
    
}

std::list<unsigned int>::iterator PmergeMe::IterAddition(std::list<unsigned int>::iterator iter, const unsigned int nbr)
{
    for(unsigned int i = 0; i < nbr; i++)
        iter++;
    return(iter);
}

void  PmergeMe::SortPairs()
{
    std::list<unsigned int>::iterator iter = _list.begin();
    std::list<unsigned int>::iterator iter2 = iter;
    iter2++;
    // if(_list.size() == 1)
    //     std::cout << "After: " << _list.front() << std::endl;
    for(; iter != _list.end() && iter2 != _list.end(); iter = this->IterAddition(iter, 2), iter2 = this->IterAddition(iter2, 2))
    {
        std::cout << *iter << "\n" << *iter2 << std::endl;
        if(*iter > *iter2)
        {
            std::swap(*iter, *iter2);
        }
    }
    std::cout << "\n\n\n";
    for(std::list<unsigned int>::iterator i = _list.begin(); i != _list.end(); i++)
        std::cout << *i << std::endl;
}

void PmergeMe::ListSort()
{
    SortPairs();
}

void PmergeMe::ParseInput(int argc, char** argv)
{
    double checknum;
    char end = '\0';
    char* endptr = &end;
    if(argc > 3001 || argc < 2)
        throw MyException("Invalid number of arguments");
    for(int i = 1; argv[i] != NULL; i++)
    {
        checknum = std::strtod(argv[i], &endptr);
        if(*endptr != '\0' || checknum < 0 || checknum > std::numeric_limits<int>::max())
            throw MyException("double: impossible");
        _vec.push_back(static_cast<unsigned int>(checknum));
        _list.push_back(static_cast<unsigned int>(checknum));
    }
}
