#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

static char	*test(int len, int value)
{
	if (len == value)
		return ("SUCCESS");
	printf("ERROR : '%d' should be equal to '%d' !\n", len, value);
	return ("FAIL");
}

static void	putnl(void)
{
	write(1, "\n", 1);
}

static void	test_pf(int value, int ref_value)
{
	putnl();
	if (value != ref_value)
		printf("FAIL! : %d should be %d !\n", value, ref_value);
	else
		ft_printf("SUCCESS!");
	putnl();
}

int	main(void)
{
	/* Tests without bonuses */

	/* Without specifier tests */

	int len;
	int	pf_len;

	ft_printf("/*** TEST WITHOUT SPECIFIERS ***/\n");
	len = ft_printf("");
	printf("Len of empty string : %s\n", test(len, 0));
	
	len = ft_printf("Yo");
	printf("\nTwo characters string : %s\n", test(len, 2));
	
	len = ft_printf("gnpogpwpogjwjgwjegwjgpog");
	printf("\nLen of random string (must be 24) : %s\n", test(len, 24));

	len = ft_printf("%%");
	printf("\nLen of just '%%' : %s\n", test(len, 1));

	len = ft_printf("Avec tiret : %+5  ", 48);
	putnl();
	ft_putstr("Lengths should be 13 : ");
	ft_putstr(test(len, 13));
	putnl();
	len = ft_printf("Sans tiret : %5  ", 48);
	ft_putstr(test(len, 13));
	putnl();
	len = ft_printf("Sans tiret : %-5-d  ", 48);
	ft_putstr(test(len, 13));
	putnl();
	len = ft_printf("Sans tiret : %5.5-d  ", 48);
	ft_putstr(test(len, 13));
	putnl();
	len = ft_printf("Sans tiret : % % ", 48);
	ft_putstr(test(len, 15));
	putnl();
	len = ft_printf("Sans tiret : %  ", 48);
	ft_putstr(test(len, 13));
	putnl();

	putnl();
	ft_printf("/*** TEST WITH SPECIFIERS ***/\n");
	ft_printf("/* SPECIFIER : '%%c' */\n");

	pf_len = printf("%c", 48);
	len = ft_printf("%c", 48);
	ft_putstr(test(len, pf_len));
	putnl();

	pf_len = printf("%c", 0);
	len = ft_printf("%c", 0);
	ft_putstr(test(len, pf_len));
	putnl();

	pf_len = printf("%c", -1);
	len = ft_printf("%c", -1);
	ft_putstr(test(len, pf_len));
	putnl();

	pf_len = printf("%c", 256);
	len = ft_printf("%c", 256);
	ft_putstr(test(len, pf_len));
	putnl();

	pf_len = printf("%c", -256);
	len = ft_printf("%c", -256);
	ft_putstr(test(len, pf_len));
	putnl();
	
	len = ft_printf("%-3cq", 48);
	putnl();
	ft_putstr(test(len, 4));
	putnl();
	len = ft_printf("%3c", 48);
	putnl();
	ft_putstr(test(len, 3));
	putnl();
	len = ft_printf("%#c", 48);
	putnl();
	ft_putstr(test(len, 1));
	putnl();
	len = ft_printf("%03c", 48);
	putnl();
	ft_putstr(test(len, 3));
	putnl();
	putnl();

	ft_printf("/* SPECIFIER : '%%s' */\n");

	test_pf(ft_printf("%s", ""), 0);
	test_pf(ft_printf("%s", "Hello World"), 11);
	test_pf(ft_printf("%34s", "Hello World"), 34);
	test_pf(ft_printf("%-s", "Hello World"), 11);
	test_pf(ft_printf("%-12s", "Hello World"), 12);
	test_pf(ft_printf("%#s", "Hello World"), 11);
	test_pf(ft_printf("%#.7s", "Hello World"), 7);

	ft_printf("/* SPECIFIER : '%%p' */");
	putnl();

	test_pf(ft_printf("%p", &len), 11);
	test_pf(ft_printf("%.p", NULL), 2);
	test_pf(ft_printf("%p", NULL), 3);
	test_pf(ft_printf("%10p", &len), 11);
	test_pf(ft_printf("%-10p", &len), 11);
	test_pf(ft_printf("%.5p", &len), 11);
	test_pf(ft_printf("%13.11p", &len), 13);
	test_pf(ft_printf("%*.3p", 13, &len), 13);
	
	ft_printf("/* SPECIFIER : '%%d && %%i' */");
	putnl();

	test_pf(ft_printf("%d", 34554), 5);
	test_pf(ft_printf("%.d", 0), 0);
	test_pf(ft_printf("%d", 0), 1);
	test_pf(ft_printf("%+d", 45), 3);
	test_pf(ft_printf("%+d", -64), 3);
	test_pf(ft_printf("%10d", 345), 10);
	test_pf(ft_printf("%-10d", 345), 10);
	test_pf(ft_printf("%.5d", 345), 5);
	test_pf(ft_printf("%13.34d", 1234556), 34);
	test_pf(ft_printf("%*.3d", 13, 12), 13);
	
	ft_printf("/* SPECIFIER : '%%u' */");
	putnl();

	test_pf(ft_printf("%u", 34554), 5);
	test_pf(ft_printf("%.u", 0), 0);
	test_pf(ft_printf("%u", 0), 1);
	test_pf(ft_printf("%+u", 45), 2);
	test_pf(ft_printf("%+u", -64), 10);
	test_pf(ft_printf("%10u", 345), 10);
	test_pf(ft_printf("%-10u", 345), 10);
	test_pf(ft_printf("%.5u", 345), 5);
	test_pf(ft_printf("%13.34u", 1234556), 34);
	test_pf(ft_printf("%*.3u", 13, 12), 13);

	ft_printf("/* SPECIFIER : '%%x && %%X' */");
	putnl();

	test_pf(ft_printf("%x", 34554), 4);
	test_pf(ft_printf("%.x", 0), 0);
	test_pf(ft_printf("%x", 0), 1);
	test_pf(ft_printf("%+x", 45), 2);
	test_pf(ft_printf("%+x", -64), 8);
	test_pf(ft_printf("%10x", 345), 10);
	test_pf(ft_printf("%-10x", 345), 10);
	test_pf(ft_printf("%.5x", 345), 5);
	test_pf(ft_printf("%13.34x", 1234556), 34);
	test_pf(ft_printf("%*.3x", 13, 12), 13);
	
	ft_printf("%u\n", ft_printf("%1.d\n", 0));
	ft_printf("%u\n", printf("%1.d\n", 0));

	return (0);
}
