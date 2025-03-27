//===========================================================================================================================
// Name        : main.cpp
// Author      : Ryan C. Ellis
// Creation Date: 11/6/2024
// Last Update: 11/8/2024
// Description: Main function that implements Shape parent class and functions along with all child class structures
// and runs a menu prompt for the user to select which objects to create with specified values for size of the
// given object and color of the border and filler. Objects will be stored into a Doubly linked list structure database.
// Menu prompt also has option to print .svg format and save to a file for the user to have in this directory and open in web browser.
//===========================================================================================================================

//Note: I feel like I am so close to making it all work but I am having the time of my life finding out why the polymorphism
//isn't taking place the dynamic binding isn't happening. Also running down to the wire, the view box calculations have fallen
// to the wayside as that was the last thing I was working on and had to finish commenting everything out.

//Feedback: DLinkedList<Shape>* database = new DLinkedList<Shape>();
// should be
// DLinkedList<Shape *> database;
// This will make the polymorphism take hold.
//
// Then you would populate with something like
//
// Rectangle *rect = new Rectangle(rx, ry, rw, rh);
// ...
// database->push_back(rect);
//
// As is, there are some memory errors.
//
// You are right, you are very close here.  With the above change and a little editing it will be finished.
//
// The bounding boxes need a little editing here and there.


#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"
#include "Circle.h"
#include "DLinkedList.h"
#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

void menu();
void bordercolors();            //prototypes
void fillcolors();

