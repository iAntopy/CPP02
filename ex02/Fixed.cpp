/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:11:28 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/18 23:20:14 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_frac_nbits = 8;
const float		Fixed::_inverse_nbits_pow2 = 1.0f / (1 << Fixed::_frac_nbits);

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

Fixed::Fixed(void) : _n(0) {}

Fixed::Fixed(Fixed const& other) : _n(other.getRawBits()) {}

Fixed::Fixed(int const i) : _n(i << this->_frac_nbits) {}

Fixed::Fixed(float const f) : _n(float_to_fixed(f, _frac_nbits)) {}

Fixed::~Fixed(void) {}

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
	if (this->_n < 0)
		return ((float)(~(this->_n - 1)) * -this->_inverse_nbits_pow2);
	else
		return ((float)this->_n * this->_inverse_nbits_pow2);
}

std::ostream&	operator<<(std::ostream& out, Fixed const& f)
{
	return (out << f.toFloat());
}

bool	Fixed::operator<(Fixed const& other) const {return (_n < other.getRawBits());}
bool	Fixed::operator>(Fixed const& other) const {return (_n > other.getRawBits());}
bool	Fixed::operator<=(Fixed const& other) const {return (_n <= other.getRawBits());}
bool	Fixed::operator>=(Fixed const& other) const {return (_n >= other.getRawBits());}
bool	Fixed::operator==(Fixed const& other) const {return (_n == other.getRawBits());}
bool	Fixed::operator!=(Fixed const& other) const {return (_n != other.getRawBits());}

Fixed	Fixed::operator+(Fixed const& other) const
{
	Fixed	ret;

	ret.setRawBits(this->_n + other.getRawBits());
	return (ret);
}
Fixed	Fixed::operator-(Fixed const& other) const
{
	Fixed	ret;

	ret.setRawBits(this->_n - other.getRawBits());
	return (ret);
}
Fixed	Fixed::operator-() const
{
	Fixed	ret;

	ret.setRawBits(-this->_n);
	return (ret);
}

Fixed	Fixed::operator*(Fixed const& other) const
{
	Fixed	ret;

	ret.setRawBits((this->_n * other.getRawBits()) >> this->_frac_nbits);
	return (ret);
}

Fixed	Fixed::operator/(Fixed const& other) const
{
	Fixed	ret;

	ret.setRawBits(((this->_n << this->_frac_nbits) / other.getRawBits()));
	return (ret);
}

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

Fixed&	Fixed::min(Fixed& lhs, Fixed& rhs)
{
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}

Fixed const&	Fixed::min(Fixed const& lhs, Fixed const& rhs)
{
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}

Fixed&	Fixed::max(Fixed& lhs, Fixed& rhs)
{
	if (lhs > rhs)
		return (lhs);
	return (rhs);
}

Fixed const&	Fixed::max(Fixed const& lhs, Fixed const& rhs)
{
	if (lhs > rhs)
		return (lhs);
	return (rhs);
}
