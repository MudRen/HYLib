// roar.c ����ʨ�Ӻ�

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object *ob;
	int i, skill, damage;

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ�ܹ�������! \n");

	if ( !wizardp(this_player()) && (me->query("family/family_name") != "����"))
		return notify_fail("�㲻�����̽��ڲ���ʹ�þ����񹦡�\n");

	if( ((int)me->query("neili") < 600 ) || ( (int)me->query_skill("jiuyang-shengong") < 20) )
		return notify_fail("���������\"��\"�ĺ���һ��, ��������˼�ֻ����\n");

	if( !me->is_fighting())
		return notify_fail("�㲻�ڴ�ܣ��������ʲô?\n");

	skill = me->query_skill("force");

	me->add("neili", -150);
	me->receive_damage("qi", 10);

	me->start_busy(1);
	message_combatd(
		HIY "$N�������һ�����������ŷ�������һ�����춯�صľ޺�\n" NOR, me);

	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++) {
		if( !living(ob[i]) || ob[i]==me ) continue;
                if( !ob[i]->is_fighting(me) ) continue;
                if( ob[i]==me ) continue;
	        if( !ob[i]->is_character() || ob[i]->is_corpse() ) continue;

		if( skill/2 + random(skill/2) < (int)ob[i]->query("con") * 2 ) continue;

		damage = skill - ((int)ob[i]->query("max_neili") / 10);
		if( damage > 0 ) {
			ob[i]->receive_damage("jing", damage/2  );
			if( (int)ob[i]->query("neili") < skill * 2 )
				ob[i]->receive_wound("jing", damage/2);
			tell_object(ob[i], "�������ǰһ�������ð������ʹ������Ҫ�ѿ�һ����\n");
		if( !me->is_killing(ob[i]) )
			me->fight_ob(ob[i]);

		if( !ob[i]->is_killing(me) )
			ob[i]->fight_ob(me);

		}
	}

	return 1;
}

