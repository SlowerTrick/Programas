chocolates = int(input("Quantidade de chocolates: "))

for i in range (0, chocolates, 1):
    print ('\n')
    print ("Toma seus chocolates", end = '')
    for j in range (-1, i, 1):
        print ("🍫", end = '')

print ("\n")
print ("Vamos usar uma calulador agora!\n")
calculadora = input ("Escolha uma operação: '+', '-', '*' ou '/': ")
numero1 = int(input ("Numero 1: "))
numero2 = int(input ("Numero 2: "))

if calculadora == '+':
    soma = numero1 + numero2
    print (soma)

if calculadora == '-':
    subtracao = numero1 - numero2
    print (subtracao)

if calculadora == '*':
    multiplicacao = numero1 * numero2
    print (multiplicacao)

if calculadora == '/':
    divisao = numero1 / numero2
    print (divisao)

print ("Potencia: %i", (numero1 ** numero2))

print ("Vou ordenar os seus numeros agora!")

lista = [10, 9, 8 ,7, 6 ,5 ,4 ,3 ,2, 1]
lista.sort()

for i in range (10):
    print (lista[i])
