// ������

#include <ansi.h>

inherit F_SSERVER;

int thunderspell(object me, object obj)
{
	int	kee, damage, spells;

        if ((int)me->query_skill("magic-old", 1) < 100)
                return notify_fail(WHT"��ĹŴ�ħ��������죬��ʹ������������������\n"NOR);
	message_vision(HIC "\nһ��������$N"HIC"��ͷ�ϴ�����\n" NOR, obj);
	obj->receive_damage("jing", 0, me);
	spells = me->query_skill("spells");
	if(obj->is_ghost()==1) {
		message_vision(RED "$N"RED"�ҽ���һ������Ϊ�˻ҽ���\n" NOR, obj);
		obj->die();
		return 1;
	}
	if(obj->is_zombie()==1) {
		message_vision(RED "$N"RED"�ҽ���һ������Ϊ��һ̲Ѫˮ��\n" NOR, obj);
		obj->die();
		return 1;
	}
	if(obj->query("race")=="Ұ��") {
//		kar = obj->query("qi");
//		spi = obj->query("jing");
                damage = (int)me->query_skill("magic-old", 1);
                damage = damage + random(damage);
//		damage = (31 - spi)*(spells/4)*(random(31-kar)+1)+100;
		if(damage <= 20) damage = 0;
//		if(damage > 2000) damage = 2000;
		if(damage != 0) {
			message_vision(RED "��������$N"RED"��ͷ�ϣ�\n" NOR, obj);
  		            obj->receive_damage("qi", 400);
               		obj->receive_damage("jing", 30);
               		obj->receive_damage("qi", damage);
               		obj->receive_damage("jing", damage/2);
	 		COMBAT_D->report_status(obj);
			if( !obj->is_fighting(me) ) {
                		if( living(obj) ) {
                        		if( userp(obj) ) 
						obj->fight_ob(me);
					else
						obj->kill_ob(me);
                		}
                		me->kill_ob(obj);
        		}
		} else 
			message_vision(RED "����$N"RED"����ˣ�\n" NOR, obj);
		return 1;
	}
//	kar = obj->query("qi");
//	spi = obj->query("jing");
                damage = (int)me->query_skill("magic-old", 3);
                damage = damage + random(damage);
//	damage = (31 - spi)*(spells/10)*(random(30-kar)+1);
	if(damage < 0) damage = 10;
	if(random(2)==1) {
		message_vision(RED "��������$N"RED"��ͷ�ϣ�\n" NOR, obj);
               		obj->receive_damage("qi", damage);
               		obj->receive_wound("qi", damage);
               		obj->receive_damage("jing", damage/2);

 		COMBAT_D->report_status(obj);
		if( !obj->is_fighting(me) ) {
               		if( living(obj) ) {
                       		if( userp(obj) ) 
					obj->fight_ob(me);
				else
					obj->kill_ob(me);
               		}
               		me->kill_ob(obj);
       		}
	} else 
			message_vision(RED "����$N"RED"����ˣ�\n" NOR, obj);
	return 1;
	
}
int perform(object me)
{
	string 	msg;
	object	env;
	object	*inv;
	int	i;

	if((int)me->query_skill("spells") < 200 )
		return notify_fail("��ķ��������ߣ�\n");

	if((int)me->query("neili") < 200 )
		return notify_fail("��ķ���������\n");

	if((int)me->query("qi") < 100 )
		return notify_fail("�������������\n");

	if((int)me->query("jing") < 100 )
		return notify_fail("��ľ���û�а취��Ч���У�\n");

	me->add("neili", -200);
	me->receive_damage("jing", 10);

	msg = YEL "$N"YEL"�Ų���â�ǣ�˫���ճɷ�ħӡ�������૵��������ģ�\n" NOR;
	msg = msg + HIC "�͵�˫��һ�ӣ����ϴ����������磡\n\n" NOR;
	message_vision(msg, me);
	env = environment(me);
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( !inv[i]->is_fighting(me) ) continue;
                if( inv[i]==me ) continue;
	        if( !inv[i]->is_character() || inv[i]->is_corpse() ) continue;
		thunderspell(me, inv[i]);
        }
	me->start_busy(1);
	return 1;
}

