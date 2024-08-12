//
//  SwiftUIView.swift
//  Aula04UFES
//
//  Created by Turma02-2 on 11/06/24.
//

import SwiftUI

struct SwiftUIView: View {
    
    @State private var showingSheet = false
    struct SheetView: View {
        var body: some View {
            ZStack {
                Color("azulescuro")
                    .scaledToFill()
                    .ignoresSafeArea()
                VStack
                {
                    Text("Sheet View")
                        .foregroundColor(.white)
                        .font(/*@START_MENU_TOKEN@*/.title/*@END_MENU_TOKEN@*/)
                        .fontWeight(/*@START_MENU_TOKEN@*/.bold/*@END_MENU_TOKEN@*/)
                    Spacer()
                    Text("Nome: Artur\nSobrenome: Vitor")
                        .fontWeight(.bold)
                        .foregroundColor(Color.white)
                        .frame(width: 200, height: 100)
                        .background(Color("rosa"))
                        .cornerRadius(5)
                    
                    Spacer()
                }
            }
        }
    }
    var body: some View {
        NavigationStack
        {
            ZStack
            {
                Color("azulescuro")
                    .scaledToFill()
                    .ignoresSafeArea()
                VStack{
                    Image("logo")
                        .resizable()
                        .renderingMode(/*@START_MENU_TOKEN@*/.template/*@END_MENU_TOKEN@*/)
                        .foregroundColor(.white)
                        .scaledToFit()
                        .frame(width: 300, height: 100)
                        .rotationEffect(.degrees(4.5))
                    Spacer()
                }
                VStack
                {
                    NavigationLink(destination: Modo1())
                    {
                        Text("Modo 1")
                            .fontWeight(.bold)
                            .foregroundColor(Color.white)
                            .frame(width: 150, height: 50)
                            .background(Color("rosa"))
                            .cornerRadius(5)
                    }
                    NavigationLink(destination: Modo2())
                    {
                        Text("Modo 2")
                            .fontWeight(.bold)
                            .foregroundColor(Color.white)
                            .frame(width: 150, height: 50)
                            .background(Color("rosa"))
                            .cornerRadius(5)
                    }
                    Button(action: {
                        showingSheet.toggle()
                    }) {
                        Text("Modo 3")
                            .frame(width: 150, height: 50)
                            .background(Color("rosa"))
                            .cornerRadius(5)
                            .foregroundColor(Color(red: 255, green:255, blue: 255))
                            .sheet(isPresented: $showingSheet) {
                                        SheetView()
                                    }

                    }
                }
            }
        }
    }
}

#Preview {
    SwiftUIView()
}
