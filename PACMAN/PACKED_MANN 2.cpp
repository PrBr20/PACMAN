# include "iGraphics.h"

int maze[18][28]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                  {1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
                  {1,0,1,1,1,1,1,1,1,0,1,0,0,1,0,0,1,0,1,1,1,1,0,1,0,1,0,1},
                  {1,3,1,0,0,1,0,0,1,0,1,0,1,1,1,0,1,0,0,0,0,0,0,1,3,1,0,1},
                  {1,0,0,0,0,0,0,3,0,0,1,0,0,0,0,0,1,1,1,0,1,1,0,1,0,0,0,1},
                  {1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,0,0,1,1,0,1,0,1,0,1},
                  {1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
                  {1,0,1,0,1,0,0,0,1,0,1,1,2,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1},
                  {0,0,0,0,0,0,1,0,1,0,2,0,0,1,0,0,2,0,1,0,0,0,0,0,1,0,0,0},
                  {1,1,1,1,0,1,1,0,1,0,1,1,1,1,2,1,1,0,1,1,1,1,1,0,0,0,1,1},
                  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1},
                  {1,0,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,0,0,0,0,1,0,1},
                  {1,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,1,1,0,0,0,1},
                  {1,0,3,0,0,1,1,0,1,1,0,0,0,1,0,1,0,1,1,0,1,0,1,1,1,1,0,1},
                  {1,0,0,1,0,0,0,0,1,1,0,1,0,1,0,1,0,1,1,0,1,0,0,1,0,0,0,1},
                  {1,0,1,1,1,1,1,0,1,1,0,1,0,1,0,1,0,1,1,0,1,1,0,1,1,0,1,1},
                  {1,0,0,0,0,0,0,3,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,3,0,0,1,1},
                  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};

//packamn initializer
double x=128, y=600,spike_x=576,spike_y=300,dx,dy,ma=1000000000000000;
int i,j,keyr=1,keyl=0,keyu=0,keyd=0,cnt=0,smooth[4]={0},change=0,d=0;
char st='r',ptime[50],sc[50];
int t=0,score=0,live=3,deatt=0,dea_key=0,deatt2=0;
int blinky_xi=480,blinky_yi=360,pinky_xi=512,pinky_yi=360,inky_xi=576,inky_yi=360,clyde_xi=608,clyde_yi=360,spike_xi=576,spike_yi=300;

//ghost initializer
int ghost_dx,ghost_dy;
//pinky
int blinky_x=480,blinky_y=360,blinky_key[4]={0},blinky_dis[4]={0},cnb[4]={0};
char kimb='l';
//pinky
int pinky_x=512,pinky_y=360,pinky_key[4]={0},pinky_dis[4]={0},cnp[4]={0};
char kimp='u';
//inky
int inky_x=576,inky_y=360,inky_key[4]={0},inky_dis[4]={0},cni[4]={0};
char kimi='d';
//clyde
int clyde_x=608,clyde_y=360,clyde_key[4]={0},clyde_dis[4]={0},cnc[4]={0};
char kimc='r';


//eat ghost
int bl_de=0,pi_de=0,in_de=0,cl_de=0,bl_te,pi_te,in_te,cl_te;




void spikemove();

int chk(char p);

void smoo();

void clo();




void blinky_move();

int blinky_distance(int r, int l, int u, int d);

void blinky_change();



void pinky_move();

int pinky_distance(int r, int l, int u, int d);

void pinky_change();



void inky_move();

int inky_distance(int r, int l, int u, int d);

void inky_change();



void clyde_move();

int clyde_distance(int r, int l, int u, int d);

void clyde_change();


int check_ghost(double x,double y, char r);


void packman_death();

void frighten_mod();

