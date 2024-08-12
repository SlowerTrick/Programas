//
//  File.swift
//  Aula09UFES
//
//  Created by Turma02-2 on 21/06/24.
//

import Foundation

struct Flashcard : Decodable, Hashable
{
    var pergunta : String?
    var imagem : String?
    var resposta : String?
}

var timeFormat: DateFormatter {
    let formatter = DateFormatter()
    formatter.dateFormat = "hh:mm"
    return formatter
}

func timeString(date: Date) -> String {
    let time = timeFormat.string(from: date)
    return time
}
