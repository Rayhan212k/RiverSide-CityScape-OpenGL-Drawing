//-------------------------- library function ------------------------
#include <GLUT/glut.h>
#include<math.h>


//--------------------------- Global variables ------------------------
float sunX = -40.0f;
float sunY = 10.0f;

float c = -15.0;

float bimanX = -40;
float bimanY = 25;

float carX = -26;
float carY = -40;
const float totalSpeed = 0.2;

float p = -35;


//-------------------------------- Circle function start ----------------------------------
void circle(float rx, float ry, float cx, float cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}
//-------------------------------- Circle function end ----------------------------------









// ------------------------- sun moving function start ---------------------------------
void sun(int value) {
    sunX += 0.03;
    sunY += 0.015;
    if (sunY > 45.0f) {
        sunX = -45.0f;
        sunY = 10.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(16, sun, 0);
}
// ------------------------- sun moving function end ---------------------------------







// ------------------------- cloud moving function start ---------------------------------
void cloud(int)
{
    c += 0.08;
    if (c > 105) {
        c = -50;
    }
    glutPostRedisplay();
    glutTimerFunc(16, cloud, 0);
}

// ------------------------- cloud moving function end ---------------------------------










// ------------------------- biman moving function start ---------------------------------

void biman(int)
{
    bimanX += 0.2;
    if (bimanX > 55) {
        bimanX = -45;
        bimanY = 25;
    }
    glutPostRedisplay();
    glutTimerFunc(16, biman, 0);
}

// ------------------------- biman moving function end ---------------------------------







// ------------------------- car moving function start ---------------------------------

void car(int)
{
    if (carX < -9) {
        carX += totalSpeed;
        carY += totalSpeed * 0.9;
    }
    else if (carX < 5) {
        carX += totalSpeed;
        carY += totalSpeed * 0.65;
    }
    else if (carX < 9) {
        carX += totalSpeed;
        carY += totalSpeed * 0.6;
    }
    else if (carX < 15) {
        carX += totalSpeed;
        carY += totalSpeed * 0.5;
    }
    else if (carX < 18) {
        carX += totalSpeed;
        carY += totalSpeed * 0.4;
    }
    else if (carX < 22) {
        carX += totalSpeed;
        carY += totalSpeed * 0.4;
    }
    else {
        carX += totalSpeed;
        carY += totalSpeed * 0.45;
    }

    if (carX > 28) {
        carX = -26;
        carY = -40;
    }
    
    glutPostRedisplay();
    glutTimerFunc(16, car, 0);
}


// ------------------------- car moving function end ---------------------------------





// ------------------------- cloud moving function start ---------------------------------
//void cloud(int)
//{
//    c += 0.08;
//    if (c > 105) {
//        c = -50;
//    }
//    glutPostRedisplay();
//    glutTimerFunc(16, cloud, 0);
//}

// ------------------------- cloud moving function end ---------------------------------








//---- Display size and color --------
void init(void)
{
    glClearColor(0.51f, 0.79f, 0.93f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-40, 40, -40, 40);
}




// ------------------------------------- Display function start --------------------------------------
void display() {
  glClear(GL_COLOR_BUFFER_BIT);

    
    
    
    
    
    // ------------------------- sun start ---------------------------------
    // Draw the sun
    glColor3ub(253, 184, 19);
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.1416 / 180;
        float x = 4.6f * cos(angle) + sunX;
        float y = 5.2f * sin(angle) + sunY;
        glVertex2f(x, y);
    }
    glEnd();
    // ------------------------- sun end -----------------------------------
    
    
    
    
    
    
    // ---------------------------------------- cloud start ---------------------------------------
    // cloud 1
    glColor3ub(255, 255, 255);
    circle(4.0, 3.5, c - 10, 32);
    circle(4.0, 3.5, c - 6, 32);
    circle(4.0, 3.5, c - 2, 32);
    circle(4.0, 3.5, c - 8, 35);
    circle(4.0, 3.5, c - 4, 35);
    glEnd();
    
    // cloud 2
    glColor3ub(255, 255, 255);
    circle(4.0, 3.5, c - 60, 34);
    circle(4.0, 3.5, c - 56, 34);
    circle(4.0, 3.5, c - 52, 34);
    circle(4.0, 3.5, c - 58, 37);
    circle(4.0, 3.5, c - 54, 37);
    glEnd();
    // ---------------------------------------- cloud end ---------------------------------------
    
    
    
    

    
    // ---------------------------------------- biman start ---------------------------------------
    // body
    glBegin(GL_POLYGON);
    glColor3ub(140, 14, 63);
    glVertex2d(bimanX, bimanY);
    glVertex2d(bimanX, bimanY + 2.5);
    glVertex2d(bimanX - 8, bimanY + 2.5);
    glVertex2d(bimanX - 9, bimanY);
    glEnd();
    
    // front side
    glBegin(GL_POLYGON);
    glColor3ub(204, 0, 204);
    glVertex2d(bimanX, bimanY);
    glVertex2d(bimanX, bimanY + 2.5);
    glVertex2d(bimanX + 1.3, bimanY + 1.8);
    glVertex2d(bimanX + 3, bimanY);
    glEnd();
    
    // fan top
    glBegin(GL_POLYGON);
    glColor3ub(102, 102, 255);
    glVertex2d(bimanX - 1.5, bimanY + 2.5);
    glVertex2d(bimanX - 4, bimanY + 2.5);
    glVertex2d(bimanX - 6.5, bimanY + 5.5);
    glVertex2d(bimanX - 4.5, bimanY + 5.5);
    glEnd();
    
    // fan bottom
    glBegin(GL_POLYGON);
    glColor3ub(102, 102, 255);
    glVertex2d(bimanX - 2, bimanY);
    glVertex2d(bimanX - 4, bimanY);
    glVertex2d(bimanX - 5, bimanY - 2);
    glVertex2d(bimanX - 3, bimanY - 2);
    glEnd();
    
    // body back
    glBegin(GL_POLYGON);
    glColor3ub(153, 51, 255);
    glVertex2d(bimanX - 8, bimanY + 2.5);
    glVertex2d(bimanX - 9, bimanY);
    glVertex2d(bimanX - 13, bimanY + 6.5);
    glVertex2d(bimanX - 11, bimanY + 6.5);
    glEnd();
    
    
    // window 1
    glBegin(GL_POLYGON);
    glColor3ub(10, 51, 0);
    glVertex2d(bimanX - 2, bimanY + 0.5);
    glVertex2d(bimanX - 2, bimanY + 2);
    glVertex2d(bimanX - 3, bimanY + 2);
    glVertex2d(bimanX - 3, bimanY + 0.5);
    glEnd();
    
    // window 2
    glBegin(GL_POLYGON);
    glColor3ub(10, 51, 0);
    glVertex2d(bimanX - 4, bimanY + 0.5);
    glVertex2d(bimanX - 4, bimanY + 2);
    glVertex2d(bimanX - 5, bimanY + 2);
    glVertex2d(bimanX - 5, bimanY + 0.5);
    glEnd();
    
    // window 3
    glBegin(GL_POLYGON);
    glColor3ub(10, 51, 0);
    glVertex2d(bimanX - 6, bimanY + 0.5);
    glVertex2d(bimanX - 6, bimanY + 2);
    glVertex2d(bimanX - 7, bimanY + 2);
    glVertex2d(bimanX - 7, bimanY + 0.5);
    glEnd();
    
    // ---------------------------------------- biman end ---------------------------------------
    
    
    
    
    
    
    
    
    
//    // window 3
//    glBegin(GL_POLYGON);
//    glColor3ub(10, 51, 0);
//    glVertex2d();
//    glVertex2d();
//    glVertex2d();
//    glVertex2d();
//    glEnd();
    
    
    
    
    
    
    
    
    
    
    
    
    // ---------------------------------------- Walk way start ---------------------------------------
    //Walk left
    glBegin(GL_POLYGON);
    glColor3ub(229, 224, 214);
    glVertex2d(-40, -28);
    glVertex2d(-40, -30);
    glVertex2d(19.5, 7.5);
    glVertex2d(20, 10);
    glEnd();
    
    
    //Walk right
    glBegin(GL_POLYGON);
    glColor3ub(229, 224, 214);
    glVertex2d(20, 10);
    glVertex2d(19.5, 7.5);
    glVertex2d(40, -20);
    glVertex2d(40, -18);
    glEnd();
    // ---------------------------------------- Walk way end ---------------------------------------
    
    
    
    //-------------------------------------- fence start --------------------------------------------
    
    // --------------- left fence start ------------
    
    //fence of stick y-axis left 1
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(-36.5, -26.5);
    glVertex2f(-36.5, -20.5);
    glEnd();
    
    //fence of stick y-axis left 2
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(-30.5, -22.5);
    glVertex2f(-30.5, -16.5);
    glEnd();
    
    //fence of stick y-axis left 3
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(-24.5, -18.5);
    glVertex2f(-24.5, -12.5);
    glEnd();
    
    //fence of stick y-axis left 4
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(-18.5, -14.5);
    glVertex2f(-18.5, -8.5);
    glEnd();
    
    //fence of stick y-axis left 5
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(-12.5, -11);
    glVertex2f(-12.5, -4.5);
    glEnd();
    
    //fence of stick y-axis left 6
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(-6.5, -7);
    glVertex2f(-6.5, -1.5);
    glEnd();
    
    //fence of stick y-axis left 7
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(0.5, -2.5);
    glVertex2f(0.5, 3.5);
    glEnd();
    
    //fence of stick y-axis left 8
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(7.5, 1.5);
    glVertex2f(7.5, 7.5);
    glEnd();
    
    //fence of stick y-axis left 9
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(14.5, 6);
    glVertex2f(14.5, 11.5);
    glEnd();
    
    //fence of stick x-axis 1 for left
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(-40, -26);
    glVertex2f(14.5, 8);
    glEnd();
     
    //fence of stick x-axis 2 for left
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(-40, -24);
    glVertex2f(14.5, 10);
    glEnd();
    
    // --------------- left fence end ------------
    
    
    // --------------- right fence start ------------
    
    //fence of stick y-axis right 1
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(27.7, -1);
    glVertex2f(27.7, 5);
    glEnd();
    
    //fence of stick y-axis right 2
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(32.7, -8);
    glVertex2f(32.7, -2);
    glEnd();
    
    //fence of stick y-axis right 3
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(37.7, -15);
    glVertex2f(37.7, -9);
    glEnd();
    
    //fence of stick x-axis 1 for right
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(40, -16);
    glVertex2f(25, 5);
    glEnd();
     
    //fence of stick x-axis 2 for right
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(40, -14);
    glVertex2f(25, 7);
    glEnd();
    
    // --------------- right fence end ------------
    
    //-------------------------------------- fence end --------------------------------------------
    
    
    
    
    //--------------------------------------- Full Block background start ---------------------------------
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 153);
    glVertex2d(-40, -30);
    glVertex2d(19.5, 7.5);
    glVertex2d(40, -20);
    glVertex2d(40, -40);
    glVertex2d(-40, -40);
    glEnd();
    //--------------------------------------- Full Block background end ---------------------------------
    
    
    
    
    // ---------------------------------------------- Block start ----------------------------------------------
    //Left top block
    glBegin(GL_POLYGON);
    glColor3ub(102, 255, 102);
    glVertex2d(-40, -34);
    glVertex2d(-25, -24);
    glVertex2d(-24, -24);
    glVertex2d(-23, -24);
    glVertex2d(-22, -25);
    glVertex2d(-21, -26);
    glVertex2d(-20, -27);
    glVertex2d(-19, -28);
    glVertex2d(-18, -30);
    glVertex2d(-18, -31);
    glVertex2d(-18, -33);
    glVertex2d(-20, -35);
    glVertex2d(-25, -40);
    glVertex2d(-40, -40);
    glEnd();
    
    //Middle top block
    glBegin(GL_POLYGON);
    glColor3ub(102, 255, 102);
    glVertex2d(7, -0.3);
    glVertex2d(15, -12);
    glVertex2d(1, -19);
    glVertex2d(-12, -28);
    glVertex2d(-15, -28);
    glVertex2d(-18, -25);
    glVertex2d(-22, -21);
    glVertex2d(-26, -21.1);
    glEnd();
    
    //Right top block
    glBegin(GL_POLYGON);
    glColor3ub(102, 255, 102);
    glVertex2d(9, 1);
    glVertex2d(18, -11);
    glVertex2d(28, -4);
    glVertex2d(19.5, 7.5);
    glEnd();
    
    //Right middle block
    glBegin(GL_POLYGON);
    glColor3ub(102, 255, 102);
    glVertex2d(20, -13);
    glVertex2d(27, -24);
    glVertex2d(27.5, -24.3);
    glVertex2d(29, -24);
    glVertex2d(37.8, -17);
    glVertex2d(29.5, -6);
    glEnd();
    
    //Right bottom block
    glBegin(GL_POLYGON);
    glColor3ub(102, 255, 102);
    glVertex2d(40, -40);
    glVertex2d(40, -20);
    glVertex2d(39.3, -19);
    glVertex2d(30, -27);
    glVertex2d(30.5, -28);
    glVertex2d(30.5, -29);
    glVertex2d(30, -30);
    glVertex2d(25, -40);
    glEnd();
    
    //Middle bottom righn block
    glBegin(GL_POLYGON);
    glColor3ub(102, 255, 102);
    glVertex2d(4, -21);
    glVertex2d(17, -14);
    glVertex2d(27, -28);
    glVertex2d(27.5, -30);
    glVertex2d(27, -32);
    glVertex2d(23, -40);
    glVertex2d(20, -40);
    glVertex2d(8, -28);
    glEnd();
    
    //Middle bottom left block
    glBegin(GL_POLYGON);
    glColor3ub(102, 255, 102);
    glVertex2d(6, -29);
    glVertex2d(17, -40);
    glVertex2d(-7, -40);
    glVertex2d(-12, -34);
    glVertex2d(-12, -32);
    glVertex2d(2, -22);
    glEnd();
    
    //Left bottom block
    glBegin(GL_POLYGON);
    glColor3ub(102, 255, 102);
    glVertex2d(-20, -40);
    glVertex2d(-16, -36);
    glVertex2d(-15, -35.5);
    glVertex2d(-14, -36);
    glVertex2d(-10, -40);
    glEnd();
    
    // ---------------------------------------------- Block end ----------------------------------------------
    
    
    

    // -------------------------- object on Left top block start -------------------------
    
    //--------- pool -----------
    // big pool
    glColor3ub (153, 204, 255);
    circle(4.8, 5, -25, -32);
    glEnd();
    
    //deep small pool
    glColor3ub (102, 178, 255);
    circle(2.8, 3, -23.3, -32);
    glEnd();
    
    //----------- tree ------------
    // tree shadow
    glColor3ub (108,108,108);
    circle(2.8, 3, -32, -36);
    glEnd();
    
    // tree root
    glColor3ub (64, 64, 64);
    circle(1.11, 1.11, -33.5, -36);
    glEnd();
    
    // tree body
    glBegin(GL_POLYGON);
    glColor3ub(153, 76, 0);
    glVertex2d(-34, -36);
    glVertex2d(-33, -36);
    glVertex2d(-33, -33);
    glVertex2d(-34, -33);
    glEnd();
    
    // tree leap
    glColor3ub (0, 102, 0);
    circle(2.4, 2.2, -33, -31);
    circle(2.4, 2.2, -34, -31);
    circle(2.5, 2.4, -33, -29);
    circle(2.5, 2.4, -34, -29);
    circle(2.2, 2.2, -33.5, -27);
    circle(1, 1.9, -33.5, -26);
    glEnd();
    
    
    //--------- lamp ----------
    // lamp body
    glBegin(GL_POLYGON);
    glColor3ub(64, 64, 64);
    glVertex2d(-39, -31);
    glVertex2d(-39, -29);
    glVertex2d(-38, -29);
    glVertex2d(-38, -31);
    glEnd();
    
    //lamp stick
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(-38.4, -29);
    glVertex2f(-38.4, -22);
    glEnd();
    
    //lamp stick bold 1
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(-38.5, -29);
    glVertex2f(-38.5, -22);
    glEnd();
    
    //lamp stick bold 2
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(-38.6, -29);
    glVertex2f(-38.6, -22);
    glEnd();
    
    // lamp
    glColor3ub (255, 255, 255);
    circle(1, 1.2, -38.5, -22);
    glEnd();
    
    // ---------------------- object on Left top block end --------------------------
    
    
    
    
    
    
    
    
    // ----------------------- object on middle top block start ------------------------
    
    // --------- left lamp ----------
    // lamp left body
    glBegin(GL_POLYGON);
    glColor3ub(64, 64, 64);
    glVertex2d(-24, -21);
    glVertex2d(-24, -19);
    glVertex2d(-23, -19);
    glVertex2d(-23, -21);
    glEnd();
    
    //lamp left stick
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(-23.4, -19);
    glVertex2f(-23.4, -12);
    glEnd();
    
    //lamp left stick bold 1
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(-23.5, -19);
    glVertex2f(-23.5, -12);
    glEnd();
    
    //lamp left stick bold 2
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(-23.55, -19);
    glVertex2f(-23.55, -12);
    glEnd();
    
    
    // lamp left
    glColor3ub (255, 255, 255);
    circle(1, 1.2, -23.5, -12);
    glEnd();
    
    
    //------ Medium house-----
    //left border
    glBegin(GL_POLYGON);
    glColor3ub(210,105,30);
    glVertex2d(-18, -21);
    glVertex2d(-18, -20);
    glVertex2d(-19, -21);
    glVertex2d(-13, -26);
    glEnd();
    
    //right border
    glBegin(GL_POLYGON);
    glColor3ub(210,105,30);
    glVertex2d(-5, -21);
    glVertex2d(-6, -20);
    glVertex2d(-6, -21);
    glVertex2d(-13, -26);
    glEnd();
    
    //right wall
    glBegin(GL_POLYGON);
    glColor3ub(210,105,30);
    glVertex2d(-6, -21);
    glVertex2d(-6, -10);
    glVertex2d(-13, -13);
    glVertex2d(-13, -26);
    glEnd();
    
    //left wall
    glBegin(GL_POLYGON);
    glColor3ub(210,105,30);
    glVertex2d(-13, -13);
    glVertex2d(-18, -8);
    glVertex2d(-18, -21);
    glVertex2d(-13, -26);
    glEnd();
    
    //devide two wall
    glBegin(GL_LINES);
    glColor3ub(160,82,45);
    glVertex2f(-12.8, -25.5);
    glVertex2f(-12, -13);
    glEnd();
    
    //main roof
    glBegin(GL_POLYGON);
    glColor3ub(210,105,30);
    glVertex2d(-13, -13);
    glVertex2d(-6, -10);
    glVertex2d(-11.8, -5);
    glVertex2d(-18, -8);
    glEnd();
    
    //main roof line
    glBegin(GL_LINES);
    glColor3ub(160,82,45);
    glVertex2d(-12, -13);
    glVertex2d(-6, -10);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(160,82,45);
    glVertex2d(-12, -13);
    glVertex2d(-18, -8);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(160,82,45);
    glVertex2d(-11.8, -5);
    glVertex2d(-6, -10);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(160,82,45);
    glVertex2d(-11.8, -5);
    glVertex2d(-18, -8);
    glEnd();
    
    //deef roof
    glBegin(GL_POLYGON);
    glColor3ub(209, 210, 205);
    glVertex2d(-11.9, -12.2);
    glVertex2d(-7, -10);
    glVertex2d(-12, -6);
    glVertex2d(-17, -8.1);
    glEnd();
    
    
    
    // ------ roof ac fan ------
    //roof fan body left
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2d(-15, -9);
    glVertex2d(-14, -8.5);
    glVertex2d(-13, -9);
    glVertex2d(-14, -10);
    glEnd();
    
    //roof fan left
    glColor3ub (160, 160, 160);
    circle(0.4, 0.4, -14, -9);
    glEnd();
    
    
    //roof fan body right
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2d(-13, -8);
    glVertex2d(-12, -7.5);
    glVertex2d(-11, -8);
    glVertex2d(-12, -9);
    glEnd();
    
    //roof fan right
    glColor3ub (160, 160, 160);
    circle(0.4, 0.4, -12, -8);
    glEnd();
    
    
    
    
    // --------- window -------
    // window left top
    glBegin(GL_POLYGON);
    glColor3ub(51, 153, 255);
    glVertex2d(-17, -12);
    glVertex2d(-13, -15);
    glVertex2d(-13, -17);
    glVertex2d(-17, -14);
    glEnd();
    
    // devide window
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    // line 1
    glVertex2d(-16, -12.5);
    glVertex2d(-16, -14.6);
    // line 2
    glVertex2d(-15, -13.4);
    glVertex2d(-15, -15.5);
    // line 3
    glVertex2d(-14, -14.1);
    glVertex2d(-14, -16.3);
    glEnd();
    
    
    // window left bottom
    glBegin(GL_POLYGON);
    glColor3ub(51, 153, 255);
    glVertex2d(-17, -15);
    glVertex2d(-13, -18);
    glVertex2d(-13, -20);
    glVertex2d(-17, -17);
    glEnd();
    
    // devide window
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    // line 1
    glVertex2d(-16, -15.5);
    glVertex2d(-16, -17.6);
    // line 2
    glVertex2d(-15, -16.4);
    glVertex2d(-15, -18.5);
    // line 3
    glVertex2d(-14, -17.1);
    glVertex2d(-14, -19.3);
    glEnd();
    
    
    
    // window right top
    glBegin(GL_POLYGON);
    glColor3ub(51, 153, 255);
    glVertex2d(-11, -15);
    glVertex2d(-7, -13);
    glVertex2d(-7, -15);
    glVertex2d(-11, -17);
    glEnd();
    
    // devide window
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    // line 1
    glVertex2d(-10, -14.4);
    glVertex2d(-10, -16.4);
    // line 2
    glVertex2d(-9, -14);
    glVertex2d(-9, -16);
    // line 3
    glVertex2d(-8, -13.55);
    glVertex2d(-8, -15.55);
    glEnd();
    
    
    // window right bottom
    glBegin(GL_POLYGON);
    glColor3ub(51, 153, 255);
    glVertex2d(-11, -18);
    glVertex2d(-7, -16);
    glVertex2d(-7, -18);
    glVertex2d(-11, -20);
    glEnd();
    
    // devide window
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    // line 1
    glVertex2d(-10, -17.4);
    glVertex2d(-10, -19.4);
    // line 2
    glVertex2d(-9, -17);
    glVertex2d(-9, -19);
    // line 3
    glVertex2d(-8, -16.55);
    glVertex2d(-8, -18.55);
    glEnd();
    
    
    
    
    // --------- right lamp ----------
    // lamp right body
    glBegin(GL_POLYGON);
    glColor3ub(64, 64, 64);
    glVertex2d(-2, -8);
    glVertex2d(-1, -8);
    glVertex2d(-1, -6);
    glVertex2d(-2, -6);
    glEnd();
    
    
    //lamp right stick
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(-1.4, -6);
    glVertex2f(-1.4, 1);
    glEnd();
    
    //lamp right stick bold 1
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(-1.5, -6);
    glVertex2f(-1.5, 1);
    glEnd();
    
    //lamp right stick bold 2
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2f(-1.55, -6);
    glVertex2f(-1.55, 1);
    glEnd();
    
    // lamp right
    glColor3ub (255, 255, 255);
    circle(1, 1.2, -1.5, 2);
    glEnd();
    

    // --------- tree ----------
    // tree shadow
    glColor3ub (108,108,108);
    circle(2.2, 2.2, 2, -15);
    glEnd();
    
    // tree root
    glColor3ub (64, 64, 64);
    circle(0.7, 0.7, 1, -15);
    glEnd();
    
    // tree body
    glBegin(GL_POLYGON);
    glColor3ub(153, 76, 0);
    glVertex2d(0.5, -15);
    glVertex2d(1.5, -15);
    glVertex2d(1.5, -13);
    glVertex2d(0.5, -13);
    glEnd();
    
    // tree leap
    glColor3ub (0, 102, 0);
    circle(1.4, 1.4, 0, -12);
    circle(1.4, 1.4, 2, -12);
    circle(1.5, 1.5, 0, -10);
    circle(1.5, 1.5, 2, -10);
    circle(1.2, 2, 1, -9);
    glEnd();
    
    
    // -------- Grass right ----------
    // grass right
    glColor3ub (0, 102, 51);
    circle(1, 1, 9, -9);
    glEnd();
    
    
    // -------- Grass left ----------
    // grass left
    glColor3ub (0, 102, 51);
    circle(1, 0.7, -15.5, -25.5);
    glEnd();
    
    // ------------------------- object on middle top block End -------------------------
    
    
    
    
    
    
    
    // ------------------------- object on right top block start -------------------------
    
    //------ Big house-----
    //left border
    glBegin(GL_POLYGON);
    glColor3ub(210,105,30);
    glVertex2d(12, 0);
    glVertex2d(13, 0);
    glVertex2d(18, -8);
    glEnd();
    
    //right border
    glBegin(GL_POLYGON);
    glColor3ub(210,105,30);
    glVertex2d(27, -4);
    glVertex2d(26, -3);
    glVertex2d(18, -8);
    glEnd();
    
    //left wall
    glBegin(GL_POLYGON);
    glColor3ub(210,105,30);
    glVertex2d(13, 0);
    glVertex2d(18, -8);
    glVertex2d(19, 16);
    glVertex2d(13, 20);
    glEnd();
    
    //right wall
    glBegin(GL_POLYGON);
    glColor3ub(210,105,30);
    glVertex2d(19, 16);
    glVertex2d(18, -8);
    glVertex2d(26, -3);
    glVertex2d(26, 17);
    glEnd();
    
    //devide two wall
    glBegin(GL_LINES);
    glColor3ub(160,82,45);
    glVertex2f(19, 16);
    glVertex2f(18, -8);
    glEnd();
    
    //main roof
    glBegin(GL_POLYGON);
    glColor3ub(210,105,30);
    glVertex2d(19, 16);
    glVertex2d(26, 17);
    glVertex2d(20, 22);
    glVertex2d(13, 20);
    glEnd();
    
    //main roof line
    glBegin(GL_LINES);
    glColor3ub(160,82,45);
    glVertex2d(19, 16);
    glVertex2d(26, 17);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(160,82,45);
    glVertex2d(19, 16);
    glVertex2d(13, 20);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(160,82,45);
    glVertex2d(20, 22);
    glVertex2d(13, 20);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(160,82,45);
    glVertex2d(20, 22);
    glVertex2d(26, 17);
    glEnd();
    
    //deef roof
    glBegin(GL_POLYGON);
    glColor3ub(209, 210, 205);
    glVertex2d(19, 16.8);
    glVertex2d(24.7, 17.5);
    glVertex2d(20, 21.4);
    glVertex2d(14.6, 19.8);
    glEnd();
    
    
    
    
    
    // ------ roof ac fan ------
    //roof fan body left
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2d(17, 19.2);
    glVertex2d(18, 19.5);
    glVertex2d(18.8, 19);
    glVertex2d(18, 18.2);
    glEnd();
    
    
    //roof fan left
    glColor3ub (160, 160, 160);
    circle(0.4, 0.4, 18, 19);
    glEnd();
    
    
    //roof fan body right
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2d(18.5, 20);
    glVertex2d(19.5, 20.5);
    glVertex2d(20.2, 19.5);
    glVertex2d(19.5, 19);
    glEnd();
    
    //roof fan right
    glColor3ub (160, 160, 160);
    circle(0.4, 0.4, 19.4, 19.7);
    glEnd();
    
    
    
    
    
    
    // --------- window -------
    // window left top top
    glBegin(GL_POLYGON);
    glColor3ub(51, 153, 255);
    glVertex2d(14, 17);
    glVertex2d(14, 15);
    glVertex2d(18, 12);
    glVertex2d(18, 14);
    glEnd();
    
    // devide window
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    // line 1
    glVertex2d(15, 16.2);
    glVertex2d(15, 14);
    // line 2
    glVertex2d(16, 15.5);
    glVertex2d(16, 13.5);
    // line 3
    glVertex2d(17, 14.6);
    glVertex2d(17, 12.5);
    glEnd();
    
    
    // window left top bottom
    glBegin(GL_POLYGON);
    glColor3ub(51, 153, 255);
    glVertex2d(14, 14);
    glVertex2d(14, 12);
    glVertex2d(18, 9);
    glVertex2d(18, 11);
    glEnd();
    
    // devide window
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    // line 1
    glVertex2d(15, 13.2);
    glVertex2d(15, 11);
    // line 2
    glVertex2d(16, 12.5);
    glVertex2d(16, 10.5);
    // line 3
    glVertex2d(17, 11.6);
    glVertex2d(17, 9.5);
    glEnd();
    
    
    // window left bottom top
    glBegin(GL_POLYGON);
    glColor3ub(51, 153, 255);
    glVertex2d(14, 10);
    glVertex2d(14, 8);
    glVertex2d(18, 5);
    glVertex2d(18, 7);
    glEnd();
    
    // devide window
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    // line 1
    glVertex2d(15, 9.2);
    glVertex2d(15, 7);
    // line 2
    glVertex2d(16, 8.5);
    glVertex2d(16, 6.5);
    // line 3
    glVertex2d(17, 7.6);
    glVertex2d(17, 5.5);
    glEnd();
    
    
    // window left bottom bottom
    glBegin(GL_POLYGON);
    glColor3ub(51, 153, 255);
    glVertex2d(14, 7);
    glVertex2d(14, 5);
    glVertex2d(18, 2);
    glVertex2d(18, 4);
    glEnd();
    
    // devide window
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    // line 1
    glVertex2d(15, 6.2);
    glVertex2d(15, 4);
    // line 2
    glVertex2d(16, 5.5);
    glVertex2d(16, 3.5);
    // line 3
    glVertex2d(17, 4.6);
    glVertex2d(17, 2.5);
    glEnd();
    
    
    
    
    
    // window right top top
    glBegin(GL_POLYGON);
    glColor3ub(51, 153, 255);
    glVertex2d(20, 14);
    glVertex2d(20, 12);
    glVertex2d(25, 12);
    glVertex2d(25, 14);
    glEnd();
    
    // devide window
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    // line 1
    glVertex2d(21, 14);
    glVertex2d(21, 12);
    // line 2
    glVertex2d(22, 14);
    glVertex2d(22, 12);
    // line 3
    glVertex2d(23, 14);
    glVertex2d(23, 12);
    // line 4
    glVertex2d(24, 14);
    glVertex2d(24, 12);
    glEnd();
    
    
    // window right top bottom
    glBegin(GL_POLYGON);
    glColor3ub(51, 153, 255);
    glVertex2d(20, 11);
    glVertex2d(20, 9);
    glVertex2d(25, 9);
    glVertex2d(25, 11);
    glEnd();
    
    // devide window
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    // line 1
    glVertex2d(21, 11);
    glVertex2d(21, 9);
    // line 2
    glVertex2d(22, 11);
    glVertex2d(22, 9);
    // line 3
    glVertex2d(23, 11);
    glVertex2d(23, 9);
    // line 4
    glVertex2d(24, 11);
    glVertex2d(24, 9);
    glEnd();
    
    
    
    // window right bottom top
    glBegin(GL_POLYGON);
    glColor3ub(51, 153, 255);
    glVertex2d(20, 7);
    glVertex2d(20, 5);
    glVertex2d(25, 5);
    glVertex2d(25, 7);
    glEnd();
    
    // devide window
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    // line 1
    glVertex2d(21, 7);
    glVertex2d(21, 5);
    // line 2
    glVertex2d(22, 7);
    glVertex2d(22, 5);
    // line 3
    glVertex2d(23, 7);
    glVertex2d(23, 5);
    // line 4
    glVertex2d(24, 7);
    glVertex2d(24, 5);
    glEnd();
    
    
    // window right bottom bottom
    glBegin(GL_POLYGON);
    glColor3ub(51, 153, 255);
    glVertex2d(20, 4);
    glVertex2d(20, 2);
    glVertex2d(25, 2);
    glVertex2d(25, 4);
    glEnd();
    
    // devide window
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    // line 1
    glVertex2d(21, 4);
    glVertex2d(21, 2);
    // line 2
    glVertex2d(22, 4);
    glVertex2d(22, 2);
    // line 3
    glVertex2d(23, 4);
    glVertex2d(23, 2);
    // line 4
    glVertex2d(24, 4);
    glVertex2d(24, 2);
    glEnd();
    
    
    // ------------------------- object on right top block end -------------------------
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // ----------------------------------- car start --------------------------------------
    
