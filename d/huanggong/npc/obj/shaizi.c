#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("����", ({ "shai zi" }));
        set_weight(2);
   set("long", "��������Ǧ�����ӡ�\n" );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "stone");
     set("value", 0);
                set("no_get", 1);
        }
        setup();
}
