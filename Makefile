

include common.mk

default: libtimer.a test/HelloWorld test/pipeline test/pipeline_data

libtimer.a: $(obj-x)
	$(STLIB) $@ $^
	$(RANLIB) $@

test/HelloWorld: $(obj-HelloWorld)
	$(CPP) $^ -o $@ $(LIBRARY) $(SYSLIBS)

test/pipeline: $(obj-pipeline)
	$(CPP) $^ -o $@ $(LIBRARY) $(SYSLIBS)

test/pipeline_data: $(obj-pipeline_data)
	$(CPP) $^ -o $@ $(LIBRARY) $(SYSLIBS)

%.o: %.cpp
	$(CPP) -Wall $(INCLUDE) -c $< -o $@


clean:
	rm -rf libtimer.a $(obj-x) $(obj-HelloWorld) test/HelloWorld $(obj-pipeline) test/pipeline $(obj-pipeline_data) test/pipeline_data



