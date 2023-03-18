/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:44:52 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/18 07:52:06 by iamongeo         ###   ########.fr       */
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
	static const float	_inverse_nbits_pow2;

public:
	Fixed(void);
	Fixed(Fixed const& other);
	Fixed(int const i);
	Fixed(float const f);
	~Fixed(void);

	Fixed&	operator=(Fixed const& other);

	int			getRawBits(void) const;
	void		setRawBits(int const raw);
	int			toInt(void) const;
	float		toFloat(void) const;
};

std::ostream&	operator<<(std::ostream& o, Fixed const& f);

#endif
