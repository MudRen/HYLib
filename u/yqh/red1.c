// lingzhi.c ǧ��ѩ��
//����(lywin)2000/4/22

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
 set_name(HIR"�´����������"NOR, ({"kiss"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
    set("no_give","ÿ����ֻ��һ�����㶼��ô�󷽣�\n");
    set("value", 0);
set("no_steal",1);
set("no_beg",1);
set("liwu",1);
    set("no_put",1);
    set("no_get","ÿ����ֻ��һ������Ҫ��ô̰�ģ�\n");
    set("no_drop","��ô���Ķ�����Ҳ�ӣ���\n");

		set("unit", "��");
set("long", "������Եõ����400���������,���10000Ǳ��,���50000�ľ��顣\n");
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
 this_player()->start_busy(300);
 this_player()->set("qi",-1);
 this_player()->set("jing",-1);
  this_player()->add("max_neili",random(400));
 this_player()->set("neili",0);
  this_player()->add("eff_neili",20);
 this_player()->add("combat_exp",random(50000));
this_player()->add("potential",random(10000));
message_vision(HIR"$N���׵��������ǣ��ٺ�,���˷ܵ�������!\n"NOR, this_player());

	destruct(this_object());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
