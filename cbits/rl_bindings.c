#include "rl_bindings.h"
#include <stdlib.h>

#ifndef RLBIND

#ifdef __EMSCRIPTEN__

#include <emscripten.h>
#define RLBIND EMSCRIPTEN_KEEPALIVE

#else

#define RLBIND

#endif

#endif

RLBIND void SetWindowIcon_(Image *a)
{
    SetWindowIcon(*a);
}

RLBIND Vector2 *GetMonitorPosition_(int a)
{
    Vector2 *ptr = (Vector2 *)malloc(sizeof(Vector2));
    *ptr = GetMonitorPosition(a);
    return ptr;
}

RLBIND Vector2 *GetWindowPosition_()
{
    Vector2 *ptr = (Vector2 *)malloc(sizeof(Vector2));
    *ptr = GetWindowPosition();
    return ptr;
}

RLBIND Vector2 *GetWindowScaleDPI_()
{
    Vector2 *ptr = (Vector2 *)malloc(sizeof(Vector2));
    *ptr = GetWindowScaleDPI();
    return ptr;
}

RLBIND void ClearBackground_(Color *a)
{
    ClearBackground(*a);
}

RLBIND void BeginMode2D_(Camera2D *a)
{
    BeginMode2D(*a);
}

RLBIND void BeginMode3D_(Camera3D *a)
{
    BeginMode3D(*a);
}

RLBIND void BeginTextureMode_(RenderTexture *a)
{
    BeginTextureMode(*a);
}

RLBIND void BeginShaderMode_(Shader *a)
{
    BeginShaderMode(*a);
}

RLBIND void BeginVrStereoMode_(VrStereoConfig *a)
{
    BeginVrStereoMode(*a);
}

RLBIND VrStereoConfig *LoadVrStereoConfig_(VrDeviceInfo *a)
{
    VrStereoConfig *ptr = (VrStereoConfig *)malloc(sizeof(VrStereoConfig));
    *ptr = LoadVrStereoConfig(*a);
    return ptr;
}

RLBIND void UnloadVrStereoConfig_(VrStereoConfig *a)
{
    UnloadVrStereoConfig(*a);
}

RLBIND Shader *LoadShader_(char *a, char *b)
{
    Shader *ptr = (Shader *)malloc(sizeof(Shader));
    *ptr = LoadShader(a, b);
    return ptr;
}

RLBIND Shader *LoadShaderFromMemory_(char *a, char *b)
{
    Shader *ptr = (Shader *)malloc(sizeof(Shader));
    *ptr = LoadShaderFromMemory(a, b);
    return ptr;
}

RLBIND bool IsShaderReady_(Shader *a)
{
    return IsShaderReady(*a);
}

RLBIND int GetShaderLocation_(Shader *a, char *b)
{
    return GetShaderLocation(*a, b);
}

RLBIND int GetShaderLocationAttrib_(Shader *a, char *b)
{
    return GetShaderLocationAttrib(*a, b);
}

RLBIND void SetShaderValue_(Shader *a, int b, const void *c, int d)
{
    SetShaderValue(*a, b, c, d);
}

RLBIND void SetShaderValueV_(Shader *a, int b, const void *c, int d, int e)
{
    SetShaderValueV(*a, b, c, d, e);
}

RLBIND void SetShaderValueMatrix_(Shader *a, int b, Matrix *c)
{
    SetShaderValueMatrix(*a, b, *c);
}

RLBIND void SetShaderValueTexture_(Shader *a, int b, Texture *c)
{
    SetShaderValueTexture(*a, b, *c);
}

RLBIND void UnloadShader_(Shader *a)
{
    UnloadShader(*a);
}

RLBIND Ray *GetMouseRay_(Vector2 *a, Camera3D *b)
{
    Ray *ptr = (Ray *)malloc(sizeof(Ray));
    *ptr = GetMouseRay(*a, *b);
    return ptr;
}

RLBIND Matrix *GetCameraMatrix_(Camera3D *a)
{
    Matrix *ptr = (Matrix *)malloc(sizeof(Matrix));
    *ptr = GetCameraMatrix(*a);
    return ptr;
}

RLBIND Matrix *GetCameraMatrix2D_(Camera2D *a)
{
    Matrix *ptr = (Matrix *)malloc(sizeof(Matrix));
    *ptr = GetCameraMatrix2D(*a);
    return ptr;
}

RLBIND Vector2 *GetWorldToScreen_(Vector3 *a, Camera3D *b)
{
    Vector2 *ptr = (Vector2 *)malloc(sizeof(Vector2));
    *ptr = GetWorldToScreen(*a, *b);
    return ptr;
}

RLBIND Vector2 *GetScreenToWorld2D_(Vector2 *a, Camera2D *b)
{
    Vector2 *ptr = (Vector2 *)malloc(sizeof(Vector2));
    *ptr = GetScreenToWorld2D(*a, *b);
    return ptr;
}

RLBIND Vector2 *GetWorldToScreenEx_(Vector3 *a, Camera3D *b, int c, int d)
{
    Vector2 *ptr = (Vector2 *)malloc(sizeof(Vector2));
    *ptr = GetWorldToScreenEx(*a, *b, c, d);
    return ptr;
}

RLBIND Vector2 *GetWorldToScreen2D_(Vector2 *a, Camera2D *b)
{
    Vector2 *ptr = (Vector2 *)malloc(sizeof(Vector2));
    *ptr = GetWorldToScreen2D(*a, *b);
    return ptr;
}

RLBIND FilePathList *LoadDirectoryFiles_(char *a)
{
    FilePathList *ptr = (FilePathList *)malloc(sizeof(FilePathList));
    *ptr = LoadDirectoryFiles(a);
    return ptr;
}

RLBIND FilePathList *LoadDirectoryFilesEx_(char *a, char *b, int c)
{
    FilePathList *ptr = (FilePathList *)malloc(sizeof(FilePathList));
    *ptr = LoadDirectoryFilesEx(a, b, c);
    return ptr;
}

RLBIND void UnloadDirectoryFiles_(FilePathList *a)
{
    UnloadDirectoryFiles(*a);
}

RLBIND FilePathList *LoadDroppedFiles_()
{
    FilePathList *ptr = (FilePathList *)malloc(sizeof(FilePathList));
    *ptr = LoadDroppedFiles();
    return ptr;
}

RLBIND void UnloadDroppedFiles_(FilePathList *a)
{
    UnloadDroppedFiles(*a);
}

RLBIND Vector2 *GetMousePosition_()
{
    Vector2 *ptr = (Vector2 *)malloc(sizeof(Vector2));
    *ptr = GetMousePosition();
    return ptr;
}

RLBIND Vector2 *GetMouseDelta_()
{
    Vector2 *ptr = (Vector2 *)malloc(sizeof(Vector2));
    *ptr = GetMouseDelta();
    return ptr;
}

RLBIND Vector2 *GetMouseWheelMoveV_()
{
    Vector2 *ptr = (Vector2 *)malloc(sizeof(Vector2));
    *ptr = GetMouseWheelMoveV();
    return ptr;
}

RLBIND Vector2 *GetTouchPosition_(int a)
{
    Vector2 *ptr = (Vector2 *)malloc(sizeof(Vector2));
    *ptr = GetTouchPosition(a);
    return ptr;
}

RLBIND Vector2 *GetGestureDragVector_()
{
    Vector2 *ptr = (Vector2 *)malloc(sizeof(Vector2));
    *ptr = GetGestureDragVector();
    return ptr;
}

RLBIND Vector2 *GetGesturePinchVector_()
{
    Vector2 *ptr = (Vector2 *)malloc(sizeof(Vector2));
    *ptr = GetGesturePinchVector();
    return ptr;
}

RLBIND void UpdateCameraPro_(Camera3D *a, Vector3 *b, Vector3 *c, float d)
{
    UpdateCameraPro(a, *b, *c, d);
}

RLBIND void SetShapesTexture_(Texture *a, Rectangle *b)
{
    SetShapesTexture(*a, *b);
}

RLBIND void DrawPixel_(int a, int b, Color *c)
{
    DrawPixel(a, b, *c);
}

RLBIND void DrawPixelV_(Vector2 *a, Color *b)
{
    DrawPixelV(*a, *b);
}

RLBIND void DrawLine_(int a, int b, int c, int d, Color *e)
{
    DrawLine(a, b, c, d, *e);
}

RLBIND void DrawLineV_(Vector2 *a, Vector2 *b, Color *c)
{
    DrawLineV(*a, *b, *c);
}

RLBIND void DrawLineEx_(Vector2 *a, Vector2 *b, float c, Color *d)
{
    DrawLineEx(*a, *b, c, *d);
}

RLBIND void DrawLineBezier_(Vector2 *a, Vector2 *b, float c, Color *d)
{
    DrawLineBezier(*a, *b, c, *d);
}

RLBIND void DrawLineBezierQuad_(Vector2 *a, Vector2 *b, Vector2 *c, float d, Color *e)
{
    DrawLineBezierQuad(*a, *b, *c, d, *e);
}

RLBIND void DrawLineBezierCubic_(Vector2 *a, Vector2 *b, Vector2 *c, Vector2 *d, float e, Color *f)
{
    DrawLineBezierCubic(*a, *b, *c, *d, e, *f);
}

RLBIND void DrawLineBSpline_(Vector2 *a, int b, float c, Color *d)
{
    DrawLineBSpline(a, b, c, *d);
}

RLBIND void DrawLineCatmullRom_(Vector2 *a, int b, float c, Color *d)
{
    DrawLineCatmullRom(a, b, c, *d);
}

RLBIND void DrawLineStrip_(Vector2 *a, int b, Color *c)
{
    DrawLineStrip(a, b, *c);
}

RLBIND void DrawCircle_(int a, int b, float c, Color *d)
{
    DrawCircle(a, b, c, *d);
}

