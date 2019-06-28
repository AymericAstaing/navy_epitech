/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** navy.h
*/

#ifndef NAVY_H_
# define NAVY_H_

#include	<stdio.h>
#include	<sys/types.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<signal.h>

static const int	C_EXIT_SUCCESS = 0;
static const int	C_EXIT_ERROR = 	84;
static const int	IS_SERVER = 2;
static const int 	IS_CLIENT = 3;
static const int	BOARD_SQUARE_NBR = 65;
static const int	MESSAGE_RECEIVED = 16;
static const int	HELLO_SIGNAL = 0;
static const int 	MAX_LINE_COL = 7;
static const char 	LESS_SYMBOL = '-';
#define		GAME			g_game
#define		SEPARATOR_SYMBOL	':'
#define		IS_SHOT(x)		(x <= 3 && x >= 2 ? 1 : 0)
#define		IS_DIGIT(x)		(x >= 49 && x <= 56 ? 1 : 0)
#define		BOAT_NBR(x)		(x >= 50 && x <= 53 ? 1 : 0)
#define		IS_LETTER(x)		(x >= 65 && x <= 72 ? 1 : 0)
#define		IS_CORRECT_POS(x, y)	(x >= 65 && x <= 72 &&\
					y >= 49 && y <= 56 ? 1 : 0)
#define		IS_SPACE(x)		(x != 12 ? 1 : 0)

typedef	struct	s_server_player		t_server_player;
typedef	struct	s_client_player		t_client_player;

enum		ret_state {
	ERROR = 0,
	SUCCESS
};

enum		comment_display {
	MY_PID = 0,
	WAITING_ENEMY = 1,
	ENEMY_CONCTD = 2,
	MY_POS = 3,
	ENEMY_POS = 4,
	SUCCESS_CONCTD = 5,
	WAIT_ENEMY_ATTACK = 6,
	HIT = 7,
	MISSED = 8,
	ATTACK = 9,
	WRONG_POS = 10,
	ENEMY_WON = 11
};

enum		info_state {
	WAITING = 0,
	CONNECTED
};

enum		boardsymbol {
	MISSED_POS = -2,
	HIT_POS = -1,
	FREE_POS = 0
};

static const char* const top_board = " |A B C D E F G H\n-+---------------\n1|";

static const char* const info[] = {
	"my_pid: ",
	"\nwaiting for enemy connection...\n",
	"\nenemy connected\n",
	"\nmy positions:\n",
	"\nenemy's positions:\n",
	"\nsuccessfully connected\n",
	"\nwaiting for enemy's attack...",
	": hit\n",
	": missed\n",
	"\nattack: ",
	"wrong position",
	"\nEnemy won\n",
};

static const char* const help = "USAGE\n     ./navy \
[first_player_pid] navy_positions\nDESCRIPTION\n     \
first_player_pid:  only for the 2nd player.  \
pid of the first player.\n     \
navy_positions:  file representing the positions of the ships.\n";

struct s_server_player {
	pid_t		server_pid;
	int		receive_nbr;
	char		*receivex;
	char		*receivey;
	int		*s_boat_position;
	int		*e_boat_position;
	int		first;
};

struct s_client_player
{
	pid_t		enemy_pid;
};

struct s_game_struct
{
	t_server_player server_player;
	t_client_player client_player;

}	g_game;

int	main(int, char **);
void	show_all(void);
char	*get_next_line(const int);
void	attack(void);
void	show(void);
int	store_positions(char *);
char	*get_next_line(const int fd);
int	check_hit(int);
char	*my_strmcat(char *, char *);
int	get_str_from_binary(char *);
void	show_server_grid(void);
void	show_enemy_grid(void);

#endif
