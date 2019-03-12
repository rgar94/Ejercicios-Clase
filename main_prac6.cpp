
//Semestre 2019 - 2
 /*
 García Callejas Ricardo
 Grupo 2
 Visual Studio 2017
 Práctica 6
 Manual:
 */
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol=0;
int mercurio = 0;
int venus = 0;
int tierra = 0;
int marte = 0;
int jupiter = 0;
int saturno = 0;
int urano = 0;
int neptuno = 0;
int luna1 = 0;
int luna2 = 0;
int luna3 = 0;
int luna4 = 0;
int luna5 = 0;
int anillo1 = 0;
int anillo2 = 0;
float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[]= { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[]= { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[]= { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX,0.0,-5.0+camaraZ);			//camara
	glPushMatrix();
	
		glPushMatrix();
			glRotatef(sol,0.0,1.0,0.0);	//El Sol gira sobre su eje
			glColor3f( 1.0,1.0,0.0 );	//Sol amarillo
			glutSolidSphere(1.9,12,12);  //Draw Sun (radio,H,V);
		glPopMatrix();
	glPopMatrix();
		glPushMatrix();
		glRotatef(mercurio, 0.0, 1.0, 0.0);	//Mercurio gira sobre su eje
		glTranslatef(5.0, 0.0, 0.0);	
		glColor3f(1.0, 0.458, 0.078);	//color naranja
		glRotatef(mercurio, 0.0, 1.0, 0.0);	//Mercurio gira sobre su eje
		glutSolidSphere(0.5, 12, 12);  //Draw mercurio
		glPopMatrix();
		glPushMatrix();
		glRotatef(venus, 0.0, 1.0, 0.0);	//Mercurio gira sobre su eje
		glTranslatef(9.0, 0.0, 0.0);
		glColor3f(0.9, 0.8, 0.4);	//color naranja
		glRotatef(venus, 0.0, 1.0, 0.0);	//Mercurio gira sobre su eje
		glutSolidSphere(0.8, 12, 12);  //Draw mercurio
		glPopMatrix();
		glPushMatrix();
		glRotatef(tierra, 0.0, 1.0, 0.0);	//tierra gira sobre su eje
		glTranslatef(12.0, 0.0, 0.0);
		glColor3f(0.0, 0.5, 0.5);	//color azul
		glRotatef(tierra, 0.0, 1.0, 0.0);	//tierra gira sobre su eje
		glutSolidSphere(1.3, 12, 12);  //Draw tierra
			glPushMatrix();
			glRotatef(luna1, 0.0, 1.0, 0.0);	//luna1 gira sobre su eje
			glTranslatef(2.0, 1.0, 0.0);
			glColor3f(0.6, 0.6, 0.6);	//color gris
			glRotatef(luna1, 0.0, 1.0, 0.0);	//luna1 gira sobre su eje
			glutSolidSphere(0.5, 12, 12);  //Draw luna1
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();
		glRotatef(marte, 0.0, 1.0, 0.0);	//marte gira sobre su eje
		glTranslatef(16.0, 0.0, 0.0);
		glColor3f(1.0, 0.0, 0.0);	//color rojo
		glRotatef(marte, 0.0, 1.0, 0.0);	//marte gira sobre su eje
		glutSolidSphere(1.0, 12, 12);  //Draw marte
		glPopMatrix();

		glPushMatrix();
		glRotatef(jupiter, 0.0, 1.0, 0.0);	//jupiter gira sobre su eje
		glTranslatef(20.0, 0.0, 0.0);
		glColor3f(0.9, 0.7, 0.6);	//color naranja
		glRotatef(jupiter, 0.0, 1.0, 0.0);	//jupiter gira sobre su eje
		glutSolidSphere(1.7, 12, 12);  //Draw jupiter
			glPushMatrix();
			glRotatef(luna2, 0.0, 1.0, 0.0);	//luna2 gira sobre su eje
			glTranslatef(2.0, 1.0, 0.0);
			glColor3f(0.6, 0.6, 0.6);	//color gris
			glRotatef(luna2, 0.0, 1.0, 0.0);	//luna2 gira sobre su eje
			glutSolidSphere(0.4, 12, 12);  //Draw luna1
			glPopMatrix();			
			glPushMatrix();
			glRotatef(luna3, 0.0, 1.0, 0.0);	//luna3 gira sobre su eje
			glTranslatef(2.0, -2.0, 0.0);
			glColor3f(0.6, 0.6, 0.6);	//color gris
			glRotatef(luna3, 0.0, 1.0, 0.0);	//luna3 gira sobre su eje
			glutSolidSphere(0.3, 12, 12);  //Draw luna1
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();
		glRotatef(saturno, 0.0, 1.0, 0.0);	//saturno gira sobre su eje
		glTranslatef(24.0, 0.0, 0.0);
		glColor3f(0.9, 1.0, 0.3);	//color 
		glRotatef(saturno, 0.0, 1.0, 0.0);	//saturno gira sobre su eje
		glutSolidSphere(1.4, 12, 12);  //Draw saturno
			glPushMatrix();
			glColor3f(0.9, 1.0, 0.8);	//color 
			glRotatef(anillo1, 0.0, 1.0, 0.0);	//anillo1 gira sobre su eje
			glutSolidTorus(0.5,1, 10,50);  //Draw saturno
			glRotatef(45, 0.0, 0.0, 1.0);
			glColor3f(1.0,0.74, 0.1);	//color 
			glRotatef(anillo1, 0.0, 1.0, 0.0);	//anillo2 gira sobre su eje
			glutSolidTorus(0.5, 2,10, 50);  //Draw saturno
			glPopMatrix();
			glPopMatrix();
		glPushMatrix();
		glPushMatrix();
		glRotatef(urano, 0.0, 1.0, 0.0);	//urano gira sobre su eje
		glTranslatef(28.0, 0.0, 0.0);
		glColor3f(0.6, 0.6, 0.6);	//color gris
		glRotatef(urano, 0.0, 1.0, 0.0);	//urano gira sobre su eje
		glutSolidSphere(1.2, 12, 12);  //Draw urano
		glPopMatrix();
		glPushMatrix();
		glRotatef(neptuno, 0.0, 1.0, 0.0);	//neptuno gira sobre su eje
		glTranslatef(31.0, 0.0, 0.0);
		glColor3f(0.2, 0.0, 1.0);	//color azul
		glRotatef(neptuno, 0.0, 1.0, 0.0);	//neptuno gira sobre su eje
		glutSolidSphere(0.9, 12, 12);  //Draw neptuno

			glPushMatrix();
			glRotatef(luna5, 0.0, 1.0, 0.0);	//luna5 gira sobre su eje
			glTranslatef(2.0, -2.0, 0.0);
			glColor3f(0.6, 0.6, 0.6);	//color gris
			glRotatef(luna5, 1.0, 0.0, 0.0);	//luna5 gira sobre su eje
			glutSolidSphere(0.3, 12, 12);  //Draw luna5
			glRotatef(luna4, 1.0, 0.0, 0.0);	//luna5 gira sobre su eje
			glTranslatef(2.0, 1.0, 0.0);
			glColor3f(0.6, 0.6, 0.6);	//color gris
			glRotatef(luna4, 1.0, 0.0, 0.0);	//luna5 gira sobre su eje
			glutSolidSphere(0.4, 12, 12);  //Draw luna5
			glPopMatrix();
		glPopMatrix();
	glutSwapBuffers ( );

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;
	
	if(dwElapsedTime >= 30)
	{
	sol = (sol - 5) % 360;
		mercurio = (mercurio - 10) % 360;
		venus = (venus - 7) % 360;
		dwLastUpdateTime = dwCurrentTime;
		tierra = (tierra - 6) % 360;
		dwLastUpdateTime = dwCurrentTime;
		marte = (marte + 8) % 360;
		dwLastUpdateTime = dwCurrentTime;
		jupiter = (jupiter - 4) % 360;
		dwLastUpdateTime = dwCurrentTime;
		saturno = (saturno +3) % 360;
		dwLastUpdateTime = dwCurrentTime;
		urano = (urano - 2) % 360;
		dwLastUpdateTime = dwCurrentTime;
		neptuno = (neptuno + 1) % 360;
		dwLastUpdateTime = dwCurrentTime;
		luna1 = (luna1 - 1) % 360;
		dwLastUpdateTime = dwCurrentTime;
		luna2 = (luna3 - 3) % 360;
		dwLastUpdateTime = dwCurrentTime;
		luna4 = (luna4 - 4) % 360;
		dwLastUpdateTime = dwCurrentTime;
		luna5 = (luna5 - 3) % 360;
		dwLastUpdateTime = dwCurrentTime;
		anillo1 = (anillo1 - 2) % 360;
		dwLastUpdateTime = dwCurrentTime;
		anillo2 = (anillo2 - 1) % 360;
		dwLastUpdateTime = dwCurrentTime;
	
	}
	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			camaraZ +=0.5f;
			break;
		case 's':
		case 'S':
			camaraZ -=0.5f;
			break;
		case 'a':
		case 'A':
			camaraX -= 0.5f;
			break;
		case 'd':
		case 'D':
			camaraX += 0.5f;
			break;

		case 'i':		//Movimientos de Luz
		case 'I':
			
			break;
		case 'k':
		case 'K':
			
			break;

		case 'l':   //Activamos/desactivamos luz
		case 'L':
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		
		break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		
		break;
	case GLUT_KEY_LEFT:
		
		break;
	case GLUT_KEY_RIGHT:
		
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (20, 60);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 6"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}