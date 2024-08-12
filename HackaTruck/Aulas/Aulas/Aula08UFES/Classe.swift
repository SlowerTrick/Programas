//
//  Classe.swift
//  Aula08UFES
//
//  Created by Turma02-2 on 19/06/24.
//

import Foundation

class ViewModel : ObservableObject{
    @Published var pokemons : [Pokemon] = []
    func fetchAmiibos(){
        guard let url = URL(string: "http://127.0.0.1:1880/get") else{
            return
        }
        let task = URLSession.shared.dataTask(with: url){ [weak self] data, _, error in
            
            guard let data = data, error == nil else{
                return
            }
            do{
                let jsonDecodificado = try JSONDecoder().decode([Pokemon].self, from: data)
                
                DispatchQueue.main.async{
                    self?.pokemons = jsonDecodificado
                }
            }catch{
                print(error)
            }
        }
        task.resume()
    }
}
