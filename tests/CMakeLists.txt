
set(TEST_NAME test_aes)
set(TEST_NAME2 test_b64)

add_executable(${TEST_NAME}  test_aes.cc)

add_executable(${TEST_NAME2}  test_b64.cc)

target_link_libraries(${TEST_NAME} 
	"${PROJECT_SOURCE_DIR}/lib/libcrypto.a"
	"${PROJECT_SOURCE_DIR}/lib/libssl.a"

	pthread
	dl

)

target_link_libraries(${TEST_NAME2} 
	"${PROJECT_SOURCE_DIR}/lib/libcrypto.a"
	"${PROJECT_SOURCE_DIR}/lib/libssl.a"

	pthread
	dl

)
