
# FT_PRINTF

By nifromon (Nicolas Fromont), student at 42 perpignan, France.
> ---
>
> ## DESCRIPTION
>
> This project goal of this project is quite simple : replicate the printf function. In a nutshell, printf is a command of the {stdio.h} library used to isplay a **formatted** string on the standard output (terminal).
>
> What i mean by formatted is that the format specifiers beginning by '%' character indicate the location and the method of convertion of a data element (such as a number) into printable characters.
>
> ---
>
> ## INSTRUCTIONS
>
> - Program name : libftprintf.a
> - Prototype : `int    ft_printf(const char *, ...);`
> - Files to return :
>   - Mandatory :
>     - [Makefile](ft_printf/Makefile)
>     - [ft_printf.h](ft_printf/mandatory/headers/ft_printf.h)
>     - [*.c](ft_printf/mandatory/src/)
>   - If bonus :
>     - [ft_printf_bonus.h](ft_printf/bonus/headers_bonus/ft_printf_bonus.h)
>     - [*_bonus.c](ft_printf/bonus/src_bonus/)
> - Allowed external functions : malloc(), free() {stdlib.h}, write {unistd.h}, va_start, va_arg, va_copy, va_end {stdarg.h}
> - Libft allowed : Yes.
>
> ---
>
> ## VARIADIC FUNCTIONS
> 