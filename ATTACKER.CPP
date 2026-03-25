#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<fstream.h>
#include<string.h>
#include<iomanip.h>


void format(char x='*')
{
 cout<<"\n";
 for(int i=1;i<=80;i++)
  cout<<x;
 cout<<"\n";
}
class Player
{
char name[15];
float score1,score2;


public:

Player()
{
 strcpy(name,"\0");
 score1=0.0;
 score2=0.0;
}

void player_input(float x1,float x2)
{
 clrscr();
 format();
 cout<<"\n                        ----------- PLAYER DETAILS ----------\n";
 format();
 cout<<"\n\t\tEnter your name :";
 gets(name);
 score1=x1;
 score2=x2;
 cout<<"\n\t\tAttacker Score  :"<<score1<<endl;
 cout<<"\n\t\tDefender Score  :"<<score2<<endl;
 format();
}

void player_display()
{
  cout<<setw(30)<<name<<setw(20)<<score1<<setw(20)<<score2;
  cout<<"\n";
}
};

/*********************************************************************
			  STORE THE SCORE
**********************************************************************/

void storescore(Player P1)
{
ofstream f1;
if (f1==0)
goto e;
f1.open("score.txt",ios::app|ios::binary);
f1.write((char*)&P1,sizeof(P1));
cout<<"\n\tRecord added";
f1.close();
e:
}

