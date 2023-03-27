
/*
 A placa de relés utilizadas trabalha com lógica inversa ,
 por isso a ativação se dá por digitalWrite (... ,0)
 */

 const char VNT1 =3;
 const char MUSC =2;
 const char VNT2 =4;
 const char SENSOR1 =5;
 const char SENSOR2 =6;

 void setup ()
 {
 // SAIDAS
 pinMode (VNT1 , OUTPUT );
 pinMode (VNT2 , OUTPUT );
 pinMode (MUSC , OUTPUT );

 // ENTRADAS
 pinMode (SENSOR1 , INPUT );
 pinMode (SENSOR2 , INPUT );
 }

 void loop ()
 {
 digitalWrite (VNT1 , 0); // Inicialização
 digitalWrite (VNT2 , 0); // Inicialização
 digitalWrite (MUSC , 1); // Inicialização


 for(int i=0;i <15;i++){ // rotina de subida
 digitalWrite (VNT2 , 0); // ativa ventosa de cima

 while (! digitalRead ( SENSOR2 )); // aguarda leitura do sensor da ventosa de cima
 delay (500);
 digitalWrite (VNT1 , 1); // desativa ventosa de baixo
 digitalWrite (MUSC , 0); // contrai o musculo
 delay (600); // espera para o musculo contrair corretamente
 digitalWrite (VNT1 , 0); // ativa ventosa de baixo e fica travado
 while (! digitalRead ( SENSOR1 )); // aguarda leitura do sensor da ventosa debaixo
 delay (500);
 digitalWrite (VNT2 , 1); // desativa a ventosa de cima
 digitalWrite (MUSC , 1); // desativa o musculo
 delay (600); // aguarda
 }
 }
