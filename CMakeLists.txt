cmake_minimum_required(VERSION 3.16)

project(projet VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(ENV{QT_QPA_PLATFORM} "xcb")

#find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick Network QuickControls2)

qt_add_executable(apptest
<<<<<<< HEAD
    projet/src/main.cpp
    projet/src/weatherAPI.cpp
    projet/src/weatherdata.cpp
    projet/src/forecastmodel.cpp
    projet/inc/weatherAPI.h
    projet/inc/forecastday.h
    projet/inc/forecastmodel.h
    projet/inc/weatherdata.h
=======
    #source files
    projet/src/main.cpp
    projet/src/weatherAPI.cpp
    projet/src/weatherdata.cpp
    projet/src/forecastday.cpp
    projet/src/forecastmodel.cpp

    #include files
    projet/inc/weatherdata.h
    projet/inc/weatherAPI.h
    projet/inc/forecastday.h
    projet/inc/forecastmodel.h
    
>>>>>>> 509121c7ac4979d0a2562979307a3fcf4abb78db
)

qt_add_qml_module(apptest
    URI projet
    VERSION 1.0
    QML_FILES projet/qml/main.qml
    projet/qml/CurrentWeather.qml
    projet/qml/Forecast.qml
    projet/qml/SearchScreen.qml
)

set_target_properties(apptest PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(apptest PRIVATE Qt6::Core Qt6::Network Qt6::Gui Qt6::Qml Qt6::Quick Qt6::QuickControls2)

include(GNUInstallDirs)
install(TARGETS apptest
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_add_resources(APP_RESOURCES resources.qrc)

