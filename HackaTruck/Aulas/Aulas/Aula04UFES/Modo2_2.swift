//
//  Modo2.2.swift
//  Aula04UFES
//
//  Created by Turma02-2 on 14/06/24.
//

import SwiftUI

struct Modo2_2: View {
    @State var nome2: String = ""
    var body: some View
    {
        ZStack{
            Color("azulescuro")
                .scaledToFill()
                .ignoresSafeArea()
            VStack
            {
                Text("Tá na hora de voltar \n               \(nome2)")
                    .font(/*@START_MENU_TOKEN@*/.title/*@END_MENU_TOKEN@*/)
                    .fontWeight(/*@START_MENU_TOKEN@*/.bold/*@END_MENU_TOKEN@*/)
                    .foregroundColor(Color.white)
                    .frame(width: 300, height: 200)
                    .background(Color("rosa"))
                AsyncImage(url: URL(string: "https://i.pinimg.com/originals/ba/fb/d1/bafbd1c646f3bd638d2a8454623b2f6a.png")) { image in
                    image
                        .resizable()
                        .scaledToFit()
                } placeholder: {
                    Color.red
                }
                .frame(width: 200, height: 200)
            }
        }
    }
}

#Preview {
    Modo2_2()
}
