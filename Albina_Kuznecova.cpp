#include "TXLib.h"

//----------------------------------------------------------------------------

 void DrawSun     (int x, int y, COLORREF bodyColor, COLORREF raysColor, COLORREF eyesColor,
                  COLORREF mouthColor, double happysmile, double horizonlefteye, double horizonrighteye);
 void DrawCloud   (int x, int y, double sizeR, COLORREF bodyColor);
 void DrawTerra   (int x, int y, COLORREF bodyColor);
 void DrawHedgehog(int x, int y, COLORREF bodyColor, COLORREF eyesColor, COLORREF hairColor,
                  COLORREF mouthColor,COLORREF noseColor, COLORREF glassesColor, double surprise,
                  double noselength, double happysmile);
 void DrawTree    (int x, int y, double sizeX, double sizeY, COLORREF bodyColor, COLORREF armColor,
                   double treeheight);
 void DrawBirdRight(int x, int y, COLORREF bodyColor, COLORREF eyesColor, COLORREF wingsColor,
                  COLORREF beakColor, double legs);
 void DrawBirdLeft (int x, int y, COLORREF bodyColor, COLORREF eyesColor, COLORREF wingsColor,
                  COLORREF beakColor, double legs);
 void FlyBirdGreenWings ();
 void FlyBirdMagentaWings ();
 void FlyBirdPinkWings ();
 void FlyBirdGrayWings ();
 void DrawCabbage (int x, int y, double sizeR, COLORREF cabbageColor);
 void DrawCarrot  (int x, int y, double sizeX, double sizeY);
 void DrawBackground();
 void StartTitles ();
 void EndTitles ();
 void SunSmile ();
 void CabbagegrowLeft ();
 void Cabbagegrowtwo ();
 void Cabbagegrowthree ();
 void CabbagegrowRight ();

//----------------------------------------------------------------------------

 int main()
    {
    txCreateWindow(1500,  1000);
    txBegin();
    StartTitles();
    FlyBirdGreenWings ();
    SunSmile();
    FlyBirdMagentaWings ();
    SunSmile();
    FlyBirdPinkWings ();
    SunSmile();
    FlyBirdGrayWings ();
    SunSmile();
    CabbagegrowLeft ();
    Cabbagegrowtwo ();
    Cabbagegrowthree ();
    CabbagegrowRight ();

    CarrotgrowLeft ();
    //CarrotgrowpastLeft ();
    //CarrotgrowCenter ();
    //CarrotgrowPreRight ();
    //CarrotgrowRight ();

    DrawCarrot  (200, 820, -3,   1.5);
    DrawCarrot  (200, 780,  0.3, 0.3);
    DrawCarrot  (400, 800,  2,   2  );
    DrawCarrot  (500, 680,  0.5,-1  );
    DrawCarrot  (700, 800, -1,   2.3);

    EndTitles ();
    txEnd();
    return 0;
    }

//----------------------------------------------------------------------------

void CabbagegrowLeft ()
    {
    int    t  = 0;
    while (t <= 20)
    {
    DrawCabbage (300, 820, 1 * t%3, TX_BROWN);
    txSleep (20);
    t++;
    }
    }

//----------------------------------------------------------------------------

void Cabbagegrowtwo ()
    {
    int    t  = 0;
    while (t <= 20)
    {
    DrawCabbage (500, 800, t%4, TX_LIGHTGREEN);
    txSleep (20);
    t++;
    }
    }

//----------------------------------------------------------------------------

    void Cabbagegrowthree ()
    {
    int    t  = 0;
    while (t <= 20)
    {
    DrawCabbage (650, 800, 1 * t%3,   TX_LIGHTCYAN   );
    txSleep (20);
    t++;
    }
    }

//----------------------------------------------------------------------------

    void CabbagegrowRight ()
    {
    int    t  = 0;
    while (t <= 20)
    {
    DrawCabbage (1100, 820, 2 * t%3,   TX_LIGHTMAGENTA);
    txSleep (20);
    t++;
    }
    }
//----------------------------------------------------------------------------

void SunSmile ()
    {
    int    t  = 10;
    while (t <= 20)
    {
    DrawSun     (1200, 150, TX_YELLOW, TX_ORANGE, TX_LIGHTGREEN, TX_LIGHTMAGENTA, t, t%2, t%3);
    txSleep (20);
    t++;
    }
    }

