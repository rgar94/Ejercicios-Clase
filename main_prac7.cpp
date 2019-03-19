
//Semestre 2019 - 2
 /*
 García Callejas Ricardo
 Grupo 2
 Visual Studio 2017
 Práctica 7
 Manual:Con el uso de los conocimientos del uso de las funciones gllighfv y glmaterial para poder definir
 el tipo de luz y el tipo de ilumninacion que tendran los planetas
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


static int spin = 0;


GLfloat LightAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; 			// Ambient Light Values
GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat LightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat LightPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position
GLfloat LightPosition1[] = { 0.0f, 0.0f, 1.0f, 0.0f };			// Light Position
GLfloat LightDirection[] = { 0.0f, 0.0f, -2.0f };			// Light Position

GLfloat SunDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.0, 0.0, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MercurioDiffuse[] = { 1.0f, 0.458f, 0.078f, 1.0f };			// Mercurio
GLfloat MercurioSpecular[] = { 1.0f, 0.458f, 0.078f, 1.0 };
GLfloat MercurioShininess[] = { 100.0 };

GLfloat VenusDiffuse[] = { 0.0f, 0.5f, 0.5f, 1.0f };			// Venus
GLfloat VenusSpecular[] = { 0.0f, 0.5f, 0.5f, 1.0 };
GLfloat VenusShininess[] = { 90.0 };

GLfloat JupiterDiffuse[]= { 0.9f, 0.7f, 0.8f, 1.0f };			// Jupiter
GLfloat JupiterSpecular[] = { 0.9f, 0.7f, 0.8f, 1.0 };
GLfloat JupiterShininess[] = { 75.0 };

GLfloat SaturnDiffuse[] = { 0.9f, 1.0f, 0.3f, 1.0f };			// Saturno
GLfloat SaturnSpecular[] = { 0.9f, 1.0f, 0.3f, 1.0 };
GLfloat SaturnShininess[] = { 70.0 };

GLfloat UranusDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Urano
GLfloat UranusSpecular[] = { 0.2f, 0.2f, 1.0f, 1.0 };
GLfloat UranusShininess[] = { 65.0 };

GLfloat NeptuneDiffuse[] = { 0.0f, 1.0f, 0.0f, 1.0f };			// Neptuno
GLfloat NeptuneSpecular[] = { 0.0f, 1.0f, 0.0f, 1.0 };
GLfloat NeptuneShininess[] = { 65.0 };


GLfloat MoonDiffuse[]= { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 0.8f, 0.8f, 0.8f, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat RingDiffuse[] = { 0.9f, 1.0f, 0.8f, 1.0f };			// anillo
GLfloat RingSpecular[] = { 0.9f, 1.0f, 0.8f, 1.0 };
GLfloat RingShininess[] = { 80.0 };

GLfloat MarsDiffuse[]= { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 0.8f, 0.4f, 0.1f, 1.0 };
GLfloat MarsShininess[] = { 80.0 };

void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);				// Setup The Ambient Light
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);				// Setup The Diffuse Light
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular);				// Setup The Diffuse Lights
	
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX,0.0,-5.0+camaraZ);			//camara
	glPushMatrix();
	glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
		glPushMatrix();
			glRotatef(sol,0.0,1.0,0.0);	//El Sol gira sobre su eje
			glColor3f( 1.0,1.0,0.0 );	//Sol amarillo
			glDisable(GL_LIGHTING);
			glutSolidSphere(1.9, 50, 50);  //Draw Sun (radio,H,V);
			glEnable(GL_LIGHTING);

		glPopMatrix();
	glPopMatrix();
		glPushMatrix();
		glRotatef(mercurio, 0.0, 1.0, 0.0);	//Mercurio gira sobre su eje
		glTranslatef(5.0, 0.0, 0.0);	
		glColor3f(1.0, 0.458, 0.078);	//color naranja
		glRotatef(mercurio, 0.0, 1.0, 0.0);	//Mercurio gira sobre su eje
		glMaterialfv(GL_FRONT, GL_DIFFUSE, MercurioDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, MercurioSpecular);
		glutSolidSphere(0.5, 12, 12);  //Draw mercurio
		glPopMatrix();
		glPushMatrix();
		glRotatef(venus, 0.0, 1.0, 0.0);	//Mercurio gira sobre su eje
		glTranslatef(9.0, 0.0, 0.0);
		glColor3f(0.9, 0.8, 0.4);	//color naranja
		glRotatef(venus, 0.0, 1.0, 0.0);	//venus gira sobre su eje
		glMaterialfv(GL_FRONT, GL_DIFFUSE, VenusDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, VenusSpecular);
		glutSolidSphere(0.8, 12, 12);  //venus mercurio
		glPopMatrix();
		glPushMatrix();
		glRotatef(tierra, 0.0, 1.0, 0.0);	//tierra gira sobre su eje
		glTranslatef(12.0, 0.0, 0.0);
		glColor3f(0.0, 0.5, 0.5);	//color azul
		glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, EarthSpecular);
		glRotatef(tierra, 0.0, 1.0, 0.0);	//tierra gira sobre su eje
		glutSolidSphere(1.3, 12, 12);  //Draw tierra
			glPushMatrix();
			glRotatef(luna1, 0.0, 1.0, 0.0);	//luna1 gira sobre su eje
			glTranslatef(2.0, 1.0, 0.0);
			glColor3f(0.6, 0.6, 0.6);	//color gris
			glRotatef(luna1, 0.0, 1.0, 0.0);	//luna1 gira sobre su eje
			glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
			glutSolidSphere(0.5, 12, 12);  //Draw luna1
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();
		glRotatef(marte, 0.0, 1.0, 0.0);	//marte gira sobre su eje
		glTranslatef(16.0, 0.0, 0.0);
		glColor3f(1.0, 0.0, 0.0);	//color rojo
		glRotatef(marte, 0.0, 1.0, 0.0);	//marte gira sobre su eje
		glMaterialfv(GL_FRONT, GL_DIFFUSE, MarsDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, MarsSpecular);
		glutSolidSphere(1.0, 12, 12);  //Draw marte
		glPopMatrix();

		glPushMatrix();
		glRotatef(jupiter, 0.0, 1.0, 0.0);	//jupiter gira sobre su eje
		glTranslatef(20.0, 0.0, 0.0);
		glColor3f(0.9, 0.7, 0.6);	//color naranja
		glRotatef(jupiter, 0.0, 1.0, 0.0);	//jupiter gira sobre su eje
		glMaterialfv(GL_FRONT, GL_DIFFUSE, JupiterDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, JupiterSpecular);
		glutSolidSphere(1.7, 12, 12);  //Draw jupiter
			glPushMatrix();
			glRotatef(luna2, 0.0, 1.0, 0.0);	//luna2 gira sobre su eje
			glTranslatef(2.0, 1.0, 0.0);
			glColor3f(0.6, 0.6, 0.6);	//color gris
			glRotatef(luna2, 0.0, 1.0, 0.0);	//luna2 gira sobre su eje
			glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
			glutSolidSphere(0.4, 12, 12);  //Draw luna1
			glPopMatrix();			
			glPushMatrix();
			glRotatef(luna3, 0.0, 1.0, 0.0);	//luna3 gira sobre su eje
			glTranslatef(2.0, -2.0, 0.0);
			glColor3f(0.6, 0.6, 0.6);	//color gris
			glRotatef(luna3, 0.0, 1.0, 0.0);	//luna3 gira sobre su eje
			glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
			glutSolidSphere(0.3, 12, 12);  //Draw luna1
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();
		glRotatef(saturno, 0.0, 1.0, 0.0);	//saturno gira sobre su eje
		glTranslatef(24.0, 0.0, 0.0);
		glColor3f(0.9, 1.0, 0.3);	//color 
		glRotatef(saturno, 0.0, 1.0, 0.0);	//saturno gira sobre su eje
		glMaterialfv(GL_FRONT, GL_DIFFUSE, SaturnDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, SaturnSpecular);
		glutSolidSphere(1.4, 12, 12);  //Draw saturno
			glPushMatrix();
			glColor3f(0.9, 1.0, 0.8);	//color 
			glRotatef(anillo1, 0.0, 1.0, 0.0);	//anillo1 gira sobre su eje
			glMaterialfv(GL_FRONT, GL_DIFFUSE, RingDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, RingSpecular);
			glutSolidTorus(0.5,1, 10,50);  //Draw saturno
			glRotatef(45, 0.0, 0.0, 1.0);
			glColor3f(1.0,0.74, 0.1);	//color 
			glRotatef(anillo1, 0.0, 1.0, 0.0);	//anillo2 gira sobre su eje
			glMaterialfv(GL_FRONT, GL_DIFFUSE, RingDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, RingSpecular);
			glutSolidTorus(0.5, 2,10, 50);  //Draw saturno
			glPopMatrix();
			glPopMatrix();
		glPushMatrix();
		glPushMatrix();
		glRotatef(urano, 0.0, 1.0, 0.0);	//urano gira sobre su eje
		glTranslatef(28.0, 0.0, 0.0);
		glColor3f(0.6, 0.6, 0.6);	//color gris
		glRotatef(urano, 0.0, 1.0, 0.0);	//urano gira sobre su eje
		glMaterialfv(GL_FRONT, GL_DIFFUSE, UranusDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, UranusSpecular);
		glutSolidSphere(1.2, 12, 12);  //Draw urano
		glPopMatrix();
		glPushMatrix();
		glRotatef(neptuno, 0.0, 1.0, 0.0);	//neptuno gira sobre su eje
		glTranslatef(31.0, 0.0, 0.0);
		glColor3f(0.2, 0.0, 1.0);	//color azul
		glMaterialfv(GL_FRONT, GL_DIFFUSE, NeptuneDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, NeptuneSpecular);
		glRotatef(neptuno, 0.0, 1.0, 0.0);	//neptuno gira sobre su eje
		glutSolidSphere(0.9, 12, 12);  //Draw neptuno

			glPushMatrix();
			glRotatef(luna5, 0.0, 1.0, 0.0);	//luna5 gira sobre su eje
			glTranslatef(2.0, -2.0, 0.0);
			glColor3f(0.6, 0.6, 0.6);	//color gris
			glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
			glRotatef(luna5, 1.0, 0.0, 0.0);	//luna5 gira sobre su eje
			glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
			glutSolidSphere(0.3, 12, 12);  //Draw luna5
			glRotatef(luna4, 1.0, 0.0, 0.0);	//luna5 gira sobre su eje
			glTranslatef(2.0, 1.0, 0.0);
			glColor3f(0.6, 0.6, 0.6);	//color gris
			glRotatef(luna4, 1.0, 0.0, 0.0);	//luna5 gira sobre su eje
			glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
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