/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
    iClear();
    iSetColor(255,0,0);
    int cnt=0;
    for(i=0;i<18;i++){
        for(j=0;j<28;j++){
            if(maze[i][j]==1){
                iSetColor(15,125,238);
                iShowBMP(x+32*j,y-30*i,"blockmain.bmp");
            }
            else if(maze[i][j]==2){
                iSetColor(255,0,0);
                iFilledRectangle(x+32*j,y-30*i,32,30);
            }
            else if(maze[i][j]==0){
                    iSetColor(249, 183, 156);
                    iFilledCircle(x+32*j+32/2,y-30*i+30/2,5);
            }
            else if(maze[i][j]==3){
                    iSetColor(27, 245, 59);
                    iFilledCircle(x+32*j+32/2,y-30*i+30/2,8);
            }
        }
    }


    if(dea_key==0){

        if(keyr==1){
                if(change<5){iShowBMP2(spike_x,spike_y,"spike1.bmp",0x000000);change++;}
                else if(change==5){iShowBMP2(spike_x,spike_y,"closy_spike.bmp",0x000000);change=0;}
        }
        else if(keyl==1){
                if(change<5){iShowBMP2(spike_x,spike_y,"spike2.bmp",0x000000);change++;}
                else if(change==5){iShowBMP2(spike_x,spike_y,"closy_spike.bmp",0x000000);change=0;}
        }
        else if(keyd==1){
                if(change<5){iShowBMP2(spike_x,spike_y,"spike3.bmp",0x000000);change++;}
                else if(change==5){iShowBMP2(spike_x,spike_y,"closy_spike.bmp",0x000000);change=0;}
        }
        else if(keyu==1){
                if(change<5){iShowBMP2(spike_x,spike_y,"spike4.bmp",0x000000);change++;}
                else if(change==5){iShowBMP2(spike_x,spike_y,"closy_spike.bmp",0x000000);change=0;}
        }
        else {
            if(st=='r')iShowBMP2(spike_x,spike_y,"spike1.bmp",0x000000);
            else if(st=='l')iShowBMP2(spike_x,spike_y,"spike2.bmp",0x000000);
            else if(st=='d')iShowBMP2(spike_x,spike_y,"spike3.bmp",0x000000);
            else if(st=='u')iShowBMP2(spike_x,spike_y,"spike4.bmp",0x000000);
        }



        if(blinky_key[0]==1){
            if(cnb[0]==0){iShowBMP2(blinky_x,blinky_y,"blinky_r1.bmp",0x000000);cnb[0]=1;}
            else if(cnb[0]==1){iShowBMP2(blinky_x,blinky_y,"blinky_r2.bmp",0x000000);cnb[0]=0;}
        }
        else if(blinky_key[1]==1){
            if(cnb[1]==0){iShowBMP2(blinky_x,blinky_y,"blinky_l1.bmp",0x000000);cnb[1]=1;}
            else if(cnb[1]==1){iShowBMP2(blinky_x,blinky_y,"blinky_l2.bmp",0x000000);cnb[1]=0;}
        }
        else if(blinky_key[2]==1){
            if(cnb[2]==0){iShowBMP2(blinky_x,blinky_y,"blinky_u1.bmp",0x000000);cnb[2]=1;}
            else if(cnb[2]==1){iShowBMP2(blinky_x,blinky_y,"blinky_u2.bmp",0x000000);cnb[2]=0;}
        }
        else if(blinky_key[3]==1){
            if(cnb[3]==0){iShowBMP2(blinky_x,blinky_y,"blinky_d1.bmp",0x000000);cnb[3]=1;}
            else if(cnb[3]==1){iShowBMP2(blinky_x,blinky_y,"blinky_d2.bmp",0x000000);cnb[3]=0;}
        }




        if(pinky_key[0]==1){
            if(cnp[0]==0){iShowBMP(pinky_x,pinky_y,"pinky_r1.bmp");cnp[0]=1;}
            else if(cnp[0]==1){iShowBMP(pinky_x,pinky_y,"pinky_r2.bmp");cnp[0]=0;}
        }
        else if(pinky_key[1]==1){
            if(cnp[1]==0){iShowBMP(pinky_x,pinky_y,"pinky_l1.bmp");cnp[1]=1;}
            else if(cnp[1]==1){iShowBMP(pinky_x,pinky_y,"pinky_l2.bmp");cnp[1]=0;}
        }
        else if(pinky_key[2]==1){
            if(cnp[2]==0){iShowBMP(pinky_x,pinky_y,"pinky_u1.bmp");cnp[2]=1;}
            else if(cnp[2]==1){iShowBMP(pinky_x,pinky_y,"pinky_u2.bmp");cnp[2]=0;}
        }
        else if(pinky_key[3]==1){
            if(cnp[3]==0){iShowBMP(pinky_x,pinky_y,"pinky_d1.bmp");cnp[3]=1;}
            else if(cnp[3]==1){iShowBMP(pinky_x,pinky_y,"pinky_d2.bmp");cnp[3]=0;}
        }





        if(inky_key[0]==1){
            if(cni[0]==0){iShowBMP(inky_x,inky_y,"inky_r1.bmp");cni[0]=1;}
            else if(cni[0]==1){iShowBMP(inky_x,inky_y,"inky_r2.bmp");cni[0]=0;}
        }
        else if(inky_key[1]==1){
            if(cni[1]==0){iShowBMP(inky_x,inky_y,"inky_l1.bmp");cni[1]=1;}
            else if(cni[1]==1){iShowBMP(inky_x,inky_y,"inky_l1.bmp");cni[1]=0;}
        }
        else if(inky_key[2]==1){
            if(cni[2]==0){iShowBMP(inky_x,inky_y,"inky_u1.bmp");cni[2]=1;}
            else if(cni[2]==1){iShowBMP(inky_x,inky_y,"inky_u2.bmp");cni[2]=0;}
        }
        else if(inky_key[3]==1){
            if(cni[3]==0){iShowBMP(inky_x,inky_y,"inky_d1.bmp");cni[3]=1;}
            else if(cni[3]==1){iShowBMP(inky_x,inky_y,"inky_d2.bmp");cni[3]=0;}
        }





        if(clyde_key[0]==1){
            if(cnc[0]==0){iShowBMP(clyde_x,clyde_y,"clyde_r1.bmp");cnc[0]=1;}
            else if(cnc[0]==1){iShowBMP(clyde_x,clyde_y,"clyde_r2.bmp");cnc[0]=0;}
        }
        else if(clyde_key[1]==1){
            if(cnc[1]==0){iShowBMP(clyde_x,clyde_y,"clyde_l1.bmp");cnc[1]=1;}
            else if(cnc[1]==1){iShowBMP(clyde_x,clyde_y,"clyde_l2.bmp");cnc[1]=0;}
        }
        else if(clyde_key[2]==1){
            if(cnc[2]==0){iShowBMP(clyde_x,clyde_y,"clyde_u1.bmp");cnc[2]=1;}
            else if(cnc[2]==1){iShowBMP(clyde_x,clyde_y,"clyde_u2.bmp");cnc[2]=0;}
        }
        else if(clyde_key[3]==1){
            if(cnc[3]==0){iShowBMP(clyde_x,clyde_y,"clyde_d1.bmp");cnc[3]=1;}
            else if(cnc[3]==1){iShowBMP(clyde_x,clyde_y,"clyde_d2.bmp");cnc[3]=0;}
        }

    }
    else if(dea_key==2){
        if(t<deatt2){

            if(keyr==1){
                if(change<5){iShowBMP2(spike_x,spike_y,"spike1.bmp",(0,0,0));change++;}
                else if(change==5){iShowBMP2(spike_x,spike_y,"closy_spike.bmp",(0,0,0));change=0;}
            }
            else if(keyl==1){
                    if(change<5){iShowBMP2(spike_x,spike_y,"spike2.bmp",(0,0,0));change++;}
                    else if(change==5){iShowBMP2(spike_x,spike_y,"closy_spike.bmp",(0,0,0));change=0;}
            }
            else if(keyd==1){
                    if(change<5){iShowBMP2(spike_x,spike_y,"spike3.bmp",(0,0,0));change++;}
                    else if(change==5){iShowBMP2(spike_x,spike_y,"closy_spike.bmp",(0,0,0));change=0;}
            }
            else if(keyu==1){
                    if(change<5){iShowBMP2(spike_x,spike_y,"spike4.bmp",(0,0,0));change++;}
                    else if(change==5){iShowBMP2(spike_x,spike_y,"closy_spike.bmp",(0,0,0));change=0;}
            }
            else {
                if(st=='r')iShowBMP2(spike_x,spike_y,"spike1.bmp",(0,0,0));
                else if(st=='l')iShowBMP2(spike_x,spike_y,"spike2.bmp",(0,0,0));
                else if(st=='d')iShowBMP2(spike_x,spike_y,"spike3.bmp",(0,0,0));
                else if(st=='u')iShowBMP2(spike_x,spike_y,"spike4.bmp",(0,0,0));
            }



            if(bl_de==0){
                if(blinky_key[0]==1){
                    if(cnb[0]==0){iShowBMP(blinky_x,blinky_y,"gd1.bmp");cnb[0]=1;}
                    else if(cnb[0]==1){iShowBMP(blinky_x,blinky_y,"gd2.bmp");cnb[0]=0;}
                }
                else if(blinky_key[1]==1){
                    if(cnb[1]==0){iShowBMP(blinky_x,blinky_y,"gd1.bmp");cnb[1]=1;}
                    else if(cnb[1]==1){iShowBMP(blinky_x,blinky_y,"gd2.bmp");cnb[1]=0;}
                }
                else if(blinky_key[2]==1){
                    if(cnb[2]==0){iShowBMP(blinky_x,blinky_y,"gd1.bmp");cnb[2]=1;}
                    else if(cnb[2]==1){iShowBMP(blinky_x,blinky_y,"gd2.bmp");cnb[2]=0;}
                }
                else if(blinky_key[3]==1){
                    if(cnb[3]==0){iShowBMP(blinky_x,blinky_y,"gd1.bmp");cnb[3]=1;}
                    else if(cnb[3]==1){iShowBMP(blinky_x,blinky_y,"gd2.bmp");cnb[3]=0;}
                }
            }



            if(pi_de==0){
                if(pinky_key[0]==1){
                    if(cnp[0]==0){iShowBMP(pinky_x,pinky_y,"gd1.bmp");cnp[0]=1;}
                    else if(cnp[0]==1){iShowBMP(pinky_x,pinky_y,"gd2.bmp");cnp[0]=0;}
                }
                else if(pinky_key[1]==1){
                    if(cnp[1]==0){iShowBMP(pinky_x,pinky_y,"gd1.bmp");cnp[1]=1;}
                    else if(cnp[1]==1){iShowBMP(pinky_x,pinky_y,"gd2.bmp");cnp[1]=0;}
                }
                else if(pinky_key[2]==1){
                    if(cnp[2]==0){iShowBMP(pinky_x,pinky_y,"gd1.bmp");cnp[2]=1;}
                    else if(cnp[2]==1){iShowBMP(pinky_x,pinky_y,"gd2.bmp");cnp[2]=0;}
                }
                else if(pinky_key[3]==1){
                    if(cnp[3]==0){iShowBMP(pinky_x,pinky_y,"gd1.bmp");cnp[3]=1;}
                    else if(cnp[3]==1){iShowBMP(pinky_x,pinky_y,"gd2.bmp");cnp[3]=0;}
                }
            }




            if(in_de==0){
                if(inky_key[0]==1){
                    if(cni[0]==0){iShowBMP(inky_x,inky_y,"gd1.bmp");cni[0]=1;}
                    else if(cni[0]==1){iShowBMP(inky_x,inky_y,"gd2.bmp");cni[0]=0;}
                }
                else if(inky_key[1]==1){
                    if(cni[1]==0){iShowBMP(inky_x,inky_y,"gd1.bmp");cni[1]=1;}
                    else if(cni[1]==1){iShowBMP(inky_x,inky_y,"gd2.bmp");cni[1]=0;}
                }
                else if(inky_key[2]==1){
                    if(cni[2]==0){iShowBMP(inky_x,inky_y,"gd1.bmp");cni[2]=1;}
                    else if(cni[2]==1){iShowBMP(inky_x,inky_y,"gd2.bmp");cni[2]=0;}
                }
                else if(inky_key[3]==1){
                    if(cni[3]==0){iShowBMP(inky_x,inky_y,"gd1.bmp");cni[3]=1;}
                    else if(cni[3]==1){iShowBMP(inky_x,inky_y,"gd2.bmp");cni[3]=0;}
                }
            }




            if(cl_de==0){
                if(clyde_key[0]==1){
                    if(cnc[0]==0){iShowBMP(clyde_x,clyde_y,"gd1.bmp");cnc[0]=1;}
                    else if(cnc[0]==1){iShowBMP(clyde_x,clyde_y,"gd2.bmp");cnc[0]=0;}
                }
                else if(clyde_key[1]==1){
                    if(cnc[1]==0){iShowBMP(clyde_x,clyde_y,"gd1.bmp");cnc[1]=1;}
                    else if(cnc[1]==1){iShowBMP(clyde_x,clyde_y,"gd2.bmp");cnc[1]=0;}
                }
                else if(clyde_key[2]==1){
                    if(cnc[2]==0){iShowBMP(clyde_x,clyde_y,"gd1.bmp");cnc[2]=1;}
                    else if(cnc[2]==1){iShowBMP(clyde_x,clyde_y,"gd2.bmp");cnc[2]=0;}
                }
                else if(clyde_key[3]==1){
                    if(cnc[3]==0){iShowBMP(clyde_x,clyde_y,"gd1.bmp");cnc[3]=1;}
                    else if(cnc[3]==1){iShowBMP(clyde_x,clyde_y,"gd2.bmp");cnc[3]=0;}
                }
            }


        }
        else {
                if(blinky_x%2!=0)blinky_x--;
                if(blinky_y%2!=0)blinky_y--;
                if(pinky_x%2!=0)pinky_x--;
                if(pinky_y%2!=0)pinky_y--;
                if(inky_x%2!=0)inky_x--;
                if(inky_y%2!=0)inky_y--;
                if(clyde_x%2!=0)clyde_x--;
                if(clyde_y%2!=0)clyde_y--;
                if(bl_de==1){
                    blinky_x=blinky_xi;
                    blinky_y=blinky_yi;
                    blinky_key[1]=1;
                    kimb='l';
                    bl_de=0;
                }
                if(pi_de==1){
                    pinky_x=pinky_xi;
                    pinky_y=pinky_yi;
                    pinky_key[2]=1;
                    kimp='u';
                    pi_de=0;
                }
                if(in_de==1){
                    inky_x=inky_xi;
                    inky_y=inky_yi;
                    inky_key[3]=1;
                    kimi='d';
                    in_de=0;
                }
                if(cl_de==1){
                    clyde_x=clyde_xi;
                    clyde_y=clyde_yi;
                    clyde_key[0]=1;
                    kimc='r';
                    cl_de=0;
                }
                ghost_dx=2;
                ghost_dy=2;
                dea_key=0;

        }
    }



    if(dea_key==0){

            spikemove();

            smoo();

            if(bl_de==0)blinky_move();
            else {
                blinky_x=blinky_xi;
                blinky_y=blinky_yi;
            }

            if(bl_de==0)pinky_move();
            else {
                pinky_x=pinky_xi;
                pinky_y=pinky_yi;
            }

            if(bl_de==0)inky_move();
            else {
                inky_x=inky_xi;
                inky_y=inky_yi;
            }

            if(bl_de==0)clyde_move();
            else {
                clyde_x=clyde_xi;
                clyde_y=clyde_yi;
            }

            packman_death();

    }
    else if(dea_key==1){
            if(t>deatt){
                dea_key=0;
                //t=0;
                spike_x=spike_xi;
                spike_y=spike_yi;
                keyr=0;keyl=0;keyu=0;keyd=0;
                for(int i=0;i<4;i++)smooth[i]=0;
                smooth[0]=1;
                blinky_x=blinky_xi;
                blinky_y=blinky_yi;
                pinky_x=pinky_xi;
                pinky_y=pinky_yi;
                inky_x=inky_xi;
                inky_y=inky_yi;
                clyde_x=clyde_xi;
                clyde_y=clyde_yi;
                blinky_key[1]=1;
                pinky_key[2]=1;
                inky_key[3]=1;
                clyde_key[0]=1;

                live--;
            }
    }
    else if(dea_key==2){

            spikemove();

            smoo();

            blinky_move();

            pinky_move();

            inky_move();

            clyde_move();

            frighten_mod();

    }




    //time
    if(t%60<10&&t/60<10)sprintf(ptime,"0%d:0%d",t/60,t%60);
    else if(t%60>10&&t/60<10)sprintf(ptime,"0%d:%d",t/60,t%60);
    else if(t%60>10&&t/60>10)sprintf(ptime,"%d:%d",t/60,t%60);

    iSetColor(9, 243, 249);
    iText(40,600,"TIME",GLUT_BITMAP_TIMES_ROMAN_24);

    iSetColor(41, 250, 192);
    iText(45,570,ptime,GLUT_BITMAP_TIMES_ROMAN_24);
    //

    //score
    iSetColor(116, 190, 249);
    iText(1080,600,"YOUR SCORE",GLUT_BITMAP_TIMES_ROMAN_24);

    sprintf(sc,"%d",score*10);
    iSetColor(0, 252, 94 );
    iText(1130,570,sc,GLUT_BITMAP_TIMES_ROMAN_24);
    //

    //lifes
    iSetColor(116, 190, 249);
    iText(1110,500,"LIFES",GLUT_BITMAP_TIMES_ROMAN_24);

    if(live==3){
        iShowBMP(1110,470,"lifes.bmp");
        iShowBMP(1130,470,"lifes.bmp");
        iShowBMP(1150,470,"lifes.bmp");
    }
    else if(live==2){
        iShowBMP(1110,470,"lifes.bmp");
        iShowBMP(1130,470,"lifes.bmp");
    }
    else if(live==1){
        iShowBMP(1110,470,"lifes.bmp");
    }
    //


}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{

    //place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{


}


