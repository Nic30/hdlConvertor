antrl_parser_headers = custom_target('antrl_parser_sv2017_headers',
	input : antlr_parser_parser_src_gen,
	output : generated_headers,
	command : [cp, ] + generated_headers_abs + [meson.current_build_dir()])
