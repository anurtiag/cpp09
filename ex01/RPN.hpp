/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 06:40:27 by anurtiag          #+#    #+#             */
/*   Updated: 2024/09/05 07:03:25 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

# include "MyException.hpp"

# define ASCIITONBR 48

class RPN
{
    private:
        std::stack<float>   _stack;
        float               _result;
        bool                _initialized_stack;
    public:
        RPN();
        ~RPN();
        void ChargeInput(int argc, char** argv);
        void IsOperator(char sign);
        void Addition();
        void Substraction();
        void Multiplication();
        void Division();
};

#endif