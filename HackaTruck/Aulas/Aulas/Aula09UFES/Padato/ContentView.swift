//
//  ContentView.swift
//  Aula09UFES
//
//  Created by Turma02-2 on 21/06/24.
//

import SwiftUI

struct ContentView: View {
    @State var date = Date()
    @State var usuario = "Arnold"
    
    var body: some View {
        NavigationStack
        {
            ZStack {
                LinearGradient(colors: [Color("darkblue"), Color("darkblue")], startPoint: .top, endPoint: .bottom)
                    .ignoresSafeArea()
                VStack {
                    Text("Bem-vindo,")
                        .font(.system(size: 45))
                        .foregroundColor(.white)
                        .fontWeight(/*@START_MENU_TOKEN@*/.bold/*@END_MENU_TOKEN@*/)
                    Text("\(usuario)!")
                        .font(.system(size: 45))
                        .foregroundColor(.white)
                        .fontWeight(/*@START_MENU_TOKEN@*/.bold/*@END_MENU_TOKEN@*/)
                    Text("\(timeString(date: date))")
                        .font(.system(size: 60))
                        .padding()
                        .foregroundColor(.white)
                        .fontWeight(/*@START_MENU_TOKEN@*/.bold/*@END_MENU_TOKEN@*/)
                    
                    NavigationLink(destination: pag2())
                    {
                        VStack
                        {
                            Text("RESPONDER BARALHOS")
                                .frame(width: 300, height: 70)
                                .background(Color(.white))
                                .foregroundColor(Color("darkblue"))
                                .font(.system(size: 25))
                                .cornerRadius(10)
                                .padding(3)
                             
                                .fontWeight(/*@START_MENU_TOKEN@*/.bold/*@END_MENU_TOKEN@*/)
                            Text("EDITAR BARALHOS")
                                .frame(width: 300, height: 70)
                                .background(Color(.white))
                                .foregroundColor(Color("darkblue"))
                                .font(.system(size: 25))
                                .background(Color("darkblue"))
                                .fontWeight(/*@START_MENU_TOKEN@*/.bold/*@END_MENU_TOKEN@*/)
                                .cornerRadius(10)
                                .padding(3)
                            
                            Text("SCOREBOARD")
                                .frame(width: 300, height: 70)
                                .font(.system(size: 25))
                                .background(Color(.white))
                                .foregroundColor(Color("darkblue"))
                                .fontWeight(/*@START_MENU_TOKEN@*/.bold/*@END_MENU_TOKEN@*/)
                                .cornerRadius(10)
                                .padding(3)
                            
                            Text("PERFIL")
                                .frame(width: 300, height: 70)
                                .font(.system(size: 25))
                                .background(Color(.white))
                                .foregroundColor(Color("darkblue"))
                                .fontWeight(/*@START_MENU_TOKEN@*/.bold/*@END_MENU_TOKEN@*/)
                                .cornerRadius(10)
                                .padding(3)
                        }
                        .padding(30)
                    }
                    Spacer()
                }
                .padding()
            }
        }
    }
}

#Preview {
    ContentView()
}
