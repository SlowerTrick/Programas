//
//  Desafio3.swift
//  Aula01UFES
//
//  Created by Turma02-2 on 06/06/24.
//

import SwiftUI

struct Desafio3: View {
    var body: some View {
        HStack
        {
            ZStack{
                Image("Djoko")
                    .resizable()
                    .frame(width: /*@START_MENU_TOKEN@*/100/*@END_MENU_TOKEN@*/, height: 100)
                    .clipShape(Circle())
                    .offset(x: 5)
                AsyncImage(url: URL(string: "https://cdn0.iconfinder.com/data/icons/social-messaging-ui-color-shapes/128/add-circle-blue-512.png")) { image in
                    image
                        .resizable()
                        .scaledToFit()
                } placeholder: {
                    Color.black
                }
                .frame(width: 30, height: 20)
                .offset(x: 40, y: 40)
            }
            
            Spacer()
            
            VStack
            {
                HStack
                {
                    Rectangle()
                        .fill(.white)
                        .frame(width: 65, height: 70)
                        .overlay(Text("    8")
                            .fontWeight(.bold))
                        .overlay(Text("    \n\n     Posts")
                            .fontWeight(.regular))
                        .offset(x: -1)
                    Spacer()
                    
                    Rectangle()
                        .fill(.white)
                        .frame(width: 110, height: 70)
                        .overlay(Text("     12k")
                            .fontWeight(.bold))
                        .overlay(Text("    \n\n     Seguidores")
                            .fontWeight(.regular))
                        .offset(x: -10)
                    
                    Spacer()
                    Rectangle()
                        .fill(.white)
                        .frame(width: 100, height: 70)
                        .overlay(Text("     2k")
                            .fontWeight(.bold))
                        .overlay(Text("    \n\n     Seguidos")
                            .fontWeight(.regular))
                        .offset(x: -20)
                }
                Rectangle()
                    .fill(.gray)
                    .overlay(Text("Editar Perfil"))
                    .frame(width: 220, height: 30)
            }
        }
        HStack{
            Text("Nome: Djoko\nProfissão: Coach")
                .frame(width: 200, height: 80)
                .bold()
                .offset(x: -120)
        }
        HStack{
            HStack{
                (Image("Image 2"))
                    .resizable()
                    .frame(width: 50, height: 50)
                    .offset(x: -85)
                (Image("Image 3"))
                    .resizable()
                    .frame(width: 50, height: 50)
                    .offset(x: -5)
                (Image("Image 1"))
                    .resizable()
                    .frame(width: 40, height: 50)
                    .offset(x: +76)
            }
        }
        VStack
        {
            HStack{
                Rectangle()
                    .fill(.gray)
                Rectangle()
                    .fill(.gray)
                Rectangle()
                    .fill(.gray)
            }
            HStack{
                Rectangle()
                    .fill(.gray)
                Rectangle()
                    .fill(.gray)
                Rectangle()
                    .fill(.gray)
            }
            HStack{
                Rectangle()
                    .fill(.gray)
                Rectangle()
                    .fill(.gray)
                Rectangle()
                    .fill(.gray)
            }
        }
    }
}

#Preview {
    Desafio3()
}
