
set(TEST_NAME test_aes)

add_executable(${TEST_NAME}  test_aes.cc)


target_link_libraries(${TEST_NAME} 
	"${PROJECT_SOURCE_DIR}/lib/libcrypto.a"
	"${PROJECT_SOURCE_DIR}/lib/libssl.a"

	pthread
	dl

)
