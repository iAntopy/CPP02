/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:11:28 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/18 23:04:34 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_frac_nbits = 8;
const float	Fixed::_inverse_nbits_pow2 = 1.0f / (1 << Fixed::_frac_nbits);

static int	float_to_fixed(float const f, int const frac_nBits)
{
	float	t;
	int		res;

	t = f * (1 << frac_nBits);
	res = (int)roundf(t);
	if (f < 0)
	{
		res = -res;
		res = ~res;
		res += 1;
	}
	return (res);
}

Fixed::Fixed(void) : _n(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(int const i) : _n(i << this->_frac_nbits) {
	std::cout << "Integer constructor called : " << i << " -> " << this->_n << std::endl;
}

Fixed::Fixed(float const f) : _n(float_to_fixed(f, _frac_nbits)) {
	std::cout << "Float constructor called : " << f << " -> " << _n << std::endl;
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
	int		c;

	if (this->_n < 0)
		return ((float)(~(this->_n - 1)) * -this->_inverse_nbits_pow2);
	else
		return ((float)this->_n * this->_inverse_nbits_pow2);
}

std::ostream&	operator<<(std::ostream& out, Fixed const& f)
{
	return (out << f.toFloat());
}
