#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


inherit F_SSERVER;
 
int perform(object me, object target)
{
        string msg;
	int extra;
	object weapon,ob;
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	extra = me->query_skill("qishang-quan",1);
        if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("�����Ļ�ϡ�ֻ����ս����ʹ�á�\n");
 
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����Ļ�ϡ�ֻ�ܿ���ʹ�á�\n");		
       
	 if( (int)me->query("neili") < 700 )
                return notify_fail("�������������\n");

        if( extra < 200 )
                return notify_fail("�������ȭ��򲻹����޷�ʹ�á����Ļ�ϡ���\n");

        if( (int)me->query_skill("shenghuo-shengong",1) < 150 )
                return notify_fail("���ʥ������Ϊ�������޷�ʹ�á����Ļ�ϡ���\n");
	
	weapon = me->query_temp("weapon");
// not tiezhang-zhangfa, should be qishang-quan (by xbd)
	extra = me->query_skill("qishang-quan",1) / 20;
	extra += me->query_skill("force",1) /20;
	me->add_temp("apply/attack", (extra*2));	
	me->add_temp("apply/damage", (extra*10));

        msg = HIW "$N���λ�ת��ŭ��һ����ͬʱʹ������ȭ�еľ��裬һ��[���Ļ��]��������$n��" NOR;
        	         message_vision(msg, me, target);                
	 msg =  HIW  "�������" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "�ݳ�����" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "��ʧ����" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "��������" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW "�˷ξ���" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "���ľ���" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW "���㱾���" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -(extra*2));
	me->add_temp("apply/damage", -(extra*10));
        me->add("neili", -400);
        me->start_busy(2);

        return 1;
}

