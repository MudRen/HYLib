// wugou.c �����޹�
// shang 97/6

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon = me->query_temp("weapon");
	object *ob;
	int i, skill, damage;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "staff")
			return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query("neili") < 2000 )
		return notify_fail("���������ۺ���ʹ�������޹�������\n");

	if( (int)me->query("neili") < 500 )
                return notify_fail("������û���㹻������ʹ�������޹���\n");


        if ((int)me->query("jing") < 100)
                return notify_fail("������û���㹻�ľ���ʹ�������޹���\n");

        if( (int)me->query_skill("dagou-bang", 1) < 200 )
                return notify_fail("��Ĵ򹷰�����û���������޹�ʹ��������\n");

        if (me->query_skill("huntian-qigong", 1)<70)
                return notify_fail("��ı����ڹ����δ������\n");

	if( !me->is_fighting())
		return notify_fail("�㲻�ڴ�ܣ��������ʲô?\n");


	if( environment(me)->query("no_fight") )
		return notify_fail("�����ﲻ�ܹ������ˡ�\n");

	skill = me->query_skill("dagou-bang", 1);

	me->add("neili", -300);
	me->receive_damage("jing", 20);

	me->start_busy(2);
	message_vision(
		HIY "$Nʹ���������޹����ĵ����䣬ɲʱ����˷��ǰ�����\n" NOR, me);

	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++) {
		if( !living(ob[i]) || ob[i]==me ) continue;
                if( !ob[i]->is_fighting(me) ) continue;
                if( ob[i]==me ) continue;
	        if( !ob[i]->is_character() || ob[i]->is_corpse() ) continue;

                damage = (int)me->query_skill("dagou-bang", 1);
                damage = (int)me->query_skill("dagou-bang", 1) +damage;
                damage = random(damage)+500;
		if( damage > 5000 ) damage = 5001;
		ob[i]->receive_damage("qi", damage , me);
		ob[i]->receive_damage("jing", damage / 5 , me);
		tell_object(ob[i], "�������ǰһ����꣬���˲����¡�\n");	
		if( !me->is_killing(ob[i]) )
			me->fight_ob(ob[i]);

		if( !ob[i]->is_killing(me) )
			ob[i]->fight_ob(me);	        
	        }

	return 1;
}

	