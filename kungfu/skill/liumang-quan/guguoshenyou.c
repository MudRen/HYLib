#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        if(me->is_busy())
                return notify_fail("������û�գ���\n");
        extra = me->query_skill("liumang-quan",1);
	if ( extra < 50) return notify_fail("�����å��ȭ���������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۹ʹ����Σ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if( (int)me->query("neili", 1) < 600 )
		return notify_fail("�������������㣬����ʹ�ã�\n");	
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����书ֻ�ܿ���ʹ�á�\n");		
extra=extra/3;
if (extra> 200) extra=200;
        me->add_temp("apply/damage",extra);
        me->add_temp("apply/attack",extra);

        msg = HIY  "$N���쳤Ц��ʹ����С��ɽ�Ƶģ۹ʹ����Σݣ�һ�ɺ�Ȼ����ֱ��������\n" NOR;
        message_vision(msg,me,target);
        msg = HIR  "��" NOR;
                msg+= "\n$N�����ھ���˫�������ֱȡ$n��$l��";
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "      ��" NOR;
                msg+= "\n$N�ұ��绷��Ȧס$n���ֱۣ����ֺ���������һȭ����$p��";
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIM  "            ��" NOR;
                msg+= "\n$N������磬ת�ۼ�˫���Ѿ�������$n����ǰ��";
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "                  ��" NOR;
                msg+= "\n$N����һ�ۣ�����»���$n��ֱ����֪����ζ�ܣ�";
if (random(3)==0) target->start_busy(2);
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->start_busy(2);
        me->add_temp("apply/damage",-extra);
        me->add_temp("apply/attack",-extra);
        return 1;
}    
