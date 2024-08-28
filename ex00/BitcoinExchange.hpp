/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:42:40 by anurtiag          #+#    #+#             */
/*   Updated: 2024/08/28 11:08:04 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <algorithm>
# include <fstream>
# include <iterator>
# include <iomanip>


class BitcoinExchange
{
    private:
        std::map<std::string, float> btc_values;
        std::string date;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& source);
        BitcoinExchange& operator=(const BitcoinExchange& source);
        ~BitcoinExchange();
        void ChargeTable();
        bool ValidFormat(std::string date);
        void ft_read();
};

#endif