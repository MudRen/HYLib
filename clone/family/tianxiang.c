// tianxiang.c ������¶

#include <ansi.h>

inherit ITEM;

void setup()
{
}

void create()
{
	set_name(HIG "������¶" NOR, ({"magic water", "yvlu", "lu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIG "���Ǹ�������֥�ϵ�һ�ξ�Ө��͸����¶����˵����\n"
                                "��ɽ��ǧ��������֥Ϊĸ�����ϵ���ȡ���վ��»���\n"
                                "�������ޱ�����Ĺ�Ч��\n");
                set("value", 100000);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
        string force;
	int neili_limit;

	neili_limit = me->query_neili_limit();
	message_vision(HIG "$N" HIG "С������Ľ���¶�������У���ʱ����"
                       "��̨һ�������������\n��ƮƮ���ɣ�һʱ�侹�в���"
                       "�����ĸо���\n" NOR,
		       me);

	if (me->query("max_neili") < neili_limit)
	{
		me->add("max_neili", 120 + random(150));
		if (me->query("max_neili") > neili_limit)
			me->set("max_neili", neili_limit);
		me->set("neili", me->query("max_neili"));

	}

        if (me->query("gift/tianxiang") <= 200) 
        {
        force = me->query_skill_mapped("force");
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 40000);
        if (stringp(force) && me->can_improve_skill(force))
                me->improve_skill(force, 40000);
        }

        me->add("gift/tianxiang", 1);
        // me->start_busy(random(5) + 5);
	destruct(this_object());
	return 1;
}
