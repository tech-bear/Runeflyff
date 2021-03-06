CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

PROJECT(LoginServer)

SET(PROJECT_INSTALL_DIR ${PROJECT_BINARY_DIR}/../dist/${CMAKE_BUILD_TYPE})

SET(MSVC_BUILD ${MSVC})

CONFIGURE_FILE(
		"${PROJECT_SOURCE_DIR}/../include/config.h.in"
		"${PROJECT_BINARY_DIR}/config.h")

INCLUDE_DIRECTORIES(src)
INCLUDE_DIRECTORIES(../include)
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}")

ADD_EXECUTABLE(Login
		src/buffer.cpp
		src/logger.cpp
		src/login.cpp
		src/network.cpp
		src/PacketLogger.cpp
		src/reciever.cpp
		src/stringf.cpp)

TARGET_LINK_LIBRARIES(Login
		ws2_32
		wsock32)

IF (MYSQL_SUPPORT)
	TARGET_LINK_LIBRARIES(Login ${MYSQL_LIBRARIES})
	IF (MSVC)
		INSTALL(FILES ${MYSQL_DYNAMIC} DESTINATION ${PROJECT_INSTALL_DIR}/bin)
	ELSE()
		INSTALL(FILES ${MYSQL_LIBRARIES} DESTINATION ${PROJECT_INSTALL_DIR}/bin)
	ENDIF()
ENDIF()

INSTALL(TARGETS Login
		RUNTIME DESTINATION ${PROJECT_INSTALL_DIR}/bin)

INSTALL(FILES
		${QtCore_Location}
		${QtSql_Location}
		${CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS}
		DESTINATION ${PROJECT_INSTALL_DIR}/bin)