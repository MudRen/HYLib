#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        extra = me->query_skill("six-sword",1);
        if ( extra < 150) return notify_fail("�������׷�꽣�����������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�ۺ�Ԩ�˽���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        if((int)me->query("neili") < 500 )
                return notify_fail("�������������㣬����ʹ�ã�\n");
                weapon = me->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "sword"       )
                return notify_fail("������û�н����޷�ʹ�ã�\n");                 
        msg = HIY  "$Nʹ����Ԩ�����еģۺ�Ԩ�˽��ݣ�һ�������˽���������е�"+ weapon->name()+  "�������$n������ˮ����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "���޽���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIC  "���Ľ���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIM  "��������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "���ƽ���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "ɱ�˽���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "�޵н���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
        msg = HIY  "���ֽ���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = HIG "\n$Nһ���ӳ� ����һ����û������$N���У���ʱ��ͣ��ֹ�������Ϣ���ղŵ�һ���� 
���ƺ�ֻ��һ�����Σ���Ȼ�޴档" ;

if(random(2)==0)
{
	 target->start_busy(2);
	target->add("jing",-extra);
target->add("eff_jing",-extra);
}	
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili",-380);
        me->start_busy(3);
        return 1;
}