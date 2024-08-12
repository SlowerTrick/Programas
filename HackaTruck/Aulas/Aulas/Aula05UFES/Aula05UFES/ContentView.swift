//
//  ContentView.swift
//  Aula05UFES
//
//  Created by Turma02-2 on 12/06/24.
//

import SwiftUI

struct ContentView: View {
    
    var arrayMusica = [
        Song(id: 1, name: "World Hold On - FISHER Rework", artist: "Bob Sinclair, FISHER, Steve Edwards", capa: "bob"),
        Song(id: 2, name: "Innerbloom", artist: "RÜFUS DU SOL", capa: "inner"),
        Song(id: 3, name: "Unholy", artist: "Sam Smith, Kim Patras", capa: "sam"),
        Song(id: 4, name: "teste 4", artist: "teste2", capa: ""),
        Song(id: 5, name: "teste 5", artist: "teste2", capa: ""),
        Song(id: 6, name: "teste 6", artist: "teste2", capa: ""),
        Song(id: 7, name: "teste 7", artist: "teste2", capa: ""),
        Song(id: 8, name: "teste 8", artist: "teste2", capa: ""),
        Song(id: 9, name: "teste 9", artist: "teste2", capa: ""),
        Song(id: 10, name: "teste 10", artist: "teste2", capa: ""),
    ]
    
    var body: some View {
        
        NavigationStack
        {
            ZStack 
            {
                LinearGradient(colors: [.blue, .black], startPoint: .top, endPoint: .bottom)
                    .ignoresSafeArea()
                ScrollView
                {
                    VStack
                    {
                        Image("caminhao")
                            .resizable()
                            .frame(width: 180, height: 180)
                    }
                    VStack
                    {
                        HStack
                        {
                            Text("HackaFM")
                                .font(.title)
                                .fontWeight(.bold)
                                .foregroundColor(Color.white)
                                .offset(x: 20)
                            Spacer()
                        }

                        HStack
                        {
                            Image("caminhao")
                                .resizable()
                                .frame(width: 30, height: 30)
                                .offset(x: 20, y: -10)
                            Text("HackaSong")
                                .font(.footnote)
                                .fontWeight(.bold)
                                .foregroundColor(Color.white)
                                .offset(x: 20, y: -10)
                            Spacer()
                        }
                    }
                    
                    VStack(alignment: .leading)
                    {
                        ForEach(arrayMusica) 
                        { item in
                            NavigationLink(destination: p2(name: item.name, image: item.capa, artist: item.artist))
                            {
                                HStack
                                {
                                    Image(item.capa)
                                        .resizable()
                                        .frame(width: 60, height: 60)

                                    VStack
                                    {
                                        Text(item.name)
                                            .frame(maxWidth: .infinity, alignment: .leading)
                                            .foregroundColor(Color.white)

                                        
                                        Text(item.artist)
                                            .frame(maxWidth: .infinity, alignment: .leading)
                                            .foregroundColor(Color.gray)
                                    }
                                    VStack{
                                        Image(systemName: "ellipsis")
                                            .foregroundColor(.white)
                                    }
                                    Spacer()
                                    
                                }
                                .padding(5)
                            }
                        }
                    }
                    ScrollView(.horizontal)
                    {
                        HStack
                        {
                            ForEach(arrayMusica)
                            { item in
                                NavigationLink(destination: p2(name: item.name, image: item.capa, artist: item.artist))
                                {
                                    HStack
                                    {
                                        VStack{
                                            Image(item.capa)
                                                .resizable()
                                                .frame(width: 200, height: 200)
                                            Text(item.name)
                                                .foregroundColor(Color.white)
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

#Preview {
    ContentView()
}