//----------------------------------------------------------------------------

 void FlyBirdGreenWings ()

    {
    txBegin();
    int    t  =  1500;
    while (t >=    10)
    {
    DrawBackground();
    DrawBirdRight ( t, 110, TX_LIGHTCYAN, TX_RED,      TX_LIGHTGREEN, TX_GREEN,  (t-1440)/10);
    txSleep (20);
    t-=10;
    }
    txEnd();
    }
//----------------------------------------------------------------------------

 void FlyBirdMagentaWings ()

    {
    txBegin();
    int    t  =  160;
    while (t <= 1500)
    {
     DrawBackground();
     DrawBirdLeft  (t,   200, TX_LIGHTCYAN, TX_BROWN, TX_LIGHTRED, TX_LIGHTMAGENTA, (t-60)/10);
     txSleep (20);
     t+=10;
    }
    txEnd();
    }
//----------------------------------------------------------------------------

 void FlyBirdPinkWings ()

    {
    txBegin();
    int    t  =  1500;
    while (t >= - 400)
    {
     DrawBackground();
     DrawBirdRight ( t,   200, TX_LIGHTRED,  TX_ORANGE,   TX_PINK,       TX_CYAN,  (t - 1500)/20);
     txSleep (20);
     t-=10;
    }
    txEnd();
    }
//----------------------------------------------------------------------------

void FlyBirdGrayWings ()

    {
    txBegin();
    int    t  =  500;
    while (t <=  900)
    {
    DrawBackground();
    DrawBirdLeft  ( t,   200, TX_GRAY,      TX_DARKGRAY, TX_LIGHTGRAY,  TX_BLUE, (t - 470)/20);
    txSleep (20);
    t+=10;
    }
    txEnd();
    }
 //----------------------------------------------------------------------------

void DrawBackground()
    {
    txSetColor    (TX_CYAN,  4);
    txSetFillColor(TX_CYAN    );
    txRectangle   (0, 0, 1500, 1000);
    DrawSun     (1200, 150, TX_YELLOW, TX_ORANGE, TX_LIGHTGREEN, TX_LIGHTMAGENTA, 0, 2, 1);

    DrawCloud   ( 150, 100,  1,   TX_WHITE    );
    DrawCloud   ( 550, 100,  0.7, TX_LIGHTCYAN);
    DrawCloud   ( 850, 100, -1.3, TX_WHITE    );

    DrawTerra   (   5, 900, TX_GREEN);
    DrawTerra   ( 600, 900, TX_GREEN);

    DrawHedgehog( 400, 600, TX_PINK,     TX_BLUE,  TX_MAGENTA,  TX_RED,   TX_BLACK,
               TX_BROWN,      1,  0,   0);
    DrawHedgehog( 850, 700, TX_LIGHTGRAY,TX_BLACK, TX_LIGHTRED, TX_PINK,  TX_CYAN,
               TX_LIGHTGREEN, 2, 15,  10);

    DrawTree    (  25, 900, 1, 1, TX_LIGHTGRAY, TX_BLACK, 0.4);
    DrawTree    (1200, 900, 1, 1, TX_LIGHTGRAY, TX_BLACK, 1  );
    DrawTree    (1500, 900, 1, 1, TX_LIGHTGRAY, TX_BLACK, 0.5);
    DrawTree    (1400, 900, 1, 1, TX_LIGHTGRAY, TX_BLACK, 0.3);
    }

//----------------------------------------------------------------------------

void DrawSun (int x, int y, COLORREF bodyColor, COLORREF raysColor, COLORREF eyesColor,
              COLORREF mouthColor, double happysmile, double horizonlefteye, double horizonrighteye)
    {
    txSetColor     (bodyColor, 4   );
    txSetFillColor (bodyColor      );
    txCircle (x,        y,       50);

    txSetColor     (TX_BLACK, 4);
    txSetFillColor (eyesColor  );
    txCircle (x -  10,  y -  5,   5*horizonlefteye );
    txCircle (x +  20,  y -  5,   5*horizonrighteye);

    txSetColor     (mouthColor, 4);
    txSetFillColor (mouthColor   );
    txLine   (x -  20,  y + 20,              x -  5,  y + 20 + happysmile);
    txLine   (x -   5,  y + 20 + happysmile, x + 30, y + 20);

    txSetColor     (raysColor, 4);
    txSetFillColor (raysColor   );
    txLine   (x - 100,  y - 100, x - 30,  y -  40);
    txLine   (x,        y - 100, x,       y -  50);
    txLine   (x + 30,   y - 40,  x + 100, y - 100);
    txLine   (x + 50,   y,       x + 100, y      );
    txLine   (x + 40,   y + 30,  x + 100, y + 100);
    txLine   (x,        y + 50,  x,       y + 100);
    txLine   (x - 40,   y + 30,  x - 100, y + 100);
    txLine   (x - 100,  y,       x - 50,  y      );
    }

