// maotan.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("ë̺", ({ "mao tan","tan" }) );
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���ɴ���ë֯�ɵ�ë̺��ë��ϸ��ʮ�ֱ�ů��\n");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}
