// tengjia.c �ټ�
//

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("�ټ�", ({ "teng jia" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���ٱ��Ƶļף�����ȡ��һЩ�������á�\n");
                set("material", "steel");
		set("value", 2000);
                set("armor_prop/armor", 80);
        }
        setup();
}

