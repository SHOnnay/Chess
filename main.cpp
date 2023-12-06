#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <ctype.h>
#include <dos.h>
using namespace std;
int board[8][8],turn=0,count1=0,count2=0,which=2;
int gameover();
DWORD width=GetSystemMetrics(SM_CXSCREEN);
DWORD height=GetSystemMetrics(SM_CYSCREEN);
void printboard();
void wrongStart();
void initialize();
void cleartext();
void check();
char gethor();

int pawn(int x,int y,int x1,int y1);
int horse(int x,int y,int x1,int y1);
int rook(int x,int y,int x1,int y1);
int bishop(int x,int y,int x1,int y1);
int queen(int x,int y,int x1,int y1);
int king(int x,int y,int x1,int y1);
void gotoxy(int i,int j);
void gotoxy(int i,int j){

}
int ifcheck(){
    int i,j,k,l,checks;
    for(i=0;i<=7;i++){
        for(j=0;j<=7;j++){
            if (board[i][j]==-5){
                k=i;l=j;
                break;
            }
        }

    }
    i=0;j=0;
    for(i=0;i<k;i++){
        if(board[i][l]>0){
                int u;
                for(u=0;u<=i;u++){
                    if(board[i][l]==4)if(board[u][l]==0||board[u][l]<0){checks=0;
                    printf("no check");
                    }
                }

        }
    }

}
char gethor(){
    POINT cursor;

        GetCursorPos(&cursor);

        if(cursor.x>250&&cursor.x<295)return 'A';
        else if(cursor.x>295&&cursor.x<340)return 'B';
        else if(cursor.x>340&&cursor.x<385)return 'C';
        else if(cursor.x>385&&cursor.x<430)return 'D';
        else if(cursor.x>430&&cursor.x<475)return 'E';
        else if(cursor.x>475&&cursor.x<520)return 'F';
        else if(cursor.x>520&&cursor.x<565)return 'G';
        else if(cursor.x>565 && cursor.x<610)return 'H';


}

char getver(){
    POINT cursor;
    GetCursorPos(&cursor);
            if(cursor.y>115&&cursor.y<160)return '1';
           if(cursor.y>160&&cursor.y<195)return '2';
           if(cursor.y>195&&cursor.y<240)return '3';
           if(cursor.y>240&&cursor.y<285)return '4';
           if(cursor.y>285&&cursor.y<330)return '5';
           if(cursor.y>330&&cursor.y<375)return '6';
           if(cursor.y>375&&cursor.y<420)return '7';
           if(cursor.y>420&&cursor.y<465)return '8';
           }
