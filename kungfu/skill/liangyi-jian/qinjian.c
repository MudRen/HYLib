// tianlei.c 

#include <ansi.h>

#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
        string msg;
        object weapon;
int extra;
	if( !target ) target = offensive_target(me);

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
		return notify_fail("�����޽�,����ôʹ�ó���\n");

	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	extra = me->query_skill("liangyi-jian",1);
        if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");
 

	if(me->is_busy())
		return notify_fail("������û�գ���\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("kunlun-zhang", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("liangyi-jian", 1) < 500 )
		return notify_fail("��ı����⹦������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("xuantian-wuji", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "xuantian-wuji")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");


        msg = HBWHT "$N��ͨ������ѧ��ʹ�������صľ�ѧ֮���裡\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);              
	me->add_temp("apply/attack",(extra/3));
	me->add_temp("apply/damage",(extra));
 if (random(2)==0) target->start_busy(3);
 msg=HIY "$N�����޷��Զ���ʹ�����������ǽ����е���ɽ������\n"
HIG "ɲ�Ǽ����ذ�����ɳ��ʯ��������Ӱ��$n��ȫ��Ҫ����̣��򿳣�������ȥ��\n" NOR;
        message_vision(msg, me, target);              
    msg = HIC"$n��������ƫ�󣬼�������ת����ֻ��һɲ������ɲʱϮ�����ף�"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("liangyi-jian",1)));
    msg = HIG"$n��������ƫ�ң���������ת����ֻ��һɲ������ɲʱϮ�����ף�"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("liangyi-jian",1)));
    msg = HIY"$n��������ƫ�ϣ���������ת����ֻ��һɲ������ɲʱϮ������"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("liangyi-jian",1)));
    msg = HIR"$n��������ƫ�£���������ת����ֻ��һɲ������ɲʱϮ������"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("liangyi-jian",1)));
    msg = CYN"$n��������ƫǰ��������ǰת����ֻ��һɲ������ɲʱϮ��ǰ��"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("liangyi-jian",1)));
    msg = WHT"$n��������ƫ�󣬼������ת����ֻ��һɲ������ɲʱϮ�����"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("jing",random((int)me->query_skill("liangyi-jian",1)));
	me->add_temp("apply/attack",-(extra/3));
	me->add_temp("apply/damage",-(extra));
	me->start_busy(4);
    msg = HIY "\n$N��Ȼ������һ������ �� ˫ ���������ϵĽ���糵������������һ�������潣�ƿ�쭶������Ʋ��ɵ���\n"NOR;

	if( weapon = target->query_temp("weapon") ){
    if (random(me->query_skill("force")) > target->query_skill("force")/2|| 
       random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
{  
    msg += HIM"\n$pֻ���û���һ�ȣ����ƻ��ھ�ʹ������"
                + target->query_temp("weapon")->query("name") + "���ֶ�����\n" NOR;
		message_vision(msg, me, target);
		(target->query_temp("weapon"))->move(environment(target));
		target->start_busy(3);
	} else {
    msg += HIY"\n$pΣ����ͻȻ���ط����������ܹ���������һ�������ŵ���ɫ�԰ף�\n" NOR;
		message_vision(msg, me, target);
	}

        }
        else
        {
        if (random(me->query_skill("force")) > target->query_skill("force")/2 ||
          random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
	{
		target->start_busy(random(3)+1);
		
		damage = (int)me->query_skill("art", 1);
		
		damage = damage*6 + random(damage);
		
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		
		if( damage < 300 ) msg += HIY"\n���$n��ɫһ�±�òҰף��������������˺ü�����\n"NOR;
        	else if( damage < 400 ) msg += HIY"\n������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n"NOR;
        	else if( damage < 500 ) msg += RED"\n������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n"NOR;
        	else msg += HIR"\n���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n"NOR;
		
	} else 
	{
    msg += HIY"\n$pΣ����ͻȻ���ط����������ܹ���������һ�������ŵ���ɫ�԰ף�\n" NOR;
	}
	message_vision(msg, me, target);

        }

	return 1;
}
