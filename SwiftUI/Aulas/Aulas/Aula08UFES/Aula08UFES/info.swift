//
//  info.swift
//  Aula08UFES
//
//  Created by Turma02-2 on 19/06/24.
//

import SwiftUI

struct info: View 
{
    @State var pokemon = ""
    @State var type : type?
    @State var ability = ""
    @State var image = ""
    
    var body: some View {
        ZStack{
            Color(.black)
                .ignoresSafeArea()
            VStack
            {
                Text(pokemon)
                    .foregroundColor(.white)
                AsyncImage(url: URL(string: image)) { image in
                    image
                        .resizable()
                        .scaledToFit()
                } placeholder: {
                    Color.black
                }
                .frame(width: 200, height: 200)
                HStack
                {
                    Text("Tipo 2:")
                        .foregroundColor(.white)
                    Text(type?.primary! ?? "Não possui")
                        .foregroundColor(.white)
                }
                HStack
                {
                    Text("Tipo 1:")
                        .foregroundColor(.white)
                    Text(type?.secundary ?? "Não possui")
                        .foregroundColor(.white)
                }
            }
        }
    }
}

#Preview {
    info()
}
