//
//  Desafio2.swift
//  Aula01UFES
//
//  Created by Turma02-2 on 06/06/24.
//

import SwiftUI

struct Desafio2: View {
    var body: some View 
    {
        HStack
        {
            Image("Image")
                .resizable()
                .frame(width: 150, height: 150)
                .clipShape(Circle())
                .offset(x: -25)
            
            VStack
            {
                Text(/*@START_MENU_TOKEN@*/"Hello, World!"/*@END_MENU_TOKEN@*/)
                    .foregroundColor(Color.red)
                    .fontWeight(/*@START_MENU_TOKEN@*/.bold/*@END_MENU_TOKEN@*/)
                    .offset(x: +25)
                VStack
                {
                    Text("77 Universidades")
                        .fontWeight(.bold)
                        .foregroundColor(Color.blue)
                        .offset(x: +25)
                }
                VStack
                {
                    Text("6 regiões do Brasil")
                        .foregroundColor(Color.yellow)
                        .fontWeight(/*@START_MENU_TOKEN@*/.bold/*@END_MENU_TOKEN@*/)
                        .offset(x: +25)
                }
            }
        }
    }
}

#Preview {
    Desafio2()
}
