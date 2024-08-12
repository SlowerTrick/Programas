//
//  Classe.swift
//  Aula07UFES
//
//  Created by Turma02-2 on 14/06/24.
//

import Foundation

class ViewModel : ObservableObject{
    @Published var amiibos : [Amiibo] = []
    func fetchAmiibos(){
        guard let url = URL(string: "https://www.amiiboapi.com/api/amiibo/?gameseries=mario") else{
            return
        }
        let task = URLSession.shared.dataTask(with: url){ [weak self] data, _, error in
            
            guard let data = data, error == nil else{
                return
            }
            do{
                let jsonDecodificado = try JSONDecoder().decode(API.self, from: data)
                
                DispatchQueue.main.async{
                    self?.amiibos = jsonDecodificado.amiibo
                }
            }catch{
                print(error)
            }
        }
        task.resume()
    }
}
