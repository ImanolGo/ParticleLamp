///////////////////////////////////////////////////////////////////
// Class holding and updating a particle system
//
//
// This code is under A Creative Commons Attribution/Share-Alike License
// http://creativecommons.org/licenses/by-sa/4.0/
// 2018, Imanol Gomez
///////////////////////////////////////////////////////////////////

#pragma once
#include "Arduino.h"
#include "Particle.h"
#include "Constants.h"

#define NUM_PARTICLES 20


class ParticlesManager{

  public:
    
    ParticlesManager();
    
    void setup();
    void update();
   
  private:

    void updateParticles();
    
    Particle particles[NUM_PARTICLES];
    
};

ParticlesManager::ParticlesManager()
{
    //Intentionally left empty
}

void ParticlesManager::setup()
{
    ///
}

void ParticlesManager::update()
{
    updateParticles();
}


void ParticlesManager::updateParticles()
{
    for(int i=0 ; i<NUM_PARTICLES; i++){
          particles[i].update();
    }
    
}



