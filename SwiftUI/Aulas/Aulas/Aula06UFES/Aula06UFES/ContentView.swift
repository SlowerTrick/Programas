//
//  ContentView.swift
//  Aula06UFES
//
//  Created by Turma02-2 on 13/06/24.
//

//

//AsyncImage(url: URL(string: "string"))
//AsyncImage(url: URL(string: "https://s2.static.brasilescola.uol.com.br/be/2021/10/vista-toquio.jpg"))

import SwiftUI
import MapKit

//

struct ContentView: View
{
    
    @State private var position = MapCameraPosition.region(
        MKCoordinateRegion(
            center: CLLocationCoordinate2D(latitude: -14.2350, longitude: -51.9253),
            span: MKCoordinateSpan(latitudeDelta: 1, longitudeDelta: 1))
    )
    
    @State var PaisSelecionado = ""
    @State private var showingSheet = false
    
    var body: some View
    {
        ZStack
        {
            Map(position: $position)
            {
                ForEach(arrayMapa)
                { local in
                    Annotation(local.name, coordinate: local.coordinate)
                    {
                        Button
                        {
                            showingSheet.toggle()
                        } label: {
                            Image(local.flag)
                                .resizable()
                                .frame(width: 100, height: 80)
                        }
                        .sheet(isPresented: $showingSheet)
                        {
                            VStack
                            {
                                Text(local.name)
                                Image(local.flag)
                                    .resizable()
                                    .frame(width: 350, height: 300)
                                Text(local.description)
                                Spacer()
                            }
                        }
                    }
                }
            }
            .ignoresSafeArea()
            VStack
            {
                Text("\nWorld Map\n\(PaisSelecionado)")
                    .multilineTextAlignment(.center)
                    .padding()
                    .frame(width: 400, height: 150)
                    .background(Rectangle().fill(Color.white).shadow(radius: 3))
                    .ignoresSafeArea()
                    .opacity(0.7)
                    .fontWeight(.bold)
                    .font(/*@START_MENU_TOKEN@*/.title/*@END_MENU_TOKEN@*/)
                Spacer()
                ScrollView(.horizontal)
                {
                    HStack
                    {
                        ForEach(arrayMapa)
                        { local in
                            HStack
                            {
                                Button
                                {
                                    position = MapCameraPosition.region(
                                        MKCoordinateRegion(
                                            center: local.coordinate,
                                            span: MKCoordinateSpan(latitudeDelta: 1, longitudeDelta: 1))
                                    )
                                    PaisSelecionado = local.name
                                } label: {
                                    Image(local.flag)
                                        .resizable()
                                        .frame(width: 100, height: 80)
                                }
                            }
                        }
                    }
                }
                .frame(width: 400,height: 100)
            }
        }
    }
}

#Preview 
{
    ContentView()
}
