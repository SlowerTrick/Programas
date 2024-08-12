//
//  Location.swift
//  Aula06UFES
//
//  Created by Turma02-2 on 13/06/24.
//

import Foundation
import MapKit

struct Location: Identifiable 
{
    let id = UUID()
    let name: String
    let coordinate: CLLocationCoordinate2D
    let flag: String
    let description: String
}

var arrayMapa =
[
    Location(name: "Brazil", coordinate: CLLocationCoordinate2D(latitude: -15.721487, longitude: -48.1021714), flag: "brasil", description: "Brasil é o maior país da América do Sul e o único da América cuja língua oficial é o português. Considerado uma das maiores economias, o país apresenta enorme biodiversidade. Brasil é o maior país da América do Sul e uma das maiores economias do mundo."),
    
    Location(name: "França", coordinate: CLLocationCoordinate2D(latitude: 48.8588255, longitude: 2.2646344), flag: "franca", description: "França, oficialmente República Francesa, é um país localizado no oeste da Europa. É o terceiro maior país do continente europeu e um dos mais antigos do mundo. É banhado pelo Oceano Atlântico e pelo Mar Mediterrâneo."),
    
    Location(name: "Canada", coordinate: CLLocationCoordinate2D(latitude: 45.2496824, longitude: -78.1298999), flag: "canada", description: "O Canadá possui um território extenso e é banhado por três oceanos: Atlântico, Pacífico e Glacial Ártico. A população canadense é de cerca de 38 milhões de habitantes. O território canadense é pouco povoado. Esse país possui grandes reservas de recursos naturais diversos, como petróleo, gás natural e madeira."),
    
    Location(name: "Egito", coordinate: CLLocationCoordinate2D(latitude: 30.0594628, longitude: 31.1760627), flag: "egito", description: "O Egito é um país africano localizado na região da África Setentrional, no nordeste do continente. Possui cerca de 1 milhão de km² de área, e seu território abrange a península do Sinai, onde faz fronteira com a Faixa de Gaza e Israel."),
    
    Location(name: "Japão", coordinate: CLLocationCoordinate2D(latitude: 35.50205781, longitude: 138.4504518), flag: "japao", description: "O Japão é um arquipélago que formam um arco no Oceano Pacífico, à leste do continente asiático. O território é formado por quatro grandes ilhas chamadas (em ordem de tamanho) Honshu, Hokkaido, Kyushu e Shikoku, além de outras pequenas ilhas."),
]
