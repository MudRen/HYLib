#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("��Ь", ({"caoxie","boots"}));
	set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "leather");
                set("unit", "˫");
                set("value",100);
                set("long","���Ѳ����ܱ��ƶ��ɵĲ�Ь.\n");
		set("armor_prop/armor", 11);
        }
        setup();
}