/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE_UP,
	GLUT_KEY_PAGE_DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/




void iSpecialKeyboard(unsigned char key)
{
    if(key==GLUT_KEY_RIGHT){
            smooth[0]=1;
            smooth[1]=0;
            smooth[2]=0;
            smooth[3]=0;
            //if(chk('r')){keyr=1;keyl=0;keyu=0;keyd=0;};
    }
    if(key==GLUT_KEY_LEFT){
            smooth[0]=0;
            smooth[1]=1;
            smooth[2]=0;
            smooth[3]=0;
//            if(chk('l')){keyr=0;keyl=1;keyu=0;keyd=0;};
    }
    if(key==GLUT_KEY_UP){
            smooth[0]=0;
            smooth[1]=0;
            smooth[2]=1;
            smooth[3]=0;
//            if(chk('u')){keyr=0;keyl=0;keyu=1;keyd=0;};
    }
    if(key==GLUT_KEY_DOWN){
            smooth[0]=0;
            smooth[1]=0;
            smooth[2]=0;
            smooth[3]=1;
    }

}


void smoo(){
    if(smooth[0]==1)if(chk('r')){keyr=1;keyl=0;keyd=0;keyu=0;}
    if(smooth[1]==1)if(chk('l')){keyr=0;keyl=1;keyd=0;keyu=0;}
    if(smooth[2]==1)if(chk('u')){keyr=0;keyl=0;keyd=0;keyu=1;}
    if(smooth[3]==1)if(chk('d')){keyr=0;keyl=0;keyd=1;keyu=0;}
}




