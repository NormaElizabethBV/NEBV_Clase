//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s):Baca Velázquez Norma Elizabeth *****//
//*************											******//
//*************				Visual Studio 2017			******//
//************************************************************//
#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;
float angHombro = 0.0;
float angCodo = 0.0;
float angMun = 0.0;
float angMan =0.0;
float angique = 0.0;
float angNa = 0.0;
float angTa = 0.0;
GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL ( void )     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	
		//Poner Código Aquí.
	//hombro
	glRotated(angHombro,0,0,1.0);
	glPushMatrix();
		glScaled(1,2,2);
		glColor3f(0, 1, 1);
		prisma();
	glPopMatrix();
	//brazo
	glTranslatef(2,0,0);
	glPushMatrix();
		glScaled(3, 2, 2);
		glColor3f(1, 0.5, 1);
		prisma();
	glPopMatrix();
	//codo
	glRotated(angCodo,0, 1.0, 0.0);
	//glPushMatrix();//rot
	glTranslatef(1.75, 0, 0);
	glPushMatrix();
		glScaled(0.5, 2, 2);
		glColor3f(1, 0, 1);
	prisma();
	glPopMatrix();
	//antebrazo
	glTranslatef(2.25, 0, 0);
	glPushMatrix();
		glScaled(4, 2, 2);
		glColor3f(1, 0, 0);
		prisma();
	glPopMatrix();
	//muñeca
	glRotated(angMun,1, 0.0, 0.0);
	glTranslatef(2.25, 0, 0);
	glPushMatrix();
		glScaled(0.5, 2, 2);
		glColor3f(3, 2, 4);
		prisma();
	glPopMatrix();
	//mano
	glRotated(angMan,0.0, 0.0, 1.0);
	glTranslatef(1.25, -0.12, 0);
	glPushMatrix();
	glScaled(2, 3, 2);
	glColor3f(0, 1, 1);
	prisma();
	glPopMatrix();
//Dedo Meñique
	//Falange
	glRotated(angique,0.0, 1.0, 0.0);
	glTranslatef(1.25, -1, 0);
	glPushMatrix();
	glScaled(0.5, 0.3, 1);
	glColor3f(1,0, 0);
	prisma();
	glPopMatrix();
	//Falangina
	glRotated(angNa,0.0, 1.0, 0.0);
	glTranslatef(0.5, 0, 0);
	glPushMatrix();
		glScaled(0.5, 0.2, 1);
		glColor3f(1, 0, 1);
		prisma();
	glPopMatrix();
	//Falangeta
	glRotated(angTa,0.0, 1.0, 0.0);
	glTranslatef(0.5, 0, 0);
	glPushMatrix();
		glScaled(0.5, 0.1, 1);
		glColor3f(1, 1, 1);
		prisma();
	glPopMatrix();
//Anular
	//Falange
	glTranslatef(-1,0.5, 0);
	glPushMatrix();
	glScaled(0.5, 0.3, 1);
	glColor3f(1, 0, 0);
	prisma();
	glPopMatrix();
	//Falangina
	glTranslatef(0.5, 0, 0);
	glPushMatrix();
	glScaled(0.5, 0.2, 1);
	glColor3f(1, 0, 1);
	prisma();
	glPopMatrix();
	//Falangeta
	glTranslatef(0.5, 0, 0);
	glPushMatrix();
	glScaled(0.5, 0.1, 1);
	glColor3f(1, 1, 1);
	prisma();
	glPopMatrix();
//Dedo Medio
	//Falange
	glTranslatef(-1, 0.5, 0);
	glPushMatrix();
	glScaled(0.5, 0.3, 1);
	glColor3f(1, 0, 0);
	prisma();
	glPopMatrix();
	//Falangina
	glTranslatef(0.5, 0, 0);
	glPushMatrix();
	glScaled(0.5, 0.2, 1);
	glColor3f(1, 0, 1);
	prisma();
	glPopMatrix();
	//Falangeta
	glTranslatef(0.5, 0, 0);
	glPushMatrix();
	glScaled(0.5, 0.1, 1);
	glColor3f(1, 1, 1);
	prisma();
	glPopMatrix();
