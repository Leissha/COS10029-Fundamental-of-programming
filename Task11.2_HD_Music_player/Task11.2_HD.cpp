#include <iostream>
#include <cstdbool>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cmath>
#include <string>
#include <limits>
#include "splashkit.h"
using namespace std;
    // Variables
    int xl=30, yl=30, w=250, h=250; // s- square
    int xt=300, yt=30; // r- rectangle
    int xb=30, yb=300;
    int xr=300, yr=300;


// Structure for a track
struct Track {
    string name;
    string location;
};

// Structure for an album
struct Album {
    string artist;
    string albumName;
    int numTracks;
    Track tracks[10]; // Assuming maximum of 10 tracks per album
};


void readAlbum(ifstream &inFile, Album a[], int& size) 
{
    inFile >> size;
    inFile.ignore(); // Ignore the newline after size

    for (int i = 0; i < size; ++i) 
    {
        getline(inFile, a[i].artist);    // Read artist name
        getline(inFile, a[i].albumName); // Read album name

        inFile >> a[i].numTracks; // Read number of tracks
        inFile.ignore();

        for (int j = 0; j < a[i].numTracks; ++j) 
        {
            getline(inFile, a[i].tracks[j].name);      // Read track name
            getline(inFile, a[i].tracks[j].location);  // Read track location
        }
        inFile.ignore();
    }
    cout << "\n===== Displaying Albums =====\n";
    for (int i = 0; i < size; ++i) 
    {
        cout << i+1 << " Title: " << a[i].albumName << " Artist: " << a[i].artist;
        cout << endl;
    }

    draw_text("AlbumName: ", COLOR_RED, "impact.TTF", 400, xl+50,yl+60);
    draw_text(a[0].albumName, COLOR_YELLOW, "impact.TTF", 400, xl+50,yl+80);
    draw_text("Artist: ", COLOR_RED, "impact.TTF", 400, xl+50,yl+120);
    draw_text(a[0].artist, COLOR_YELLOW, "impact.TTF", 400, xl+50,yl+140);
    
    draw_text("AlbumName: ", COLOR_RED, "impact.TTF", 400, xt+50,yt+60);
    draw_text(a[1].albumName, COLOR_YELLOW, "impact.TTF", 400, xt+50,yt+80);
    draw_text("Artist: ", COLOR_RED, "impact.TTF", 400, xt+50,yt+120);
    draw_text(a[1].artist, COLOR_YELLOW, "impact.TTF", 400, xt+50,yt+140);

    draw_text("AlbumName: ", COLOR_RED, "impact.TTF", 400, xb+50,yb+60);
    draw_text(a[2].albumName, COLOR_YELLOW, "impact.TTF", 400, xb+50,yb+80);
    draw_text("Artist: ", COLOR_RED, "impact.TTF", 400, xb+50,yb+120);
    draw_text(a[3].artist, COLOR_YELLOW, "impact.TTF", 400, xb+50,yb+140);

    draw_text("AlbumName: ", COLOR_RED, "impact.TTF", 400, xr+50,yr+60);
    draw_text(a[3].albumName, COLOR_YELLOW, "impact.TTF", 400, xr+50,yr+80);
    draw_text("Artist: ", COLOR_RED, "impact.TTF", 400, xr+50,yr+120);
    draw_text(a[3].artist, COLOR_YELLOW, "impact.TTF", 400, xr+50,yr+140);
}

int theMenu(Album a[], int size)
{
    // DRAW SHAPE
    draw_rectangle(COLOR_BLACK,xl,yl,w,h);
    draw_rectangle(COLOR_BLACK,xt,yt,w,h);
    draw_rectangle(COLOR_BLACK,xb,yb,w,h);
    draw_rectangle(COLOR_BLACK,xr,yr,w,h);

    //string albumName1= "left";
        
        // Click effect
    if(mouse_clicked(LEFT_BUTTON))
    {
        int x=600, y= 0;
        if ((mouse_x()>=xl) and (mouse_x()<=xl+w) and (mouse_y()>=yl) and (mouse_y()<=yl+h)) 
        {
            fill_rectangle(COLOR_BLUE,580,20,200,200);
            for (int i = 0; i < a[0].numTracks; ++i) 
            {
                y+=30;
                draw_text(a[0].tracks[i].name, COLOR_WHITE, "impact.TTF", 400, x,y);
            }
        }
        else if ((mouse_x()>=xt) and (mouse_x()<=xt+w) and (mouse_y()>=yt) and (mouse_y()<=yt+h)) 
        {
            fill_rectangle(COLOR_BLUE,580,20,200,200);
            for (int i = 0; i < a[0].numTracks; ++i) 
            {
                y+=30;
                draw_text(a[1].tracks[i].name, COLOR_WHITE, "impact.TTF", 400, x,y);
            }
        }
        else if ((mouse_x()>=xr) and (mouse_x()<=xr+w) and (mouse_y()>=yr) and (mouse_y()<=yr+h)) 
        {
            fill_rectangle(COLOR_BLUE,580,20,200,200);
            for (int i = 0; i < a[0].numTracks; ++i) 
            {
                y+=30;
                draw_text(a[2].tracks[i].name, COLOR_WHITE, "impact.TTF", 400, x,y);
            }
        }
        else if ((mouse_x()>=xb) and (mouse_x()<=xb+w) and (mouse_y()>=yb) and (mouse_y()<=yb+h)) 
        {
            fill_rectangle(COLOR_BLUE,580,20,200,200);
            for (int i = 0; i < a[0].numTracks; ++i) 
            {
                y+=30;
                draw_text(a[3].tracks[i].name, COLOR_WHITE, "impact.TTF", 400, x,y);
            }
        }
    }
    return 0;
}

int main()
{

    int size; //number of album
    string filename;
    ifstream inFile;
    Album a[100]; // example

    open_window("Draw Shape",800,600);
    clear_screen(COLOR_BLUE);

    inFile.open("resources/albums.txt");

    if (inFile.fail ()) // check for successful open
    {
        cout << "\nThe file was not successfully opened" 
        << "\nPlease check that the file currently exists"
        << endl;
        exit(1) ;
    }
    readAlbum(inFile,a,size);


    while(not quit_requested())
    {
        process_events();
        
        theMenu(a,size); //Draw shape & color

        refresh_screen(60);
    }
    inFile.close();
    return 0;
}
