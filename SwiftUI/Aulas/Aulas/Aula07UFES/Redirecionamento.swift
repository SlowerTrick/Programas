//
//  Redirecionamento.swift
//  Aula07UFES
//
//  Created by Turma02-2 on 14/06/24.
//

import SwiftUI

struct Redirecionamento: View {
    var body: some View {
        ZStack{
            Color(.black)
                .ignoresSafeArea()
            VStack
            {
                Text(index.character!)
                    .foregroundColor(.white)
                Text(index.gameSeries!)
                    .foregroundColor(.white)
                Text(index.head!)
                    .foregroundColor(.white)
                AsyncImage(url: URL(string: index.image!)) { image in
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

#Preview 
    {
    Redirecionamento()
}
