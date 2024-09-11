/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 08:30:58 by anurtiag          #+#    #+#             */
/*   Updated: 2024/09/09 15:02:41 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    PmergeMe merge;
    try
    {
        merge.ParseInput(argc, argv);
        merge.ListSort();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    return(0);
    
}