#include "quizz.h"

void	ft_start_questions(t_s_quizz   *p_s_quizz)
{
	short	c;

	c = -1;
	while (++c < p_s_quizz->nbr_of_quizz_questions)
	{
		printf("%s", RESET);
		ft_display_question_header(p_s_quizz, c);
		p_s_quizz->p_s_question[c] = ft_generate_1_question(p_s_quizz);
		ft_display_question(&p_s_quizz->p_s_question[c], p_s_quizz->p_s_question[c].e_question_operation_type);
		p_s_quizz->p_s_question[c].user_answer = ft_read_user_answer();
		p_s_quizz->p_s_question[c].e_question_passing = ft_get_question_pass_or_fail_result(p_s_quizz->p_s_question[c].question_answer, p_s_quizz->p_s_question[c].user_answer);
		ft_winning_losing_colors_effect(p_s_quizz->p_s_question[c].e_question_passing);
		printf("\n%s\n\n", ft_get_str_question_result(p_s_quizz->p_s_question[c].e_question_passing));
		ft_display_right_answer(p_s_quizz->p_s_question[c].question_answer, p_s_quizz->p_s_question[c].e_question_passing);
		ft_update_quizz_results_after_every_question(p_s_quizz, p_s_quizz->p_s_question[c].e_question_passing);
	}
}

void	ft_display_question_header(t_s_quizz   *p_s_quizz, short current_question_nbr)
{
	printf("\nQuestion [%hd/%hd]\n", current_question_nbr + 1, p_s_quizz->nbr_of_quizz_questions);
}

t_s_question	ft_generate_1_question(t_s_quizz   *p_s_quizz)
{
	t_s_question	question;
	t_e_quizz_lvl	e_tmp_question_lvl;

	if (p_s_quizz->e_quizz_lvl == mix_of_lvls)
		e_tmp_question_lvl = (t_e_quizz_lvl) ft_p_generate_random_nbr_in_range(1, 3);
	else
		e_tmp_question_lvl = p_s_quizz->e_quizz_lvl;
	if (p_s_quizz->e_quizz_operation_type == mix_of_operations)
		question.e_question_operation_type = (t_e_operation_type) ft_p_generate_random_nbr_in_range(1, 4);
	else
		question.e_question_operation_type = p_s_quizz->e_quizz_operation_type;
	if (e_tmp_question_lvl == easy_lvl)
	{
		question.nbr_1 = (short) ft_p_generate_random_nbr_in_range(1, 10);
        question.nbr_2 = (short) ft_p_generate_random_nbr_in_range(1, 10);
	}
	else if (e_tmp_question_lvl == medium_lvl)
	{
		question.nbr_1 = (short) ft_p_generate_random_nbr_in_range(11, 50);
        question.nbr_2 = (short) ft_p_generate_random_nbr_in_range(11, 50);
	}
	else if (e_tmp_question_lvl == hard_lvl)
	{
		question.nbr_1 = (short) ft_p_generate_random_nbr_in_range(51, 100);
        question.nbr_2 = (short) ft_p_generate_random_nbr_in_range(51, 100);
	}
	question.question_answer = ft_calculate_question_answer(&question, question.e_question_operation_type);
	return (question);
}

short	ft_calculate_question_answer (t_s_question *p_s_question, t_e_operation_type e_quizz_operation_type)
{
    if (e_quizz_operation_type == addition)
        return (p_s_question->question_answer = p_s_question->nbr_1 + p_s_question->nbr_2);
    else if (e_quizz_operation_type == subtraction)
        return (p_s_question->question_answer = p_s_question->nbr_1 - p_s_question->nbr_2);
    else if (e_quizz_operation_type == multiplication)
        return (p_s_question->question_answer = p_s_question->nbr_1 * p_s_question->nbr_2);
	else
	{
        if (p_s_question->nbr_2 != 0)
            return (p_s_question->question_answer = p_s_question->nbr_1 / p_s_question->nbr_2);
        else
            return (0);
    }
}

void	ft_display_question(t_s_question    *p_s_question, t_e_operation_type e_question_operation_type)
{
	printf("%hd\n%hd  %c\n_______\n", p_s_question->nbr_1, p_s_question->nbr_2, ft_get_operation_symbol(e_question_operation_type));
}

char	ft_get_operation_symbol(t_e_operation_type  e_quizz_operation_type)
{
	if (e_quizz_operation_type == addition)
		return ('+');
	else if (e_quizz_operation_type == subtraction)
		return ('-');
	else if (e_quizz_operation_type == multiplication)
		return ('*');
	else
		return ('/');
}

short	ft_read_user_answer()
{
	short	answer;
	
	scanf("%hd", &answer);
	return (answer);
}

t_e_pass_or_fail	ft_get_question_pass_or_fail_result(short question_answer, short user_answer)
{
	if (question_answer != user_answer)
		return (fail);
	else
		return (pass);
}

const char	*ft_get_str_question_result(t_e_pass_or_fail e_pass_or_fail)
{
	if (e_pass_or_fail == pass)
		return ("Right Answer :-)");
	else
		return ("Wrong Answer :-(");
}

void	ft_winning_losing_colors_effect(t_e_pass_or_fail e_pass_or_fail)
{
	 if (e_pass_or_fail == pass)
		 printf("%s", GREEN);
	 else if (e_pass_or_fail == fail)
		 printf("%s", RED);
}

void	ft_display_right_answer(short right_answer, t_e_pass_or_fail e_pass_or_fail)
{
	if (e_pass_or_fail != pass)
		printf("\n\"The Right answer is: (%hd)\"\n\n", right_answer);
}

void	ft_update_quizz_results_after_every_question(t_s_quizz *p_s_quizz, t_e_pass_or_fail e_pass_or_fail)
{
	if (e_pass_or_fail == pass)
		p_s_quizz->nbr_of_correct_answers++;
	else
		p_s_quizz->nbr_of_wrong_answers++;
}


