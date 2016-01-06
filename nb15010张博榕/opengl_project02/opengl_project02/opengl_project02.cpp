#include <GL/glut.h>
#include <stdlib.h>

static int year = 0, day = 0, moon = 0;

void init(void){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	//����̫��
	glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(1.0, 20.0, 16.0);

	glRotatef ((GLfloat) year, 0.0, 1.0, 0.0);
	glTranslatef (2.0, 0.0, 0.0);
	glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
	//���Ƶ���
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere(0.3, 10.0, 8.0);

	glTranslatef(1.0, 0.0, 0.0);
	glRotatef((GLfloat) moon, 0.0, 1.0, 0.0);
	//��������
	glColor3f(1.0, 1.0, 1.0);
	glutSolidSphere(0.2, 10.0, 8.0);

	/*glColor3f(0.7f,0.7f,0.7f);  
    glutSolidSphere(50.0f,50.0f,50.0f); */ 

	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h){
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	/*GLfloat aspect =(float)w/(float)h;  
  
    if(w <= h)  
    {  
        glOrtho(-100.0f, 100.0f, -100.0f/aspect, 100.0f/aspect, -100.0f, 100.0f);  
    }   
    else  
    {  
        glOrtho(-100.0f * aspect, 100.0f * aspect, -100.0f, 100.0f, -100.0f, 100.0f);  
    }  */
}

void keyboard(GLubyte key, GLint x, GLint y){
	 switch(key)  
    {  
        case 0x31:                    //�򿪺�ɫ��ƣ�����1��
            glDisable(GL_LIGHT2);  
            glDisable(GL_LIGHT3);  
            glEnable(GL_LIGHT1);  
            break;  
  
        case 0x32:                    //����ɫ��ƣ�����2��
            glDisable(GL_LIGHT1);  
            glDisable(GL_LIGHT3);  
            glEnable(GL_LIGHT2);  
            break;  
  
        case 0x33:                    //����ɫ��ƣ�����4��
            glDisable(GL_LIGHT2);  
            glDisable(GL_LIGHT1);  
            glEnable(GL_LIGHT3);  
            break;  
  
        case 0x34:                    //�򿪺�ɫ����Դ������4��
            glDisable(GL_LIGHT0);  
            glEnable(GL_LIGHT4);  
            break;  
  
        default:                    //�ر�������Ʋ�������Դ���ɰ�ɫ  
            glDisable(GL_LIGHT1);  
            glDisable(GL_LIGHT2);  
            glDisable(GL_LIGHT3);  
            glDisable(GL_LIGHT4);  
            glEnable(GL_LIGHT0);  
            break;  
  
    }  
	glutPostRedisplay();
}

//������Ⱦ����
void SetupRC(){
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
}

//���ù�Դ
void SetupLights(){
	GLfloat ambientLight[] = {0.2, 0.2, 0.2, 0.1};	//��ɫ����Դ������
	GLfloat diffuseLight[] = {0.8, 0.8, 0.8, 1.0};	//��ɫ��Դ������
	GLfloat specularLight[] = {1.0, 1.0, 1.0, 1.0};	//��ɫ����Դ�����

	GLfloat redAmbiLight[] = {0.2, 0.0, 0.0, 1.0};	//��ɫ����Դ������
	GLfloat redDiffLight[] = {0.8, 0.0, 0.0, 1.0};	//��ɫ��Դ������
	GLfloat redSpecLight[] = {1.0, 0.0, 0.0, 1.0};	//��ɫ����Դ�����

	GLfloat lightPos[] = {50.0, 120.0, 120.0, 1.0};	//��Դλ��
	GLfloat spotLightPos[] = {0.0, 0.0, 200.0, 1.0};	//���λ��
	GLfloat spotDir[] = {0.0, 0.0, -1.0};		//��Ʒ���

	GLfloat redLight[] = {1.0, 0.0, 0.0, 1.0};	//��ɫ��Դ
	GLfloat greenLight[] = {0.0, 1.0, 0.0, 1.0};	//��ɫ��Դ
	GLfloat blueLight[] = {0.0, 0.0, 1.0, 1.0};	//��ɫ��Դ

	glEnable(GL_LIGHTING);	//���ù���
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);	//���û�����Դ
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);	//�����������Դ
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);	//���þ����Դ
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);	//���õƹ�λ��
	glEnable(GL_LIGHT0);	//�򿪰�ɫ����Դ

	glLightfv(GL_LIGHT4, GL_AMBIENT, redAmbiLight);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, redDiffLight);
	glLightfv(GL_LIGHT4, GL_SPECULAR, redSpecLight);
	glLightfv(GL_LIGHT4, GL_POSITION, lightPos);

	glLightfv(GL_LIGHT1, GL_SPECULAR, redLight);	//��ɫ���
	glLightfv(GL_LIGHT1, GL_POSITION, spotLightPos);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotDir);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 85.0); 

	glLightfv(GL_LIGHT2, GL_SPECULAR, greenLight);	//��ɫ���	
	glLightfv(GL_LIGHT2, GL_POSITION, spotLightPos);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spotDir);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 85.0);

	glLightfv(GL_LIGHT3, GL_SPECULAR, blueLight);	//��ɫ���
	glLightfv(GL_LIGHT3, GL_POSITION, spotLightPos);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, spotDir);
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 85.0);

	glEnable(GL_COLOR_MATERIAL);	//���ò��ʵ���ɫ����
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);	//ָ��������ɫ����
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularLight);	//ָ�����϶Ծ����ķ�Ӧ
	glMateriali(GL_FRONT, GL_SHININESS, 100);	//ָ������ϵ��
}

void main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);  
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);

	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	SetupRC();  
    SetupLights();

	glutMainLoop();
}