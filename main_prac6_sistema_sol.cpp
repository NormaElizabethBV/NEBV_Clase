//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************		Baca Velázquez Norma Elizabeth		******//
//*************				Visual Studio 2017			******//
//************************************************************//
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
int luna = 0;
int marte = 0;
int jupiter = 0;
int urano = 0;
int saturno = 0;
int neptuno = 0;

int satelite=0;
int satelite2=0;
int satelite3=0;
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
		
//Sistema solar
	glPushMatrix();
//sol
	glPushMatrix();
	glRotatef(sol,0.0,1.0,0.0);	//El Sol gira sobre su eje
	glColor3f( 1.0,1.0,0.0 );	//Sol amarillo
	glutSolidSphere(4,20,20);  //Draw Sun (radio,H,V);
	
	//Mercurio
	glPushMatrix();
	glRotated(mercurio, 0, 1, 0);//Traslacion mercurio
	glTranslatef(3, 0, 0);
	glColor3f(1,1,1);
	glRotated(mercurio, 0, 1, 0);//Rotacion mercurio
	glutSolidSphere(0.5, 20, 20);
	glPopMatrix();
	
	//Venus
	glPushMatrix();
	glRotated(venus, 0, 2, 0);//Traslacion venus
	glTranslatef(6, 0, 0);
	glColor3f(0.964 ,0.968,0.783); 
	glRotated(venus, 0, 2, 0);//Rotacion venus
	glutSolidSphere(0.7, 20, 20);
	glPopMatrix();
	
	//Tierra
	glPushMatrix();
	glRotated(tierra, 0, 0.6, 0);//Traslacion tierra
	glTranslatef(8, 0, 0);
	glColor3f(0.6, 0.8, 196078);
	glRotated(tierra, 0, 1, 0);//Rotacion tierra
	glutSolidSphere(0.9, 20, 20);

	//Luna Tierra
	glPushMatrix();
	glRotated(luna, 0, 1, 0);//Traslacion luna
	glTranslatef(1.5, 0, 0);
	glColor3f(1, 1, 1);
	glRotated(luna, 0, 1, 0);//Rotacion luna
	glutSolidSphere(0.4, 20, 20);
	glPopMatrix();

	glPopMatrix();

	//Marte
	glPushMatrix();
	glRotated(marte, 0, 2, 0);//Traslacion marte
	glTranslatef(11, 0, 0);
	glColor3f(0.9, 0.0, 0.0);
	glRotated(marte, 0, 2, 0);//Rotacion marte
	glutSolidSphere(0.8, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glRotated(jupiter, 0, 2, 0);//Traslacion jupiter
	glTranslatef(16, 0, 0);
	glColor3f(0.5, 0.85, 0.72);
	glRotated(jupiter, 0, 2, 0);//Rotacion jupiter
	glutSolidSphere(2, 20, 20);

	glPushMatrix();
	glRotated(satelite, 0, 1, 0);//Traslacion sat
	glTranslatef(2.5, 0, 0);
	glColor3f(1, 1, 1);
	glRotated(satelite, 0, 1, 0);//Rotacion sat
	glutSolidSphere(0.4, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glRotated(satelite2, 0, 1, 0);//Traslacion sat2
	glTranslatef(3, 0, 0);
	glColor3f(1, 1, 1);
	glRotated(satelite2, 1, 0, 0);//Rotacion sat2
	glutSolidSphere(0.4, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glRotated(satelite3, 0, 1, 0);//Traslacion sat3
	glTranslatef(3.5, 0, 0);
	glColor3f(1, 1, 1);
	glRotated(satelite3, 1, 0, 0);//Rotacion sat3
	glutSolidSphere(0.4, 20, 20);
	glPopMatrix();
	
	
	
	glPopMatrix();//jup

	//Saturno
	glPushMatrix();
	glRotated(saturno, 0, 2, 0);//Traslacion saturno
	glTranslatef(22, 0, 0);
	glColor3f(0.99, 0.99, 0.55);
	glRotated(saturno, 0, 2, 0);//Rotacion saturno
	glPushMatrix();
	
	glutSolidTorus(.1,3,10,50);
	
	glPopMatrix();
	glColor3f(0.99, 0.99, 0.50);
	glutSolidSphere(1.8, 20, 20);
	glPopMatrix();

	//urano
	glPushMatrix();
	glRotated(urano, 0, 2, 0);//Traslacion urano
	glTranslatef(26, 0, 0);
	glColor3f(0.0, 0.0, 0.9);
	glRotated(urano, 0, 2, 0);//Rotacion urano
	glutSolidSphere(1.6, 20, 20);
	glPopMatrix();

	//neptuno
	glPushMatrix();
	glRotated(neptuno, 0, 2, 0);//Traslacion urano
	glTranslatef(30, 0, 0);
	glColor3f(.25, 0.07, 0.81);
	glRotated(neptuno, 0, 2, 0);//Rotacion urano
	glutSolidSphere(1.4, 20, 20);
	glPopMatrix();





	glPopMatrix();//Sol
	glPopMatrix();//Sistema solar
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
		sol = (sol - 1) % 360;
		mercurio = (mercurio - 9) % 360;
		venus = (venus - 8) % 360;
		tierra = (tierra -7 ) % 360;
		luna = (luna - 9) % 360;
		marte = (marte - 5) % 360;
		jupiter=(jupiter-4)% 360;
		saturno=(saturno-3)% 360;
		urano=(urano-2)%360;
		neptuno=(neptuno-1)%360;
		satelite=(satelite-9)%360;
		satelite2=(satelite2+9)%360;
		satelite3=(satelite3-6)%360;
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