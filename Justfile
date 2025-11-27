build:
  cmake -S . -B build
  cmake --build build

standalone:
  open build/plugin/AudioPlugin_artefacts/Standalone/YourPluginName.app
