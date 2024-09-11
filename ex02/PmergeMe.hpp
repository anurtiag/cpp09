/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:17:24 by anurtiag          #+#    #+#             */
/*   Updated: 2024/09/09 06:05:10 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGE_HPP

# include <iostream>
# include <vector>
# include <list>
# include <ctime>
# include <limits>
# include <stdlib.h>
# include <iterator>

# include "MyException.hpp"

class PmergeMe
{
    private:
        std::vector<unsigned int> _vec;
        std::list<unsigned int> _list;
        clock_t _start;
        clock_t _end;               
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& source);
        PmergeMe& operator=(const PmergeMe& source);
        ~PmergeMe();
        std::list<unsigned int>::iterator IterAddition(std::list<unsigned int>::iterator iter, const unsigned int nbr);
        void ParseInput(int argc, char** argv);
        void ListSort();
        void SortPairs();
        void SortThePairs();
        void VecSort();
        
};

#endif