#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(GRN"Ѳ�Ǳ���3"NOR, ({ "xunchen3" }) );
    set_weight(1);
    set("no_drop",1);
set("no_get",1);
set("no_steal",1);
set("no_beg",1);
set("no_put",1);
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
