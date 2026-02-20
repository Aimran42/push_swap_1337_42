/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momahdam <momahdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 11:26:55 by momahdam          #+#    #+#             */
/*   Updated: 2026/02/10 01:34:45 by momahdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H

# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct stack_list
{
	int					nbr;
	int					index;
	struct stack_list	*next;
}						t_stack;

# define INT__MIN -2147483648
# define INT__MAXX 2147483647

// parsing helpers
int						ft_strlen(char *str);
long					ft_atoi(const char *str);
char					*ft_strjoin(char *s1, char *s2);
char					*ft_strdup(char *s1);
char					**ft_split(char *s, char c);
int						is_empty(int ac, char **av);

// parsing functions
int						ft_parse_args(int ac, char **av, char ***tab);

char					*join_args(int ac, char **av);
void					free_array(char **tab, int i);
int						words(char *str, char c);
void					ft_clean_exit(char *s, char **tab);

int						check_arr_numbers(char **array);
int						check_overflow(char **array);
int						check_duplicated_number(char **array);
int						ft_validate_args(char **array);
void					ft_error(void);
int						is_sorted(t_stack *head);

// libft linked list
t_stack					*ft_stack_new(int nbr);
t_stack					*ft_lstlast(t_stack *lst);
int						ft_lstsize(t_stack *lst);
void					ft_stack_clear(t_stack **stack);
void					ft_lstadd_back(t_stack **lst, t_stack *new);

// helpers
t_stack					*ft_fill_a(char **tab);
void					ft_handle_sort(t_stack **a, t_stack **b, int count);
void					sort_small_st(t_stack **a, t_stack **b, int count);
void					get_small_to_top(t_stack **a);
int						get_small_index(t_stack *a);
int						get_max_position(t_stack *stack);

// op
void					pa(t_stack **a, t_stack **b, int print_move);
void					pb(t_stack **a, t_stack **b, int print_move);
void					ra(t_stack **a, int print_move);
void					rb(t_stack **b, int print_move);
void					sa(t_stack **a, int print_move);
void					sb(t_stack **b, int print_move);
void					ss(t_stack **a, t_stack **b);
void					rra(t_stack **a, int print_move);
void					rrb(t_stack **b, int print_move);

// chunks
void					start_algo_chunks(t_stack **a, t_stack **b);
void					return_numbers_to_a(t_stack **a, t_stack **b);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

char					*ft_handle_read(
							char **big_buffer,
							char *buffer,
							int b_read,
							int fd
							);

char					*ft_line_alloc(char *big_buf, char *buffer, int b_read);

char					*ft_extract_line(char *buff, int len);

void					ft_bzero(void *s, size_t n);

void					*ft_calloc(size_t n, size_t size);

char					*ft_strjoin_b(char *s1, char *s2);

char					*get_next_line(int fd);

size_t					ft_strlength(char *s);

void					*ft_memmove(void *dest, const void *src, size_t n);

int						ft_perform_op(char *op, t_stack **a, t_stack **b);

int						ft_error_exit(t_stack **a, t_stack **b);

#endif