void spikemove()
{
    if(keyr==1)if(spike_x<=1024){
        double r=ceil((600-spike_y)*1.0/30)+ceil((600-spike_y)*1.0/30)-(600-spike_y)*1.0/30,p=((spike_x+32)/32)*1.0-4;
        double d=((spike_x+16)/32)*1.0-4;
        if(maze[(int)r][(int)d]==0){
                maze[(int)r][(int)d]=4;
                score++;
        }
        else if(maze[(int)r][(int)d]==3){
                maze[(int)r][(int)d]=4;
                score+=3;
                dea_key=2;
                deatt2=t+8;
                ghost_dx=1;
                ghost_dy=1;
        }
        if(maze[(int)r][(int)p]!=1){
                smooth[0]=0;
                spike_x+=dx;
        }
        else {keyr=0;st='r';cnt=1;}
        if(spike_x==992&&spike_y==360){
                spike_x=124;
        }
    }
    if(keyl==1)if(spike_x>=128){
        double r=ceil((600-spike_y)*1.0/30)+ceil((600-spike_y)*1.0/30)-(600-spike_y)*1.0/30,p=((spike_x-dx)/32)*1.0-4;
        double d=((spike_x+16)/32)*1.0-4;
        if(maze[(int)r][(int)d]==0){
                maze[(int)r][(int)d]=4;
                score++;
        }
        else if(maze[(int)r][(int)d]==3){
                maze[(int)r][(int)d]=4;
                score+=3;
                dea_key=2;
                deatt2=t+8;
                ghost_dx=1;
                ghost_dy=1;
        }
        if(maze[(int)r][(int)p]!=1) {
            smooth[1]=0;
            spike_x-=dx;
        }
        else {keyl=0;st='l';cnt=1;}
        if(spike_x==128&&spike_y==360){
                spike_x=996;
        }
    }
    if(keyu==1)if(spike_y<=630){
        double r=ceil((600-spike_y-30)*1.0/30)+ceil((600-spike_y-30)*1.0/30)-(600-spike_y-30)*1.0/30,p=(spike_x/32)*1.0-4;
        double d=ceil((600-spike_y-15)*1.0/30)+ceil((600-spike_y-15)*1.0/30)-(600-spike_y-15)*1.0/30;
        if(maze[(int)d][(int)p]==0){
                maze[(int)d][(int)p]=4;
                score++;
        }
        else if(maze[(int)d][(int)p]==3){
                maze[(int)d][(int)p]=4;
                score+=3;
                dea_key=2;
                deatt2=t+8;
                ghost_dx=1;
                ghost_dy=1;
        }
        if(maze[(int)r][(int)p]!=1){
            smooth[2]=0;
            spike_y+=dy;
        }
        else {keyu=0;st='u';cnt=1;}
    }
    if(keyd==1)if(spike_y>=90){
        double r=ceil((600-spike_y+dy)*1.0/30)+ceil((600-spike_y+dy)*1.0/30)-(600-spike_y+dy)*1.0/30,p=(spike_x/32)*1.0-4;
        double d=ceil((600-spike_y-15)*1.0/30)+ceil((600-spike_y-15)*1.0/30)-(600-spike_y-15)*1.0/30;
        if(maze[(int)d][(int)p]==0){
                maze[(int)d][(int)p]=4;
                score++;
        }
        else if(maze[(int)d][(int)p]==3){
                maze[(int)d][(int)p]=4;
                score+=3;
                dea_key=2;
                deatt2=t+8;
                ghost_dx=1;
                ghost_dy=1;
        }
        if(maze[(int)r][(int)p]!=1) {
                smooth[3]=0;
                spike_y-=dy;
        }
        else {keyd=0;st='d';cnt=1;}
    }

}



