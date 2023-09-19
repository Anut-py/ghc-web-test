/**
 * @file rl_bindings.h
 * @author Anut-py
 * @brief Required methods for binding Haskell to Raylib
 *
 * Haskell does not support interfacing with C directly through structs (e.g. Vector2).
 * In order to achieve this, wrapper functions that use pointers need to be written. This
 * file contains wrapper functions for all Raylib functions that do not take pointers.
 */

#include <raylib.h>

void SetWindowIcon_(Image *a);

Vector2 *GetMonitorPosition_(int a);

Vector2 *GetWindowPosition_();

Vector2 *GetWindowScaleDPI_();

void ClearBackground_(Color *a);

void BeginMode2D_(Camera2D *a);

void BeginMode3D_(Camera3D *a);

void BeginTextureMode_(RenderTexture *a);

void BeginShaderMode_(Shader *a);

void BeginVrStereoMode_(VrStereoConfig *a);

VrStereoConfig *LoadVrStereoConfig_(VrDeviceInfo *a);

void UnloadVrStereoConfig_(VrStereoConfig *a);

Shader *LoadShader_(char *a, char *b);

Shader *LoadShaderFromMemory_(char *a, char *b);

bool IsShaderReady_(Shader *a);

int GetShaderLocation_(Shader *a, char *b);

int GetShaderLocationAttrib_(Shader *a, char *b);

void SetShaderValue_(Shader *a, int b, const void *c, int d);

void SetShaderValueV_(Shader *a, int b, const void *c, int d, int e);

void SetShaderValueMatrix_(Shader *a, int b, Matrix *c);

void SetShaderValueTexture_(Shader *a, int b, Texture *c);

void UnloadShader_(Shader *a);

Ray *GetMouseRay_(Vector2 *a, Camera3D *b);

Matrix *GetCameraMatrix_(Camera3D *a);

Matrix *GetCameraMatrix2D_(Camera2D *a);

Vector2 *GetWorldToScreen_(Vector3 *a, Camera3D *b);

Vector2 *GetScreenToWorld2D_(Vector2 *a, Camera2D *b);

Vector2 *GetWorldToScreenEx_(Vector3 *a, Camera3D *b, int c, int d);

Vector2 *GetWorldToScreen2D_(Vector2 *a, Camera2D *b);

FilePathList *LoadDirectoryFiles_(char *a);

FilePathList *LoadDirectoryFilesEx_(char *a, char *b, int c);

void UnloadDirectoryFiles_(FilePathList *a);

FilePathList *LoadDroppedFiles_();

void UnloadDroppedFiles_(FilePathList *a);

Vector2 *GetMousePosition_();

Vector2 *GetMouseDelta_();

Vector2 *GetMouseWheelMoveV_();

Vector2 *GetTouchPosition_(int a);

Vector2 *GetGestureDragVector_();

Vector2 *GetGesturePinchVector_();

void UpdateCameraPro_(Camera3D *a, Vector3 *b, Vector3 *c, float d);

void SetShapesTexture_(Texture *a, Rectangle *b);

void DrawPixel_(int a, int b, Color *c);

void DrawPixelV_(Vector2 *a, Color *b);

void DrawLine_(int a, int b, int c, int d, Color *e);

void DrawLineV_(Vector2 *a, Vector2 *b, Color *c);

void DrawLineEx_(Vector2 *a, Vector2 *b, float c, Color *d);

void DrawLineBezier_(Vector2 *a, Vector2 *b, float c, Color *d);

void DrawLineBezierQuad_(Vector2 *a, Vector2 *b, Vector2 *c, float d, Color *e);

void DrawLineBezierCubic_(Vector2 *a, Vector2 *b, Vector2 *c, Vector2 *d, float e, Color *f);

void DrawLineBSpline_(Vector2 *a, int b, float c, Color *d);

void DrawLineCatmullRom_(Vector2 *a, int b, float c, Color *d);

void DrawLineStrip_(Vector2 *a, int b, Color *c);

void DrawCircle_(int a, int b, float c, Color *d);

void DrawCircleSector_(Vector2 *a, float b, float c, float d, int e, Color *f);

