/*
 * Copyright (C) 2013 Davidlohr Bueso <davidlohr.bueso@hp.com>
 *
 *  Based on the shift-and-subtract algorithm for computing integer
 *  square root from Guy L. Steele.
 */

#include <linux/kernel.h>
#include <linux/export.h>

/**
 * int_sqrt - rough approximation to sqrt
 * @x: integer of which to calculate the sqrt
 *
 * A very rough approximation to the sqrt() function.
 */
inline unsigned long int_sqrt(unsigned long x)
{
<<<<<<< HEAD
	unsigned long b, m, y = 0;
=======
	register unsigned long tmp;
	register unsigned long place;
	register unsigned long root = 0;
>>>>>>> 54da30c... int_sqrt: Improve 3x faster integer sqrt.

	if (x <= 1)
		return x;

<<<<<<< HEAD
	m = 1UL << (BITS_PER_LONG - 2);
	while (m != 0) {
		b = y + m;
		y >>= 1;

		if (x >= b) {
			x -= b;
			y += m;
		}
		m >>= 2;
	}
=======
	place = 1UL << (BITS_PER_LONG - 2);

	do{
		place >>= 2;
	}while(place > x);

	do {
		tmp = root + place;
		root >>= 1;

		if (x >= tmp)
		{
			x -= tmp;
			root += place;
		}
		place >>= 2;
	}while (place != 0);
>>>>>>> 54da30c... int_sqrt: Improve 3x faster integer sqrt.

	return y;
}
EXPORT_SYMBOL(int_sqrt);
