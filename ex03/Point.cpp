/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 02:06:34 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/21 02:06:34 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "Fixed.hpp"
#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {std::cout << "Default Point constructor" << std::endl;}
Point::Point(float x, float y) : _x(Fixed(x)), _y(Fixed(y)) {}//{std::cout << "Point constructor with args " << std::endl;};
Point::Point(Fixed const& x, Fixed const& y) : _x(x), _y(y) {}//{std::cout << "Point constructor with args " << std::endl;};
Point::Point(Point const& other): _x(other.getX()), _y(other.getY()) {}//{std::cout << "Point constructor by copy " << std::endl;};

Point::~Point(void) {}

Fixed const&	Point::getX(void) const {return (_x);}
Fixed const&	Point::getY(void) const {return (_y);}
//void			Point::setX(Fixed const& f) {this->_x = f;}
//void			Point::setY(Fixed const& f) {this->_y = f;}


Point&	Point::operator=(Point const& other) {
//	std::cout << "Point constructor by assignation " << std::endl;
//	this->_x = other.getX();
//	this->_y = other.getY();
	return (*this);
}

Point	Point::operator+(Point const& other) const {
	return (Point(_x + other.getX(), _y + other.getY()));}

Point	Point::operator-(Point const& other) const {
	return (Point(_x - other.getX(), _y - other.getY()));}

Point	Point::operator*(Fixed const& scalar) const {
	return (Point(_x * scalar, _y * scalar));}

Point	Point::operator/(Fixed const& scalar) const {
	return (Point(_x / scalar, _y / scalar));}

Fixed	Point::dot(Point const& other) const {
	return (_x * other.getX() + _y * other.getY());
}

Fixed	Point::operator*(Point const& other) const {
	return (this->dot(other));
}

Fixed	Point::dot(Point const& a, Point const& b) {
	return (a * b);
}

Point	Point::orthogonal_right(void) const {
	//std::cout << "Entering orthogonal right in point : " << *this << std::endl;
	return (Point(_y, -_x));
}

std::ostream&	operator<<(std::ostream& s, Point const& p)
{
	s << "Point{" << p.getX() << ", " << p.getY() << "} ";
	return (s);
}