void DrawCircleSectorLines_(Vector2 *a, float b, float c, float d, int e, Color *f);

void DrawCircleGradient_(int a, int b, float c, Color *d, Color *e);

void DrawCircleV_(Vector2 *a, float b, Color *c);

void DrawCircleLines_(int a, int b, float c, Color *d);

void DrawEllipse_(int a, int b, float c, float d, Color *e);

void DrawEllipseLines_(int a, int b, float c, float d, Color *e);

void DrawRing_(Vector2 *a, float b, float c, float d, float e, int f, Color *g);

void DrawRingLines_(Vector2 *a, float b, float c, float d, float e, int f, Color *g);

void DrawRectangle_(int a, int b, int c, int d, Color *e);

void DrawRectangleV_(Vector2 *a, Vector2 *b, Color *c);

void DrawRectangleRec_(Rectangle *a, Color *b);

void DrawRectanglePro_(Rectangle *a, Vector2 *b, float c, Color *d);

void DrawRectangleGradientV_(int a, int b, int c, int d, Color *e, Color *f);

void DrawRectangleGradientH_(int a, int b, int c, int d, Color *e, Color *f);

void DrawRectangleGradientEx_(Rectangle *a, Color *b, Color *c, Color *d, Color *e);

void DrawRectangleLines_(int a, int b, int c, int d, Color *e);

void DrawRectangleLinesEx_(Rectangle *a, float b, Color *c);

void DrawRectangleRounded_(Rectangle *a, float b, int c, Color *d);

void DrawRectangleRoundedLines_(Rectangle *a, float b, int c, float d, Color *e);

void DrawTriangle_(Vector2 *a, Vector2 *b, Vector2 *c, Color *d);

void DrawTriangleLines_(Vector2 *a, Vector2 *b, Vector2 *c, Color *d);

void DrawTriangleFan_(Vector2 *a, int b, Color *c);

void DrawTriangleStrip_(Vector2 *a, int b, Color *c);

void DrawPoly_(Vector2 *a, int b, float c, float d, Color *e);

void DrawPolyLines_(Vector2 *a, int b, float c, float d, Color *e);

void DrawPolyLinesEx_(Vector2 *a, int b, float c, float d, float e, Color *f);

int CheckCollisionRecs_(Rectangle *a, Rectangle *b);

int CheckCollisionCircles_(Vector2 *a, float b, Vector2 *c, float d);

int CheckCollisionCircleRec_(Vector2 *a, float b, Rectangle *c);

int CheckCollisionPointRec_(Vector2 *a, Rectangle *b);

int CheckCollisionPointCircle_(Vector2 *a, Vector2 *b, float c);

int CheckCollisionPointTriangle_(Vector2 *a, Vector2 *b, Vector2 *c, Vector2 *d);

int CheckCollisionLines_(Vector2 *a, Vector2 *b, Vector2 *c, Vector2 *d, Vector2 *e);

int CheckCollisionPointLine_(Vector2 *a, Vector2 *b, Vector2 *c, int d);

Rectangle *GetCollisionRec_(Rectangle *a, Rectangle *b);

Image *LoadImage_(char *a);

Image *LoadImageRaw_(char *a, int b, int c, int d, int e);

Image *LoadImageSvg_(char *a, int b, int c);

Image *LoadImageAnim_(char *a, int *b);

Image *LoadImageFromMemory_(char *a, unsigned char *b, int c);

Image *LoadImageFromTexture_(Texture *a);

Image *LoadImageFromScreen_();

bool IsImageReady_(Image *a);

void UnloadImage_(Image *a);

int ExportImage_(Image *a, char *b);

unsigned char *ExportImageToMemory_(Image *a, char *fileType, int *fileSize);

int ExportImageAsCode_(Image *a, char *b);

Image *GenImageColor_(int a, int b, Color *c);

Image *GenImageGradientLinear_(int a, int b, int c, Color *d, Color *e);

Image *GenImageGradientRadial_(int a, int b, float c, Color *d, Color *e);

Image *GenImageGradientSquare_(int a, int b, float c, Color *d, Color *e);

Image *GenImageChecked_(int a, int b, int c, int d, Color *e, Color *f);

