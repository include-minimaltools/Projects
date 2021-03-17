Algoritmo ATM_UNI
	Definir op,d,g,h Como entero;//declaramos las variables segun su tipo
	Definir saldo,deposito Como Real;//declaramos las variables segun su tipo
	Definir b,f,w,p,q,z,i,x,ex,pr,wu,n,flip,e,nombre,usuario,salida,r,opc,t,s como caracter;//declaramos las variables segun su tipo
	Definir num,c,cont,l,v,sf,alfin,xy,intentos,contrasenia,restantes,a,po,recarga como entero;//declaramos las variables segun su tipo
	
	intentos=0;//inicializamos la variable intentos en 0
	
	contrasenia=060720;//definimos la contraseña que usaremos para acceder al menu del cajero
	
	po=0;//inicializamos la variable po en 0
	
	saldo=0;//inicializamos la variable saldo en 0
	
	deposito=0;//inicializamos la variable depositos en 0
	
	d=0;//inicializamos la variable d en 0
	
	Mientras intentos<3 & po=0 Hacer//agregamos el ciclo "mientras" para decir que mientras intentos sean menor que 3 y po sea 0 entonces vuelve a pedir las credenciales  
		
		Borrar Pantalla;//Usamos esta instruccion para borrar la pantalla en caso de que el usuario falle o decida realizar otra transaccion
		
		Escribir "   Usuario   ";//escribimos esto para que digite su nombre de usuario
		Leer usuario;//leemos el nombre del usuario ingresado
		
		Escribir "";//hacemos esto para que no se mire tan pegadas las lineas
		
		Escribir "   Contraseña:   ";//escribimos esto para que el usuario digite la contraseña confidencial que le fue dada
		Leer a;//leemos la contraseña ingresada
		
		si usuario="admin" & a=contrasenia Entonces //comparamos, si usuario y contraseña son correctos pasamos al siguiente menu
			Borrar Pantalla;//borramos lo anterior para que se mire mejor y mas limpio
			
			//escribimos las opciones a elegir que se le presentara al usuario
			Escribir "Menu Principal:";
			Escribir "";
			Escribir "1. Presentacion";
			Escribir "2. Cajero ATM-UNI";
			Escribir "3. Recarga";
			Escribir "4. Salir";
			Leer op;//leemos la opcion que ingreso el usuario
			
			//validamos la opcion elegida por el usuario y si es incorrecta le presentamos esto
			//esto se repetira hasta que el usuario elija una opcion correcta
			
			Mientras op>4 | op<=0 hacer 
				Escribir "Opcion no valida:";//le decimos al usuario que la opcion que eligio es incorrecta o no valida
				Escribir "Vuelva a intentarlo";//le decimos que vuelva a intentarlo
				Esperar 2 Segundos;
				Borrar Pantalla;//limpiamos pantalla
				
				//volvemos a presentar el menu
				Escribir "Menu Principal:";
				Escribir "";
				Escribir "1. Presentacion";
				Escribir "2. Cajero ATM-UNI";
				Escribir "3. Recarga";
				Escribir "4. Salir";
				Leer op;
			FinMientras//si usuario elije una opcion correcta finaliza el ciclo y pasamos a lo siguiente
			
			Segun op hacer//ya que el usuario eligio una opcion correcta, pasamos a realizar la opcion elegida
				
				//si la opcion que elijio fue la primera (presentacion)
				//Lo mostramos en pantalla
				1:
					Escribir "------------Universidad----------------";
					Escribir "UNI-Universidad Nacional De Ingenieria.";
					Escribir "---------------------------------------";
					Escribir "Carrera: Ingenieria en Computacion.";
					Escribir "-------Integrantes:---------";
					Escribir "";
					Escribir "-Luis MIguel Pineda Joseph";
					Escribir " --No. De Carnet: 2020-0251U"; 
					Escribir "";
					Escribir "-Alexha Carolina Lopez Rocha";
					Escribir " --No. De Carnet: 2020-0256U";
					Escribir "";
					Escribir "-Victor Hugo Romero Espinoza";
					Escribir " --No. De Carnet: 2020-0299U";
					Escribir "";
					Escribir "Grupo: 1M1-CO.";
					Escribir "-------------------------";
					Escribir "Profesor: Nelson Alejandro Barrios.";
					Escribir "";
					Escribir "Fecha: Lunes 6 de Julio del año 2020";
					Escribir "";
					Escribir "Presione una tecla para continuar";//esta opcion es para que el usuario tenga el tiempo de leer la presentacion
					Esperar Tecla;//cuando haya terminado y presione cualquier tecla pasamos a lo siguiente
					
					Borrar Pantalla;//limpiamos pantalla
					
					//presentamos este pequeño menu
					Escribir "Desea Realizar otra transaccion";//preguntamos si desea realizar otra transaccion
					Escribir "--s";
					Escribir "--n";
					Leer opc;//leemos la opcion
					Esperar 2 segundos;//esperamos un poco
					
					
					//validamos la opcion elegida 
					
					Mientras opc<>"s" & opc<>"n" hacer//si la opcion que ingresa el usuario es distinta a "s" o "n" entonces
						Escribir "Usted ha ingresado una opcion invalida";//le decimos al usuario que ingreso una opcion incorrecta
						Escribir "--------------------------------------";
						Escribir "Desea Realizar otra transaccion";//preguntamos de nuevo si desea realizar otra transaccion
						Escribir "--s";
						Escribir "--n";
						Leer opc;//leemos la opcion
						Esperar 3 segundos;
						si opc="s" Entonces
							po=0;
							intentos=0;
						SiNo
							Si opc="n" Entonces
								po=1;
							FinSi
						FinSi
					FinMientras//el ciclo finaliza hasta que el usuario haya elegido una opcion correcta
					
					si opc="s" Entonces//si la opcion elegida es s(si) entonces
						po=0;//esta variable sigue siendo 0 y significa que volvemos al menu principal ya que si po=0 el ciclo se vuelve a repetir
						intentos=0;
					SiNo
						Si opc="n" Entonces//si elige la opcion n(no) entonces
							po=1;//esta variable se vuelve 1 y el ciclo finaliza y pasamos al ultimo mensaje de salida
						FinSi
					FinSi
					
					
					//si el usuario elije la opcion numero dos (cajero ATM-UNI)
					//Mostramos en pantalla el siguiente menu
				2:
					//le mostramos las opciones del cajero
						Borrar Pantalla;//limpiamos pantalla
						Escribir "1. Ingresar saldo en cuenta:";
						Escribir "2. Retirar saldo en cuenta:";
						Escribir "3. Consultar saldo en cuenta:";
						Leer c;//leemos la opcion y la validamos
						
						Mientras c<1 | c>3 Hacer//si elije una opcion diferente a las antes mostradas, le presentamos lo siguiente
							Escribir "Opcion no valida.";//le decimos que eligio una opcion incorrecta
							Escribir "Intentelo otra vez.";
							Escribir "Presione una tecla para continuar";//le indicamos que tiene que presionar una tecla para continuar
							Esperar Tecla;//esperamos a que presione la tecla 
							Borrar Pantalla;
							Escribir "1. Ingresar saldo en cuenta:";//opcion de ingresar dinero a la cuenta del usuario 
							Escribir "2. Retirar saldo en cuenta:";//opcion de retirar dinero de la cuenta del usuario
							Escribir "3. Consultar saldo en cuenta:";//consultar cuanto dinero tiene actualmemte la cuenta
							Leer c;//leemos la opcion que ingrese el usuario
						FinMientras//el ciclo finaliza hasta que el usuario ingrese una opcion correcta
						
						//segun la opcion que haya elegido le mostramos en pantalla la instruccion
						Segun c hacer
							1:
								//si eligio la opcion 1 entonces
								Repetir//repetimos hasta que el deposito sea mayor a cero y menor o igual que 10,000
								Borrar Pantalla;
								Escribir "Ingrese la cantidad de saldo:";//le decimos que ingrese la cantidad a depositar
								Leer deposito;//leemos la cantidad a depositar
								//validamos la variable
								si deposito>10000 Entonces//el deposito no puede ser mayor a 10,000 
									Escribir "No puede ingresar una cantidad mayor a 10000.";
									Esperar 3 Segundos;
								FinSi
								si deposito<=0 entonces//no puede depositar con numeros negativos
									Escribir "No puede ingresar numeros negativos.";
									Esperar 3 Segundos;
								FinSi
								Hasta Que deposito<=10000 & deposito>0
								saldo=saldo+deposito;//realizamos la operacion (la cual es que sumamos el saldo actual mas la cantidad depositada)
								Escribir "Saldo Ingresado exitosamente";
								Escribir "";
								Escribir "Presione una tecla para continuar"; 
								Esperar Tecla;
							2:
								Repetir//repetimos hasta que el retiro sea mayor a cero y menor o igual que el saldo actual
								Borrar Pantalla;
								Escribir "Ingrese la cantidad de saldo a retirar:";
								Leer d;
								si d>saldo Entonces
									Escribir "La cantidad supera el saldo actual.";
									Esperar 3 Segundos;
								FinSi
								si d<0 Entonces
									Escribir "No puede Ingresar numeros negativos.";
									Esperar 3 Segundos;
								FinSi
								Hasta Que d<saldo & d>0//si se cumple estas condiciones, termina el ciclo
								saldo=saldo-d;//realizamos la operacion (en la cual agarramos el saldo actual y le restamos la cantidad de retiro) y el resultado sera nuestro nuevo saldo 
								Escribir "Saldo retirado exitosamente.";
								Escribir "";
								Escribir "Presione una tecla para continuar"; 
								Esperar Tecla;
							3:
								Escribir "Su saldo actual es: ",saldo;//le hacemos ver el saldo actual de la cuenta
								Escribir "";
								Escribir "Presione una tecla para continuar"; 
								Esperar Tecla;
						FinSegun
						Borrar Pantalla;
						//presentamos este pequeño menu
						Escribir "Desea Realizar otra transaccion";//preguntamos si desea realizar otra transaccion
						Escribir "--s";
						Escribir "--n";
						Leer opc;//leemos la opcion
						Esperar 3 segundos;//esperamos un poco
						Mientras opc<>"s" & opc<>"n" hacer//si la opcion que ingresa el usuario es distinta a "s" o "n" entonces
							Escribir "Usted ha ingresado una opcion invalida";//le decimos al usuario que ingreso una opcion incorrecta
							Escribir "--------------------------------------";
							Escribir "Desea Realizar otra transaccion";//preguntamos de nuevo si desea realizar otra transaccion
							Escribir "--s";
							Escribir "--n";
							Leer opc;//leemos la opcion
							Esperar 3 segundos;
							si opc="s" Entonces
								po=0;
								intentos=0;
							SiNo
								Si opc="n" Entonces
									po=1;
								FinSi
							FinSi
						FinMientras//el ciclo finaliza hasta que el usuario haya elegido una opcion correcta
						
						si opc="s" Entonces//si la opcion elegida es s(si) entonces
							po=0;//esta variable sigue siendo 0 y significa que volvemos al menu principal ya que si po=0 el ciclo se vuelve a repetir
							intentos=0;
						SiNo
							Si opc="n" Entonces//si elige la opcion n(no) entonces
								po=1;//esta variable se vuelve 1 y el ciclo finaliza y pasamos al ultimo mensaje de salida
							FinSi
						FinSi
						
						
						
						
					//si el usuario elije la opcion numero tres (Recarga)
					//Mostramos en pantalla el siguiente menu
				3:
					Borrar Pantalla;
					Escribir "Ingrese a que compañia pertenece su numero telefonico";//le decimos que seleccione la compañia
					Escribir "1- Tigo";
					Escribir "2- Claro";
					Leer xy;//leemos la compañia
					Mientras  xy<1 | xy>2 hacer//validamos las opciones
						Escribir "------------------Opcion no valida-------------------";
						Escribir "Ingrese nuevamente a que compañia pertenece su numero telefonico";
						Escribir "1- Tigo";
						Escribir "2- Claro";
						Leer xy;
					FinMientras//se cierra el ciclo cuando el usuario ingrese una opcion valida
					Si xy=1 | xy=2 Entonces
						Escribir "Digite su numero de telefono (8 digitos)";//le pedimos al usuario que ingrese su numero telefonico
						Leer num;//leemos el numero
						
						//para obtener la longitud, primero debemos pasarlo a texto
						b<-ConvertirATexto(num);//convertimos a texto el numero telefonico ingresado
						c<-Longitud(b);//le asignamos a la variable c la longitud del numero telefonico ingresado
						
						//validamos la longitud
						si c>8 | c<8 entonces
							Repetir//repetimos esto hasta que la longitud del numero sea ni mas ni menos que de 8 digitos
								Borrar Pantalla;
								Escribir "Usted ha ingresado un numero telefonico no valido";
								Escribir "-------------------------------------------------";
								Escribir "Digite nuevamente su numero de telefono (8 digitos)";
								Leer num;
								b<-ConvertirATexto(num);
								c<-Longitud(b);
							Hasta que c=8//fin del ciclo
						FinSi
						Repetir
							Escribir "Ingrese el monto a recargar (cordobas)";//le pedimos al usuario que ingrese el minto a recargar
							Leer recarga;//leemos el monto de recarga
							
							//validamos la variable recarga para que no sobrepase el saldo actual de la cuenta
							//y tambien para que no pueda ingresar datos negativos
							si recarga>saldo Entonces
								Escribir "La cantidad a recargar supera el saldo actual.";
							FinSi
							si recarga<0 Entonces
								Escribir "No puede Ingresar numeros negativos.";
							FinSi
						Hasta que recarga<=saldo & recarga>0//fin del ciclo
						
						
						//Todas estas instrucciones son para poder validar cada digito del numero telefonico ingresado
						
						
						//ocupamos la instruccion "para" para valorar cada numero del telefono ingresado
						Para cont=1 hasta 1 con paso 1 hacer
							f=SubCadena(b,0,0);//le asignamos a una variable el valor de la cual tendra el primer digito
							l=ConvertirANumero(f);//lo convertimos a numero para usarlo, mas adelante...
							e=ConvertirATexto(l);//lo convertimos a texto para usarlo, mas adelante...
						FinPara
						//asi mismo haremos con los 7 digitos restantes
						Para cont=1 hasta 1 con paso 1 hacer
							f=SubCadena(b,1,1);
							l=ConvertirANumero(f);
							i=ConvertirATexto(l);
						FinPara
						
						Para cont=1 hasta 1 con paso 1 hacer
							f=SubCadena(b,2,2);
							l=ConvertirANumero(f);
							n=ConvertirATexto(l);
						FinPara
						
						Para cont=1 hasta 1 con paso 1 hacer
							f=SubCadena(b,3,3);
							l=ConvertirANumero(f);
							s=ConvertirATexto(l);
						FinPara
						
						Para cont=1 hasta 1 con paso 1 hacer
							f=SubCadena(b,4,4);
							l=ConvertirANumero(f);
							p=ConvertirATexto(l);
						FinPara
						
						Para cont=1 hasta 1 con paso 1 hacer
							f=SubCadena(b,5,5);
							l=ConvertirANumero(f);
							q=ConvertirATexto(l);
						FinPara
						
						Para cont=1 hasta 1 con paso 1 hacer
							f=SubCadena(b,6,6);
							l=ConvertirANumero(f);
							z=ConvertirATexto(l);
						FinPara
						
						Para cont=1 hasta 1 con paso 1 hacer
							f=SubCadena(b,7,7);
							l=ConvertirANumero(f);
							x=ConvertirATexto(l);
						FinPara
						
						//luego para unir los digitos, tomamos una variable y concatenamos "en orden" los digitos del numero telefonico
						t=Concatenar(e,i);//los primeros dos digitos los concatenamos en la variable t
						r=Concatenar(n,s);//El tercer y cuarto digito los concatenamos en la variable r
						w=Concatenar(t,r);//Ahora concatenamos la variable "t" y "r" para obtener una nueva variable con los 4 digitos juntos
						v=ConvertirANumero(w);//la convertimos a numero para usarlo mas adelante...
						
						//igual procedimiento que la anterior
						ex=Concatenar(p,q);
						pr=Concatenar(z,x);
						wu=Concatenar(ex,pr);
						sf=ConvertirANumero(wu);
						
						
						//Ahora concatenamos los primeros 4 dijitos con los otros 4
						flip=Concatenar(w,wu);//le asignamos una variable para que almacene los 8 digitos
						alfin=ConvertirANumero(flip);//lo convertimos a numero para usarlo en el mensaje de recarga
						
						
						//si el usuario elije la opcion 1 de compañia, la cual es tigo
						//estas operaciones(valoraciones) lo que haran es que valoraran los primeros 4 digitos del numero telefonico ingresado por el usuario
						//asi lograran diferenciar si el usuario ingreso el numero de otra compañia, a la cual no pertenece su numero
						Si xy=1 Entonces
							Si (v<5500) Entonces
								Escribir "Su numero ",alfin," es invalido";
							FinSi
							Si (v>=5500) && (v<=5749) Entonces
								Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";
							FinSi
							Si (v>=5750) && (v<=5779) Entonces
								Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";
								saldo=saldo-recarga;
							FinSi
							Si (v>=5780) && (v<=5789) Entonces
								Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";
							FinSi
							Si (v>=5790) && (v<=5799) Entonces
								Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";	
								saldo=saldo-recarga;
							FinSi
							Si (v>=5800) && (v<=5809) Entonces
								Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";
							FinSi
							Si (v>=5810) && (v<=5819) Entonces
								Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";
								saldo=saldo-recarga;
							FinSi
							Si (v>=5820) && (v<=6999) Entonces
								Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";
							FinSi
							Si (v>=7000) && (v<=7719) Entonces
								Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";
								saldo=saldo-recarga;
							FinSi
							Si (v>=7720) && (v<=7749) Entonces
								Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";
							FinSi
							Si (v>=7750) && (v<=8199) Entonces
								Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";
								saldo=saldo-recarga;
							FinSi
							Si (v>=8200) && (v<=8249) Entonces
								Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";
							FinSi
							Si (v>=8250) && (v<=8329) Entonces
								Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";
								saldo=saldo-recarga;
							FinSi
							Si (v>=8330) && (v<=8369) Entonces
								Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";
							FinSi
							Si (v>=8370) && (v<=8399) Entonces
								Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";
								saldo=saldo-recarga;
							FinSi
							Si (v>=8400) && (v<=8449) Entonces
								Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";
							FinSi
							Si (v>=8450) && (v<=8489) Entonces
								Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";
								saldo=saldo-recarga;
							FinSi
							Si (v>=8490) && (v<=8549) Entonces
								Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";
							FinSi
							Si (v>=8550) && (v<=8599) Entonces
								Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";
								saldo=saldo-recarga;
							FinSi
							Si (v>=8600) && (v<=8669) Entonces
								Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";
							FinSi
							Si (v>=8670) && (v<=8689) Entonces
								Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";
								saldo=saldo-recarga;
							FinSi
							Si (v>=8690) && (v<=8749) Entonces
								Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";
							FinSi
							Si (v>=8750) && (v<=8789) Entonces
								Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";
								saldo=saldo-recarga;
							FinSi
							Si (v>=8790) && (v<=8799) Entonces
								Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";
							FinSi
							Si (v>=8800) && (v<=8819) Entonces
								Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";
								saldo=saldo-recarga;
							FinSi
							Si (v>=8820) && (v<=8859) Entonces
								Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";
							FinSi
							Si (v>=8860) && (v<=8899) Entonces
								Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";
								saldo=saldo-recarga;
							FinSi
							Si (v>=8900) && (v<=8949) Entonces
								Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";
							FinSi
							Si (v>=8950) && (v<=8969) Entonces
								Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";
								saldo=saldo-recarga;
							FinSi
							Si (v>=8970) && (v<=8999) Entonces
								Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";
							FinSi
							Si (v>=9000) Entonces
								Escribir "Su numero ",num," es invalido";
							Finsi
						Finsi	
						
						
						//si el usuario elije la opcion 2 de compañia, la cual es claro
						//estas valoraciones lo que haran es que valoraran los primeros 4 digitos del numero telefonico ingresado por el usuario
						//asi lograran diferenciar si el usuario ingreso el numero de otra compañia, a la cual no pertenece su numero
							Si xy=2 Entonces
								Si (v<5500) Entonces
									Escribir "Su numero ",alfin," es invalido";
								FinSi
								Si (v>=5500) && (v<=5749) Entonces
									Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";
									saldo=saldo-recarga;
								FinSi
								Si (v>=5750) && (v<=5779) Entonces
									Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";
								FinSi
								Si (v>=5780) && (v<=5789) Entonces
									Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";
									saldo=saldo-recarga;
								FinSi
								Si (v>=5790) && (v<=5799) Entonces
									Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";								
								FinSi
								Si (v>=5800) && (v<=5809) Entonces
									Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";
									saldo=saldo-recarga;
								FinSi
								Si (v>=5810) && (v<=5819) Entonces
									Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";
								FinSi
								Si (v>=5820) && (v<=6999) Entonces
									Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";
									saldo=saldo-recarga;
								FinSi
								Si (v>=7000) && (v<=7719) Entonces
									Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";
								FinSi
								Si (v>=7720) && (v<=7749) Entonces
									Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";
									saldo=saldo-recarga;
								FinSi
								Si (v>=7750) && (v<=8199) Entonces
									Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";
								FinSi
								Si (v>=8200) && (v<=8249) Entonces
									Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";
									saldo=saldo-recarga;
								FinSi
								Si (v>=8250) && (v<=8329) Entonces
									Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";
								FinSi
								Si (v>=8330) && (v<=8369) Entonces
									Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";
									saldo=saldo-recarga;
								FinSi
								Si (v>=8370) && (v<=8399) Entonces
									Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";
								FinSi
								Si (v>=8400) && (v<=8449) Entonces
									Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";
									saldo=saldo-recarga;
								FinSi
								Si (v>=8450) && (v<=8489) Entonces
									Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";
								FinSi
								Si (v>=8490) && (v<=8549) Entonces
									Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";
									saldo=saldo-recarga;
								FinSi
								Si (v>=8550) && (v<=8599) Entonces
									Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";
								FinSi
								Si (v>=8600) && (v<=8669) Entonces
									Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";
									saldo=saldo-recarga;
								FinSi
								Si (v>=8670) && (v<=8689) Entonces
									Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";
								FinSi
								Si (v>=8690) && (v<=8749) Entonces
									Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";
									saldo=saldo-recarga;
								FinSi
								Si (v>=8750) && (v<=8789) Entonces
									Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";
								FinSi
								Si (v>=8790) && (v<=8799) Entonces
									Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";
									saldo=saldo-recarga;
								FinSi
								Si (v>=8800) && (v<=8819) Entonces
									Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";
								FinSi
								Si (v>=8820) && (v<=8859) Entonces
									Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";
									saldo=saldo-recarga;
								FinSi
								Si (v>=8860) && (v<=8899) Entonces
									Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";
								FinSi
								Si (v>=8900) && (v<=8949) Entonces
									Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";
									saldo=saldo-recarga;
								FinSi
								Si (v>=8950) && (v<=8969) Entonces
									Escribir "Su numero ","+505 ",alfin," pertenece a otra compañia";
								FinSi
								Si (v>=8970) && (v<=8999) Entonces
									Escribir "Su recarga al numero ","+505 ",alfin," ha sido exitosa";
									saldo=saldo-recarga;
								FinSi
								Si (v>=9000) Entonces
									Escribir "Su numero ",num," es invalido";
								Finsi
							FinSi
						FinSi
					Escribir "Presione una tecla para continuar";
					Esperar Tecla;
					Escribir "";
					Borrar Pantalla;
					//presentamos este pequeño menu
					Escribir "Desea Realizar otra transaccion";//preguntamos si desea realizar otra transaccion
					Escribir "--s";
					Escribir "--n";
					Leer opc;//leemos la opcion ingresada por el usuario y la validamos
					Esperar 3 segundos;//esperamos un poco
					si opc="s" Entonces
						po=0;
						intentos=0;
					SiNo
						Si opc="n" Entonces
							po=1;
						FinSi
					FinSi
					Mientras opc<>"s" & opc<>"n" hacer//si la opcion que ingresa el usuario es distinta a "s" o "n" entonces
						Escribir "Usted ha ingresado una opcion invalida";//le decimos al usuario que ingreso una opcion incorrecta
						Escribir "--------------------------------------";
						Escribir "Desea Realizar otra transaccion";
						Escribir "--s";
						Escribir "--n";
						Leer opc;
						Esperar 3 segundos;
						si opc="s" Entonces
							po=0;
							intentos=0;
						SiNo
							Si opc="n" Entonces
								po=1;
							FinSi
						FinSi
					FinMientras//el ciclo finaliza hasta que el usuario haya elegido una opcion correcta
				4:
					//si el usuario elije la opcion numero cuatro (Salida)
					//Mostramos en pantalla el siguiente menu
					Borrar Pantalla;
						Escribir "Desea Realizar otra transaccion";//como opcion de salida le preguntamos al usuario si quiere realizar otra transaccion
						Escribir "--s";//s significa "si"
						Escribir "--n";//n significa "no"
						Leer opc;//leemos la opcion ingresada por el usuario
						Esperar 3 segundos;//esperamos un poquito de tiempo para no ir tan rapido 
						
						Mientras opc<>"s" & opc<>"n" hacer//si la opcion que ingresa el usuario es distinta a "s" o "n" entonces
							Escribir "Usted ha ingresado una opcion invalida";//le decimos al usuario que ingreso una opcion incorrecta
							Escribir "--------------------------------------";
							Escribir "Desea Realizar otra transaccion";//preguntamos de nuevo si desea realizar otra transaccion
							Escribir "--s";//s significa "si"
							Escribir "--n";//n significa "no"
							Leer opc;//leemos nuevamente la opcion ingresada por el usuario
							Esperar 3 segundos;
							si opc="s" Entonces//si ingresa la letra s(si) entonces po sigue siendo 0 y vuelve a pedir las credenciales
								po=0;//esta variable sigue siendo 0 y significa que volvemos al menu principal ya que si po=0 el ciclo se vuelve a repetir
								intentos=0;
							SiNo
								Si opc="n" Entonces
									po=1;//si po=1 el ciclo llega a su fin y pasa directamente al mensaje de salida
								FinSi
							FinSi
						FinMientras
						si opc="s" Entonces
							po=0;//esta variable sigue siendo 0 y significa que volvemos al menu principal ya que si po=0 el ciclo se vuelve a repetir
							intentos=0;
						SiNo
							Si opc="n" Entonces
								po=1;//si po=1 el ciclo llega a su fin y pasa directamente al mensaje de salida
							FinSi
						FinSi
			FinSegun//fin de todo
		SiNo
			//aqui lo que hicimos fue valorar cada posible caso, y presentarle en pantalla
			//si fue en el usuario,contraseña o ambos en donde tuvo el error
			Si usuario<>"admin" & a=contrasenia Entonces
				Escribir "Usuario Incorrecto";
				//si intentos llegan a 3 y restantes a 0 aparecera un mensaje en pantalla
				intentos=intentos+1;
				restantes=3 - intentos;
				Esperar 3 segundos;
				Escribir "";
				Escribir "Lleva ",intentos," intentos"; 
				Escribir "Le restan ",restantes," intentos";
				Esperar 3 segundos;
			SiNo
				Si a<>contrasenia & usuario="admin" Entonces
					Escribir "Contraseña incorrecta";
					//si intentos llegan a 3 y restantes a 0 aparecera un mensaje en pantalla
					intentos=intentos+1;
					restantes=3 - intentos;
					Esperar 3 segundos;
					Escribir "";
					Escribir "Lleva ",intentos," intentos"; 
					Escribir "Le restan ",restantes," intentos";
					Esperar 3 segundos;
				SiNo
					Escribir "Usario y contraseña incorrectos";
					//si intentos llegan a 3 y restantes a 0 aparecera un mensaje en pantalla
					intentos=intentos+1;
					restantes=3 - intentos;
					Esperar 3 segundos;
					Escribir "";
					Escribir "Lleva ",intentos," intentos"; 
					Escribir "Le restan ",restantes," intentos";
					Esperar 3 segundos;
				FinSi
			FinSi
		FinSi
		si intentos=3 Entonces//mensaje de bloqueo por haber alcanzado el numero maximo de intentos
			Escribir "";
			Borrar Pantalla;
			Escribir "Ha agotado sus 3 intentos";
			Escribir "-------------------------";
			Escribir "Estimado Usuario: admin";
			Escribir "Su cuenta sera bloqueada por 24 horas";
			Escribir "Por motivos de seguridad";
			Escribir "Gracias por su comprension";
			Escribir "";
		FinSi
	FinMientras
	//mensaje de despedida o salida
Escribir "Estamos Para Servirle 7u7";
Escribir "Que tenga un buen dia UwU";
FinAlgoritmo


