//���� red-cloth.c
//zly 99.08.22.

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(RED"����"NOR, ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","����һ���ʺ�ɫ�·���\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        setup();
}