Image *GenImageWhiteNoise_(int a, int b, float c);

Image *GenImagePerlinNoise_(int a, int b, int c, int d, float e);

Image *GenImageCellular_(int a, int b, int c);

Image *GenImageText_(int a, int b, char *c);

Image *ImageCopy_(Image *a);

Image *ImageFromImage_(Image *a, Rectangle *b);

Image *ImageText_(char *a, int b, Color *c);

Image *ImageTextEx_(Font *a, char *b, float c, float d, Color *e);

void ImageToPOT_(Image *a, Color *b);

void ImageCrop_(Image *a, Rectangle *b);

void ImageAlphaClear_(Image *a, Color *b, float c);

void ImageAlphaMask_(Image *a, Image *b);

void ImageResizeCanvas_(Image *a, int b, int c, int d, int e, Color *f);

void ImageColorTint_(Image *a, Color *b);

void ImageColorReplace_(Image *a, Color *b, Color *c);

Color *LoadImageColors_(Image *a);

Color *LoadImagePalette_(Image *a, int b, int *c);

Rectangle *GetImageAlphaBorder_(Image *a, float b);

Color *GetImageColor_(Image *a, int b, int c);

void ImageClearBackground_(Image *a, Color *b);

void ImageDrawPixel_(Image *a, int b, int c, Color *d);

void ImageDrawPixelV_(Image *a, Vector2 *b, Color *c);

void ImageDrawLine_(Image *a, int b, int c, int d, int e, Color *f);

void ImageDrawLineV_(Image *a, Vector2 *b, Vector2 *c, Color *d);

void ImageDrawCircle_(Image *a, int b, int c, int d, Color *e);

void ImageDrawCircleV_(Image *a, Vector2 *b, int c, Color *d);

void ImageDrawCircleLines_(Image *a, int b, int c, int d, Color *e);

void ImageDrawCircleLinesV_(Image *a, Vector2 *b, int c, Color *d);

void ImageDrawRectangle_(Image *a, int b, int c, int d, int e, Color *f);

void ImageDrawRectangleV_(Image *a, Vector2 *b, Vector2 *c, Color *d);

void ImageDrawRectangleRec_(Image *a, Rectangle *b, Color *c);

void ImageDrawRectangleLines_(Image *a, Rectangle *b, int c, Color *d);

void ImageDraw_(Image *a, Image *b, Rectangle *c, Rectangle *d, Color *e);

void ImageDrawText_(Image *a, char *b, int c, int d, int e, Color *f);

void ImageDrawTextEx_(Image *a, Font *b, char *c, Vector2 *d, float e, float f, Color *g);

Texture *LoadTexture_(char *a);

Texture *LoadTextureFromImage_(Image *a);

Texture *LoadTextureCubemap_(Image *a, int b);

RenderTexture *LoadRenderTexture_(int a, int b);

bool IsTextureReady_(Texture *a);

void UnloadTexture_(Texture *a);

bool IsRenderTextureReady_(RenderTexture *a);

void UnloadRenderTexture_(RenderTexture *a);

void UpdateTexture_(Texture *a, const void *b);

void UpdateTextureRec_(Texture *a, Rectangle *b, const void *c);

void SetTextureFilter_(Texture *a, int b);

void SetTextureWrap_(Texture *a, int b);

void DrawTexture_(Texture *a, int b, int c, Color *d);

void DrawTextureV_(Texture *a, Vector2 *b, Color *c);

void DrawTextureEx_(Texture *a, Vector2 *b, float c, float d, Color *e);

void DrawTextureRec_(Texture *a, Rectangle *b, Vector2 *c, Color *d);

void DrawTexturePro_(Texture *a, Rectangle *b, Rectangle *c, Vector2 *d, float e, Color *f);

void DrawTextureNPatch_(Texture *a, NPatchInfo *b, Rectangle *c, Vector2 *d, float e, Color *f);

Color *Fade_(Color *a, float b);

int ColorToInt_(Color *a);

Vector4 *ColorNormalize_(Color *a);

Color *ColorFromNormalized_(Vector4 *a);

Vector3 *ColorToHSV_(Color *a);

Color *ColorFromHSV_(float a, float b, float c);

