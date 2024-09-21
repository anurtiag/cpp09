/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:57:02 by anurtiag          #+#    #+#             */
/*   Updated: 2024/09/07 13:01:18 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main()
{
    BitcoinExchange a;
    try
    {
        a.ChargeTable("data.csv");
        a.ChargeInput("input.txt");
    }
    // catch(const std::exception& e)
    // {
    //     std::cerr << "hmmm" << e.what() << '\n';
    // }
    catch(const MyException& e)
    {
        std::cerr << e.what() << '\n';
    }
    BitcoinExchange b;
    return(0);
}