#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;
	if( !target ) target = offensive_target(me);

if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����ʯ��١�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query_skill("tianyu-qijian", 1) < 180 )
		return notify_fail("��������潣������죬����ʹ�á�\n");

	if(((int)me->query_skill("bahuang-gong", 1) < 40 ) &&
	   ((int)me->query_skill("beiming-shengong", 1) < 40 ))
		return notify_fail("��ı����ڹ�������졣\n");

       if(!( me->query("eff_qi")<100||(int)(me->query("max_qi")/me->query("eff_qi"))>=2.5))
             return notify_fail("�㻹û�����ˣ���Ҫʹ����ʯ��١�\n");

	if(((int)me->query_skill("bahuang-gong", 1) < 100 ) &&
	   ((int)me->query_skill("beiming-shengong", 1) < 100 ))
		return notify_fail("��ı����ڹ�ʵ��̫�û���á���ʯ��١���\n");

	if( (int)me->query("max_neili", 1) < 1500 )
		return notify_fail("����������̫��������ʹ�á���ʯ��١���\n");
			
	msg = RED "$NԾ�����ɣ���ɫ���أ�һ��[��ʯ���]���$nͬ���ھ���\n"NOR;
	
if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
		msg += "���$p��$P���˸����ֲ�����������ȥ��\n" NOR;
if (target->query("qi") > 50000)
{
target->add("qi",-35000);
target->add("eff_qi",-35000);
}else target->unconcious();
if (random(10) == 1)
                {
		msg += "$P�Լ�Ҳ�����������ȣ�������ȥ��\n" NOR;
                me->unconcious();
                }
	} else {
		msg += "����$p���Ƕ����$P�����һ������\n" NOR;
		me->start_busy(3);
	}
	message_vision(msg, me, target);
//        me->unconcious();
	return 1;
}
