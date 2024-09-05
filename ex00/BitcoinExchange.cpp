/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:42:42 by anurtiag          #+#    #+#             */
/*   Updated: 2024/09/02 13:14:15 by anurtiag         ###   ########.fr       */
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

void BitcoinExchange::ChargeTable(std::string filename)
{
    std::map<std::string, float>::iterator it;
    std::map<std::string, float>::iterator end;
    std::ifstream infile;
    ft_open(filename, infile);
    std::cout << std::fixed << std::setprecision(2);
    std::string line;
    int pos;
    while (std::getline(infile, line))
	{
        pos = line.find(',');
		this->btc_values.insert(std::pair<std::string, float>(line.substr(0,pos), strtof(line.substr(pos + 1, line.length()).c_str(), NULL)));
	}
    it = btc_values.begin();
    end = btc_values.end();
    for(;it != end; it++)
    {
        std::cout << "Date: " << it->first << " value:" << it->second << "\n\n";
    }
    infile.close();
}

void BitcoinExchange::ChargeInput(std::string filename)
{
    std::ifstream infile;
    ft_open(filename, infile);
    std::string line;
    while (std::getline(infile, line))
	{
		this->ValidFormat(line);
	}
    infile.close();
}

void BitcoinExchange::ValidFormat(std::string line)
{
    size_t pos = line.find("|");
    if(pos == std::string::npos)
    {
        throw MyException("Invalid format");
    }
    ValidDate(line.substr(0, pos - 1));
}

void BitcoinExchange::ValidDate(std::string date)
{
    if(date.length() != DATELENGHT)
        throw MyException("Invalid date format");
    std::cout << date << std::endl;
}

void BitcoinExchange::ft_open(std::string filename, std::ifstream& infile)
{
    infile.open(filename.c_str());
	std::string line;
    
	if(!infile.is_open())
	{
		throw MyException("filename couldnt be opened");
	}
}

// void BitcoinExchange::ft_read(std::string filename, void(*function)(std::string line))
// {
// 	std::ifstream infile("data.csv");
//     // std::ifstream infile(filename.c_str());
// 	std::string line;
//     std::map<std::string, float>::iterator it;
//     std::map<std::string, float>::iterator end;
//     int pos;
    
//     std::cout << std::fixed << std::setprecision(2);
// 	if(!infile.is_open())
// 	{
// 		throw MyException("data.csv couldnt be opened");
// 	}
// 	while (std::getline(infile, line))
// 	{
//         pos = line.find(',');
// 		this->btc_values.insert(std::pair<std::string, float>(line.substr(0,pos), strtof(line.substr(pos + 1, line.length()).c_str(), NULL)));
// 	}
//     it = btc_values.begin();
//     end = btc_values.end();
//     for(;it != end; it++)
//     {
//         std::cout << "Date: " << it->first << " value:" << it->second << "\n\n";
//     }
// 	infile.close();
// }
