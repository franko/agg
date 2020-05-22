// This example shows how to create a SDL_Surface* with the data loaded from an image
// file with the stb_image.h library (https://github.com/nothings/stb/)

// the color format you request stb_image to output,
// use STBI_rgb if you don't want/need the alpha channel
#include "SDL_surface.h"
#include "SDL_log.h"
#include "stb_image.h"

int main() {
  int req_format = STBI_rgb_alpha;
  int width, height, orig_format;
  unsigned char* data = stbi_load("./test.png", &width, &height, &orig_format, req_format);
  if(data == NULL) {
    SDL_Log("Loading image failed: %s", stbi_failure_reason());
    exit(1);
  }

  // Set up the pixel format color masks for RGB(A) byte arrays.
  // Only STBI_rgb (3) and STBI_rgb_alpha (4) are supported here!
  Uint32 rmask, gmask, bmask, amask;
  #if SDL_BYTEORDER == SDL_BIG_ENDIAN
    int shift = (req_format == STBI_rgb) ? 8 : 0;
    rmask = 0xff000000 >> shift;
    gmask = 0x00ff0000 >> shift;
    bmask = 0x0000ff00 >> shift;
    amask = 0x000000ff >> shift;
  #else // little endian, like x86
    rmask = 0x000000ff;
    gmask = 0x0000ff00;
    bmask = 0x00ff0000;
    amask = (req_format == STBI_rgb) ? 0 : 0xff000000;
  #endif

  int depth, pitch;
  if (req_format == STBI_rgb) {
    depth = 24;
    pitch = 3*width; // 3 bytes per pixel * pixels per row
  } else { // STBI_rgb_alpha (RGBA)
    depth = 32;
    pitch = 4*width;
  }

  SDL_Surface* surf = SDL_CreateRGBSurfaceFrom((void*)data, width, height, depth, pitch,
                                               rmask, gmask, bmask, amask);

  if (surf == NULL) {
    SDL_Log("Creating surface failed: %s", SDL_GetError());
    stbi_image_free(data);
    exit(1);
  }

  // ... do something useful with the surface ...
  // ...

  // when you don't need the surface anymore, free it..
  SDL_FreeSurface(surf);
  // .. *and* the data used by the surface!
  stbi_image_free(data);

  return 0;
}
