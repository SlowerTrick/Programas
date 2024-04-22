from cs50 import get_string, get_int

"""
import cs50
#Uso de get_int usando o comando:

cs50.get_int
"""

resposta = get_string ("Nome: ")
"""
resposta = input ("Nome: ")
"""

print (f"Olá {resposta}! tudo bem? Escolhe dois numeros ae:")
"""
print ("Olá, " + resposta)
"""

x = int(input("x: "))
y = int(input("y: "))

print (f"soma: {x + y}")

if x > y:
    print ("x é maior")
elif y > x:
    print ("y é maior")
else:
    print ("x == y")

pao = True
contador = 0

while pao == True:
    contador += 1
    print ("Pão de alho é mt gostoso")
    if contador == 3:
        pao = False

for i in [0, 1, 2]:
    print ("Será mesmo???")

for i in range(3):
    print ("Chocolate é melhor")

for i in range(0, 101, 2):
    print (i)

#if x == y or y == x:
#if string.lower() in ["y", "yes"]:


