References:  
 
1. GL3W, https://www.khronos.org/opengl/wiki/OpenGL_Loading_Library
2. 

Steps:  
1. Build GLFW in external.  
   1. Using CMake generate the Makefile/sln 
   2. Copy the built library `glfw3.lib` from build/Debug to root/libs
   3. Copy include from GLFW/include to root/include