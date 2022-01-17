# **TP-3 - BCC362 - 2021-01**

## **Integrantes**
- Daniel Monteiro Valério - 19.1.4035
- Gabriel Mace dos Santos Ferreira - 19.1.4013
- Marcus Vinícius Souza Fernandes - 19.1.4046

## **Instruções de execução**
> Compilação do código:
```
make
```

> Execução do código [`Broker`](appl/Broker.java): 
```
make broker
```
**OBS:** É possível a criação de diferentes brokers em múltiplos terminais, de forma a emular um broker primário que possua vários backups, no entanto vale ressaltar que a aplicação atual não possui suporte para a criação de multiplos brokers primários.

> Execução do código [`OneAppl`](appl/OneAppl.java):
```
make client
```

> Deletar os códigos-objeto:
```
make clean
```