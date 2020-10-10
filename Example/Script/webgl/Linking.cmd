echo "Linking"
em++ -s WASM=0 %OBJ_FILES% -L../../Library/WebGl/ -l%LIB_FILE% -o %NAME%.html

