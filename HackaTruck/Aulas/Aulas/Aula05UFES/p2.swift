//
//  Texto Clicado.swift
//  Aula05UFES
//
//  Created by Turma02-2 on 14/06/24.
//

import SwiftUI

struct p2: View {
    @State var name = ""
    @State var image = ""
    @State var artist = ""
    
    var body: some View
    {
        ZStack
        {
            LinearGradient(colors: [.blue, .black], startPoint: .top, endPoint: .bottom)
                .ignoresSafeArea()
            VStack{
                Spacer()
                Image(image)
                    .resizable()
                    .frame(width: 200, height: 200)
                Text(name)
                    .font(.title3)
                    .foregroundColor(.white)
                    .fontWeight(/*@START_MENU_TOKEN@*/.bold/*@END_MENU_TOKEN@*/)
                Text(artist)
                    .foregroundColor(.white)
                Spacer()
                HStack
                {
                    Spacer()
                    Image(systemName: "shuffle")
                        .resizable()
                        .frame(width: 40, height: 40)
                        .foregroundColor(.white)
                    Spacer()
                    Image(systemName: "backward.end.fill")
                        .resizable()
                        .frame(width: 40, height: 40)
                        .foregroundColor(.white)
                    Spacer()
                    Image(systemName: "play.fill")
                        .resizable()
                        .frame(width: 60, height: 60)
                        .foregroundColor(.white)
                    Spacer()
                    Image(systemName: "forward.end.fill")
                        .resizable()
                        .frame(width: 40, height: 40)
                        .foregroundColor(.white)
                    Spacer()
                    Image(systemName: "repeat")
                        .resizable()
                        .frame(width: 40, height: 40)
                        .foregroundColor(.white)
                    Spacer()
                }
                Spacer()
            }
        }
    }
}

#Preview 
{
    p2()
}
