#include "quizz.h"

void	ft_start_quizz()
{
	t_s_quizz	*p_s_quizz;
	char	play_again;

	play_again = 'Y';
	p_s_quizz = malloc(sizeof(t_s_quizz));
	if (!p_s_quizz)
		return ;
	while (play_again == 'Y' || play_again == 'y')
	{
		printf("%s", RESET);
		printf("\033[2J\033[1;1H");			// Clear the screen and move cursor to top-left
		p_s_quizz->nbr_of_quizz_questions = (short)ft_i_read_ranged_nbr("Enter the quizz number of questions: ", 1, 10);
		p_s_quizz->e_quizz_lvl = ft_e_read_quiz_lvl();
		p_s_quizz->e_quizz_operation_type = ft_e_read_quiz_questions_operations();
		p_s_quizz->p_s_question = malloc(sizeof(t_s_question) * p_s_quizz->nbr_of_quizz_questions);
		if (!p_s_quizz->p_s_question) 
		{
            free(p_s_quizz);
            return;
        }
		ft_set_s_quizz_initial_values(p_s_quizz);
		ft_start_questions(p_s_quizz);
		printf("%s", RESET);
		p_s_quizz->e_quizz_passing = ft_e_get_quizz_result(p_s_quizz->nbr_of_correct_answers, p_s_quizz->nbr_of_wrong_answers);
		ft_print_quizz_results(p_s_quizz);
		printf("Do you want to play again? Y/N: ");
		scanf(" %c", &play_again);
	}
	free(p_s_quizz);
}

void	ft_set_s_quizz_initial_values(t_s_quizz *p_s_quizz)
{
	short	i;

	p_s_quizz->nbr_of_correct_answers = 0;
    p_s_quizz->nbr_of_wrong_answers = 0;
	i = -1;
	while (++i < p_s_quizz->nbr_of_quizz_questions)
	{
        p_s_quizz->p_s_question[i].nbr_1 = 0;
        p_s_quizz->p_s_question[i].nbr_2 = 0;
        p_s_quizz->p_s_question[i].question_answer = 0;
        p_s_quizz->p_s_question[i].user_answer = 0;
	}
}

t_e_quizz_lvl	ft_e_read_quiz_lvl()
{
	short	entered_lvl_nbr;

	entered_lvl_nbr = (short) ft_i_read_ranged_nbr("Enter the question level as follows: [1]: Easy, [2]: Medium, [3]: Hard, [4]: Mix of levels: ", 1, 4);
	if (entered_lvl_nbr == 1)
		return (easy_lvl);
	else if (entered_lvl_nbr == 2)
		return (medium_lvl);
	else if (entered_lvl_nbr == 3)
		return (hard_lvl);
	else
		return (mix_of_lvls);
}

t_e_operation_type	ft_e_read_quiz_questions_operations()
{
	short   entered_operation_nbr;

	entered_operation_nbr = (short) ft_i_read_ranged_nbr("Enter the Operations type as follows: [1]: Addition, [2]: Subtraction, [3]: Multiplication, [4]: Division, [5]: Mix of operations: ", 1, 5);
	if (entered_operation_nbr == 1)
		return (addition);
	else if (entered_operation_nbr == 2)
		return (subtraction);
	else if (entered_operation_nbr == 3)
		return (multiplication);
	else if (entered_operation_nbr == 4)
		return (division);
	else
		return (mix_of_operations);
}

t_e_pass_or_fail	ft_e_get_quizz_result(short nbr_of_correct_answers, short nbr_of_wrong_answers)
{
	if (nbr_of_correct_answers >= nbr_of_wrong_answers)
		return (pass);
	else
		return (fail);
}

const char	*ft_get_str_quiz_result(t_e_pass_or_fail e_pass_or_fail)
{
	if (e_pass_or_fail == pass)
		return ("Congratulations! You Passed.\n");
	else
		return ("Unfortunately :( You Failed.\n");
}

void	ft_print_quiz_result_header(t_e_pass_or_fail e_pass_or_fail)
{
	printf("\n");
    printf("╔════════════════════════════════════╗\n");
    printf("║                                    ║\n");
    printf("║ %33s ║\n", ft_get_str_quiz_result(e_pass_or_fail));
    printf("║                                    ║\n");
    printf("╚════════════════════════════════════╝\n");
    printf("\n");
}

void	ft_print_quizz_results(t_s_quizz *p_s_quizz)
{
	printf("\033[2J\033[1;1H");			// Clear the screen and move cursor to top-left
	ft_winning_losing_colors_effect(p_s_quizz->e_quizz_passing);
	ft_print_quiz_result_header(p_s_quizz->e_quizz_passing);
	printf("The number of questions:  %hd", p_s_quizz->nbr_of_quizz_questions);
	printf("\nThe level of the quizz:  %s", ft_get_lvl_str(p_s_quizz->e_quizz_lvl));
	printf("\nThe operations used in the quizz:  %s", ft_get_operations_types_str(p_s_quizz->e_quizz_operation_type));
	printf("\nNumber of Right Answers:  %hd", p_s_quizz->nbr_of_correct_answers);
	printf("\nNumber of Wrong Answers:  %hd\n\n", p_s_quizz->nbr_of_wrong_answers);
}

const char	*ft_get_lvl_str(t_e_quizz_lvl e_quizz_lvl)
{
	if (e_quizz_lvl == easy_lvl)
		return ("Easy");
	else if (e_quizz_lvl == medium_lvl)
		return ("Medium");
	else if (e_quizz_lvl == hard_lvl)
		return ("Hard");
	else 
		return ("Mix of all levels");
}

const char	*ft_get_operations_types_str(t_e_operation_type e_quizz_operation_type)
{
	if (e_quizz_operation_type == addition)
		return ("Addition (+)");
	else if (e_quizz_operation_type == subtraction)
		return ("Subtraction (-)");
	else if (e_quizz_operation_type == multiplication)
		return ("Multiplication (*)");
	else if (e_quizz_operation_type == division)
		return ("Division (/)");
	else
		return ("Mix of all operations");
}

