// ITEM: /d/jingzhou/obj/wucanyi.c
// Date: 99/05/31 by Byt

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(CYN "�ڲ���" NOR, ({ "wucan yi", "yi" }) );
        set_weight(5000); 
        set("unique", 1);        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("no_drop","��������/�����˵ģ�Ҳ���ܸ����ˡ�");
                set("value", 50000);
                set("material", "gold");
                set("armor_prop/armor", 200);
        }
        setup();
}