void dispscore()
{
ifstream f1;
Player buff;
f1.open("score.txt",ios::in|ios::binary);
if (!f1)
{
clrscr();
cout<<"\n\n*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#";
cout<<"\n\n            SCORE RECORDS ARE NOT AVAILABLE   ";
cout<<"\n\n";
cout<<"*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#";
getch();
goto z;
}
f1.seekg(0);
clrscr();
cout<<"\n\n*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#";
cout<<"\n\n";
cout<<setw(30)<<"NAME OF THE PLAYER"<<setw(20)<<"ATTACKER-SCORE"<<setw(20)<<"DEFENDER-SCORE";
cout<<"\n\n";
while (f1.read((char*)&buff,sizeof(buff)))
{
buff.player_display();
getch();
}
f1.close();
cout<<"\n\n";
cout<<"*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#";
z:
}



      char ch;
       union REGS in,out;    //asky about putimage()
			     // change color of text
       int callmouse()
       {
	      in.x.ax=1;
	      int86(51,&in,&out);
	      return 1;
       }
       void mouseposi(int &xpos,int &ypos,int &click)
       {
	      in.x.ax=3;
	      int86(51,&in,&out);
	      click=out.x.bx;
	      xpos=out.x.cx;
	      ypos=out.x.dx;
	}
       int mousehide()
       {
	      in.x.ax=2;
	      int86(51,&in,&out);
	      return 1;
       }
       void setposi(int &xpos,int &ypos)
       {
	     in.x.ax=4;
	     in.x.cx=xpos;
	     in.x.dx=ypos;
	     int86(51,&in,&out);
	}

	void extrema(float zx,float zy,int &res)
  {res=0;
   if(zx>610)
   {res+=20;}
   if(zx<6)
   {res+=10;}
   if(zy>445)
   {res+=2;}
   if(zy<285)
   {res+=1;}

  }
      void exd(float zx,float zy,int &res)
  {res=0;
   if(zx>610)
   {res+=20;}
   if(zx<6)
   {res+=10;}
   if(zy>170)
   {res+=2;}
   if(zy<10)
   {res+=1;}

  }



	void game()
       {     int g=DETECT,m;
	     initgraph(&g,&m," ");

	     int gno=1;
	     i1:
	     setbkcolor(5);

	     printf("                        * * * * * WELCOME TO * * * * *");

	     settextstyle(0,0,5);
	     outtextxy(120,150,"MULTIPLAYER");

	     settextstyle(0,0,5);
	     outtextxy(170,250,"SHOOTOUT");
	     getch();

	     int res=0,cl,a,b,x,y;
	     int life=20,count=-12;
	     float dx=305,dy=95;
	     cleardevice();


	     a=100;
	     b=400;
	     setposi(a,b);
	     callmouse();
	     int rx=305,ry=377;
	     printf("\n\tplayer%d",gno);
	     printf(" attacks Press any key to start");
	     do
	     {      w1:printf("\n\n\n\n\n\n\nLIFE OF DEFENDER: %d",life);
		    mouseposi(x,y,cl);
		    gotoxy(10,9);
		   // printf("\n\tMouse Position is: %d,%d",x,y);
		   // printf("\n\tClick: %d",cl);

		   ch='b';         //for not repeating moves

		  if(kbhit())
		  {
		  ch=getch();
		  }
		  extrema(rx,ry,res);

		   if(ch=='w' && res%10!=1)    //  A
		  ry-=10;
		   if(kbhit())
		  {
		  ch=getch();
		  }
		  if(rx<615)
		  if(ch=='d')   //  >
		 { rx+=10; }
		   if(kbhit())
		  {
		  ch=getch();
		  }
		  extrema(rx,ry,res);
		   if(ch=='s' && res%10!=2)   //  V
		  ry+=10;
		   if(kbhit())
		  {
		  ch=getch();
		  }
		  extrema(rx,ry,res);
		   if(ch=='a' && res/10!=1)   //  <
		  rx-=10;
		   if(kbhit())
		  {
		  ch=getch();
		  }		    //***cross movment below return 0 *****

		  exd(dx,dy,res);

		   if(ch=='i' && res%10!=1)    //  A
		  dy-=10;
		   if(kbhit())
		  {
		  ch=getch();
		  }
		  if(dx<615)
		  if(ch=='l')                 //  >
		 { dx+=10; }
		   if(kbhit())
		  {
		  ch=getch();
		  }
		  exd(dx,dy,res);
		   if(ch=='k' && res%10!=2)   //  V
		  dy+=10;
		   if(kbhit())
		  {
		  ch=getch();
		  }
		  exd(dx,dy,res);
		   if(ch=='j' && res/10!=1)   //  <
		  dx-=10;

		   setbkcolor(9);
		   settextstyle(0,0,3);
		   outtextxy(rx,ry,"\14");
		   outtextxy(dx,dy,"\14");
		   rectangle(0,479,639,280);
		   rectangle(0,0,639,200);

		   if(ch!='b')
		  { settextstyle(0,0,3);
		   outtextxy(rx,ry,"\14");
		   outtextxy(dx,dy,"\14");
		   cleardevice();
		   setbkcolor(9);
		   rectangle(0,479,639,280);
		     rectangle(0,0,639,200);
		  }
		   if(count==7)
		   {cleardevice();
		  setbkcolor(0);
		  settextstyle(0,0,4);
		  outtextxy(150,100,"GAME OVER");
		  if(life<=8)
		  {outtextxy(150,200,"Attacker Won");}
		  else
		  {outtextxy(150,200,"Defender Won");}

		  outtextxy(150,250,"SCORE:");
		  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n                    Attacker                         %d",(25-life)*237);
		  printf("\n\n                    Defender                        %d",(life)*237);
		  getch();
		  delay(2000);
		  goto q1;}

		   if(cl==1 && count<7)
		    { float RX,RY;
		      RX=rx;
		      RY=ry;

		    if(x>rx)
		      {count++;


		      for(double i=RX;i<800;i++)
			{float X,Y,z,s,n;
			X=x;
			Y=y;
			n=1;
			s= (Y-RY)/(X-RX);
			if((pow(dx-fabs(i),2)+pow(dy-fabs(RY+(i-RX)*s),2))<625)
			 {life-=1;goto w1;}
			ch='b';                                    //sr
			 if(kbhit())
		  {
		  ch=getch();
		  }
		  extrema(rx,ry,res);

		   if(ch=='w' && res%10!=1)    //  A
		  ry-=10;
		   if(kbhit())
		  {
		  ch=getch();
		  }
		  extrema(rx,ry,res);
		   if(ch=='d' && res/10!=2)   //  >
		  rx+=10;
		   if(kbhit())
		  {
		  ch=getch();
		  }
		  extrema(rx,ry,res);
		   if(ch=='s' && res%10!=2)   //  V
		  ry+=10;
		   if(kbhit())
		  {
		  ch=getch();
		  }
		  extrema(rx,ry,res);
		   if(ch=='a' && res/10!=1)   //  <
		  rx-=10;
		   if(kbhit())
		  {
		  ch=getch();
		  }

		   exd(dx,dy,res);

		   if(ch=='i' && res%10!=1)    //  A
		  dy-=10;
		   if(kbhit())
		  {
		  ch=getch();
		  }
		  if(dx<615)
		  if(ch=='l')                 //  >
		 { dx+=10; }
		   if(kbhit())
		  {
		  ch=getch();
		  }
		  exd(dx,dy,res);
		   if(ch=='k' && res%10!=2)   //  V
		  dy+=10;
		   if(kbhit())
		  {
		  ch=getch();
		  }
		  exd(dx,dy,res);
		   if(ch=='j' && res/10!=1)   //  <
		  dx-=10;

			setbkcolor(9);
			rectangle(0,479,639,280);
			rectangle(0,0,639,200);

			X=x;
			Y=y;
			n=0;
			s= (Y-RY)/(X-RX);

			if(RY+(i-RX)*s<0)
			if(fabs(s)>1)
			{n=2;}
			if(RY+(i-RX)*s<0)
			{goto r1;}
			settextstyle(0,0,3);
			outtextxy(rx,ry,"\14");
			outtextxy(dx,dy,"\14");
			circle(i,ry+(i-rx)*s,5);
			circle(dx,dy,25);
			cleardevice();
			settextstyle(0,0,3);
			outtextxy(rx,ry,"\14");
			outtextxy(dx,dy,"\14");
			rectangle(0,479,639,280);
			  rectangle(0,0,639,200);
			delay(n);
			circle(i,RY+(i-RX)*s,5);
			delay(n);}}

			if(x<rx)
		      {count++;
		     //int m=0;

		      for(float i=RX;i>m;i--)
   /* LIFE-- */	        {float X,Y,z,s,n;
			X=x;
			Y=y;
			n=0;
			s= (Y-RY)/(X-RX);
			if(pow((dx-i),2)+pow(dy-(RY+(i-RX)*s),2)<625)
			{life-=1;goto w1;}
			ch='b';                                     //sl
			 if(kbhit())
		  {
		  ch=getch();
		  }
		  extrema(rx,ry,res);

		   if(ch=='w' && res%10!=1)    //  A
		  ry-=10;
		   if(kbhit())
		  {
		  ch=getch();
		  }
		  extrema(rx,ry,res);
		   if(ch=='d' && res/10!=2)   //  >
		  rx+=10;
		   if(kbhit())
		  {
		  ch=getch();
		  }
		  extrema(rx,ry,res);
		   if(ch=='s' && res%10!=2)   //  V
		  ry+=10;
		   if(kbhit())
		  {
		  ch=getch();
		  }
		  extrema(rx,ry,res);
		   if(ch=='a' && res/10!=1)   //  <
		  rx-=10;
		   if(kbhit())
		  {
		  ch=getch();
		  }

		   exd(dx,dy,res);

		   if(ch=='i' && res%10!=1)    //  A
		  dy-=10;
		   if(kbhit())
		  {
		  ch=getch();
		  }
		  if(dx<615)
		  if(ch=='l')                 //  >
		 { dx+=10; }
		   if(kbhit())
		  {
		  ch=getch();
		  }
		  exd(dx,dy,res);
		   if(ch=='k' && res%10!=2)   //  V
		  dy+=10;
		   if(kbhit())
		  {
		  ch=getch();
		  }
		  exd(dx,dy,res);
		   if(ch=='j' && res/10!=1)   //  <
		   dx-=10;

			setbkcolor(9);
			rectangle(0,479,639,280);
			rectangle(0,0,639,200);

			X=x;
			Y=y;
			n=0;
			s= (Y-RY)/(X-RX);

			if(RY+(i-RX)*s<0){goto r1;}
			if(fabs(s)>1)
			{
			n=2;}
			if(RY+(i-RX)*s<0)
			{goto r1;}
			settextstyle(0,0,3);
			outtextxy(rx,ry,"\14");
			outtextxy(dx,dy,"\14");
			circle(i,RY+(i-RX)*s,5);
			circle(dx,dy,25);

			cleardevice();
			settextstyle(0,0,3);
			outtextxy(rx,ry,"\14");
			outtextxy(dx,dy,"\14");
			rectangle(0,479,639,280);
			rectangle(0,0,639,200);
			delay(n);
			circle(i,RY+(i-RX)*s,5);
			delay(n);}}
		    }
		    r1:if (ch=='p')
		    {goto l1;}



	     }while(1);

	     l1:q1:
	     float sc_att=(25-life)*237;
	     float sc_def=life*237;
	     cleardevice();
	     closegraph();
	     Player p1;
	     p1.player_input(sc_att,sc_def);
	     storescore(p1);
	     return ;

     }

