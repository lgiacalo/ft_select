#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>
#include <termcap.h>
#include <termios.h>
#include <stdlib.h>


static void ft_putchar(char c)
{
    write(1, &c, 1);
}

static void ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}

static int		canonical_mode(struct termios *save_term)
{
	struct termios				term;
	char						buffer[2048];
	char						*name_term;

	if ((name_term = getenv("TERM")) == NULL)
	{
		ft_putstr("TERM not found\n");
		return (-1);
	}
	if (tgetent(buffer, name_term) == -1)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	*save_term = term;
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 1;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	return (0);
}

static int		non_canonical_mode(struct termios *term)
{
//	if (tcgetattr(0, term) == -1)
//		return (-1);
//	term->c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, term) == -1)
		return (-1);
	return (0);
}

static void    redraw(int nb_line)
{
    while (nb_line-- > 0)
	    ft_putstr("\e[1A"); // monte de une ligne par iteration
	ft_putchar('\r');       // se positionne en debut de ligne
	ft_putstr(tgetstr("cd", NULL));      // clear la fenetre
}

static int		len_max_str(char **argv)
{
	int i;
	int space;
	size_t len_max;

	i = 0;
	space = 1;
	len_max = 0;
	while(argv[i])
	{
		if (len_max < strlen(argv[i]))
			len_max = strlen(argv[i]) + space;
		i++;
	}
    return (len_max);
}

static void draw_tab(char *str, int len_max, int cursor, int index)
{
    int len;

    len = len_max - strlen(str);
    if (cursor == index)
    {
        ft_putstr("\e[48;5;88m");
        ft_putstr(str);
        ft_putstr("\e[0m");
    }
    else
        ft_putstr(str);
    while (len-- > 0)
        ft_putchar(' ');
    
}

static int    print_tab_and_cursor(int argc, char **argv, int cursor)
{
    int i;
    int nb_line;
    int tmp;
    struct winsize w;
    int nb_arg_per_line;    

    i = 1;
    ioctl(0, TIOCGWINSZ, &w);
    nb_arg_per_line = w.ws_col / len_max_str(argv);  //w.ws_col = largeur du terminal en colonne
    nb_line = argc / nb_arg_per_line + 1; 
    tmp = nb_arg_per_line;
    while (argv[i])
    {
        while(tmp > 0 && i < argc - 1)
        {
			tmp--;
            draw_tab(argv[i], len_max_str(argv), cursor, i);
            i++;
        }
        ft_putchar('\n');
        tmp = nb_arg_per_line;
        i++;
    }
    return (nb_line);
}

int main(int argc, char **argv)
{
    int cursor;
    int nb_line;
    long int key;
    struct termios save_term;

    nb_line = 0;
    cursor = 1;
    if (argc > 1)
    {
        if (canonical_mode(&save_term) == -1)
            return (-1);
        ft_putstr(tgetstr("vi", NULL)); // enleve le curseur
        while(key != 27)
        {
            key = 0;
            (nb_line > 0) ? redraw(nb_line) : 0;
            nb_line = print_tab_and_cursor(argc, argv, cursor);         
            read(0, &key, sizeof(long));
            if (key == 10)
                cursor++;
            if (cursor == argc - 1)
                cursor = 1;
        }
        ft_putstr(tgetstr("ve", NULL)); // remet le curseur
        if (non_canonical_mode(&save_term) == -1)
		    return (-1);
    }
    else
        printf("too few arguments\n");
    return (0);
}