Color *ColorAlpha_(Color *a, float b);

Color *ColorAlphaBlend_(Color *a, Color *b, Color *c);

Color *GetColor_(unsigned int a);

Color *GetPixelColor_(void *a, int b);

void SetPixelColor_(void *a, Color *b, int c);

Font *GetFontDefault_();

Font *LoadFont_(char *a);

Font *LoadFontEx_(char *a, int b, int *c, int d);

Font *LoadFontFromImage_(Image *a, Color *b, int c);

Font *LoadFontFromMemory_(char *a, unsigned char *b, int c, int d, int *e, int f);

Image *GenImageFontAtlas_(GlyphInfo *a, Rectangle **b, int c, int d, int e, int f);

bool IsFontReady_(Font *a);

void UnloadFont_(Font *a);

int ExportFontAsCode_(Font *a, char *b);

void DrawText_(char *a, int b, int c, int d, Color *e);

void DrawTextEx_(Font *a, char *b, Vector2 *c, float d, float e, Color *f);

void DrawTextPro_(Font *a, char *b, Vector2 *c, Vector2 *d, float e, float f, float g, Color *h);

void DrawTextCodepoint_(Font *a, int b, Vector2 *c, float d, Color *e);

void DrawTextCodepoints_(Font *a, int *b, int c, Vector2 *d, float e, float f, Color *g);

Vector2 *MeasureTextEx_(Font *a, char *b, float c, float d);

int GetGlyphIndex_(Font *a, int b);

GlyphInfo *GetGlyphInfo_(Font *a, int b);

Rectangle *GetGlyphAtlasRec_(Font *a, int b);

void DrawLine3D_(Vector3 *a, Vector3 *b, Color *c);

void DrawPoint3D_(Vector3 *a, Color *b);

void DrawCircle3D_(Vector3 *a, float b, Vector3 *c, float d, Color *e);

void DrawTriangle3D_(Vector3 *a, Vector3 *b, Vector3 *c, Color *d);

void DrawTriangleStrip3D_(Vector3 *a, int b, Color *c);

void DrawCube_(Vector3 *a, float b, float c, float d, Color *e);

void DrawCubeV_(Vector3 *a, Vector3 *b, Color *c);

void DrawCubeWires_(Vector3 *a, float b, float c, float d, Color *e);

void DrawCubeWiresV_(Vector3 *a, Vector3 *b, Color *c);

void DrawCubeTexture_(Texture *a, Vector3 *b, float c, float d, float e, Color *f);

void DrawCubeTextureRec_(Texture *a, Rectangle *b, Vector3 *c, float d, float e, float f, Color *g);

void DrawSphere_(Vector3 *a, float b, Color *c);

void DrawSphereEx_(Vector3 *a, float b, int c, int d, Color *e);

void DrawSphereWires_(Vector3 *a, float b, int c, int d, Color *e);

void DrawCylinder_(Vector3 *a, float b, float c, float d, int e, Color *f);

void DrawCylinderEx_(Vector3 *a, Vector3 *b, float c, float d, int e, Color *f);

void DrawCylinderWires_(Vector3 *a, float b, float c, float d, int e, Color *f);

void DrawCylinderWiresEx_(Vector3 *a, Vector3 *b, float c, float d, int e, Color *f);

void DrawCapsule_(Vector3 *a, Vector3 *b, float c, int d, int e, Color *f);

void DrawCapsuleEx_(Vector3 *a, Vector3 *b, float c, int d, int e, Color *f);

void DrawPlane_(Vector3 *a, Vector2 *b, Color *c);

void DrawRay_(Ray *a, Color *b);

Model *LoadModel_(char *a);

Model *LoadModelFromMesh_(Mesh *a);

bool IsModelReady_(Model *a);

void UnloadModel_(Model *a);

BoundingBox *GetModelBoundingBox_(Model *a);

void DrawModel_(Model *a, Vector3 *b, float c, Color *d);

void DrawModelEx_(Model *a, Vector3 *b, Vector3 *c, float d, Vector3 *e, Color *f);

void DrawModelWires_(Model *a, Vector3 *b, float c, Color *d);

