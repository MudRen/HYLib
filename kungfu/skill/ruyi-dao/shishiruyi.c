// mie.c  �ط�����������������⡹

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;

        if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʲô��Ц��ûװ��������ʹ���������⡹��\n");
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("���������⡹ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if( (int)me->query_skill("beiming-shengong", 1) < 60 )
                return notify_fail("��ġ���ڤ�񹦡�������졣\n");

        if ((int)me->query_skill("ruyi-dao", 1) < 200 )
                return notify_fail("������⵶������죬��ʹ�������������⡹��\n");
        if ((int)me->query("max_neili")<800)
                return notify_fail("���������Ϊ���㣬�޷����㡸�������⡹��������\n");
        if ((int)me->query("neili")<200)
                      return notify_fail("����������������û�ܽ����������⡹ʹ�꣡\n");
        msg = HIC "$N���г�����âԾ�������Ⱪ����һ�����������⽥���ƽ�$n��\n"NOR;
        msg += HIM"$n�������쵶�⣬�����Ծ��ֻ��һɲ�����쵶Ӱ��Ϊһ��ֱ��$nǰ�أ�\n"NOR;
        msg += HIR"**************��������***************"NOR;
	if( weapon = target->query_temp("weapon") ){
        if( random(me->query("str")) > (int)target->query("str")*3/4 ) {  
    msg += HIM"\n$pֻ���û���һ�ȣ����ƻ��ھ�ʹ������"
                + target->query_temp("weapon")->query("name") + "���ֶ�����\n" NOR;
		message_vision(msg, me, target);
		(
		target->query_temp("weapon"))->move(environment(target));
                target->start_busy(2);
	} else {
    msg += HIY"\n$pΣ����ͻȻ���ط����������ܹ���������һ�������ŵ���ɫ�԰ף�\n" NOR;
		message_vision(msg, me, target);
	}
	me->start_busy(1);
        }
        else
        {
        if (random(me->query_skill("force")) > target->query_skill("force")/3 )
	{
		me->start_busy(3);
		target->start_busy(random(3));
		
		damage = (int)me->query_skill("ruyi-dao", 1);
		
		damage = damage*3 + random(damage);
		
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		
		if( damage < 300 ) msg += HIC"\n���$n��ɫ��һ�����У��������������˺ü�����\n"NOR;
        	else if( damage < 400 ) msg += HIC"\n���һ�����У�$n���ۡ���һ���³�һ����Ѫ��\n"NOR;
        	else if( damage < 500 ) msg += HIR"\n������䡹��һ����һ������������,$nȫ����Ѫ������������Ѫ���������\n"NOR;
        	else msg += HIR"\n���ֻ���������������죬һ����������,$nһ���ҽУ���̲�����������ȥ����\n"NOR;
		
	} else 
	{
		me->start_busy(1);
    msg += HIY"\n$pΣ����ͻȻ���ط����������ܹ���������һ�������ŵ���ɫ�԰ף�\n" NOR;
	}
	message_vision(msg, me, target);

        }
        me->add("neili", -300);
	return 1;
}