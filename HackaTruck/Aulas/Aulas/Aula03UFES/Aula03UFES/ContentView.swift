//
//  ContentView.swift
//  Aula03UFES
//
//  Created by Turma02-2 on 10/06/24.
//

import SwiftUI

struct ContentView: View {
    @State var peso = ""
    @State var peso2 = 0.0
    @State var altura = ""
    @State var altura2 = 0.0
    @State var calculoimc = false
    @State var texto = "Normal"
    @State var cor = "default"

    var body: some View {
        ZStack 
        {
            Color(cor)
                .frame(width: .infinity, height: .infinity)
                .ignoresSafeArea()
            VStack
            {
                Text("Calculadora de IMC")
                    .font(.title)
                TextField("Peso", text: $peso)
                      .multilineTextAlignment(.center)
                      .background()
                      .frame(width: 350)
                      .padding()
                TextField("Altura", text: $altura)
                      .multilineTextAlignment(.center)
                      .background()
                      .frame(width: 350)
                
                Button(action: {
                        peso2 = Double(peso) ?? 0.0
                        altura2 = Double(altura) ?? 0.0
                        
                        let resultado = peso2 / (altura2 * altura2)
                        
                        if (resultado < 18.5)
                        {
                            texto = "Baixo Peso"
                            cor = "baixo"
                        }
                        else if (resultado >= 18.5 && resultado < 24.99)
                        {
                            texto = "Normal"
                            cor = "normal"
                        }
                        else if (resultado >= 25 && resultado < 29.99)
                        {
                            texto = "Sobrepeso"
                            cor = "sobrepeso"
                        }
                        else if (resultado >= 30)
                        {
                            texto = "Obesidade"
                            cor = "obesidade"
                        }

                            calculoimc = true
                        }) {
                            Text("Calcular")
                                .frame(width: 100, height: 30)
                                .background(.blue)
                                .cornerRadius(5)
                                .foregroundColor(Color(red: 255, green:255, blue: 255))
                            
                        }
                        .padding()
                Spacer()
                if (calculoimc)
                {
                    Text(texto)
                        .foregroundColor(Color(red: 255, green:255, blue: 255))
                        .font(.title)
                }
                Spacer()
                VStack
                {
                    Image("tabela")
                        .resizable()
                        .scaledToFit()
                }
            }
        }
    }

}


#Preview {
    ContentView()
}
