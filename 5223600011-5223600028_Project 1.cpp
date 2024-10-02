///////////////////////////////////
// 
//
// OpenGL program to draw a cube.
// 
// Sumanta Guha.
///////////////////////////////////

#include <C:\OpenGLwrappers\glew-1.10.0\glew-1.10.0\include\GL\glew.h>
#include <C:\OpenGLwrappers\freeglut\freeglut\include\GL\freeglut.h>

// Sudut untuk rotasi
float angleX = 0.0f; // Rotasi sumbu X
float angleY = 0.0f; // Rotasi sumbu Y
float angleZ = 0.0f; // Rotasi sumbu Z

// Fungsi untuk menggambar prisma segi empat
void drawPrism() {
    glBegin(GL_QUADS); // Memulai menggambar quads

    // Bagian depan (abu-abu muda)
    glColor3f(0.8f, 0.8f, 0.8f); // Light gray
    glVertex3f(-1.0f, 2.0f, -1.0f); // (-1, 2, -1)  -> kiri atas belakang
    glVertex3f(1.0f, 2.0f, -1.0f);  // (1, 2, -1)   -> kanan atas belakang
    glVertex3f(1.0f, 2.0f, 1.0f);   // (1, 2, 1)    -> kanan atas depan
    glVertex3f(-1.0f, 2.0f, 1.0f);  // (-1, 2, 1)   -> kiri atas depan

    // Bagian belakang (abu-abu gelap)
    glColor3f(0.4f, 0.4f, 0.4f); // Dark gray
    glVertex3f(-1.0f, -2.0f, -1.0f); // (-1, -2, -1) -> kiri bawah belakang
    glVertex3f(1.0f, -2.0f, -1.0f);  // (1, -2, -1)  -> kanan bawah belakang
    glVertex3f(1.0f, -2.0f, 1.0f);   // (1, -2, 1)   -> kanan bawah depan
    glVertex3f(-1.0f, -2.0f, 1.0f);  // (-1, -2, 1)  -> kiri bawah depan

    // Bagian atas (abu-abu sedang)
    glColor3f(0.6f, 0.6f, 0.6f); // Medium gray
    glVertex3f(-1.0f, -2.0f, 1.0f); // (-1, -2, 1) -> kiri bawah depan
    glVertex3f(1.0f, -2.0f, 1.0f);  // (1, -2, 1)  -> kanan bawah depan
    glVertex3f(1.0f, 2.0f, 1.0f);   // (1, 2, 1)   -> kanan atas depan
    glVertex3f(-1.0f, 2.0f, 1.0f);  // (-1, 2, 1)  -> kiri atas depan

    // Bagian bawah (abu-abu tua)
    glColor3f(0.2f, 0.2f, 0.2f); // Darker gray
    glVertex3f(-1.0f, -2.0f, -1.0f); // (-1, -2, -1) -> kiri bawah belakang
    glVertex3f(1.0f, -2.0f, -1.0f);  // (1, -2, -1)  -> kanan bawah belakang
    glVertex3f(1.0f, 2.0f, -1.0f);   // (1, 2, -1)   -> kanan atas belakang
    glVertex3f(-1.0f, 2.0f, -1.0f);  // (-1, 2, -1)  -> kiri atas belakang

    // Sisi kiri (abu-abu sangat gelap)
    glColor3f(0.1f, 0.1f, 0.1f); // Very dark gray
    glVertex3f(-1.0f, -2.0f, -1.0f); // (-1, -2, -1) -> kiri bawah belakang
    glVertex3f(-1.0f, -2.0f, 1.0f);  // (-1, -2, 1)  -> kiri bawah depan
    glVertex3f(-1.0f, 2.0f, 1.0f);   // (-1, 2, 1)   -> kiri atas depan
    glVertex3f(-1.0f, 2.0f, -1.0f);  // (-1, 2, -1)  -> kiri atas belakang

    // Sisi kanan (abu-abu terang)
    glColor3f(0.5f, 0.5f, 0.5f); // Light gray
    glVertex3f(1.0f, -2.0f, -1.0f); // (1, -2, -1)  -> kanan bawah belakang
    glVertex3f(1.0f, -2.0f, 1.0f);  // (1, -2, 1)   -> kanan bawah depan
    glVertex3f(1.0f, 2.0f, 1.0f);   // (1, 2, 1)    -> kanan atas depan
    glVertex3f(1.0f, 2.0f, -1.0f);  // (1, 2, -1)   -> kanan atas belakang

    glEnd(); // Selesai menggambar quads
}

// Fungsi untuk menggambar scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Membersihkan buffer
    glLoadIdentity(); // Mengatur matrix modelview

    // Mengatur posisi kamera
    glTranslatef(0.0f, 0.0f, -10.0f); // Maju menjauh dari objek
    glRotatef(angleX, 1.0f, 0.0f, 0.0f); // Rotasi di sekitar sumbu X
    glRotatef(angleY, 0.0f, 1.0f, 0.0f); // Rotasi di sekitar sumbu Y
    glRotatef(angleZ, 0.0f, 0.0f, 1.0f); // Rotasi di sekitar sumbu Z

    drawPrism(); // Menggambar prisma segi empat

    glutSwapBuffers(); // Menukar buffer
}

// Fungsi untuk menangani input keyboard
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'x':
        angleX += 5.0f; // Putar di sekitar sumbu X
        break;
    case 'y':
        angleY += 5.0f; // Putar di sekitar sumbu Y
        break;
    case 'z':
        angleZ += 5.0f; // Putar di sekitar sumbu Z
        break;
    case 27: // Escape key
        exit(0);
        break;
    }
    glutPostRedisplay(); // Meminta pembaruan display
}

// Fungsi untuk mengatur tampilan dan perspektif
void init() {
    glEnable(GL_DEPTH_TEST); // Mengaktifkan pengujian kedalaman
    glMatrixMode(GL_PROJECTION); // Mengatur mode matrix proyeksi
    gluPerspective(45.0f, 1.0f, 0.1f, 100.0f); // Mengatur perspektif
    glMatrixMode(GL_MODELVIEW); // Kembali ke mode modelview
}

// Fungsi utama
int main(int argc, char** argv) {
    glutInit(&argc, argv); // Inisialisasi GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Mengatur mode tampilan
    glutInitWindowSize(800, 600); // Mengatur ukuran jendela
    glutCreateWindow("3D Rectangular Prism"); // Membuat jendela
    init(); // Inisialisasi
    glutDisplayFunc(display); // Fungsi tampilan
    glutKeyboardFunc(keyboard); // Fungsi keyboard
    glutMainLoop(); // Memasuki loop utama GLUT
    return 0;
}
