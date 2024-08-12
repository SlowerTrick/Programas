//
//  ContentView.swift
//  Aula07UFES
//
//  Created by Turma02-2 on 14/06/24.
//

import SwiftUI

struct ContentView: View {
    @StateObject var viewModel = ViewModel()
    @State private var showingSheet = false
    
    var body: some View 
    {
        ZStack
        {
            Color(.black)
                .ignoresSafeArea()
            VStack
            {
                Text("Personagens:")
                    .foregroundColor(.white)
                    .font(/*@START_MENU_TOKEN@*/.title/*@END_MENU_TOKEN@*/)
                    .fontWeight(/*@START_MENU_TOKEN@*/.bold/*@END_MENU_TOKEN@*/)
                NavigationStack
                {
                    ScrollView
                    {
                        ForEach(viewModel.amiibos, id: \.self)
                        { item in
                            NavigationLink(destination: info(series: item.amiiboSeries!, character: item.character!, gameseries: item.gameSeries!, head: item.head!, image: item.image!, release: item.release!, name: item.name!, tail: item.tail!, type: item.type!))
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
                                    Text(item.character!)
                                        .frame(width: 200, height: 20)
                                    Text(item.name!)
                                        .frame(width: 200, height: 20)
                                }
                                    }
                                Spacer()
                                }
                        .frame(width: 500)
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
