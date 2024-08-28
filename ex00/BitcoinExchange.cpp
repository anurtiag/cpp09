/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:42:42 by anurtiag          #+#    #+#             */
/*   Updated: 2024/08/28 11:07:34 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "MyException.hpp"

BitcoinExchange::BitcoinExchange()
{
    
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& source)
{
    *this = source;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& source)
{
    this->btc_values = source.btc_values;
    this->date = source.date;
    return(*this);
}

BitcoinExchange::~BitcoinExchange()
{
    
}

void BitcoinExchange::ChargeTable()
{
    
}

bool BitcoinExchange::ValidFormat(std::string date)
{
    date += "a";
    return(true);
}

void BitcoinExchange::ft_read()
{
	std::ifstream infile("data.csv");
	std::string line;
    std::map<std::string, float>::iterator it;
    std::map<std::string, float>::iterator end;
    int pos;
    
    std::cout << std::fixed << std::setprecision(2);
	if(!infile.is_open())
	{
		std::cerr << "infile could not be opened" << std::endl;
		throw MyException("data.csv couldnt be opened");
	}
	while (std::getline(infile, line))
	{
        pos = line.find(',');
		this->btc_values.insert(std::pair<std::string, float>(line.substr(0,pos), strtof(line.substr(pos + 1, line.length()).c_str(), NULL)));
	}
    it = btc_values.begin();
    end = btc_values.end();
    for(;it != end; it++)
    {
        std::cout << "Date: " << it->first << "value:" << it->second << "\n\n";
    }
	infile.close();
}