RLBIND void DrawCircleSector_(Vector2 *a, float b, float c, float d, int e, Color *f)
{
    DrawCircleSector(*a, b, c, d, e, *f);
}

RLBIND void DrawCircleSectorLines_(Vector2 *a, float b, float c, float d, int e, Color *f)
{
    DrawCircleSectorLines(*a, b, c, d, e, *f);
}

RLBIND void DrawCircleGradient_(int a, int b, float c, Color *d, Color *e)
{
    DrawCircleGradient(a, b, c, *d, *e);
}

RLBIND void DrawCircleV_(Vector2 *a, float b, Color *c)
{
    DrawCircleV(*a, b, *c);
}

RLBIND void DrawCircleLines_(int a, int b, float c, Color *d)
{
    DrawCircleLines(a, b, c, *d);
}

RLBIND void DrawEllipse_(int a, int b, float c, float d, Color *e)
{
    DrawEllipse(a, b, c, d, *e);
}

RLBIND void DrawEllipseLines_(int a, int b, float c, float d, Color *e)
{
    DrawEllipseLines(a, b, c, d, *e);
}

RLBIND void DrawRing_(Vector2 *a, float b, float c, float d, float e, int f, Color *g)
{
    DrawRing(*a, b, c, d, e, f, *g);
}

RLBIND void DrawRingLines_(Vector2 *a, float b, float c, float d, float e, int f, Color *g)
{
    DrawRingLines(*a, b, c, d, e, f, *g);
}

RLBIND void DrawRectangle_(int a, int b, int c, int d, Color *e)
{
    DrawRectangle(a, b, c, d, *e);
}

RLBIND void DrawRectangleV_(Vector2 *a, Vector2 *b, Color *c)
{
    DrawRectangleV(*a, *b, *c);
}

RLBIND void DrawRectangleRec_(Rectangle *a, Color *b)
{
    DrawRectangleRec(*a, *b);
}

RLBIND void DrawRectanglePro_(Rectangle *a, Vector2 *b, float c, Color *d)
{
    DrawRectanglePro(*a, *b, c, *d);
}

RLBIND void DrawRectangleGradientV_(int a, int b, int c, int d, Color *e, Color *f)
{
    DrawRectangleGradientV(a, b, c, d, *e, *f);
}

RLBIND void DrawRectangleGradientH_(int a, int b, int c, int d, Color *e, Color *f)
{
    DrawRectangleGradientH(a, b, c, d, *e, *f);
}

RLBIND void DrawRectangleGradientEx_(Rectangle *a, Color *b, Color *c, Color *d, Color *e)
{
    DrawRectangleGradientEx(*a, *b, *c, *d, *e);
}

RLBIND void DrawRectangleLines_(int a, int b, int c, int d, Color *e)
{
    DrawRectangleLines(a, b, c, d, *e);
}

RLBIND void DrawRectangleLinesEx_(Rectangle *a, float b, Color *c)
{
    DrawRectangleLinesEx(*a, b, *c);
}

RLBIND void DrawRectangleRounded_(Rectangle *a, float b, int c, Color *d)
{
    DrawRectangleRounded(*a, b, c, *d);
}

RLBIND void DrawRectangleRoundedLines_(Rectangle *a, float b, int c, float d, Color *e)
{
    DrawRectangleRoundedLines(*a, b, c, d, *e);
}

RLBIND void DrawTriangle_(Vector2 *a, Vector2 *b, Vector2 *c, Color *d)
{
    DrawTriangle(*a, *b, *c, *d);
}

RLBIND void DrawTriangleLines_(Vector2 *a, Vector2 *b, Vector2 *c, Color *d)
{
    DrawTriangleLines(*a, *b, *c, *d);
}

RLBIND void DrawTriangleFan_(Vector2 *a, int b, Color *c)
{
    DrawTriangleFan(a, b, *c);
}

RLBIND void DrawTriangleStrip_(Vector2 *a, int b, Color *c)
{
    DrawTriangleStrip(a, b, *c);
}

RLBIND void DrawPoly_(Vector2 *a, int b, float c, float d, Color *e)
{
    DrawPoly(*a, b, c, d, *e);
}

RLBIND void DrawPolyLines_(Vector2 *a, int b, float c, float d, Color *e)
{
    DrawPolyLines(*a, b, c, d, *e);
}

RLBIND void DrawPolyLinesEx_(Vector2 *a, int b, float c, float d, float e, Color *f)
{
    DrawPolyLinesEx(*a, b, c, d, e, *f);
}

RLBIND int CheckCollisionRecs_(Rectangle *a, Rectangle *b)
{
    return CheckCollisionRecs(*a, *b);
}

RLBIND int CheckCollisionCircles_(Vector2 *a, float b, Vector2 *c, float d)
{
    return CheckCollisionCircles(*a, b, *c, d);
}

RLBIND int CheckCollisionCircleRec_(Vector2 *a, float b, Rectangle *c)
{
    return CheckCollisionCircleRec(*a, b, *c);
}

RLBIND int CheckCollisionPointRec_(Vector2 *a, Rectangle *b)
{
    return CheckCollisionPointRec(*a, *b);
}

RLBIND int CheckCollisionPointCircle_(Vector2 *a, Vector2 *b, float c)
{
    return CheckCollisionPointCircle(*a, *b, c);
}

RLBIND int CheckCollisionPointTriangle_(Vector2 *a, Vector2 *b, Vector2 *c, Vector2 *d)
{
    return CheckCollisionPointTriangle(*a, *b, *c, *d);
}

RLBIND int CheckCollisionLines_(Vector2 *a, Vector2 *b, Vector2 *c, Vector2 *d, Vector2 *e)
{
    return CheckCollisionLines(*a, *b, *c, *d, e);
}

RLBIND int CheckCollisionPointLine_(Vector2 *a, Vector2 *b, Vector2 *c, int d)
{
    return CheckCollisionPointLine(*a, *b, *c, d);
}

RLBIND Rectangle *GetCollisionRec_(Rectangle *a, Rectangle *b)
{
    Rectangle *ptr = (Rectangle *)malloc(sizeof(Rectangle));
    *ptr = GetCollisionRec(*a, *b);
    return ptr;
}

RLBIND Image *LoadImage_(char *a)
{
    Image *ptr = (Image *)malloc(sizeof(Image));
    *ptr = LoadImage(a);
    return ptr;
}

RLBIND Image *LoadImageRaw_(char *a, int b, int c, int d, int e)
{
    Image *ptr = (Image *)malloc(sizeof(Image));
    *ptr = LoadImageRaw(a, b, c, d, e);
    return ptr;
}

RLBIND Image *LoadImageSvg_(char *a, int b, int c)
{
    Image *ptr = (Image *)malloc(sizeof(Image));
    *ptr = LoadImageSvg(a, b, c);
    return ptr;
}

RLBIND Image *LoadImageAnim_(char *a, int *b)
{
    Image *ptr = (Image *)malloc(sizeof(Image));
    *ptr = LoadImageAnim(a, b);
    return ptr;
}

RLBIND Image *LoadImageFromMemory_(char *a, unsigned char *b, int c)
{
    Image *ptr = (Image *)malloc(sizeof(Image));
    *ptr = LoadImageFromMemory(a, b, c);
    return ptr;
}

RLBIND Image *LoadImageFromTexture_(Texture *a)
{
    Image *ptr = (Image *)malloc(sizeof(Image));
    *ptr = LoadImageFromTexture(*a);
    return ptr;
}

RLBIND Image *LoadImageFromScreen_()
{
    Image *ptr = (Image *)malloc(sizeof(Image));
    *ptr = LoadImageFromScreen();
    return ptr;
}

RLBIND bool IsImageReady_(Image *a)
{
    return IsImageReady(*a);
}

RLBIND void UnloadImage_(Image *a)
{
    UnloadImage(*a);
}

RLBIND int ExportImage_(Image *a, char *b)
{
    return ExportImage(*a, b);
}

RLBIND unsigned char *ExportImageToMemory_(Image *a, char *fileType, int *fileSize)
{
    return ExportImageToMemory(*a, fileType, fileSize);
}

RLBIND int ExportImageAsCode_(Image *a, char *b)
{
    return ExportImageAsCode(*a, b);
}

RLBIND Image *GenImageColor_(int a, int b, Color *c)
{
    Image *ptr = (Image *)malloc(sizeof(Image));
    *ptr = GenImageColor(a, b, *c);
    return ptr;
}

RLBIND Image *GenImageGradientLinear_(int a, int b, int c, Color *d, Color *e)
{
    Image *ptr = (Image *)malloc(sizeof(Image));
    *ptr = GenImageGradientLinear(a, b, c, *d, *e);
    return ptr;
}

RLBIND Image *GenImageGradientRadial_(int a, int b, float c, Color *d, Color *e)
{
    Image *ptr = (Image *)malloc(sizeof(Image));
    *ptr = GenImageGradientRadial(a, b, c, *d, *e);
    return ptr;
}

RLBIND Image *GenImageGradientSquare_(int a, int b, float c, Color *d, Color *e)
{
    Image *ptr = (Image *)malloc(sizeof(Image));
    *ptr = GenImageGradientSquare(a, b, c, *d, *e);
    return ptr;
}

RLBIND Image *GenImageChecked_(int a, int b, int c, int d, Color *e, Color *f)
{
    Image *ptr = (Image *)malloc(sizeof(Image));
    *ptr = GenImageChecked(a, b, c, d, *e, *f);
    return ptr;
}

RLBIND Image *GenImageWhiteNoise_(int a, int b, float c)
{
    Image *ptr = (Image *)malloc(sizeof(Image));
    *ptr = GenImageWhiteNoise(a, b, c);
    return ptr;
}

