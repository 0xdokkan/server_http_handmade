// main.c — server_http_handmade, M1 (WIP)
// Il codice dentro main() è tuo; le righe marcate [scaffolding] le ho aggiunte io.

#include <stdio.h>       // [scaffolding] perror, getchar
#include <stdlib.h>      // [scaffolding] exit
#include <sys/socket.h>  // [scaffolding] socket, bind, listen
#include <netinet/in.h>  // [scaffolding] struct sockaddr_in, INADDR_LOOPBACK
#include <arpa/inet.h>   // [scaffolding] htons, htonl
#include <unistd.h>

int main(void) {
    fprintf(stderr, "[1] main, pid=%d\n", getpid());
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) { perror("socket"); exit(1); }   // [scaffolding] regola fissa: controlla ogni syscall

    struct sockaddr_in addr = {0};
    fprintf(stderr, "[2] socket ok, fd=%d\n", fd);
    addr.sin_family      = AF_INET;
    addr.sin_port        = htons(8080);
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) { perror("bind");   exit(1); }
    fprintf(stderr, "[3] bind ok\n");
    if (listen(fd, 8) == -1)                                    { perror("listen"); exit(1); }
    fprintf(stderr, "[4] listen ok, premi Invio per uscire\n");
    getchar();   // tiene vivo il processo per il checkpoint con lsof

    // TODO (prossima sessione): accept(), send(), close()
    return 0;
}
