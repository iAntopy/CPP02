/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:44:52 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/18 07:14:03 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

#include <fstream>

class Fixed
{
	private:
		int				_n;
		static const int	_frac_nbits;

	public:
		Fixed(void);
		Fixed(Fixed const& other);
		~Fixed(void);

		Fixed&	operator=(Fixed const& other);

		int			getRawBits(void) const;
		int			getNbBits(void) const;
		void		setRawBits(int const raw);
};

std::ostream&	operator<<(std::ostream& o, Fixed const& f);

#endif