int chk(char p){
    if(p=='r'){
        double r=ceil((600-spike_y)*1.0/30)+ceil((600-spike_y)*1.0/30)-(600-spike_y)*1.0/30,p=((spike_x+32)*1.0)/32-4;
        if(floor(r)==r){
            if(maze[(int)(r)][(int)p]!=1) return 1;
            else return 0;
        }
        else return 0;
    }
    else if(p=='l'){
        double r=ceil((600-spike_y)*1.0/30)+ceil((600-spike_y)*1.0/30)-(600-spike_y)*1.0/30,p=((spike_x-dx)*1.0)/32-4;
        if(floor(r)==r){
            if(maze[(int)r][(int)p]!=1&&maze[(int)ceil(r)][(int)p]!=1) return 1;
            else return 0;
        }
        else return 0;
    }
    else if(p=='u'){
        double r=ceil((600-spike_y-30)*1.0/30)+ceil((600-spike_y-30)*1.0/30)-(600-spike_y-30)*1.0/30,p=((spike_x/32)*1.0)-4;
        if(floor(p)==p){
            if(maze[(int)r][(int)ceil(p)]!=1&&maze[(int)r][(int)p]!=1) return 1;
            else return 0;
        }
        else return 0;
    }
    else if(p=='d'){
        double r=ceil((600-spike_y+dy)*1.0/30)+ceil((600-spike_y+dy)*1.0/30)-(600-spike_y+dy)*1.0/30,p=((spike_x/32)*1.0)-4;
        if(floor(p)==p){
            if(maze[(int)r][(int)ceil(p)]!=1&&maze[(int)r][(int)p]!=1) return 1;
            else return 0;
        }
        else return 0;
    }
}



void blinky_move(){
    if(blinky_key[0]==1)if(blinky_x<=1024){
        double r=ceil((600-blinky_y)*1.0/30)+ceil((600-blinky_y)*1.0/30)-(600-blinky_y)*1.0/30,p=((blinky_x+32)/32)*1.0-4;
        if(maze[(int)r][(int)p]!=1){
                blinky_x+=ghost_dx;
                double r=ceil((600-blinky_y)*1.0/30)+ceil((600-blinky_y)*1.0/30)-(600-blinky_y)*1.0/30,p=((blinky_x)/32)*1.0-4;
                if(floor(p)==p){
                    kimb='l';
                    blinky_change();
                }
        }
        if(blinky_x==992&&blinky_y==360){
                blinky_x=124;
        }
    }
    if(blinky_key[1]==1)if(blinky_x>=128){
        double r=ceil((600-blinky_y)*1.0/30)+ceil((600-blinky_y)*1.0/30)-(600-blinky_y)*1.0/30,p=((blinky_x-ghost_dx)/32)*1.0-4;
        if(maze[(int)r][(int)p]!=1) {
            blinky_x-=ghost_dx;
            double r=ceil((600-blinky_y)*1.0/30)+ceil((600-blinky_y)*1.0/30)-(600-blinky_y)*1.0/30,p=((blinky_x)/32)*1.0-4;
            if(floor(p)==p){
                    kimb='r';
                    blinky_change();
            }
        }
        if(blinky_x==128&&blinky_y==360){
                blinky_x=996;
        }
    }
    if(blinky_key[2]==1)if(blinky_y<=630){
        double r=ceil((600-blinky_y-30)*1.0/30)+ceil((600-blinky_y-30)*1.0/30)-(600-blinky_y-30)*1.0/30,p=((blinky_x)/32)*1.0-4;
        if(maze[(int)r][(int)p]!=1){
            blinky_y+=ghost_dy;
            double r=ceil((600-blinky_y)*1.0/30)+ceil((600-blinky_y)*1.0/30)-(600-blinky_y)*1.0/30,p=((blinky_x)/32)*1.0-4;
            if(floor(r)==r){
                    kimb='d';
                    blinky_change();
            }
        }
    }
    if(blinky_key[3]==1)if(blinky_y>=90){
        double r=ceil((600-blinky_y+ghost_dy)*1.0/30)+ceil((600-blinky_y+ghost_dy)*1.0/30)-(600-blinky_y+ghost_dy)*1.0/30,p=((blinky_x)/32)*1.0-4;
        if(maze[(int)r][(int)p]!=1) {
            blinky_y-=ghost_dy;
            double r=ceil((600-blinky_y)*1.0/30)+ceil((600-blinky_y)*1.0/30)-(600-blinky_y)*1.0/30,p=((blinky_x)/32)*1.0-4;
            if(floor(r)==r){
                    kimb='u';
                    blinky_change();
            }
        }

    }

}


