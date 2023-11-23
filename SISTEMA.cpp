#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//Constantes para o número de senhas e dígitos
#define QNT_senhas 10
#define digito 3

main(void){
// Apresentação do sistema
sleep(1); 
printf("\n|-------------------------------------------------|\n");
printf("\n|                   SISTEMA ESCOLAR               |\n");
printf("\n|-------------------------------------------------|\n");
sleep(1.5); 
system("cls");
printf("-----------------CADASTRO DE SENHAS-----------------\n");

  int senha[QNT_senhas];	// Array para armazenar senhas
  
  // Variáveis para entrada de senha
  int senhaDigitada;   
  int senhaCadastrada;
  
  bool verifica = false; // Variável de controle para verificar se a senha está correta
  
printf("-----*VALIDO SOMENTE SENHAS CONTENDO %d DIGITOS*-----", digito);
printf("\n\n\n-----CADASTRE %d SENHAS-----", QNT_senhas);
  
  for(int i = 0 ; i < QNT_senhas ; i++){	// Cadastro de senha
        
  //Loopings para validar senhas
  do{
    
    printf("\nDIGITE A SENHA DE NUMERO %d:\n", i + 1);			
      scanf("%d", &senhaCadastrada);
      
      if(senhaCadastrada < 99 || senhaCadastrada > 999){			
      printf("\nSENHA INVALIDA! TENTE NOVAMENTE");						
      }
      
      for(int j = 0 ; j < i ; j++){  //for para identificar se a senha foi insirida anteriormente
                    
        if (senhaCadastrada == senha[j]){
          printf("\nSENHA JA CADASTRADA! TENTE NOVAMENTE");
          senhaCadastrada = 1;
          break;
      }
    }
                                          
  }while(senhaCadastrada < 99 || senhaCadastrada > 999);
  
senha[i] = senhaCadastrada;	//senha [i] recebe senha validada					  								
}
      
system("cls");	
printf("\n-----SENHAS CADASTRADAS COM SUCESSO!!-----\n");
sleep(2);
system("cls");
printf("\n|-------------------------------------------------|\n");
printf("\n|                       LOGIN                     |\n");
printf("\n|-------------------------------------------------|\n");
sleep(0.5);
    

//sistema de login
int cont = 0;
#define limiteTentativas 6 //numero de tentativas para fazer login
    
while (!verifica){ 
  sleep(0.5);
  
    printf("\nDIGITE UMA SENHA PARA ENTRAR: ");
    
    scanf("%d", &senhaDigitada);
        
     for (int i = 1; i <= QNT_senhas; i++){ //lopping de verificação
      
         if (senha[i] == senhaDigitada){
             system("cls");
             printf("\n--VOCE ENTROU--\n");
             sleep(1);
             system("cls");
             verifica = true;
             break;
          }
      }
      

      if (!verifica){  
    system("cls");      	
          printf("\n\nSenha incorreta. Tente novamente\n\n");
          cont = cont + 1;
          
          if(cont > 2){						
            printf("\n\nATENCAO! %d TENTATIVAS RESTANTES ANTES DE BLOQUEAR", limiteTentativas - cont );
        }
      }
      
      
    while(cont == limiteTentativas){ //looping de bloqueio caso as tentativas tenham exedido
      system("cls");
      printf("\n\n\\\\\\\\\\\ACESSO NEGADO////////////");
      printf("\n\\\\\\\\\\\SISTEMA BLOQUEADO////////\n");
      system("pause");
  }
  
  }
      
  int opcao = 0;				//variavel para controlar o looping do menu
  int NumOpcoes[3] = {1,2,3}; //variavel para controlar o numero de opcoes do menu							

sleep(1);    
printf("|-------------------------------------------------|\n");
printf("\n|                  SEJA BEM VINDO!!               |\n");
printf("\n|-------------------------------------------------|\n");

while(opcao != 3){	//looping do menu de opções
  //interface do menu de opções
  sleep(2); 
  system("cls");
  printf("--------MENU DE OPCOES---------\n");
  sleep(0.5);
  printf("\nDIGITE O NUMERO DE UMA DAS OPCOES ABAIXO\n");
  sleep(0.5); 
  printf("\n1. CALCULAR MEDIA DO ALUNO");
  sleep(0.5); 
  printf("\n2. VERIFICAR IDADE DE ALUNO");
  sleep(0.5); 
  printf("\n3. SAIR\n");
          
  int verificacao; //variavel de controle
  
  do{//verfica se o numero digitado é valido
    verificacao = scanf("%d", &opcao);	
      
    if(verificacao != 1 || (opcao != NumOpcoes[0] && opcao != NumOpcoes[1] && opcao != NumOpcoes[2])){
      printf("\nNUMERO DIGITADO INVALIDO. TENTE NOVAMENTE\n");
      while (getchar() != '\n');
    }
    
  }while(verificacao != 1 || (opcao != NumOpcoes[0] && opcao != NumOpcoes[1] && opcao != NumOpcoes[2]));
  

  if(opcao == NumOpcoes[0]){ //primeira opção 
    //interface primeira opção												
    system("cls");		
    printf("------CALCULAR MEDIA DO ALUNO------\n");
    sleep(1);
    printf("\n-POR FAVOR INSIRA A QUANTIDADE DE NOTAS QUE DESEJA CADASTRAR--\n");
    
    int QNT_notas;
    int result;		
  
    do{//verfica se o numero digitado é valido	
                                  
            result = scanf("%d", &QNT_notas);

      if(result != 1){
            printf("\nNUMERO DIGITADO INVALIDO. TENTE NOVAMENTE\n");
              while (getchar() != '\n');
          }

      }while(result != 1);
      while (getchar() != '\n');//limpa buffer do teclado
          
    float nota[result], mediaNotas, somaNotas;
    
    system("cls");
    printf("\nOK! VAMOS CADASTRAR %d notas\n", QNT_notas);
    sleep(1);
      for(int i = 1 ; i <= QNT_notas ; i++){ //processo aritimetico
        
        printf("\nINSIRA A NOTA %d:\n", i);
        scanf("%f", &nota[i]);
        somaNotas = somaNotas + nota[i];
        mediaNotas = (somaNotas / QNT_notas);
       }
       //interface dos resultados
       system("cls");
       sleep(0.5);
       printf("\n--------------SISTEMA--------------\n");
       printf("\n------CALCULAR MEDIA DO ALUNO------\n");
       printf("\n-------------CONCLUIDO-------------\n");
       sleep(1);
       printf("\n\nTOTAL DE NOTAS INSIRIDAS- - - - - -: %d\n", QNT_notas);
       printf("\nTOTAL DAS NOTAS SOMADAS- - - - - - : %.2f\n", somaNotas);
       printf("\nMEDIA ENTRE AS NOTAS SOMADAS- - - -: %.2f\n", mediaNotas);
       printf("\n\nPRESSIONE QUALQUER TECLA PARA VOLAR PARA O MENU\n\n");
       system("pause");				   		 
   }
  
    if(opcao == NumOpcoes[1]){//segunda opção 
    
    //interface segunda opção  		
      system("cls");		
      printf("--------------------VERIFICAR IDADE DOS(as) ALUNO(as)--------------------\n");
    sleep(1);
    printf("\n-POR FAVOR INSIRA A QUANTIDADE DE ALUNOS(as) QUE DESEJA VERIFICAR--\n");
    int QNT_aluno;
    int result;	
  
    do{	 //verfica se o numero digitado é valido
                                  
            result = scanf("%d", &QNT_aluno);

      if(result != 1){
            printf("\nNUMERO DIGITADO INVALIDO. TENTE NOVAMENTE\n");
              while (getchar() != '\n'); //buffer no teclado
          }
          
            
      }while(result != 1);
      char nome[QNT_aluno][50];//vetor para os nomes dos alunos
    int idade[QNT_aluno]; // vetor para suas idades
    
    system("cls");
    printf("\nOK! VAMOS CADASTRAR %d ALUNOS(as)\n", QNT_aluno);
    sleep(1);
    fflush(stdin); // Limpa o buffer do teclado
    
      for (int i = 0 ; i < QNT_aluno ; i++){//looping para cadatrar alunos de acordo com o numero informado
      printf("\nDIGITE O NOME DO(a) ALUNO(a) %d\n", i + 1);	
      fgets(nome[i], 50, stdin);
          nome[i][strcspn(nome[i], "\n")] = '\0'; // Remove o caractere de nova linha do final
                        
        printf("\nDIGITE A IDADE DE %s\n", nome[i]);
        scanf("%d", &idade[i]);	    	
                  
        system("cls");
        fflush(stdin); // Limpa o buffer do teclado
                  
    }
    //interface de resultados
    system("cls");
    printf("------------------SISTEMA---------------------\n");
    printf("-------VERIFICAR IDADE DE ALUNO(as)-----------\n");
    printf("-----------------CONCLUIDO--------------------\n");
    sleep(1);
    
    int cont = 0;
    while(cont < QNT_aluno){ //verificar se aluno é maior de idade ou nao
      printf("\nALUNO(A): %s\n", nome[cont]);
      printf("IDADE: %d\n", idade[cont]);
      
      if(idade[cont] < 18){
        
        printf("MENOR DE IDADE\n");					
      }else{
        printf("MAIOR DE IDADE\n");
      }
      
      cont++;								
    }
    printf("\n\nPRESSIONE QUALQUER TECLA PARA VOLAR PARA O MENU\n\n");
    system("pause");
                
  }//fim segunda opcao
  
//fim looping do menu	/	   		       
 }system("cls");
printf("\n----------OBRIGADO POR USAR NOSSO SISTEMA----------\n"); //tela final
}
            









	
	

