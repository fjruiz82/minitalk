#include "minitalk_bonus.h"

int	send_bits(unsigned char c_byte, int server_pid)
{
	int				i;
	unsigned char	bit;

	i = 8;
	while (i--)
	{
		bit = (c_byte >> i & 1) + '0';
		if (bit == '1')
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(500);
	}
	return (0);
}

void	receive_check(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR2)
		++received;
	else
	{
		ft_printf("\n%d bytes readed succesfully\n", received);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*str;
	size_t	i;

	if (argc != 3 || ft_strlen(argv[2]) == 0)
	{
		ft_printf("Invalid arguments. Check server id / message sent");
		return (-1);
	}
	str = argv[2];
	server_pid = ft_atoi(argv[1]);
	i = 0;
	signal(SIGUSR1, receive_check);
	signal(SIGUSR2, receive_check);
	while (ft_strlen(str) >= i)
	{
		send_bits(str[i], server_pid);
		i++;
	}
	while (1)
		pause();
	return (0);
}