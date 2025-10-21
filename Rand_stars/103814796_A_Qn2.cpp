// Student name: Kha Anh Nguyen
// Student ID: 103814796
// File name: 103814796_A_Qn2.cpp
// Purpose: To produce random color stars shape with switch and while loop
#include "splashkit.h"
#include <time.h>

void draw_star(int clr_value, double x, double y, int width, int height)
{
    /// Declare 8 local variables
    double x2, y2, left_x, mid_y, mid_x, right_x,top_y,bottom_y;
    color clr;
    x2=x+width; 
    y2=y+height; 
    left_x=x-width; 
    mid_y=y+height/2; 
    mid_x=x+width/2; 
    right_x=x2+width; 
    top_y=y-height; 
    bottom_y=y2+height;

    switch(clr_value)
    {
        case 0: 
            clr = COLOR_PINK;
            break;
        case 1: 
            clr = COLOR_LIGHT_GREEN;
            break;
        case 2: 
            clr = COLOR_POWDER_BLUE;
            break;
        case 3: 
            clr = COLOR_BLANCHED_ALMOND;
            break;
    }
    // Draw function
    fill_rectangle(clr, x,y,width,height); //rectangle
    fill_triangle(clr,x,y,x2,y,mid_x,top_y); //top
    fill_triangle(clr,x2,y,x2,y2,right_x,mid_y); //right
    fill_triangle(clr,x2,y2,x,y2,mid_x,bottom_y); //bot
    fill_triangle(clr,x,y2,x,y,left_x,mid_y); //left
}

int main()
{
    open_window("Shape", 800,600);
    clear_screen(COLOR_WHITE);
    srand(time(NULL)); //seed random number
    int row=1, x=100, y=100, column;
    while(row<=10)
    {
        column=1; // set column at 1 every time inner loop runs
        while (column<=row)
        {
            draw_star(rand() % 4, x, y, 10, 10); // call function to draw random color with 4 options (0-3)
            x += 32; // update x position to draw the next draw 
            column++;
        }
        x = 100; // reset x position so the next row starts at the same position
        y += 32; // update the y position to go the next row
        row++;
    }
    refresh_screen(60);
    delay(5000);
    return 0;
}
    


