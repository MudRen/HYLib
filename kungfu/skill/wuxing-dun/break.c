// break.c ��ݾ�ɱ
// Modified by Venus Oct.1997
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
string msg;
int count;
  if( !target ) target = offensive_target(me);
if( !me->is_fighting() )
      return notify_fail("����ݾ�ɱ��ֻ����ս����ʹ�á�\n");
if( (int)me->query("qi") < 100 )
      return notify_fail("�����������\n");
if( (int)me->query("max_neili") < 200 )
      return notify_fail("�������������\n");
if( (int)me->query("neili") < (int)me->query("max_neili")/2)
      return notify_fail("�������������\n");
    if ((int)me->query_skill("shayi-xinfa", 1) < 30)
   return notify_fail("���ɱ���ķ���򲻹���\n");

	if((int)me->query_skill("wuxing-dun",1) < 50)
		return notify_fail("������ж��е���Ϊ����, ����ʹ����һ���� !\n");
	if((int)me->query_skill("dodge") < 50)
		return notify_fail("����Ṧ��Ϊ������ Ŀǰ����ʹ��! \n");

 	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����ݾ�ɱ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

msg = HIC "$Nʹ�����ж��еġ���ݾ�ɱ��������Ȼ���ñ��Ī�⣡\n" NOR;
message_combatd(msg, me);
count = (int)me->query_skill("wuxing-dun") / 40 + 2;
   if( count > 6 ) count = 6;
   while( count-- )
 {
  object ob;
  me->clean_up_enemy();
  ob = me->select_opponent();
  if( !ob || (environment(ob) != environment(me))) {
  message_combatd(WHT "$N������ٿ��һת������ͣס�˽Ų���\n" NOR, me);
     break;
   }
  else

  message_combatd(WHT "$N����Ӱ��$n����ʱ��ʱ�� ...\n" NOR, me, ob);
  COMBAT_D->fight(me, ob); 
if (!me->query("double_attack"))
  COMBAT_D->fight(me, ob);      
  me->receive_damage("qi", 30);
  me->add("neili", -50);
 }
    me->start_busy(2);
    return 1;
}

