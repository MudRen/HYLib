// ���

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"���"NOR, ({"hong bao", "bao", "hong"}));
	set_weight(10);
    set("value", 0);
set("no_steal",1);
set("no_beg",1);
    set("no_put",1);
    set("no_get","ÿ����ֻ��һ������Ҫ��ô̰�ģ�\n");
    set("no_drop","��ô���Ķ�����Ҳ�ӣ���\n");
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���ú�ֽ�������ɵ�"+HIR"�����"NOR+"�ƺ�����˺��(opengift)��\n");
		set("unit", "��");
	}
}
  void init()
{
  add_action("do_open","opengift");
}
int do_open()
{
object ob;
        this_player()->add("combat_exp", 200+random(100));
        this_player()->add("potential",150+random(100));
        ob=new("/clone/money/gold");
        ob->set_amount(500000+random(5000));
        ob->move(this_player());
	message_vision("$N���˺����ֻ�����Լ��ֱ�������һЩ !����ﻹ��һЩ����!\n", this_player());
	destruct(this_object());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