void instrct()
{
clrscr();
format('#');
cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tINSTRUCTIONS";
format();
cout<<"\nWelcome to the Instructions page of MULTIPLAYER SHOOTOUT. The game requires TWO ";
cout<<"PLAYERS:The Attacker and The Defender. The Attacker, as the name suggests, would";
cout<<"be given few bullets to shoot at The Defender. While The Defender, as the name";
cout<<"  suggests, would have to defend the bullets of The Attacker. The tentative score would be displayed at the end of the game. The game ends when either The";
cout<<"        Attacker loses all of his given bullets or when The Defender loses all of his";
cout<<"   given lives. The Attacker can move with the AWSD keys and shoot with the left ";
cout<<"  mouse click. The Defender can move with the JIKL keys to defend.";
format();
cout<<"\n\t\t\t\tENJOY PLAYING";
format('#');
}


void menu()
{
 l1:
 int ch;
 clrscr();
 format();
 cout<<"\n\n                             MULTIPLAYER SHOOT OUT\n";
 format();
 cout<<"\nTHE MENU\n";
 cout<<"\n\t1. PLAY GAME\n\t2. INSTRUCTIONS\n\t3. SCORE BOARD\n\t4. EXIT";
 format('#');
 cout<<"\nEnter your choice:";
 cin>>ch;
 switch(ch)
{
  case 1:
	 game();
	 getch();
	 break;
  case 2:

	 instrct();
	 break;
  case 3:
	 cout<<"\nDisplayscore";
	 dispscore();
	 break;
  case 4:
	 format('>');
	 cout<<"\n                                  \4\4\4THANK YOU\4\4\4\n";
	 getch();
	 return;
  default:
	 cout<<"\nWrong choice pressed";
}
cout<<"\nPress any key....";
getch();
goto l1;
}

void main()
{
menu();
}

