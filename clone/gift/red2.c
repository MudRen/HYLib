// lingzhi.c ǧ����֥
//����(lywin)2000/4/22

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "xinshang");
}
void create()
{
        set_name(HIR"��С��"NOR, ({"lting"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
    set("no_give","ÿ����ֻ��һ�����㶼��ô�󷽣�\n");
   set("liwu",1);
    set("value", 0);
set("no_steal",1);
set("no_beg",1);
    set("no_put",1);
    set("no_get","ÿ����ֻ��һ������Ҫ��ô̰�ģ�\n");
    set("no_drop","��ô���Ķ�����Ҳ�ӣ���\n");

                set("unit", "λ");
                set("long", "��Ů��С�� ��ɧ���� �ߵ����� ��ҿ���������(xinshang)��\n");
                set("no_give", 1);
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{

	this_player()->add("combat_exp", 500);
	this_player()->add("potential",200);
        message_vision("$N�����������С�����ϵı�ɴ.... ��!!! ���а�Ůװ��!!!\n", this_player());
	destruct(this_object());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
