// tie@fengyun
#include <ansi.h>
#include <combat.h> 
         
inherit F_SSERVER; 
int perform(object me, object target)
{
	string msg;
	int extra,count,i;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������һ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("canglang-bian",1) / 5;
	if( extra <=10) return notify_fail("��������ƻ�����������\n");

      if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԡ�\n");


        if (me->query_skill("force") < 150)
                return notify_fail("����ڹ�����Ϊ����������ʹ�á�����һ������\n");

        if (me->query_skill("canglang-bian", 1) < 300)  
                return notify_fail("��ġ����˱޷� ��δ�����磬�޷�ʩ��������һ������\n");  

        if (me->query_skill("bibo-shengong", 1) < 150)  
                return notify_fail("��ı���������Ϊ�������޷�ʩ��������һ������\n");  

        if (me->query_skill_mapped("whip") != "canglang-bian")  
                return notify_fail("�����õĲ��ǡ����˱޷� ����ʩչ����������һ������\n");  

        if (me->query("neili") < 500)
                return notify_fail("��������������޷�ʹ�á�����һ������\n");
if (extra> 200) extra=200;

	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIR  "$N������ң����е�"+weapon->query("name")+"���ȣ���һ����������������$n��ȥ��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	msg = HIR "ͻȻ��$N" HIR "�͵�������ϣ�����" + weapon->name() +
              HIR "��ת�����Ʋ�Ҫ�������$n" HIR "�͹���ȥ��\n" NOR;

        if (random(me->query_skill("whip")) > target->query_skill("parry") / 2)
        {
                msg += HIR "$n" HIR "�䲻��������ʱ��æ���ң��м���"
                       "ɢ����æ�����Եֵ���\n" NOR;
                count = me->query_skill("whip") / 20;
        } else
        {
                msg += HIC "$n" HIC "�ĵ�һ������æȫ��Ӧ�ԣ�������"
                       "˿�����⡣\n" NOR;
                count = 0;
        }

	message_combatd(msg, me, target);
	me->add("neili", -180);
        me->add_temp("apply/attack", 80);

        for (i = 0; i < 6; i++)
        {

                if (random(3) == 1 && ! target->is_busy())
                        target->start_busy(1);
        	COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add_temp("apply/attack", -80);
	me->start_busy(3);
	me->add("neili",-300);
	return 1;
}
