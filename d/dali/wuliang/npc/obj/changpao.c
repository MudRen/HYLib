// changpao.c ����

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name("����", ({ "chang pao", "pao" ,"cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("long","һ������ͨ�����Ƴɵĳ��ۡ�\n");
                set("value", 100);
                set("armor_prop/armor", 5);
        }
        setup();
}
