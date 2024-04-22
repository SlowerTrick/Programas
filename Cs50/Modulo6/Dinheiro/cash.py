def main():

    total = float(input("Valor: "))
    moedastotais = moedas1 = moedas50 = moedas25 = moedas10 = moedas5 = moedas0 = 0

    while total > 0.99:
        total = total - 1
        moedastotais += 1
        moedas1 += 1
    print ("1 real:", moedas1)

    while total > 0.4:
        total = total - 0.5
        moedastotais += 1
        moedas50 += 1
    print ("50 centavos:", moedas50)

    while total > 0.24:
        total = total - 0.25
        moedastotais += 1
        moedas25 += 1
    print ("25 centavos:", moedas25)

    while total > 0.09:
        total = total - 0.10
        moedastotais += 1
        moedas10 += 1
    print ("10 centavos:", moedas10)

    while total > 0.04:
        total = total - 0.05
        moedastotais += 1
        moedas5 += 1
    print ("5 centavos:", moedas5)

    while total > 0.009:
        total = total - 0.01
        moedastotais += 1
        moedas0 += 1
    print ("1 centavo:", moedas0)

    print ("Total de moedas:", moedastotais)


main()
