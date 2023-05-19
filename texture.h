#ifndef TEXTURE_HEADERS
#define TEXTURE_HEADERS

class LTexture
{
public:
    LTexture();
    ~LTexture();
    bool loadFromFile(std::string path);
    void free();
    bool loadFromRenderedText(std::string textureText, SDL_Color textColor);
    void setColor(Uint8 red, Uint8 green, Uint8 blue);
    void setBlendMode(SDL_BlendMode blending);
    void setAlpha(Uint8 alpha);

    void render(int x, int y);
    int getWidth();
    int getHeight();

private:

    SDL_Texture* mTexture;

    int mWidth;
    int mHeight;
};


#endif 