int main()
{

		int gdriver = DETECT;
	int gmode;
	initgraph(&gdriver,&gmode,"e:\\borlandc\\bgi");
    initwindow(width,height,"Chess");
    POINT cursor;


	outtextxy(500,500,"\nPress any key to play ");
	getch();
	cleardevice();
    cleartext();
	initialize();

	int x=-1,y=-1,x1=-1,y1=-1;
	setcolor(GREEN);
	outtextxy(10,400,"Player 1");

	//for(;;){GetCursorPos(&cursor);printf("%d,%d\n",cursor.x,cursor.y);}
	for(;;)
	{   if(ismouseclick(WM_LBUTTONDOWN)){
            delay(400);
	        int game;
            game=gameover();
		    if(game==0)
		   {
			 break;
		   }

		//printf("%d",toupper(ch));
		if(x==-1){
			char ch=gethor();
			//printf("\n%c",gethor());
			if(ch>=65 && ch<=72){

				x=ch-65;
				printf("%c",ch);
				}

        if(y==-1)
		{
		char ch1=getver();
		//printf("%c",ch1);
		which=0;
				printf("\n%c",ch1);
			if(ch1>='1' && ch1<='8')
			{

				y=ch1-'1';

				if(board[y][x]==0){
					wrongStart();
					x=-1;
					y=-1;
					}
				else
				{
					if(turn==0)
					{
						if(board[y][x]<0)

						{
							wrongStart();
							x=-1;
							y=-1;
						}
					}
					else if(turn!=0)
					{
						if(board[y][x]>0)
						{
							wrongStart();
							x=-1;
							y=-1;
						}
					}
				}
			}
			clearmouseclick(WM_LBUTTONDOWN);
			if(x!=-1 && y!=-1)
				outtextxy(1,300,"Final move");
		}
    }
		else if(x1==-1)
		{
            char ch=gethor();
            printf("%c",ch);
				which=1;
			ch=toupper(ch);
			if(ch>=65 && ch<=72)
			{

				x1=ch-65;
			}
		 if(y1==-1)
		{
			char ch1=getver();
			printf("%c",ch1);
		which=0;
		if(ch1>='1' && ch1<='8')
			{

				y1=ch1-'1';
			}
		int b=0,killed=0;

//pawn

     if(abs(board[y][x])>=9 && abs(board[y][x])<=16){
				b = pawn(x,y,x1,y1);
            }

		      else if(abs(board[y][x])==2 ||abs(board[y][x])==7){
				b = horse(x,y,x1,y1);
				}

		      else if(abs(board[y][x])==4){
				b = queen(x,y,x1,y1);
				}
		      else if(abs(board[y][x])==5){
				b = king(x,y,x1,y1);
			 }

		      else if(abs(board[y][x])==1 ||abs(board[y][x])==8){
				b = rook(x,y,x1,y1);
				}

		      else if(abs(board[y][x])==3 ||
abs(board[y][x])==6){
				b = bishop(x,y,x1,y1);
				}


			 if(b==1)
			{
				if(turn==0)
				{
					if(board[y1][x1]<0)
					{
						board[y1][x1]=board[y][x];
						board[y][x] = 0;
						killed=1;
						       }

                            }
				if(turn!=0)
				{
					if(board[y1][x1]>0)
					{
						board[y1][x1]=board[y][x];
						board[y][x] = 0;
						killed=1;int i,j;

                        }

                        }
				if(board[y1][x1]==0)
				{
					int temp=0;
					temp=board[y][x];
					board[y][x]=board[y1][x1];
					board[y1][x1]=temp;
					killed=1;
					//printf("\n%d,%d\n",board[y1][x1],board[y][x]);
				}


			}
			ifcheck();
			if(x1!=-1&&y1!=-1)printboard();
			clearmouseclick(WM_LBUTTONDOWN);
			setfillstyle(SOLID_FILL,BLACK);
			bar(1,300,100,330);
			bar(20,320,110,370);
			x=-1;
			y=-1;
			x1=-1;
			y1=-1;

			check();
		      setcolor(0);
		      //outtextxy(30,340,"Check");
			if(killed==0){
				wrongStart();
				continue;
				}
			cleartext();
			setcolor(GREEN);
			outtextxy(10,400,"Player 1");
			if(turn==0){
				check();
				turn=1;
				setcolor(RED);
				outtextxy(10,400,"Player 2");
				}
			else{
				check();
				turn=0;
				setcolor(GREEN);
				outtextxy(10,400,"Player 1");
				}

			}
		}

			}
		}
}
void camal(int c1,int c2,int c)

{
	if(c==1)setcolor(GREEN);
	else if(c==2)setcolor(RED);
	line(c1+10,c2+35,c1+30,c2+35);
	line(c1+10,c2+35,c1+20,c2+5);
	line(c1+30,c2+35,c1+20,c2+5);
	line(c1+15,c2+30,c1+25,c2+30);
	line(c1+15,c2+30,c1+10,c2+35);
	line(c1+25,c2+30,c1+30,c2+35);
	for(int i=c1+15;i<=c1+25;i++)
	{
		line(c1+20,c2+5,i,c2+30);
	}
}
void queen(int k1,int k2,int c)

{
    if(c==1)setcolor(GREEN);
	else if(c==2)setcolor(RED);
	line(k1+5,k2+35,k1+35,k2+35);
	line(k1+5,k2+35,k1+35,k2+10);
	line(k1+35,k2+35,k1+5,k2+10);
	line(k1+5,k2+10,k1+35,k2+10);
	int i;
	for(i=k1+5;i<=k1+35;i=i+4){line(i,k2+4,i,k2+10);}
	for(i=k1+7;i<=k1+35;i=i+4){line(i,k2+2,i,k2+10);}
	for(i=k1+5;i<=k1+35;i++){line(k1+20,k2+22,i,k2+10);}
	for(i=k1+5;i<=k1+35;i++){line(k1+20,k2+22,i,k2+35);}

}
void rookdraw(int e1,int e2,int c)

{
	if(c==1)setcolor(GREEN);
	else if(c==2)setcolor(RED);
	rectangle(e1+12,e2+5,e1+28,e2+35);
	line(e1+12,e2+30,e1+28,e2+30);
	line(e1+12,e2+10,e1+28,e2+10);
	for(int i=e2+10;i<=e2+30;i++)
	{
		line(e1+12,i,e1+28,i);
	}

}
void king(int q1,int q2, int c)


