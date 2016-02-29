double R_true = 0.1001405119340;
double L_true = 0.5052864456892;

// Control strategy
#define ROTATION_CONTROL 0
#define TRANSLATION_CONTROL 1
#define STOP_CONTROL 2

// The control strategy: R(otation), T(ranslation), S(top)
int control_strategy = ROTATION_CONTROL;

// The angle between the robot and the goal
double theta_R = 0.0;

// The robot cannot (in general) be rotated *exactly* theta_R degrees
/*double angle_tolerance = 6;*/
double angle_tolerance = 2.0;

// The robot cannot (in general) be translated *exactly* to the goal (cm)
/*double distance_tolerance = 20;*/
double distance_tolerance = 1.0;

// Sampling time. Should be obtained through the GUI?
double Ts = 1.0;

// Rotation and translation inputs
double u_psi = 0.0;
double u_omega = 0.0;

// Part I of Rotation Control
double r_K_psi_min = 0.0;
double r_K_psi_max = 2.0 * L_true / (R_true * Ts);
double r_K_psi = r_K_psi_max * 0.1;

// Part II of Rotation Control
double r_K_omega_min = 0.0;
double r_K_omega_max = 2.0 / (R_true * Ts);
double r_K_omega = r_K_omega_max * 0.5;

// Part II of Line Following Control
double t_p = 40.0;
double t_K_psi_min = -2.0 * L_true / (t_p * Ts * R_true);
double t_K_psi_max = 0.0;
double t_K_psi = t_K_psi_min * 0.5;

// Part I of Line Following Control
double t_K_omega_min = 0.0;
double t_K_omega_max = 2.0 / (R_true * Ts);
double t_K_omega = t_K_omega_max * 0.1;
