EIGEN_VERSION='3.3.4'

cc_binary(
  name = "lsh_main",
	srcs = [
	  'main.cpp',
		'lsh.cpp',
		'lsh_wrapper.cpp',
	],
	incs = [
	  '.',
		'../../thirdparty/eigen-' + EIGEN_VERSION,
	],
)

cc_library(
  name = 'lsh_mips',
	srcs = [
	  'lsh.cpp',
	],
	incs = [
	  '.',
		'../../thirdparty/eigen-' + EIGEN_VERSION,
	],
)
