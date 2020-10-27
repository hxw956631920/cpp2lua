
OBJ = lua_test_c.o lua2cpp.o test_example.o Ref.o lua_ref_binding_module.o
LIB = liblua.a


lua_test_c:$(OBJ)
	g++ -o lua_test_c $(OBJ) $(LIB) -lpthread

lua_test_c.o:lua_test_c.cpp test_example.h
	g++ -c -g lua_test_c.cpp

test_example.o:test_example.cpp test_example.h lua2cpp.h
	g++ -c -g test_example.cpp

lua2cpp.o:lua2cpp.cpp lua2cpp.h 
	g++ -c -g lua2cpp.cpp 

lua_ref_binding_module.o:lua_ref_binding_module.cpp lua_ref_binding_module.h Ref.h luastd.h
	g++ -c -g lua_ref_binding_module.cpp

Ref.o:Ref.cpp Ref.h
	g++ -c -g Ref.cpp

clean:
	rm -f *.o