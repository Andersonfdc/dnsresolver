# DNS RESOLVER
DNS Resolver e Port Scanner desenvolvido em linguagem C. Ele combina funcionalidades de resolução de DNS e scanner de portas para ajudar a identificar hosts e verificar portas abertas em um determinado domínio. O programa é capaz de resolver os subdomínios fornecidos em um arquivo de texto, anexando-os a um domínio-alvo. Ele consulta o sistema DNS para obter o endereço IP correspondente a cada subdomínio. Após a resolução DNS, o programa verifica a abertura de portas no IP resultante. Ele tenta conectar-se a uma porta específica e informa se a porta está aberta ou fechada.

## Funcionamento
 * 1º O usuário fornece o nome de domínio alvo, a porta a ser verificada e o nome do arquivo de texto contendo uma lista de subdomínios.
 * 2º O código lê o arquivo de texto linha por linha, concatenando cada subdomínio com o nome de domínio alvo para formar um nome de host completo.
 * 3º O código usa a função ```gethostbyname()``` para obter o endereço IP do host completo.
 * 4º Se o endereço IP for encontrado, o código imprime o nome do host completo e o endereço IP.
 * 5º O código cria um socket TCP e tenta se conectar ao host no endereço IP especificado e na porta especificada.
 * 6º Se a conexão for bem-sucedida, o código imprime uma mensagem informando que a porta está aberta.

## Modo de Uso
~~~bash
./dnsresolver .alvo.com.br porta subdomains.txt
~~~
  * alvo.com.br: O domínio de destino que você deseja analisar.
  * porta: A porta que você deseja verificar.
  * subdomains.txt: Um arquivo de texto contendo uma lista de subdomínios que você deseja resolver e verificar.
      
## Notas
* Certifique-se de que o programa seja executado com privilégios adequados, especialmente se você estiver verificando portas com números menores que 1024.
* Lembre-se de usar esta ferramenta com responsabilidade e apenas em sistemas nos quais você tenha permissão para realizar testes de penetração. Não a utilize para fins ilegais ou não éticos. Este projeto é uma demonstração de conceito e não uma ferramenta completa de segurança.

