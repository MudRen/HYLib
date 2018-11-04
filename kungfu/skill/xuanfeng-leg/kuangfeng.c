// kuangfeng.c  ������

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon, ob;
        string msg;
int extra;
if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����������ֻ����ս����ʹ�á�\n");
 
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������������ʼʱ�������ű�����\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("�������������\n");

	if( (int)me->query_skill("bibo-shengong",1) < 50 )
		return notify_fail("��ı̲��񹦲�����\n");
        if (me->query_skill_mapped("unarmed") != "xuanfeng-leg")
                return notify_fail("��û�м�������ɨҶ�ȣ�����ʩչ��\n");
	if( (int)me->query_skill("luoying-zhang",1) < 100 ||
	    me->query_skill("xuanfeng-leg",1) < 100)
		return notify_fail("������ƹ��򻹲����ң��޷�ʹ�ÿ�������\n");

	extra = me->query_skill("xuanfeng-leg",1) / 10;
	extra += me->query_skill("luoying-zhang",1) /20;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", 900);
	msg = YEL "$Nʹ���һ�����������������������Ȼ�ӿ죡" NOR;
if (!target->is_busy() && random(6)==0 ) target->start_busy(2);

	message_vision(msg, me, target);                
	msg =  YEL  "$N���������ƣ�����һ�Ÿ����߳���" NOR;
        	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = CYN  "��Ӱ�У�$N����������ƴ����û���$n��" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "$N��$n�Ż��󿪣�����������˫����������$n��" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = CYN  "$NԽսԽ�£���Χ����һ�����磬ʹ��$n�����巽��" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL "$N���ǹ�է�֣������Դ���Ȼ֮ɫ����$n��" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = CYN "$N��Хһ��������෢����Ȼת��$n��󣬷�������һ�ƣ�" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);	
	me->add_temp("apply/damage", -900);

	me->add("neili", -200);
        me->start_busy(2);

        return 1;
}

