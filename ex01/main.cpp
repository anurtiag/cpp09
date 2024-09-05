/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 06:59:13 by anurtiag          #+#    #+#             */
/*   Updated: 2024/09/05 07:06:47 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char** argv)
{
    RPN polish;
    try
    {
        polish.ChargeInput(argc, argv);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    return(0);
}