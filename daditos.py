    import random
    def validarNum(n):
        while True:
            n=int(input('\nElija el num de dado que desea conservar (1-3):\n-->'))
            if 1<=n<=3: 
                return n
                break
            else: print ('¡¡El numero debe ser entre 1 y 3')
    print ('---Reglas---')
    print ('1. En cada tiro solo puedes conservar un dado')
    print ('2. Si en la tercera ronda los numeros de los dados que elegiste no se repitieron en otro, ganas')
    dados=[]
    for i in range(3):#para que lo haga 3 veces(D1,D2,D3)
        dados.append(random.randint(1,6))#para sacar num de 1 al 6
    conservados=[]
    indices=[]#no quiero que elijas el mismo dado otra vez
    for ronda in range(1,4):
        print ('\n-Ronda ',ronda,'-')
        for i,valor in enumerate(dados):
            if i not in indices:
                print ('Dado',i+1,':',dados[i])
        eleccion=validarNum(0)
        indice=eleccion-1
        if indice in indices:
            print ('¡¡Ya fue conservado anteriormente!!')
            eleccion=int(input('Elija otro dado (1-3):\n-->'))
            indice=eleccion-1
        conservados.append(dados[indice])
        indices.append(indice)
        if ronda<3:
            for i in range(3):
                if i not in indices:
                    dados[i]=random.randint(1,6)
    print ('Resultados finales: ', conservados)
    if len(set(conservados))==3: print ('\nGanaste') #el set() quita los duplicados en la lista
    else: print ('\nPerdiste')