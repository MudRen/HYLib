#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(GRN"Ѳ�Ǳ���4"NOR, ({ "xunchen4" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	         set("value", 100);
           set("unit", "��");
            set("material", "paper");
            set("long", "һ��Ѳ�Ǳ��档\n");
          }

    setup();
}
