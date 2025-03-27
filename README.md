
# FT_PRINTF

By nifromon (Nicolas Fromont), student at 42 perpignan, France.

> ## DESCRIPTION
> - This project goal of this project is quite simple : replicate the printf() function. In a nutshell, printf is a command of the {stdio.h} library used to display a **formatted** string on the standard output (terminal).
> - What i mean by **formatted** is that the format specifiers beginning by `%` character indicate the location and the method of convertion of a data element (such as a number) into printable characters.
>
> ---
> ## INSTRUCTIONS
>
> - Program name : libftprintf.a
> - Prototype : `int    ft_printf(const char *, ...);`
> - Requirements :
> 	- Do not implement the original printf()'s buffer management.
> 	- Your implementation will be evaluated against the behavior of the original printf().
> 	- "libftprintf.a" must be created at the root of the repository
> - Files to return :
>   - Mandatory :
>     - [Makefile](ft_printf/Makefile)
>     - [ft_printf.h](ft_printf/mandatory/headers/ft_printf.h)
>     - **`*.c`**
>   - Bonus :
>     - [ft_printf_bonus.h](ft_printf/bonus/headers_bonus/ft_printf_bonus.h)
>     - **`*_bonus.c`**
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
>## Mandatory
> - Your function have to handle the following conversions :
> 	- **[%c] :** The given argument of type `int` is converted into one `unsigned char`, and the corresponding character is displayed.
> 	- **[%s] :** The given argument of type `const char *` which is assumed to be a pointer to an array of characters (pointer to a string). The characters in the array are written down to the final null byte `\0`.
> 	- **[%p] :** The given argument of type `void *` is displayed in hexadecimal as with `%#x`.
> 	- **[%d] | [%i] :** The given argument of type `int` is converted to a signed decimal digit and displayed.
> 	- **[%u] :** The given argument of type `unsigned int` is converted to an unsigned decimal digit and displayed.
> 	- **[%x] | [%X] :** The given argument of type `unsigned int` is converted to an unsigned hexadecimal digit. Either `0123456789abcdef` for `x` or `0123456789ABCDEF` for `X`.
> 	- **[%%] :** A `%` character is displayed, there is no conversion.
> 	### Functions
> 	- **ftpf_check_type :** 
> 		- Prototype : `int    ftpf_check_type(char c);`
> 		- Description : Checks if the character correspond to any of the conversion specifier handled.
> 		- Return Value : return `1` if it found a valid conversion specifier and `0` if not.
> 	- **ftpf_check_spec :** 
> 		- Prototype : `int    ftpf_check_spec(const char *s);`
> 		- Description : Checks if any character in the `s` string correspond to any of the conversion specifier (call to function `ftpf_check_type`).
> 		- Return Value : return `1` if it found any valid conversion specifier and `0` if not.
> 	- **ftpf_init_struct :** 
> 		- Prototype : `t_ft_printf *ftpf_init_struct(void);`
> 		- Description : Init the structure for the  current conversion and put each variable of the structure to it's value of initialisation (mostly `0` or `-1`).
> 		- Return Value : Return a pointer to the created structure or `NULL` if `malloc()` failed.
> 	- **ftpf_fetch_type :** 
> 		- Prototype : `int ftpf_fetch_type(const char *format);`
> 		- Description : Fetch the conversion specifier from `format` string.
> 		- Return Value : Return the value corresponding to the conversion specifier fetched (Value of an `enum`).
> 	- **ftpf_format_\* :** 
> 		- Prototype : `void    ftpf_format_*(t_ft_printf *format, va_list arg);`
> 		- Description : Replace `*` with each of the handled specifier. It convert value found in `va_list` and then display it.
> 		- Return Value : None.
> 	- **ftpf_dispatching :** 
> 		- Prototype : `void    ftpf_dispatching(int type, t_ft_printf *format, va_list arg);`
> 		- Description : This is a dispatch table function which call a function dynamically depending on the `type`(`specifier`) and passing as parameters of the function (`ftpf_format_*`) : `format` and `arg`.
> 		- Return Value : None.
> 	- **ftpf_parsing :** 
> 		- Prototype : `int ftpf_parsing(const char *format, va_list arg);`
> 		- Description : Init a structure with `ftpf_init_struct` then fetch the specifier with `ftpf_fetch_type` and then dispatch to the corresponding function with `ftpf_dispatching`.
> 		- Return Value : Return the number of characters printed.
> ---
> ## Bonus
> - Your function have to handle the following flags :
> 	- **[Field Width] :** An optional number that does not start with a zero can indicate a minimum field width. If the converted value occupies fewer characters than this width, it will be supplemented with spaces on the left (or the right if `-` flag is provided). A negative width is considered a `-` flag followed by a width.
> 		- Ignored if :
> 			- `%%`.
> 	- **[-] :** Indicates that the value must be justified on the left boundary of the field (by default on the right). The values are supplemented by blanks on the right.
> 		- Ignored if :
> 			- `%%`.
> 	- **[0] :** Indicates filling with zeros. The value is completed on the left with zeros rather than with spaces by default.
> 		- Ignored if :
> 			- `-` is defined.
> 			- `.` is defined for `%d`, `%i`, `%u`, `%x`, `%X`.
> 			- `%c`, `%s`, `%%`.
> 	- **[.] :** Indicates a minimum number of digits to be displayed during `%d`, `%i`, `%u`, `%x`, `%X` conversions and the maximum number of characters to be printed from a string during `%s` conversions.
> 		- Ignored if :
> 			- `%c`, `%%`.
> 	- **[#] :** Indicates that the value must be converted to another form. For conversions `%x` and `%X`, a non-zero value receive the prefix `0x` (`%x`) or `0X`(`%X`).
> 		- Ignored if :
> 			- `%c`, `%s`, `%d`, `%i`, `%u`, `%p`, `%%`.
> 	- **[ ] :** (A space) Indicates that a space must be left before a positive number (or an empty string) produced by a signed conversion.
> 		- Ignored if :
> 			- `+` is defined.
> 			- `%c`, `%s`, `%u`, `%x`, `%X`, `%p`, `%%`.
> 	- **[+] :** Indicates that a sign (`+` or `-`) must always be printed before a number produced by a signed conversion. By default a sign is only used for negative values.
> 		- Ignored if :
> 			- `%c`, `%s`, `%u`, `%x`, `%X`, `%p`, `%%`.
> 	- **[\*] | [\*n\$]:** Indicates that the `Field width` or `.` is provided in the following arguments (if `*`) or the n-th argument (if `*n$`, with `n` representing a `int`).
> 		- Ignored if : None.
> 	 ### Functions
> 	- **ftpf_format_\* :** Were modified to handle all bonus flags.
> 	- **ftpf_get_index_arg :** 
> 		- Prototype : `int ftpf_get_index_arg(int idx, const char *format);`
> 		- Description : Get the index in `va_list` of the arguments to define either `Field width` or `.` using `*n$` form.
> 		- Return Value : Index of the needed argument or `-1` if failed.
> 	- **ftpf_nth_star :** 
> 		- Prototype : `int ftpf_nth_star(int idx, const char *format, t_ft_printf **flags, va_list arg);`
> 		- Description : Set either `Field width` or `.` to the corresponding argument specified with `*n$`.
> 		- Return Value : Return `0` on success and `-1` on failure.
> 	- **ftpf_star_manager :** 
> 		- Prototype : `void    ftpf_star_manager(const char *format, t_ft_printf **flags, va_list arg);`
> 		- Description : Set either `Field width` or `.` to the corresponding argument specified with either `*` or `*n$` form.
> 		- Return Value : None.
> 	- **ftpf_sort_flags_spec :** 
> 		- Prototype : `void    ftpf_sort_flags_manager(t_ft_printf **flags, int spec);`
> 		- Description : Sort the flags depending on the conversion specifier used.
> 		- Return Value : None.
> 	- **ftpf_sort_flags_manager :** 
> 		- Prototype : `void    ftpf_sort_flags_manager(t_ft_printf **flags);`
> 		- Description : Call `ftpf_sort_flags_spec` then sort the flags depending on the other flags set.
> 		- Return Value : None.
> 	- **ftpf_fetch_width :** 
> 		- Prototype : `int ftpf_fetch_width(const char *format, int index);`
> 		- Description : Fetch the `Field width` from the `format` string starting from `index`.
> 		- Return Value : `Field width`.
> 	- **ftpf_fetch_precision :** 
> 		- Prototype : `int ftpf_fetch_precision(const char *format, int index);`
> 		- Description : Fetch the `.` from the `format` string starting from `index`.
> 		- Return Value : `.` (precision).
> 	- **ftpf_fetch_flags :** 
> 		- Prototype : `void    ftpf_fetch_flags(const char *format, t_ft_printf **flags);`
> 		- Description : Fetch the different flags contained in the `format` string and then call `ftpf_sort_flags_manager` to sort them.
> 		- Return Value : None.
> 	- **ftpf_fetch_flags :** 
> 		- Prototype : `void    ftpf_fetch_flags(const char *format, t_ft_printf **flags);`
> 		- Description : Fetch the different flags contained in the `format` string and then call `ftpf_sort_flags_manager` to sort them.
> 		- Return Value : None.
> ---

