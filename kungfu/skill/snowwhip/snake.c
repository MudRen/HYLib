//by greenwc 2000.11
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
void snake_ok(object);
int perform(object me, object target)
{
	string msg;
        object weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С����ߡ���\n");
                
        if(!me->is_fighting())
                return notify_fail("�����ߡ�ֻ����ս����ʹ�ã�\n");
        if((int)me->query("max_neili") < 500 )
                return notify_fail("�������������\n");
          if((int)me->query("neili") < 500 )
                return notify_fail("����������㣡\n");
        if((int)me->query("jing") < 200 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

         if((int)me->query_skill("snow-zhang",1) < 150)
                return notify_fail("��ķ�ѩӳ÷����Ϊ������\n");
         if((int)me->query_skill("hanshan-strike",1) < 150)
                return notify_fail("��ĺ�ɽ�Ʒ���Ϊ������\n");
         if((int)me->query_skill("doom-hand",1) < 150)
                return notify_fail("��ĺ���������Ϊ������\n");                                
         if((int)me->query_skill("snowwhip",1) < 150)
                return notify_fail("��ĺ�ѩ�޷���Ϊ������\n");   

         if((int)me->query_skill("bingxue-xinfa",1) < 150)
                return notify_fail("��ı�ѩ�ķ���Ϊ������\n"); 

        if((int)me->query_skill("snowwhip", 1) < 100)
                return notify_fail("��ĺ�ѩ�޷�����������ʹ����һ�л������ѣ�\n");

          if(me->query_temp("no_snake"))
                        return notify_fail("�������������ӣ��Ȼ�����ðɣ�\n");

        me->delete("env/brief_message");
        target->delete("env/brief_message");
message_vision(HIC"\n$N���б��Һ�Ȼ̧��������֮�����$n\n"NOR,me,target);
me->set_temp("SS_perform", 7);  
        if (random(3)==0) target->start_busy(3);
               msg =  HIC  "��һ�� ���ǵ�㣡" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                msg = HIC "�ڶ��� �������⣡" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                msg = HIC "������ �����ѩ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                msg = HIC "���ı� ѩ�����棡" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                msg = HIC "����� ��ѩ���ߣ�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                msg = HIC "������ �����ѩ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                msg = HIC "���߱� ��ѩ���ӣ�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->delete_temp("SS_perform");
        me->receive_damage("jing", 50);
me->add("force", -50);

        me->add("neili", -390);
me->start_busy(3);
        me->set_temp("no_snake",1);
                call_out("snake_ok",1+random(2),me);

return 1;
}
void snake_ok(object me)
{ if (!me) return;
      me->delete_temp("no_snake");
}
