// ying-kuang.c ����ʯ
// ����lywin 2000/6/15

#include <ansi.h>
inherit ITEM;  
void create() 
{
        set_name(HIW"����ʯ"NOR,({"ying kuang", "kuang"}));
        set_weight(50000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("no_drop","��Ҫ�Ҷ����ⶫ������ʹ��\n");
		set("no_put",1);
		set("no_get",1);
		set("no_give",1);
		set("no_steal",1);
                set("long", "����һ����ص�����ʯ��\n");
             }
        setup();
}
