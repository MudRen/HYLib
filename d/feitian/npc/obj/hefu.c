// hefu-cloth.c
#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(BLU"��ʽ�ͷ�"NOR, ({ "cloth" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "����һ����ʽ�ͷ���\n");
                set("material", "cloth");
		set("value", 0);
                set("armor_prop/armor", 50);
        }
        setup();
}

