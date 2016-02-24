// Calculate theta_R, the angle between the robot and the goal
if (fabs(x - xg) > 0.00001)
{
  theta_R = atan2(y-yg, x-xg) * 180 / PI - 180;

  // Limit theta-R to (-180,180]
  if (theta_R > 180)
  {
    theta_R = theta_R - 360;
  }
  if (theta_R <= -180)
  {
    theta_R = theta_R + 360;
  }
}
else
{
  theta_R = 0;
}

/*control_strategy = ROTATION_CONTROL;*/
control_strategy = TRANSLATION_CONTROL;

switch (control_strategy)
{
  case ROTATION_CONTROL:

    u_psi = r_K_psi * (theta_R - theta);

    // Task 8
    /*right = 0.5 * u_psi;*/
    /*left = -right;*/

    u_omega = r_K_omega * (cos(theta) * (x0 - x) + sin(theta) * (y0 - y));

    // Task 10
    /*left = u_omega;*/
    /*right = u_omega;*/

    break;
  case TRANSLATION_CONTROL:

    u_omega = t_K_omega * (cos(theta_R) * (xg-x) + sin(theta_R) * (yg-y));

    // Task 13
    /*left = u_omega;*/
    /*right = u_omega;*/

    u_psi = t_K_psi *
      (sin(theta_R) * (x + t_p * cos(theta) - x0)
      - cos(theta_R) * (y + t_p * sin(theta) - y0));

    // Task 16
    /*right = 0.5 * u_psi;*/
    /*left = -right;*/
    break;
}

left = 0.5 * (2 * u_omega - u_psi);
right = 0.5 * (2 * u_omega + u_psi);
