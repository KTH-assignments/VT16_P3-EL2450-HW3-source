switch ( control_strategy )
{
  case ROTATION_CONTROL:

    // Destination angle
    theta_R = atan2( yg-y0, xg-x0 ) * 180 / PI;

    if ( fabs(theta - theta_R) > angle_tolerance )
    {
      u_psi = r_K_psi * (theta_R - theta);

      u_omega = r_K_omega *
        (cos(theta * PI / 180) * (x0 - x) + sin(theta * PI / 180) * (y0 - y));
    }
    else
    {
      control_strategy = TRANSLATION_CONTROL;
    }
    break;

  case TRANSLATION_CONTROL:
    if ( fabs(
        cos(theta_R * PI / 180) * (xg - x) + sin(theta_R * PI / 180) * (yg - y))
      > distance_tolerance )
    {
      u_omega = t_K_omega *
        (cos(theta_R * PI / 180) * (xg-x) + sin(theta_R * PI / 180) * (yg-y));

      u_psi = t_K_psi *
        (sin(theta_R * PI / 180) * (x + t_p * cos(theta * PI / 180) - x0)
         - cos(theta_R * PI / 180) * (y + t_p * sin(theta * PI / 180) - y0));
    }
    else
    {
      control_strategy = STOP_CONTROL;
    }
    break;

  case STOP_CONTROL:

    u_psi = 0;
    u_omega = 0;
    break;

}

left = u_omega - 0.5 * u_psi;
right = u_omega + 0.5 * u_psi;
