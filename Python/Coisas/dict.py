def main():
    lista = []
    hp = 100
    atk = 80
    deff = 50

    for i in range(3):
        novoDict = {
            "HP": hp,
            "ATK": atk,
            "DEF": deff,
        }
        hp += 30
        atk += 30
        deff += 30
        lista.append(novoDict)
    
    for i in range(3):
        print (f'HP: {lista[i]["HP"]} ATK: {lista[i]["ATK"]} DEF: {lista[i]["DEF"]}')

main()