void DrawModelWiresEx_(Model *a, Vector3 *b, Vector3 *c, float d, Vector3 *e, Color *f);

void DrawBoundingBox_(BoundingBox *a, Color *b);

void DrawBillboard_(Camera3D *a, Texture *b, Vector3 *c, float d, Color *e);

void DrawBillboardRec_(Camera3D *a, Texture *b, Rectangle *c, Vector3 *d, Vector2 *e, Color *f);

void DrawBillboardPro_(Camera3D *a, Texture *b, Rectangle *c, Vector3 *d, Vector3 *e, Vector2 *f, Vector2 *g, float h, Color *i);

void UpdateMeshBuffer_(Mesh *a, int b, const void *c, int d, int e);

void UnloadMesh_(Mesh *a);

void DrawMesh_(Mesh *a, Material *b, Matrix *c);

void DrawMeshInstanced_(Mesh *a, Material *b, Matrix *c, int d);

int ExportMesh_(Mesh *a, char *b);

BoundingBox *GetMeshBoundingBox_(Mesh *a);

Mesh *GenMeshPoly_(int a, float b);

Mesh *GenMeshPlane_(float a, float b, int c, int d);

Mesh *GenMeshCube_(float a, float b, float c);

Mesh *GenMeshSphere_(float a, int b, int c);

Mesh *GenMeshHemiSphere_(float a, int b, int c);

Mesh *GenMeshCylinder_(float a, float b, int c);

Mesh *GenMeshCone_(float a, float b, int c);

Mesh *GenMeshTorus_(float a, float b, int c, int d);

Mesh *GenMeshKnot_(float a, float b, int c, int d);

Mesh *GenMeshHeightmap_(Image *a, Vector3 *b);

Mesh *GenMeshCubicmap_(Image *a, Vector3 *b);

Material *LoadMaterialDefault_();

bool IsMaterialReady_(Material *a);

void UnloadMaterial_(Material *a);

void SetMaterialTexture_(Material *a, int b, Texture *c);

void UpdateModelAnimation_(Model *a, ModelAnimation *b, int c);

void UnloadModelAnimation_(ModelAnimation *a);

int IsModelAnimationValid_(Model *a, ModelAnimation *b);

int CheckCollisionSpheres_(Vector3 *a, float b, Vector3 *c, float d);

int CheckCollisionBoxes_(BoundingBox *a, BoundingBox *b);

int CheckCollisionBoxSphere_(BoundingBox *a, Vector3 *b, float c);

RayCollision *GetRayCollisionSphere_(Ray *a, Vector3 *b, float c);

RayCollision *GetRayCollisionBox_(Ray *a, BoundingBox *b);

RayCollision *GetRayCollisionMesh_(Ray *a, Mesh *b, Matrix *c);

RayCollision *GetRayCollisionTriangle_(Ray *a, Vector3 *b, Vector3 *c, Vector3 *d);

RayCollision *GetRayCollisionQuad_(Ray *a, Vector3 *b, Vector3 *c, Vector3 *d, Vector3 *e);

Wave *LoadWave_(char *a);

Wave *LoadWaveFromMemory_(char *a, unsigned char *b, int c);

Sound *LoadSound_(char *a);

Sound *LoadSoundFromWave_(Wave *a);

Sound *LoadSoundAlias_(Sound *a);

void UpdateSound_(Sound *a, const void *b, int c);

bool IsWaveReady_(Wave *a);

void UnloadWave_(Wave *a);

bool IsSoundReady_(Sound *a);

void UnloadSound_(Sound *a);

void UnloadSoundAlias_(Sound *a);

int ExportWave_(Wave *a, char *b);

int ExportWaveAsCode_(Wave *a, char *b);

void PlaySound_(Sound *a);

void StopSound_(Sound *a);

void PauseSound_(Sound *a);

void ResumeSound_(Sound *a);

int IsSoundPlaying_(Sound *a);

void SetSoundVolume_(Sound *a, float b);

void SetSoundPitch_(Sound *a, float b);

void SetSoundPan_(Sound *a, float b);

Wave *WaveCopy_(Wave *a);

float *LoadWaveSamples_(Wave *a);

Music *LoadMusicStream_(char *a);

