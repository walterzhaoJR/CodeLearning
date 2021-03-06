# telnet program example
import socket, select, string, sys


def prompt():
    sys.stdout.write('<You> ')
    sys.stdout.flush()


# main function
if __name__ == "__main__":



    host = "127.0.0.1"
    port = 5000

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.settimeout(2)

    # connect to remote host
    try:
        s.connect((host, port))
    except:
        print('Unable to connect')
        sys.exit()

    print('Connected to remote host. Start sending messages')
    prompt()

    while 1:
        rlist = [sys.stdin, s]

        # Get the list sockets which are readable
        read_list, write_list, error_list = select.select(rlist, [], [])

        for sock in read_list:
            # incoming message from remote server
            if sock == s:
                data = sock.recv(4096)
                if not data:
                    print('\nDisconnected from chat server')
                    sys.exit()
                else:
                    # print data
                    sys.stdout.write(data)
                    prompt()

            # user entered a message
            else:
                msg = sys.stdin.readline()
                s.send(msg.encode())
                prompt()