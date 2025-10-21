// Student name: Kha Anh Nguyen
// Student ID: 103814796
// File name: 103814796_A_Qn3.cpp
// Purpose: To generate random bar graphs 

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "splashkit.h"

#define SIZE 800
struct sample
{
    int value;
    color clr;
};

color get_color(int num)
{
    color clr;
    float hue;
    hue = num/700.0f;
    clr = hsb_color(hue,0.7,0.8);
    return clr;
}
void fill_array(sample data[]) 
{
    int i;
    for(i=0;i<SIZE;i++)
    {
        data[i].value = rand()%600; //generate random bar vertical value at each index
        data[i].clr = get_color(data[i].value); //generate color base on bar vertical values
    }
}
void draw_bar(sample data[],bool show_bars) // bool = button state, draw when "show_bars" is on
{
    int i;
    float x,y,rect_width=1;
    float screen_height=700;
    if(show_bars) 
    {
        for(i=0;i<800;i++)
        {
            x = rect_width * i;
            y = screen_height - data[i].value;
            fill_rectangle(data[i].clr,x,y,rect_width,data[i].value);
        }
    }
}

void BubbleSort(sample a[], int array_size)
{
    int i, j, temp;
    for (i = 0; i < (array_size-1); i++) //control no(each pass)
    {
        for (j = 0; j < (array_size-1-i); j++) //next loop decreases as smallest element is sorted to the right after each loop
        {
            if (a[j].value < a[j+1].value) //loop if the next value is larger then swap
            {
                temp = a[j+1].value;
                a[j+1].value = a[j].value;
                a[j].value = temp;
            }
        }
    }
}
void selectionSort(sample arr[], int n)
{
    int i, j, min_idx, temp;
    for (i=0; i<n-1; i++) 
    {
        min_idx = i;
        for (j=i+1; j<n; j++) //compare pair of 2 index
        {
            if (arr[j].value < arr[min_idx].value) //swap if the second index is smaller (*)
            min_idx = j;
        }
        if (min_idx != i) // if (*) happended 
        {
            temp = arr[min_idx].value;
            arr[min_idx].value = arr[i].value;
            arr[i].value = temp;
        }
    }
}

int main()
{
    sample data[SIZE];
    open_window("Array rectangles",800,700);
    
    //* declare button coordinate
    int x_draw = 10 , y = 10, width = 100, height = 30;
    int x_sort1 = 160; 
    int x_sort2 = 310 ;

    //* bool for button state toggle
    bool show_bars = false; // bool false = deactivate draw_bar function 
    bool sorting_bars = false; // bool false = deactivate sorting state
    
    srand(time(NULL));
    fill_array(data);
    while(not quit_requested())
    {
        process_events();
        clear_screen(COLOR_WHITE);
        
        fill_rectangle(COLOR_GREEN,x_sort1,y,width,height);
        
        fill_rectangle(COLOR_GREEN,x_draw,y,width,height); // click draw button
        draw_text("Draw Bars", COLOR_WHITE, "BERNHC.TTF",100, x_draw + 10, y + 10);
    
        fill_rectangle(COLOR_GREEN,x_sort1,y,width,height); // click draw button
        draw_text("Sort 1", COLOR_WHITE, "BERNHC.TTF",100, x_sort1 + 10, y + 10);

        fill_rectangle(COLOR_GREEN,x_sort2,y,width,height); // click draw button
        draw_text("Sort 2", COLOR_WHITE, "BERNHC.TTF",100, x_sort2 + 10, y + 10);
        
        fill_rectangle(COLOR_RED,0,50,800,5); // horizontal separator

        if(mouse_clicked(LEFT_BUTTON))
        {
            if (!sorting_bars) // bool = false
            {
                if ((mouse_x()>=x_draw) and (mouse_x()<=x_draw+width) and (mouse_y()>=y) and (mouse_y()<=y+height))
                {
                    show_bars = true; // activate draw_bar function
                    fill_array(data); // Generate new data for bars
                }

                else if ((mouse_x()>=x_sort1) and (mouse_x()<=x_sort1+width) and (mouse_y()>=y) and (mouse_y()<=y+height))
                {
                    if (show_bars) // Sort only if bars are drawn
                    {
                        sorting_bars = true; // Turn on sorting state
                        BubbleSort(data, SIZE);
                        sorting_bars = false; // Turn off sorting state => bar disappears
                    }
                }
                else if ((mouse_x()>=x_sort2) and (mouse_x()<=x_sort2+width) and (mouse_y()>=y) and (mouse_y()<=y+height))
                {
                    if (show_bars) // Sort only if bars are drawn
                    {
                        sorting_bars = true;
                        selectionSort(data, SIZE);
                        sorting_bars = false; 
                    }
                }
            }
        }
        draw_bar(data, show_bars); // draw new bar every time the 1st button is clicked 
        refresh_screen(60);
    }
    return 0;
}