#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"�����ϻ�"NOR, ({ "tiger" }) );
            set("no_put", 1);
            set("value", 0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	          set("unit", "��");
            set("material", "paper");
            set("long", "����֮һ��\n");
          }

    setup();
}