{
	if(c==1)setcolor(GREEN);
	else if(c==2)setcolor(RED);
	rectangle(q1+5,q2+15,q1+35,q2+35);
	rectangle(q1+10,q2+10,q1+30,q2+30);
	int i;
	for(i=q2+10;i<=q2+30;i++){line(q1+12,i,q1+28,i);}
	for(i=q1+10;i<=q1+30;i=i+2){line(i,q2+4,i,q2+10);}

}
void solder(int x,int y,int c)

{

    if(c==1)setcolor(GREEN);
	else if(c==2)setcolor(RED);
	line(x+5,y+35,x+35,y+35);
	for( int i=x+5;i<=x+35;i++)
	{
		line(x+20,y+15,i,y+30);
	}
	line(x+8,y+30,x+32,y+30);
	line(x+5,y+35,x+20,y+15);
	line(x+35,y+35,x+20,y+15);
	circle(x+20,y+10,5);

}
void horsecolor(int h1,int h2,int c)

{
	if(c==1)setcolor(GREEN);
	else if(c==2)setcolor(RED);
	line(h1+10,h2+5,h1+10,h2+35);
	line(h1+10,h2+10,h1+15,h2+10);
	line(h1+15,h2+10,h1+15,h2+20);
	line(h1+15,h2+20,h1+30,h2+20);
	line(h1+30,h2+20,h1+30,h2+35);

	line(h1+30,h2+35,h1+25,h2+35);
	line(h1+25,h2+35,h1+25,h2+25);
	line(h1+25,h2+25,h1+15,h2+25);
	line(h1+15,h2+25,h1+15,h2+35);
	line(h1+15,h2+35,h1+10,h2+35);
	line(h1+10,h2+33,h1+15,h2+33);
	line(h1+30,h2+33,h1+25,h2+33);
	int i;
	for(i=h1+10;i<=h1+20;i=i+2){line(i,h2+5,i,h2+10);}
	for(i=h2+10;i<=h2+20;i=i+2){line(h1+15,i,h1+20,i);}
	for(i=h1+10;i<=h1+15;i++){line(i,h2+10,i,h2+33);}
	for(i=h1+15;i<=h1+30;i++){line(i,h2+20,i,h2+25);}
	for(i=h1+25;i<=h1+30;i++){line(i,h2+25,i,h2+33);}

}
void printboard(){
    int i,j;


	  setcolor(BLACK);
	  setfillstyle(SOLID_FILL,BLACK);
	  bar(250,90,610,450);
        for ( i=250;i<560;i+=90){
                setcolor(WHITE);
                setfillstyle(SOLID_FILL,WHITE);
                for ( j=90;j<450;j+=90)
                {
                bar(i,j,i+45,j+45);

                bar(i+45,j+45,i+90,j+90);
                }
        }
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){

			if((i+j)%2==0)
				{
				    setcolor(WHITE);

				}
			else{
				setcolor(BLACK);

			}
			//outtextxy(270+(j*45),105+(i*45),"");


			if(board[i][j]<0)
				setcolor(GREEN);
			else if(board[i][j]>0)
				setcolor(9);
         if(board[i][j]>=9 && board[i][j]<=16){
                solder(255+(j*45),95+(i*45),1);
			  }
            else if( board[i][j]<-8)
                {solder(255+(j*45),95+(i*45),2);}
			else if(board[i][j]==1 || board[i][j]==8){
			  rookdraw(255+(j*45),95+(i*45),1);
			  }
            else if(board[i][j]==(-1) || board[i][j]==(-8)){
			  rookdraw(255+(j*45),95+(i*45),2);
			  }

			else if(board[i][j]==2 || board[i][j]==7){
			  horsecolor(255+(j*45),95+(i*45),1);
			  }
			else if(board[i][j]==-2 || board[i][j]==-7){
			  horsecolor(255+(j*45),95+(i*45),2);
			  }
			else if(board[i][j]==3 || board[i][j]==6){

			  camal(255+(j*45),95+(i*45),1);
			  }
			else if(board[i][j]==-3 || board[i][j]==-6){

			  camal(255+(j*45),95+(i*45),2);
			  }
			else if(board[i][j]==4){
			  queen(255+(j*45),95+(i*45),1);
			  }
			else if(board[i][j]==-4){
			  queen(255+(j*45),95+(i*45),2);
			  }
			else if(board[i][j]==5){
			  king(255+(j*45),95+(i*45),1);
			  }
			else if(board[i][j]==-5){
			  king(255+(j*45),95+(i*45),2);
			  }
			}
		}
	}
void wrongStart()
{ int i,j;
	  /*setcolor(WHITE);
	  rectangle(250,90,610,450);
        for ( i=250;i<560;i+=90){
                setcolor(WHITE);
                for ( j=90;j<450;j+=90)
                {
                bar(i,j,i+45,j+45);

                bar(i+45,j+45,i+90,j+90);
                }
        }
        setcolor(BLACK);
        rectangle(350,130,295,304);



*/

}

