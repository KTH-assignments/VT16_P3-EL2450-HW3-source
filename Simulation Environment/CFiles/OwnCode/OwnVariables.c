double R_true = 0.1001405119340;
double L_true = 0.5052864456892;

// Control strategy
#define ROTATION_CONTROL 0
#define TRANSLATION_CONTROL 1

// The control strategy: rotation or translation
int control_strategy = 0;

// The angle between the robot and the goal
double theta_R = 0;

// Sampling time. Should be obtained through the GUI?
double Ts = 1;

// Rotation and translation inputs
double u_psi = 0;
double u_omega = 0;

// Part I of Rotation Control
double r_K_psi_min = 0;
double r_K_psi_max = 2 * L_true / (R_true * Ts);
double r_K_psi = L_true / (R_true * Ts);

// Part II of Rotation Control
double r_K_omega_min = 0;
double r_K_omega_max = 2 / (R_true * Ts);
double r_K_omega = 1 / (R_true * Ts);

// Part I of Line Following Control
double t_K_psi_min = 0;
double t_K_psi_max = 2 * L_true / (R_true * Ts);
double t_K_psi = L_true / (R_true * Ts);

// Part II of Line Following Control
double t_p = 1;
double t_K_omega_min = -2 * L_true / (t_p * Ts * R_true);
double t_K_omega_max = 0;
double t_K_omega = -L_true / (t_p * Ts * R_true);
