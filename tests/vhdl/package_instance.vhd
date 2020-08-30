library IEEE;

package fixed_pkg is new IEEE.fixed_generic_pkg
  generic map (
    fixed_round_style    => IEEE.fixed_float_types.fixed_round,
    fixed_overflow_style => IEEE.fixed_float_types.fixed_saturate,
    fixed_guard_bits     => 3,
    no_warning           => false
    );