void cleartext(){
int i,j;
for( i=1;i<=27;i++)
		for( j=1;j<=8;j++){
			gotoxy(i,j);
			cout<<" ";
			}
	gotoxy(1,1);
	cout<<"enter initial position ";
}



void initialize(){
	  setcolor(WHITE);
	  rectangle(250,90,610,450);
        int i,j;

	  for ( i=250;i<560;i+=90)
		for ( j=90;j<450;j+=90)
		 {
		 bar(i,j,i+45,j+45);
		 bar(i+45,j+45,i+90,j+90);
		 }


	   for(i=2;i<=5;i++)
		for( j=0;j<=7;j++)
		 board[i][j] = 0;

		for( j=0;j<=7;j++)
		{
		 board[0][j] = j+1;
		 board[1][j] = j+9;
		 board[7][j] = 0-(j+1);
		 board[6][j] = 0-(j+9);
		 }
        printboard();
        //printboard(2);

	setcolor(YELLOW);

	  outtextxy(265,55,"A");
	  outtextxy(310,55,"B");
	  outtextxy(355,55,"C");
	  outtextxy(400,55,"D");
	  outtextxy(445,55,"E");
	  outtextxy(490,55,"F");
	  outtextxy(535,55,"G");
	  outtextxy(580,55,"H");

	  outtextxy(220,105,"1");
	  outtextxy(220,150,"2");
	  outtextxy(220,195,"3");
	  outtextxy(220,240,"4");
	  outtextxy(220,285,"5");
	  outtextxy(220,330,"6");
	  outtextxy(220,375,"7");
	  outtextxy(220,420,"8");
}



int horse(int x,int y,int x1,int y1)
{
	int a=0;
	if((y1==y+2 && x1==x+1)||(y1==y+2 && x1==x-1)||
    (y1==y+1 && x1==x+2)||(y1==y+1 && x1==x-2)||
    (y1==y-1 && x1==x+2)||(y1==y-1 &&
    x1==x-2)||(y1==y-2 && x1==x+1)||(y1==y-2 && x1==x-1)){
		a = 1;
		}
	return a;
}



int king(int x,int y,int x1,int y1)
{
     int a = 0;
     if((y1==y+1 && x1==x)||(y1==y-1 && x1==x)||(y1==y+1 &&
x1==x+1)||(y1==y+1 && x1==x-1)||(y1==y-1 && x1==x+1)||(y1==y-1 &&
x1==x-1)||(y1==y && x1==x+1)||(y1==y && x1==x-1)){
	a = 1;
}


     else
if(board[y][x+1]==0&&board[y][x+2]==0&&(abs(board[y1][x1])
==abs(board[y][x+3])==1||abs(board[y1][x1])==
abs(board[y][x+3])==8)){

      return 2;
     }
		if(a==1)
		{
			 if(board[y][x]==5)
			 count1=1;
			 if(board[y][x]==-5)
			 count2=1;
		}
		return a;
}



int bishop(int x,int y,int x1,int y1)
{
		int a=1,i;
		if(abs(x1-x)!=abs(y1-y))
		{
			a=0;
		}

		if((x<x1)&&(y<y1))
		{
			for(i=1;(i+x)<x1;i++)
			{
				 if(board[y+i][x+i]!=0)
				 a=0;
			}
		}

       else if((x>x1)&&(y>y1)){
	for(i=1;(x-i)>x1;i++){
	 if(board[y-i][x-i]!=0)
	    a=0;
	 }
	}
	else if((x>x1)&&(y<y1)){
	 for(i=1;(x-i)>x1;i++){
	  if(board[y+i][x-i]!=0)
	    a=0;
	 }
	}
	else if((x<x1)&&(y>y1)){
	for(i=1;(y-i)>y1;i++){
	 if(board[y-i][x+i]!=0)
	    a=0;
	 }
	}
	return a;
	}


int queen(int x,int y,int x1,int y1){
   if(x==x1||y==y1){

	 return rook(x,y,x1,y1);
   }
   else if(abs(x1-x)==abs(y-y1)){
  //if queen moves in diagnoldirection
	 return bishop(x,y,x1,y1);
   }
   else
	 return 0;
}



