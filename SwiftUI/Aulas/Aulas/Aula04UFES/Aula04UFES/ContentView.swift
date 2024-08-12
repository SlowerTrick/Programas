//
//  ContentView.swift
//  Aula04UFES
//
//  Created by Turma02-2 on 11/06/24.
//

import SwiftUI

struct ContentView: View 
{
    var body: some View {
        VStack
        {
            TabView{
                ZStack {
                        Color("rosa")
                            .frame(width: 400, height: 800)
                            .ignoresSafeArea()
                            .offset(y: -60)
                        Image(systemName: "paintbrush")
                            .resizable()
                            .foregroundColor(Color("rosa"))
                            .background(Circle().frame(width: 300, height: 300))
                            .frame(width: 200, height: 200)
                    }
                    .tabItem {
                        Label("Rosa", systemImage: "paintbrush.fill")
                    }
                ZStack {
                    Color("azul")
                        .frame(width: 400, height: 800)
                        .ignoresSafeArea()
                        .offset(y: -60)
                    Image(systemName: "paintbrush.pointed")
                        .resizable()
                        .foregroundColor(Color("azul"))
                        .background(Circle().frame(width: 300, height: 300))
                        .frame(width: 200, height: 200)
                    }
                    .tabItem {
                        Label("Azul", systemImage: "paintbrush.pointed.fill")
                    }
                ZStack {
                    Color("cinza")
                        .frame(width: 400, height: 800)
                        .ignoresSafeArea()
                        .offset(y: -60)
                    Image(systemName: "paintpalette")
                        .resizable()
                        .foregroundColor(Color("cinza"))
                        .background(Circle().frame(width: 300, height: 300))
                        .frame(width: 200, height: 200)
                        
                    }
                    .tabItem {
                        Label("Cinza", systemImage: "paintpalette.fill")
                    }
                ZStack {
                    Color(.white)
                        .frame(width: 400, height: 800)
                        .ignoresSafeArea()
                        .offset(y: -60)
                    NavigationStack {
                        List {
                            HStack
                            {
                                Text("Item")
                                Spacer()
                                Image(systemName: "paintbrush")
                            }
                            HStack
                            {
                                Text("Item")
                                Spacer()
                                Image(systemName: "paintbrush.pointed")
                            }
                            HStack
                            {
                                Text("Item")
                                Spacer()
                                Image(systemName: "paintpalette")
                            }
                        }
                        .navigationTitle("List")
                    }
                    }
                    .tabItem {
                        Label("Lista", systemImage: "list.bullet")
                    }
            }
        }
    }
}

#Preview {
    ContentView()
}
