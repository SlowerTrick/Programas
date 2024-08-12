//
//  Struct.swift
//  Aula07UFES
//
//  Created by Turma02-2 on 14/06/24.
//

import Foundation

struct Amiibo : Decodable, Hashable {
    var amiiboSeries : String?
    var character : String?
    var gameSeries : String?
    var head : String?
    var image : String?
    var name : String?
    var release : release?
    var tail : String?
    var type : String?
}

struct API : Decodable
{
    var amiibo : [Amiibo]
}


struct release : Decodable, Hashable
{
    var au: String?
    var eu: String?
    var jp: String?
    var na: String?
}
