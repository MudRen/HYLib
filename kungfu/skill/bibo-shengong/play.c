// play.c �ࡰ�̺���������

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object *ob;
	object weapon;
	int i, skill, damage;

	if( environment(me)->query("no_fight") )
		return notify_fail("�����ﲻ�ܹ������ˡ�\n");

//	if (!weapon = me->query_temp("weapon"))
//		return notify_fail("��Ҫ��ʲô�����ࣿ\n");

//       if (!weapon->id("xiao"))
//		return notify_fail("������ı��������\n");

	if( (int)me->query("neili") < 400 )
		return notify_fail("�������������\n");

	skill = me->query_skill("force");

	me->add("neili", -150);
	me->receive_damage("qi", 15);

	me->start_busy(3);
	message_vision(HIY"$N�ó�һֻ�����յ���ߣ���ʼ�������ʵش����𡰱̺���������������������������������ˡ�\n"NOR, me);
	ob = all_inventory(environment(me));
	for (i = 0; i < sizeof(ob); i++) {
		if (!living(ob[i]) || ob[i] == me) continue;
		if( !living(ob[i]) || ob[i]==me ) continue;
                if( !ob[i]->is_fighting(me) ) continue;
                if( ob[i]==me ) continue;
		if (skill / 2 + random(skill / 2) < (int)ob[i]->query("con") * 2) continue;

		if (!userp(ob[i]) || ob[i]->query("age") >= 16) {
			damage = skill - ((int)ob[i]->query("max_neili") / 8) + 10;
			if( damage > 0 ) {
				ob[i]->receive_damage("jing", damage * 2, me);
				if( (int)ob[i]->query("neili") < skill * 2)
					ob[i]->receive_wound("jing", damage, me);
				tell_object(ob[i], "����������࣬�������ţ����ҡ��������Ҳ��ü��ٶ��������ˡ�\n");
		if( !me->is_killing(ob[i]) )
			me->fight_ob(ob[i]);

		if( !ob[i]->is_killing(me) )
			ob[i]->fight_ob(me);
			}
		}
		else
			tell_object(ob[i], "��������С������һ��û��ʲô�ر�ĸ��ܡ�\n");
	}

	return 1;
}