RLBIND Image *GenImagePerlinNoise_(int a, int b, int c, int d, float e)
{
    Image *ptr = (Image *)malloc(sizeof(Image));
    *ptr = GenImagePerlinNoise(a, b, c, d, e);
    return ptr;
}

RLBIND Image *GenImageCellular_(int a, int b, int c)
{
    Image *ptr = (Image *)malloc(sizeof(Image));
    *ptr = GenImageCellular(a, b, c);
    return ptr;
}

RLBIND Image *GenImageText_(int a, int b, char *c)
{
    Image *ptr = (Image *)malloc(sizeof(Image));
    *ptr = GenImageText(a, b, c);
    return ptr;
}

RLBIND Image *ImageCopy_(Image *a)
{
    Image *ptr = (Image *)malloc(sizeof(Image));
    *ptr = ImageCopy(*a);
    return ptr;
}

RLBIND Image *ImageFromImage_(Image *a, Rectangle *b)
{
    Image *ptr = (Image *)malloc(sizeof(Image));
    *ptr = ImageFromImage(*a, *b);
    return ptr;
}

RLBIND Image *ImageText_(char *a, int b, Color *c)
{
    Image *ptr = (Image *)malloc(sizeof(Image));
    *ptr = ImageText(a, b, *c);
    return ptr;
}

RLBIND Image *ImageTextEx_(Font *a, char *b, float c, float d, Color *e)
{
    Image *ptr = (Image *)malloc(sizeof(Image));
    *ptr = ImageTextEx(*a, b, c, d, *e);
    return ptr;
}

RLBIND void ImageToPOT_(Image *a, Color *b)
{
    ImageToPOT(a, *b);
}

RLBIND void ImageCrop_(Image *a, Rectangle *b)
{
    ImageCrop(a, *b);
}

RLBIND void ImageAlphaClear_(Image *a, Color *b, float c)
{
    ImageAlphaClear(a, *b, c);
}

RLBIND void ImageAlphaMask_(Image *a, Image *b)
{
    ImageAlphaMask(a, *b);
}

RLBIND void ImageResizeCanvas_(Image *a, int b, int c, int d, int e, Color *f)
{
    ImageResizeCanvas(a, b, c, d, e, *f);
}

RLBIND void ImageColorTint_(Image *a, Color *b)
{
    ImageColorTint(a, *b);
}

RLBIND void ImageColorReplace_(Image *a, Color *b, Color *c)
{
    ImageColorReplace(a, *b, *c);
}

RLBIND Color *LoadImageColors_(Image *a)
{
    return LoadImageColors(*a);
}

RLBIND Color *LoadImagePalette_(Image *a, int b, int *c)
{
    return LoadImagePalette(*a, b, c);
}

RLBIND Rectangle *GetImageAlphaBorder_(Image *a, float b)
{
    Rectangle *ptr = (Rectangle *)malloc(sizeof(Rectangle));
    *ptr = GetImageAlphaBorder(*a, b);
    return ptr;
}

RLBIND Color *GetImageColor_(Image *a, int b, int c)
{
    Color *ptr = (Color *)malloc(sizeof(Color));
    *ptr = GetImageColor(*a, b, c);
    return ptr;
}

RLBIND void ImageClearBackground_(Image *a, Color *b)
{
    ImageClearBackground(a, *b);
}

RLBIND void ImageDrawPixel_(Image *a, int b, int c, Color *d)
{
    ImageDrawPixel(a, b, c, *d);
}

RLBIND void ImageDrawPixelV_(Image *a, Vector2 *b, Color *c)
{
    ImageDrawPixelV(a, *b, *c);
}

RLBIND void ImageDrawLine_(Image *a, int b, int c, int d, int e, Color *f)
{
    ImageDrawLine(a, b, c, d, e, *f);
}

RLBIND void ImageDrawLineV_(Image *a, Vector2 *b, Vector2 *c, Color *d)
{
    ImageDrawLineV(a, *b, *c, *d);
}

RLBIND void ImageDrawCircle_(Image *a, int b, int c, int d, Color *e)
{
    ImageDrawCircle(a, b, c, d, *e);
}

RLBIND void ImageDrawCircleV_(Image *a, Vector2 *b, int c, Color *d)
{
    ImageDrawCircleV(a, *b, c, *d);
}

RLBIND void ImageDrawCircleLines_(Image *a, int b, int c, int d, Color *e)
{
    ImageDrawCircleLines(a, b, c, d, *e);
}

RLBIND void ImageDrawCircleLinesV_(Image *a, Vector2 *b, int c, Color *d)
{
    ImageDrawCircleLinesV(a, *b, c, *d);
}

RLBIND void ImageDrawRectangle_(Image *a, int b, int c, int d, int e, Color *f)
{
    ImageDrawRectangle(a, b, c, d, e, *f);
}

RLBIND void ImageDrawRectangleV_(Image *a, Vector2 *b, Vector2 *c, Color *d)
{
    ImageDrawRectangleV(a, *b, *c, *d);
}

RLBIND void ImageDrawRectangleRec_(Image *a, Rectangle *b, Color *c)
{
    ImageDrawRectangleRec(a, *b, *c);
}

RLBIND void ImageDrawRectangleLines_(Image *a, Rectangle *b, int c, Color *d)
{
    ImageDrawRectangleLines(a, *b, c, *d);
}

RLBIND void ImageDraw_(Image *a, Image *b, Rectangle *c, Rectangle *d, Color *e)
{
    ImageDraw(a, *b, *c, *d, *e);
}

RLBIND void ImageDrawText_(Image *a, char *b, int c, int d, int e, Color *f)
{
    ImageDrawText(a, b, c, d, e, *f);
}

RLBIND void ImageDrawTextEx_(Image *a, Font *b, char *c, Vector2 *d, float e, float f, Color *g)
{
    ImageDrawTextEx(a, *b, c, *d, e, f, *g);
}

RLBIND Texture *LoadTexture_(char *a)
{
    Texture *ptr = (Texture *)malloc(sizeof(Texture));
    *ptr = LoadTexture(a);
    return ptr;
}

RLBIND Texture *LoadTextureFromImage_(Image *a)
{
    Texture *ptr = (Texture *)malloc(sizeof(Texture));
    *ptr = LoadTextureFromImage(*a);
    return ptr;
}

RLBIND Texture *LoadTextureCubemap_(Image *a, int b)
{
    Texture *ptr = (Texture *)malloc(sizeof(Texture));
    *ptr = LoadTextureCubemap(*a, b);
    return ptr;
}

RLBIND RenderTexture *LoadRenderTexture_(int a, int b)
{
    RenderTexture *ptr = (RenderTexture *)malloc(sizeof(RenderTexture));
    *ptr = LoadRenderTexture(a, b);
    return ptr;
}

RLBIND bool IsTextureReady_(Texture *a)
{
    return IsTextureReady(*a);
}

RLBIND void UnloadTexture_(Texture *a)
{
    UnloadTexture(*a);
}

RLBIND bool IsRenderTextureReady_(RenderTexture *a)
{
    return IsRenderTextureReady(*a);
}

RLBIND void UnloadRenderTexture_(RenderTexture *a)
{
    UnloadRenderTexture(*a);
}

RLBIND void UpdateTexture_(Texture *a, const void *b)
{
    UpdateTexture(*a, b);
}

RLBIND void UpdateTextureRec_(Texture *a, Rectangle *b, const void *c)
{
    UpdateTextureRec(*a, *b, c);
}

RLBIND void SetTextureFilter_(Texture *a, int b)
{
    SetTextureFilter(*a, b);
}

RLBIND void SetTextureWrap_(Texture *a, int b)
{
    SetTextureWrap(*a, b);
}

RLBIND void DrawTexture_(Texture *a, int b, int c, Color *d)
{
    DrawTexture(*a, b, c, *d);
}

RLBIND void DrawTextureV_(Texture *a, Vector2 *b, Color *c)
{
    DrawTextureV(*a, *b, *c);
}

RLBIND void DrawTextureEx_(Texture *a, Vector2 *b, float c, float d, Color *e)
{
    DrawTextureEx(*a, *b, c, d, *e);
}

RLBIND void DrawTextureRec_(Texture *a, Rectangle *b, Vector2 *c, Color *d)
{
    DrawTextureRec(*a, *b, *c, *d);
}

RLBIND void DrawTexturePro_(Texture *a, Rectangle *b, Rectangle *c, Vector2 *d, float e, Color *f)
{
    DrawTexturePro(*a, *b, *c, *d, e, *f);
}

RLBIND void DrawTextureNPatch_(Texture *a, NPatchInfo *b, Rectangle *c, Vector2 *d, float e, Color *f)
{
    DrawTextureNPatch(*a, *b, *c, *d, e, *f);
}

RLBIND Color *Fade_(Color *a, float b)
{
    Color *ptr = (Color *)malloc(sizeof(Color));
    *ptr = Fade(*a, b);
    return ptr;
}

RLBIND int ColorToInt_(Color *a)
{
    return ColorToInt(*a);
}

RLBIND Vector4 *ColorNormalize_(Color *a)
{
    Vector4 *ptr = (Vector4 *)malloc(sizeof(Vector4));
    *ptr = ColorNormalize(*a);
    return ptr;
}

RLBIND Color *ColorFromNormalized_(Vector4 *a)
{
    Color *ptr = (Color *)malloc(sizeof(Color));
    *ptr = ColorFromNormalized(*a);
    return ptr;
}

RLBIND Vector3 *ColorToHSV_(Color *a)
{
    Vector3 *ptr = (Vector3 *)malloc(sizeof(Vector3));
    *ptr = ColorToHSV(*a);
    return ptr;
}

RLBIND Color *ColorFromHSV_(float a, float b, float c)
{
    Color *ptr = (Color *)malloc(sizeof(Color));
    *ptr = ColorFromHSV(a, b, c);
    return ptr;
}