int blinky_distance(int r, int l, int u, int d){
    double d1=ma,d2=ma,d3=ma,d4=ma,re;
    if(r==1){
        d1=pow(pow(blinky_x+dx-spike_x,2)+pow(blinky_y-spike_y,2),0.5);
    }
    if(l==1){
        d2=pow(pow(blinky_x-dx-spike_x,2)+pow(blinky_y-spike_y,2),0.5);
    }
    if(u==1){
        d3=pow(pow(blinky_x-spike_x,2)+pow(blinky_y+dy-spike_y,2),0.5);
    }
    if(d==1){
        d4=pow(pow(blinky_x+dx-spike_x,2)+pow(blinky_y-dy-spike_y,2),0.5);
    }

    if(d1<d2)re=d1;
    else re=d2;
    if(d3<re)re=d3;
    if(d4<re)re=d4;


    if(re==d1)return 0;
    else if(re==d2)return 1;
    else if(re==d3)return 2;
    else if(re==d4)return 3;


}


void blinky_change(){
        if(check_ghost(blinky_x,blinky_y,'r')&&kimb!='r')blinky_dis[0]=1;
        else blinky_dis[0]=0;
        if(check_ghost(blinky_x,blinky_y,'l')&&kimb!='l')blinky_dis[1]=1;
        else blinky_dis[1]=0;
        if(check_ghost(blinky_x,blinky_y,'u')&&kimb!='u')blinky_dis[2]=1;
        else blinky_dis[2]=0;
        if(check_ghost(blinky_x,blinky_y,'d')&&kimb!='d')blinky_dis[3]=1;
        else blinky_dis[3]=0;

        int bl_ck=blinky_distance(blinky_dis[0],blinky_dis[1],blinky_dis[2],blinky_dis[3]);

        for(int i=0;i<4;i++)blinky_key[i]=0;
        if(bl_ck==0)blinky_key[0]=1;
        else if(bl_ck==1)blinky_key[1]=1;
        else if(bl_ck==2)blinky_key[2]=1;
        else if(bl_ck==3)blinky_key[3]=1;

}


void pinky_move(){
    if(pinky_key[0]==1)if(pinky_x<=1024){
        double r=ceil((600-pinky_y)*1.0/30)+ceil((600-pinky_y)*1.0/30)-(600-pinky_y)*1.0/30,p=((pinky_x+32)/32)*1.0-4;
        if(maze[(int)r][(int)p]!=1){
                pinky_x+=ghost_dx;
                double r=ceil((600-pinky_y)*1.0/30)+ceil((600-pinky_y)*1.0/30)-(600-pinky_y)*1.0/30,p=((pinky_x)/32)*1.0-4;
                if(floor(p)==p){
                    kimp='l';
                    pinky_change();
                }
        }
        if(pinky_x==992&&pinky_y==360){
                pinky_x=124;
        }
    }
    if(pinky_key[1]==1)if(pinky_x>=128){
        double r=ceil((600-pinky_y)*1.0/30)+ceil((600-pinky_y)*1.0/30)-(600-pinky_y)*1.0/30,p=((pinky_x-ghost_dx)/32)*1.0-4;
        if(maze[(int)r][(int)p]!=1) {
            pinky_x-=ghost_dx;
            double r=ceil((600-pinky_y)*1.0/30)+ceil((600-pinky_y)*1.0/30)-(600-pinky_y)*1.0/30,p=((pinky_x)/32)*1.0-4;
            if(floor(p)==p){
                    kimp='r';
                    pinky_change();
            }
        }
        if(pinky_x==128&&pinky_y==360){
                pinky_x=996;
        }
    }
    if(pinky_key[2]==1)if(pinky_y<=630){
        double r=ceil((600-pinky_y-30)*1.0/30)+ceil((600-pinky_y-30)*1.0/30)-(600-pinky_y-30)*1.0/30,p=((pinky_x)/32)*1.0-4;
        if(maze[(int)r][(int)p]!=1){
            pinky_y+=ghost_dy;
            double r=ceil((600-pinky_y)*1.0/30)+ceil((600-pinky_y)*1.0/30)-(600-pinky_y)*1.0/30,p=((pinky_x)/32)*1.0-4;
            if(floor(r)==r){
                    kimp='d';
                    pinky_change();
            }
        }
    }
    if(pinky_key[3]==1)if(pinky_y>=90){
        double r=ceil((600-pinky_y+ghost_dy)*1.0/30)+ceil((600-pinky_y+ghost_dy)*1.0/30)-(600-pinky_y+ghost_dy)*1.0/30,p=((pinky_x)/32)*1.0-4;
        if(maze[(int)r][(int)p]!=1) {
            pinky_y-=ghost_dy;
            double r=ceil((600-pinky_y)*1.0/30)+ceil((600-pinky_y)*1.0/30)-(600-pinky_y)*1.0/30,p=((pinky_x)/32)*1.0-4;
            if(floor(r)==r){
                    kimp='u';
                    pinky_change();
            }
        }

    }

}


int pinky_distance(int r, int l, int u, int d){
    double d1=ma,d2=ma,d3=ma,d4=ma,re;
    if(r==1){
        d1=pow(pow(pinky_x+dx-spike_x,2)+pow(pinky_y-spike_y,2),0.5);
    }
    if(l==1){
        d2=pow(pow(pinky_x-dx-spike_x,2)+pow(pinky_y-spike_y,2),0.5);
    }
    if(u==1){
        d3=pow(pow(pinky_x-spike_x,2)+pow(pinky_y+dy-spike_y,2),0.5);
    }
    if(d==1){
        d4=pow(pow(pinky_x+dx-spike_x,2)+pow(pinky_y-dy-spike_y,2),0.5);
    }

    if(d1<d2)re=d1;
    else re=d2;
    if(d3<re)re=d3;
    if(d4<re)re=d4;

    if(re==d1)return 0;
    else if(re==d2)return 1;
    else if(re==d3)return 2;
    else if(re==d4)return 3;


}


void pinky_change(){
        if(check_ghost(pinky_x,pinky_y,'r')&&kimp!='r')pinky_dis[0]=1;
        else pinky_dis[0]=0;
        if(check_ghost(pinky_x,pinky_y,'l')&&kimp!='l')pinky_dis[1]=1;
        else pinky_dis[1]=0;
        if(check_ghost(pinky_x,pinky_y,'u')&&kimp!='u')pinky_dis[2]=1;
        else pinky_dis[2]=0;
        if(check_ghost(pinky_x,pinky_y,'d')&&kimp!='d')pinky_dis[3]=1;
        else pinky_dis[3]=0;

        int pl_ck=pinky_distance(pinky_dis[0],pinky_dis[1],pinky_dis[2],pinky_dis[3]);

        for(int i=0;i<4;i++)pinky_key[i]=0;
        if(pl_ck==0)pinky_key[0]=1;
        else if(pl_ck==1)pinky_key[1]=1;
        else if(pl_ck==2)pinky_key[2]=1;
        else if(pl_ck==3)pinky_key[3]=1;

}




