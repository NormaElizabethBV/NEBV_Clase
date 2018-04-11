//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	Baca Velázquez Norma Elizabeth			******//
//*************		Visual Studio 2017					******//
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

GLfloat MercuryDiffuse[] = { 1.0f, 1.0f, 1.0f, .0f };			// Mercurio
GLfloat MercurySpecular[] = { 2.0, 2.5, 2.5, 1.0 };
GLfloat MercuryShininess[] = { 50.0 };

GLfloat VenusDiffuse[] = { 0.97f, 0.95f, 0.7f, 1.0f };			// Venus
GLfloat VenusSpecular[] = { 2.0, 2.5, 2.5, 1.0 };
GLfloat VenusShininess[] = { 50.0 };

GLfloat EarthDiffuse[]= { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[]= { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[]= { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

GLfloat JupiterDiffuse[] = { 0.7f, 0.8f, 0.7f, 1.0f };			// Jupiter
GLfloat JupiterSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat JupiterShininess[] = { 50.0 };

GLfloat Sat1Diffuse[] = { 0.9f, 0.9f, 0.8f, 1.0f };			// Jupiter Sat1
GLfloat Sat1Specular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat Sat1Shininess[] = { 50.0 };

GLfloat Sat2Diffuse[] = { 0.7f, 0.4f, 0.2f, 1.0f };			// Jupiter Sat2
GLfloat Sat2Specular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat Sat2Shininess[] = { 50.0 };

GLfloat Sat3Diffuse[] = { 0.5f, 0.6f, 0.2f, 1.0f };			// Jupiter Sat3
GLfloat Sat3Specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat Sat3Shininess[] = { 50.0 };


GLfloat SaturnoDiffuse[] = { 0.9f, 0.9f, 0.55f, 1.0f };			// Saturno
GLfloat SaturnoSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat SaturnoShininess[] = { 50.0 };

GLfloat AnilloDiffuse[] = { 0.9f, 0.5f, 0.2f, 1.0f };			// Saturno Anillo
GLfloat AnilloSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat AnilloShininess[] = { 50.0 };

GLfloat UranoDiffuse[] = { 0.4f, 0.0f, 1.0f, 1.0f };			//Urano
GLfloat UranoSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat UranoShininess[] = { 50.0 };

GLfloat NepDiffuse[] = { 0.25f, 0.8f, 0.7f, 1.0f };			//Neptuno
GLfloat NepSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat NepShininess[] = { 50.0 };

void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);

	glLightfv(GL_LIGHT1, GL_DIFFUSE, SunDiffuse);

	glLightfv(GL_LIGHT1, GL_SPECULAR, SunDiffuse);

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
	glLightfv(GL_LIGHT1, GL_POSITION, SunPosition);
	glDisable(GL_LIGHTING);
	glutSolidSphere(2.5,20,20);  //Draw Sun (radio,H,V);
	glEnable(GL_LIGHTING);
	
	//Mercurio
	glPushMatrix();
	glRotated(mercurio, 0, 1, 0);//Traslacion mercurio
	glTranslatef(6, 0, 0);
	glColor3f(1,1,1);
	glRotated(mercurio, 0, 1, 0);//Rotacion mercurio
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MercuryDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MercurySpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MercuryShininess);
	glutSolidSphere(0.5, 20, 20);
	glPopMatrix();
	
	//Venus
	glPushMatrix();
	glRotated(venus, 0, 2, 0);//Traslacion venus
	glTranslatef(8, 0, 0);
	//glColor3f(0.964 ,0.968,0.783); 
	glRotated(venus, 0, 2, 0);//Rotacion venus
	glMaterialfv(GL_FRONT, GL_DIFFUSE, VenusDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, VenusSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, VenusShininess);

	glutSolidSphere(0.7, 20, 20);
	glPopMatrix();
	
	//Tierra
	glPushMatrix();
	glRotated(tierra, 0, 0.6, 0);//Traslacion tierra
	glTranslatef(10, 0, 0);
	//glColor3f(0.6, 0.8, 196078);
	glRotated(tierra, 0, 1, 0);//Rotacion tierra
	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, EarthSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, EarthShininess);
	glutSolidSphere(0.9, 20, 20);

	//Luna Tierra
	glPushMatrix();
	glRotated(luna, 0, 1, 0);//Traslacion luna
	glTranslatef(1.5, 0, 0);
	//glColor3f(1, 1, 1);
	glRotated(luna, 0, 1, 0);//Rotacion luna
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.4, 20, 20);
	glPopMatrix();

	glPopMatrix();

	//Marte
	glPushMatrix();
	glRotated(marte, 0, 2, 0);//Traslacion marte
	glTranslatef(15, 0, 0);
	//glColor3f(0.9, 0.0, 0.0);
	glRotated(marte, 0, 2, 0);//Rotacion marte
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MarsDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MarsSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MarsShininess);
	glutSolidSphere(0.8, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glRotated(jupiter, 0, 2, 0);//Traslacion jupiter
	glTranslatef(18, 0, 0);
	glColor3f(0.7, 0.85, 0.72);
	glRotated(jupiter, 0, 2, 0);//Rotacion jupiter
	glMaterialfv(GL_FRONT, GL_DIFFUSE, JupiterDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, JupiterSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, JupiterShininess);
	glutSolidSphere(1.2, 20, 20);

	glPushMatrix();
	glRotated(satelite, 0, 1, 0);//Traslacion sat
	glTranslatef(3, 0, 0);
	glColor3f(1, 1, 1);
	glRotated(satelite, 0, 1, 0);//Rotacion sat
	glMaterialfv(GL_FRONT, GL_DIFFUSE, Sat1Diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, Sat1Specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, Sat1Shininess);
	glutSolidSphere(0.4, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glRotated(satelite2, 0, 1, 0);//Traslacion sat2
	glTranslatef(3.5, 0, 0);
	glColor3f(1, 1, 1);
	glRotated(satelite2, 1, 0, 0);//Rotacion sat2
	glMaterialfv(GL_FRONT, GL_DIFFUSE, Sat2Diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, Sat2Specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, Sat2Shininess);
	glutSolidSphere(0.4, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glRotated(satelite3, 0, 1, 0);//Traslacion sat3
	glTranslatef(4, 0, 0);
	glColor3f(1, 1, 1);
	glRotated(satelite3, 1, 0, 0);//Rotacion sat3
	glMaterialfv(GL_FRONT, GL_DIFFUSE, Sat3Diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, Sat3Specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, Sat3Shininess);
	glutSolidSphere(0.4, 20, 20);
	glPopMatrix();
	
	
	
	glPopMatrix();//jup

	//Saturno
	glPushMatrix();
	glRotated(saturno, 0, 2, 0);//Traslacion saturno
	glTranslatef(21, 0, 0);
	glColor3f(0.79, 0.99, 0.55);
	glRotated(saturno, 0, 2, 0);//Rotacion saturno
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, AnilloDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, AnilloSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, AnilloShininess);
	glutSolidTorus(.1,3,10,50);
	
	glPopMatrix();
	glColor3f(0.99, 0.99, 0.50);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, SaturnoDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, SaturnoSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, SaturnoShininess);
	glutSolidSphere(1.4, 20, 20);
	glPopMatrix();

	//urano
	glPushMatrix();
	glRotated(urano, 0, 2, 0);//Traslacion urano
	glTranslatef(25, 0, 0);
	glColor3f(0.3, 0.0, 0.9);
	glRotated(urano, 0, 2, 0);//Rotacion urano
	glMaterialfv(GL_FRONT, GL_DIFFUSE, UranoDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, UranoSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, UranoShininess);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();

	//neptuno
	glPushMatrix();
	glRotated(neptuno, 0, 2, 0);//Traslacion urano
	glTranslatef(27, 0, 0);
	glColor3f(.25, 0.07, 0.81);
	glRotated(neptuno, 0, 2, 0);//Rotacion urano
	glMaterialfv(GL_FRONT, GL_DIFFUSE, NepDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, NepSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, NepShininess);
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
		mercurio = (mercurio +6) % 360;
		venus = (venus +5) % 360;
		tierra = (tierra +3 ) % 360;
		luna = (luna - 9) % 360;
		marte = (marte +4) % 360;
		jupiter=(jupiter+2)% 360;
		saturno=(saturno+3)% 360;
		urano=(urano+3)%360;
		neptuno=(neptuno+2)%360;
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
  glutCreateWindow    ("Practica 7"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}