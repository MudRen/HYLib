// mie.c  �ط�����������𽣡�

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        int extra;
        string msg;
        object weapon;

        if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���𽣣�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʲô��Ц��ûװ��������ʹ���𽣡���\n");
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("���𽣡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if ((int)me->query_skill("huifeng-jian", 1) < 200 )
                return notify_fail("��Ļط��������������죬��ʹ�������𽣡���\n");
        if ((int)me->query_skill("linji-zhuang", 1) < 100 )
                return notify_fail("����ټ�ʮ��ׯ��򲻹������𽣡�������ʽ��\n");
        if ((int)me->query("max_neili")<800)
                return notify_fail("���������Ϊ���㣬�޷����㡸�𽣡���������\n");
        if ((int)me->query("neili")<600)
                      return notify_fail("����������������û�ܽ����𽣡�ʹ�꣡\n");
	extra = me->query_skill("huifeng-jian",1) / 10;
	extra += me->query_skill("huifeng-jian",1) /10;

    if( (int)me->query_skill("linji-zhuang", 1) > 200 )
    {
        me->add_temp("apply/attack", extra*4);
        me->add_temp("apply/damage", extra*2);
        msg = HIC "ֻ��$N����һ����"+ weapon->name()+ HIY"����$n���Ҽ磡" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY "ֻ��$N����һ����"+ weapon->name()+ HIY"����$n����磡" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  HIW "$N���һ����"+ weapon->name()+ GRN"����$n���Ҽ磡" NOR;
      	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = CYN "$N��Хһ�����۹��������֣�ʹ����������߾���--�𽣣���$n����ǰ��ȥ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -extra*4);
        me->add_temp("apply/damage", -extra*2);

}
               
        msg = YEL "$N���г�����âԾ�������Ⱪ�����ó�������ɫ�ʣ����⽥���ƽ�$n��\n"NOR;
        msg += YEL"$n�������콣�⣬�����Ծ��ֻ��һɲ�����콣Ӱ��Ϊһ��ֱ��$nǰ�أ�"NOR;

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
          message_vision(HIW "��$NƮ�����ʹ�����Ҿ������𽣡��ķ�����ʱ�������Ʈ�ݣ�����ǧ�������裬����ͷ�����
������$n����֮�£���ʱ����ɢ�ң��޴��мܣ�\n" NOR, 
                         me, target);
       target->start_busy(2);
	}
	me->start_busy(3);
        }
        else
        {
        if (random(me->query_skill("force")) > target->query_skill("force")/2 
        || random(me->query("combat_exp"))+5000 > target->query("combat_exp")/2 )
	{
		me->start_busy(2);
		target->start_busy(random(3));
		
		damage = (int)me->query_skill("huifeng-jian", 1);
		
		damage = damage*4 + random(damage);
		
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		
		if( damage < 300 ) msg += HIY"\n���$n��ɫ��һ�����У��������������˺ü�����\n"NOR;
        	else if( damage < 400 ) msg += HIY"\n���һ�����У�$n���ۡ���һ���³�һ����Ѫ��\n"NOR;
        	else if( damage < 500 ) msg += RED"\n������䡹��һ����һ������,$nȫ����Ѫ������������Ѫ���������\n"NOR;
        	else msg += HIR"\n���ֻ���������������죬һ������,$nһ���ҽУ���̲�����������ȥ����\n"NOR;
		
	} else 
	{
		me->start_busy(3);
    msg += HIY"\n$pΣ����ͻȻ���ط����������ܹ���������һ�������ŵ���ɫ�԰ף�\n" NOR;
	message_vision(msg, me, target);
            message_vision(HIW "��$NƮ�����ʹ�����Ҿ������𽣡��ķ�����ʱ�������Ʈ�ݶ�������ǧ�������裬����ͷ�����
������$n���Ѽӱ���������Ըй���ƵƵ�մ졣\n" NOR, 
me, target);
        target->add("jing",-extra);
        target->add("eff_jing",-extra/2);
        target->add("qi",-extra);
        target->add("eff_qi",-extra/2);
	}
	message_vision(msg, me, target);

        }
        me->add("neili", -480);
	return 1;
}