//----------------------------------------------------------------------------

void DrawCloud (int x, int y,double sizeR, COLORREF bodyColor)
    {
    txSetColor     (bodyColor, 1  );
    txSetFillColor (bodyColor     );
    txCircle (x - 20, y,  75*sizeR);
    txCircle (x + 50, y,  50*sizeR);
    txCircle (x - 70, y,  50*sizeR);
    }

//----------------------------------------------------------------------------

void DrawTerra (int x, int y, COLORREF bodyColor)
    {
    txSetColor     (bodyColor, 4);
    txSetFillColor (bodyColor   );
    POINT terra [5] = {{x, y}, {x + 50, y - 50}, {x + 400, y - 150}, {x + 750, y - 50},  {x + 1000, y}};
    txPolygon (terra, 5);
    }

//----------------------------------------------------------------------------

void DrawBirdRight (int x, int y, COLORREF bodyColor, COLORREF eyesColor, COLORREF wingsColor,
               COLORREF beakColor, double legs)
    {
    txSetColor     (TX_BLACK, 2);
    txSetFillColor (bodyColor  );
    txCircle  (x + 100, y + 45, 25);
    txCircle  (x + 75,  y,      25);

    txSetColor     (TX_BLACK, 1);
    txSetFillColor (eyesColor  );
    txCircle  (x + 70,  y, 5   );

    txSetColor     (TX_BLACK, 3);
    txSetFillColor (TX_BLACK   );
    txLine    (x + 50  - legs/2,  y + 120, x + 100, y + 70);
    txLine    (x + 100 + legs/2,  y + 120, x + 100, y + 70);

    txSetColor     (TX_BLACK, 2);
    txSetFillColor (wingsColor );
    POINT wings [5] = {{x + 100, y + 20}, {x + 150, y - 30}, {x + 150, y - 20},
                      {x + 200, y - 20}, {x + 100, y + 70}};
    txPolygon      (wings, 5);

    txSetColor     (TX_BLACK, 2);
    txSetFillColor (beakColor  );
    POINT beak [3] = {{x, y}, {x + 60, y - 20}, {x + 50, y}};
    txPolygon (beak, 3);
    }

//----------------------------------------------------------------------------

void DrawBirdLeft (int x, int y, COLORREF bodyColor, COLORREF eyesColor, COLORREF wingsColor,
               COLORREF beakColor, double legs)
    {
    txSetColor     (TX_BLACK, 2);
    txSetFillColor (bodyColor  );
    txCircle  (x + 100, y + 45, 25);
    txCircle  (x + 120, y +  5, 25);

    txSetColor     (TX_BLACK, 1);
    txSetFillColor (eyesColor  );
    txCircle  (x + 120,  y, 5   );

    txSetColor     (TX_BLACK, 3);
    txSetFillColor (TX_BLACK   );
    txLine    (x + 50  - legs/2,  y + 120, x + 100, y + 70);
    txLine    (x + 100 + legs/2,  y + 120, x + 100, y + 70);

    txSetColor     (TX_BLACK, 2);
    txSetFillColor (wingsColor );
    POINT wings [5] = {{x + 100, y + 20}, {x + 50, y - 30}, {x + 50, y - 20},
                      {x , y - 20}, {x + 100, y + 70}};
    txPolygon      (wings, 5);

    txSetColor     (TX_BLACK, 2);
    txSetFillColor (beakColor  );
    POINT beak [3] = {{x + 205, y + 20}, {x + 145, y}, {x + 145, y + 20}};
    txPolygon (beak, 3);
    }

//----------------------------------------------------------------------------

