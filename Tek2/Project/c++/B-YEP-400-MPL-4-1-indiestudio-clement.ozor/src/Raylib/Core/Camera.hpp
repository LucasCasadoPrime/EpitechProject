/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Camera.hpp
*/

#ifndef BOMBERMAN_CAMERA_HPP
#define BOMBERMAN_CAMERA_HPP

//TODO:
//void SetCameraMode(Camera camera, int mode);                            // Set camera mode (multiple camera modes available)
//void UpdateCamera(Camera *camera);                                      // Update camera position for selected mode
//void SetCameraPanControl(int keyPan);                                   // Set camera pan key to combine with mouse movement (free camera)
//void SetCameraAltControl(int keyAlt);                                   // Set camera alt key to combine with mouse movement (free camera)
//void SetCameraSmoothZoomControl(int keySmoothZoom);                     // Set camera smooth zoom key to combine with mouse (free camera)
//void SetCameraMoveControls(int keyFront, int keyBack, int keyRight, int keyLeft, int keyUp, int keyDown); // Set camera move controls (1st person and 3rd person cameras)


#include "raylib.h"

namespace Raylib {
    namespace Core {
        class CameraB {
            public:
                CameraB(Vector3 position, Vector3 target, Vector3 up, float fovy, CameraProjection projection);
                ~CameraB();

                void setCameraMode(int mode);
                void setPosition(Vector3 position);
                Vector3 getPosition();
                void updateCamera();
                void setCameraPanControl(int keyPan);
                void setCameraAltControl(int keyAlt);
                void setCameraSmoothZoomControl(int keySmoothZoom);
                void setCameraMoveControls(int keyFront, int keyBack, int keyRight, int keyLeft, int keyUp, int keyDown);
                Camera3D getCamera();

            private:
                Camera3D _camera;
        };
    }
}

#endif
