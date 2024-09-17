#include "game.h"

void	ft_show_round_nbr_in_round_start(short round_nbr)
{
	printf("Round (%hd) Begins:\n\n", round_nbr);
}

void	ft_show_round_nbr_in_round_result(short round_nbr)
{
	printf("________ Round (%hd) ________\n\n", round_nbr);
}

t_e_choice	ft_get_e_player_choice()
{
	short entered_choice;

	entered_choice = ft_i_read_ranged_nbr("Enter your choice: [1]: Stone, [2]: Paper, [3]: Scissors?\n", 1, 3);
	if (entered_choice == 1)
		return (stone);
	else if (entered_choice == 2)
		return (paper);
	else if (entered_choice == 3)
		return (scissor);
	else 
		return (invalid_choice);
}


t_e_choice	ft_get_e_computer_random_choice()
{
	short random_choice;

	random_choice = ft_p_generate_random_nbr_in_range(1, 3);
	if (random_choice == 1)
		return (stone);
	else if (random_choice == 2)
		return (paper);
	else if (random_choice == 3)
		return (scissor);
	else
		return (invalid_choice);
}

char	*ft_get_str_choice(t_e_choice choice)
{
	if (choice == stone)
		return ("Stone");
	else if (choice == paper)
		return ("Paper");
	else if (choice == scissor)
		return ("Scissor");
	else
		return ("Invalid Choice");
}

t_e_winner ft_get_e_round_winner(t_e_choice player_choice, t_e_choice computer_choice)
{
    if (player_choice == stone)
    {
        if (computer_choice == scissor)
            return (player);
        else if (computer_choice == stone)
            return (draw);
        else
            return (computer);
    }
    else if (player_choice == paper)
    {
        if (computer_choice == stone)
            return (player);
        else if (computer_choice == paper)
            return (draw);
        else
            return (computer);
    }
    else if (player_choice == scissor)
    {
        if (computer_choice == paper)
            return (player);
        else if (computer_choice == scissor)
            return (draw);
        else
            return (computer);
    }
    else
        return (draw);
}

char	*ft_get_str_winner(t_e_winner winner)
{
	if (winner == player)
		return ("Player");
	else if (winner == computer)
		return ("Computer");
	else if (winner == draw)
		return ("No Winner");
	else
		return ("Error happened in char    *ft_get_str_winner(t_e_winner winner)\n\n");
}

char *ft_color_change_result(t_e_winner winner)
{
    const char *color;

    if (winner == player)
    {
        color = GREEN;
    }
    else if (winner == computer)
    {
        color = RED;
    }
    else
    {
        color = YELLOW;
    }
    return ((char *)color);
}

void	ft_print_round_results(t_s_round_results *p_e_round)
{
	printf("%s", ft_color_change_result(p_e_round->round_winner)); // Start coloring
	printf("Player Choice: {%s}\n", ft_get_str_choice(p_e_round->player_choice));
	printf("Computer Choice: {%s}\n", ft_get_str_choice(p_e_round->computer_choice));
	printf("Round Winner: {%s}\n", ft_get_str_winner(p_e_round->round_winner));
	printf("____________________\n\n\n");
	printf("%s", RESET);
}

void	ft_update_game_results(t_s_game_results *p_s_game, t_e_winner round_winner)
{
	if (round_winner == player)
		p_s_game->player_winning_times++;
	else if (round_winner == computer)
		p_s_game->computer_winning_times++;
	else
		p_s_game->draw_times++;
}


