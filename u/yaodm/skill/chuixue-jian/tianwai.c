#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
           
   if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if((int)me->query("neili") < 1500 )
                return notify_fail("�������������\n");

        if ((int)me->query("max_neili") < 2000)
                return notify_fail("�������������\n");
       
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if((int)me->query("jing") < 200 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");


        if((int)me->query_skill("chuixue-jian", 1) < 200)
                return notify_fail("��ĺ��촵ѩ�����ȼ��������޷�ʹ�á�������ɡ���\n");
 
             weapon=me->query_temp("weapon");
           me->delete("env/brief_message");
           message_vision(HIY"\n$N����Ծ��ʹ�����촵ѩ�����ռ�������������ɡ�!n"NOR, me);
           message_vision(HIB"\nͻȻֻ��$Nʹ�����촵ѩ�����ռ�������������ɡ���\n"NOR, me);
                      me->delete("env/brief_message");
   target->delete("env/brief_message");

message_vision(HIC"\n$N����Ծ��ʹ�����촵ѩ�����ռ�������������ɡ�!\n"NOR,me,target);
message_vision(HIB"$N��Х�����죡����\n"NOR,me,target);        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
message_vision(HIM"$N��Х�����⣡����\n"NOR,me,target);        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIR"$N��Х�����ɣ�������\n"NOR,me,target);                
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIR"$N��Х�����ɣ�������\n"NOR,me,target);                
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIW"\n$N������δ��,������������籩��֮������$n��ȥ��\n"NOR, me, weapon);
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           message_vision(HIC"\n$N�޷�������Ϣ������ֻ�ú�Ծ���С�\n"NOR, me, weapon);


           me->add("neili", -400);

          if( !target->is_fighting(me) ) {
                    if( living(target) ) {
                    if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

   me->start_busy(4);
   return 1;
}


