build:
  cmake -S . -B build
  cmake --build build

# Change OLD to NEW in plugin/** and test/** and plugin/include/OLD using sed and mv
change-plugin-name OLD NEW:
  # Change all occurances in the plugin directory
  find plugin/ -type f | xargs sed -i s/{{OLD}}/{{NEW}}/ 
  # Change all occurances in test directory
  find test/ -type f | xargs sed -i s/{{OLD}}/{{NEW}}/ 
  # Rename plugin include directory
  mv plugin/include/{{OLD}} plugin/include/{{NEW}}
