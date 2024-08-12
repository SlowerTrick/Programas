//
//  ContentView.swift
//  Aula08UFES
//
//  Created by Turma02-2 on 19/06/24.
//

import SwiftUI

struct ContentView: View {
    @StateObject var viewModel = ViewModel()
    
    var body: some View
    {
        ZStack
        {
            Color(.black)
                .ignoresSafeArea()
            VStack
            {
                Text("Pokemons Iniciais")
                    .foregroundColor(.white)
                    .font(/*@START_MENU_TOKEN@*/.title/*@END_MENU_TOKEN@*/)
                    .fontWeight(/*@START_MENU_TOKEN@*/.bold/*@END_MENU_TOKEN@*/)
                NavigationStack
                {
                    ScrollView
                    {
                        ForEach(viewModel.pokemons, id: \.self)
                        { item in
                            NavigationLink(destination: info(pokemon: item.pokemon!, type: item.type!, ability: item.ability!, image: item.image!))
                            {
                                HStack
                                {
                                    AsyncImage(url: URL(string: item.image!)) { image in
                                        image
                                            .resizable()
                                            .scaledToFit()
                                            .frame(width: 100, height: 100)
                                    } placeholder: {
                                        Color.black
                                    }
                                }
                                VStack
                                {
                                    Text(item.pokemon!)
                                        .frame(width: 200, height: 20)
                                }
                                }
                                Spacer()
                                }
                        .frame(width: 500, height: 2000)
                        .background(.black)
                        }
                    }
                }
            }
            .onAppear()
            {
                viewModel.fetchAmiibos()
            }
            .background(.black)
        }
    }


#Preview {
    ContentView()
}

