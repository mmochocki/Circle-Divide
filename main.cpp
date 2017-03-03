#include <iostream>
#include <math.h>
#include <allegro.h>
#include <stdio.h>
#include <string>

using namespace std;

double srednica;
double ileCzesci;
double stopnie;
double r;
double wsp[1300][2];
double a;
double x, y;
double stopnieIteracja = 0.0;
double pixelTab[1300][2];
char konwersja[20];
char konwersjaX[20];
char konwersjaY[20];
string s1;
string s2;


void pobierzDane()
{
    cout << "Srednica: ";
    cin >> srednica;
    cout << "Czesci: ";
    cin >> ileCzesci;

    //ileCzesci += 5;
}

void zamienNaStopnie()
{
    stopnie = 360.0 / ileCzesci;
    cout << "Kat: " << stopnie;
    stopnie = M_PI * stopnie/180;
    cout << ", w Rad: " << stopnie << endl;
}

void obliczPromien()
{
    r = srednica / 2.0;
    cout << "Promien: " << r << endl;
}
void oblicz()
{
    y = sin(stopnieIteracja) * r;
    x = cos(stopnieIteracja) * r;

}


void wyznaczWspolrzedne()
{

    for (int i = 0; i < ileCzesci; i++)
    {
        stopnieIteracja = stopnieIteracja + stopnie;
        oblicz();
        wsp[i+1][1] = x;
        wsp[i+1][2] = y;
    }
}

void wypiszWspolrzedne()
{
    for (int i = 0; i < ileCzesci; i++)
    {
        cout<< "Wsp " << i + 1 << " :" ;
        cout << " X: " << wsp[i+1][1] << " Y: " << wsp[i+1][2] << endl;
    }

}


void zamienNaPixele()
{
    for (int i = 0; i < ileCzesci; i++)
    {

        pixelTab[i + 1][1] = 250.0 / r * wsp[i+1][1];
        pixelTab[i + 1][2] = 250.0 / r * wsp[i+1][2];
    }


}

void wypiszTab()
{
    for (int i = 0; i < ileCzesci; i++)
    {

        cout<< endl << "Wspolrzedna " << i + 1 << " :" << endl;;
        cout << " X: " << pixelTab[i + 1][1] << " Y: " << pixelTab[i + 1][2] << endl << endl;
    }

}




int main()
{


    pobierzDane();
    zamienNaStopnie();
    obliczPromien();
    wyznaczWspolrzedne();
    wypiszWspolrzedne();
    zamienNaPixele();
    //wypiszTab();


    allegro_init();
    install_keyboard();
    set_color_depth( 16 );
    set_gfx_mode( GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0 );


    clear_to_color( screen, makecol( 255, 255, 255 ) );

    circle( screen, 400, 300, 250, makecol( 0, 0, 0 ) );
    //arc( screen, 400, 300, itofix( 64 ), itofix( 100 ), 250, makecol( 255, 0, 0 ) );
    vline( screen, 400, 0, 900, makecol( 128, 128, 128 ) );
    hline( screen, 0, 300, 900, makecol( 128, 128, 128 ) );
    for (int j = 0; j < ileCzesci; j++)
    {
        pixelTab[j + 1][2] = pixelTab[j + 1][2] * -1;
        circlefill( screen, pixelTab[j + 1][1]+400, pixelTab[j + 1][2]+300, 3, makecol( 0, 0, 0 ) );


        sprintf (konwersja, "%lf", wsp[j+1][1]);
        strcat (konwersja, "1");
        sscanf (konwersja, "%lf", &wsp[j+1][1]);
        strncpy( konwersjaX, konwersja, 6 );

        sprintf (konwersja, "%lf", wsp[j+1][2]);
        strcat (konwersja, "1");
        sscanf (konwersja, "%lf", &wsp[j+1][2]);
        strncpy( konwersjaY, konwersja, 6 );

        if (wsp[j+1][1] < 0)
        {
            textout_ex(screen,font, konwersjaX,pixelTab[j + 1][1]+345,pixelTab[j + 1][2]+300,makecol(0,0,0),-1);
            textout_ex(screen,font, konwersjaY,pixelTab[j + 1][1]+345,pixelTab[j + 1][2]+312,makecol(0,0,0),-1);
        }
        else
        {
            textout_ex(screen,font, konwersjaX,pixelTab[j + 1][1]+420,pixelTab[j + 1][2]+300,makecol(0,0,0),-1);
            textout_ex(screen,font, konwersjaY,pixelTab[j + 1][1]+420,pixelTab[j + 1][2]+312,makecol(0,0,0),-1);
        }
    }

    release_screen();
    readkey();
    allegro_exit();
    system("pause");
    return 0;
}
END_OF_MAIN()
