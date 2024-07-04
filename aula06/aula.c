classDiagram
class TelefoneCelular {
-agenda: Agenda
-ultimasChamadas: Lista
-ultimasMensagens: Lista
-despertador: Despertador
-toques: Lista +realizarChamada(telefone: string): void
+enviarMensagem(telefone: string, mensagem: string): void
+receberChamada(): void
+receberMensagem(mensagem: string): void
+gerenciarAgenda(): void
+gerenciarDespertador(): void
+selecionarToque(toque: Toque): void
}

class Agenda {
-contatos: Lista
+adicionarContato(nome: string, telefone: string): void
+buscarContato(telefone: string): Contato
}

class Chamada {
-telefoneDestino: string
-dataHora: DateTime
}

class Mensagem {
-telefoneDestino: string
-conteudo: string
-dataHora: DateTime
}

class Contato {
-nome: string
-telefone: string
}

class Despertador {
-horarios: Lista
+adicionarHorario(horario: Horario): void
+ativarDespertador(): void
}

class Horario {
-hora: DateTime
-ativo: boolean
}

class Toque {
-nome: string
-caminhoArquivo: string
}

TelefoneCelular "1" --> "1" Agenda
TelefoneCelular "1" --> "1" Despertador
TelefoneCelular "1" --> "1..*" Toque
TelefoneCelular "0..*" --> "0..*" Chamada
TelefoneCelular "0..*" --> "0..*" Mensagem
Agenda "1" --> "0..*" Contato
Despertador "1" --> "0..*" Horario