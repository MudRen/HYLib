#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(RED"Ѫ��"NOR,({"xuejie"}));
        set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "��ҩ��֮һ.\n");
                set("value", 100);
        }
}

void init()
{
 add_action("do_eat","eat");
}
int do_eat(string arg)
{
 if (!arg||arg!="xuejie") return notify_fail("�����ʲô?\n");
if (!living(this_player())) return 0;
this_player()->apply_condition("youming",0);
message_vision("$Næ�����ĳ���һ��"+this_object()->name()+",ȫ������Щ��ɫ֭Һ��.\n",this_player());
destruct(this_object());
return 1;
}

