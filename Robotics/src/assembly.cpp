#include "vex.h"

// The code in this file is example and can be deleted

// This is example code for a push back robot with two 5.5W motors on the lower intake,
// 11W motor on the top intake, a scraper, and wing
mik::piston* Assembly::claw = nullptr;
mik::piston* Assembly::claw_spin = nullptr;
// This function is called once at the start of user control
void Assembly::init() {
    // You can declare a task that you want to always run in user control.

    // For example a task that is always checking if the intake is moving forward while being told to,
    // and detected not, then the intake will move in reverse to unjam itself
} 

// You want to put this function inside the user control loop in main.
void Assembly::control() {
    static bool initialized = false;

    if (!initialized) {
        init();
        initialized = true;
    }

    // lower_intake_control();
    // upper_intake_control();
    // wing_piston_control();
    // scraper_piston_control();
    raise_lower_lift();
    // claw_spin_control();
    claw_control();
    extend_claw_control();
    intake_control();
}


// Extends piston when button R1 is pressed, releases otherwise 
void Assembly::raise_lower_lift() {
    if (Controller.ButtonUp.pressing()) {
        lift_right.spin(fwd, 12, volt);
        lift_left.spin(fwd, 12, volt);
    } else if (Controller.ButtonDown.pressing()) {
        lift_right.spin(reverse, 6, volt);
        lift_left.spin(reverse, 6, volt);
    } else {
        lift_right.stop(hold);
        lift_left.stop(hold);
    }
}

// void Assembly::claw_spin_control(){
//     if (Controller.ButtonA.pressing()) {
//         claw_spin->open();
//     } else if (Controller.ButtonB.pressing()) {
//         claw_spin->close();
//     }
// }

void Assembly::claw_control() {
    if (Controller.ButtonX.pressing()) {
        claw->open();
    } else if (Controller.ButtonY.pressing()) {
        claw->close();
    }
}
void Assembly::extend_claw_control() {
    if (Controller.ButtonR1.pressing()) {
        extend_claw.spin(reverse,12,volt);
    } else if (Controller.ButtonR2.pressing()) {
        extend_claw.spin(fwd,12,volt);
    } else {
        extend_claw.stop();
    }
}
void Assembly::intake_control() {
    if (Controller.ButtonL1.pressing()) {
        intake.spin(fwd, 12, volt);
    } else if (Controller.ButtonL2.pressing()) {
        intake.spin(reverse, 12, volt);
    } else {
        intake.stop();
    }
}
// Extends or retracts piston when button A is pressed, 
// can only extend or retract again until button A is released and pressed again