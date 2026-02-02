#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_gfx.h>
#include <SDL2/SDL_TTF.h>
using namespace std;

int main( int argc, char * argv[] ) {

    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER;
    /*
    SDL_INIT_VIDEO(زیرسیستم گرافیکی رو فعال میکنه.به این معنی که میتونی پنجره بسازی،رنگ بکشی،تصویر نمایش بدی)
    SDL_INIT_AUDIO (زیرسیستم صدا رو فعال میکنه،میشه صدا پخش کرد/ضبط کرد/روی صداها کار کرد)
    SDL_INIT_TIMER(میشه تایمر ساخت، تاخیر ایجاد کردو زمان رو اندازه گرفت. مثلا هر 1 ثانیه یک کار انجام شود.)
    SDL_INIT_EVENTS(سیستم رویداد هارو فعال میکنه؛مثل کلیک موس،فشار دادن کیبورد،بستن پنجره و...بدون این نمیشه دید کاربر چکار کرده)
    SDL_INIT_EVERYTHING(برای فعالسازی همشون)
    */


    Uint32 WND_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP;
    /*
    SDL_WINDOW_SHOWN(پنجره قابل مشاهده باشه و نماش داده بشه؛تگر استفاده نشه پنجره ساخته میشه ولی مخفی میمونه)
    SDL_WINDOW_FULLSCREEN_DESKTOP(پنجره رو تمام صفحه میکنه اما با رزولوشن دسکتاپ، یعنی تنظیمات مانیتور رو عوض نمیکنه و فقط پنجره رو بزرگ میکنه)
    SDL_WINDOW_FULLSCREEN(تمام صفحه واقعی که رزولوشن رو عوض میکنه)
    SDL_WINDOW_BORDERLESS(بدون حاشیه و دکمه های بستن یا کوچک کردن)
    SDL_WINDOW_RESIZABLE(قابل تغییر اندازه با موس)
    SDL_WINDOW_MINIMIZED(شروع به صورت کوچک شده)
    SDL_WINDOW_MAXIMIZED(شروع به صورت بزرگ شده)
    SDL_WINDOW_INPUT_GRABBED(موس محدود به داخل پنجره)
    SDL_WINDOW_ALWAYS_ON_TOP(همیشه روی سایر پنجره ها باشه)
    SDL_WINDOW_HIGH_PIXEL_DENSITY(یعنی تعداد پیکسل در هر اینچ خیلی بیشتره ،پس تصویر واضح تر و شارپ تر میشه)
    */

    SDL_Window *m_window;       // the OS window  (ghabe naghashi)
    SDL_Renderer *m_renderer;   // the GPU drawing context for that window   (ghalamoo)

    SDL_Init(SDL_flags);
    //SDL_Init(...) (.استsdlبرای راه اندازی اولیه کتابخانه )



    /*
     instead of the "SDL_CreateWindowAndRenderer" line we can write:

    m_window = SDL_CreateWindow(
    "My Game",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    800,
    600,
    SDL_WINDOW_SHOWN);

    // ya be shekle zir. ke in safhe namayesh be andazeye kole safhe
    SDL_DisplayMode DM;
    SDL_Window *m_window=SDL_CreateWindow(
    "name",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    DM.w,
    DM.h,
    SDL_WINDOW_FULLSCREEN_DESKTOP);


    m_renderer = SDL_CreateRenderer(
    m_window,
    -1,
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    renderer is linked to the window!
     */
    SDL_CreateWindowAndRenderer(1920, 480, WND_flags, &m_window, &m_renderer);
    //SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);  جلوی سکرین تیرینگ رو میگیرن
    SDL_RaiseWindow(m_window);

    SDL_DisplayMode DM; // این یک ساختار (struct) از SDL هست که مشخصات حالت نمایش صفحه‌نمایش رو نگه می‌داره

    SDL_GetCurrentDisplayMode(0, &DM);
    //اطلاعات حالت فعلی مانیتور رو میگیره و میریزه داخل استراکت
    //پارامتر 0شماره مانیتور اصلی است_اگر مانیتور دومی باشه میشه یک_اگر عددی بذاری که مانیتوری براش نیست خطا برمیگردونه
    //برای فهمیدن تعداد مانیتور ها: int num_displays= SDL_GetNumVideoDisplays();

    //کاربرد خط زیر: معمولا برای ساخت پنجره ای به اندازه کل صفحه است.
    int W = DM.w;
    int H = DM.h;

    //تعریف پس زمینه
    SDL_Texture *bkImg=nullptr;
    bkImg= SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_TARGET, W, H);
    SDL_SetRenderTarget(m_renderer, bkImg); // این خط به sdl میگه که از این به بعد، به‌جای اینکه داخل پنجره رسم کنی، داخل bkImg رسم کن

    //هر چی کد میخوایم تو پس زمینه باشه اینجاعه
    SDL_SetRenderTarget(m_renderer, nullptr);  // این خط یعنی باشه، تموم شد؛ دوباره روی پنجره‌ی اصلی رسم کن. بدون این خط همه چی فقط رو تکسچر میمونه و چیزی روی صفحه نمایش دیده نمیشه
    SDL_RenderCopy(m_renderer, bkImg, nullptr, nullptr); // تکسچر bkImg رو از کل خودش یعنی nullptr به کل خودش یعنی nullptr کپی میکنه. یعنی پس زمینه ای که قبلا ساختی رو الان نمایش بده
    SDL_RenderPresent(m_renderer); // بافر پشت رو میاره روی صفحه. بدون این خط چیزی دیده نمیشه

    // what color?:
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );

    /* SDL_RenderClear looks at the lines before to see what color has been defined with SDL_SetRenderDrawColor.
    whatever the color is, then it looks to the SDL_SetRenderTarget. if it is on the m_renderer then the whole
    page is gone and it will be shown as a black color (because of SDL_SetRenderDrawColor color); but if the
    SDL_SetRenderTarget is on bkImg then just the texture will be deleted. if we don't write this line then the pictures
    will az saro koole ham bala miran*/
    SDL_RenderClear( m_renderer );


    //SDL_RenderDrawLine(m_renderer, x1, y1, x2, y2) : رسم خط با رنگ مشخص شده
    //SDL_RenderDrawPoint(m_renderer, x, y);  : رسم نقطه
    //SDL_Rect rect1={x1, y1, x2, y2};  SDL_RenderFillRect(m_renderer, &rect1);  : رسم مستطیل توپر
    //SDL_Rect rect2={x1, y1, x2, y2};  SDL_RenderDrawRect(m_renderer, &rect2);  : رسم کادر مستطیلی
    //SDL_Point points[]={{x1,y1},{x2,y2},{x3,y3}};   SDL_RenderDrawPoints(m_renderer, points, 3);  : رسم چند نقطه
    //SDL_Point points2[]={{x1,y1},{x2,y2},{x3,y3}};    SDL_RenderDrawLines(m_renderer, points2, 3);  : هر نقطه رو به نقطه بعدی وصل میکنه و خط میکشه

    /* **blend mode?  :  اگر اینو استفاده نکنیم و مثلا پس زمینه قرمز باشه و بخوایم یه مستطیل با توابع بالا بکشیم که آلفاش کمتر از 255 باشه
        مستطیل عملا کامل ابی نمایش داده میشه و الفای کمتر مثل اینکه تاثیری نداره و پس زمینه قرمز کاملا پنهان میشه. ولی با فعال کردنش مستطیل
        نیمه شفاف میشه و پس زمینه قرمز از لای ابی دیده میشه و رنگ ترکیبی بنفش مایل به ابی میشه. خالا چطور فعالش کنیم؟ قبل رسم جمله زیر را مینویسیم
        SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);
        پیشفرض دستگاه SDL_BLENDMODE-NONE
        ترکیب عادی با شفافیت : SDL_BLENDMODE_BLEND
        جمع کردن رنگ ها که روشن تر میشه : SDL_BLENDMODE_ADD
        ضرب کردن رنگ ها که تیره تر میشه : SDL_BLENDMODE_MOD
    */

    // this line should be used only onced in each frame
    SDL_RenderPresent( m_renderer );


    // giving a color to a specific pixel
    //pixelColor(m_renderer,x,y,0xcolor);
    //pixelRGBA(m_renderer,x,y,r,g,b);
    //pixel(m_renderer,x,y);  : تنظیم رنگ با SDL_SetRenderDrawColor( m_renderer, r, g, b,a);


    // DRAWING A LINE
    aalineRGBA(m_renderer, 50, 50, 400, 500, 255, 0, 0, 255);
    //aalineColor(m_renderer, x1, y1, x2, y2, 0xcolor)  :  با این دو تا اولی حط صاف و صوفه
    //lineColor(m_renderer, x1, y1, x2, y2, 0xcolor);

    //lineRGBA(m_renderer, x1, y1, x2, y2, r, g, b, a);  : با این دوتا دومی خط یکم پیکسل پیکسله
    //hlineRGBA(m_renderer, x1, x2, y, r, g, b, a);

    //hlineColor(m_renderer, x1, x2, y, 0xcolor);  : خط افقی میکشن این دوتا
    //vlineColor(m_renderer, x, y1, y2, 0xcolor);

    //vlineRGBA(m_renderer, x, y1, y2, g, b, a);  : خط عمودی میکشن این دوتا
    //thickLineColor(m_renderer, x1,y1,x2,y2,width,0xcolor);
    //thickLineRGBA(m_renderer, x1,y1,x2,y2,width,r,g,b,a);  :  خط با ضخامت دلخواه

    //رسم منحنی بزیه  **
    /*Sint16 vx[]={xi, x1, x2, xf};   Sint16 vy[]={yi, y1, y2, yf};   :  اولی نقطه شروع و اخری نقطه پایانه و دوتا وسطی نقاطی ان که منحنی به سمتشون کشیده میشه و منحنی وار میشه
     bezierRGBA(m_renderer, vx, vy, numberOfDots, flatness,r,g,b,a); * /

    //رسم بیضی  **
    filledEllipseColor(m_renderer, 100, 100, 100, 50, 0x80FF0000); //توپر
    //filledEllipseRGBA(m_renderer, x, y, rx, ry, r, g, b, a);  : توپر

    //aaellipseRGBA(m_renderer, x, y, rx, ry, r, g, b, a);
    //aaellipseColor(m_renderer, x, y, rx, ry, 0xcolor);  : این دو تا بیضی تو خالی میکشن و صاف و صوفه خطاش

    //ellipseColor(m_renderer, x, y, rx, ry, r, g, b, a);
    //ellipseRGBA(m_renderer, x, y, rx, ry, 0xcolor); : این دوتا هم توخالی ولی پیکسلی اند

    //رسم دایره  **
    // filledCircleColor(m_renderer, x, y, R, 0xcolor);
    // filledCircleRGBA(m_renderer, x, y, R, r, g, b, a);
    // aacircleRGBA(m_renderer, x, y, R, r, g, b, a);
    // aacircleColor(m_renderer, x, y, R, 0xcolor);
    //circleColor(m_renderer, x, y, R, 0xcolor);
    //circleRGBA(m_renderer, x, y, R, r, g, b, a);

    //رسم مستطیل  **
    /*SDL_Rect rects[]={{x1,y1,x2,y2},{x1,y1,x2,y2}}
     SDL_SetRenderDrawColor(m_renderer, r,g,b,a);
     SDL_RenderDrawRect(m_renderer, &rect[0]);  : یک مستطیل توخالی
     SDL_RenderFillRect(m_renderer, &rect[1]);  : یک مستطیل توپر
     SDL_RenderDrawRects(m_renderer, rects, numberOfRects);  : رسم چند مستطیل توخالی
     SDL_RenderFillRects(m_renderer, rects, numberOfRects);  : رسم چند مستطیل توپر
     */
    //rectangleRGBA(m_renderer, x1,y1,x2,y2,r,g,b,a);
    //rectangleColor(m_renderer, x1,y1,x2,y2,0xcolor);
    //roundedRectangleRGBA(m_renderer, x1,y1,x2,y2,R,r,g,b,a);
    //roundedRectangleColor(m_renderer, x1,y1,x2,y2,R,0xcolor);
    //boxRGBA(m_renderer,x1,y1,x2,y2,r,g,b,a);
    //boxColor(m_renderer, x1,y1,x2,y2,0xcolor);
    //roundedBoxRGBA(m_renderer, x1,y1,x2,y2,R,r,g,b,a);
    //roundedBoxColor(m_renderer, x1,y1,x2,y2,R,0xcolor);

    //رسم سهمی  **
    //arcColor(m_renderer, x, y, R, startdegree, enddegree,0xcolor);
    //arcRGBA(m_renderer, x, y, R, startdegree, enddegree, r,g,b,a);

    //نوشتن متن  **
    //characterColor(m_renderer,x,y,character,0xcolor);
    //characterRGBA(m_renderer,x,y,character,r,g,b,a);  : فقط یک کارکتر
    //const char * text ="your text";  متن انگلیسی
    //stringRGBA(m_renderer, x, y, text, r,g,b,a);
    //stringColor(m_renderer, x, y, text, 0xcolor);  : بدون فونت و با یک اندازه مشخص
    //textColor(m_renderer, x,y,text,font,font_size,0xcolor);
    //textRGBA(m_renderer, x,y,text,font,font_size,r,g,b,a);  : با فونت و اندازه دلخواه
    //Uint16 textUTF[]= {0xFEB0,0xFEE3,0xFE8E, 0xFEE0, 0xFEB3}; متن فارسی
    //textUTFColor(m_renderer, x, y, const Uint16 *text, const char *font, font_size, 0xcolor);
    //textUTFRGBA(m_renderer, x, y, const Uint16 *text, const char *font, font_size,r,g,b,a);  : برای زمانی که میخوایم متن فارسی بنویسیم

    //رسم قطاع دایره
    //filledPieColor(m_renderer, x, y, R, startdegree, enddegree, 0xcolor);
    //filledPieRGBA(m_renderer, x, y, R, startdegree, enddegree, r,g,b,a);
    //pieColor(m_renderer, x, y, R, startdegree, enddegree, 0xcolor);
    //pieRGBA(m_renderer, x, y, R, startdegree, enddegree, r,g,b,a;

    //برای مکث داشتن بین ترسیم ها  **
    SDL_Delay( 1 );

    //صبر کن تا یه کلید زده شه
    SDL_Event *e = new SDL_Event();
    e->type=0;  //تا مقدار رندومی نیفته توش
    //SDL_Event یک استراکت است که اطلاعات رویدادها را نگه میدارد
    while(e->type != SDL_KEYDOWN)
        SDL_PollEvent(e);  /*صف رویدادها را بررسی میکند و اگر رویدادی وجود داشته باشد،
                                  ان را برمیدارد و داخل ایونت تعریف شده میریزد.اگر رویداد بود 1
                                  و اگر نبود 0 برمیگرداند*/
    e->type=0; //پاک کردن رویداد قبلی. اگه نزنیم ممکنه دوباره از رویداد قبلی استفاده شه


    //بستن صفحه ساخته شده
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
    IMG_Quit();
    SDL_Quit();

    return 0;
}