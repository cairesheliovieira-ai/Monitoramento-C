# Desafio de Monitoramento de Temperatura

## 1. Identificação

- **Aluno:** Hélio Junior Vieira Caires
- **Disciplina:** _(preencher com o nome da disciplina)_
- **Professora:** Profa. Karla Sartin
- **Título do projeto:** Desafio – Monitoramento de Temperatura em C

## 2. Objetivo

Fazer um programa em C que monitora temperaturas digitadas pelo usuário e compara cada uma com um limite definido no início. Se aparecerem **três temperaturas consecutivas acima do limite**, o monitoramento é encerrado automaticamente. No final, o programa mostra um relatório com média, maior, menor, quantidade e percentual de temperaturas acima do limite.

## 3. Funcionamento do programa

**Definição do limite.** No começo, o usuário digita o limite de temperatura. Ele só é aceito se estiver entre **-50 e 150**. Se estiver fora dessa faixa, o programa mostra "Limite invalido!" e pede de novo.

**Leituras.** Depois de definido o limite, o programa pede uma temperatura de cada vez, quantas o usuário quiser, até o monitoramento terminar.

**Valores inválidos.** Se a temperatura estiver fora da faixa de -50 a 150, o programa mostra "Temperatura invalida!" e pede a próxima. Essa leitura **não entra** na média, no maior, no menor nem na contagem de consecutivas.

**Temperaturas acima do limite.** Para cada leitura válida, o programa verifica se `t > limite`. Se for, soma 1 em `acima` e mostra um aviso.

**Contagem de consecutivas.** A variável `seguidas` aumenta em 1 a cada temperatura acima do limite. Quando aparece uma temperatura normal (menor ou igual ao limite), ela volta para **zero**. Assim ela sempre guarda quantas temperaturas seguidas estão acima do limite.

**Condições que encerram o monitoramento:**
- **Automática:** quando `seguidas` chega a 3.
- **Manual:** quando o usuário digita `999`.

**Relatório final.** Mostra a quantidade de leituras válidas, a **média**, a **maior** e a **menor** temperatura, e a **quantidade** e o **percentual** acima do limite (acima ÷ leituras válidas × 100). Se o encerramento foi automático, isso também é informado. Se não houve nenhuma leitura válida, o programa avisa em vez de calcular (para não dividir por zero).

## 4. Estruturas de repetição utilizadas

- **`do...while`:** usado para ler o **limite**. O programa precisa pedir o limite pelo menos uma vez, e só depois de digitado dá para saber se ele é válido. Por isso a condição fica no final.
- **`while`:** usado no **monitoramento das temperaturas**, com a condição `seguidas < 3`. Ela é verificada antes de cada leitura, então assim que a terceira temperatura seguida acima do limite acontece, o laço termina sem pedir outra leitura. O `break` é usado para sair do laço quando o usuário digita 999.

## 5. Como executar

```bash
gcc monitoramento.c -o monitoramento
./monitoramento
```

No Windows: `gcc monitoramento.c -o monitoramento.exe` e depois `monitoramento.exe`.

> O programa espera que o usuário digite apenas números.

## 6. Testes realizados

Os logs estão na pasta `evidencias/` (arquivos `.txt`), junto com os prints (`.png`) de cada teste.

### Teste 1 – Validação de entradas inválidas

**Entradas:** limite `500`, `-80`, `40`; temperaturas `200`, `-100`, `30`, `999`.

```
Limite de temperatura (-50 a 150): 500
Limite invalido!
Limite de temperatura (-50 a 150): -80
Limite invalido!
Limite de temperatura (-50 a 150): 40
Temperatura (999 encerra): 200
Temperatura invalida!
Temperatura (999 encerra): -100
Temperatura invalida!
Temperatura (999 encerra): 30
Temperatura (999 encerra): 999

=== RELATORIO FINAL ===
Leituras validas: 1
Media: 30.00
Maior: 30.0
Menor: 30.0
Acima do limite: 0 (0.0%)
```

**Resultado:** os dois limites inválidos (500 e -80) foram recusados e o programa pediu de novo até receber 40. Nas leituras, 200 e -100 foram recusadas e não entraram nos cálculos. Só o 30 foi contado como válido.

### Teste 2 – Temperaturas acima do limite, porém não consecutivas

**Entradas:** limite `40`; temperaturas `41, 42, 30, 45, 46, 20, 999`.

```
Limite de temperatura (-50 a 150): 40
Temperatura (999 encerra): 41
Acima do limite! (1 seguida(s))
Temperatura (999 encerra): 42
Acima do limite! (2 seguida(s))
Temperatura (999 encerra): 30
Temperatura (999 encerra): 45
Acima do limite! (1 seguida(s))
Temperatura (999 encerra): 46
Acima do limite! (2 seguida(s))
Temperatura (999 encerra): 20
Temperatura (999 encerra): 999

=== RELATORIO FINAL ===
Leituras validas: 6
Media: 37.33
Maior: 46.0
Menor: 20.0
Acima do limite: 4 (66.7%)
```

**Resultado:** teve 4 temperaturas acima do limite, mas em duas sequências de 2, cada uma interrompida por uma temperatura normal. O contador voltou a zero (na leitura 4 ele recomeçou em 1) e o programa **não** encerrou sozinho. Só terminou quando digitei 999.

### Teste 3 – Três temperaturas consecutivas acima do limite

**Entradas:** limite `40`; temperaturas `35, 41, 42, 43`.

```
Limite de temperatura (-50 a 150): 40
Temperatura (999 encerra): 35
Temperatura (999 encerra): 41
Acima do limite! (1 seguida(s))
Temperatura (999 encerra): 42
Acima do limite! (2 seguida(s))
Temperatura (999 encerra): 43
Acima do limite! (3 seguida(s))

=== RELATORIO FINAL ===
Encerrado: 3 temperaturas consecutivas acima do limite!
Leituras validas: 4
Media: 40.25
Maior: 43.0
Menor: 35.0
Acima do limite: 3 (75.0%)
```

**Resultado:** na terceira temperatura seguida acima do limite (43), o programa encerrou sozinho, sem precisar do 999, e o relatório saiu com os valores corretos (média = (35+41+42+43)/4 = 40,25 e percentual = 3/4 = 75%).

## Questão final de reflexão

**Por que você escolheu while, do...while ou uma combinação das duas estruturas? Em qual parte do algoritmo a diferença entre testar a condição antes ou depois da execução foi importante para sua solução?**

Usei uma **combinação das duas**, porque cada parte do programa pedia um tipo de teste diferente.

Para ler o **limite**, usei `do...while`. O programa precisa pedir o valor pelo menos uma vez e só depois conferir se ele é válido. Como o `do...while` testa a condição no final, o bloco sempre roda uma vez, que é o que eu queria. Com `while` eu teria que inventar um valor inicial só para conseguir entrar no laço.

Para o **monitoramento**, usei `while (seguidas < 3)`, porque a condição é verificada antes de cada leitura. Assim, quando o programa detecta 3 temperaturas consecutivas acima do limite, ele para na hora, sem pedir uma leitura a mais.

A diferença entre testar antes ou depois foi mais importante na **leitura do limite**, onde a primeira execução é obrigatória, e no **encerramento do monitoramento**, onde não pode haver leitura extra depois que o critério de parada foi atingido.
