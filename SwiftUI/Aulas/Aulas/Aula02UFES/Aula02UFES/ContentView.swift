//
//  ContentView.swift
//  Aula02UFES
//
//  Created by Turma02-2 on 07/06/24.
//

import SwiftUI

struct ContentView: View {
    @State private var name = ""
    @State private var showAlert = false
    
    var body: some View {
        VStack {
            Spacer()
            HStack{
                Text ("Bem Vindo,")
                Text(name)
            }
                .font(/*@START_MENU_TOKEN@*/.title/*@END_MENU_TOKEN@*/)
                .bold()
            TextField("Escreva o seu nome", text: $name)
                  .multilineTextAlignment(.center)
            ZStack
            {
                Image("truck")
                    .resizable()
                    .scaledToFit()
                    .frame(width:250, height: 80)
                Image("fundo")
                    .resizable()
                    .scaledToFill()
                    .opacity(0.1)
                    .frame(width:400, height: 650)
                Image("logo")
                    .resizable()
                    .scaledToFit()
                    .frame(width:250, height: 80)
                    .offset(y: -80)
            }
            .offset(y: 60)
            Button(action: {
                        showAlert = true
                    }) {
                        Text("Entrar")
                    }
                    .alert(isPresented: $showAlert) {
                        Alert(title: Text("ALERTA!"),
                             message: Text("Você irá iniciar o desafio da aula agora!"),
                             dismissButton: .cancel(Text("Vamos lá")
                               ))
                    }
            
        }
        .padding()
    }
}

#Preview {
    ContentView()
}