Music *LoadMusicStreamFromMemory_(char *a, unsigned char *b, int c);

bool IsMusicReady_(Music *a);

void UnloadMusicStream_(Music *a);

void PlayMusicStream_(Music *a);

int IsMusicStreamPlaying_(Music *a);

void UpdateMusicStream_(Music *a);

void StopMusicStream_(Music *a);

void PauseMusicStream_(Music *a);

void ResumeMusicStream_(Music *a);

void SeekMusicStream_(Music *a, float b);

void SetMusicVolume_(Music *a, float b);

void SetMusicPitch_(Music *a, float b);

void SetMusicPan_(Music *a, float b);

float GetMusicTimeLength_(Music *a);

float GetMusicTimePlayed_(Music *a);

AudioStream *LoadAudioStream_(unsigned int a, unsigned int b, unsigned int c);

bool IsAudioStreamReady_(AudioStream *a);

void UnloadAudioStream_(AudioStream *a);

void UpdateAudioStream_(AudioStream *a, const void *b, int c);

int IsAudioStreamProcessed_(AudioStream *a);

void PlayAudioStream_(AudioStream *a);

void PauseAudioStream_(AudioStream *a);

void ResumeAudioStream_(AudioStream *a);

int IsAudioStreamPlaying_(AudioStream *a);

void StopAudioStream_(AudioStream *a);

void SetAudioStreamVolume_(AudioStream *a, float b);

void SetAudioStreamPitch_(AudioStream *a, float b);

void SetAudioStreamPan_(AudioStream *a, float b);

void SetAudioStreamCallback_(AudioStream *a, AudioCallback *b);

void AttachAudioStreamProcessor_(AudioStream *a, AudioCallback *b);

void DetachAudioStreamProcessor_(AudioStream *a, AudioCallback *b);

void AttachAudioMixedProcessor_(AudioCallback *a);

void DetachAudioMixedProcessor_(AudioCallback *a);

void InitWindow_(int width, int height, const char *title);

bool WindowShouldClose_(void);

void CloseWindow_(void);

bool IsWindowReady_(void);

bool IsWindowFullscreen_(void);

bool IsWindowHidden_(void);

bool IsWindowMinimized_(void);

bool IsWindowMaximized_(void);

bool IsWindowFocused_(void);

bool IsWindowResized_(void);

bool IsWindowState_(unsigned int flag);

void SetWindowState_(unsigned int flags);

void ClearWindowState_(unsigned int flags);

void ToggleFullscreen_(void);

void ToggleBorderlessWindowed_(void);

void MaximizeWindow_(void);

void MinimizeWindow_(void);

void RestoreWindow_(void);

void SetWindowIcons_(Image *images, int count);

void SetWindowTitle_(const char *title);

void SetWindowPosition_(int x, int y);

void SetWindowMonitor_(int monitor);

void SetWindowMinSize_(int width, int height);

void SetWindowMaxSize_(int width, int height);

void SetWindowSize_(int width, int height);

void SetWindowOpacity_(float opacity);

void SetWindowFocused_(void);

void *GetWindowHandle_(void);

int GetScreenWidth_(void);

int GetScreenHeight_(void);

int GetRenderWidth_(void);

int GetRenderHeight_(void);

int GetMonitorCount_(void);

int GetCurrentMonitor_(void);

int GetMonitorWidth_(int monitor);

int GetMonitorHeight_(int monitor);

int GetMonitorPhysicalWidth_(int monitor);

int GetMonitorPhysicalHeight_(int monitor);

int GetMonitorRefreshRate_(int monitor);

const char *GetMonitorName_(int monitor);

void SetClipboardText_(const char *text);

const char *GetClipboardText_(void);

void EnableEventWaiting_(void);

void DisableEventWaiting_(void);

void SwapScreenBuffer_(void);

void PollInputEvents_(void);

void WaitTime_(double seconds);

void ShowCursor_(void);

void HideCursor_(void);

bool IsCursorHidden_(void);

void EnableCursor_(void);

void DisableCursor_(void);

bool IsCursorOnScreen_(void);

void BeginDrawing_(void);

void EndDrawing_(void);

