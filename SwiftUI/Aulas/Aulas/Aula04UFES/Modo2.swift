//
//  Modo1.swift
//  Aula04UFES
//
//  Created by Turma02-2 on 11/06/24.
//
    // : Hashable
//struct Aluno{
//    var name: String
//    var idade: Int
//}

//@State var a: Aluno = Aluno(nome: a, idade: 1)

//var arrAluno [Aluno]{
//    Aluno(nome: a, idade: 1)
//    Aluno(nome: a, idade: 1)
//}

import SwiftUI

struct Modo2: View {
    @State var nome = ""
    var body: some View {
        ZStack {
            Color("azulescuro")
                .scaledToFill()
                .ignoresSafeArea()
            VStack
            {
                Text("Modo 2")
                    .foregroundColor(.white)
                    .font(/*@START_MENU_TOKEN@*/.title/*@END_MENU_TOKEN@*/)
                    .fontWeight(/*@START_MENU_TOKEN@*/.bold/*@END_MENU_TOKEN@*/)
                Spacer()
                ZStack
                {
                    Text("Bem-vindo, \(nome)")
                        .fontWeight(.bold)
                        .foregroundColor(Color.white)
                        .frame(width: 200, height: 200)
                        .background(Color("rosa"))
                        .cornerRadius(5)
                        .offset(y: -50)
                    
                    TextField("Nome", text: $nome)
                        .fontWeight(.bold)
                        .frame(width: /*@START_MENU_TOKEN@*/100/*@END_MENU_TOKEN@*/, height: 30)
                        .foregroundColor(Color.white)
                        .background(Color("rosa"))
                        .offset(y: -100)
                        .offset(x: 20)
                    
                    NavigationStack
                    {
                        VStack
                        {
                            NavigationLink(destination: Modo2_2(nome2: nome))
                            {
                                Text("Modo2p2")
                            }
                        }
                    }
                }
                Spacer()
            }
        }
    }
}
    
    #Preview {
        Modo2()
    }

