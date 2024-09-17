#ifndef QUIZZ_H
# define QUIZZ_H

#include <stdio.h>
#include "time.h"
#include <stdlib.h>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

// Enum and struct declarations
typedef enum e_quizz_lvl
{
    easy_lvl = 1,
	medium_lvl,
	hard_lvl,
	mix_of_lvls
} t_e_quizz_lvl;

typedef enum e_operation_type
{
	addition = 1,
	subtraction,
	multiplication,
	division,
	mix_of_operations
} t_e_operation_type;

typedef enum e_pass_or_fail
{
	pass = 1,
	fail
} t_e_pass_or_fail;

typedef struct s_question 
{
	short	nbr_1;
	short	nbr_2;
	short	question_answer;
	short	user_answer;
	t_e_operation_type	e_question_operation_type;
	t_e_pass_or_fail	e_question_passing;
} t_s_question;

typedef struct s_quizz {
	short	nbr_of_quizz_questions;
	short	nbr_of_correct_answers;
	short	nbr_of_wrong_answers;
	t_e_operation_type	e_quizz_operation_type;
	t_e_quizz_lvl	e_quizz_lvl;
	t_e_pass_or_fail	e_quizz_passing;
	t_s_question	*p_s_question;
} t_s_quizz;




// Function declarations
void    ft_start_questions(t_s_quizz   *p_s_quizz);
short   ft_calculate_question_answer (t_s_question *p_s_question, t_e_operation_type e_quizz_operation_type);
void    ft_display_question(t_s_question    *p_s_question, t_e_operation_type  e_quizz_operation_type);
char  ft_get_operation_symbol(t_e_operation_type  e_quizz_operation_type);
short   ft_read_user_answer();
t_e_pass_or_fail    ft_get_question_pass_or_fail_result(short question_answer, short user_answer);
const char  *ft_get_str_question_result(t_e_pass_or_fail e_pass_or_fail);
void    ft_winning_losing_colors_effect(t_e_pass_or_fail e_pass_or_fail);
void	ft_display_question_header(t_s_quizz *p_s_quizz, short current_question_nbr);
void    ft_update_quizz_results_after_every_question(t_s_quizz *p_s_quizz, t_e_pass_or_fail e_pass_or_fail);
void    ft_display_right_answer(short right_answer, t_e_pass_or_fail e_pass_or_fail);
t_s_question    ft_generate_1_question(t_s_quizz   *p_s_quizz);
void    ft_start_quizz();
void    ft_set_s_quizz_initial_values(t_s_quizz *p_s_quizz);
t_e_quizz_lvl   ft_e_read_quiz_lvl();
t_e_operation_type  ft_e_read_quiz_questions_operations();
t_e_pass_or_fail    ft_e_get_quizz_result(short nbr_of_correct_answers, short nbr_of_wrong_answers);
const char  *ft_get_str_quiz_result(t_e_pass_or_fail e_pass_or_fail);
void    ft_print_quiz_result_header(t_e_pass_or_fail e_pass_or_fail);
void    ft_print_quizz_results(t_s_quizz *p_s_quizz);
const char  *ft_get_lvl_str(t_e_quizz_lvl e_quizz_lvl);
const char  *ft_get_operations_types_str(t_e_operation_type e_quizz_operation_type);



int ft_i_read_nbr(char *speak);
char    *ft_read_str();
double  ft_d_read_nbr(char *speak);
int ft_i_read_ranged_nbr(char *tell ,int min, int max);
char*   ft_put_tabs(short num);
int ft_p_generate_random_nbr_in_range(int from, int to);
#endif // GAME_H

