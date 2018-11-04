// roar.c �����ķ���

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob;
        int i, skill, damage;

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ׼��ܡ�\n");

  	 if( (int)me->query_skill("kuihua-xinfa",1) < 20)
		return notify_fail("��Ŀ����ķ����������졣\n");

        if( (int)me->query("neili") < 150 )
                return notify_fail("���Цһ�����������һ����\n");


        skill = me->query_skill("force");

        me->add("neili", -150);
        me->receive_damage("qi", 10);

        me->start_busy(2);
        message_combatd(
        MAG "$N����һ�䣬��Ȼ����������������������Ц������\n" NOR, me);

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me )
                        continue;

                if( !ob[i]->is_fighting(me) ) continue;
                if( ob[i]==me ) continue;
	        if( !ob[i]->is_character() || ob[i]->is_corpse() ) continue;
                if( skill/2 + random(skill/2) < (int)ob[i]->query("con") * 2 )
                        continue;


                damage = skill - ((int)ob[i]->query("max_neili") / 10);
                if( damage > 0 ) {
                        ob[i]->receive_damage("jing", damage);
                        if( (int)ob[i]->query("neili") < skill * 2 )
                                ob[i]->receive_wound("jing", damage);
                tell_object(ob[i], "���Ȼ����һ�����������������������Ư�Ʋ�����\n");
		if( !me->is_killing(ob[i]) )
			me->fight_ob(ob[i]);

		if( !ob[i]->is_killing(me) )
			ob[i]->fight_ob(me);
                }
        }

        return 1;
}

