//Semestre 2019 - 2
 /*
 Garc�a Callejas Ricardo
 Grupo 2
 Visual Studio 2017
 Pr�ctica 8
 Manual: Con el uso de las funciones para cargar y aplicar texturas aplicamos las caras de la imagen de
 un dado a cada una de las caras de un prisma de tama�o m x n x p, cuidando las coordenadas para cada uno
 de los vertices de dicho prisma.
 */
#include "texture.h"

float pos_camX = 0, pos_camY = 0, pos_camZ = -5; 
int eye_camX = 0, eye_camY = 0.0, eye_camZ = 0;


GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, -5.0f, 0.0f, 1.0f };			// Light Position


CTexture t_Ajedrez1;
CTexture t_Ajedrez2;
CTexture t_metal01;
CTexture t_cube;


int font=(int)GLUT_BITMAP_TIMES_ROMAN_24;



void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.5f, 0.5f, 0.8f, 0.0f);				// Azul de fondo	

	glEnable(GL_TEXTURE_2D);

	//glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	t_Ajedrez1.LoadTGA("01.tga");
	t_Ajedrez1.BuildGLTexture();
	t_Ajedrez1.ReleaseImage();

	t_metal01.LoadBMP("metal2.bmp");
	t_metal01.BuildGLTexture();
	t_metal01.ReleaseImage();

	t_Ajedrez2.LoadTGA("02.tga");
	t_Ajedrez2.BuildGLTexture();
	t_Ajedrez2.ReleaseImage();

	t_cube.LoadTGA("cube03.tga");
	t_cube.BuildGLTexture();
	t_cube.ReleaseImage();

}


void renderBitmapCharacter(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}



void prisma(float x, float y, float z,GLuint textura1)
{
	GLfloat vertice[8][3] = {
				{x / 2 ,-y / 2, z / 2},    //Coordenadas V�rtice 0 V0
				{-x / 2 ,-y / 2, z / 2},    //Coordenadas V�rtice 1 V1
				{-x / 2 ,-y / 2, -z / 2},    //Coordenadas V�rtice 2 V2
				{x / 2 ,-y / 2, -z / 2},    //Coordenadas V�rtice 3 V3
				{x / 2 ,y / 2, z / 2},    //Coordenadas V�rtice 4 V4
				{x / 2 ,y / 2, -z / 2},    //Coordenadas V�rtice 5 V5
				{-x / 2 ,y / 2, -z / 2},    //Coordenadas V�rtice 6 V6
				{-x / 2 ,y / 2, z / 2},    //Coordenadas V�rtice 7 V7
	};

		
		glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
		glBegin(GL_POLYGON);	//Front
		glColor3f(1.0, 1.0, 1.0);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.5f, 0.33f); glVertex3fv(vertice[0]);
		glTexCoord2f(0.5f, 0.66f); glVertex3fv(vertice[4]);
		glTexCoord2f(0.25f, 0.66f); glVertex3fv(vertice[7]);
		glTexCoord2f(0.25f, 0.33f); glVertex3fv(vertice[1]);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, textura1);
		glBegin(GL_POLYGON);	//Right
		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.5f, 0.33f); glVertex3fv(vertice[0]);
		glTexCoord2f(0.75f, 0.33f); glVertex3fv(vertice[3]);
		glTexCoord2f(0.75f, 0.66f); glVertex3fv(vertice[5]);
		glTexCoord2f(0.5f, 0.66f); glVertex3fv(vertice[4]);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, textura1);
		glBegin(GL_POLYGON);	//Back
		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(1.0f, 0.66f); glVertex3fv(vertice[6]);
		glTexCoord2f(0.75f, 0.66f); glVertex3fv(vertice[5]);
		glTexCoord2f(0.75f, 0.33f); glVertex3fv(vertice[3]);
		glTexCoord2f(1.0f, 0.33f); glVertex3fv(vertice[2]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, textura1);
		glBegin(GL_POLYGON);  //Left
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.25f, 0.33f); glVertex3fv(vertice[1]);
		glTexCoord2f(0.25f, 0.66f); glVertex3fv(vertice[7]);
		glTexCoord2f(0.0f, 0.66f); glVertex3fv(vertice[6]);
		glTexCoord2f(0.0f, 0.33f); glVertex3fv(vertice[2]);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, textura1);
		glBegin(GL_POLYGON);  //Bottom
		glNormal3f(0.0f, -1.0f, 0.0f);
		glTexCoord2f(0.5f, 0.33f); glVertex3fv(vertice[0]);
		glTexCoord2f(0.25f, 0.33f); glVertex3fv(vertice[1]);
		glTexCoord2f(0.25f, 0.0f); glVertex3fv(vertice[2]);
		glTexCoord2f(0.5f, 0.0f); glVertex3fv(vertice[3]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
		glBegin(GL_POLYGON);  //Top
		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0.5f, 0.66f); glVertex3fv(vertice[4]);
		glTexCoord2f(0.5f, 1.0f); glVertex3fv(vertice[5]);
		glTexCoord2f(0.25f, 1.0f); glVertex3fv(vertice[6]);
		glTexCoord2f(0.25f, 0.66f); glVertex3fv(vertice[7]);
		glEnd();
}


void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(pos_camX, pos_camY, pos_camZ);
		glRotatef(eye_camX, 1.0, 0.0, 0.0);
		glRotatef(eye_camY, 0.0, 1.0, 0.0);
		glRotatef(eye_camZ, 0.0, 0.0, 1.0);
	
		glPushMatrix(); 
			glColor3f(3.0, 3.0, 3.0);
			prisma(1,1,1,t_cube.GLindex);
		glPopMatrix();


	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
		renderBitmapCharacter(-11, 12.0, -14.0, (void *)font, "Practica 8");
		renderBitmapCharacter(-11, 10.5, -14, (void *)font, "Texturas");
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers ( );

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
	glLoadIdentity();
}

void animacion()
{
	

	glutPostRedisplay();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			pos_camZ += 0.5f;
			//eye_camZ -= 0.5f;
			break;

		case 's':
		case 'S':
			pos_camZ -= 0.5f;
			//eye_camZ += 0.5f;
			break;

		case 'a':
		case 'A':
			pos_camX += 0.5f;
			//eye_camX -= 0.5f;
			break;
		case 'd':
		case 'D':
			pos_camX -= 0.5f;
			//eye_camX += 0.5f;
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
	case GLUT_KEY_PAGE_UP:
		pos_camY -= 0.5f;
		//eye_camY += 0.5f;
		break;

	case GLUT_KEY_PAGE_DOWN:
		pos_camY += 0.5f;
		//eye_camY -= 0.5f;
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		eye_camX = (eye_camX-15) % 360;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		eye_camX = (eye_camX+15) % 360;
		break;

	case GLUT_KEY_LEFT:
		eye_camY = (eye_camY-15) % 360;
		break;

	case GLUT_KEY_RIGHT:
		eye_camY = (eye_camY+15) % 360;
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
  glutInitWindowSize  (5000, 5000);	// Tama�o de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 8"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut funci�n de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut funci�n en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut funci�n de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}