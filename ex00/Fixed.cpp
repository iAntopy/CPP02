/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:11:28 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/18 07:21:12 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int	Fixed::_frac_nbits = 8;

Fixed::Fixed(void) : _n(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
//	this->setRawBits(other.getRawBits());
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(other.getRawBits());
	return (*this);
}

int Fixed::getNbBits(void) const
{
	return (this->_frac_nbits);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_n);
}

void     Fixed::setRawBits(int const n)
{
//	std::cout << "setRawBits member function called" << std::endl;
	this->_n = n;
}

std::ostream&	operator<<(std::ostream& out, Fixed const& f)
{
	out << "Fixed {fbits: " << f.getNbBits() << ", nb: " << f.getRawBits() << "}" << std::endl;
	return (out);
}
