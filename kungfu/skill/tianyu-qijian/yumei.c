// �꼤÷������� ��չ÷���⼼
// by hem
// yumei.c perform wuzhan-mei
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{      
       int damage;
       object weapon;
       object obj;
       string msg;
        if( !target ) target = offensive_target(me);
weapon = me->query_temp("weapon");
	if( !target || !target->is_character() )
	return notify_fail("��"HIC"�꼤÷�������"NOR"��ֻ�ܶԶ���ʹ�á�\n");
	if( (int)me->query_skill("bahuang-gong", 1) < 100 )
                return notify_fail("��İ˻Ĺ������ߣ��������á�"HIC"�꼤÷�������"NOR"����\n");

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("����������̫��������ʹ�á�"HIC"�꼤÷�������"NOR"����\n");
         if(!weapon || weapon->query("skill_type") != "sword")
                 return notify_fail("�����ʹ����������ʹ�á����羪�硹��\n");   

	if(me->query_skill("tianyu-qijian")<100)
	return notify_fail("��������潣������죬�������á�"HIC"�꼤÷�������"NOR"����\n");
	if (!objectp(weapon = target->query_temp("weapon")))
	return notify_fail("���ֲ�û��ʹ��������\n");
	msg = HIM"$N���н�ббһ����ʩչ����"HIC"�꼤÷�������"HIM"������ƮƮѹס$n�ı�����\n"NOR;
	me->start_busy(2);
//	if (random(me->query_skill("force")) > target->query_skill("force")/2 )
	if( random( (int)me->query("combat_exp",1))>random(target->query("combat_exp")/2 ) )
	{
	msg +=HIY"ֻ����һ�����֮����$p�ı��о���$P���飬��м�籩��㷴����$p��\n" NOR;
	obj=target->query_temp("weapon");
	destruct(obj);
	damage = (int)me->query_skill("bahuang-gong", 1);
                
                damage = damage + random(damage/2)+200;
                
if (target->query("qi") >damage)
{
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/1);
}
                me->add("neili", -damage);
	if( damage < 120 )
                        msg += HIY"���$n�����ɵı�����м���У����˵���ˡ�\n"NOR;
       else if( damage < 140 )
                        msg += HIY"���$n�����ɵı�����м���У�����Щ�ˡ�\n"NOR;
        else if( damage < 180 )
                        msg += RED"���$n�����ɵı�����м���У����������˺ۣ���״���ң�\n"NOR;
                else
                        msg += HIR"���$n�����ɵı�����м���У��������¾�����һ�㣡\n"NOR;
                
	target->start_busy(5);
        } 
	else {
	msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
	me->start_busy(3);
}
message_vision(msg, me, target);
return 1;
}