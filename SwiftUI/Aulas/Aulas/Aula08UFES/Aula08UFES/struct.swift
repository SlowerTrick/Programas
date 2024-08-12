//
//  struct.swift
//  Aula08UFES
//
//  Created by Turma02-2 on 19/06/24.
//

import Foundation

struct Pokemon : Decodable, Hashable
{
    var _id : String?
    var _rev : String?
    var pokemon : String?
    var type : type?
    var ability : String?
    var image : String?
}

struct API : Decodable, Hashable
{
    var pokemon : [Pokemon]
}

struct type : Decodable, Hashable
{
    var primary: String?
    var secundary: String?
}
