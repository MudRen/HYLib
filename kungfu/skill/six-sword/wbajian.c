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
                return notify_fail("�����°˽���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        if((int)me->query("neili") < 500 )
                return notify_fail("�������������㣬����ʹ�ã�\n");
                weapon = me->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "sword"       )
                return notify_fail("������û�н����޷�ʹ�ã�\n");         
        
        msg = HIY  "$N"HIY"ʹ�����ڽ����еģ����°˽��ݣ�һ�������˽���������е�"+ weapon->name()+  HIY"�������$n�������½���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "���ɽ���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "���콣��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIM  "�μҽ���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "���Ž���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "ɱ�˽���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "���ֽ���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
        msg = HIY  "佻�����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

      msg = HIC "$Nһ���ӳ�����Ϧ�����������գ���ʺ磬�������ƣ��綯�־���������ʵ��
�����������ң�����ǰ�������ᣬ��������������ʵ�� \n"NOR;
if(random(2)==0)
{
	 target->start_busy(2);
	target->add("qi",-extra*5);
target->add("eff_qi",-extra*3);
}	
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);



        me->add("neili",-380);
        me->start_busy(3);
        return 1;
}