int main(){

    srand((0));         //set random seed

   // DLinkedList<Shape>* database = new DLinkedList<Shape>();  //change to have indeces?
    DLinkedList<Shape *> database; //updated code
    int input = 0;
    int bord;               //database and variable declarations, to hold border and fill color selections
    int fil;                //along with width, opactiy and the name of the file to be saved
    int wid;
    double op;
    string svgfile;
    string svgtext;

    while(input != 14){         //while loop structure for menu prompt

        do{ menu();
            cin>> input;                //do while loop for initial menu prompt for user input validity checking

            if(cin.fail()){
                cerr<<"Input was not between 1-14, try again."<<endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else if(input >= 1 && input <= 14 )
                break;
            else
                cerr<<"Input was not between 1-14, try again."<<endl;
        }while(true);


        if(input == 14)         //initial check for quit status
            break;

        else if(input == 1){       //first prompt choice to creae a rectangle and ask for boundaries
            int rx, ry,rw, rh;

            cout<< "Input Upper Left X [-1000,1000] : ";
            cin>>rx;
            cout<< "Input Upper Left Y [-1000,1000] : ";
            cin>>ry;
            cout<< "Input Width [1,1000]: ";
            cin>>rw;
            cout<<"Input Height [1,1000]: ";
            cin>>rh;

            Rectangle *rect = new Rectangle(rx, ry, rw, rh);        //create rectangle of specified size

            bordercolors();
            cin>>bord;
            rect->setbordercolor(bord);             //set border and fill colors

            fillcolors();
            cin>>fil;
            rect->setfillcolor(fil);

            try{
            cout<<"Input Border Width [1,100]: ";
            cin>>wid;                               //try-catch for user validity checking
            cout<<"Input the Opacity [0,1]: ";
            cin>>op;
            rect->setborderwidth(wid);
            rect->setopacity(op);

            }catch(string exstring){
                throw exstring;
            }
            database.push_back(rect);
            /*database[databasesize]->push_back(*rect); */            //push back rectangle into database
        }
        else if(input == 2){            //prompt to create Square and ask for boundaries
            int sx, sy,sl;

            cout<< "Input Upper Left X [-1000,1000] : ";
            cin>>sx;
            cout<< "Input Upper Left Y [-1000,1000] : ";
            cin>>sy;
            cout<< "Input Side Length [1,1000]: ";
            cin>>sl;
            Square *sq = new Square(sx, sy, sl);        //create square of specified size


            bordercolors();
            cin>>bord;                  //set border and fill colors
            sq->setbordercolor(bord);

            fillcolors();
            cin>>fil;
            sq->setfillcolor(fil);

            try{
            cout<<"Input Border Width [1,100]: ";       //try catch for validity checking
            cin>>wid;
            cout<<"Input the Opacity [0,1]: ";
            cin>>op;
            sq->setborderwidth(wid);
            sq->setopacity(op);

            }catch(string exstring){
                throw exstring;
            }
            database.push_back(sq);
            //database[databasesize]->push_back(*sq);           //push back square into database
        }
        else if(input == 3){        //prompt to create triangle and ask for boundaries
            int trivert[6];
            int trin;
            int vertcount = 1;

            for(int i = 0; i< 3;i++){
                cout<< "Input x"<<vertcount<<" [-1000,1000] : ";
                cin>>trin;
                trivert[i] = trin;
                cout<< "Input y"<<vertcount<<" [-1000,1000] : ";
                cin>>trin;
                trivert[i] = trin;
                vertcount++;
            }

            Triangle *tri = new Triangle(trivert);      //create triangle of specified size

            bordercolors();
            cin>>bord;
            tri->setbordercolor(bord);      //set border and fill colors

            fillcolors();
            cin>>fil;
            tri->setfillcolor(fil);

            try{
            cout<<"Input Border Width [1,100]: ";   //try catch for validity checking
            cin>>wid;
            cout<<"Input the Opacity [0,1]: ";
            cin>>op;
            tri->setborderwidth(wid);
            tri->setopacity(op);

            }catch(string exstring){
                throw exstring;
            }
            database.push_back(tri);
            //database[databasesize]->push_back(*tri);          //push back triangle into database
        }
        else if(input == 4){        //prompt to create circle and ask for boundaries
            int cirx, ciry;
            int rad;

            cout<< "Input Center X [-1000,1000] : ";
            cin>>cirx;
            cout<< "Input Center Y [-1000,1000] : ";
            cin>>ciry;
            cout<< "Input Radius [1,1000]: ";
            cin>>rad;

            Circle *cir = new Circle(cirx, ciry, rad);      //create circle of specified size

            bordercolors();
            cin>>bord;
            cir->setbordercolor(bord);          //set border and fill colors

            fillcolors();
            cin>>fil;
            cir->setfillcolor(fil);

            try{
            cout<<"Input Border Width [1,100]: ";       //try catch for validity checking
            cin>>wid;
            cout<<"Input the Opacity [0,1]: ";
            cin>>op;
            cir->setborderwidth(wid);
            cir->setopacity(op);

            }catch(string exstring){
                throw exstring;
            }
            database.push_back(cir);
            //database[databasesize]->push_back(*cir);          //push back circle into database
        }
        else if(input == 5){
            int runs=0;
            int min = -1000;
            int max = 1000;
            int rx =  min + rand() % (max - min + 1);
            int ry =  min + rand() % (max - min + 1);       //create random rectangles
            int rw = rand()%1000+1;
            int rh = rand()%1000+1;
            bord = rand()%25+1;
            fil = rand()%25+1;                      //sets random values within bounds
            wid = rand()%100+1;
            op = rand()%2;
            int count = 0;

            cout<<"Number of Objects in Database : ";       //number of rectangles to make
            cin>> runs;

            while (count < runs && runs != 0){
                Rectangle *rec = new Rectangle(rx, ry, rw, rh);     //loop to create rectangles
                rec->setbordercolor(bord);
                rec->setfillcolor(fil);
                rec->setborderwidth(wid);
                rec->setopacity(op);
                database.push_back(rec);
                //database[databasesize]->push_back(*rec);
                count++;
                delete rec;
            }
        }
        else if(input == 6){
            int runs =0;
            int min = -1000;
            int max = 1000;
            int sx =  min + rand() % (max - min + 1);
            int sy =  min + rand() % (max - min + 1);       //create random squares
            int sl = rand()%1000+1;
            bord = rand()%25+1;                 //sets random values within bounds
            fil = rand()%25+1;
            wid = rand()%100+1;
            op = rand()%2;
            int count = 0;

            cout<<"Number of Objects in Database : ";       //number of squares to make
            cin>> runs;

            while (count < runs && runs != 0){
                Square *sq = new Square(sx, sy, sl);        //loop to create squares
                sq->setbordercolor(bord);
                sq->setfillcolor(fil);
                sq->setborderwidth(wid);
                sq->setopacity(op);
                database.push_back(sq);
                //database[databasesize]->push_back(*sq);
                count++;
            }
        }
        else if(input == 7){
            int trivert[6];
            int runs =0;
            int min = -1000;            //create random triangle
            int max = 1000;
            bord = rand()%25+1;
            fil = rand()%25+1;
            wid = rand()%100+1;
            op = rand()%2;
            int count = 0;



            for(int i =0;i <6;i++){
                trivert[i] =  (min + rand() % (max - min + 1));     //sets random values within bounds
            }


            cout<<"Number of Objects in Database : ";       //number of triangles to make
            cin>> runs;

            while (count < runs&& runs != 0){
                Triangle *tri = new Triangle(trivert);      //loop to create triangles
                tri->setbordercolor(bord);
                tri->setfillcolor(fil);
                tri->setborderwidth(wid);
                tri->setopacity(op);
                database.push_back(tri);
                //database[databasesize]->push_back(*tri);
                count++;
            }
        }
        else if(input == 8){        //create random circle
            int runs = 0;
            int min = -1000;
            int max = 1000;
            int cirx =  min + rand() % (max - min + 1);
            int ciry =  min + rand() % (max - min + 1);   //set random values within bounds
            int rad = rand()%1000+1;
            bord = rand()%25+1;
            fil = rand()%25+1;
            wid = rand()%100+1;
            op = rand()%2;
            int count = 0;

            cout<<"Number of Objects in Database : ";       //number of circles to make
            cin>> runs;

            while (count < runs && runs != 0){
                Circle *cir = new Circle(cirx, ciry, rad);      //loop to create circles
                cir->setbordercolor(bord);
                cir->setfillcolor(fil);
                cir->setborderwidth(wid);
                cir->setopacity(op);
                database.push_back(cir);
                //database[databasesize]->push_back(*cir);
                count++;
            }
        }
        else if(input == 9){            //user selected to pick random object and add specified number to database
            int runs =0;
            int count = 0;
            int randomgen;

            cout<<"Number of Objects to Add [0,100] : ";        //set amount of times to add
            cin>> runs;

            while(count < runs){
                randomgen = rand()%4+1;     //random object selection number value
                switch(randomgen){
                    case 1:{
                        int runs =0 ;
                        int min = -1000;        //first case is random rectangle creation
                        int max = 1000;
                        int rx =  min + rand() % (max - min + 1);
                        int ry =  min + rand() % (max - min + 1);
                        int rw = rand()%1000+1;
                        int rh = rand()%1000+1;
                        bord = rand()%25+1;
                        fil = rand()%25+1;
                        wid = rand()%100+1;
                        op = rand()%2;
                        int count = 0;



                        while (count < runs && runs != 0){
                            Rectangle *rec = new Rectangle(rx, ry, rw, rh);
                            rec->setbordercolor(bord);
                            rec->setfillcolor(fil);
                            rec->setborderwidth(wid);
                            rec->setopacity(op);
                            database.push_back(rec);
                            //database[databasesize]->push_back(*rec);
                            count++;
                        }

                    }break;
                    case 2: {
                        int runs =0;
                        int min = -1000;        //second case is random Square creation
                        int max = 1000;
                        int sx =  min + rand() % (max - min + 1);
                        int sy =  min + rand() % (max - min + 1);
                        int sl = rand()%1000+1;
                        bord = rand()%25+1;
                        fil = rand()%25+1;
                        wid = rand()%100+1;
                        op = rand()%2;
                        int count = 0;

                        cout<<"Number of Objects in Database : ";
                        cin>> runs;

                        while (count < runs && runs != 0){
                            Square *sq = new Square(sx, sy, sl);

                            sq->setbordercolor(bord);
                            sq->setfillcolor(fil);
                            sq->setborderwidth(wid);
                            sq->setopacity(op);
                            database.push_back(sq);
                            //database[databasesize]->push_back(*sq);
                            count++;
                        }

                    }break;
                    case 3:{
                        int trivert[6];
                        int runs;
                        int min = -1000;
                        int max = 1000;
                        bord = rand()%25+1;
                        fil = rand()%25+1;
                        wid = rand()%100+1;         //third case is random triangle creation
                        op = rand()%2;
                        int count = 0;

                        for(int i =0;i <6;i++)
                            trivert[i] =  (min + rand() % (max - min + 1));


                        cout<<"Number of Objects in Database : ";
                        cin>> runs;

                        while (count < runs&& runs != 0){
                            Triangle *tri = new Triangle(trivert);
                            tri->setbordercolor(bord);
                            tri->setfillcolor(fil);
                            tri->setborderwidth(wid);
                            tri->setopacity(op);
                            database.push_back(tri);
                            //database[databasesize]->push_back(*tri);
                            count++;
                        }

                    }break;
                    case 4:{
                        int runs;
                        int min = -1000;            //fourth case is random circle creation
                        int max = 1000;
                        int cirx =  min + rand() % (max - min + 1);
                        int ciry =  min + rand() % (max - min + 1);
                        int rad = rand()%1000+1;
                        bord = rand()%25+1;
                        fil = rand()%25+1;
                        wid = rand()%100+1;
                        op = rand()%2;
                        int count = 0;

                        cout<<"Number of Objects in Database : ";
                        cin>> runs;

                        while (count < runs && runs != 0){
                            Circle *cir = new Circle(cirx, ciry, rad);
                            cir->setbordercolor(bord);
                            cir->setfillcolor(fil);
                            cir->setborderwidth(wid);
                            cir->setopacity(op);
                            database.push_back(cir);
                            //database[databasesize]->push_back(*cir);
                            count++;
                        }

                    }break;

                }count++;
            }
        }
        else if(input == 10){
            cout<< "Number of Objects in Database : "<<database.length()<<endl;

            for(int i = 0; i<database.length();i++){           //print out number of objects in database and then call draw for each node
                database.get(i)->draw();
                //database[i]->get(i).draw();
                cout<<endl;
            }
            cout<<endl;
        }
        else if(input == 11){
            cout<< "Number of Objects in Database : "<<database.length()<<endl;        //print out number of objects in database
                                                                                        //and then call svgcode for each node value
            for(int i = 0; i<database.length();i++)
                cout<< database.get(i)->svgcode();
            cout<<endl;
        }
        else if(input == 12){       //create out stream file
            ofstream outputfile;
            cout<<"Enter the filename for your .svg file: ";        //prompt for filename
            cin>>svgfile;

            if(svgfile.find(".svg") == string::npos)        //if .svg isn't already in name then add ".svg"
                svgfile = svgfile + ".svg";

            outputfile.open(svgfile);       //open file

            for(int i = 0; i<database.length();i++){                           //write data to outputfile
                outputfile<< "<?xml version=\"1.0\" standalone=\"no\"?> ";
                outputfile<< "<svg width=\"1000\" height=\"1000\" viewBox=\"-998 -996 1993 1993\" ";
                outputfile<< "version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">";
                //database->get(i).svgcode();
                outputfile<<database.get(i)->svgcode();
            }

            outputfile.close();         //close file

        }
        else if(input == 13){           //clear database structure of all nodes
            database.clear();
        }

    }

    //delete database;

    cout<<"End of program."<<endl;      //print out program is done

    return 0;
}

void menu(){
    cout<<"1. Add Rectangle"<<endl;             //menu prompt
    cout<<"2. Add Square"<<endl;
    cout<<"3. Add Triangle"<<endl;
    cout<<"4. Add Circle"<<endl;
    cout<<"5. Add Random Rectangles"<<endl;
    cout<<"6. Add Random Squares"<<endl;
    cout<<"7. Add Random Triangles"<<endl;
    cout<<"8. Add Random Circles"<<endl;
    cout<<"9. Add Random Objects"<<endl;
    cout<<"10. View Object Database"<<endl;
    cout<<"11. View Object Database in SVG Format"<<endl;
    cout<<"12. Save SVG File"<<endl;
    cout<<"13. Clear Shape Database"<<endl;
    cout<<"14. Quit"<<endl;
    cout<<"Choice : ";
}

void bordercolors(){    //prompt for choice of colors
    cout<<"1: black\t\t2: blue\t\t3: brown\t\t4: cyan\t\t5: darkblue"<<endl;
    cout<<"6: darkcyan\t\t7: darkgray\t\t8:darkgreen\t\t9: darkorange\t\t10: darkred"<<endl;
    cout<<"11: gold\t\t12: gray\t\t13: green\t\t14:lightcyan\t\t15: lightgray"<<endl;
    cout<<"16: lightgreen\t\t17: magenta\t\t18:maroon\t\t19: navyt\t\t20: orange"<<endl;
    cout<<"21: purple\t\t22: red\t\t23: violet\t\t24: yellow\t\t25: transparent"<<endl;
    cout<<"Select border colors: ";
}

void fillcolors(){          //prompt for choice of colors
    cout<<"1: black\t\t2: blue\t\t3: brown\t\t4: cyan\t\t5: darkblue"<<endl;
    cout<<"6: darkcyan\t\t7: darkgray\t\t8:darkgreen\t\t9: darkorange\t\t10: darkred"<<endl;
    cout<<"11: gold\t\t12: gray\t\t13: green\t\t14:lightcyan\t\t15: lightgray"<<endl;
    cout<<"16: lightgreen\t\t17: magenta\t\t18:maroon\t\t19: navyt\t\t20: orange"<<endl;
    cout<<"21: purple\t\t22: red\t\t23: violet\t\t24: yellow\t\t25: transparent"<<endl;
    cout<<"Select fill colors: ";
}
