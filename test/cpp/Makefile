# 目标依赖文件
OBJ = lua_test_c.o lua2cpp.o test_example.o 

# 工具依赖文件
TOOL = tmcolor.o  debugTool.o 

# 库依赖文件
LIB = liblua.a

# 类依赖文件
CLASS = Ref.o Node.o Vec2.o

# 绑定依赖文件
BINDING = lua_tmcolor_binding.o lua_ref_binding_module.o lua_ref_binding_oop.o \
lua_node_binding.o

# 目标依赖 \
	name:OBJ \
	version: 1.0 \
	date:2020.11.11
# 
lua_test_c:$(OBJ) $(LIB) $(CLASS) $(TOOL) $(BINDING)
	g++ -o lua_test_c $(OBJ) $(LIB) $(CLASS) $(TOOL) $(BINDING) -lpthread

lua_test_c.o:lua_test_c.cpp test_example.h luastd.h
	g++ -c -g lua_test_c.cpp

test_example.o:test_example.cpp test_example.h lua2cpp.h
	g++ -c -g test_example.cpp

lua2cpp.o:lua2cpp.cpp lua2cpp.h
	g++ -c -g lua2cpp.cpp 

# 绑定依赖 \
	name:BINDING \
	version: 1.0 \
	date:2020.11.11
# 
lua_ref_binding_module.o:lua_ref_binding_module.cpp lua_ref_binding_module.h Ref.h
	g++ -c -g lua_ref_binding_module.cpp

lua_ref_binding_oop.o:lua_ref_binding_oop.cpp lua_ref_binding_oop.h Ref.h
	g++ -c -g lua_ref_binding_oop.cpp

lua_node_binding.o:lua_node_binding.cpp lua_node_binding.h Node.h

lua_tmcolor_binding.o:lua_tmcolor_binding.cpp lua_tmcolor_binding.h
	g++ -c -g lua_tmcolor_binding.cpp

# 类依赖 \
	name:CLASS \
	version: 1.0 \
	date:2020.11.11
# 
Ref.o:Ref.cpp Ref.h
	g++ -c -g Ref.cpp

Node.o:Node.cpp Node.h
	g++ -c -g Node.cpp

Vec2.o:Vec2.cpp Vec2.h
	g++ -c -g Vec2.cpp

# 工具依赖 \
	name:TOOL \
	version: 1.0 \
	date:2020.11.11
# 
tmcolor.o:tmcolor.cpp tmcolor.h
	g++ -c -g tmcolor.cpp

debugTool.o:debugTool.cpp debugTool.h
	g++ -c -g debugTool.cpp



clean:
	rm -f *.o