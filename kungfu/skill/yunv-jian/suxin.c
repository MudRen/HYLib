//suxing.c ��Ů����
//by sdong

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string weapon;
string msg;
        int bili,original,dodge,skill;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��Ů����ֻ�ܶ�ս���еĶ���ʹ�á�\n");


        if( me->query_skill("yunv-xinfa", 1) < 60 )
                return notify_fail("�����Ů�ľ����δ�����޷�ʩչ��Ů���ģ�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");


        if( me->query_skill("sword") < 135 )
                return notify_fail("�����Ů������Ϊ���㣬������ʹ����Ů���ģ�\n");

        if( me->query("neili") <= 400 )
                return notify_fail("�����������ʹ����Ů���ģ�\n");
        if( me->query("jing") <= 100 )
                return notify_fail("��ľ�������ʹ����Ů���ģ�\n");

        if( (int)me->query_temp("suxin") ) 
                return notify_fail("���Ѿ���������Ů���ģ�\n");


        if(!me)
                return notify_fail("����û�ˣ�\n");
        if(!target)
                return notify_fail("����û�ˣ�\n");

//        message_vision(HIR "$N��Хһ����������Ů�����ھ���������ԴԴ���ϵ�ע��"+(me->query_temp("weapon"))->query("name")+ HIR "����ҲͻȻ�ӿ죡\n\n" NOR, me);
        message_vision(HIW"$N����һ����������������֮�����"+(me->query_temp("weapon"))->query("name")+ HIR "�û���������â����$n�糸��ȥ��\n"NOR,me,target);
        skill = (int)me->query_skill("yunv-jian", 1);
        original = me->query_skill("yunv-xinfa")/2;
        bili = me->query_str();
        dodge = me->query_dex();

        me->add_temp("apply/strength", bili/2);
        me->add_temp("apply/dexerity", dodge/2);
        me->add_temp("apply/damage", 150);

	msg = HIR "$N�������ߣ�һ��δ�ϣ������������г���ʱ�������󣬽��еֵ�ʱ����ת�ң����ƽ��ǽ��������ˣ������ⲻ��ɣ�\n"NOR;
	message_vision(msg, me, target);
     msg = HIY  "$N�������飬�ж����������಻��������������������������ɣ����н��������ӵ�ȹ�����̬֮��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
     msg = HIY  "$Nֻ΢һ���֣�ͻȻ�Ž���˫��ֱ�ۣ��ͻ�$nǰ�أ�ͬʱ��������������˫��һ������·������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
      if (!target->is_busy())
      target->start_busy(1); 
       msg = HIY  "$N˫��������������$n����$w"HIY"бָ������ֻ�������$n����������" NOR;
      COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

//        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
//        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
//        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->add_temp("apply/damage", -150);
        me->add_temp("apply/armor", original);
        me->add_temp("apply/damage", original);
        me->start_busy(1+random(2));
        me->add("neili", -150);
        me->add("jing", -50);
        me->set_temp("suxin", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, bili,original,dodge :), skill/5);
//      me->start_busy(3);


        return 1;
}


void remove_effect(object me, int bili, int amount,int dodge,int original)
{
        original = me->query_skill("yunv-xinfa")/2;
        me->add_temp("apply/strength", - bili/2);
        me->add_temp("apply/dexerity",-dodge/2);
        me->add_temp("apply/armor", -original);
        me->add_temp("apply/damage", -original);
        me->delete_temp("suxin");

        tell_object(me, "�㻺������һ�������ջ���Ů���ģ������ֻص����\n");
}
