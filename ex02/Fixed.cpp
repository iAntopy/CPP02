/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:11:28 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/20 02:11:28 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_frac_nbits = 8;

static int	float_to_fixed(float const f, int const frac_nBits)
{
	float	t;
	int		res;

	t = f * (1 << frac_nBits);
	res = (int)roundf(t);
	if (t < 0)
	{
		res = -res;
		res = ~res;
		res += 1;
	}
	return (res);
}

static float	fixed_to_float(int const x, int const frac_nBits)
{
	int		c;
	int		sign;
	float	f;

	c = std::abs(x);
	sign = 1;
	if (x < 0)
	{
		c = x - 1;
		c = ~c;
		sign = -1;
	}
	f = (float)c / (1 << frac_nBits);
	f *= sign;
	return (f);
}

Fixed::Fixed(void) : _n(0) {
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& other) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(int const i) : _n(i << this->_frac_nbits) {
	//std::cout << "Integer constructor called : " << i << " -> " << this->_n << std::endl;
}

//Fixed::Fixed(float const f) : _n(f * pow2(_frac_nbits)) {
Fixed::Fixed(float const f) : _n(float_to_fixed(f, _frac_nbits)) {
	//std::cout << "Float constructor called : " << f << " -> " << _n << std::endl;
}

Fixed::~Fixed(void) {
	//std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const& other)
{
	this->setRawBits(other.getRawBits());
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->_n);
}

void     Fixed::setRawBits(int const n)
{
	this->_n = n;
}

int		Fixed::toInt(void) const
{
	return (_n >> _frac_nbits);
}

float	Fixed::toFloat(void) const
{
	return (fixed_to_float(_n, _frac_nbits));
}

std::ostream&	operator<<(std::ostream& out, Fixed const& f)
{
	out << f.toFloat();
	return (out);
}

bool	Fixed::operator<(Fixed const& other) const {return (_n < other._n);}
bool	Fixed::operator>(Fixed const& other) const {return (_n > other._n);}
bool	Fixed::operator<=(Fixed const& other) const {return (_n <= other._n);}
bool	Fixed::operator>=(Fixed const& other) const {return (_n >= other._n);}
bool	Fixed::operator==(Fixed const& other) const {return (_n == other._n);}
bool	Fixed::operator!=(Fixed const& other) const {return (_n != other._n);}

Fixed	Fixed::operator+(Fixed const& other) const {
	return (Fixed(this->toFloat() + other.toFloat()));}
Fixed	Fixed::operator-(Fixed const& other) const {
	return (Fixed(this->toFloat() - other.toFloat()));}
Fixed	Fixed::operator*(Fixed const& other) const {
	return (Fixed(this->toFloat() * other.toFloat()));}
Fixed	Fixed::operator/(Fixed const& other) const {
	return (Fixed(this->toFloat() / other.toFloat()));}

Fixed	Fixed::operator++()
{
	++_n;
	return (Fixed(*this));
}
Fixed	Fixed::operator--()
{
	--_n;
	return (Fixed(*this));
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp;

	temp = *this;
	_n++;
	return (temp);
}
Fixed	Fixed::operator--(int)
{
	Fixed	temp;

	temp = *this;
	_n--;
	return (temp);
}

Fixed&	Fixed::min(Fixed& lhs, Fixed& rhs) {
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}

Fixed const&	Fixed::min(Fixed const& lhs, Fixed const& rhs) {
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}

Fixed&	Fixed::max(Fixed& lhs, Fixed& rhs) {
	if (lhs > rhs)
		return (lhs);
	return (rhs);
}

Fixed const&	Fixed::max(Fixed const& lhs, Fixed const& rhs) {
	if (lhs > rhs)
		return (lhs);
	return (rhs);
}