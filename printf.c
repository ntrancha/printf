/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 11:44:14 by ntrancha          #+#    #+#             */
/*   Updated: 2014/12/26 11:44:14 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

typedef struct		s_print
{
	char			*format;
	int				param;
	int				moins;
	int				plus;
	int				space;
	int				sharp;
	int				n;
	int				dot;
	int				h;
	int				l;
	int				nbr;
	int				nbr2;
	int				L;
}					t_print;

void	ft_printf(char *format, ...)
{
	va_list	pa;
	t_print	flags;
	int		index;
	int		test;
	char	*s;
	char	c;
	int		n;

	va_start(pa, format);
	test = 0;
	index = 0;
	while (format[index])
	{
		if (test == 0 && format[index] == '%')
			test = 1;
		else if (test == 1 && ft_cinstr(" -+#", format[index]) != 0)
			ft_putstr("flag");
		else if (test == 1 && ft_cinstr("n*", format[index]) != 0)
			ft_putstr("largeur");
		else if (test == 1 && ft_cinstr(".", format[index]) != 0)
			ft_putstr("Précision");
		else if (test == 1 && ft_cinstr("hlLqjzt", format[index]) != 0)
			ft_putstr("modif");
		else if (test == 1 && ft_cinstr("diouxXfFaAeEgGcspCSPm%", format[index]) != 0)
		{
			switch(format[index])
			{
				case '%' :
					putchar('%');
					break;
  			    case 'c' : /* affichage d'un caractère */
                   c = va_arg(pa, int);
                   ft_putchar(c);
                   break;
				case 'd' : /* affichage d'un entier */
                   n = va_arg(pa, int);
                   ft_putnbr(n);
                   break;
				case 's' : /* affichage d'une chaîne */
                   s = va_arg(pa, char *);
					ft_putstr(s);
                   break;
			}
			test = 0;
		}
		else if (test == 0)
			ft_putchar(format[index]);
		index++;
	}
	va_end(pa);
}

void myprintf(char *format, ...) {
  va_list pa;
  int n;
  char *s, c;
  float f;
  
  va_start(pa, format);
  while (*format != '\0') {
    if ( *format == '%' ) {
      switch (*++format) {
        case '%' : putchar('%'); break;
        case 'c' : /* affichage d'un caractère */ 
                   c = va_arg(pa, int);
                   putchar(c);
                   break;
        case 'd' : /* affichage d'un entier */ 
                   n = va_arg(pa, int);
                   printf("%d", n); 
                   break;
        case 'f' : /* affichage d'un float */ 
                   f = va_arg(pa, double);    /* !!!!! */
                   printf("%f", f); 
                   break;
        case 's' : /* affichage d'une chaîne */ 
                   s = va_arg(pa, char *);
                   for ( ; *s != '\0'; s++ ) 
                     putchar( *s );
                   break;
      } /* end switch */
    }
    else 
      putchar( *format );
    format++;
  }   
  va_end(pa);
} 

int			main()
{
  ft_printf("float = %f\n", (float) 1.2345);
  ft_printf("int = %d   char = %c   Chaine = %s\n", 123, 'A', "C is beautiful !\n" );
  return 0;
}
