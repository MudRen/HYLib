// hantie-kuang2.c ǧ�꺮��  
// ����lywin 2000/8/27

#include <ansi.h>
inherit ITEM;  
void create() 
{
        set_name(HIR"ǧ�꺮��"NOR,({"han tie", "kuang"}));
        set_weight(50000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("no_drop","��Ҫ�Ҷ����ⶫ������ʹ��\n");
		set("no_get",1);
		set("no_give",1);
		set("no_steal",1);

		set("no_put",1);
                set("long", "����һ����صĺ�����ʯ��\n");
             }
        setup();
}
