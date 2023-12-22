#include <GL/glut.h>
#include <cmath>

// Variabel untuk sudut pandang kamera
GLfloat x = 0.0f; 
GLfloat y = 0.0f;

// Fungsi untuk menggambar kotak
void drawBox() {
  glBegin(GL_QUADS);
  
  // Sisi depan kotak
  glColor3f(1.0f, 0.0f, 0.0f); 
  glVertex3f(1.0f, 1.0f, -1.0f);
  glVertex3f(-1.0f, 1.0f, -1.0f);
  glVertex3f(-1.0f, -1.0f, -1.0f);
  glVertex3f(1.0f, -1.0f, -1.0f);

  // Sisi belakang kotak
  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex3f(1.0f, -1.0f, 1.0f);
  glVertex3f(-1.0f, -1.0f, 1.0f);  
  glVertex3f(-1.0f, 1.0f, 1.0f);
  glVertex3f(1.0f, 1.0f, 1.0f);
   
  glEnd();
}

// Fungsi untuk menggambar kerucut
void drawCone() {

  glRotatef(90, 1.0, 0.0, 0.0); // Putar kerucut 90 derajat
  
  glBegin(GL_TRIANGLE_FAN);
  
  glColor3f(0.0f, 0.0f, 1.0f);
  
  // Puncak kerucut
  glVertex3f(0.0f, 0.0f, 2.0f);  

  int slices = 20;

  // Alas kerucut
  for(int i = 0; i <= slices; i++) {
    
      float theta = (float)i / slices * 2.0f * 3.14159f;
      
      glVertex3f(sin(theta) * 1.0f, cos(theta) * 1.0f, 0.0f);

  }
  
  glEnd();
  
}

// Fungsi untuk menggambar bidang
void drawPlane() {
  
  glBegin(GL_POLYGON);
  
  glColor3f(1.0f, 1.0f, 1.0f);
  
  glVertex3f(2.0f, 0.0f, 2.0f);
  glVertex3f(-2.0f, 0.0f, 2.0f); 
  glVertex3f(-2.0f, 0.0f, -2.0f);
  glVertex3f(2.0f, 0.0f, -2.0f);
  
  glEnd();
  
}

// Fungsi untuk mengatur kamera
void setCamera() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45, 1.0, 1.0, 10.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();  
  gluLookAt(x, y, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); 
}

// Fungsi untuk menggambar scene
void renderScene() {
  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  setCamera();

  drawBox();
  
  drawCone();
   
  drawPlane();

  glutSwapBuffers();
  
} 

// Fungsi untuk menangani input keyboard
void processKeyboard(int key, int x, int y) {

  // Geser kamera ke kiri/kanan dengan panah kiri/kanan
  if(key == GLUT_KEY_LEFT) x -= 0.5f;
  if(key == GLUT_KEY_RIGHT) x += 0.5f;

  // Geser kamera ke atas/bawah dengan panah atas/bawah
  if(key == GLUT_KEY_UP) y += 0.5f;
  if(key == GLUT_KEY_DOWN) y -= 0.5f;

  // Redraw scene
  glutPostRedisplay();

}

int main(int argc, char** argv) {

  // Inisialisasi GLUT
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA); 

  glutInitWindowPosition(100,100); // Posisi window
  glutInitWindowSize(400,400); // Ukuran window

  glutCreateWindow("Contoh OpenGL");
  
  // Fungsi callback
  glutDisplayFunc(renderScene); 
  glutIdleFunc(renderScene);   
  glutSpecialFunc(processKeyboard);

  // Konfigurasi OpenGL
  glEnable(GL_DEPTH_TEST);
  glClearColor(0.0, 0.0, 0.0, 0.0); 

  glutMainLoop();

  return 1;
}
