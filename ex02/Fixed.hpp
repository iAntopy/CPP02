/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:44:52 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/19 19:44:52 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

#include <fstream>

class Fixed
{
private:
	int					_n;
	static const int	_frac_nbits;

public:
	Fixed(void);
	Fixed(Fixed const& other);
	Fixed(int const i);
	Fixed(float const f);
	~Fixed(void);

	Fixed&	operator=(Fixed const& other);
	
	bool	operator<(Fixed const& other) const;
	bool	operator>(Fixed const& other) const;
	bool	operator<=(Fixed const& other) const;
	bool	operator>=(Fixed const& other) const;
	bool	operator==(Fixed const& other) const;
	bool	operator!=(Fixed const& other) const;

	Fixed	operator+(Fixed const& other) const;
	Fixed	operator-(Fixed const& other) const;
	Fixed	operator*(Fixed const& other) const;
	Fixed	operator/(Fixed const& other) const;

	Fixed	operator++();
	Fixed	operator++(int);
	Fixed	operator--();
	Fixed	operator--(int);

	static Fixed&		min(Fixed& lhs, Fixed& rhs);
	static Fixed const&	min(Fixed const& lhs, Fixed const& rhs);
	static Fixed&		max(Fixed& lhs, Fixed& rhs);
	static Fixed const&	max(Fixed const& lhs, Fixed const& rhs);

    int			getRawBits(void) const;
    void		setRawBits(int const raw);
	int			toInt(void) const;
	float		toFloat(void) const;
};

std::ostream&	operator<<(std::ostream& o, Fixed const& f);

#endif
