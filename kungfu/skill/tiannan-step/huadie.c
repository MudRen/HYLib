#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int i,sl;
        object weapon;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        if (!weapon) return notify_fail("����ֻ�ܺͽ�����ͣ�\n");
        if( (string)weapon->query("skill_type") != "sword" )
        return notify_fail("����ֻ�ܺͽ�����ͣ�\n");

        if ((int)me->query_skill("kurong-changong",1) < 80)
            return notify_fail("��Ŀ�������̫�͡�\n");
        if ((int)me->query_skill("duanjia-sword", 1) < 80)
		return notify_fail("��Ķμҽ����̫ǳ��\n");    
        if ((int)me->query_skill("jinyu-quan", 1) < 80)
		return notify_fail("��Ľ���ȭ���̫ǳ��\n");
        if ((int)me->query_skill("wuluo-zhang", 1) < 80)
		return notify_fail("������������ƻ��̫ǳ��\n");
        if ((int)me->query_skill("feifeng-whip", 1) < 80)
		return notify_fail("��ķɷ�޻��̫ǳ��\n");


		        if ((int)me->query("neili") < 500)
                return notify_fail("�����ڵ���������������ʩչ��\n");
        extra = me->query_skill("tiannan-step",1) / 40;
        extra += me->query_skill("tiannan-step",1) /40;
        if (extra> 200) extra=200;
        sl=extra/3;
        if (sl > 9) sl=9;
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra);
        msg = HIG  "$N��̤�۶��ϲ����ݣ�ͬʱʹ���۶��Ͻ������еľ��裭��" + HIR"����"HIG + "�ݣ����е�"+ weapon->name() +"����" + HIC"��" + HIY"��" + HIG"������߻���$n��" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        for(i=0;i<sl;i++)
        {
        msg = HIC "$N������ʵ����裬�ֳ���"+chinese_number(i+1)+"����\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
 me->add("neili",-20);
        }
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        me->start_busy(2);
        return 1;

}