RLBIND Color *ColorTint_(Color *a, Color *b)
{
    Color *ptr = (Color *)malloc(sizeof(Color));
    *ptr = ColorTint(*a, *b);
    return ptr;
}

RLBIND Color *ColorBrightness_(Color *a, float b)
{
    Color *ptr = (Color *)malloc(sizeof(Color));
    *ptr = ColorBrightness(*a, b);
    return ptr;
}

RLBIND Color *ColorContrast_(Color *a, float b)
{
    Color *ptr = (Color *)malloc(sizeof(Color));
    *ptr = ColorContrast(*a, b);
    return ptr;
}

RLBIND Color *ColorAlpha_(Color *a, float b)
{
    Color *ptr = (Color *)malloc(sizeof(Color));
    *ptr = ColorAlpha(*a, b);
    return ptr;
}

RLBIND Color *ColorAlphaBlend_(Color *a, Color *b, Color *c)
{
    Color *ptr = (Color *)malloc(sizeof(Color));
    *ptr = ColorAlphaBlend(*a, *b, *c);
    return ptr;
}

RLBIND Color *GetColor_(unsigned int a)
{
    Color *ptr = (Color *)malloc(sizeof(Color));
    *ptr = GetColor(a);
    return ptr;
}

RLBIND Color *GetPixelColor_(void *a, int b)
{
    Color *ptr = (Color *)malloc(sizeof(Color));
    *ptr = GetPixelColor(a, b);
    return ptr;
}

RLBIND void SetPixelColor_(void *a, Color *b, int c)
{
    SetPixelColor(a, *b, c);
}

RLBIND Font *GetFontDefault_()
{
    Font defaultFont = GetFontDefault();
    Font *defaultFontCopy = (Font *)malloc(sizeof(Font));

    defaultFontCopy->baseSize = defaultFont.baseSize;
    defaultFontCopy->glyphCount = defaultFont.glyphCount;
    defaultFontCopy->glyphPadding = defaultFont.glyphPadding;
    defaultFontCopy->texture = defaultFont.texture;

    defaultFontCopy->glyphs = malloc(sizeof(GlyphInfo) * defaultFont.glyphCount);
    defaultFontCopy->recs = malloc(sizeof(Rectangle) * defaultFont.glyphCount);

    for (int i = 0; i < defaultFont.glyphCount; i++)
    {
        defaultFontCopy->glyphs[i] = defaultFont.glyphs[i];
        defaultFontCopy->glyphs[i].image = ImageCopy(defaultFont.glyphs[i].image);
        defaultFontCopy->recs[i] = defaultFont.recs[i];
    }

    return defaultFontCopy;
}

RLBIND Font *LoadFont_(char *a)
{
    Font *ptr = (Font *)malloc(sizeof(Font));
    *ptr = LoadFont(a);
    return ptr;
}

RLBIND Font *LoadFontEx_(char *a, int b, int *c, int d)
{
    Font *ptr = (Font *)malloc(sizeof(Font));
    *ptr = LoadFontEx(a, b, c, d);
    return ptr;
}

RLBIND Font *LoadFontFromImage_(Image *a, Color *b, int c)
{
    Font *ptr = (Font *)malloc(sizeof(Font));
    *ptr = LoadFontFromImage(*a, *b, c);
    return ptr;
}

RLBIND Font *LoadFontFromMemory_(char *a, unsigned char *b, int c, int d, int *e, int f)
{
    Font *ptr = (Font *)malloc(sizeof(Font));
    *ptr = LoadFontFromMemory(a, b, c, d, e, f);
    return ptr;
}

RLBIND Image *GenImageFontAtlas_(GlyphInfo *a, Rectangle **b, int c, int d, int e, int f)
{
    Image *ptr = (Image *)malloc(sizeof(Image));
    *ptr = GenImageFontAtlas(a, b, c, d, e, f);
    return ptr;
}

RLBIND bool IsFontReady_(Font *a)
{
    return IsFontReady(*a);
}

RLBIND void UnloadFont_(Font *a)
{
    UnloadFont(*a);
}

RLBIND int ExportFontAsCode_(Font *a, char *b)
{
    return ExportFontAsCode(*a, b);
}

RLBIND void DrawText_(char *a, int b, int c, int d, Color *e)
{
    DrawText(a, b, c, d, *e);
}

RLBIND void DrawTextEx_(Font *a, char *b, Vector2 *c, float d, float e, Color *f)
{
    DrawTextEx(*a, b, *c, d, e, *f);
}

RLBIND void DrawTextPro_(Font *a, char *b, Vector2 *c, Vector2 *d, float e, float f, float g, Color *h)
{
    DrawTextPro(*a, b, *c, *d, e, f, g, *h);
}

RLBIND void DrawTextCodepoint_(Font *a, int b, Vector2 *c, float d, Color *e)
{
    DrawTextCodepoint(*a, b, *c, d, *e);
}

RLBIND void DrawTextCodepoints_(Font *a, int *b, int c, Vector2 *d, float e, float f, Color *g)
{
    DrawTextCodepoints(*a, b, c, *d, e, f, *g);
}

RLBIND Vector2 *MeasureTextEx_(Font *a, char *b, float c, float d)
{
    Vector2 *ptr = (Vector2 *)malloc(sizeof(Vector2));
    *ptr = MeasureTextEx(*a, b, c, d);
    return ptr;
}

RLBIND int GetGlyphIndex_(Font *a, int b)
{
    return GetGlyphIndex(*a, b);
}

RLBIND GlyphInfo *GetGlyphInfo_(Font *a, int b)
{
    GlyphInfo *ptr = (GlyphInfo *)malloc(sizeof(GlyphInfo));
    *ptr = GetGlyphInfo(*a, b);
    return ptr;
}

RLBIND Rectangle *GetGlyphAtlasRec_(Font *a, int b)
{
    Rectangle *ptr = (Rectangle *)malloc(sizeof(Rectangle));
    *ptr = GetGlyphAtlasRec(*a, b);
    return ptr;
}

RLBIND void DrawLine3D_(Vector3 *a, Vector3 *b, Color *c)
{
    DrawLine3D(*a, *b, *c);
}

RLBIND void DrawPoint3D_(Vector3 *a, Color *b)
{
    DrawPoint3D(*a, *b);
}

RLBIND void DrawCircle3D_(Vector3 *a, float b, Vector3 *c, float d, Color *e)
{
    DrawCircle3D(*a, b, *c, d, *e);
}

RLBIND void DrawTriangle3D_(Vector3 *a, Vector3 *b, Vector3 *c, Color *d)
{
    DrawTriangle3D(*a, *b, *c, *d);
}

RLBIND void DrawTriangleStrip3D_(Vector3 *a, int b, Color *c)
{
    DrawTriangleStrip3D(a, b, *c);
}

RLBIND void DrawCube_(Vector3 *a, float b, float c, float d, Color *e)
{
    DrawCube(*a, b, c, d, *e);
}

RLBIND void DrawCubeV_(Vector3 *a, Vector3 *b, Color *c)
{
    DrawCubeV(*a, *b, *c);
}

RLBIND void DrawCubeWires_(Vector3 *a, float b, float c, float d, Color *e)
{
    DrawCubeWires(*a, b, c, d, *e);
}

RLBIND void DrawCubeWiresV_(Vector3 *a, Vector3 *b, Color *c)
{
    DrawCubeWiresV(*a, *b, *c);
}

RLBIND void DrawSphere_(Vector3 *a, float b, Color *c)
{
    DrawSphere(*a, b, *c);
}

RLBIND void DrawSphereEx_(Vector3 *a, float b, int c, int d, Color *e)
{
    DrawSphereEx(*a, b, c, d, *e);
}

RLBIND void DrawSphereWires_(Vector3 *a, float b, int c, int d, Color *e)
{
    DrawSphereWires(*a, b, c, d, *e);
}

RLBIND void DrawCylinder_(Vector3 *a, float b, float c, float d, int e, Color *f)
{
    DrawCylinder(*a, b, c, d, e, *f);
}

RLBIND void DrawCylinderEx_(Vector3 *a, Vector3 *b, float c, float d, int e, Color *f)
{
    DrawCylinderEx(*a, *b, c, d, e, *f);
}

RLBIND void DrawCylinderWires_(Vector3 *a, float b, float c, float d, int e, Color *f)
{
    DrawCylinderWires(*a, b, c, d, e, *f);
}

RLBIND void DrawCylinderWiresEx_(Vector3 *a, Vector3 *b, float c, float d, int e, Color *f)
{
    DrawCylinderWiresEx(*a, *b, c, d, e, *f);
}

RLBIND void DrawCapsule_(Vector3 *a, Vector3 *b, float c, int d, int e, Color *f)
{
    DrawCapsule(*a, *b, c, d, e, *f);
}

RLBIND void DrawCapsuleWires_(Vector3 *a, Vector3 *b, float c, int d, int e, Color *f)
{
    DrawCapsuleWires(*a, *b, c, d, e, *f);
}

RLBIND void DrawPlane_(Vector3 *a, Vector2 *b, Color *c)
{
    DrawPlane(*a, *b, *c);
}

RLBIND void DrawRay_(Ray *a, Color *b)
{
    DrawRay(*a, *b);
}

RLBIND Model *LoadModel_(char *a)
{
    Model *ptr = (Model *)malloc(sizeof(Model));
    *ptr = LoadModel(a);
    return ptr;
}

RLBIND Model *LoadModelFromMesh_(Mesh *a)
{
    Model *ptr = (Model *)malloc(sizeof(Model));
    *ptr = LoadModelFromMesh(*a);
    return ptr;
}

RLBIND bool IsModelReady_(Model *a)
{
    return IsModelReady(*a);
}

