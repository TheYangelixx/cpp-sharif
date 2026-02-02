#include "myheader.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfx.h>

int main( int argc, char * argv[] )
{

    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP;//SDL_WINDOW_BORDERLESS ;
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;


    SDL_Init( SDL_flags );
    SDL_CreateWindowAndRenderer( 1920, 480, WND_flags, &m_window, &m_renderer );
    //Pass the focus to the drawing window
    SDL_RaiseWindow(m_window);
    //Get screen resolution
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    int W = DM.w;
    int H = DM.h;
    cout<<W<<"x"<<H<<endl;


    // Clear the window with a black background
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear( m_renderer );

    // Show the window
    SDL_RenderPresent( m_renderer );


    // Render a new color bar every 0.5 seconds
    for ( int i = 0; i < 256; i++)
    {
        aalineRGBA(m_renderer, i, 50, i, 500, i, 0, 0, 255);
        SDL_RenderPresent( m_renderer );
        SDL_Delay( 1 );
    }
    SDL_RenderPresent( m_renderer );
    /*این دستور تمام محتوایی را که از طریق دستورات رندرینگ (مانند SDL_RenderClear, SDL_RenderCopy, SDL_RenderDrawLine و غیره) بر روی بافر رندر (Render Buffer) که به m_renderer متصل است، ترسیم شده است، را به صفحه نمایش کاربر منتقل (Present) می‌کند.

به عبارت ساده‌تر:

شما تمام عناصر بازی یا برنامه خود (تصاویر، متن، خطوط) را به صورت مجازی در یک “بوم نقاشی مخفی” (بافر) می‌کشید.
SDL_RenderPresent() این “بوم نقاشی” را به صورت یک فریم کامل به مانیتور کاربر نشان می‌دهد.
اهمیت:

نمایش تغییرات: اگر این دستور فراخوانی نشود، هیچ‌یک از ترسیماتی که انجام داده‌اید، روی صفحه نمایش داده نخواهد شد.
*/

    //filledEllipseRGBA(m_renderer, 100, 100, 100, 50, 100, 200, 0, 255);

    /*   BEIZI   */
    filledEllipseColor(m_renderer, 100, 100, 100, 50, 0x80FF0000);

    /* khate ofoghi misazad          zede pixel nadarad!! yani dandane dar chap mikonad */
    hlineRGBA(m_renderer, 0, W, H/2, 0, 0, 255, 255);

    /* khat chap mikonad.   zede pixel darad                rang: RGBA */
    aalineRGBA(m_renderer, 200, 200, 400, 500, 0, 255, 0, 255);  // age adad double bedim be rgba, warning mide ama barname ejra mishe va tabdil mikone be int

    /* marboot be ketabkhane SDL_gfx   zede pixel darad          rang: HEX */
    aalineColor(m_renderer, 220, 220, 420, 520, 0xFF00FF00);

    lineColor(m_renderer, 220, 2400, 420, 540, 0xFF00FF00);  // in nesbat be aalineColor dandane darad

    int L = 500, x0=200, y0=200, n=10;
    for(int i = 0; i <= n; i++)
    {
        aalineRGBA(m_renderer, x0, y0 + i * L / n, x0 + i * L / n, y0+L, 255, 255, 255, 255);
        SDL_RenderPresent( m_renderer );
        SDL_Delay(20);
    }


    /*       this functions fo the same thing -->  stringRGBA , textRGBA , textColor, textUTFRGBA          */


    const char * text ="WELCOME TO SHARIF EE DEPARTMENT!!";

    // it's in SDL_gfx library
    stringRGBA(m_renderer, 100, 100, "Yasna is EE student in sharif EE department", 255,255,255,255);
    stringRGBA(m_renderer, 100, 190, text, 255,255,255,255);

// 1 for lazy.ttf , 2 for arial.ttf , 3 for B Roya.ttf     font ha bayad dar kenar file exe bashan
    int font =2;
    int x_position=500;
    int y_position=600;
    int R=255;
    int G =2;
    int B=3;
    int A=0.5;
    SDL_Color text_color = { 250, 250, 250};

//    textColor(m_renderer,  x_position,      y_position,      text,  font ,  24,  text_color);
//    textRGBA(m_renderer,   x_position,      y_position,      text,  font ,  24,  R,G,B,A);
    textRGBA(m_renderer, 100, 130, text, "Shabnam.ttf", 18, 0, 0 , 255, 255);

    // utf code. "character map"   baraye matne farsi
    Uint16 textUTF[]= {0xFEB0,0xFEE3,0xFE8E, 0xFEE0, 0xFEB3};   // 16 biti    araye char va string araye 8 biti bood. vali baraye inke farsi bashe bayad uni code 16 biti bashe. az 256 halat miad roo 65000 va khoorde ii halat
    textUTFRGBA(m_renderer, 100, 160, textUTF, "Shabnam.ttf", 38, 0, 255 , 255, 255);


    // this code waits and repeats the loop until any button on the keyboard is pressed. then the rest of the code will be runned
    SDL_Event *e = new SDL_Event();
    while(e->type != SDL_KEYDOWN)
        SDL_PollEvent(e);



    /*   Loading image   */


    //Texture for loading image
    int img_w, img_h;
    SDL_Rect img_rect;  /*ناحیه‌ای را روی صفحه نمایش تعریف می‌کند (موقعیت و ابعاد نهایی تصویر پس از رندر) */
    SDL_Texture* m_img = nullptr;  /*  یک اشاره‌گر به SDL_Texture که داده‌های تصویر پس از بارگذاری در حافظه GPU/RAM ذخیره می‌شوند*/
    m_img = IMG_LoadTexture(m_renderer, "golden.png");

    SDL_QueryTexture(m_img, NULL, NULL, &img_w, &img_h);   //width & height image ro begir. estekhraje abaad

    img_rect.x = 400;
    img_rect.y = 200;
    img_rect.w = img_w * 1;
    img_rect.h = img_h * 1;

    /*  kodam bakhsh az texture bayad copy shavad */
    SDL_Rect img_src;
    img_src.x=60;//img_w/10;
    img_src.y=60;//img_h/10;
    img_src.w=img_w/2;
    img_src.h=img_h/3;
    // copy the texture to the rendering context

    /*کل ناحیه تعریف شده در &img_src از تکسچر m_img را برداشته و آن را در ناحیه تعریف شده در &img_rect روی بافر رندر (که فعلاً نامرئی است) می‌کشد*/
    SDL_RenderCopy(m_renderer, m_img, &img_src, &img_rect);

    /*tasvir ra khabele moshahede mikonad. */
    SDL_RenderPresent( m_renderer );

    filledEllipseRGBA(m_renderer, 1100, 400, 100, 50, 100, 200, 0, 127);
    SDL_RenderPresent( m_renderer );

    e->type = 0;
    int x=100, y=200, r=50, dx=20, dy=10;
    //Wait for a key to be pressed
    // in function ba keshidane beizi, akse zir ro pak mikone. baraye inke injoori nashe, bayad akse pas zamine ye ja zakhire beshe
    while(e->type != SDL_KEYDOWN)
    {
        SDL_PollEvent(e);
        filledEllipseRGBA(m_renderer, x, y, r,r, 255, 0, 0, 255);
        SDL_RenderPresent(m_renderer);
        SDL_Delay(50);
        //circleRGBA(........)
        filledEllipseRGBA(m_renderer, x, y, r,r, 0, 0, 0, 255);
        x+=dx;
        y+=dy;
        if(x<r||x>W-r)
            dx=-dx;
        if(y<r||y>H-r)
            dy=-dy;
    }

    //Finalize and free resources
    SDL_DestroyTexture(m_img);
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
    IMG_Quit();
    SDL_Quit();

    return 0;

}

