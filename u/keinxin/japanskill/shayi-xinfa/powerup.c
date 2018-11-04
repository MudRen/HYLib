// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
   int skill;
   if( target != me )
   return notify_fail("��ֻ����ɱ���ķ��������Լ���ս������\n");
   if( (int)me->query("neili") < 150  )
   return notify_fail("�������������\n");
   if( (int)me->query_temp("powerup") )
   return notify_fail("���Ѿ����˹����ˡ�\n");

   skill = me->query_skill("force");
   me->add("neili", -50);
   me->receive_damage("qi", 0);
   message_combatd(
   HIY "$N����һ�䣬���Ʊ���һ���ˣ�ɱ���α�ȫ��\n" NOR,me);
   me->add_temp("apply/attack", skill/4);
   me->add_temp("apply/dodge", skill/4);
   me->set_temp("powerup", 1);

   me->start_call_out((:call_other, __FILE__, "remove_effect", me, skill/3:), skill);
   if( me->is_fighting() ) me->start_busy(3);
   return 1;
}

void remove_effect(object me, int amount)
{
   int skill;
   skill = me->query_skill("force");
   me->add_temp("apply/attack", -skill/4);
   me->add_temp("apply/dodge", -skill/4);
   me->delete_temp("powerup");
   tell_object(me, "���ɱ���ķ�������ϡ��ص���ƽ�������ӡ�\n");
}

