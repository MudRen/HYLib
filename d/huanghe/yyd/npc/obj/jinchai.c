// ���� jinchai.c
// zly 99.6.21

#include <ansi.h>

inherit ITEM;

void create()
{
          set_name(HIY"����"NOR, ({"jin chai","jin","chai"}));
        set("long",
                "\n����һ֧����Ư���Ľ��Σ�����һ�������ִ���Բ������ӨȻ��\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "֧");
        set("weight", 10);
        set("value", 50);
}
        setup();
}
