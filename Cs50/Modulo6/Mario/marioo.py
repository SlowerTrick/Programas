def main():

    while(True):

        n = int(input("Altura: "))
        if n < 1 or n > 8:
            print ("Entrada invalida (1 < Altura < 8):", end = "")
        else:
            break

    i = 1
    j = 0

    for i in range(n + 1):
        for j in range(n - i):
            print (" ", end = "")
        print("#" * i + "  " + "#" * i)

    print()

main()
