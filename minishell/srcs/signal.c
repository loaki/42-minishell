#include "minishell.h"

void    sigint_handler_cmd(int signal)
{
    (void)signal;
    ft_putstr_fd("\n", 0);
    g_sigint = true;
    g_sigquit = false;
}

void    sigquit_handler_cmd(int signal)
{
    (void)signal;
    ft_putstr_fd("Quit: ", 0);
    ft_putnbr_fd(signal, 0);
    ft_putstr_fd("\n", 0);
    g_sigint = false;
    g_sigquit = true;
}

void    sigint_handler_sh(int signal)
{
    (void)signal;
    ft_putstr_fd("\n", 0);
    print_prompt();
    g_sigint = true;
    g_sigquit = false;
}

void sigquit_handler_sh(int signal)
{
    (void)signal;
    ft_putstr_fd("What should be happening here mdr\n", 0);
}