#include "adafruit_1431_Obj.h"


adafruit_1431_Obj::adafruit_1431_Obj(byte inCS,byte inRST)
  :displayObj(true,true,false,true,false) {

  theOLED = NULL;
  cs = inCS;
  rst = inRST;
}

adafruit_1431_Obj::~adafruit_1431_Obj(void) {

    if (theOLED) { 
      delete theOLED;
      theOLED = NULL;
    }
  }


int  adafruit_1431_Obj::width(void)																							{ return theOLED->width(); }
int  adafruit_1431_Obj::height(void)																						{ return theOLED->height(); }

  
bool adafruit_1431_Obj::begin(void) { 

  theOLED = new Adafruit_SSD1351(cs, LC_DC, rst);
  if (theOLED!=NULL) {
    theOLED->begin();
    return true;
  }
  return false;
}


void adafruit_1431_Obj::setRotation(byte inRotation)      															{ theOLED->setRotation(inRotation); }
void adafruit_1431_Obj::setTextColor(colorObj* inColor)   															{ theOLED->setTextColor(dim16(inColor)); }
void adafruit_1431_Obj::setTextColor(colorObj* tColor,colorObj* bColor)											{ theOLED->setTextColor(dim16(tColor),dim16(bColor)); }
void adafruit_1431_Obj::setTextSize(byte inSize)          															{ theOLED->setTextSize(inSize); }
void adafruit_1431_Obj::setTextWrap(boolean wrap)         															{ theOLED->setTextWrap(wrap); }
void adafruit_1431_Obj::setFont(const GFXfont* font) 																	{ theOLED->setFont(font); }
void adafruit_1431_Obj::setCursor(int x,int y)        																{ theOLED->setCursor(gX(x),gY(y)); }
void adafruit_1431_Obj::drawText(const char* inText)            													{ theOLED->print(inText); }
void adafruit_1431_Obj::fillScreen(colorObj* inColor)     															{ theOLED->fillScreen(dim16(inColor));}
void adafruit_1431_Obj::fillRect(int x,int y,int width,int height,colorObj* inColor)						{ theOLED->fillRect(gX(x),gY(y), width, height,dim16(inColor)); }
void adafruit_1431_Obj::fillRect(rect* aRect,colorObj* inColor)													{ theOLED->fillRect(gX(aRect->x),gY(aRect->y), aRect->width, aRect->height,dim16(inColor)); }
void adafruit_1431_Obj::drawRect(int x,int y,int width,int height,colorObj* inColor)						{ theOLED->drawRect(gX(x),gY(y), width, height,dim16(inColor)); }
void adafruit_1431_Obj::drawRect(rect* aRect,colorObj* inColor)													{ theOLED->drawRect(gX(aRect->x),gY(aRect->y), aRect->width, aRect->height,dim16(inColor)); }
void adafruit_1431_Obj::fillRoundRect(int x,int y,int width,int height,int radius,colorObj* inColor)	{ theOLED->fillRoundRect(gX(x),gY(y),width,height,radius,dim16(inColor)); }
void adafruit_1431_Obj::fillRoundRect(rect* aRect,int radius,colorObj* inColor)								{ theOLED->fillRoundRect(gX(aRect->x),gY(aRect->y),aRect->width,aRect->height,radius,dim16(inColor)); }
void adafruit_1431_Obj::drawRoundRect(int x,int y,int width,int height,int radius,colorObj* inColor)	{ theOLED->drawRoundRect(gX(x),gY(y),width,height,radius,dim16(inColor)); }
void adafruit_1431_Obj::drawRoundRect(rect* aRect,int radius,colorObj* inColor)								{ theOLED->drawRoundRect(gX(aRect->x),gY(aRect->y),aRect->width,aRect->height,radius,dim16(inColor)); }
void adafruit_1431_Obj::drawCircle(int x,int y,int diam, colorObj* inColor) 									{ drawRoundRect(gX(x),gY(y),diam,diam,diam/2,inColor); }
void adafruit_1431_Obj::drawCircleHelper(int x,int y,int rad,byte corner,colorObj* inColor)				{ theOLED->drawCircleHelper(gX(x),gY(y),rad,corner,dim16(inColor)); }
void adafruit_1431_Obj::fillCircle(int x,int y,int diam, colorObj* inColor) 									{ fillRoundRect(gX(x),gY(y),diam,diam,diam/2,inColor); }
void adafruit_1431_Obj::drawTriangle(point* pt0,point* pt1,point* pt2,colorObj* inColor) 					{ theOLED->drawTriangle(gP(pt0).x,gP(pt0).y,gP(pt1).x,gP(pt1).y,gP(pt2).x,gP(pt2).y,dim16(inColor)); }
void adafruit_1431_Obj::fillTriangle(point* pt0,point* pt1,point* pt2,colorObj* inColor)					{ theOLED->fillTriangle(gP(pt0).x,gP(pt0).y,gP(pt1).x,gP(pt1).y,gP(pt2).x,gP(pt2).y,dim16(inColor)); }
void adafruit_1431_Obj::drawVLine(int x,int y,int height,colorObj* inColor) 									{ theOLED->drawFastVLine(gX(x),gY(y),height,dim16(inColor)); }
void adafruit_1431_Obj::drawHLine(int x,int y,int width,colorObj* inColor) 									{ theOLED->drawFastHLine(gX(x),gY(y),width,dim16(inColor)); }
void adafruit_1431_Obj::drawLine(int x,int y,int x2,int y2,colorObj* inColor) 								{ theOLED->drawLine(gX(x),gY(y),gX(x2),gY(y2),dim16(inColor)); }
void adafruit_1431_Obj::drawPixel(int x,int y,colorObj* pColor) 													{ theOLED->drawPixel(gX(x),gY(y),pColor->getColor16()); }


 
