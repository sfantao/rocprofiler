configure_file(run_asan_tests.sh ${PROJECT_BINARY_DIR}/tests/memorytests COPYONLY)
configure_file(suppr.txt ${PROJECT_BINARY_DIR}/tests/memorytests COPYONLY)
configure_file(test_mem.py ${PROJECT_BINARY_DIR}/tests/memorytests COPYONLY)
configure_file(input.txt ${PROJECT_BINARY_DIR}/tests/memorytests COPYONLY)