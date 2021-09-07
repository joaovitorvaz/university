import numpy as np

###########################################################
def gaussseidel(A,B):
    # Método de GaussSeidel (Gladston Moreira)
    """
    input A = nxn array
          B = nx1 array
    """
    # Verifica se o sistema é compatível
    d = np.linalg.det(A)
    if d==0:
        print('Sistema não é compatível')

    # Estimativa Inicial
    n = len(A)
    X = np.zeros((n, 1))
    Xk = np.copy(X)
    
    # Verifica condições de convergência
    for i in range(n):
        L = 0 # Soma dos elementos "não-pivô" de uma linha
        C = 0 # Soma dos elementos "não-pivô" de uma coluna

        # Critério das linhas
        for j in range(n):
            if j != i:
                L += abs(A[i, j])

        # Critério das colunas
        for k in range(n):
            if k != i:
                C += abs(A[k, i])

        if L > abs(A[i, i]):
            print('Linha', i+1, ' não satisfaz critério das linhas')
            break
        elif C > abs(A[i, i]):
            print('Coluna', i+1, ' não satisfaz critério das colunas')
            break
    
    #Critérios de parada
    maxiter = 10
    minDelta = 1e-09
    delta = 1
    
    # Contador
    k = 0
    print('\nk -\t X \t\t- \t\t max |X(k) - X(k-1)| ')
    print(k,'\t',np.transpose(X),'\t\t\t---')
    while k < maxiter and delta > minDelta:
        # Para cada linha
        for i in range(n):
            # Quantidade de componentes atualizados, e que serão utilizados no cálculo de x(i)k
            numero_componentes_atualizados = i
            # Multiplica e soma elementos conhecidos e joga para o outro lado
            soma = B[i, 0]
            for j in range(n): # Cada coluna da linha em questão
                if i != j: # Xk será utilizado para armazenar o valor das variáveis x, na iteração k-1
                    if numero_componentes_atualizados > 0:
                        soma += (A[i, j] * (-1)) * X[j, 0]
                        numero_componentes_atualizados -= 1
                    else:
                        soma += (A[i, j] * (-1)) * Xk[j, 0]
            soma /= A[i, i]
            X[i, 0] = soma
        
        # calcula max|x(i)k-x(i)k-1|
        lista_auxiliar = [] # Armazena os valores de |x(i)k - x(i)k-1| para cada linha da matriz X
        for i in range(n):
            lista_auxiliar.append(abs(X[i, 0] - Xk[i, 0]))
        delta = max(lista_auxiliar)

        # interação
        k = k + 1
        # print k -- xk   --  max|x(i)k-x(i)k-1|
        print(k,'\t',np.transpose(X),'\t\t\t',delta)
        Xk = np.copy(X) # Xk será utilizado para armazenar o valor das variáveis x, na iteração k-1
        
    print('X:')
    print(X)
    return X

# Teste
print('= Teste 1 =\n')
A = np.array([[9, 3, 1],
              [9, 11, 1.3],
              [1.3, 9, -7]])
B = np.array([[7],
              [8],
              [6]])
X = gaussseidel(A, B)
print('\n')