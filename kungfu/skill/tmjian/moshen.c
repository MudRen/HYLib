#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int my_exp,your_exp;
        int extra, n, force,damage,damage1,damage2;
        int tmp,chance,skill;
        object weapon;
        
        skill = me->query_skill("tmjian",1);
        extra=skill+random(skill);
          
        damage = extra*3/2;
        if (skill < 280) return notify_fail("�����ħ�����������죬���ܽ����ʮ����ħ�ݵ�������磬�����߻���ħ��\n");

        tmp = me->query_skill("sword",1);
        if (tmp < 200) return notify_fail("��Ļ����������������죡�����׼���Ѫħ������\n");

        if ( (int)me->query_int() < 50 )
        return notify_fail("����������Բ��㣬����������ħ���ľ�����ʽ"RED"��ʮ����ħ����\n"NOR);
        
        if( (int)me->query_skill("tmjian",1)<199)
        return notify_fail("�����ħ����������죡\n"NOR);
        
        if( (int)me->query_skill("tmdao",1)<199)
        return notify_fail("�����ħ����������죡\n"NOR);

        if( (int)me->query_skill("tmquan",1)<199)
        return notify_fail("�����ħȭ��������죡\n"NOR);

        if( (int)me->query_skill("tmzhang",1)<199)
        return notify_fail("�����ħ�Ʒ�������죡\n"NOR);

        if( (int)me->query_skill("pmshenfa",1)<199)
        return notify_fail("���Ʈ����������죡\n"NOR);

        if( (int)me->query_skill("tmdafa",1)<199)
        return notify_fail("�����ħ�󷨲�����죡\n"NOR);


        if( !(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "sword" )
        return notify_fail("������û��װ������������\n");
        if( (int)me->query("neili")<600)
        return notify_fail("����������̫��������ʹ�ã�\n"NOR);
                
        if( !target ) target = offensive_target(me);
        if( !target
        || !target->is_character()
        || !me->is_fighting(target) )
                return notify_fail("��ʮ����ħ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
        chance=extra+tmp;
        if (extra> 200) extra=200;
        me->add_temp("apply/attack",100);
        me->add_temp("apply/damage",1000);


        weapon = me->query_temp("weapon");
        message_vision(HIR "\n\n $N�������֣������������һƬ���£����д��һ����"NOR,me);
        msg =HIR "\n ��"+HIM"��"+HIR"��"+HIY"Ũ"+HIR"��"+BLU"��"+HIR"��"+HIG"��"+HIR"��"+WHT"��"+HIR"��\n" NOR;
// msg += HIM "\n��\n" NOR; 
        msg += MAG "\n$N"+MAG"�����г���ħ�⣬���е�ħ���ڿ��з��裡\n"+CYN"Զ������һ����������������Զ������һȺ����ӵ��һ�Ż���������������������"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (chance>random(300)) {
  message_vision(HIM"\n       				��"NOR,me);
// message_vision(HIY "\n Ũ\n" NOR,me);
         msg =WHT "\n�����Ĺ���"+HIG"�п�ȸ���ᣬ"+BLU"������ĳᣬ"+BLK"�����ӵļ�β��"+HIY"���۷�Ķ��룬"+HIC"��ߵĳ���أӥ��\n"
         +BLU"��ߵĳ�������"+HIG"��ߵ���ë�ǿ�ȸ��"+HIR"��ߵ���ë�Ƿ�ˡ�\n"+HIW"�����ɡ����ڣ����ӵļ�β��������ȸ����ë�Իͣ���˵���ë������\n"+HIM"ÿһ����ɫ������ϵ�������������Ѱ����������Ѱ���Ĺ֡�\n"
         +HIG"ÿһֻ��Ĳ����϶�����һ���塣�������죬�·�Ҫ���˵Ļ��ǡ�\n"NOR;


        my_exp = random(me->query("combat_exp")*5);
        your_exp = (int)target->query("combat_exp");
        
        if( my_exp > your_exp) {
                msg += HIR "\n$n"+HIR"�Ļ��ǲ�δ��������������ǿ�"+HIR"$n"+HIR"�Ǹ����ӣ�ȴ�������ǲ��壬ʧ�����ǣ�\n" NOR;
// target->start_busy(3);
                 damage1 = extra*7;
                 target->receive_damage("jing", damage1);
                 target->receive_wound("qi", damage1);
                 target->receive_damage("qi", damage1);
        } else {
                msg += CYN "\n$n"+CYN"���˶�����û�б���ǰ�ļ����Ի󣬵���Ȼ����������\n" NOR;
                		target->query_busy(3);
        }
        message_vision(msg, me, target); 
        }
        if (chance>random(350)) {
                message_vision(HIY "\n      			 	Ũ" NOR,me);
// message_vision(BLU "\n ��" NOR,me);

                msg = MAG "\n$N"+MAG"ͻȻ��ʧ��"+MAG"��������к�Ȼ������ʮ���$w��" NOR;
target->start_busy(2);
                 target->receive_wound("qi", damage);
                 target->receive_damage("qi", damage);

                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
        if (chance>random(400)) {
                message_vision(BLU "\n       				��" NOR,me);
// message_vision(HIG "\n ��"NOR,me); 
                msg = MAG "\n���°��$w"+MAG"��ҫ������Ĺ�â��\n" +MAG"����ʮ����ħ�����У������������֣��������������������֮��һƬ���¡�"NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
        if (chance>random(450)) {
                message_vision(HIG "\n       				��"NOR,me);
// message_vision(WHT"\n ��" NOR,me); 
          msg = HIC "\nһ�����������ͻȻ�ڱ������������ʮ����ħ�����ս�������������ʳָ�����ݸ����¡�\n"+BLINK RED"�����һ����\n"NOR;
    msg += HIC "ʮ���$w"+HIC"һ�����ʮ��ֻʳָ֮�ϣ�ʮ���ħѪ�ӽ����зɳ�����ħָ�зɳ���"NOR;
target->start_busy(2);
                 target->receive_wound("qi", damage);
                 target->receive_damage("qi", damage);

    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
  }
         if (chance>random(500)) {
           
           if (me->query("class")!="xuemo") 
             {
               damage = damage*5;
               extra = extra*5;
             }
           

           message_vision(WHT"\n       				��" NOR,me);
           msg= HIG "\n�����ǧ���ٰ�ʮ�ߵ�ħѪ�γ���һֻ"+HIR"Ѫ����"+HIG"��$n"+HIG"��Χ��������"NOR;
target->start_busy(2);
                 target->receive_wound("qi", damage);
                 target->receive_damage("qi", damage);

    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        }
                me->add("neili",-500);
                me->start_busy(4);
        me->add_temp("apply/attack",-100);
        me->add_temp("apply/damage",-1000);

        
        return 1;
} 
