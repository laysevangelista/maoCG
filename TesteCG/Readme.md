# Trabalho Final de Computaçao Gráfica

<h2>TRABALHO REALIZADO POR: </h2>
	<h3> Ronaldo Juniro 
	     Lays F. E. Popova</h3>
	
	
<h4> trabalho desenvolvido no Visual Studio (Windows) e XCode (MacOS)
Crie um programa que simule uma mão mecânica em 3D.  

A mão deve ser a mais parecida possível com a anatomia de uma mão humana, ou seja, conter um punho e cinco dedos articulados, sendo um dos dedos um polegar opositor (capaz de fazer um movimento de pinça com o dedo indicador). 

O programa deve ser programado em C++, utilizando a biblioteca OpenGL.

Requisitos do programa:

1) O usuário deve poder articular de forma independente cada dedo (abrir e fechar).
	- 1-> dedao
	- 2-> indicador
	- 3-> dedo do meio
	- 4-> anelar
	- 5-> mindinho
2) O usuário também deve poder articular o pulso.
	- tecla m -> levanta o pulso
	- tecla n -> abaixa o pulso
3) O movimento do sistema (pulso e dedos) deve ser controlado pelo usuário através do teclado ou mouse (ou combinações).
	- tecla d -> fecha a mão
	- tecla a -> abre a mão / fecha cada dedo
	
4) O sistema deve ser observado através de um Viewport com uma transformação projetiva.
 

5) Deve ser possível realizar, a partir de comandos do teclado ou mouse, movimentos de câmera (zoom e pan).

	-tecla w -> almenta o zoom
	-tecla s -> diminui o zoom
	-teclas j e l -> giram o eixo x;
	-teclas i e k -> giram o eixo z;
	-teclas t e g -> transladam em y;
	-teclas f e h -> transladam em x;


Observações:

1) O trabalho pode ser feito em grupos de até três alunos.

2) O trabalho deve ser submetido até as 7:00hs do dia 20 de agosto de 2018 (impreterivelmente).

3) Devem ser entregues: as fontes do programa em C++ e um pequeno manual de instruções, via e-mail ou AVA/Moodle. 

4) Caso o programa tenha sido desenvolvido para Windows, enviar também o executável.

5) Este trabalho terá o mesmo peso que a prova na média final do aluno.

6) Caso dois ou mais trabalhos tenham o mesmo código (ou códigos muito semelhantes), todos receberão nota zero.

7) Além do OpenGL e GLUT, não será permitido o uso de bibliotecas ou APIs proprietárias (isto fará com que seu trabalho receba nota zero). Só é permitida a utilização da biblioteca RgbImage (disponível junto com o Tópico 7), para a leitura de imagens de textura.

8) O aspecto artístico (textura, iluminação, etc.) será considerado na atribuição da nota.