void EndMode2D_(void);

void EndMode3D_(void);

void EndTextureMode_(void);

void EndShaderMode_(void);

void BeginBlendMode_(int mode);

void EndBlendMode_(void);

void BeginScissorMode_(int x, int y, int width, int height);

void EndScissorMode_(void);

void EndVrStereoMode_(void);

void SetTargetFPS_(int fps);

int GetFPS_(void);

float GetFrameTime_(void);

double GetTime_(void);

int GetRandomValue_(int min, int max);

void SetRandomSeed_(unsigned int seed);

void TakeScreenshot_(const char *fileName);

void SetConfigFlags_(unsigned int flags);

void SetTraceLogLevel_(int logLevel);

void *MemAlloc_(unsigned int size);

void *MemRealloc_(void *ptr, unsigned int size);

void MemFree_(void *ptr);

void OpenURL_(const char *url);

void SetTraceLogCallback_(TraceLogCallback callback);

void SetLoadFileDataCallback_(LoadFileDataCallback callback);

void SetSaveFileDataCallback_(SaveFileDataCallback callback);

void SetLoadFileTextCallback_(LoadFileTextCallback callback);

void SetSaveFileTextCallback_(SaveFileTextCallback callback);

unsigned char *LoadFileData_(const char *fileName, int *dataSize);

void UnloadFileData_(unsigned char *data);

bool SaveFileData_(const char *fileName, void *data, int dataSize);

bool ExportDataAsCode_(const unsigned char *data, int dataSize, const char *fileName);

char *LoadFileText_(const char *fileName);

void UnloadFileText_(char *text);

bool SaveFileText_(const char *fileName, char *text);

bool FileExists_(const char *fileName);

bool DirectoryExists_(const char *dirPath);

bool IsFileExtension_(const char *fileName, const char *ext);

int GetFileLength_(const char *fileName);

const char *GetFileExtension_(const char *fileName);

const char *GetFileName_(const char *filePath);

const char *GetFileNameWithoutExt_(const char *filePath);

const char *GetDirectoryPath_(const char *filePath);

const char *GetPrevDirectoryPath_(const char *dirPath);

const char *GetWorkingDirectory_(void);

const char *GetApplicationDirectory_(void);

bool ChangeDirectory_(const char *dir);

bool IsPathFile_(const char *path);

bool IsFileDropped_(void);

long GetFileModTime_(const char *fileName);

unsigned char *CompressData_(const unsigned char *data, int dataSize, int *compDataSize);

unsigned char *DecompressData_(const unsigned char *compData, int compDataSize, int *dataSize);

char *EncodeDataBase64_(const unsigned char *data, int dataSize, int *outputSize);

unsigned char *DecodeDataBase64_(const unsigned char *data, int *outputSize);

bool IsKeyPressed_(int key);

bool IsKeyPressedRepeat_(int key);

bool IsKeyDown_(int key);

bool IsKeyReleased_(int key);

bool IsKeyUp_(int key);

void SetExitKey_(int key);

int GetKeyPressed_(void);

int GetCharPressed_(void);

bool IsGamepadAvailable_(int gamepad);

const char *GetGamepadName_(int gamepad);

bool IsGamepadButtonPressed_(int gamepad, int button);

bool IsGamepadButtonDown_(int gamepad, int button);

bool IsGamepadButtonReleased_(int gamepad, int button);

bool IsGamepadButtonUp_(int gamepad, int button);

int GetGamepadButtonPressed_(void);

int GetGamepadAxisCount_(int gamepad);

float GetGamepadAxisMovement_(int gamepad, int axis);

int SetGamepadMappings_(const char *mappings);

bool IsMouseButtonPressed_(int button);

bool IsMouseButtonDown_(int button);

bool IsMouseButtonReleased_(int button);

bool IsMouseButtonUp_(int button);

int GetMouseX_(void);

int GetMouseY_(void);

void SetMousePosition_(int x, int y);

void SetMouseOffset_(int offsetX, int offsetY);

void SetMouseScale_(float scaleX, float scaleY);

float GetMouseWheelMove_(void);

void SetMouseCursor_(int cursor);

int GetTouchX_(void);

int GetTouchY_(void);

