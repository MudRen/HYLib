
// shisan �컨ʮ����
// 2000.5.30  by ybl

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
object weapon;
int i,j;

if( !target ) target = offensive_target(me);

if( !target || !target->is_character()|| !me->is_fighting(target) )

 return notify_fail("���컨ʮ������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail("����ʹ�õ���������\n");

if ( (int)me->query_int() < 35 )
 return notify_fail("������첻�㣬�������򡸺컨ʮ���������\n");


if( (int)me->query_skill("luohua-jian", 1) < 199 )
 return notify_fail("��ĺ컨ʮ��������������죬����ʹ�á��컨ʮ��������\n");

if( (int)me->query("neili")<800)
 return notify_fail("����������̫��������ʹ�á��컨ʮ��������\n");

if( (time()-(int)me->query_temp("last_perform_time"))<
  me->query_temp("last_perform_busy") )
 return notify_fail("���������ת��û����ô�졣\n");
if( random(me->query("combat_exp")) < (int)target->query("combat_exp")/3 )
{
me->start_busy(4);
if( !target->is_killing(me) ) me->kill_ob(target);
me->add("neili",-500);
message_vision(YEL+"\n$N"+RED+"����ͼ��������!,$N��ʱ����������!\n"NOR,me);
return notify_fail("��Ĺ���ʧ���ˡ�\n");
}
me->set_temp("last_perform_time",time());
me->set_temp("last_perform_busy",1);
if( !target->is_killing(me) ) me->kill_ob(target);
/* */ if(random(2)==1) {
/* */ i=13;
  message_vision(YEL+"\n$N"+RED+"������Ц�������컨�����������С�\n"NOR,me);
}
else {
/* */ i=12;
 message_vision(YEL+"\n$N"+RED+"������Ц�������컨�����������С�\n"NOR,me);
}


/* */ weapon=me->query_temp("weapon");
/* */ for(j=1;j<=i;j++) {
 COMBAT_D->do_attack(me, target, weapon, 1);
}
me->start_busy(4);
me->add("neili",-550);

return 1;
}
