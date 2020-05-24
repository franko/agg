#include <new>
#include <stdio.h>

#include "SDL.h"
#include "SDL_error.h"
#include "SDL_log.h"
#include "SDL_surface.h"

#include "font_render_lcd.h"

#define RENDERER_PIXEL_SIZE 3
#define RENDERER_PIXEL_FORMAT SDL_PIXELFORMAT_RGB24

extern "C" int main(int argc, char *argv[]);

#if defined(_WIN32) || defined(WIN32)
static const char *os_font_directory = "C:/Windows/fonts";
static const char *font_filename = "georgia.ttf";
#else
static const char *os_font_directory = "/usr/share/fonts/truetype";
const char *font_filename = "liberation/LiberationSerif-Regular.ttf";
#endif

static char *path_join(const char *dir, const char *filename) {
    const int path_len = strlen(dir), filename_len = strlen(filename);
    const int len = path_len + 1 + filename_len + 1;
    char *full_name = new char[len];
    memcpy(full_name, dir, path_len);
    memcpy(full_name + path_len, "/", 1);
    memcpy(full_name + path_len + 1, filename, filename_len);
    full_name[len - 1] = 0;
    return full_name;
}

static SDL_Surface *SetupNewRendererSurface(agg::rendering_buffer& ren_buf, int width, int height) {
    fprintf(stderr, "new width: %d height: %d\n", width, height);
    SDL_Surface *surface = SDL_CreateRGBSurfaceWithFormat(0, width, height,
        RENDERER_PIXEL_SIZE * 8, RENDERER_PIXEL_FORMAT);
    SDL_SetSurfaceBlendMode(surface, SDL_BLENDMODE_NONE);
    ren_buf.attach((agg::int8u *) surface->pixels, width, height, -width * RENDERER_PIXEL_SIZE);
    return surface;
}

int main(int argc, char* argv[])
{
    if (argc > 2) {
        fprintf(stderr, "usage: %s [truetype-font-dir]\n", argv[0]);
        return 1;
    }

    if (argc == 2) {
        os_font_directory = argv[1];
    }
    fprintf(stderr, "looking for truetype fonts in directory %s.\n", os_font_directory);

    const char *font_full_path = path_join(os_font_directory, font_filename);

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        return 3;
    }

    SDL_Window *window = SDL_CreateWindow("Font Rendering", 0, 0, 640, 480, SDL_WINDOW_RESIZABLE);

    font_renderer_lcd font_renderer;
    font_renderer.load_font(font_full_path);

    agg::rendering_buffer ren_buf;
    const agg::rgba8 text_color = agg::rgba8(0x23, 0x1f, 0x20);
    const agg::rgba8 page_color = agg::rgba8(0xe9, 0xe5, 0xcd);

    SDL_Surface *rendering_surface = NULL;
    while (1) {
        SDL_Event event;
        if (SDL_WaitEvent(&event) == 0) {
            continue;
        }
        if (event.type == SDL_QUIT) {
            break;
        }
        fprintf(stderr, "event.type %06x\n", event.type);
        if (event.type == SDL_WINDOWEVENT) {
            fprintf(stdout, "window event %d\n", event.window.event);
            Uint8 wet = event.window.event;
            if (wet == SDL_WINDOWEVENT_SHOWN || wet == SDL_WINDOWEVENT_SIZE_CHANGED) {
                int width, height;
                SDL_GetWindowSize(window, &width, &height);
                if (rendering_surface) {
                    SDL_FreeSurface(rendering_surface);
                }
                rendering_surface = SetupNewRendererSurface(ren_buf, width, height);
            } else if (wet == SDL_WINDOWEVENT_EXPOSED) {
                if (rendering_surface != NULL) {
                    font_renderer.clear(ren_buf, page_color);
                    font_renderer.render_text(ren_buf, 24, text_color,
                        20, rendering_surface->w / 2,
                        "Hello world!");

                    SDL_Surface *window_surface = SDL_GetWindowSurface(window);
                    SDL_BlitSurface(rendering_surface, NULL, window_surface, NULL);
                    SDL_UpdateWindowSurface(window);
                } else {
                    fprintf(stderr, "rendering_surface NULL\n");
                }
            }
        }
    }

    if (rendering_surface) {
        SDL_FreeSurface(rendering_surface);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
