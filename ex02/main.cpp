/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:41:35 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/18 09:34:00 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) + Fixed( 2 ) );
	std::cout << "b : Fixed (5.05f) + Fixed (2) = " << b << std::endl;
	Fixed const c( Fixed( 5.05f ) - Fixed( 2 ) );
	std::cout << "c : Fixed (5.05f) - Fixed (2) = " << c << std::endl;
//	std::cout << c << std::endl;
	Fixed const d( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "d : Fixed (5.05f) * Fixed (2) = " << d << std::endl;
	Fixed const e( Fixed( 5.05f ) / Fixed( 2 ) );
	std::cout << "e : Fixed (5.05f) / Fixed (2) = " << e << std::endl;

	std::cout << "a :		" << a << std::endl;
	std::cout << "++a :		" << ++a << std::endl;
	std::cout << "a :		" << a << std::endl;
	std::cout << "a++ :		" << a++ << std::endl;
	std::cout << "a :		" << a << std::endl;
	std::cout << "d :		" << d << std::endl;

	std::cout << "a < d ->	" << a << " < " << d << "	= " << (bool)(a < d) << std::endl;
	std::cout << "a < a ->	" << a << " < " << a << "	= " << (bool)(a < a) << std::endl;
	std::cout << "a > d ->	" << a << " > " << d << "	= " << (bool)(a > d) << std::endl;
	std::cout << "a > a ->	" << a << " > " << a << "	= " << (bool)(a > a) << std::endl;
	std::cout << "a <= d ->	" << a << " <= " << d << "	= " << (bool)(a <= d) << std::endl;
	std::cout << "a <= a ->	" << a << " <= " << a << "	= " << (bool)(a <= a) << std::endl;
	std::cout << "a >= d ->	" << a << " >= " << d << "	= " << (bool)(a >= d) << std::endl;
	std::cout << "a >= a ->	" << a << " >= " << a << "	= " << (bool)(a >= a) << std::endl;
	std::cout << "a == d ->	" << a << " == " << d << "	= " << (bool)(a == d) << std::endl;
	std::cout << "a == a ->	" << a << " == " << a << "	= " << (bool)(a == a) << std::endl;
	std::cout << "a != d ->	" << a << " != " << d << "	= " << (bool)(a != d) << std::endl;
	std::cout << "a != a ->	" << a << " != " << a << "	= " << (bool)(a != a) << std::endl;

	std::cout << "max( a, d ) :	" << Fixed::max( a, d ) << std::endl;
	std::cout << "min( a, d ) :	" << Fixed::min( a, d ) << std::endl;
	return 0;
}

/*
EXPECTED RESULT : 

0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
*/
