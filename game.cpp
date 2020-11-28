/*
Fatih Alparslan
1.11.2020
YELLOW HEAD MOVES UP WHEN PRESSED W
YELLOW HEAD MOVES TO THE LEFT WHEN PRESSED A
YELLOW HEAD MOVES RIGHT WHEN PRESSED D
YELLOW HEAD MOVES DOWN WHEN PRESSED S
GREEN BALLS ARE FRUIT. YELLOW HEAD MUST EAT GREEN BALLS.
IF THE MONSTERS HIT THE YELLOW HEAD, THE GAME IS END
*/
#include <stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<stdbool.h>

bool alive=true;
int scor;
void cerceve(void){
 setcolor(RED);
 setlinestyle(SOLID_LINE,0,10);
 line(80,80,380,80);
 line(80,380,380,380);
 line(80,80,80,380);
 line(380,80,380,380);
}
void draw_bariers(void){
setfillstyle(1,RED);
bar(150,85,200,180);
bar(85,220,200,260);
bar(260,125,375,155);
bar(260,300,375,330);
bar(300,155,330,260);

}
void draw_monster1(void){
  static int incr=0;
  static bool way=true;
  setcolor(3);
  sector(110,100+incr,0,360,10,10);
  setcolor(5);
  sector(110,100+incr,0,360,7,7);
  setcolor(7);
  sector(104,98+incr,0,360,3,3); 
  setcolor(0);
  sector(104,99+incr,0,360,1,1);   
  setcolor(7);
  sector(116,98+incr,0,360,3,3); 
  setcolor(0);
  sector(116,99+incr,0,360,1,1);
  if(way){
  incr++;
  	if(incr==100){
  		way=false;
	  }
   }else{
   	incr--;
   	if(incr==0)
   	way=true;
   }
}
void draw_monster2(void){
  static int incr=0;
  static bool way=true;
  setcolor(3);
  sector(260+incr,100,0,360,10,10);
  setcolor(5);
  sector(260+incr,100,0,360,7,7);
  setcolor(7);
  sector(256+incr,98,0,360,3,3); 
  setcolor(0);
  sector(256+incr,99,0,360,1,1);   
  setcolor(7);
  sector(267+incr,98,0,360,3,3); 
  setcolor(0);
  sector(267+incr,99,0,360,1,1);
  if(way){
  incr++;
  	if(incr==100){
  		way=false;
	  }
   }else{
   	incr--;
   	if(incr==0)
   	way=true;
   }
}

void draw_monster3(void){
  static int incr=0;
  static bool way=true;
  setcolor(3);
  sector(360,170+incr,0,360,10,10);
  setcolor(5);
  sector(360,170+incr,0,360,7,7);
  setcolor(7);
  sector(354,168+incr,0,360,3,3); 
  setcolor(0);
  sector(354,169+incr,0,360,1,1);   
  setcolor(7);
  sector(367,168+incr,0,360,3,3); 
  setcolor(0);
  sector(367,169+incr,0,360,1,1);
  if(way){
  incr++;
  	if(incr==100){
  		way=false;
	  }
   }else{
   	incr--;
   	if(incr==0)
   	way=true;
   }
}
void draw_monster4(void){
  static int incr=0;
  static bool way=true;
  setcolor(3);
  sector(260+incr,360,0,360,10,10);
  setcolor(5);
  sector(260+incr,360,0,360,7,7);
  setcolor(7);
  sector(256+incr,358,0,360,3,3); 
  setcolor(0);
  sector(256+incr,359,0,360,1,1);   
  setcolor(7);
  sector(267+incr,358,0,360,3,3); 
  setcolor(0);
  sector(267+incr,359,0,360,1,1);
  if(way){
  incr++;
  	if(incr==100){
  		way=false;
	  }
   }else{
   	incr--;
   	if(incr==0)
   	way=true;
   }
}