RLBIND void UnloadModel_(Model *a)
{
    UnloadModel(*a);
}

RLBIND BoundingBox *GetModelBoundingBox_(Model *a)
{
    BoundingBox *ptr = (BoundingBox *)malloc(sizeof(BoundingBox));
    *ptr = GetModelBoundingBox(*a);
    return ptr;
}

RLBIND void DrawModel_(Model *a, Vector3 *b, float c, Color *d)
{
    DrawModel(*a, *b, c, *d);
}

RLBIND void DrawModelEx_(Model *a, Vector3 *b, Vector3 *c, float d, Vector3 *e, Color *f)
{
    DrawModelEx(*a, *b, *c, d, *e, *f);
}

RLBIND void DrawModelWires_(Model *a, Vector3 *b, float c, Color *d)
{
    DrawModelWires(*a, *b, c, *d);
}

RLBIND void DrawModelWiresEx_(Model *a, Vector3 *b, Vector3 *c, float d, Vector3 *e, Color *f)
{
    DrawModelWiresEx(*a, *b, *c, d, *e, *f);
}

RLBIND void DrawBoundingBox_(BoundingBox *a, Color *b)
{
    DrawBoundingBox(*a, *b);
}

RLBIND void DrawBillboard_(Camera3D *a, Texture *b, Vector3 *c, float d, Color *e)
{
    DrawBillboard(*a, *b, *c, d, *e);
}

RLBIND void DrawBillboardRec_(Camera3D *a, Texture *b, Rectangle *c, Vector3 *d, Vector2 *e, Color *f)
{
    DrawBillboardRec(*a, *b, *c, *d, *e, *f);
}

RLBIND void DrawBillboardPro_(Camera3D *a, Texture *b, Rectangle *c, Vector3 *d, Vector3 *e, Vector2 *f, Vector2 *g, float h, Color *i)
{
    DrawBillboardPro(*a, *b, *c, *d, *e, *f, *g, h, *i);
}

RLBIND void UpdateMeshBuffer_(Mesh *a, int b, const void *c, int d, int e)
{
    UpdateMeshBuffer(*a, b, c, d, e);
}

RLBIND void UnloadMesh_(Mesh *a)
{
    UnloadMesh(*a);
}

RLBIND void DrawMesh_(Mesh *a, Material *b, Matrix *c)
{
    DrawMesh(*a, *b, *c);
}

RLBIND void DrawMeshInstanced_(Mesh *a, Material *b, Matrix *c, int d)
{
    DrawMeshInstanced(*a, *b, c, d);
}

RLBIND int ExportMesh_(Mesh *a, char *b)
{
    return ExportMesh(*a, b);
}

RLBIND BoundingBox *GetMeshBoundingBox_(Mesh *a)
{
    BoundingBox *ptr = (BoundingBox *)malloc(sizeof(BoundingBox));
    *ptr = GetMeshBoundingBox(*a);
    return ptr;
}

RLBIND Mesh *GenMeshPoly_(int a, float b)
{
    Mesh *ptr = (Mesh *)malloc(sizeof(Mesh));
    *ptr = GenMeshPoly(a, b);
    return ptr;
}

RLBIND Mesh *GenMeshPlane_(float a, float b, int c, int d)
{
    Mesh *ptr = (Mesh *)malloc(sizeof(Mesh));
    *ptr = GenMeshPlane(a, b, c, d);
    return ptr;
}

RLBIND Mesh *GenMeshCube_(float a, float b, float c)
{
    Mesh *ptr = (Mesh *)malloc(sizeof(Mesh));
    *ptr = GenMeshCube(a, b, c);
    return ptr;
}

RLBIND Mesh *GenMeshSphere_(float a, int b, int c)
{
    Mesh *ptr = (Mesh *)malloc(sizeof(Mesh));
    *ptr = GenMeshSphere(a, b, c);
    return ptr;
}

RLBIND Mesh *GenMeshHemiSphere_(float a, int b, int c)
{
    Mesh *ptr = (Mesh *)malloc(sizeof(Mesh));
    *ptr = GenMeshHemiSphere(a, b, c);
    return ptr;
}

RLBIND Mesh *GenMeshCylinder_(float a, float b, int c)
{
    Mesh *ptr = (Mesh *)malloc(sizeof(Mesh));
    *ptr = GenMeshCylinder(a, b, c);
    return ptr;
}

RLBIND Mesh *GenMeshCone_(float a, float b, int c)
{
    Mesh *ptr = (Mesh *)malloc(sizeof(Mesh));
    *ptr = GenMeshCone(a, b, c);
    return ptr;
}

RLBIND Mesh *GenMeshTorus_(float a, float b, int c, int d)
{
    Mesh *ptr = (Mesh *)malloc(sizeof(Mesh));
    *ptr = GenMeshTorus(a, b, c, d);
    return ptr;
}

RLBIND Mesh *GenMeshKnot_(float a, float b, int c, int d)
{
    Mesh *ptr = (Mesh *)malloc(sizeof(Mesh));
    *ptr = GenMeshKnot(a, b, c, d);
    return ptr;
}

RLBIND Mesh *GenMeshHeightmap_(Image *a, Vector3 *b)
{
    Mesh *ptr = (Mesh *)malloc(sizeof(Mesh));
    *ptr = GenMeshHeightmap(*a, *b);
    return ptr;
}

RLBIND Mesh *GenMeshCubicmap_(Image *a, Vector3 *b)
{
    Mesh *ptr = (Mesh *)malloc(sizeof(Mesh));
    *ptr = GenMeshCubicmap(*a, *b);
    return ptr;
}

RLBIND Material *LoadMaterialDefault_()
{
    Material *ptr = (Material *)malloc(sizeof(Material));
    *ptr = LoadMaterialDefault();
    return ptr;
}

RLBIND bool IsMaterialReady_(Material *a)
{
    return IsMaterialReady(*a);
}

RLBIND void UnloadMaterial_(Material *a)
{
    UnloadMaterial(*a);
}

RLBIND void SetMaterialTexture_(Material *a, int b, Texture *c)
{
    SetMaterialTexture(a, b, *c);
}

RLBIND void UpdateModelAnimation_(Model *a, ModelAnimation *b, int c)
{
    UpdateModelAnimation(*a, *b, c);
}

RLBIND void UnloadModelAnimation_(ModelAnimation *a)
{
    UnloadModelAnimation(*a);
}

RLBIND int IsModelAnimationValid_(Model *a, ModelAnimation *b)
{
    return IsModelAnimationValid(*a, *b);
}

RLBIND int CheckCollisionSpheres_(Vector3 *a, float b, Vector3 *c, float d)
{
    return CheckCollisionSpheres(*a, b, *c, d);
}

RLBIND int CheckCollisionBoxes_(BoundingBox *a, BoundingBox *b)
{
    return CheckCollisionBoxes(*a, *b);
}

RLBIND int CheckCollisionBoxSphere_(BoundingBox *a, Vector3 *b, float c)
{
    return CheckCollisionBoxSphere(*a, *b, c);
}

RLBIND RayCollision *GetRayCollisionSphere_(Ray *a, Vector3 *b, float c)
{
    RayCollision *ptr = (RayCollision *)malloc(sizeof(RayCollision));
    *ptr = GetRayCollisionSphere(*a, *b, c);
    return ptr;
}

RLBIND RayCollision *GetRayCollisionBox_(Ray *a, BoundingBox *b)
{
    RayCollision *ptr = (RayCollision *)malloc(sizeof(RayCollision));
    *ptr = GetRayCollisionBox(*a, *b);
    return ptr;
}

RLBIND RayCollision *GetRayCollisionMesh_(Ray *a, Mesh *b, Matrix *c)
{
    RayCollision *ptr = (RayCollision *)malloc(sizeof(RayCollision));
    *ptr = GetRayCollisionMesh(*a, *b, *c);
    return ptr;
}

RLBIND RayCollision *GetRayCollisionTriangle_(Ray *a, Vector3 *b, Vector3 *c, Vector3 *d)
{
    RayCollision *ptr = (RayCollision *)malloc(sizeof(RayCollision));
    *ptr = GetRayCollisionTriangle(*a, *b, *c, *d);
    return ptr;
}

RLBIND RayCollision *GetRayCollisionQuad_(Ray *a, Vector3 *b, Vector3 *c, Vector3 *d, Vector3 *e)
{
    RayCollision *ptr = (RayCollision *)malloc(sizeof(RayCollision));
    *ptr = GetRayCollisionQuad(*a, *b, *c, *d, *e);
    return ptr;
}

RLBIND Wave *LoadWave_(char *a)
{
    Wave *ptr = (Wave *)malloc(sizeof(Wave));
    *ptr = LoadWave(a);
    return ptr;
}

RLBIND Wave *LoadWaveFromMemory_(char *a, unsigned char *b, int c)
{
    Wave *ptr = (Wave *)malloc(sizeof(Wave));
    *ptr = LoadWaveFromMemory(a, b, c);
    return ptr;
}

RLBIND Sound *LoadSound_(char *a)
{
    Sound *ptr = (Sound *)malloc(sizeof(Sound));
    *ptr = LoadSound(a);
    return ptr;
}

RLBIND Sound *LoadSoundFromWave_(Wave *a)
{
    Sound *ptr = (Sound *)malloc(sizeof(Sound));
    *ptr = LoadSoundFromWave(*a);
    return ptr;
}

RLBIND Sound *LoadSoundAlias_(Sound *a)
{
    Sound *ptr = (Sound *)malloc(sizeof(Sound));
    *ptr = LoadSoundAlias(*a);
    return ptr;
}

RLBIND void UpdateSound_(Sound *a, const void *b, int c)
{
    UpdateSound(*a, b, c);
}

RLBIND bool IsWaveReady_(Wave *a)
{
    return IsWaveReady(*a);
}

