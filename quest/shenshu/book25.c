#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIM"�߳�����"NOR, ({ "bclangzi" }) );
    set_weight(1);
            set("no_put", 1);
            set("value", 0);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	        
            set("unit", "��");
            set("material", "paper");
            set("long", "����֮һ��\n");
          }

    setup();
}
