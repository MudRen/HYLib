 // mimicat@fy4
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg,weapon_name;
        int extra, myexp, hisexp;
        object weapon,myweapon;
        if(me->is_busy())
                return notify_fail("��������æ����\n"); 
        extra = me->query_skill("ittouryu",1) ;
        if ( extra < 100) return notify_fail("��ģ�һ���������ݻ��������죡\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
			return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("neili") < 600 )
		return notify_fail("�������������\n");                
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�������У�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
        weapon = target->query_temp("weapon");
        myexp = (int)me->query("combat_exp");
        hisexp= (int)target->query("combat_exp");
        myweapon = me->query_temp("weapon");
        weapon_name= myweapon->query("name");
        
        if(random(hisexp*5) < (extra*extra*extra/4+myexp+hisexp)/3  && weapon)  
        {
        message_vision(
HIG "$N��������$n�Ĺ��������һ���������С�����"+weapon_name+"�߾ٹ��磬
�����Ϸ�ֱ��$n������
���$N������һ���һ����$n�����еı�������ʶ��һ����
"+ HIW"
$nֻ���û���һ�ȣ����е�"+weapon->name()+"��Ҳ�ò�ס�ˣ���������һ�����ڵ��ϡ�\n\n" NOR, me,target);
        if(weapon->unequip()) weapon->move(environment(target));
        me->start_busy(1);
        }
        else if(random(hisexp*3) < (extra*extra*extra/4+myexp+hisexp)/3  && weapon)
        { 
        msg = HIG "$N��������$n�Ĺ��������һ���������С�����"+weapon_name+"�߾ٹ��磬
�����Ϸ�ֱ��$n������
���$N������һ���һ����$n�����еı�������ʶ��һ����"+
HIC"\nֻ���á�������һ�����죬�������еı���һ�𣬸��Ժ�����һ����\n\n"+ NOR;
        message_vision(msg,me,target);
        me->start_busy(2);
        target->start_busy(2);
        }
        else
        {
        msg = HIG "$N��������$n�Ĺ��������һ���������С�����$w�߾ٹ��磬
�����Ϸ�ֱ��$n������"NOR;
        	if (extra >= 300) extra=300;
        me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra*2);
        	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra*2);
        me->start_busy(2);
        me->add("neili",-300);
        }  
        return 1;
}    
