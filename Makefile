

include common.mk

default: libtimer.a test/HelloWorld

libtimer.a: $(obj-x)
	$(STLIB) $@ $^
	$(RANLIB) $@

test/HelloWorld: $(obj-HelloWorld)
	$(CPP) $^ -o $@ $(LIBRARY) $(SYSLIBS)

%.o: %.cpp
	$(CPP) -Wall $(INCLUDE) -c $< -o $@


clean:
	rm -rf libtimer.a $(obj-x) $(obj-HelloWorld) test/HelloWorld



