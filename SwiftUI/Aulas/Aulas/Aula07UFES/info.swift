//
//  info.swift
//  Aula07UFES
//
//  Created by Turma02-2 on 17/06/24.
//

import SwiftUI

struct info: View {
    @State var series = ""
    @State var character = ""
    @State var gameseries = ""
    @State var head = ""
    @State var image = ""
    @State var release: release?
    @State var name = ""
    @State var tail = ""
    @State var type = ""
    
    
    
    var body: some View {
        ZStack{
            Color(.black)
                .ignoresSafeArea()
            VStack
            {
                Text(character)
                    .foregroundColor(.white)
                Text(gameseries)
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
                    Text("au:")
                        .foregroundColor(.white)
                    Text(release?.au! ?? "desconhecido")
                        .foregroundColor(.white)
                }
                HStack
                {
                    Text("eu:")
                        .foregroundColor(.white)
                    Text(release?.au! ?? "desconhecido")
                        .foregroundColor(.white)
                }
                HStack
                {
                    Text("jp:")
                        .foregroundColor(.white)
                    Text(release?.jp! ?? "desconhecido")
                        .foregroundColor(.white)
                }
                HStack
                {
                    Text("na:")
                        .foregroundColor(.white)
                    Text(release?.na! ?? "desconhecido")
                        .foregroundColor(.white)
                }
            }
        }
    }
}

#Preview {
    info()
}
