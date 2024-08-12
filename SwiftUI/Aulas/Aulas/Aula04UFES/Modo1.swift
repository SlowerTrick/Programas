//
//  Modo1.swift
//  Aula04UFES
//
//  Created by Turma02-2 on 11/06/24.
//

import SwiftUI

struct Modo1: View {
    var body: some View {
        ZStack {
            Color("azulescuro")
                .scaledToFill()
                .ignoresSafeArea()
            VStack
            {
                Text("Modo 1")
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

#Preview {
    Modo1()
}
