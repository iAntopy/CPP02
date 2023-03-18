/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 02:00:07 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/21 02:00:07 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_HPP__
# define __POINT_HPP__

# include <fstream>
# include "Fixed.hpp"

class Point
{
private:
	Fixed const	_x;
	Fixed const _y;

public:

	Point(void);
	Point(float x, float y);
	Point(Fixed const& x, Fixed const& y);
	Point(Point const& other);
	~Point(void);

	Point&	operator=(Point const& other);

	Point	operator+(Point const& other) const;
	Point	operator-(Point const& other) const;
	Point	operator*(Fixed const& scalar) const;
	Fixed	operator*(Point const& other) const;
	Point	operator/(Fixed const& scalar) const;

	Fixed const&	getX(void) const;
	Fixed const&	getY(void) const;
	//void			setX(Fixed const& f);
	//void			setY(Fixed const& f);
	Fixed			dot(Point const& other) const;
	static Fixed	dot(Point const& a, Point const& b);
	Point			orthogonal_right(void) const;
};

std::ostream&	operator<<(std::ostream& s, Point const& p);

#endif