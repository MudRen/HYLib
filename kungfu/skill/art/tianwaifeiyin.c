// tianwaifeiyin.c �������
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object *ob;
	int i, skill, damage;

	if( (int)me->query("neili") < 500 )
		return notify_fail("�������������\n");
	if(me->query_skill("art",1)<100)
		return notify_fail("�������������\n");
	if(me->query_skill("xuantian-wuji",1)<100)
		return notify_fail("��������޼���������\n");
//	if (! present("gu zheng", me))
//		return notify_fail("�㵯ʲô��\n"); 
	skill = me->query_skill("force");

	me->add("neili", -500);
	me->receive_damage("qi", 10);

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ�ܹ�������! \n");
	me->receive_damage("qi", 10);

	me->start_busy(3);
	message_combatd(
        HIY "$N�ڳ���һ�Ź��ݣ����ض����������ؽ�һ�����������������������һʱ�䣬�����������Χ���˶�������һƬ����֮�У�\n" NOR, me);

	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++) {
		if( !living(ob[i]) || ob[i]==me )
			continue;
                if( !ob[i]->is_fighting(me) ) continue;
                if( ob[i]==me ) continue;
	        if( !ob[i]->is_character() || ob[i]->is_corpse() ) continue;
		if(ob[i]->query_temp("no_kill")> 0 )
		{	tell_object(ob[i], HIC"��ֻ�������Ŀ��������ޱ���̹......\n"NOR);
			ob[i]->add("jing", 1);
		continue;
		}

		if(ob[i]->query("shen")> 0 )
		{	tell_object(ob[i], HIC"��ֻ�������Ŀ��������ޱ���̹......\n"NOR);
			ob[i]->add("jing", 1);
		continue;
		}
		
		damage = skill*2 - ((int)ob[i]->query("max_neili") / 10);
		if( damage > 0 ) {
			if (damage > 6000) damage=6000;
			ob[i]->receive_damage("qi", damage * 2 );
			if( (int)ob[i]->query("neili") < (int)me->query("max_neili") )		{
			if( (int)ob[i]->query("max_neili") > 10 ){				
				ob[i]->add("max_neili", -5);
		}
			if( (int)ob[i]->query("max_jing") > 10 ){				
				ob[i]->add("max_jing", -5);
		}
		}
		if( !me->is_killing(ob[i]) )
			me->fight_ob(ob[i]);

		if( !ob[i]->is_killing(me) )
			ob[i]->fight_ob(me);
		tell_object(ob[i], HIR"��ֻ�������ķ����ң���Ѫһ���ڣ���ת������......\n"NOR);
		}
	}

	return 1;
}
