// shi3.c
// By River 98.10
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"��"HIY"��"HIW"ʯ"NOR, ({"e luanshi", "e", "luanshi", "stone"}));
        set_weight(40000);
        if (clonep())
               set_default_object(__FILE__);
        else {
               set("long", "����һ��ɫ�ʰ�쵵Ķ���ʯ��\n");
               set("unit", "��");
        }
        setup();
}
