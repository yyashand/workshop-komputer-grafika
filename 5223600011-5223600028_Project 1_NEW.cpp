///////////////////////////////////
// Kelompok 2 
//
// OpenGL program to draw a cube.
// 
// Sumanta Guha.
///////////////////////////////////

#include <C:\OpenGLwrappers\glew-1.10.0\glew-1.10.0\include\GL\glew.h>
#include <C:\OpenGLwrappers\freeglut\freeglut\include\GL\freeglut.h>


// Sudut untuk rotasi
float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;

// Fungsi untuk menggambar tombol power
void drawPowerButton() {
    glPushMatrix();
    glTranslatef(0.3f, 1.7f, 1.02f);
    glColor3f(0.1f, 0.1f, 0.1f);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();
}

// Fungsi untuk menggambar port USB
void drawUSBPorts() {
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f);
    for (float i = 0; i < 3; i++) {
        glTranslatef(0.15f, 1.6f - i * 0.2f, 1.02f);
        glScalef(0.1f, 0.05f, 0.05f);
        glutSolidCube(1);
        glPopMatrix();
    }
}

// Fungsi untuk menggambar ventilasi
void drawVentilation() {
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f);
    for (float i = -1.5f; i < 1.5f; i += 0.2f) {
        glBegin(GL_QUADS);
        glVertex3f(-0.7f, i, -1.02f);
        glVertex3f(-0.7f, i + 0.1f, -1.02f);
        glVertex3f(0.7f, i + 0.1f, -1.02f);
        glVertex3f(0.7f, i, -1.02f);
        glEnd();
    }
    glPopMatrix();
}

// Fungsi untuk menggambar logo Dell
void drawDellLogo() {
    glPushMatrix();
    glTranslatef(0.0f, 0.5f, 1.01f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glutSolidSphere(0.3, 20, 20);
    glPopMatrix();
}

// Fungsi untuk menggambar case PC Dell
void drawDellPC() {
    // Menggambar badan utama
    glBegin(GL_QUADS);

    // Bagian depan (mengkilap)
    glColor3f(0.05f, 0.05f, 0.05f);
    glVertex3f(-0.7f, -1.5f, 1.0f); // kiri bawah depan
    glVertex3f(0.7f, -1.5f, 1.0f);  // kanan bawah depan
    glVertex3f(0.7f, 1.5f, 1.0f);   // kanan atas depan
    glVertex3f(-0.7f, 1.5f, 1.0f);  // kiri atas depan

    // Bagian belakang
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex3f(-0.7f, -1.5f, -1.0f); // kiri bawah belakang
    glVertex3f(0.7f, -1.5f, -1.0f);  // kanan bawah belakang
    glVertex3f(0.7f, 1.5f, -1.0f);   // kanan atas belakang
    glVertex3f(-0.7f, 1.5f, -1.0f);  // kiri atas belakang

    // Sisi kiri (ventilasi)
    glColor3f(0.15f, 0.15f, 0.15f);
    glVertex3f(-0.7f, -1.5f, -1.0f); // kiri bawah belakang
    glVertex3f(-0.7f, -1.5f, 1.0f);  // kiri bawah depan
    glVertex3f(-0.7f, 2.0f, 1.0f);  // Titik kiri atas depan 
    glVertex3f(-0.7f, 2.0f, -1.0f); // Titik kiri atas belakang

    // Sisi kanan (abu-abu medium)
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(0.7f, 2.0f, -1.0f);  // Titik kanan atas belakang
    glVertex3f(0.7f, -1.5f, -1.0f); // kanan bawah belakang
    glVertex3f(0.7f, -1.5f, 1.0f); // kanan bawah depan
    glVertex3f(0.7f, 2.0f, 1.0f);   // Titik kanan atas // kanan atas depan

    // Bagian atas yang lebih tinggi dan berwarna hitam
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f); // Warna hitam
    glVertex3f(-0.7f, 1.5f, 1.0f);  // Titik kiri atas depan (titik awal bagian atas yang sudah ada)
    glVertex3f(0.7f, 1.5f, 1.0f);   // Titik kanan atas depan
    glVertex3f(0.7f, 2.0f, 1.0f);   // Titik kanan atas belakang (titik baru, lebih tinggi)
    glVertex3f(-0.7f, 2.0f, 1.0f);  // Titik kiri atas belakang (titik baru, lebih tinggi)

    // Bagian atas belakang (sesuaikan dengan bagian depan)
    glVertex3f(-0.7f, 2.0f, -1.0f);
    glVertex3f(0.7f, 2.0f, -1.0f);
    glVertex3f(0.7f, 1.5f, -1.0f);
    glVertex3f(-0.7f, 1.5f, -1.0f);
    glEnd();
    // Tutup atas (misalnya, dengan warna abu-abu)
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f); // Warna abu-abu
    glVertex3f(-0.7f, 2.0f, 1.0f);  // Titik kiri atas depan tutup atas
    glVertex3f(0.7f, 2.0f, 1.0f);   // Titik kanan atas depan tutup atas
    glVertex3f(0.7f, 2.0f, -1.0f);  // Titik kanan atas belakang tutup atas
    glVertex3f(-0.7f, 2.0f, -1.0f); // Titik kiri atas belakang tutup atas
    glEnd();

    // Tutup bawah (misalnya, dengan warna hitam)
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f); // Warna hitam
    glVertex3f(-0.7f, -1.5f, 1.0f); // Titik kiri bawah depan tutup bawah
    glVertex3f(0.7f, -1.5f, 1.0f);  // Titik kanan bawah depan tutup bawah
    glVertex3f(0.7f, -1.5f, -1.0f); // Titik kanan bawah belakang tutup bawah
    glVertex3f(-0.7f, -1.5f, -1.0f); // Titik kiri bawah belakang tutup bawah
    glEnd();
    // Tambahkan detail lainnya
    drawPowerButton();
    drawUSBPorts();
    drawVentilation();
    drawDellLogo();
}

// Fungsi untuk menampilkan scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -7.0f); // Mengubah nilai z menjadi -7.0f
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);
    glRotatef(angleZ, 0.0f, 0.0f, 1.0f);
    drawDellPC(); // Gambar model PC Dell

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'x') angleX += 5.0f;
    if (key == 'y') angleY += 5.0f;
    if (key == 'z') angleZ += 5.0f;
    if (key == 27) exit(0); // Escape key
    glutPostRedisplay();
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0f, 1.0f, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("PC Dell 3D Model");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}