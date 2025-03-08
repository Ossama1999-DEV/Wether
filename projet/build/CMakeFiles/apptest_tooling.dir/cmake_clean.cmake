file(REMOVE_RECURSE
  "projet1QtWether/CurrentWeather.qml"
  "projet1QtWether/Forecast.qml"
  "projet1QtWether/SearchScreen.qml"
  "projet1QtWether/main.qml"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/apptest_tooling.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