void DrawHedgehog (int x, int y, COLORREF bodyColor, COLORREF eyesColor, COLORREF hairColor,
                    COLORREF mouthColor,COLORREF noseColor, COLORREF glassesColor, double surprise,
                    double noselength, double happysmile)
    {
    txSetColor     (bodyColor, 2);
    txSetFillColor (bodyColor   );
    txCircle (x,      y, 100    );

    txSetColor     (glassesColor, 3);
    txCircle (x - 50, y,  25);
    txCircle (x + 50, y,  25);
    txLine   (x - 25, y,      x + 25, y     );

    txSetColor     (eyesColor, 2);
    txSetFillColor (eyesColor   );
    txCircle (x - 50, y,   5*surprise);
    txCircle (x + 50, y,   5*surprise);

    txSetColor     (noseColor, 2);
    txSetFillColor (noseColor   );
    txCircle (x,      y + 20 + noselength, 8);

    txSetColor     (mouthColor, 4);
    txSetFillColor (mouthColor   );
    txLine   (x - 25, y + 50,              x     , y + 50 + happysmile);
    txLine   (x     , y + 50 + happysmile, x + 25, y + 50);

    txSetColor     (bodyColor, 2);
    txSetFillColor (bodyColor   );
    txRectangle (x - 75, y + 70, x - 50, y + 170);
    txRectangle (x + 50, y + 70, x + 75, y + 170);

    txSetColor     (bodyColor, 2);
    txSetFillColor (bodyColor   );
    POINT handleft [4] =  {{x - 150, y + 50}, {x - 100, y + 20}, {x -  80, y + 40}, {x - 140, y + 75}};
    txPolygon (handleft, 4);

    txSetColor     (bodyColor, 2);
    txSetFillColor (bodyColor   );
    POINT handright [4] = {{x +  90, y + 40}, {x + 125, y + 75}, {x + 140, y + 50}, {x + 100, y + 10}};
    txPolygon (handright, 4);

    txSetColor     (TX_BLACK, 2);
    txSetFillColor (hairColor  );
    POINT hairleft [5] =  {{x - 100, y}, {x - 150, y - 50}, {x - 90, y - 60}, {x - 100, y - 100},
                          {x -  25, y - 100}};
    txPolygon (hairleft, 5);

    txSetColor     (TX_BLACK, 2);
    txSetFillColor (hairColor  );
    POINT hairright [5] = {{x +  25, y - 100}, {x + 100, y - 100}, {x + 85, y - 60}, {x + 150, y - 50},
                          {x + 100, y}};
    txPolygon (hairright, 5);

    txSetColor     (TX_BLACK, 2);
    txSetFillColor (hairColor  );
    POINT haircenter[3] = {{x -  25, y - 100}, {x, y - 150}, {x + 25, y - 100}};
    txPolygon (haircenter, 3);
    }

//----------------------------------------------------------------------------

void DrawTree(int x, int y, double sizeX, double sizeY, COLORREF bodyColor, COLORREF armColor,
               double treeheight)
    {
    txSetColor     (armColor, 2);
    txSetFillColor (bodyColor  );
    POINT tree [3] = {{ROUND(x - 50*sizeX), ROUND(y*sizeY)},
    {ROUND(x*sizeX),(ROUND(y*sizeY - 600))* ROUND(treeheight)}, {ROUND(x*sizeX + 50), ROUND(y*sizeY)}};
    txPolygon (tree, 3);
    txLine   (x +  8*sizeX, y - 550*sizeY, x +  40*sizeX, y - 580*sizeY);
    txLine   (x +  9*sizeX, y - 550*sizeY, x +  50*sizeX, y - 530*sizeY);
    txLine   (x + 10*sizeX, y - 450*sizeY, x + 100*sizeX, y - 400*sizeY);
    txLine   (x + 12*sizeX, y - 500*sizeY, x +  80*sizeX, y - 500*sizeY);
    txLine   (x + 20*sizeX, y - 500*sizeY, x +  50*sizeX, y - 450*sizeY);
    txLine   (x + 27*sizeX, y - 300*sizeY, x +  80*sizeX, y - 360*sizeY);
    txLine   (x + 30*sizeX, y - 250*sizeY, x + 100*sizeX, y - 300*sizeY);
    txLine   (x -  8*sizeX, y - 550*sizeY, x -  40*sizeX, y - 580*sizeY);
    txLine   (x -  9*sizeX, y - 550*sizeY, x -  50*sizeX, y - 530*sizeY);
    txLine   (x - 10*sizeX, y - 450*sizeY, x - 100*sizeX, y - 400*sizeY);
    txLine   (x - 12*sizeX, y - 500*sizeY, x -  80*sizeX, y - 500*sizeY);
    txLine   (x - 20*sizeX, y - 500*sizeY, x -  50*sizeX, y - 450*sizeY);
    txLine   (x - 27*sizeX, y - 300*sizeY, x -  80*sizeX, y - 360*sizeY);
    txLine   (x - 30*sizeX, y - 250*sizeY, x - 100*sizeX, y - 300*sizeY);
    }

