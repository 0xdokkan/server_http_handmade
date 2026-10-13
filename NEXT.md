fatto:     socket/bind/listen funzionano: fd=3, LISTEN su 127.0.0.1:8080
           (verificato con lsof + curl: connessione accettata dal kernel nel backlog,
           la request di curl aspetta nel buffer)
           Debug con print bisection: il binario con -fsanitize=address
           si blocca PRIMA di main su macOS

rotto:     ASan su macOS (Xcode clang 17) → processo bloccato pre-main
           Per ora compilo senza -fsanitize=address

prossimo:  1) accept() + send() della risposta hardcoded → curl -v mostra 200 OK
           2) (rabbit hole) lldb -p <pid> + bt sul binario ASan bloccato: dove si ferma?
              provare anche solo -fsanitize=undefined