//Dedo Indice
	//Falange
	glTranslatef(-1, 0.5, 0);
	glPushMatrix();
	glScaled(0.5, 0.3, 1);
	glColor3f(1, 0, 0);
	prisma();
	glPopMatrix();
	//Falangina
	glTranslatef(0.5, 0, 0);
	glPushMatrix();
	glScaled(0.5, 0.2, 1);
	glColor3f(1, 0, 1);
	prisma();
	glPopMatrix();
	//Falangeta
	glTranslatef(0.5, 0, 0);
	glPushMatrix();
	glScaled(0.5, 0.1, 1);
	glColor3f(1, 1, 1);
	prisma();
	glPopMatrix();
	//Dedo Pulgar
	//Falange
	glTranslatef(-1, 0.5, 0);
	glPushMatrix();
	glScaled(0.5, 0.3, 1);
	glColor3f(1, 0, 0);
	prisma();
	glPopMatrix();
	//Falangina
	glTranslatef(0.5, 0, 0);
	glPushMatrix();
	glScaled(0.5, 0.2, 1);
	glColor3f(1, 0, 1);
	prisma();
	glPopMatrix();
	//Falangeta
	glTranslatef(0.5, 0, 0);
	glPushMatrix();
	glScaled(0.5, 0.1, 1);
	glColor3f(1, 1, 1);
	prisma();
	glPopMatrix();
	//glPopMatrix();//rotend
		
  											
	glutSwapBuffers ( );
  // Swap The Buffers
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
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.2f;
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			break;
		case 'a':
		case 'A':
			transX +=0.2f;
			break;
		
		case 'd':
		case 'D':
			transX -=0.2f;
			break;
  //////angulos a modificar

		//hombro
		case 'r':		
		case 'R':
			angHombro ++;
			if(angHombro > 90)
				angHombro = 90;
			break;

		case 'f':		
		case 'F':
			angHombro --;
			if(angHombro < -90)
				angHombro =-90;
			break;

					//codo
		case 't':		
		case 'T':
			angCodo ++;
			if(angCodo > 0)
				angCodo = 0;
			break;

		case 'g':		
		case 'G':
			angCodo --;
			if(angCodo < -90)
				angCodo = -90;
			break;


			//muñeca
		case 'y':		
		case 'Y':
			angMun ++;
			if(angMun > 90)
				angMun = 90;
			break;

		case 'h':		
		case 'H':
			angMun --;
			if(angMun < -90)
				angMun = -90;
			break;
			//mano
			
		case 'u':		
		case 'U':
			angMan ++;
			if(angMan > 90)
				angMan = 90;
			break;

		case 'j':
		case 'J':
			angMan --;
			if(angMan < -90)
				angMan = -90;
			break;

			//falange
			case 'i':		//Movimientos de Luz
		case 'I':
			angique ++;
			if(angique > 40)
				angique = 40;
			break;

		case 'k':   //Activamos/desactivamos luz
		case 'K':
			angique --;
			if(angique < -90)
				angique = -90;
			break;
//falangina
			case 'o':	
		case 'O':
			angNa ++;
			if(angNa > 0)
				angNa = 0;
			break;

		case 'l':   
			angNa --;
			if(angNa < -90)
				angNa = -90;
			break;
			//falangeta
			case 'z':		//Movimientos de Luz
		case 'Z':
			angTa ++;
			if(angTa > 0)
				angTa = 0;
			break;

		case 'x':   //Activamos/desactivamos luz
		case 'X':
			angTa --;
			if(angTa < -90)
				angTa = -90;
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
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		if(angleX <= 90)
		angleX +=2.0f;
		printf("%f\n", angleX);
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		if(angleX >= -90)
		angleX -=2.0f;
		printf("%f\n", angleX);
		break;
	case GLUT_KEY_LEFT:
		if (angleY <= 90)
		angleY +=2.0f;
		break;
	case GLUT_KEY_RIGHT:
		if (angleY >= -90)
		angleY -=2.0f;
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
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 5"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



