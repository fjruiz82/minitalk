
#include "minitalk_bonus.h"

static void	receive_bits(int sig, siginfo_t *info, void *context)
{
	static unsigned char	str = 0;
	static int				bit_pos = 7;
	static pid_t			c_pid = 0;

	(void)context;
	if (!c_pid)
		c_pid = info->si_pid;
	if (sig == SIGUSR2)
		str = (1 << bit_pos) | str;
	bit_pos--;
	if (bit_pos < 0)
	{
		if (str == '\0')
		{
			kill(c_pid, SIGUSR1);
			bit_pos = 7;
			c_pid = 0;
			ft_printf("\n");
			return ;
		}
		ft_printf("%c", str);
		kill(c_pid, SIGUSR2);
		bit_pos = 7;
		str = 0;
	}
}

int	main(void)
{
	struct sigaction	signal_data;

	ft_printf("\nSERVER PID: %d\n\n", getpid());
	signal_data.sa_sigaction = receive_bits;
	signal_data.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &signal_data, NULL);
	sigaction(SIGUSR2, &signal_data, NULL);
	while (1)
		pause();
	return (0);
}