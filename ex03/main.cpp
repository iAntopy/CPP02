/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:41:35 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/20 23:46:04 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

static void	single_bsp_test(int i, bool expected, Point const& a,
				Point const& b, Point const& c, Point const& probe)
{
	bool	is_inside = bsp(a, b, c, probe);

	std::cout << std::boolalpha;
	std::cout << "	test probe " << i << " : " << probe << std::endl;
	std::cout << "	BSP test : " << is_inside << std::endl; 
	std::cout << "	Expected : " << expected << std::endl << std::endl;
	std::cout << std::noboolalpha;
}

void	triangle_test_1(void)
{
	Point	a(0.0f, 0.0f);
	Point	b(4.0f, 3.0f);
	Point	c(4.0f, 0.0f);

	std::cout << "TRIANGLE 1 ABC : " << a << b << c << std::endl;
	single_bsp_test(1, false, a, b, c, Point(0.0f, 0.0f));
	single_bsp_test(2, false, a, b, c, Point(100.0f, 100.0f));
	single_bsp_test(3, true, a, b, c, Point(3.0f, 2.0f));
}

void	triangle_test_2(void)
{
	Point	a(-1.0f, 0.0f);
	Point	b(-5.0f, 2.5f);
	Point	c(-5.0f, -2.5f);

	std::cout << "TRIANGLE 2 ABC : " << a << b << c << std::endl;
	single_bsp_test(1, false, a, b, c, Point(0.0f, 0.0f));
	single_bsp_test(2, false, a, b, c, Point(-1.0f, 0.0f));
	single_bsp_test(3, true, a, b, c, Point(-4.0f, 1.0f));
}

void	triangle_test_3(void)
{
	Point	a(0.0f, 0.0f);
	Point	b(5.0f, 5.0f);
	Point	c(5.0f, 0.0f);

	std::cout << "TRIANGLE 3 ABC : " << a << b << c << std::endl;
	single_bsp_test(1, false, a, b, c, Point(1.0f, 1.0f));
	single_bsp_test(2, false, a, b, c, Point(0.99f, 1.0f));
	single_bsp_test(3, true, a, b, c, Point(1.01f, 1.0f));
}

void	draw_bsp_canvas(Point const& a, Point const& b, Point const& c)
{
	const int	width = 60;
	const int	height = 30;
	Point		pxl;

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			pxl = Point(x * 1.0f, y * 2.0f);
//			std::cout << "x : " << x << " y : " << y << " px : " << px << std::endl;
			if (bsp(a, b, c, pxl))
				std::cout << "#";
			else
				std::cout << ".";
		}
		std::cout << std::endl;
	}
}

int main( void )
{
	Point	a(2.0f, 2.0f);
	Point	b(65.0f, 2.0f);
	Point	c(2.0f, 65.0f);
//	triangle_test_1();
//	triangle_test_2();
//	triangle_test_3();
	std::cout << "Displaying triangle abc -> a : (" << a.getX() << ", " << a.getY() << ") "
		<< "b : (" << b.getX() << ", " << b.getY() << ") "
		<< "c : (" << c.getX() << ", " << c.getY() << ") " << std::endl;
	draw_bsp_canvas(a, b, c);
	return (0);
}
