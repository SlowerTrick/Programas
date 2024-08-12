//
//  ContentView.swift
//  Aula01UFES
//
//  Created by Turma02-2 on 06/06/24.
//

import SwiftUI

struct ContentView: View 
{
    var body: some View
    {
        VStack
        {
            VStack
            {
                HStack
                {
                    Rectangle()
                        .fill(.red)
                    //foregroundStyle(.red)
                        .frame(width: 100, height: 100)
                    Spacer()
                    VStack
                    {
                        Rectangle()
                            .fill(.blue)
                            .frame(width: 100, height: 100)
                    }
                }
                
                Spacer()
                
                HStack
                {
                    Rectangle()
                        .fill(.green)
                        .frame(width: 100, height: 100)
                    Spacer()
                    VStack
                    {
                        Rectangle()
                        .fill(.yellow)
                        .frame(width: 100, height: 100)
                    }
                }
            }
        }
        .padding()
    }
}

#Preview {
    ContentView()
}
