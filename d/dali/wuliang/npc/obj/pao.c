// ����

#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("����", ({ "qing pao", "pao" ,"cloth" }) );
        set_weight(1000);
        if( clonep() )
             set_default_object(__FILE__);
        else {
             set("unit", "��");
             set("material", "steel");
             set("long","����һ����ɫ���ۣ���֪������ʲô�ʵص��������ģ��������е��쳣��\n");
             set("value", 0);
             set("armor_prop/armor", 50);
        }
        setup();
}

