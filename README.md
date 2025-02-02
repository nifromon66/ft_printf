
# FT_PRINTF

By nifromon (Nicolas Fromont), student at 42 perpignan, France.
> ---
>
> ## DESCRIPTION
>
> This project goal of this project is quite simple : replicate the printf function. In a nutshell, printf is a command of the {stdio.h} library used to display a **formatted** string on the standard output (terminal).
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
> This is the new concept introduced to us trough this project aside from the really usefull function that is ft_printf : Variadic functions. As it name implies a variadic function is a function that can take a variable number of arguments, which is characterized by the '...' parameter in the function signature.
>
> What drasticly change from the functions we previously created is that we do not know in advance what those arguments will be 🤷‍♂️ but one which is mandatory, you can't have the '...' parameter alone.
>
> To use this new feature you will have to use the {stdarg.h} library which will allow us to use a new type of variable : **va_list**, and 4 very usefull macros : **va_start**, **va_arg**, **va_copy** and **va_end**.
>
> - **va_list** (new object type) : **va_list** is an object type suitable for holding the information needed by the macros **va_start**, **va_copy**, **va_arg** and **va_end**. In other words, it is a list that will contain all the dynamic arguments.
> - **va_start** (function macro) : **va_start** is a function macro that will initialize everything in our **va_list** variable. It's purpose is to set the stage and define which elements will be stable and which will vary. This is when our **va_list** variable will have all the elements in the table. **va_start** must be called before any use of **va_arg** otherwise our **va_list** will be empty.
> - **va_arg** (function macro) : **va_arg** is a function macro that will allow us to access to the arguments of the variadic function. Each time **va_arg** is called, we move to the next argument in the **va_list**. **va_arg** will take as argument first the list of dynamic arguments we had defined at the very beginning and the **type** of the variable of the next argument.
> - **va_copy** (function macro) : **va_copy** is a function macro that is used to copy the state of a **va_list** variable to another. It is particularly usefull when we need to iterate over the same list of variadic arguments multiple times or when we want to pass the argument list to another function without modifying the original.
> - **va_end** (function macro) : **va_end** is a function macro used to clean up properly the object we initialized by calling **va_star** or **va_copy**, **va_end** will free the allocated memory.
>
> ---
>