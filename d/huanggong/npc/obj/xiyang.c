#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("�����", ({ "xiyang biao" }));
        set_weight(2);
   set("long", "��ֻ���˽����������\n" );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("material", "stone");
     set("value", 0);
                set("no_get", 1);
        }
        setup();
}