RLBIND void UnloadWave_(Wave *a)
{
    UnloadWave(*a);
}

RLBIND bool IsSoundReady_(Sound *a)
{
    return IsSoundReady(*a);
}

RLBIND void UnloadSound_(Sound *a)
{
    UnloadSound(*a);
}

RLBIND void UnloadSoundAlias_(Sound *a)
{
    UnloadSoundAlias(*a);
}

RLBIND int ExportWave_(Wave *a, char *b)
{
    return ExportWave(*a, b);
}

RLBIND int ExportWaveAsCode_(Wave *a, char *b)
{
    return ExportWaveAsCode(*a, b);
}

RLBIND void PlaySound_(Sound *a)
{
    PlaySound(*a);
}

RLBIND void StopSound_(Sound *a)
{
    StopSound(*a);
}

RLBIND void PauseSound_(Sound *a)
{
    PauseSound(*a);
}

RLBIND void ResumeSound_(Sound *a)
{
    ResumeSound(*a);
}

RLBIND int IsSoundPlaying_(Sound *a)
{
    return IsSoundPlaying(*a);
}

RLBIND void SetSoundVolume_(Sound *a, float b)
{
    SetSoundVolume(*a, b);
}

RLBIND void SetSoundPitch_(Sound *a, float b)
{
    SetSoundPitch(*a, b);
}

RLBIND void SetSoundPan_(Sound *a, float b)
{
    SetSoundPan(*a, b);
}

RLBIND Wave *WaveCopy_(Wave *a)
{
    Wave *ptr = (Wave *)malloc(sizeof(Wave));
    *ptr = WaveCopy(*a);
    return ptr;
}

RLBIND float *LoadWaveSamples_(Wave *a)
{
    return LoadWaveSamples(*a);
}

RLBIND Music *LoadMusicStream_(char *a)
{
    Music *ptr = (Music *)malloc(sizeof(Music));
    *ptr = LoadMusicStream(a);
    return ptr;
}

RLBIND Music *LoadMusicStreamFromMemory_(char *a, unsigned char *b, int c)
{
    Music *ptr = (Music *)malloc(sizeof(Music));
    *ptr = LoadMusicStreamFromMemory(a, b, c);
    return ptr;
}

RLBIND bool IsMusicReady_(Music *a)
{
    return IsMusicReady(*a);
}

RLBIND void UnloadMusicStream_(Music *a)
{
    UnloadMusicStream(*a);
}

RLBIND void PlayMusicStream_(Music *a)
{
    PlayMusicStream(*a);
}

RLBIND int IsMusicStreamPlaying_(Music *a)
{
    return IsMusicStreamPlaying(*a);
}

RLBIND void UpdateMusicStream_(Music *a)
{
    UpdateMusicStream(*a);
}

RLBIND void StopMusicStream_(Music *a)
{
    StopMusicStream(*a);
}

RLBIND void PauseMusicStream_(Music *a)
{
    PauseMusicStream(*a);
}

RLBIND void ResumeMusicStream_(Music *a)
{
    ResumeMusicStream(*a);
}

RLBIND void SeekMusicStream_(Music *a, float b)
{
    SeekMusicStream(*a, b);
}

RLBIND void SetMusicVolume_(Music *a, float b)
{
    SetMusicVolume(*a, b);
}

RLBIND void SetMusicPitch_(Music *a, float b)
{
    SetMusicPitch(*a, b);
}

RLBIND void SetMusicPan_(Music *a, float b)
{
    SetMusicPan(*a, b);
}

RLBIND float GetMusicTimeLength_(Music *a)
{
    return GetMusicTimeLength(*a);
}

RLBIND float GetMusicTimePlayed_(Music *a)
{
    return GetMusicTimePlayed(*a);
}

RLBIND AudioStream *LoadAudioStream_(unsigned int a, unsigned int b, unsigned int c)
{
    AudioStream *ptr = (AudioStream *)malloc(sizeof(AudioStream));
    *ptr = LoadAudioStream(a, b, c);
    return ptr;
}

RLBIND bool IsAudioStreamReady_(AudioStream *a)
{
    return IsAudioStreamReady(*a);
}

RLBIND void UnloadAudioStream_(AudioStream *a)
{
    UnloadAudioStream(*a);
}

RLBIND void UpdateAudioStream_(AudioStream *a, const void *b, int c)
{
    UpdateAudioStream(*a, b, c);
}

RLBIND int IsAudioStreamProcessed_(AudioStream *a)
{
    return IsAudioStreamProcessed(*a);
}

RLBIND void PlayAudioStream_(AudioStream *a)
{
    PlayAudioStream(*a);
}

RLBIND void PauseAudioStream_(AudioStream *a)
{
    PauseAudioStream(*a);
}

RLBIND void ResumeAudioStream_(AudioStream *a)
{
    ResumeAudioStream(*a);
}

RLBIND int IsAudioStreamPlaying_(AudioStream *a)
{
    return IsAudioStreamPlaying(*a);
}

RLBIND void StopAudioStream_(AudioStream *a)
{
    StopAudioStream(*a);
}

RLBIND void SetAudioStreamVolume_(AudioStream *a, float b)
{
    SetAudioStreamVolume(*a, b);
}

RLBIND void SetAudioStreamPitch_(AudioStream *a, float b)
{
    SetAudioStreamPitch(*a, b);
}

RLBIND void SetAudioStreamPan_(AudioStream *a, float b)
{
    SetAudioStreamPan(*a, b);
}

RLBIND void SetAudioStreamCallback_(AudioStream *a, AudioCallback *b)
{
    SetAudioStreamCallback(*a, *b);
}

RLBIND void AttachAudioStreamProcessor_(AudioStream *a, AudioCallback *b)
{
    AttachAudioStreamProcessor(*a, *b);
}

RLBIND void DetachAudioStreamProcessor_(AudioStream *a, AudioCallback *b)
{
    DetachAudioStreamProcessor(*a, *b);
}

RLBIND void AttachAudioMixedProcessor_(AudioCallback *a)
{
    AttachAudioMixedProcessor(*a);
}

RLBIND void DetachAudioMixedProcessor_(AudioCallback *a)
{
    DetachAudioMixedProcessor(*a);
}

RLBIND void InitWindow_(int width, int height, const char *title)
{
    InitWindow(width, height, title);
}

RLBIND bool WindowShouldClose_(void)
{
    return WindowShouldClose();
}

RLBIND void CloseWindow_(void)
{
    CloseWindow();
}

RLBIND bool IsWindowReady_(void)
{
    return IsWindowReady();
}

RLBIND bool IsWindowFullscreen_(void)
{
    return IsWindowFullscreen();
}

RLBIND bool IsWindowHidden_(void)
{
    return IsWindowHidden();
}

RLBIND bool IsWindowMinimized_(void)
{
    return IsWindowMinimized();
}

RLBIND bool IsWindowMaximized_(void)
{
    return IsWindowMaximized();
}

RLBIND bool IsWindowFocused_(void)
{
    return IsWindowFocused();
}

RLBIND bool IsWindowResized_(void)
{
    return IsWindowResized();
}

RLBIND bool IsWindowState_(unsigned int flag)
{
    return IsWindowState(flag);
}

RLBIND void SetWindowState_(unsigned int flags)
{
    SetWindowState(flags);
}

RLBIND void ClearWindowState_(unsigned int flags)
{
    ClearWindowState(flags);
}

RLBIND void ToggleFullscreen_(void)
{
    ToggleFullscreen();
}

RLBIND void ToggleBorderlessWindowed_(void)
{
    ToggleBorderlessWindowed();
}

RLBIND void MaximizeWindow_(void)
{
    MaximizeWindow();
}

RLBIND void MinimizeWindow_(void)
{
    MinimizeWindow();
}

RLBIND void RestoreWindow_(void)
{
    RestoreWindow();
}

RLBIND void SetWindowIcons_(Image *images, int count)
{
    SetWindowIcons(images, count);
}

RLBIND void SetWindowTitle_(const char *title)
{
    SetWindowTitle(title);
}

RLBIND void SetWindowPosition_(int x, int y)
{
    SetWindowPosition(x, y);
}

RLBIND void SetWindowMonitor_(int monitor)
{
    SetWindowMonitor(monitor);
}

RLBIND void SetWindowMinSize_(int width, int height)
{
    SetWindowMinSize(width, height);
}

RLBIND void SetWindowMaxSize_(int width, int height)
{
    SetWindowMaxSize(width, height);
}

RLBIND void SetWindowSize_(int width, int height)
{
    SetWindowSize(width, height);
}

RLBIND void SetWindowOpacity_(float opacity)
{
    SetWindowOpacity(opacity);
}

RLBIND void SetWindowFocused_(void)
{
    SetWindowFocused();
}

RLBIND void *GetWindowHandle_(void)
{
    return GetWindowHandle();
}

RLBIND int GetScreenWidth_(void)
{
    return GetScreenWidth();
}

RLBIND int GetScreenHeight_(void)
{
    return GetScreenHeight();
}

RLBIND int GetRenderWidth_(void)
{
    return GetRenderWidth();
}

RLBIND int GetRenderHeight_(void)
{
    return GetRenderHeight();
}

RLBIND int GetMonitorCount_(void)
{
    return GetMonitorCount();
}

RLBIND int GetCurrentMonitor_(void)
{
    return GetCurrentMonitor();
}

RLBIND int GetMonitorWidth_(int monitor)
{
    return GetMonitorWidth(monitor);
}

RLBIND int GetMonitorHeight_(int monitor)
{
    return GetMonitorHeight(monitor);
}

RLBIND int GetMonitorPhysicalWidth_(int monitor)
{
    return GetMonitorPhysicalWidth(monitor);
}

