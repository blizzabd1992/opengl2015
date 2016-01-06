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
	//绘制太阳
	glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(1.0, 20.0, 16.0);

	glRotatef ((GLfloat) year, 0.0, 1.0, 0.0);
	glTranslatef (2.0, 0.0, 0.0);
	glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
	//绘制地球
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere(0.3, 10.0, 8.0);

	glTranslatef(1.0, 0.0, 0.0);
	glRotatef((GLfloat) moon, 0.0, 1.0, 0.0);
	//绘制月球
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
        case 0x31:                    //打开红色射灯（按键1）
            glDisable(GL_LIGHT2);  
            glDisable(GL_LIGHT3);  
            glEnable(GL_LIGHT1);  
            break;  
  
        case 0x32:                    //打开绿色射灯（按键2）
            glDisable(GL_LIGHT1);  
            glDisable(GL_LIGHT3);  
            glEnable(GL_LIGHT2);  
            break;  
  
        case 0x33:                    //打开蓝色射灯（按键4）
            glDisable(GL_LIGHT2);  
            glDisable(GL_LIGHT1);  
            glEnable(GL_LIGHT3);  
            break;  
  
        case 0x34:                    //打开红色主光源（按键4）
            glDisable(GL_LIGHT0);  
            glEnable(GL_LIGHT4);  
            break;  
  
        default:                    //关闭所有射灯并将主光源换成白色  
            glDisable(GL_LIGHT1);  
            glDisable(GL_LIGHT2);  
            glDisable(GL_LIGHT3);  
            glDisable(GL_LIGHT4);  
            glEnable(GL_LIGHT0);  
            break;  
  
    }  
	glutPostRedisplay();
}

//设置渲染环境
void SetupRC(){
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
}

//设置光源
void SetupLights(){
	GLfloat ambientLight[] = {0.2, 0.2, 0.2, 0.1};	//白色主光源环境光
	GLfloat diffuseLight[] = {0.8, 0.8, 0.8, 1.0};	//白色光源漫反射
	GLfloat specularLight[] = {1.0, 1.0, 1.0, 1.0};	//白色主光源镜面光

	GLfloat redAmbiLight[] = {0.2, 0.0, 0.0, 1.0};	//红色主光源环境光
	GLfloat redDiffLight[] = {0.8, 0.0, 0.0, 1.0};	//红色光源漫反射
	GLfloat redSpecLight[] = {1.0, 0.0, 0.0, 1.0};	//红色主光源镜面光

	GLfloat lightPos[] = {50.0, 120.0, 120.0, 1.0};	//光源位置
	GLfloat spotLightPos[] = {0.0, 0.0, 200.0, 1.0};	//射灯位置
	GLfloat spotDir[] = {0.0, 0.0, -1.0};		//射灯方向

	GLfloat redLight[] = {1.0, 0.0, 0.0, 1.0};	//红色光源
	GLfloat greenLight[] = {0.0, 1.0, 0.0, 1.0};	//绿色光源
	GLfloat blueLight[] = {0.0, 0.0, 1.0, 1.0};	//蓝色光源

	glEnable(GL_LIGHTING);	//启用光照
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);	//设置环境光源
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);	//设置漫反射光源
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);	//设置镜面光源
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);	//设置灯光位置
	glEnable(GL_LIGHT0);	//打开白色主光源

	glLightfv(GL_LIGHT4, GL_AMBIENT, redAmbiLight);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, redDiffLight);
	glLightfv(GL_LIGHT4, GL_SPECULAR, redSpecLight);
	glLightfv(GL_LIGHT4, GL_POSITION, lightPos);

	glLightfv(GL_LIGHT1, GL_SPECULAR, redLight);	//红色射灯
	glLightfv(GL_LIGHT1, GL_POSITION, spotLightPos);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotDir);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 85.0); 

	glLightfv(GL_LIGHT2, GL_SPECULAR, greenLight);	//绿色射灯	
	glLightfv(GL_LIGHT2, GL_POSITION, spotLightPos);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spotDir);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 85.0);

	glLightfv(GL_LIGHT3, GL_SPECULAR, blueLight);	//蓝色射灯
	glLightfv(GL_LIGHT3, GL_POSITION, spotLightPos);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, spotDir);
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 85.0);

	glEnable(GL_COLOR_MATERIAL);	//启用材质的颜色跟踪
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);	//指定材料着色的面
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularLight);	//指定材料对镜面光的反应
	glMateriali(GL_FRONT, GL_SHININESS, 100);	//指定反射系数
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