//    glColor3ub(0, 0, 255); // Car body color
//    glBegin(GL_POLYGON);
//    glVertex2f(carX, carY);
//    glVertex2f(carX + 4, carY);
//    glVertex2f(carX + 4, carY + 2);
//    glVertex2f(carX, carY + 2);
//    glEnd();
//
//    // Draw car wheels
//    glColor3ub(0, 0, 0); // Wheel color
//    circle(0.5, 0.5, carX + 1, carY);
//    circle(0.5, 0.5, carX + 3, carY);
//    float carX = -15;
//    float carY = -31;
    
    // car main body
    glColor3ub(0, 0, 255);
    glBegin(GL_POLYGON);
    glVertex2d(carX, carY);
    glVertex2d(carX + 1, carY - 2);
    glVertex2d(carX - 2, carY - 5);
    glVertex2d(carX - 3, carY - 3);
    glEnd();
    
    // car front body
    glColor3ub(204, 102, 0); // Car body color
    glBegin(GL_POLYGON);
    glVertex2d(carX + 1, carY - 2);
    glVertex2d(carX, carY);
    glVertex2d(carX + 1.5, carY - 0.2);
    glVertex2d(carX + 2, carY - 1);
    glEnd();

    // car wheels
    glColor3ub(0, 0, 0); // Wheel color
    circle(0.5, 0.5, carX + 1, carY - 2);
    circle(0.5, 0.5, carX - 1, carY - 4);
    glEnd();
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // ------------------------- object on right middle block start -------------------------
    
    //------ small house-----
    //left border
    glBegin(GL_POLYGON);
    glColor3ub(210,105,30);
    glVertex2d(23,-15);
    glVertex2d(24, -14);
    glVertex2d(28, -22);
    glVertex2d(28, -23);
    glEnd();
    
    //right border
    glBegin(GL_POLYGON);
    glColor3ub(210,105,30);
    glVertex2d(28, -22);
    glVertex2d(28, -23);
    glVertex2d(36, -17.8);
    glVertex2d(35, -17);
    glEnd();
    
    //left wall
    glBegin(GL_POLYGON);
    glColor3ub(210,105,30);
    glVertex2d(24, -14);
    glVertex2d(24, -6);
    glVertex2d(29, -13);
    glVertex2d(28, -22);
    glEnd();
    
    //right wall
    glBegin(GL_POLYGON);
    glColor3ub(210,105,30);
    glVertex2d(28, -22);
    glVertex2d(29, -13);
    glVertex2d(36, -11);
    glVertex2d(35, -17);
    glEnd();
    
    //devide two wall
    glBegin(GL_LINES);
    glColor3ub(160,82,45);
    glVertex2d(29, -13);
    glVertex2d(28, -22);
    glEnd();
    
    //main roof
    glBegin(GL_POLYGON);
    glColor3ub(210,105,30);
    glVertex2d(29, -13);
    glVertex2d(36, -11);
    glVertex2d(31, -4);
    glVertex2d(24, -6);
    glEnd();
    
    //main roof line
    glBegin(GL_LINES);
    glColor3ub(160,82,45);
    glVertex2d(24, -6);
    glVertex2d(29, -13);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(160,82,45);
    glVertex2d(29, -13);
    glVertex2d(36, -11);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(160,82,45);
    glVertex2d(36, -11);
    glVertex2d(31, -4);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(160,82,45);
    glVertex2d(31, -4);
    glVertex2d(24, -6);
    glEnd();
    
    //deef roof
    glBegin(GL_POLYGON);
    glColor3ub(209, 210, 205);
    glVertex2d(25, -6.5);
    glVertex2d(29, -12);
    glVertex2d(35, -10.5);
    glVertex2d(31, -4.8);
    glEnd();
    
    
    
    
    
    // ------ roof ac fan ------
    //roof fan body left
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2d(27, -7);
    glVertex2d(27.5, -8);
    glVertex2d(28.8, -8);
    glVertex2d(28.5, -6.5);
    glEnd();
    
    
    //roof fan left
    glColor3ub (160, 160, 160);
    circle(0.4, 0.4, 28, -7.3);
    glEnd();
    
    
    //roof fan body right
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2d(29.3, -6.2);
    glVertex2d(30.5, -6.);
    glVertex2d(31, -7);
    glVertex2d(29.8, -7.5);
    glEnd();
    
    //roof fan right
    glColor3ub (160, 160, 160);
    circle(0.4, 0.4, 30.1, -6.5);
    glEnd();
    
    
    
    
    
    
    // --------- window -------
    // window left
    glBegin(GL_POLYGON);
    glColor3ub(51, 153, 255);
    glVertex2d(25, -10);
    glVertex2d(25, -12.5);
    glVertex2d(27.7, -16);
    glVertex2d(27.8, -14);
    glEnd();
    
    // devide window
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    // line 1
    glVertex2d(26, -11.5);
    glVertex2d(26, -14);
    // line 2
    glVertex2d(27, -13);
    glVertex2d(27, -15.4);
    glEnd();
    
    
    
    // window right
    glBegin(GL_POLYGON);
    glColor3ub(51, 153, 255);
    glVertex2d(30, -15);
    glVertex2d(30, -17.5);
    glVertex2d(34, -16.2);
    glVertex2d(34, -14);
    glEnd();
    
    // devide window
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    // line 1
    glVertex2d(31.5, -14.6);
    glVertex2d(31.5, -17.1);
    // line 2
    glVertex2d(33, -14.3);
    glVertex2d(33, -16.8);
    glEnd();
    
    
    
    // ------------------------- object on right middle block end -------------------------
    
    
    
    
    
    
    
    
    // ------------------------- object on right bottom block end -------------------------
    
    // -------- Grass right ----------
    // grass top
    glColor3ub (0, 102, 51);
    circle(0.8, 0.8, 35, -26);
    glEnd();
    
    
    
    // --------- tree top ----------
    // tree shadow
    glColor3ub (108,108,108);
    circle(1.8, 1.8, 38, -26);
    glEnd();
    
    // tree root
    glColor3ub (64, 64, 64);
    circle(0.6, 0.6, 37, -26);
    glEnd();
    
    // tree body
    glBegin(GL_POLYGON);
    glColor3ub(153, 76, 0);
    glVertex2d(36.8, -26);
    glVertex2d(37.2, -26);
    glVertex2d(37.2, -24);
    glVertex2d(36.8, -24);
    glEnd();
    
    // tree leap
    glBegin(GL_POLYGON);
    glColor3ub (0, 102, 0);
    glVertex2d(38, -24);
    glVertex2d(36, -24);
    glVertex2d(37, -19);
    glEnd();
    
    
    
    // grass middle
    glColor3ub (0, 102, 51);
    circle(0.8, 0.8, 38, -30);
    glEnd();
    
    
    
    
    
    // --------- tree bottom ----------
    // tree shadow
    glColor3ub (108,108,108);
    circle(2.2, 2.2, 36, -37);
    glEnd();
    
    // tree root
    glColor3ub (64, 64, 64);
    circle(0.7, 0.7, 35, -37);
    glEnd();
    
    // tree body
    glBegin(GL_POLYGON);
    glColor3ub(153, 76, 0);
    glVertex2d(34.5, -37);
    glVertex2d(35.5, -37);
    glVertex2d(35.5, -35);
    glVertex2d(34.5, -35);
    glEnd();
    
    // tree leap
    glColor3ub (0, 102, 0);
    circle(1.4, 1.4, 34, -34);
    circle(1.4, 1.4, 36, -34);
    circle(1.4, 1.5, 34, -32.5);
    circle(1.4, 1.5, 36, -32.5);
    circle(1.2, 2, 35, -31.5);
    glEnd();
    
    
    
    
    // grass bottom
    glColor3ub (0, 102, 51);
    circle(0.8, 0.8, 28, -38);
    glEnd();
    
    
    // ------------------------- object on right bottom block end -------------------------
    
    
    
    
    
    
    
    
    
    // ------------------------- object on middle bottom right block start -------------------------
    
    
    // --------- tree top ----------
    // tree shadow
    glColor3ub (108,108,108);
    circle(2.2, 2.2, 16, -22);
    glEnd();
    
    // tree root
    glColor3ub (64, 64, 64);
    circle(0.7, 0.7, 15, -22);
    glEnd();
    
    // tree body
    glBegin(GL_POLYGON);
    glColor3ub(153, 76, 0);
    glVertex2d(14.5, -22);
    glVertex2d(15.5, -22);
    glVertex2d(15.5, -19);
    glVertex2d(14.5, -19);
    glEnd();
    
    // tree leap
    glColor3ub (0, 102, 0);
    circle(1.4, 1.4, 14, -18);
    circle(1.4, 1.4, 16, -18);
    circle(1.5, 1.5, 14, -16);
    circle(1.5, 1.5, 16, -16);
    circle(1.2, 2, 15, -15);
    glEnd();
    
    
    
    
    // grass left
    glColor3ub (0, 102, 51);
    circle(0.8, 0.8, 15, -28);
    glEnd();
    
    
    
    
    
    
    // --------- tree bottom ----------
    // tree shadow
    glColor3ub (108,108,108);
    circle(1.8, 1.8, 21, -37);
    glEnd();
    
    // tree root
    glColor3ub (64, 64, 64);
    circle(0.6, 0.6, 20, -37);
    glEnd();
    
    // tree body
    glBegin(GL_POLYGON);
    glColor3ub(153, 76, 0);
    glVertex2d(19.5, -37);
    glVertex2d(20.5, -37);
    glVertex2d(20.5, -35);
    glVertex2d(19.5, -35);
    glEnd();
    
    // tree leap
    glBegin(GL_POLYGON);
    glColor3ub (0, 102, 0);
    glVertex2d(21.5, -35);
    glVertex2d(18.5, -35);
    glVertex2d(20, -27);
    glEnd();
    
    
    
    // grass right
    glColor3ub (0, 102, 51);
    circle(0.8, 0.8, 25, -30);
    glEnd();
    
    
    
    // ------------------------- object on middle bottom right block end -------------------------
    
    
    
    
    
    
    
    
    
    
    
    // ------------------------- object on middle bottom left block start -------------------------
    
    
    // ------ tree top ---------
    // tree shadow
    glColor3ub(108, 108, 108);
    circle(1.8, 1.8, -5, -31);
    glEnd();

    // tree root
    glColor3ub(64, 64, 64);
    circle(0.6, 0.6, -6, -31);
    glEnd();

    // tree body
    glBegin(GL_POLYGON);
    glColor3ub(153, 76, 0);
    glVertex2d(-6.5, -31);
    glVertex2d(-5.5, -31);
    glVertex2d(-5.5, -29);
    glVertex2d(-6.5, -29);
    glEnd();

    // tree leap
    glBegin(GL_POLYGON);
    glColor3ub(0, 102, 0);
    glVertex2d(-4.5, -29);
    glVertex2d(-7.5, -29);
    glVertex2d(-6, -23);
    glEnd();

    
    
    
    
    
    //----- tree middle ----
    // tree shadow
    glColor3ub (108,108,108);
    circle(2.2, 2.2, 1, -30);
    glEnd();

    // tree root
    glColor3ub (64, 64, 64);
    circle(0.7, 0.7, 0, -30);
    glEnd();

    // tree body
    glBegin(GL_POLYGON);
    glColor3ub(153, 76, 0);
    glVertex2d(-0.5, -30);
    glVertex2d(0.5, -30);
    glVertex2d(0.5, -28);
    glVertex2d(-0.5, -28);
    glEnd();

    // tree leap
    glColor3ub (0, 102, 0);
    circle(1.4, 1.4, -1, -27);
    circle(1.4, 1.4, 1, -27);
    circle(1.4, 1.5, -1, -25.5);
    circle(1.4, 1.5, 1, -25.5);
    circle(1.2, 2, 0, -24.5);
    glEnd();


    

    // ------- tree bottom -------
    // tree shadow
    glColor3ub(108, 108, 108);
    circle(1.8, 1.8, 10, -38);
    glEnd();

    // tree root
    glColor3ub(64, 64, 64);
    circle(0.6, 0.6, 9, -38);
    glEnd();

    // tree body
    glBegin(GL_POLYGON);
    glColor3ub(153, 76, 0);
    glVertex2d(8.8, -38);
    glVertex2d(9.2, -38);
    glVertex2d(9.2, -36);
    glVertex2d(8.8, -36);
    glEnd();

    // tree leap
    glBegin(GL_POLYGON);
    glColor3ub(0, 102, 0);
    glVertex2d(10, -36);
    glVertex2d(8, -36);
    glVertex2d(9, -31);
    glEnd();

     
    
    
    // ---- lamp ------
    // lamp left body
    glBegin(GL_POLYGON);
    glColor3ub(64, 64, 64);
    glVertex2d(-9.5, -33);
    glVertex2d(-10.5, -33);
    glVertex2d(-10.5, -31);
    glVertex2d(-9.5, -31);
    glEnd();
    
    //lamp left stick
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2d(-10.1, -31);
    glVertex2d(-10.1, -22);
    glEnd();
    
    //lamp left stick bold 1
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2d(-10, -31);
    glVertex2d(-10, -22);
    glEnd();
    
    //lamp left stick bold 2
    glBegin(GL_LINES);
    glColor3ub(96, 96, 96);
    glVertex2d(-9.95, -31);
    glVertex2d(-9.95, -22);
    glEnd();
    
    
    // lamp left
    glColor3ub (255, 255, 255);
    circle(1, 1.2, -10, -23);
    glEnd();
    
    
    // ------------------------- object on middle bottom left block end -------------------------
    
    
    
    
    
    
    
    
    
    
    
    
    // ------------------------- object on left bottom block start -------------------------
    
    // grass
    glColor3ub (0, 102, 51);
    circle(0.8, 0.8, -15, -38);
    glEnd();
    
    // ------------------------- object on left bottom block end -------------------------
    
    
    

  glFlush();
}
// ------------------------------------- Display function end --------------------------------------










int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutInitWindowSize(1000,800);
    glutInitWindowPosition(100,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow(" city port ");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, sun, 0);
    glutTimerFunc(0, cloud, 0);
    glutTimerFunc(0, biman, 0);
    glutTimerFunc(0, car, 0);
    glutMainLoop();
    return 0;
}

