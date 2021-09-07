import socket

print('Creating socket...')
# create a socket object
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print('Socket created.')

print('Connection with remote host.')
s.connect(('google.com',80))
print('Connection ok.')

s.send(b'GET /index.html HTML/1.1\r\n\r\n') # a função send() envia bytes, não strings
while 1:
    # um número pequeno de bytes recebidos por vez resultará em uma maior "fragementação" da mensagem
    # data = s.recv(128).decode() 
    # os bytes necessitam de serem decodificados de volta para compor a mensagem, utilizando assim a função decode()
    data = s.recv(4096).decode()  
    print(data)
    if data == '':
        break
print('Closing the socket.')
s.close()
