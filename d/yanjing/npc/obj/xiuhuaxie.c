#include <armor.h>
inherit BOOTS;

void create()
{
set_name("�廨Ь",({"xiuhua xie","shoe"}));
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit","ֻ");
set("long","С�ɾ��µ��廨Ь,��ɫ��Ь����������ֻ��ɫ�ĺ���.\n");
                set("value", 400);
                set("material", "cloth");
                set("armor_prop/armor", 3);
        }
        setup();
}