int GetTouchPointId_(int index);

int GetTouchPointCount_(void);

void SetGesturesEnabled_(unsigned int flags);

bool IsGestureDetected_(int gesture);

int GetGestureDetected_(void);

float GetGestureHoldDuration_(void);

float GetGestureDragAngle_(void);

float GetGesturePinchAngle_(void);

void UpdateCamera_(Camera *camera, int mode);

bool CheckCollisionPointPoly_(Vector2 point, Vector2 *points, int pointCount);

void ImageFormat_(Image *image, int newFormat);

void ImageAlphaCrop_(Image *image, float threshold);

void ImageAlphaPremultiply_(Image *image);

void ImageBlurGaussian_(Image *image, int blurSize);

void ImageResize_(Image *image, int newWidth, int newHeight);

void ImageResizeNN_(Image *image, int newWidth, int newHeight);

void ImageMipmaps_(Image *image);

void ImageDither_(Image *image, int rBpp, int gBpp, int bBpp, int aBpp);

void ImageFlipVertical_(Image *image);

void ImageFlipHorizontal_(Image *image);

void ImageRotate_(Image *image, int degrees);

void ImageRotateCW_(Image *image);

void ImageRotateCCW_(Image *image);

void ImageColorInvert_(Image *image);

void ImageColorGrayscale_(Image *image);

void ImageColorContrast_(Image *image, float contrast);

void ImageColorBrightness_(Image *image, int brightness);

void UnloadImageColors_(Color *colors);

void UnloadImagePalette_(Color *colors);

void GenTextureMipmaps_(Texture2D *texture);

int GetPixelDataSize_(int width, int height, int format);

GlyphInfo *LoadFontData_(const unsigned char *fileData, int dataSize, int fontSize, int *codepoints, int codepointCount, int type);

void UnloadFontData_(GlyphInfo *glyphs, int glyphCount);

void DrawFPS_(int posX, int posY);

void SetTextLineSpacing_(int spacing);

int MeasureText_(const char *text, int fontSize);

char *LoadUTF8_(const int *codepoints, int length);

void UnloadUTF8_(char *text);

int *LoadCodepoints_(const char *text, int *count);

void UnloadCodepoints_(int *codepoints);

int GetCodepointCount_(const char *text);

int GetCodepoint_(const char *text, int *codepointSize);

int GetCodepointNext_(const char *text, int *codepointSize);

int GetCodepointPrevious_(const char *text, int *codepointSize);

const char *CodepointToUTF8_(int codepoint, int *utf8Size);

int TextCopy_(char *dst, const char *src);

bool TextIsEqual_(const char *text1, const char *text2);

unsigned int TextLength_(const char *text);

const char *TextSubtext_(const char *text, int position, int length);

char *TextReplace_(char *text, const char *replace, const char *by);

char *TextInsert_(const char *text, const char *insert, int position);

const char *TextJoin_(const char **textList, int count, const char *delimiter);

const char **TextSplit_(const char *text, char delimiter, int *count);

void TextAppend_(char *text, const char *append, int *position);

int TextFindIndex_(const char *text, const char *find);

const char *TextToUpper_(const char *text);

const char *TextToLower_(const char *text);

const char *TextToPascal_(const char *text);

int TextToInteger_(const char *text);

void DrawGrid_(int slices, float spacing);

void UploadMesh_(Mesh *mesh, bool dynamic);

void GenMeshTangents_(Mesh *mesh);

Material *LoadMaterials_(const char *fileName, int *materialCount);

void SetModelMeshMaterial_(Model *model, int meshId, int materialId);

ModelAnimation *LoadModelAnimations_(const char *fileName, int *animCount);

void UnloadModelAnimations_(ModelAnimation *animations, int animCount);

void InitAudioDevice_(void);

void CloseAudioDevice_(void);

bool IsAudioDeviceReady_(void);

void SetMasterVolume_(float volume);

void WaveCrop_(Wave *wave, int initSample, int finalSample);

void WaveFormat_(Wave *wave, int sampleRate, int sampleSize, int channels);

void UnloadWaveSamples_(float *samples);

void SetAudioStreamBufferSizeDefault_(int size);