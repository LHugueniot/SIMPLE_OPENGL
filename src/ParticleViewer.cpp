#include "ParticleViewer.h"

template<template <typename... Args> class Container>
void ParticleViewer<Container>::draw(Eigen::Matrix4f const & viewProj){

}


void particleLinkHack(){
    ParticleViewer<std::vector> temp;
    temp.draw(Eigen::Matrix4f::Identity());
}