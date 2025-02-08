VULKAN_SDK_PATH = "C:/VulkanSDK/1.4.304.0"
GLFW3_PATH = "C:/glfw-3.4_64"

CFLAGS = /std:c++20 /EHsc /I. /I$(VULKAN_SDK_PATH)/Include /I$(GLFW3_PATH)/include
LDFLAGS = /link /LIBPATH:$(VULKAN_SDK_PATH)/lib /LIBPATH:$(GLFW3_PATH)/lib-vc2022 vulkan-1.lib glfw3.lib glfw3_mt.lib glfw3dll.lib user32.lib gdi32.lib  shell32.lib /NODEFAULTLIB:MSVCRT /NODEFAULTLIB:libucrt.lib ucrt.lib vcruntime.lib

BIN_DIR = bin
OBJ_DIR = $(BIN_DIR)

SOURCES = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp,$(OBJ_DIR)/%.obj,$(SOURCES))

a.out: $(OBJECTS) | $(BIN_DIR)
	link $(LDFLAGS) /OUT:$(BIN_DIR)/main.exe $(OBJECTS)

$(OBJ_DIR)/%.obj: %.cpp | $(BIN_DIR)
	cl $(CFLAGS) /c $< /Fo$@

$(BIN_DIR):
	mkdir $(BIN_DIR)

.PHONY: test clean

test: a.out
	$(BIN_DIR)/main.exe

clean:
	del $(BIN_DIR)\main.exe
	del $(OBJ_DIR)\*.obj