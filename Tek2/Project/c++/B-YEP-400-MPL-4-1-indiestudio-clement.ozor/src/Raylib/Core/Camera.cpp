/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Camera.cpp
*/

#include "Camera.hpp"

Raylib::Core::CameraB::CameraB(Vector3 position, Vector3 target, Vector3 up, float fovy, CameraProjection projection) {
    _camera.position = position;
    _camera.target = target;
    _camera.up = up;
    _camera.fovy = fovy;
    _camera.projection = projection;
}

Raylib::Core::CameraB::~CameraB() {}

void Raylib::Core::CameraB::setCameraMode(int mode) {
    SetCameraMode(_camera, mode);
}

void Raylib::Core::CameraB::updateCamera() {
    UpdateCamera(&_camera);
}

void Raylib::Core::CameraB::setCameraPanControl(int keyPan) {
    SetCameraPanControl(keyPan);
}

void Raylib::Core::CameraB::setCameraAltControl(int keyAlt) {
    SetCameraAltControl(keyAlt);
}

void Raylib::Core::CameraB::setCameraSmoothZoomControl(int keySmoothZoom) {
    SetCameraSmoothZoomControl(keySmoothZoom);
}

void Raylib::Core::CameraB::setCameraMoveControls(int keyFront, int keyBack, int keyRight, int keyLeft, int keyUp, int keyDown) {
    SetCameraMoveControls(keyFront, keyBack, keyRight, keyLeft, keyUp, keyDown);
}

Camera3D Raylib::Core::CameraB::getCamera() {
    return (_camera);
}

void Raylib::Core::CameraB::setPosition(Vector3 position) {
    _camera.position = position;
}

Vector3 Raylib::Core::CameraB::getPosition() {
    return _camera.position;
}
