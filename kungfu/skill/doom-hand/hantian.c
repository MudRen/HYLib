 // silencer@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int step,fist,extra;
        object weapon;
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������˫�ɣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail( "ֻ�ܿ���ʩչ��\n");
        
        step = me->query_skill("bingxue-xinfa",1);
        fist = me->query_skill("doom-hand",1);



         if((int)me->query_skill("bingxue-xinfa",1) < 150)
                return notify_fail("��ı�ѩ�ķ���Ϊ������\n");

         if((int)me->query_skill("snow-zhang",1) < 150)
                return notify_fail("��ķ�ѩӳ÷����Ϊ������\n");

         if((int)me->query_skill("doom-hand",1) < 50)
                return notify_fail("��������书��Ϊ������\n");
        
        if (step< 100) return notify_fail("��ģۺ������֣ݲ���������\n");
        if (fist< 100) return notify_fail("��ģ۱�ѩ�ķ��ݲ���������\n");
        
        //if (me->query("class")=="fighter") {
                fist= fist*3/2;
                step=step*3/2;
        //}       
        if (fist>=300)  fist=300;
        if (step>=300)  fist=300;	
                
        me->add_temp("apply/attack", fist);     
        me->add_temp("apply/damage", fist*2);
        msg = HIR  "$Nʹ���۾��غ����ƣݣ�ȫ�������ת��˫��һǰһ�������Ļ���$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->add_temp("apply/attack", -fist);
        me->add_temp("apply/damage", -fist*2);
        
        me->add_temp("apply/attack", step);     
        me->add_temp("apply/damage",step*2);
if (random(3)==0) target->start_busy(3);

        msg = HIC  "$N��һ������Ѹ���ޱȵ���$n�߳�����һ�ȣ�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIC  "$N��һ������Ѹ���ޱȵ���$n�߳�����һ�ȣ�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIC  "$N��һ��ת��Ѹ���ޱȵ���$n�߳�����һ�ȣ�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIC  "$N��һ��Ծ��Ѹ���ޱȵ���$n�߳�����һ�ȣ�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->add_temp("apply/attack", -step);
        me->add_temp("apply/damage",-step*2);
        me->add("neili", -300);
me->start_busy(3);
        return 1;
}