int rook(int x,int y,int x1,int y1){
	int a=1;
	int i,j;
	if(y1==y)
	{
		for( i=x+1;i<x1;i++)
		{
			if(board[y1][i]!=0)
			{
				a = 0;
				break;
			}
		}
		for(i=x-1;i>x1;i--)
		{
			if(board[y1][i]!=0)
			{
				a = 0;
				break;
			}
		}
	}
	else if(x1==x)
	{
		for(int i=y+1;i<y1;i++)
		{
			if(board[i][x1]!=0)
			{
				a = 0;
				break;
			}
		}
		for(i=y-1;i>y1;i--)
		{
			if(board[i][x1]!=0)
			{
				a = 0;
				break;
			}
		}
	}
	else
	{
		a=0;
	}
	return a;
	}



int pawn(int x,int y,int x1,int y1){
	int a=0;
	if(turn==0){
		if(y==1){
		  if(y1==(y+2) && x1==x){
		if(board[y1][x1]==0&&board[y+1][x]==0){
				a = 1;
			   }
			}
			}
		 if(y1==y+1 && x1==x){
			if(board[y1][x1]==0){
				a = 1;
				}
			 }
	   else if(y1==(y+1) && (x1==(x+1)||x1==(x-1))){
		   if(board[y1][x1]<0){
			 a = 1;
			 }
		  }
		}
	  else if(turn==1){
		if(y==6){
		   if( y1==(y-2) && x1==x){
			if(board[y1][x1]==0&&board[y-1][x]==0){
				a = 1;
			   }
			}
		      }
		  if( y1==(y-1) && x1==x){
			if(board[y1][x1]==0){
				a = 1;
				}
			 }
	   else if(y1==(y-1) && (x1==(x-1)||x1==(x+1))){
		   if(board[y1][x1]>0){
			 a = 1;
			 }
		  }
	 }
   if(a==1)
   {
     if(turn==0)
     {
	 if(y1==7)
	 return 2;
     }
     else
     {
	if(y1==0)
	return 2;
     }
    }
 return a;
}



void check()
{
	  int t=0,i,j,x1,y1;
	   if(turn==0){
	     for(i=0;i<=7;i++)
	     {
		 for(j=0;j<=7;j++)
		 {
			if(board[i][j]==-5)
			{
				 y1=i; x1=j;
				  break;
			}
		  }
	     }
       for(j=0;j<=7;j++){
	for(i=0;i<=7;i++){
	 if (t==1){
	    setcolor(GREEN);
	    rectangle(20,335,100,365);
	    outtextxy(30,340,"Check");
	    break;
	   }

	 if(board[j][i]>=9 && board[j][i]<=16)
		t = pawn(i,j,x1,y1);
	 else if(board[j][i]==2 || board[j][i]==7)
		t = horse(i,j,x1,y1);
	 else if(board[j][i]==4)
		t = queen(i,j,x1,y1);
	 else if(board[j][i]==1 || board[j][i]==8)
		t = rook(i,j,x1,y1);
	 else if(board[j][i]==3 || board[j][i]==6)
		t = bishop(i,j,x1,y1);

	}// for
       }//  for
     }//endif turn
    else {
     for(i=0;i<=7;i++){
      for(j=0;j<=7;j++){
       if(board[i][j]==5){
	 y1=i; x1=j;
	  break;
	      }
	  }
       }
       for(j=0;j<=7;j++){
	for(i=0;i<=7;i++){
	 if (t==1){
	    setcolor(RED);
	     rectangle(20,335,100,365);
	    outtextxy(30,340,"Check");
	    break;
	   }

	 if(board[j][i]>=(-9) && board[j][i]<=(-16))
		t = pawn(i,j,x1,y1);
	 else if(board[j][i]==(-2) || board[j][i]==(-7))
		t = horse(i,j,x1,y1);
	 else if(board[j][i]==(-4))
		t = queen(i,j,x1,y1);
	 else if(board[j][i]==(-1) || board[j][i]==(-8))
		t = rook(i,j,x1,y1);
	 else if(board[j][i]==(-3) || board[j][i]==(-6))
		t = bishop(i,j,x1,y1);

	}
       }
 }
}


int gameover(){
	int i,j,a=0,b=0;

	for(i=0;i<=7;i++)
	{
		for(j=0;j<=7;j++)
		{
		       if(board[i][j]==5)
		       b=1;
		       if(board[i][j]==-5)
		       a=1;
		}
	}
	if(b==0)
	{
	       setcolor(RED);
	       outtextxy(30,340,"Game Over");
               setcolor(GREEN);
	       outtextxy(1,300,"Player 1 Loses");
	       getch();
	       return 0;
	}
	else if(a==0)
	{
		setcolor(GREEN);
		outtextxy(1,340,"Game Over");
		outtextxy(30,300,"Player 2 Loses");
		getch();
		return 0;
	}
return 1;
}
