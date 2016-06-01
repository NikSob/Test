#include "MyIncludes.h"


_Bool user_exit = 0;
int const win_x = 704;
int const win_y = 630;
_Bool redraw =1;

enum KEYS{LEFT,RIGHT,SPACE};


int main()
{

		int location[5][12];
		int FPS = 60;
		int countX, countY , pos_en_x = 0, pos_en_y= 50;
		int forX, forY;
		int playerX = 320;
		int const playerY = 580;
		_Bool keys[3]= {0,0,0};
		_Bool bullet = 0, fire = 0;
		int bullX,bullY,mob_bullX, mob_bullY;
		int alive[5][12][2];
		int shootX, shootY;
		int const size_of_mob = 24, size_of_player = 40;
		int randX, randY, mob_fire = 0, mob_bull = 0;
		int placeX = 0, placeY = 0, gor, gol, move= 0;
		int Xco,Yco, countAlive;
		int last1[2] , last2[2] ,last3[2];


	   ALLEGRO_DISPLAY       *display = NULL;
	   ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	   ALLEGRO_TIMER *timer =NULL;
	   ALLEGRO_BITMAP *image = NULL;
	   ALLEGRO_BITMAP *imageHero = NULL;
	   ALLEGRO_BITMAP *skull = NULL;
	   ALLEGRO_BITMAP *background = NULL;

	   if(!al_init())
	   {
	        fprintf(stderr, "failed to initialize allegro!\n");
	        return -1;
	   }

	   al_install_keyboard();
	   al_init_image_addon();
	   al_init_font_addon();
	   al_init_ttf_addon();
	   al_init_primitives_addon();


	   display = al_create_display(win_x, win_y);

	     if(!display) {
	        fprintf(stderr, "failed to create display!\n");
	        return -1;
	     }

	     for(forY = 0; forY < 5 ; forY++)
	     {
	    	 for(forX=0; forX < 12; forX++)
	    	 {
	    		 location[forY][forX] = 1;
	    	 }
	     }


	   image = al_load_bitmap("Resources/1-1.jpeg");
	   imageHero = al_load_bitmap("Resources/hero.jpg");
	   skull = al_load_bitmap("Resources/5.jpeg");
	   background = al_load_bitmap("Resources/back.jpg");

	   timer = al_create_timer(1.0/FPS);

	   event_queue = al_create_event_queue();
	   al_register_event_source(event_queue, al_get_keyboard_event_source());
	   al_register_event_source(event_queue, al_get_display_event_source(display));
	   al_register_event_source(event_queue, al_get_timer_event_source(timer));
	   al_start_timer(timer);



	   while(!user_exit)
	   {

		   ALLEGRO_EVENT ev;
		   al_wait_for_event(event_queue, &ev);

		   al_draw_bitmap(imageHero, playerX , playerY , 0);
		   al_draw_bitmap(skull, 0 , 0 , 0);

		   for(countY = 0; countY<5 ; countY++)
		   	{
		   		for(countX = 0; countX<12; countX++)
		   		{
		   			if(location[countY][countX] == 1)
		   			{
		   				al_draw_bitmap(image, pos_en_x, pos_en_y , 0);
		   				alive[countY][countX][0] = pos_en_x;
		   				alive[countY][countX][1] = pos_en_y;
		   			}
		   			else
		   			{
		   				alive[countY][countX][0] = NULL;
		   				alive[countY][countX][1] = NULL;
		   			}
		   			pos_en_x += 40;

		   		}
		   	 pos_en_x = placeX;
		   	 pos_en_y += 40;
		   	}

		   pos_en_y = placeY+50;


		   if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		      		  {
		      			  switch(ev.keyboard.keycode)
		      			  {

							case ALLEGRO_KEY_LEFT:
								keys[LEFT] = 1;
								break;
							case ALLEGRO_KEY_RIGHT:
								keys[RIGHT] = 1;
								break;
							case ALLEGRO_KEY_SPACE:
								keys[SPACE] = 1;
								break;
							case ALLEGRO_KEY_ESCAPE:
								user_exit = 1;
								break;
		      			  }
		      		  }
		   if(bullet == 0)
		   {
			   bullet = keys[SPACE];
		   }

		      		 if(ev.type == ALLEGRO_EVENT_KEY_UP)
		      		 {
		      			 switch(ev.keyboard.keycode)
		      			 {
		      			 case ALLEGRO_KEY_LEFT:
		      				 keys[LEFT] = 0;
		      				 break;
		      			 case ALLEGRO_KEY_RIGHT:
		      				 keys[RIGHT] = 0;
		      				 break;
		      			case ALLEGRO_KEY_SPACE:
		      				keys[SPACE] = 0;
		      				break;
		      			 }
		      		 }

		      		 if (bullet == 1)
		      		 {

		      			 if(fire == 0)
		      			 {
		      				 al_draw_line(bullX = playerX+(size_of_player/2) ,bullY = playerY - 10, playerX+(size_of_player/2), playerY, al_map_rgb(255,255,255),1);
		      				 fire = 1;
		      			 }
		      			 else
		      			 {
		      				al_draw_line(bullX ,bullY - 10, bullX, bullY, al_map_rgb(255,255,255),1);
		      				bullY -=10;
		      				if(bullY - 10 <1)
		      				{
		      					bullet = 0;
		      					fire = 0;
		      				}
		      			 }
		      			 for(shootY =0; shootY<5; shootY++)
		      			 {
		      				 for(shootX =0; shootX<12; shootX++)
		      				 {
		      					 if(bullX >= alive[shootY][shootX][0] && bullX <= (alive[shootY][shootX][0]+ size_of_mob) && (bullY-10) >= alive[shootY][shootX][1] && (bullY-10) <= (alive[shootY][shootX][1]+ size_of_mob))
		      					 {
		      						 bullet = 0;
		      						 fire = 0;
		      						 location[shootY][shootX] = 0;
		      					 }
		      				 }
		      			 }
		      		 }

		      		countAlive = 0;

		      		 for(Yco = 0; Yco< 5; Yco++)
		      		 {
		      			 for(Xco = 0 ; Xco < 12 ; Xco ++)
		      			 {
		      				 if ( location[Yco][Xco] == 1 )
		      				 {
		      					 countAlive++;
		      					 if (countAlive <4)
		      					 {
		      						 switch (countAlive)
		      						 {
		      						 case 1:
		      							 last1[0] = Yco;
		      							 last1[1] = Xco;
		      							 break;
		      						 case 2:
		      							 last2[0] = Yco;
		      							 last2[1] = Xco;
		      							 break;
		      						 case 3:
		      							 last3[0] = Yco;
		      							 last3[1] = Xco;
		      							 break;
		      						 }
		      					 }
		      				 }
		      			 }
		      		 }

		      		 if (countAlive == 0)
		      			 user_exit =1;

		      		 if(mob_fire == 120)
		      		 {
		      			 if(countAlive > 3)
		      			 {
							 do
							 {
								 randX = (rand()%12)+ 1;
								 randY = (rand()%5)+ 1;
							 }while(location[randY][randX] == 0 );
		      			 }
		      			 else
		      			 {
		      				 if(location[last1[0]][last1[1]] == 1)
		      				 {
		      					 randX = last1[1];
		      					 randY = last1[0];
		      				 }
		      				 else if (location[last2[0]][last2[1]] == 1)
		      				 {
		      					 randX = last2[1];
		      					 randY = last2[0];
		      				 }
		      				 else if (location[last3[0]][last3[1]] == 1)
		      				 {
		      					 randX = last3[1];
		      					 randY = last3[0];
		      				 }
		      			 }
		      			if(mob_bull == 0)
		      			{
		      				al_draw_line(mob_bullX = alive[randY][randX][0]+(size_of_mob/2) ,mob_bullY = alive[randY][randX][1]+ size_of_mob, alive[randY][randX][0]+(size_of_mob/2), alive[randY][randX][1]+ size_of_mob + 10, al_map_rgb(255,255,255),1);
		      				mob_bull = 1;
		      			}
		      			else
		      			{
		      				al_draw_line(mob_bullX ,mob_bullY+ size_of_mob , mob_bullX, mob_bullY+size_of_mob+ 10, al_map_rgb(255,255,255),1);
		      				mob_bullY +=10;
		      				if(mob_bullY + 10 >629)
		      				{
		      					mob_bull = 0;
		      					mob_fire++;
		      				}

		      			}

		      			if (mob_bullX >= playerX && mob_bullX <= playerX + size_of_player && mob_bullY >= playerY && mob_bullY <= playerY+ size_of_player)
		      			{
		      				user_exit = 1;
		      			}
		      		 }
		      		 else
		      		 {
		      			 mob_fire ++;
		      			 if(mob_fire == 123)
		      				 mob_fire =0;
		      		 }

		      		 if(pos_en_x == 0)
		      		 {
		      			 gor =1;
		      			 gol = 0;
		      		 }

		      		 if (pos_en_x == 240)
		      		 {
		      			 gor = 0;
		      			 gol = 1;
		      		 }
		      		 if (move == 2)
		      		 {
						 if (gor)
						 {
							 placeX += 1;
						 }

						 if(gol)
						 {
							 placeX -= 1;
						 }

						 if (move == 2)
							 move = 0;

		      		 }
		      			move ++;

		      		 if(ev.type == ALLEGRO_EVENT_TIMER)
		      		   		  {
		      			 if(playerX<665)
		      		   			playerX += keys[RIGHT]*6;
		      			 if(playerX>-1)
		      		   			playerX -= keys[LEFT] *6;

		      		   			redraw = 1;
		      		   		  }
		      		if(redraw && al_is_event_queue_empty(event_queue))
		      		   		{
		      		   			redraw = 0;
		      		   			al_flip_display();
		      		   			al_clear_to_color(al_map_rgb(0,0,0));

		      		   		}




	   }

	   al_draw_bitmap(background, 70 , 0 , 0);
	   al_flip_display();
	   al_clear_to_color(al_map_rgb(0,0,0));


	   al_rest(3.0);

	   al_destroy_display(display);
	   al_destroy_bitmap(image);
	   al_destroy_bitmap(background);
	   al_destroy_bitmap(skull);
	   al_destroy_bitmap(imageHero);
	   al_destroy_timer(timer);
	   al_destroy_event_queue(event_queue);


	   return 0;

}
