	random seed Error:  Cannot find top-level RTL /home/leviathan/Desktop/kicp/verilog/rtl/caravel_core.v.  Is this script being run in the project directory?
0; 	drc off; 	crashbackups stop; 	addpath hexdigits; 	addpath /home/leviathan/Desktop/kicp/mgmt_core_wrapper/mag; 	addpath /home/leviathan/Desktop/kicp/mag; 	load user_project_wrapper; 	property LEFview true; 	property GDS_FILE /home/leviathan/Desktop/kicp/gds/user_project_wrapper.gds; 	property GDS_START 0; 	load /home/leviathan/Desktop/kicp/mag/user_id_programming; 	load /home/leviathan/Desktop/kicp/mag/user_id_textblock; 	load /home/leviathan/Desktop/kicp/caravel/maglef/simple_por; 	load /home/leviathan/Desktop/kicp/mag/caravel_core -dereference; 	load caravel -dereference; 	select top cell; 	expand; 	cif *hier write disable; 	cif *array write disable; 	gds write /home/leviathan/Desktop/kicp/gds/caravel.gds; 	quit -noprompt;