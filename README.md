# Projeto-Discoteca-SO

Este projeto foi efetuado para a cadeira de Sistemas Operativos, em que foi solicitado para efetuar uma simulação de uma discoteca.
A discoteca é composta por varias zonas, como por exemplo, pistas de dança, zona de sofás, padaria, pista de karts, mini-golf, etc... (e.g., ver Day After, Viseu.)

Normalmente, cada espaço, por questões de segurança e políticas da discoteca, tem diferentes regras de acesso. Alguns são de acesso livre a todos os utilizadores, outros apenas a utilizadores com privilégios especiais, e ainda, algumas restrições horárias.
Os utilizadores, após entrarem na discoteca, vão para uma pista de dança específica e podem movimentar-se de pista em pista, ou para outras zonas, ficando em cada uma um determinado tempo. No caso da zona estar lotada, o utilizador deverá esperar ou ir para outra zona ou ainda ir embora da discoteca. Nesta simulação o utilizador deverá, pelo menos aceder (ou tentar) à maioria dos espaços.
A simulação a implementar pretende avaliar as condições de funcionamento de um equipamento deste género em termos de quantas pessoas pode servir, quais os tempos de espera médios, quantas desistem, entre outros.

**Arquitetura:**
O sistema desenvolvido contem duas aplicações, a primeira (Simulador) que efetua toda a simulação, e a segunda (Monitor) que receberá todas as mensagens enviadas pela primeira e efetua todo o seu tratamento.

O Simulador gera aleatoriamente a chegada dos utilizadores (cada utilizador é um thread) aos recursos, que permite a correta coordenação e sicronização por vias de semáforos) e envia mensagens para o Monitor (comunicação via sockets)

O Monitor aceita uma ligação de um Simulador e guarda em ficheiro todo o registo enviado por este.
O tratamento de dados da simulação acontece ao nível do Monitor (cálculo da média de tempo à espera, por exemplo).
Durante o funcionamento do Monitor é apresentado dados sobre o seu estado de execução.