RLBIND int GetMonitorPhysicalHeight_(int monitor)
{
    return GetMonitorPhysicalHeight(monitor);
}

RLBIND int GetMonitorRefreshRate_(int monitor)
{
    return GetMonitorRefreshRate(monitor);
}

RLBIND const char *GetMonitorName_(int monitor)
{
    return GetMonitorName(monitor);
}

RLBIND void SetClipboardText_(const char *text)
{
    SetClipboardText(text);
}

RLBIND const char *GetClipboardText_(void)
{
    return GetClipboardText();
}

RLBIND void EnableEventWaiting_(void)
{
    EnableEventWaiting();
}

RLBIND void DisableEventWaiting_(void)
{
    DisableEventWaiting();
}

RLBIND void SwapScreenBuffer_(void)
{
    SwapScreenBuffer();
}

RLBIND void PollInputEvents_(void)
{
    PollInputEvents();
}

RLBIND void WaitTime_(double seconds)
{
    WaitTime(seconds);
}

RLBIND void ShowCursor_(void)
{
    ShowCursor();
}

RLBIND void HideCursor_(void)
{
    HideCursor();
}

RLBIND bool IsCursorHidden_(void)
{
    return IsCursorHidden();
}

RLBIND void EnableCursor_(void)
{
    EnableCursor();
}

RLBIND void DisableCursor_(void)
{
    DisableCursor();
}

RLBIND bool IsCursorOnScreen_(void)
{
    return IsCursorOnScreen();
}

RLBIND void BeginDrawing_(void)
{
    BeginDrawing();
}

RLBIND void EndDrawing_(void)
{
    EndDrawing();
}

RLBIND void EndMode2D_(void)
{
    EndMode2D();
}

RLBIND void EndMode3D_(void)
{
    EndMode3D();
}

RLBIND void EndTextureMode_(void)
{
    EndTextureMode();
}

RLBIND void EndShaderMode_(void)
{
    EndShaderMode();
}

RLBIND void BeginBlendMode_(int mode)
{
    BeginBlendMode(mode);
}

RLBIND void EndBlendMode_(void)
{
    EndBlendMode();
}

RLBIND void BeginScissorMode_(int x, int y, int width, int height)
{
    BeginScissorMode(x, y, width, height);
}

RLBIND void EndScissorMode_(void)
{
    EndScissorMode();
}

RLBIND void EndVrStereoMode_(void)
{
    EndVrStereoMode();
}

RLBIND void SetTargetFPS_(int fps)
{
    SetTargetFPS(fps);
}

RLBIND int GetFPS_(void)
{
    return GetFPS();
}

RLBIND float GetFrameTime_(void)
{
    return GetFrameTime();
}

RLBIND double GetTime_(void)
{
    return GetTime();
}

RLBIND int GetRandomValue_(int min, int max)
{
    return GetRandomValue(min, max);
}

RLBIND void SetRandomSeed_(unsigned int seed)
{
    SetRandomSeed(seed);
}

RLBIND void TakeScreenshot_(const char *fileName)
{
    TakeScreenshot(fileName);
}

RLBIND void SetConfigFlags_(unsigned int flags)
{
    SetConfigFlags(flags);
}

RLBIND void SetTraceLogLevel_(int logLevel)
{
    SetTraceLogLevel(logLevel);
}

RLBIND void *MemAlloc_(unsigned int size)
{
    return MemAlloc(size);
}

RLBIND void *MemRealloc_(void *ptr, unsigned int size)
{
    return MemRealloc(ptr, size);
}

RLBIND void MemFree_(void *ptr)
{
    MemFree(ptr);
}

RLBIND void OpenURL_(const char *url)
{
    OpenURL(url);
}

RLBIND void SetTraceLogCallback_(TraceLogCallback callback)
{
    SetTraceLogCallback(callback);
}

RLBIND void SetLoadFileDataCallback_(LoadFileDataCallback callback)
{
    SetLoadFileDataCallback(callback);
}

RLBIND void SetSaveFileDataCallback_(SaveFileDataCallback callback)
{
    SetSaveFileDataCallback(callback);
}

RLBIND void SetLoadFileTextCallback_(LoadFileTextCallback callback)
{
    SetLoadFileTextCallback(callback);
}

RLBIND void SetSaveFileTextCallback_(SaveFileTextCallback callback)
{
    SetSaveFileTextCallback(callback);
}

RLBIND unsigned char *LoadFileData_(const char *fileName, int *dataSize)
{
    return LoadFileData(fileName, dataSize);
}

RLBIND void UnloadFileData_(unsigned char *data)
{
    UnloadFileData(data);
}

RLBIND bool SaveFileData_(const char *fileName, void *data, int dataSize)
{
    return SaveFileData(fileName, data, dataSize);
}

RLBIND bool ExportDataAsCode_(const unsigned char *data, int dataSize, const char *fileName)
{
    return ExportDataAsCode(data, dataSize, fileName);
}

RLBIND char *LoadFileText_(const char *fileName)
{
    return LoadFileText(fileName);
}

RLBIND void UnloadFileText_(char *text)
{
    UnloadFileText(text);
}

RLBIND bool SaveFileText_(const char *fileName, char *text)
{
    return SaveFileText(fileName, text);
}

RLBIND bool FileExists_(const char *fileName)
{
    return FileExists(fileName);
}

RLBIND bool DirectoryExists_(const char *dirPath)
{
    return DirectoryExists(dirPath);
}

RLBIND bool IsFileExtension_(const char *fileName, const char *ext)
{
    return IsFileExtension(fileName, ext);
}

RLBIND int GetFileLength_(const char *fileName)
{
    return GetFileLength(fileName);
}

RLBIND const char *GetFileExtension_(const char *fileName)
{
    return GetFileExtension(fileName);
}

RLBIND const char *GetFileName_(const char *filePath)
{
    return GetFileName(filePath);
}

RLBIND const char *GetFileNameWithoutExt_(const char *filePath)
{
    return GetFileNameWithoutExt(filePath);
}

RLBIND const char *GetDirectoryPath_(const char *filePath)
{
    return GetDirectoryPath(filePath);
}

RLBIND const char *GetPrevDirectoryPath_(const char *dirPath)
{
    return GetPrevDirectoryPath(dirPath);
}

RLBIND const char *GetWorkingDirectory_(void)
{
    return GetWorkingDirectory();
}

RLBIND const char *GetApplicationDirectory_(void)
{
    return GetApplicationDirectory();
}

RLBIND bool ChangeDirectory_(const char *dir)
{
    return ChangeDirectory(dir);
}

RLBIND bool IsPathFile_(const char *path)
{
    return IsPathFile(path);
}

RLBIND bool IsFileDropped_(void)
{
    return IsFileDropped();
}

RLBIND long GetFileModTime_(const char *fileName)
{
    return GetFileModTime(fileName);
}

RLBIND unsigned char *CompressData_(const unsigned char *data, int dataSize, int *compDataSize)
{
    return CompressData(data, dataSize, compDataSize);
}

RLBIND unsigned char *DecompressData_(const unsigned char *compData, int compDataSize, int *dataSize)
{
    return DecompressData(compData, compDataSize, dataSize);
}

RLBIND char *EncodeDataBase64_(const unsigned char *data, int dataSize, int *outputSize)
{
    return EncodeDataBase64(data, dataSize, outputSize);
}

RLBIND unsigned char *DecodeDataBase64_(const unsigned char *data, int *outputSize)
{
    return DecodeDataBase64(data, outputSize);
}

RLBIND bool IsKeyPressed_(int key)
{
    return IsKeyPressed(key);
}

RLBIND bool IsKeyPressedRepeat_(int key)
{
    return IsKeyPressedRepeat(key);
}

RLBIND bool IsKeyDown_(int key)
{
    return IsKeyDown(key);
}

RLBIND bool IsKeyReleased_(int key)
{
    return IsKeyReleased(key);
}

RLBIND bool IsKeyUp_(int key)
{
    return IsKeyUp(key);
}

RLBIND void SetExitKey_(int key)
{
    SetExitKey(key);
}

RLBIND int GetKeyPressed_(void)
{
    return GetKeyPressed();
}

RLBIND int GetCharPressed_(void)
{
    return GetCharPressed();
}

RLBIND bool IsGamepadAvailable_(int gamepad)
{
    return IsGamepadAvailable(gamepad);
}

RLBIND const char *GetGamepadName_(int gamepad)
{
    return GetGamepadName(gamepad);
}

RLBIND bool IsGamepadButtonPressed_(int gamepad, int button)
{
    return IsGamepadButtonPressed(gamepad, button);
}

RLBIND bool IsGamepadButtonDown_(int gamepad, int button)
{
    return IsGamepadButtonDown(gamepad, button);
}

RLBIND bool IsGamepadButtonReleased_(int gamepad, int button)
{
    return IsGamepadButtonReleased(gamepad, button);
}

RLBIND bool IsGamepadButtonUp_(int gamepad, int button)
{
    return IsGamepadButtonUp(gamepad, button);
}

RLBIND int GetGamepadButtonPressed_(void)
{
    return GetGamepadButtonPressed();
}

RLBIND int GetGamepadAxisCount_(int gamepad)
{
    return GetGamepadAxisCount(gamepad);
}

RLBIND float GetGamepadAxisMovement_(int gamepad, int axis)
{
    return GetGamepadAxisMovement(gamepad, axis);
}

RLBIND int SetGamepadMappings_(const char *mappings)
{
    return SetGamepadMappings(mappings);
}

RLBIND bool IsMouseButtonPressed_(int button)
{
    return IsMouseButtonPressed(button);
}

RLBIND bool IsMouseButtonDown_(int button)
{
    return IsMouseButtonDown(button);
}

RLBIND bool IsMouseButtonReleased_(int button)
{
    return IsMouseButtonReleased(button);
}

