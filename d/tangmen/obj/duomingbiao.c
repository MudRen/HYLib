// duomingbiao.c
#include <weapon.h>
inherit THROWING;

void create()
{
	set_name("������", ({"duomingbiao", "tmbiao" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "�������ŵĶ��Ű���--�����ڣ������������⡣\n");
		set("unit", "Щ");
                set("base_value", 100);
	//	set("material", "steel");
                set("base_unit", "ö");
		set("base_weight", 1); 
	}	
        set_amount(999);
        init_throwing(500);
        setup();
}