void inky_move(){
    if(inky_key[0]==1)if(inky_x<=1024){
        double r=ceil((600-inky_y)*1.0/30)+ceil((600-inky_y)*1.0/30)-(600-inky_y)*1.0/30,p=((inky_x+32)/32)*1.0-4;
        if(maze[(int)r][(int)p]!=1){
                inky_x+=ghost_dx;
                double r=ceil((600-inky_y)*1.0/30)+ceil((600-inky_y)*1.0/30)-(600-inky_y)*1.0/30,p=((inky_x)/32)*1.0-4;
                if(floor(p)==p){
                    kimi='l';
                    inky_change();
                }
        }
        if(inky_x==992&&inky_y==360){
                inky_x=124;
        }
    }
    if(inky_key[1]==1)if(inky_x>=128){
        double r=ceil((600-inky_y)*1.0/30)+ceil((600-inky_y)*1.0/30)-(600-inky_y)*1.0/30,p=((inky_x-ghost_dx)/32)*1.0-4;
        if(maze[(int)r][(int)p]!=1) {
            inky_x-=ghost_dx;
            double r=ceil((600-inky_y)*1.0/30)+ceil((600-inky_y)*1.0/30)-(600-inky_y)*1.0/30,p=((inky_x)/32)*1.0-4;
            if(floor(p)==p){
                    kimi='r';
                    inky_change();
            }
        }
        if(inky_x==128&&inky_y==360){
                inky_x=996;
        }
    }
    if(inky_key[2]==1)if(inky_y<=630){
        double r=ceil((600-inky_y-30)*1.0/30)+ceil((600-inky_y-30)*1.0/30)-(600-inky_y-30)*1.0/30,p=((inky_x)/32)*1.0-4;
        if(maze[(int)r][(int)p]!=1){
            inky_y+=ghost_dy;
            double r=ceil((600-inky_y)*1.0/30)+ceil((600-inky_y)*1.0/30)-(600-inky_y)*1.0/30,p=((inky_x)/32)*1.0-4;
            if(floor(r)==r){
                    kimi='d';
                    inky_change();
            }
        }
    }
    if(inky_key[3]==1)if(inky_y>=90){
        double r=ceil((600-inky_y+ghost_dy)*1.0/30)+ceil((600-inky_y+ghost_dy)*1.0/30)-(600-inky_y+ghost_dy)*1.0/30,p=((inky_x)/32)*1.0-4;
        if(maze[(int)r][(int)p]!=1) {
            inky_y-=ghost_dy;
            double r=ceil((600-inky_y)*1.0/30)+ceil((600-inky_y)*1.0/30)-(600-inky_y)*1.0/30,p=((inky_x)/32)*1.0-4;
            if(floor(r)==r){
                    kimi='u';
                    inky_change();
            }
        }

    }

}


int inky_distance(int r, int l, int u, int d){
    double d1=ma,d2=ma,d3=ma,d4=ma,re;
    if(r==1){
        d1=pow(pow(inky_x+dx-spike_x,2)+pow(inky_y-spike_y,2),0.5);
    }
    if(l==1){
        d2=pow(pow(inky_x-dx-spike_x,2)+pow(inky_y-spike_y,2),0.5);
    }
    if(u==1){
        d3=pow(pow(inky_x-spike_x,2)+pow(inky_y+dy-spike_y,2),0.5);
    }
    if(d==1){
        d4=pow(pow(inky_x+dx-spike_x,2)+pow(inky_y-dy-spike_y,2),0.5);
    }

    if(d1<d2)re=d1;
    else re=d2;
    if(d3<re)re=d3;
    if(d4<re)re=d4;


    if(re==d1)return 0;
    else if(re==d2)return 1;
    else if(re==d3)return 2;
    else if(re==d4)return 3;


}


void inky_change(){
        if(check_ghost(inky_x,inky_y,'r')&&kimi!='r')inky_dis[0]=1;
        else inky_dis[0]=0;
        if(check_ghost(inky_x,inky_y,'l')&&kimi!='l')inky_dis[1]=1;
        else inky_dis[1]=0;
        if(check_ghost(inky_x,inky_y,'u')&&kimi!='u')inky_dis[2]=1;
        else inky_dis[2]=0;
        if(check_ghost(inky_x,inky_y,'d')&&kimi!='d')inky_dis[3]=1;
        else inky_dis[3]=0;

        int bl_ck=inky_distance(inky_dis[0],inky_dis[1],inky_dis[2],inky_dis[3]);

        for(int i=0;i<4;i++)inky_key[i]=0;
        if(bl_ck==0)inky_key[0]=1;
        else if(bl_ck==1)inky_key[1]=1;
        else if(bl_ck==2)inky_key[2]=1;
        else if(bl_ck==3)inky_key[3]=1;

}





void clyde_move(){
    if(clyde_key[0]==1)if(clyde_x<=1024){
        double r=ceil((600-clyde_y)*1.0/30)+ceil((600-clyde_y)*1.0/30)-(600-clyde_y)*1.0/30,p=((clyde_x+32)/32)*1.0-4;
        if(maze[(int)r][(int)p]!=1){
                clyde_x+=ghost_dx;
                double r=ceil((600-clyde_y)*1.0/30)+ceil((600-clyde_y)*1.0/30)-(600-clyde_y)*1.0/30,p=((clyde_x)/32)*1.0-4;
                if(floor(p)==p){
                    kimc='l';
                    clyde_change();
                }
        }
        if(clyde_x==992&&clyde_y==360){
                clyde_x=124;
        }
    }
    if(clyde_key[1]==1)if(clyde_x>=128){
        double r=ceil((600-clyde_y)*1.0/30)+ceil((600-clyde_y)*1.0/30)-(600-clyde_y)*1.0/30,p=((clyde_x-ghost_dx)/32)*1.0-4;
        if(maze[(int)r][(int)p]!=1) {
            clyde_x-=ghost_dx;
            double r=ceil((600-clyde_y)*1.0/30)+ceil((600-clyde_y)*1.0/30)-(600-clyde_y)*1.0/30,p=((clyde_x)/32)*1.0-4;
            if(floor(p)==p){
                    kimc='r';
                    clyde_change();
            }
        }
        if(clyde_x==128&&clyde_y==360){
                clyde_x=996;
        }
    }
    if(clyde_key[2]==1)if(clyde_y<=630){
        double r=ceil((600-clyde_y-30)*1.0/30)+ceil((600-clyde_y-30)*1.0/30)-(600-clyde_y-30)*1.0/30,p=((clyde_x)/32)*1.0-4;
        if(maze[(int)r][(int)p]!=1){
            clyde_y+=ghost_dy;
            double r=ceil((600-clyde_y)*1.0/30)+ceil((600-clyde_y)*1.0/30)-(600-clyde_y)*1.0/30,p=((clyde_x)/32)*1.0-4;
            if(floor(r)==r){
                    kimc='d';
                    clyde_change();
            }
        }
    }
    if(clyde_key[3]==1)if(clyde_y>=90){
        double r=ceil((600-clyde_y+ghost_dy)*1.0/30)+ceil((600-clyde_y+ghost_dy)*1.0/30)-(600-clyde_y+ghost_dy)*1.0/30,p=((clyde_x)/32)*1.0-4;
        if(maze[(int)r][(int)p]!=1) {
            clyde_y-=ghost_dy;
            double r=ceil((600-clyde_y)*1.0/30)+ceil((600-clyde_y)*1.0/30)-(600-clyde_y)*1.0/30,p=((clyde_x)/32)*1.0-4;
            if(floor(r)==r){
                    kimc='u';
                    clyde_change();
            }
        }

    }

}


