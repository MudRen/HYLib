#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
	 int extra;
	 object weapon;
        extra = me->query_skill("xianglong-zhang",1);
	 if( !target ) target = offensive_target(me);
        if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("��"+HIY"��"NOR+HIC"��"NOR+HIW"��"NOR+HIR"��"NOR+"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

               if( objectp(me->query_temp("weapon")) )
              return notify_fail("��������ʹ�á�"+HIY"��"NOR+HIC"��"NOR+HIW"��"NOR+HIR"��"NOR+"����\n");
     
        if( (int)me->query_skill("xianglong-zhang", 1) < 200 )
                return notify_fail("��Ľ���ʮ���Ʋ�����죬�޷�ʩչ����"+HIY"��"NOR+HIC"��"NOR+HIW"��"NOR+HIR"��"NOR+"����\n");
if ( me->query_skill_mapped("force") != "huntian-qigong" )
return notify_fail("��û�ñ����ڹ���\n");
if ( me->query_skill_mapped("unarmed") != "xianglong-zhang" )
return notify_fail("��û��ʹ�������Ʒ���\n");

        if (me->query_skill("huntian-qigong", 1)<120)
                return notify_fail("��ı����ڹ����δ������\n");
       
        if ( (int)me->query("max_neili") < 2000)
                return notify_fail("��������������޷�ʩչ����"+HIY"��"NOR+HIC"��"NOR+HIW"��"NOR+HIR"��"NOR+"����\n");
        if ( (int)me->query("neili") < 1500)
                return notify_fail("��������������޷�ʩչ����"+HIY"��"NOR+HIC"��"NOR+HIW"��"NOR+HIR"��"NOR+"����\n");
                 me->add_temp("apply/strength", extra);
                 me->add_temp("apply/attack", extra*2);
	         me->add_temp("apply/damage", extra*2);
	me->add("neili", -600);
		 msg = YEL "$N˫��ƽƽ�ᵽ��ǰ����ɫ���صĻ���ʩ������ʮ���Ƶ����һ�С�"+HIY"��"NOR+HIC"��"NOR+HIW"��"NOR+HIR"��"NOR+YEL"��һ�а�ʽ����$n��" NOR;
       	         message_vision(msg, me, target);                
	 msg =  HIC  "��һʽ��$N����һʽ��������Ұ���������ޱȵ�����$n��" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "�ڶ�ʽ��$N˫��ʩ��һʽ��������½��������ԼԼ�����Ʒ�����$n��" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "����ʽ��$N�������أ�����һʽ��Ǳ����������������$n��" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "����ʽ��$Nʹ������Ծ���졹����$n���������ƣ�" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG "����ʽ��$N˫��һʽ��˫��Ϸˮ��һǰһ����$n����ǰ��" NOR;
              COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIM  "����ʽ��$N����ת����ʹ����������������$n�������£�" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "����ʽ��$N����һת��ͻȻ�۵�$n��ǰ��һʽ����ս��Ұ��ֱ����$n����" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW "�ڰ�ʽ��$NͻȻ����˫�ƾӸ��������һʽ����Х���졹ȫ������$n��" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->add_temp("apply/strength", -extra);
        me->add_temp("apply/attack", -extra*2);
        me->add_temp("apply/damage", -extra*2);
        if( random(me->query("combat_exp")) > target->query("combat_exp")/4
		&& me->query("xlz/hang"))
	 {

 msg = HIR"��ҧ�����أ�˫�ƻ�������Ĭ���ʮ���ƵĿھ�!"+HIY"��"NOR+HIC"��"NOR+HIW"��"NOR+HIR"��!!"NOR+" ";
                msg += RED"\n������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n"NOR;
                target->receive_damage("qi",(int)me->query_skill("xianglong-zhang")*2);
                target->receive_wound("qi",(int)me->query_skill("xianglong-zhang")*2);
		target->receive_wound("jing", 10 + random(200));
                if (!target->is_busy()) target->start_busy(2);
//             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		message_combatd(msg, me, target);
                COMBAT_D->report_status(target);
	}
        me->start_busy(5);
        return 1;
}
