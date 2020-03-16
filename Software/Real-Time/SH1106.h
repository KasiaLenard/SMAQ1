#ifndef __SH1106_H__
#define __SH1106_H__

#define rotation 0
#define BLACK 0
#define WHITE 1
#define INVERSE 2

#define SH1106_ADDRESS 0x3C // 011110+SA0+RW - 0x3C or 0x3D

// We use the 128x64 version of SH1106
#define WIDTH 128
#define HEIGHT 64

#define control 0x00

#define SH1106_SETCONTRAST 0x81
#define SH1106_DISPLAYALLON_RESUME 0xA4
#define SH1106_DISPLAYALLON 0xA5
#define SH1106_NORMALDISPLAY 0xA6
#define SH1106_INVERTDISPLAY 0xA7
#define SH1106_DISPLAYOFF 0xAE
#define SH1106_DISPLAYON 0xAF

#define SH1106_SETDISPLAYOFFSET 0xD3
#define SH1106_SETCOMPINS 0xDA

#define SH1106_SETVCOMDETECT 0xDB

#define SH1106_SETDISPLAYCLOCKDIV 0xD5
#define SH1106_SETPRECHARGE 0xD9

#define SH1106_SETMULTIPLEX 0xA8

#define SH1106_SETLOWCOLUMN 0x00  // from 0x00 to 0x0F
#define SH1106_SETHIGHCOLUMN 0x10 // from 0x10 to 0x1F

#define SH1106_SETSTARTLINE 0x40 // from 0x40 to 0x7f

#define SH1106_COLUMNADDR 0x00 // from 0x00 to 0x83
#define SH1106_PAGEADDR_1 0xB0
#define SH1106_PAGEADDR_2 0xB1
#define SH1106_PAGEADDR_3 0xB2
#define SH1106_PAGEADDR_4 0xB3
#define SH1106_PAGEADDR_5 0xB4
#define SH1106_PAGEADDR_6 0xB5
#define SH1106_PAGEADDR_7 0xB6
#define SH1106_PAGEADDR_8 0xB7

#define SH1106_COMSCANINC 0xC0
#define SH1106_COMSCANDEC 0xC8

#define SH1106_SEGREMAP 0xA0 // 0xA0 to 0xA1

#define SH1106_CHARGEPUMP 0x8B

#define SH1106_EXTERNALVCC 0x1
#define SH1106_SWITCHCAPVCC 0x2

void sh1106_init(int fd_SH1106);
void sh1106_display(int fd_SH1106);
void sh1106_clearDisplay();
void sh1106_setTextSize(int s);
void sh1106_drawPixel(int x, int y, unsigned int color);
void sh1106_write(int c);
void sh1106_drawString(string str);
void sh1106_drawChar(int x, int y, unsigned char c, int color);

int buffer[WIDTH * HEIGHT / 8] =
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0x70, 0x78, 0x3C, 0x3C, 0x1C, 0x0C, 0x0E, 0x0E, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x07, 0x03, 0x03, 0x02, 0x02, 0x02, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x04, 0x0C, 0x0C, 0x1C, 0x18, 0x38, 0x30, 0x60, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80,
        0xFC, 0xFE, 0x0F, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x04, 0x00, 0x00, 0x00,
        0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x43, 0x03, 0x21, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x07, 0x07, 0x0F, 0x1F, 0x1F, 0x0F,
        0x07, 0x02, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xC0, 0xE0, 0xF0, 0xF0, 0x78, 0x1C, 0x1C, 0x0E, 0x06, 0x02, 0x03, 0x01, 0x81, 0x80, 0x00, 0x00,
        0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x00, 0x08, 0x04, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x1E, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0x3F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0xFF,
        0xFF, 0xFF, 0xFF, 0x81, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x7E, 0xFF, 0xFF, 0xFF, 0x80, 0x00, 0x00,
        0x00, 0x00, 0x07, 0x07, 0x0F, 0x0F, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40,
        0x70, 0x7C, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x80, 0x80, 0xC0, 0xE0, 0xE0, 0xE0, 0xC0, 0xC0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x07, 0x3F, 0x0F, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0xF8, 0xF8, 0xF8, 0x1C, 0x0C, 0x04, 0x04,
        0x07, 0x07, 0x07, 0x07, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0x7E, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFC, 0xFC, 0x8C, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xF8, 0xF8, 0xFC, 0xFE, 0x06, 0x00, 0x00, 0x00, 0x00, 0x90, 0xF8, 0xFC, 0x7C, 0x0E, 0x04, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xF8, 0xF8, 0x0C, 0x04, 0x04, 0x04, 0x04, 0xC4, 0xFC, 0xFC,
        0xFC, 0x04, 0x00, 0x00, 0x40, 0x70, 0x70, 0x70, 0x60, 0x40, 0xC0, 0x80, 0x80, 0x80, 0x00, 0x00,
        0x02, 0x03, 0x07, 0x07, 0x87, 0x8F, 0x8F, 0x8F, 0x7F, 0x7F, 0x3F, 0x3F, 0x3F, 0x7F, 0xFE, 0xFE,
        0xF8, 0xF0, 0xF0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x03, 0x02, 0x02, 0x04,
        0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x02, 0x02, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
        0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x02, 0x02, 0x02, 0x02,
        0x02, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03,
        0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x04, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03,
        0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
        0x01, 0x01, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

#endif