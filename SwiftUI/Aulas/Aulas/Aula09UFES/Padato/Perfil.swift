//
//  ContentView.swift
//  Padato
//
//  Created by Turma02-19 on 21/06/24.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        NavigationStack{
            ZStack{
                Color("azul")
                    .ignoresSafeArea()
                VStack {
                    NavigationLink(destination: editarPerfil()){
                        Text("Editar Perfil")
                            .padding(.leading, 240)
                            .shadow(radius: /*@START_MENU_TOKEN@*/10/*@END_MENU_TOKEN@*/)
                    }
                    ZStack{
                        
                        Circle() //FOTO DO PERFIL
                            .frame(width:100 , height: 100)
                            .padding(.bottom, 60)
                            .foregroundColor(.white)
                        Rectangle() // FOTO DE CAPA DO PERFIL
                            .frame(width: 800, height: 100)
                            .padding(.top, 50)
                            .foregroundColor(.white)
                    }
                    //Spacer()
                    NavigationLink(destination: Decks_Pu_blicos()){
                        Rectangle()
                            .overlay(Text("Decks Publicos")
                                .foregroundColor(.white)
                                .bold())
                            .frame(width: 800, height: 100)
                    }
                    NavigationLink(destination: Estati_sticas_do_Usua_rio()){
                        Rectangle()
                            .overlay(Text("Estatísticas do Usuário")
                                .foregroundColor(.white)
                                .bold())
                            .frame(width: 800, height: 100)
                    }
                    NavigationLink(destination: Ofensiva()){
                        Rectangle()
                            .overlay(Text("Ofensiva")
                                .foregroundColor(.white)
                                .bold())
                            .frame(width: 800, height: 100)
                    }
                    Spacer()
                }
            }
        }
    }
}

#Preview {
    ContentView()
}