draw_all_monster(void){
	draw_monster1();
	draw_monster2();
	draw_monster3();
	draw_monster4();
}
bool wall_control(int x,int y)
{
		if(getpixel(x+12,y)==RED){
		return true;
		}else if(getpixel(x-12,y)==RED){
			return true;
		}else if(getpixel(x,y+12)==RED){
			return true;
		}else if(getpixel(x,y-12)==RED){
			return true;
		}else{
			return 0;
		}
		  
}
bool monster_control(int x,int y)
{
		if(getpixel(x+10,y)==3){
		return true;
		}else if(getpixel(x-10,y)==3){
			return true;
		}else if(getpixel(x,y+10)==3){
			return true;
		}else if(getpixel(x,y-10)==3){
			return true;
		}else{
			return false;
		}
		  
}
bool fruit_control(int x,int y)
{
    	if(getpixel(x+10,y)==10){
		return true;
		}else if(getpixel(x-10,y)==10){
			return true;
		}else if(getpixel(x,y+10)==10){
			return true;
		}else if(getpixel(x,y-10)==10){
			return true;
		}else{
			return 0;
		}		  
}
void draw_fruit(bool eat){
	
	static int i=0,x,y;
	if(eat){
		i++;
		
		if(i>=4){
			i=0;
		}
	}
	setcolor(10);
	switch(i){
		case 0:
			x=100;y=205;
			break;
		case 1:
			x=285;y=360;
			break;
		case 2:
			x=360;y=247;
			break;
		case 3:
			x=290;y=110;
			break;
	}
	sector(x,y,0,360,10,10);

}
void draw_head(bool new_press,char c, int *x_val,int *y_val){
	static int s_angle=-135,e_angle=135;
	static int j,i;
	static int l=0;
	static bool dir=true;
	static bool fruit_new=false;
   draw_fruit(fruit_new);
   fruit_new=fruit_control(230+j,230+i);
if(fruit_new)
scor=scor+10;
setcolor(7);
char val[20];
sprintf(val,"SCOR:\t%d",scor);
settextstyle(BOLD_FONT,HORIZ_DIR,2);
outtextxy(200,50,val);
if(monster_control(230+j,230+i)){
	alive=false;
}
 if(new_press){
 
	switch(c){
		case 'W':
			s_angle=-225;
			e_angle=45;
			i--;
			if(wall_control(230+j,230+i))
			 i++;
			break;
		case 'S':
			s_angle=-45;
			e_angle=225;
			i++;
			if(wall_control(230+j,230+i))
			i--;
			break;
		case 'A':
			s_angle=-135;
			e_angle=135;
			j--;
			if(wall_control(230+j,230+i))
			j++;
			break;
		case 'D':
			s_angle=45;
			e_angle=315;
			j++;
			if(wall_control(230+j,230+i))
			j--;
			break;
		default:
			
		break;
	}
}

*x_val=j;
*y_val=i;
 if(dir)
 {
  
  setcolor(14);
  sector(230+j,230+i,0,360,10,10);
  setcolor(7);
  sector(230+j,230+i,0,360,4,2);
  setcolor(0);
  l++;
  if(l>=5){
  dir=false;
  l=0;
}

 }else{
  setcolor(14);
  sector(230+j,230+i,s_angle,e_angle,10,10);
  setcolor(7);
  sector(230+j,230+i,0,360,4,2);
  setcolor(0);
  sector(230+j,230+i,0,360,1,1);
  l++;
  if(l>=5){
     dir=true;
     l=0;
         }
    }
 
}
bool control_border(int x_inrc,int y_incr){
	bool left=((230+x_inrc-20)<=80);
	bool right=((230+x_inrc+20)>=380);
	bool up=((230+y_incr-20)<=80);
	bool down=((230+y_incr+20)>=380);
	if(left || right || up || down){
		return true;
	}else{
		return false;
	}
	
	
}

int main(){
	
	int i=0,j=0,l=0;
	int x_art,y_art;
	bool press=true;
char cd;
int gd=DETECT,gm;
initgraph(&gd,&gm,"");

setcolor(9);
cerceve();

   while(1)
   {

	   printf("%c",cd);
       while(!kbhit())
       {

cleardevice();
cerceve();
draw_bariers();
draw_all_monster();
//draw_fruit();
draw_head(press,cd,&x_art,&y_art);
press=false;
if(!alive){
	break;
}
delay(40);

 }
  if(alive){
   cd=toupper(getch());
   press=true;
}else{
	break;
	
	
}
}
cleardevice();
setcolor(9);
cerceve();
setcolor(7);
settextstyle(BOLD_FONT,HORIZ_DIR,4);
outtextxy(90,160,"GAME OVER");
char val[20];
sprintf(val,"YOUR SC0R:\t%d",scor);
settextstyle(BOLD_FONT,HORIZ_DIR,3);
outtextxy(90,220,val);
delay(3000);
getch();
closegraph();

}



