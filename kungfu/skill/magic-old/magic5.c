// ������

#include <ansi.h>

inherit F_SSERVER;

int thunderspell(object me, object obj)
{
	int	kee, damage, spells;

        if ((int)me->query_skill("magic-old", 1) < 100)
                return notify_fail(WHT"��ĹŴ�ħ��������죬��ʹ����������ն����\n"NOR);
	message_vision(HIB "\nһ���޴�ĺ�ೳ������$N"HIB"�����ϴ�����\n" NOR, obj);
//	obj->receive_damage("jing", 0, me);
	spells = me->query_skill("spells");
//me->start_busy(0);
	if(obj->is_ghost()==1) {
		message_vision(HIB "$N"HIB"�ҽ���һ������Ϊ�˻ҽ���\n" NOR, obj);
		obj->die();
		return 1;
	}
	if(obj->is_zombie()==1) {
		message_vision(HIB "$N"HIB"�ҽ���һ������Ϊ��һ̲Ѫˮ��\n" NOR, obj);
		obj->die();
		return 1;
	}
	if(obj->query("race")=="Ұ��") {
//		kar = obj->query("qi");
//		spi = obj->query("jing");
                damage = (int)me->query_skill("magic-old", 15);
                damage = damage + random(damage)+2000;
//		damage = (31 - spi)*(spells/4)*(random(31-kar)+1)+100;
		if(damage <= 20) damage = 0;
		if(damage > 3500) damage = 3500;
		if(damage != 0) {
			message_vision(HIB "$N"HIB"��ȫ������������ˣ�\n" NOR, obj);
  		            obj->receive_damage("qi", damage);
                            obj->receive_wound("qi", damage/2);               		    
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
                damage = (int)me->query_skill("magic-old", 2);
                damage = damage + random(damage);
//	damage = (31 - spi)*(spells/10)*(random(30-kar)+1);
	if(damage < 0) damage = 10;
	if(random(2)==1) {
			message_vision(HIB "$N"HIB"��ȫ������������ˣ�\n" NOR, obj);
		obj->receive_damage("qi", damage*3);
                obj->receive_wound("qi", damage*2);               		    
                obj->start_busy(2);
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

	if((int)me->query("qi") < 500 )
		return notify_fail("�������������\n");

	if((int)me->query("jing") < 100 )
		return notify_fail("��ľ���û�а취��Ч���У�\n");

	me->add("neili", -1500);
	me->receive_damage("jing", 100);
if ((int)me->query("qi")+6000 < (int)me->query("eff_qi")) 
{
message_vision(HIW "\n�޴������������,$N"HIW"ȫ��������ʥ��Ĺ�â��ȫ����˺���ö��ˣ�\n" NOR, me);
me->receive_heal("qi", random(2000)+2000);
me->receive_heal("jing", random(2000)+1000);
}
if ((int)me->query("eff_qi")+6000 < (int)me->query("max_qi")) 
{
message_vision(HIW "\n�޴������������,$N"HIW"ȫ��������ʥ��Ĺ�â��ȫ����˺���ö��ˣ�\n" NOR, me);
me->add("eff_qi", random(3000)+3000);
}
	msg = YEL "$N"YEL"�Ų���â�ǣ�˫���ճɷ�ħӡ�������૵��������ģ�\n" NOR;
       msg += HIB"$N"HIB"� �Ⱥ�೻�Ҫ��೵Ķ���,����ҹ��Ҫ��Ķ���...\n"NOR;
       msg += HIB"$N"HIB"����� ������ʱ��֮��  �ѵ�������ǰһ���޲��ɼ�������ݻ�...\n"NOR;
       msg += HIC"$N"HIC"���һ��  ����ն!!   �޴�ĵ�೺ڳ����ֱ�����ܷ�ȥ����೵��������������磡\n"NOR;
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


