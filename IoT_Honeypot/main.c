#include <stdio.h>
#include <string.h>

#include "thread.h"
#include "shell.h"
#include "shell_commands.h"

#ifdef MODULE_NETIF
#include "net/gnrc/pktdump.h"
#include "net/gnrc.h"
#endif

static int info(int argc, char **argv) {
    (void)argc;
    (void)argv;
    printf("Welcome to BULB network.\n");
    printf("\n");
    printf("IoT based bulbs network in operation.\n");
    printf("Devices based on Mikrokernel OS. Type help for more commands.\n");
    printf("Example: <txtsnd X YY:YY:YY:YY:YY:YY Example_Message>, to send a message to another device.\n");
    printf("Where X = Interface name and YY:YY... = Interface address.\n");
    printf("Check both with ifconfig command.\n");

    return 0;
}

const shell_command_t shell_commands[] = {
    {"info", "prints general information", info},
    { NULL, NULL, NULL }
};

int main(void)
{
#ifdef MODULE_NETIF
    gnrc_netreg_entry_t dump = GNRC_NETREG_ENTRY_INIT_PID(GNRC_NETREG_DEMUX_CTX_ALL,
                                                          gnrc_pktdump_pid);
    gnrc_netreg_register(GNRC_NETTYPE_UNDEF, &dump);
#endif

    (void) puts("Welcome to Microkernel OS for IoT devices");

    char line_buf[SHELL_DEFAULT_BUFSIZE];
    shell_run(shell_commands, line_buf, SHELL_DEFAULT_BUFSIZE);
}
