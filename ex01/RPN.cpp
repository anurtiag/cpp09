/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 06:40:30 by anurtiag          #+#    #+#             */
/*   Updated: 2024/09/05 07:04:09 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _result(0), _initialized_stack(false) {}

RPN::~RPN() {}

void RPN::Addition()
{
    float num1;
    if(_initialized_stack == false)
    {
        if(_stack.size() < 2)
            throw MyException("Invalid expression");
        num1 = _stack.top();
        _stack.pop();
        _result = num1 + _stack.top();
        _stack.pop();
        _initialized_stack = true;
    }
    else
    {
        if(_stack.size() < 1)
            throw MyException("Invalid expression");
        _result += _stack.top();
        _stack.pop();
    }
}

void RPN::Substraction()
{
    float num1;
    if(_initialized_stack == false)
    {
        if(_stack.size() < 2)
            throw MyException("Invalid expression");
        num1 = _stack.top();
        _stack.pop();
        _result = num1 - _stack.top();
        _stack.pop();
        _initialized_stack = true;
    }
    else
    {
        if(_stack.size() < 1)
            throw MyException("Invalid expression");
        _result -= _stack.top();
        _stack.pop();
    }
}

void RPN::Multiplication()
{
    float num1;
    if(_initialized_stack == false)
    {
        if(_stack.size() < 2)
            throw MyException("Invalid expression");
        num1 = _stack.top();
        _stack.pop();
        _result = num1 * _stack.top();
        _stack.pop();
        _initialized_stack = true;
    }
    else
    {
        if(_stack.size() < 1)
            throw MyException("Invalid expression");
        _result *= _stack.top();
        _stack.pop();
    }
}

void RPN::Division()
{
    float num1;
    if(_initialized_stack == false)
    {
        if(_stack.size() < 2)
            throw MyException("Invalid expression");
        num1 = _stack.top();
        _stack.pop();
        _result = num1 / _stack.top();
        _stack.pop();
        _initialized_stack = true;
    }
    else
    {
        if(_stack.size() < 1)
            throw MyException("Invalid expression");
        _result /= _stack.top();
        _stack.pop();
    }
}

void RPN::IsOperator(char sign)
{
    switch (sign)
    {
    case (' '):
        ;
        break;
    case ('+'):
        Addition();
        break;
    case ('-'):
        Substraction();
        break;
    case ('*'):
        Multiplication();
        break;
    case ('/'):
        Division();
        break;
    default:
        throw MyException("Error");
        break;
    }
}

void RPN::ChargeInput(int argc, char** argv)
{
    if(argc != 2)
        throw MyException("Invalid arguments");
    for(int i = 0; argv[1][i] != '\0'; i++)
    {
        if(std::isdigit(argv[1][i]))
            _stack.push(argv[1][i] - ASCIITONBR);
        else
            IsOperator(argv[1][i]);
    }
    if(_stack.size() != 0)
        throw MyException("Invalid arguments");
    std::cout << _result << std::endl;
}