RLBIND bool IsMouseButtonUp_(int button)
{
    return IsMouseButtonUp(button);
}

RLBIND int GetMouseX_(void)
{
    return GetMouseX();
}

RLBIND int GetMouseY_(void)
{
    return GetMouseY();
}

RLBIND void SetMousePosition_(int x, int y)
{
    SetMousePosition(x, y);
}

RLBIND void SetMouseOffset_(int offsetX, int offsetY)
{
    SetMouseOffset(offsetX, offsetY);
}

RLBIND void SetMouseScale_(float scaleX, float scaleY)
{
    SetMouseScale(scaleX, scaleY);
}

RLBIND float GetMouseWheelMove_(void)
{
    return GetMouseWheelMove();
}

RLBIND void SetMouseCursor_(int cursor)
{
    SetMouseCursor(cursor);
}

RLBIND int GetTouchX_(void)
{
    return GetTouchX();
}

RLBIND int GetTouchY_(void)
{
    return GetTouchY();
}

RLBIND int GetTouchPointId_(int index)
{
    return GetTouchPointId(index);
}

RLBIND int GetTouchPointCount_(void)
{
    return GetTouchPointCount();
}

RLBIND void SetGesturesEnabled_(unsigned int flags)
{
    SetGesturesEnabled(flags);
}

RLBIND bool IsGestureDetected_(int gesture)
{
    return IsGestureDetected(gesture);
}

RLBIND int GetGestureDetected_(void)
{
    return GetGestureDetected();
}

RLBIND float GetGestureHoldDuration_(void)
{
    return GetGestureHoldDuration();
}

RLBIND float GetGestureDragAngle_(void)
{
    return GetGestureDragAngle();
}

RLBIND float GetGesturePinchAngle_(void)
{
    return GetGesturePinchAngle();
}

RLBIND void UpdateCamera_(Camera *camera, int mode)
{
    UpdateCamera(camera, mode);
}

RLBIND bool CheckCollisionPointPoly_(Vector2 point, Vector2 *points, int pointCount)
{
    return CheckCollisionPointPoly(point, points, pointCount);
}

RLBIND void ImageFormat_(Image *image, int newFormat)
{
    ImageFormat(image, newFormat);
}

RLBIND void ImageAlphaCrop_(Image *image, float threshold)
{
    ImageAlphaCrop(image, threshold);
}

RLBIND void ImageAlphaPremultiply_(Image *image)
{
    ImageAlphaPremultiply(image);
}

RLBIND void ImageBlurGaussian_(Image *image, int blurSize)
{
    ImageBlurGaussian(image, blurSize);
}

RLBIND void ImageResize_(Image *image, int newWidth, int newHeight)
{
    ImageResize(image, newWidth, newHeight);
}

RLBIND void ImageResizeNN_(Image *image, int newWidth,int newHeight)
{
    ImageResizeNN(image, newWidth, newHeight);
}

RLBIND void ImageMipmaps_(Image *image)
{
    ImageMipmaps(image);
}

RLBIND void ImageDither_(Image *image, int rBpp, int gBpp, int bBpp, int aBpp)
{
    ImageDither(image, rBpp, gBpp, bBpp, aBpp);
}

RLBIND void ImageFlipVertical_(Image *image)
{
    ImageFlipVertical(image);
}

RLBIND void ImageFlipHorizontal_(Image *image)
{
    ImageFlipHorizontal(image);
}

RLBIND void ImageRotate_(Image *image, int degrees)
{
    ImageRotate(image, degrees);
}

RLBIND void ImageRotateCW_(Image *image)
{
    ImageRotateCW(image);
}

RLBIND void ImageRotateCCW_(Image *image)
{
    ImageRotateCCW(image);
}

RLBIND void ImageColorInvert_(Image *image)
{
    ImageColorInvert(image);
}

RLBIND void ImageColorGrayscale_(Image *image)
{
    ImageColorGrayscale(image);
}

RLBIND void ImageColorContrast_(Image *image, float contrast)
{
    ImageColorContrast(image, contrast);
}

RLBIND void ImageColorBrightness_(Image *image, int brightness)
{
    ImageColorBrightness(image, brightness);
}

RLBIND void UnloadImageColors_(Color *colors)
{
    UnloadImageColors(colors);
}

RLBIND void UnloadImagePalette_(Color *colors)
{
    UnloadImagePalette(colors);
}

RLBIND void GenTextureMipmaps_(Texture2D *texture)
{
    GenTextureMipmaps(texture);
}

RLBIND int GetPixelDataSize_(int width, int height, int format)
{
    return GetPixelDataSize(width, height, format);
}

RLBIND GlyphInfo *LoadFontData_(const unsigned char *fileData, int dataSize, int fontSize, int *codepoints, int codepointCount, int type)
{
    return LoadFontData(fileData, dataSize, fontSize, codepoints, codepointCount, type);
}

RLBIND void UnloadFontData_(GlyphInfo *glyphs, int glyphCount)
{
    UnloadFontData(glyphs, glyphCount);
}

RLBIND void DrawFPS_(int posX, int posY)
{
    DrawFPS(posX, posY);
}

RLBIND void SetTextLineSpacing_(int spacing)
{
    SetTextLineSpacing(spacing);
}

RLBIND int MeasureText_(const char *text, int fontSize)
{
    return MeasureText(text, fontSize);
}

RLBIND char *LoadUTF8_(const int *codepoints, int length)
{
    return LoadUTF8(codepoints, length);
}

RLBIND void UnloadUTF8_(char *text)
{
    UnloadUTF8(text);
}

RLBIND int *LoadCodepoints_(const char *text, int *count)
{
    return LoadCodepoints(text, count);
}

RLBIND void UnloadCodepoints_(int *codepoints)
{
    UnloadCodepoints(codepoints);
}

RLBIND int GetCodepointCount_(const char *text)
{
    return GetCodepointCount(text);
}

RLBIND int GetCodepoint_(const char *text, int *codepointSize)
{
    return GetCodepoint(text, codepointSize);
}

RLBIND int GetCodepointNext_(const char *text, int *codepointSize)
{
    return GetCodepointNext(text, codepointSize);
}

RLBIND int GetCodepointPrevious_(const char *text, int *codepointSize)
{
    return GetCodepointPrevious(text, codepointSize);
}

RLBIND const char *CodepointToUTF8_(int codepoint, int *utf8Size)
{
    return CodepointToUTF8(codepoint, utf8Size);
}

RLBIND int TextCopy_(char *dst, const char *src)
{
    return TextCopy(dst, src);
}

RLBIND bool TextIsEqual_(const char *text1, const char *text2)
{
    return TextIsEqual(text1, text2);
}

RLBIND unsigned int TextLength_(const char *text)
{
    return TextLength(text);
}

RLBIND const char *TextSubtext_(const char *text, int position, int length)
{
    return TextSubtext(text, position, length);
}

RLBIND char *TextReplace_(char *text, const char *replace, const char *by)
{
    return TextReplace(text, replace, by);
}

RLBIND char *TextInsert_(const char *text, const char *insert, int position)
{
    return TextInsert(text, insert, position);
}

RLBIND const char *TextJoin_(const char **textList, int count, const char *delimiter)
{
    return TextJoin(textList, count, delimiter);
}

RLBIND const char **TextSplit_(const char *text, char delimiter, int *count)
{
    return TextSplit(text, delimiter, count);
}

RLBIND void TextAppend_(char *text, const char *append, int *position)
{
    TextAppend(text, append, position);
}

RLBIND int TextFindIndex_(const char *text, const char *find)
{
    return TextFindIndex(text, find);
}

RLBIND const char *TextToUpper_(const char *text)
{
    return TextToUpper(text);
}

RLBIND const char *TextToLower_(const char *text)
{
    return TextToLower(text);
}

RLBIND const char *TextToPascal_(const char *text)
{
    return TextToPascal(text);
}

RLBIND int TextToInteger_(const char *text)
{
    return TextToInteger(text);
}

RLBIND void DrawGrid_(int slices, float spacing)
{
    DrawGrid(slices, spacing);
}

RLBIND void UploadMesh_(Mesh *mesh, bool dynamic)
{
    UploadMesh(mesh, dynamic);
}

RLBIND void GenMeshTangents_(Mesh *mesh)
{
    GenMeshTangents(mesh);
}

RLBIND Material *LoadMaterials_(const char *fileName, int *materialCount)
{
    return LoadMaterials(fileName, materialCount);
}

RLBIND void SetModelMeshMaterial_(Model *model, int meshId, int materialId)
{
    SetModelMeshMaterial(model, meshId, materialId);
}

RLBIND ModelAnimation *LoadModelAnimations_(const char *fileName, int *animCount)
{
    return LoadModelAnimations(fileName, animCount);
}

RLBIND void UnloadModelAnimations_(ModelAnimation *animations, int animCount)
{
    UnloadModelAnimations(animations, animCount);
}

RLBIND void InitAudioDevice_(void)
{
    InitAudioDevice();
}

RLBIND void CloseAudioDevice_(void)
{
    CloseAudioDevice();
}

RLBIND bool IsAudioDeviceReady_(void)
{
    return IsAudioDeviceReady();
}

RLBIND void SetMasterVolume_(float volume)
{
    SetMasterVolume(volume);
}

RLBIND void WaveCrop_(Wave *wave, int initSample, int finalSample)
{
    WaveCrop(wave, initSample, finalSample);
}

RLBIND void WaveFormat_(Wave *wave, int sampleRate, int sampleSize, int channels)
{
    WaveFormat(wave, sampleRate, sampleSize, channels);
}

RLBIND void UnloadWaveSamples_(float *samples)
{
    UnloadWaveSamples(samples);
}

RLBIND void SetAudioStreamBufferSizeDefault_(int size)
{
    SetAudioStreamBufferSizeDefault(size);
}