import random as rand

quantidadeLetras = int(input("Quantas letras você deseja gerar? "))

for i in range(quantidadeLetras):

    if rand.randint(1, 2) == 1:
        letra = rand.randint(ord('a'), ord('z')) #ord retorna o inteiro equivalente ao caracter
    else:
        letra = rand.randint(ord('A'), ord('Z')) #ord retorna o inteiro equivalente ao caracter
    print(chr(letra), end="")