int clyde_distance(int r, int l, int u, int d){
    double d1=ma,d2=ma,d3=ma,d4=ma,re;
    if(r==1){
        d1=pow(pow(clyde_x+dx-spike_x,2)+pow(clyde_y-spike_y,2),0.5);
    }
    if(l==1){
        d2=pow(pow(clyde_x-dx-spike_x,2)+pow(clyde_y-spike_y,2),0.5);
    }
    if(u==1){
        d3=pow(pow(clyde_x-spike_x,2)+pow(clyde_y+dy-spike_y,2),0.5);
    }
    if(d==1){
        d4=pow(pow(clyde_x+dx-spike_x,2)+pow(clyde_y-dy-spike_y,2),0.5);
    }

    if(d1<d2)re=d1;
    else re=d2;
    if(d3<re)re=d3;
    if(d4<re)re=d4;


    if(re==d1)return 0;
    else if(re==d2)return 1;
    else if(re==d3)return 2;
    else if(re==d4)return 3;


}


void clyde_change(){
        if(check_ghost(clyde_x,clyde_y,'r')&&kimc!='r')clyde_dis[0]=1;
        else clyde_dis[0]=0;
        if(check_ghost(clyde_x,clyde_y,'l')&&kimc!='l')clyde_dis[1]=1;
        else clyde_dis[1]=0;
        if(check_ghost(clyde_x,clyde_y,'u')&&kimc!='u')clyde_dis[2]=1;
        else clyde_dis[2]=0;
        if(check_ghost(clyde_x,clyde_y,'d')&&kimc!='d')clyde_dis[3]=1;
        else clyde_dis[3]=0;

        int bl_ck=clyde_distance(clyde_dis[0],clyde_dis[1],clyde_dis[2],clyde_dis[3]);

        for(int i=0;i<4;i++)clyde_key[i]=0;
        if(bl_ck==0)clyde_key[0]=1;
        else if(bl_ck==1)clyde_key[1]=1;
        else if(bl_ck==2)clyde_key[2]=1;
        else if(bl_ck==3)clyde_key[3]=1;

}






int check_ghost(double x, double y, char p){
    if(p=='r'){
        double r=ceil((600-y)*1.0/30)+ceil((600-y)*1.0/30)-(600-y)*1.0/30,p=((x+32)/32)*1.0-4;
        if(floor(r)==r){
            if(maze[(int)r][(int)p]!=1) return 1;
            else return 0;
        }
        else return 0;
    }
    else if(p=='l'){
        double r=ceil((600-y)*1.0/30)+ceil((600-y)*1.0/30)-(600-y)*1.0/30,p=((x-ghost_dx)/32)*1.0-4;
        if(floor(r)==r){
            if(maze[(int)r][(int)p]!=1) return 1;
            else return 0;
        }
        else return 0;
    }
    else if(p=='u'){
        double r=ceil((600-y-30)*1.0/30)+ceil((600-y-30)*1.0/30)-(600-y-30)*1.0/30,p=((x)/32)*1.0-4;
        if(floor(p)==p){
            if(maze[(int)r][(int)p]!=1) return 1;
            else return 0;
        }
        else return 0;
    }
    else if(p=='d'){
        double r=ceil((600-y+ghost_dy)*1.0/30)+ceil((600-y+ghost_dy)*1.0/30)-(600-y+ghost_dy)*1.0/30,p=((x)/32)*1.0-4;
        if(floor(p)==p){
            if(maze[(int)r][(int)p]!=1) return 1;
            else return 0;
        }
        else return 0;
    }
}




void packman_death(){
    if((abs(spike_x-blinky_x)<16&&abs(spike_y-blinky_y)<15)||(abs(spike_x-pinky_x)<16&&abs(spike_y-pinky_y)<15)||(abs(spike_x-inky_x)<16&&abs(spike_y-inky_y)<15)||(abs(spike_x-clyde_x)<16&&abs(spike_y-clyde_y)<15)){
        dea_key=1;
        deatt=t+1;
    }
}


void frighten_mod(){
    if((abs(spike_x-blinky_x)<16&&abs(spike_y-blinky_y)<15)&&bl_de==0){
        score+=10;
        bl_de=1;
    }
    if((abs(spike_x-pinky_x)<16&&abs(spike_y-pinky_y)<15)&&pi_de==0){
        score+=10;
        pi_de=1;
    }
    if((abs(spike_x-inky_x)<16&&abs(spike_y-inky_y)<15)&&in_de==0){
        score+=10;
        in_de=1;
    }
    if((abs(spike_x-clyde_x)<16&&abs(spike_y-clyde_y)<15)&&cl_de==0){
        score+=10;
        cl_de=1;
    }
}



void clo(){
    t++;
}


void take_in(){

}

int main()
{
    //place your own initialization codes here.


    dx=4;
    dy=3;
    ghost_dx=2;
    ghost_dy=2;
    smooth[0]=1;
    blinky_key[1]=1;
    pinky_key[2]=1;
    inky_key[3]=1;
    clyde_key[0]=1;

    take_in();

    iSetTimer(1000,clo);

    iInitialize(1280, 720, "PACKED<->MANN");
    return 0;


}

