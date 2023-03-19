/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 02:06:34 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/19 00:35:58 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}
Point::Point(float x, float y) : _x(Fixed(x)), _y(Fixed(y)) {}
Point::Point(Fixed const& x, Fixed const& y) : _x(x), _y(y) {}
Point::Point(Point const& other): _x(other.getX()), _y(other.getY()) {}

Point::~Point(void) {}

Fixed const&	Point::getX(void) const {return (_x);}
Fixed const&	Point::getY(void) const {return (_y);}

// This is here to fulfill the Canonical form's requirements but is useless.
// This will be called when one Point p1 tries to take another points values of
// x and y with the '=' operator (a = b). But since these are const variables,
// they cannot be changed after constuction. Only prints a warning
// message to inform of its uselessness .
Point& Point::operator=(const Point& other) {
	std::cerr << "WARNING :: The assignment operator implementation for this function does nothing and should\
 not be used. Points are built to have constant x and y values initialized at constuction." << std::endl;
	return (*this);
}

/*
// This formulation actually compiles and successfully breaks through the
// const-correctness restrictions on the Point's _x and _y const Fixed vars.
// In other words, this can assign new values to constant variables.
// This is extremly bad form since const variables should be expected to remain
// constant as the qualifier suggests. But this seems to be the only way to 
// have the Coplien canonical form fully work with this exercise (or any 
// class where private member variables are constants). 
// Again, this is bad, very bad, not good.
Point& Point::operator=(const Point& other) 
{
	if (this != &other)
	{
		const_cast<Fixed&>(_x) = other.getX();
		const_cast<Fixed&>(_y) = other.getY();
	}
	return (*this);
}
*/

Point	Point::operator+(Point const& other) const {
	return (Point(_x + other.getX(), _y + other.getY()));}

Point	Point::operator-(Point const& other) const {
	return (Point(_x - other.getX(), _y - other.getY()));}

Point	Point::operator*(Fixed const& scalar) const {
	return (Point(_x * scalar, _y * scalar));}

Point	Point::operator/(Fixed const& scalar) const {
	return (Point(_x / scalar, _y / scalar));}

Fixed	Point::dot(Point const& other) const {
	return (_x * other.getX() + _y * other.getY());}

Fixed	Point::operator*(Point const& other) const {
	return (this->dot(other));}

Fixed	Point::dot(Point const& a, Point const& b) {
	return (a * b);}

Point	Point::orthogonal_right(void) const {
	return (Point(_y, -_x));}

std::ostream&	operator<<(std::ostream& s, Point const& p)
{
	return (s << "Point{" << p.getX() << ", " << p.getY() << "} ");
}
