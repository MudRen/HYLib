// jianzhang.c  ��ɽ���
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon, ob;
        string msg, string1;
        int count,extra;
  if( !target ) target = offensive_target(me);

	if( !me->is_fighting() )
		return notify_fail("����ɽ��塹ֻ����ս����ʹ�á�\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
            return notify_fail("��ʹ�õ��������ԡ�\n");

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("����ɽ��塹ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("huagong-dafa",1) < 60 )
                return notify_fail("��Ļ����󷨹���������\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("�������������\n");

	if( (int)me->query_skill("staff",1) < 200 ||
	    me->query_skill_mapped("staff") != "tianshan-zhang")
		return notify_fail("�����ɽ�ȷ��������ң��޷�ʹ����ɽ��壡\n");

	msg = HIY "$Nʹ����ɽ�ɾ�������ɽ��塹������Ȼ�ӿ졣�������ڣ�" NOR;
	
        extra = me->query_skill("tianshan-zhang",1) / 10;
        extra += me->query_skill("huagong-dafa",1) /10;
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra*2);
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  HIB  "        ^^�����أ�^^       " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  RED  "      ^^^^ɽ��������^^^^  " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  HIM  "    ^^^^^^���ż�ɽ��^^^^^ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIC  "^^^^^^^^^^^��ɽѩ����^^^^^^^^^^^ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -extra);    
        me->add_temp("apply/damage", -extra*2);
        if (me->query_skill("tianshan-zhang",1) > 250)
        {
        message_vision(HIY"$N����ͷ��ð�����̹�$n���̹�ɨ�У�ȫ����һ��!\n"NOR,me,target);
        target->apply_condition("xx_poison",60);
        target->apply_condition("corpse_poison",60);
	 msg =  HIR  "����ʬ����" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        target->apply_condition("x2_sandu",60);
	 msg =  HIR  "����ɰ�ơ�" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        target->apply_condition("sanpoison",60);
	 msg =  HIR  "�����ζ���" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili", -150);
        if (random(me->query("combat_exp")) >target->query("combat_exp")/2)
        {
       	 msg =  HIR  "����Ц��ңɢ��" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"$NͻȻ�����һЦ��$n��Ȼ����Ц��Ц!\n"NOR,me,target);
        target->apply_condition("sanxiao_poison",6);
        me->add("neili", -50);
        }
}
	me->add("neili", -250);
	me->start_busy(2);
	return 1;
}
