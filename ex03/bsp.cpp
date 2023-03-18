/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 02:14:06 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/21 02:14:06 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

//bool bsp( Point const a, Point const b, Point const c, Point const point);

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point	ab(b - a);
	Point	ac(c - a);
	Point	ap((point - a).orthogonal_right());

	Fixed	is_right_of_ab = (ab * ap);
	Fixed	is_right_of_ac = (ac * ap);
//	std::cout << "ab, ac, ap : " << ab << ac << ap << std::endl;
//	std::cout << "is_right_of_ab : " << is_right_of_ab << ", is_right_of_ac : " << is_right_of_ac << std::endl; 

	// If point is to the right or left of 2 segments starting at the same point
	// (a in our case), point cannot be inside the triangle.
	if ((is_right_of_ab > 0) == (is_right_of_ac > 0)
		|| (is_right_of_ab == 0)
		|| (is_right_of_ac == 0))
		return (false);

	Point	bc(c - b);
	Point	bp((point - b).orthogonal_right());

//	std::cout << "bc, bp : " << bc << bp << std::endl;
	Fixed	is_right_of_bc = (bc * bp);
//	std::cout << "is_right_of_bc : " << is_right_of_bc << std::endl;

	// The point MUST be on the same side of AB as BC. If not, the point cannot be inside.
	// If one of the tests is == 0, the point lies on one of the segments/edges
	// and is therefore considered to be outside according to the subject.
	if ((is_right_of_ab > 0 != is_right_of_bc > 0)
		|| (is_right_of_bc == 0))		
		return (false);
	
	return (true);
}




	/*
	int as_x = s.x - a.x;
	int as_y = s.y - a.y;

	bool s_ab = (b.x - a.x) * as_y - (b.y - a.y) * as_x > 0;

	if ((c.x - a.x) * as_y - (c.y - a.y) * as_x > 0 == s_ab) 
		return false;
	if ((c.x - b.x) * (s.y - b.y) - (c.y - b.y)*(s.x - b.x) > 0 != s_ab) 
		return false;
	return true;
	*/