
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIY "����" HIR "����" NOR "��" NOR,({ "shangfa ling", "ling" }) );
        set_weight(1000);
        set("long", @LONG
����һ���û�ͭ������ͭ�ƣ�������š����ơ���������š����񡱡�
LONG );
                set("unit", "��");
                set("value", 0);
                set("treasure", 1);
                set("no_drop", 1);
                set("no_give", 1);
                set("no_get", 1);
                set("material", "steel");
                set("stable", 100);
        
        setup();
}
