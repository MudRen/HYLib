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
	set_name(HIY"��תС��"NOR, ({"sjin dan", "jindan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ž�ת�𵤡�\n");
    set("no_give","ÿ����ֻ��һ�����㶼��ô�󷽣�\n");
    set("value", 0);
set("liwu",1);
set("no_steal",1);
set("no_beg",1);
    set("no_put",1);
    set("no_get","ÿ����ֻ��һ������Ҫ��ô̰�ģ�\n");
    set("no_drop","��ô���Ķ�����Ҳ�ӣ���\n");
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
	int exp,pot,score;
object corpse;
        object me = this_player();
	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
        this_player()->start_busy(30);

	exp = 500+random(500);
	             pot = exp*2/3;
             score = random(20)+10;
        me->add("max_neili", 5);
        me->add("combat_exp", exp);
        me->add("potential", pot);
tell_object(me,HIY"�㱻�����ˣ�5����������\n" +
             chinese_number(exp) + "��ʵս����\n"+
             chinese_number(pot) + "��Ǳ��\n" +
            chinese_number(score)+"�㽭������\n"NOR);

        message_vision(HIY "$N����һ�ž�ת�𵤣�ֻ������������ԴԴ��������������һ�����Ƶ�!\n" NOR, me);

	destruct(this_object());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