//----------------------------------------------------------------------------

void DrawCabbage(int x, int y,double sizeR, COLORREF cabbageColor)
    {
    txSetColor     (TX_GREEN,  3);
    txSetFillColor (cabbageColor);
    txCircle (x,      y - 20, 25*sizeR);
    txCircle (x + 20, y,      35*sizeR);
    txCircle (x - 20, y,      35*sizeR);
    txCircle (x,      y,      25*sizeR);
    txCircle (x,      y + 20, 35*sizeR);
    }

 //----------------------------------------------------------------------------

void DrawCarrot(int x, int y, double sizeX, double sizeY)
    {
    txSetColor     (TX_RED, 3);
    txSetFillColor (TX_ORANGE);
    POINT carrot [3] = {{x, y}, {ROUND(x + 50*sizeX), y}, {ROUND(x + 25*sizeX), ROUND(y + 70*sizeY)}};
    txPolygon (carrot, 3);

    txSetColor     (TX_LIGHTGREEN, 3);
    txSetFillColor (TX_LIGHTGREEN);
    txLine   (x,            y - 50*sizeY, x + 25*sizeX, y);
    txLine   (x + 25*sizeX, y - 50*sizeY, x + 25*sizeX, y);
    txLine   (x + 50*sizeX, y - 50*sizeY, x + 25*sizeX, y);
    }

 //----------------------------------------------------------------------------

void StartTitles()
    {
    int t = 0;
    while (t <= 185)
    {
    txClear();
    txSetColor    (TX_CYAN,  4);
    txSetFillColor(TX_CYAN    );
    txRectangle   (0, 0, 1500, 1000);
    DrawSun     (1200, 150, TX_YELLOW, TX_ORANGE, TX_LIGHTGREEN, TX_LIGHTMAGENTA, 10, 2, 1);
    DrawCloud   ( 150, 100,  1,   TX_WHITE    );
    DrawCloud   ( 550, 100,  0.7, TX_LIGHTCYAN);
    DrawCloud   ( 850, 100, -1.3, TX_WHITE    );
    DrawTerra   (   5, 900, TX_GREEN);
    DrawTerra   ( 600, 900, TX_GREEN);
    txSetColor (TX_YELLOW);
    txSelectFont ("Comic Sans MS", 300);
    txTextOut (-200 + t * 50, 100, "Magik");
    txSetColor (TX_YELLOW);
    txSelectFont ("Comic Sans MS", 300);
    txTextOut (900 - t * 50, 250, "hedgehog");
    txSetColor (TX_YELLOW);
    txSelectFont ("Comic Sans MS", 300);
    txTextOut (-200 + t * 50, 500, "farm");
    txSetColor (TX_YELLOW);
    txSelectFont ("Comic Sans MS", 150);
    txTextOut (900 - t * 50, 700, "by Albina Kuznecova");
    txSleep (5);
    t++;
    }
    txSetColor (TX_ORANGE);
    txSetTextAlign (TA_CENTER);
    txTextOut (750, 250, "Magik");
    txTextOut (750, 350, "hendehog");
    txTextOut (750, 450, "farm");
    txTextOut (750, 550, "by Albina Kuznecova");
    txSetTextAlign();
    txSleep (2000);
    }

 //----------------------------------------------------------------------------

void EndTitles()
    {
    txClear();
    txSetColor    (TX_CYAN,  4);
    txSetFillColor(TX_CYAN    );
    txRectangle   (0, 0, 1500, 1000);
    DrawSun     (1200, 150, TX_YELLOW, TX_ORANGE, TX_LIGHTGREEN, TX_LIGHTMAGENTA, 10, 2, 1);
    DrawCloud   ( 150, 100,  1,   TX_WHITE    );
    DrawCloud   ( 550, 100,  0.7, TX_LIGHTCYAN);
    DrawCloud   ( 850, 100, -1.3, TX_WHITE    );
    DrawTerra   (   5, 900, TX_GREEN);
    DrawTerra   ( 600, 900, TX_GREEN);
    txSetColor (TX_ORANGE);
    txSetTextAlign (TA_CENTER);
    txSelectFont ("Comic Sans MS", 300);
    txTextOut (750,250, "The End");
    txSetTextAlign();
    txSleep (2000);
    }


