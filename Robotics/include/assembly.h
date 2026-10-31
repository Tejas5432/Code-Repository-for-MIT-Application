#pragma once

#include "vex.h"

using namespace vex;

// The internals of this class is example code and can be deleted

// This is example code for a push back robot with two 5.5W motors on the lower intake,
// 11W motor on the top intake, a scraper, and wing

class Assembly {
public:
/* Create your devices here */
    static mik::motor_group lower_intake_motors;
    static mik::motor upper_intake_motor;
    static mik::motor lift_right;
    static mik::motor lift_left;
    static mik::piston* claw;
    static mik::motor extend_claw;
    static mik::piston* claw_spin;
    static mik::motor intake;
/* Examples of other vex devices you may need */
    static vex::rotation rotation_sensor;
    static vex::optical optical_sensor;
    static vex::limit limit_switch;
    
    void init();
    void control();
    void raise_lower_lift();
    // void lower_intake_control();
    // void upper_intake_control();
    // void wing_piston_control();
    // void scraper_piston_control();
    void claw_control();
    void extend_claw_control();
    // void claw_spin_control();
    void intake_control();
};