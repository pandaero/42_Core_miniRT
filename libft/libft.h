/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:26:47 by pandalaf          #+#    #+#             */
/*   Updated: 2022/06/03 11:18:40 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif
# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//Function determines whether input character is alphabetic.
int				ft_isalpha(int ch);
//Function takes a lowercase letter character and makes it an uppercase letter.
int				ft_toupper(int ch);
//Function determines whether input character is a digit.
int				ft_isdigit(int ch);
//Function takes an uppercase letter character and makes it a lowercase letter.
int				ft_tolower(int ch);
//Function determinse whether input character is alphanumeric.
int				ft_isalnum(int ch);
//Function determines whether input is in the standard ASCII table.
int				ft_isascii(int ch);
//Function determines whether input is a printing character.
int				ft_isprint(int ch);
//Function determines length of the character string.
size_t			ft_strlen(const char *str);
//Function looks for a character within a character string pointer.
char			*ft_strchr(const char *str, int ch);
//Function looks for the last instance of a character within a string pointer.
char			*ft_strrchr(const char *str, int ch);
//Function compares two strings, gives difference when not equal.
int				ft_strncmp(const char *str1, const char *str2, size_t n);
//Function writes a value to a determined length of bytes to a memory location.
void			*ft_memset(void *byte, int ch, size_t n);
//Function sets determined length of memory in a memory location to zero.
void			ft_bzero(void *str, size_t len);
//Function locates the first instance of a character within n bytes of a string.
void			*ft_memchr(const void *str, int ch, size_t n);
//Function compares two memory strings for equality within n bytes of a string.
int				ft_memcmp(const void *str1, const void *str2, size_t n);
//Function copies n bytes (char 8-bits) from a string to a different string.
void			*ft_memcpy(void *dst, const void *src, size_t n);
//Function moves n bytes (char 8-bits) from source string to dest string.
void			*ft_memmove(void *dst, const void *src, size_t n);
//Function writes to n bytes of a char string from a source to a destination.
size_t			ft_strlcpy(char *dst, const char *src, size_t sizedst);
//Function appends n bytes of a source character string to a destination string.
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
//Function locates string within n in another string. Returns ptr to location.
char			*ft_strnstr(const char *srch, const char *term, size_t srlen);
//Function interprets a character string to return an integer type.
int				ft_atoi(const char *str);
//Function allocates memory for a number of objects of a certain size in bytes.
void			*ft_calloc(size_t count, size_t size);
//Function duplicates a string to a new memory location.
char			*ft_strdup(const char *str);
//Function creates new character string from another character string's content.
char			*ft_substr(char const *s, unsigned int start, size_t len);
//Function concatenates two character strings, creates a new char string.
char			*ft_strjoin(char const *s1, char const *s2);
//Function creates a new char string with chars from the input removed.
char			*ft_strtrim(char const *s1, char const *set);
//Function finds number of "words" in string between a set delimiter character.
unsigned int	ft_nwrds(const char *str, unsigned char ch);
//Function splits a char string into char strings between delimeter chars.
char			**ft_split(char const *str, char ch);
//Function writes an integer value to a character string.
char			*ft_itoa(int n);
//Function maps a function to an input character string.
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
//Function applies another function to the entered string.
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
//Function writes character to input file descriptor.
void			ft_putchar_fd(char c, int fd);
//Function writes a string to the input file descriptor.
void			ft_putstr_fd(char *s, int fd);
//Function writes a string to the input file descriptor and an end-of-line char.
void			ft_putendl_fd(char *s, int fd);
//Function writes an integer as character to the input file descriptor.
void			ft_putnbr_fd(int n, int fd);
//Function creates a new node in the linked list.
t_list			*ft_lstnew(void *content);
//Function sets a new node to the beginning of a linked list.
void			ft_lstadd_front(t_list **lst, t_list *newnd);
//Function determines the number of nodes in the linked list.
int				ft_lstsize(t_list *lst);
//Function finds the last node of the linked list.
t_list			*ft_lstlast(t_list *lst);
//Function sets a new node to the end of a linked list.
void			ft_lstadd_back(t_list **lst, t_list *newnd);
//Function deletes a node from a linked list.
void			ft_lstdelone(t_list *lst, void (*del)(void *));
//Function clears an entire linked list.
void			ft_lstclear(t_list **lst, void (*del)(void *));
//Function applies a function to each of the linked list's nodes.
void			ft_lstiter(t_list *lst, void (*f)(void *));
//Function maps a function to every node's content in a linked list.
t_list			*ft_lstmap(t_list *lt, void *(*f)(void *), void (*del)(void *));
//Function prints out a formatted string based on inputs. Returns written chars.
int				ft_printf(const char *format, ...);
//Function prints out a character to the standard output. Returns written count.
int				ft_print_char(char ch);
//Function prints an integer to standard output, unformatted. Returns written.
int				ft_print_int(int num);
//Function prints an unsigned integer to standard output, unformatted.
int				ft_print_unsigned(unsigned int num);
//Function prints out a hexadecimal number to the standard output. Case option.
int				ft_print_hex(unsigned int num, int cas);
//Function prints out a hexadecimal number to the standard output. Case option.
int				ft_print_hex_long(unsigned long long num, int cas);
//Function prints an pointer address to standard output, unformatted.
int				ft_print_ptr(void *ptr);
//Function prints a char string to standard output, unformatted.
int				ft_print_str(const char *str);
//Function prints a hexadecimal prefix to the standard output.
int				hex_prefix_printer(int cas);
//Function identifies the format types. Returns 1 or 0.
int				type_checker(char ch);
//Function that outputs lines from a given file descriptor.
char			*get_next_line(int fd);
//Function reads a type specifier after a determined starting location.
char			type_reader(const char *string, int start);
//Function searches for char and returns first location. 0 not found. 1 is 1st.
int				ft_strsrch(char *str, int ch);
//Function joins two character strings, creates a new char string. Mod: Free s1.
char			*ft_strjoinmod(char *s1, char *s2);
//Function joins the initial string with reads from a descriptor until newline.
char			*joining(int fd, char *initial);
//Function trims the input string such that contents after newline are cut.
char			*output(char *candidate);
//Function takes input string and returns contents after the first newline.
char			*remaining(char *candidate);
#endif
