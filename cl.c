#include "minitalk.h"

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
		usleep(100);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	*str;
	size_t	i;

	if (argc != 3 || ft_strlen(argv[2]) == 0)
	{
		ft_printf("Invalid arguments. Check server id / message sent");
		return (-1);
	}
	str = argv[2];
	i = 0;
	while (ft_strlen(str) >= i)
	{
		send_bits(str[i], ft_atoi(argv[1]));
		i++;
	}
	return (0);
}