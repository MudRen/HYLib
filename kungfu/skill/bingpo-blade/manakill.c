// made by cii for snow
#include <command.h>
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
       string msg;
       int ski_value, max_lv;
       object weapon;
       ski_value= random(me->query_skill("bingpo-blade",1));
       max_lv=me->query_skill("bingpo-blade",1);

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ħ��ɱ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
          if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ��\n");

   if( me->query_skill("bingpo-blade",1)<300 )
         return notify_fail("��ı��ƺ������ɲ��㡣 \n");
	if ((int)me->query_skill("huagong-dafa", 1) < 125)
		return notify_fail("��Ļ����󷨻�򲻹�.\n");
   if( me->query_skill("blade",1)<100 )
         return notify_fail("��ĵ��������á� \n");
   if(me->query("neili")<1000)
         return notify_fail("�������������\n");
   //if( target->is_busy() )
   //   return notify_fail(target->name() + "Ϊ�˶�����ɱ��,Ŀǰ���Թ˲�Ͼ!\n");
msg = HIY "$N�Բм���,��Ѫ��ת����ɱ����\n
            ����$N���Ϸ���һ��ǿ���ɱ������\n
    ��$N����ɱ���𽥵ؾۼ���˫��,��˫�����γ�����ħ����\n
            $Nٿ�ش��һ������ħ �� ɱ����\n\n" NOR;

     if( ski_value +50 < random(max_lv) && me->query("combat_exp")>2000000){
     msg += HIR BLINK "$NͻȻ��ͷһ��������ֻ��$N�������һ��Ѫ����$n��ȥ����\n
����ħ��ɱ֮
            ����ɱ�� ��ħ Ѫ �� ɱ��\n\n
$n�⵽ǰ��δ�еĴ��,��$NҲ���˲��ᡣ\n" NOR;
     target->start_busy( (int)me->query_skill("bingpo-blade") / 60 + 3);
if (userp(target))
{    
     target->receive_damage("qi",target->query("max_qi")*70/100);
     me->receive_damage("qi",me->query("qi")*30/100);
}
else
{
     target->receive_wound("qi",ski_value*8);
     me->receive_damage("qi",me->query("qi")*20/100);
	
}
     me->add("neili",-50);  
     }
   else if( ski_value < 20 ){
      msg +="$N������ת����ɱ��������,�Ե��˺���Ӱ�졣\n";
      me->receive_damage("qi",me->query("qi")*1/100);
      me->add("neili",-me->query("max_neili")*3/10);    
       }
     message_vision(msg, me, target);

    me->add_temp("apply/attack", 100);	
    me->add_temp("apply/damage", 1000);
     
    if( ski_value >  70 ){
     msg = HIM "��һ�� ��ħ���޳���\n" NOR;
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

      }
    
    if( ski_value >  90 ){
     msg = HIG "�ڶ��� ����ħɷ��\n" NOR;
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
 
     }
     
     if( ski_value > 100 ){
     msg = HIC "������ ���̻�ħ��\n" NOR;
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

     }

     if( ski_value >  120 ){
     msg = HIB "������ ����ħ������\n" NOR;
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        }

     if( ski_value >  140 ){
     msg = HIW "������ ����ħ�ƿա�\n" NOR;
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        }


     if( ski_value >  160 ){
     msg = CYN "������ ��Ⱥħ���衻\n" NOR;
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
      }

     if( ski_value >  180 ){
     msg =  YEL "������ ���켫ħɱ��\n" NOR;
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

  }

     if( ski_value >  200 ){
     msg = BLU "�ڰ��� ����ħ�����꡻\n" NOR;
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       }

      if( ski_value >  300 ){                {
     msg = RED "�ھ��� ����ħ��תҵ��\n" NOR;
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
 
       }

    me->add_temp("apply/attack", -100);	
    me->add_temp("apply/damage", -1000);
me->start_busy(3);
        return 1;

     }
}
