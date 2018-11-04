// tisha.c ��ɳ 
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
void remove_effect(object me, int f, int j);

int exert(object me, object target)
{
        object weapon;
        int damage,p;
        string msg,dodge_skill;
        int f = me->query_skill("jiuyang-shengong", 1)/4;
        int j = me->query("jiali")/5 + 20;
        
        if( !target )
                return notify_fail(WHT"��Ҫ��˭ʹ�á�ʥ���ѧ����\n"NOR);

        if( !target ) target = offensive_target(me);


        if( !target 
         || !me->is_fighting(target) 
         || !living(target)
         || environment(target)!=environment(me))
                return notify_fail(WHT"��ʥ���ѧ��ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);

        if((int)me->query_skill("shenghuo-ling", 1) < 180 )
                return notify_fail(WHT"���ʥ�������̫ǳ������ʹ�á�\n"NOR);

        if((int)me->query_skill("jiuyang-shengong", 1) < 120 )
                return notify_fail(WHT"��ľ����񹦹���̫ǳ������ʹ�á�\n"NOR);

        if (!me->query("jiuyangok"))
                return notify_fail("����Ȼ��˵�������񹦿����ƵУ��������á�\n");

        if((int)me->query_skill("qiankun-danuoyi", 1) < 180 )
                return notify_fail(WHT"���Ǭ����Ų�ƹ���̫ǳ������ʹ�á�\n"NOR);
                                
        if((int)me->query("max_neili") < 2500 )
                return notify_fail(WHT"�������̫ǳ������ʹ�á�\n"NOR);

        if((int)me->query("jing") < 100 )
                return notify_fail(WHT"��ľ�����������ʹ�á�\n"NOR);

        if((int)me->query("neili") < 500 )
                return notify_fail(WHT"�����������������ʹ�á�\n"NOR);

        if (me->query_temp("shlf_ji", 1))
                return notify_fail(WHT+target->name()+"�Ѿ�����ġ������־����Ի�����Է��ĵĹ����ˡ�\n"NOR);

        if (!objectp(weapon = me->query_temp("weapon"))
         || weapon->query("skill_type") != "sword"
         || me->query_skill_mapped("sword") != "shenghuo-ling"
         || me->query_skill_mapped("force") != "jiuyang-shengong"
         || me->query_skill_mapped("parry") != "qiankun-danuoyi"
         )
                return notify_fail(WHT"�㲻��ʹ��������У�\n"NOR);
                 


        me->add("neili", -400);
        me->add("jing", -20);
        if(!me->query_temp("ling")){
          me->set_temp("shlf/sh", 1); 
          me->add_temp("apply/attack", f);
          me->add_temp("apply/damage", j);
        }
        

        message_vision(HIM"\n$NͻȻ���ȼ�ɨ��������´�Ƭɳʯ������һ��Ϊ����ǰ��л����������У�\n" NOR, me);
msg = YEL "$N���ȼ�ɨ һ��Ϊ����\n" NOR;
if (!target->is_busy()) target->start_busy(2);
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
//        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        if (present(target,environment(me)) && me->is_fighting(target))
msg = HIY "$N����ɳʯ ǰ��л���\n" NOR;
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
//        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);

        if (present(target,environment(me)) && me->is_fighting(target)) {
          msg = CYN"\n$n����ʱ֮�䣬������ѩ���棬˫�۲��ܼ��ãȻ��֪���룬$N������"YEL"�粿"CYN"�ӱ�����$nײȥ��\n"NOR;
if (random(me->query("combat_exp")) > target->query("combat_exp")/3 && living(target)){
            damage = (int)me->query_skill("force");  //�Ի����ڹ��;����񹦵ĸߵͣ�ȡ��ɱ�����Ĵ�С��
            damage = damage + random(damage);
            damage +=(int)me->query_skill("jiuyang-shengong", 1);
if (damage < target->query("qi") || userp(target))
{
            target->receive_damage("qi", damage*2);
            target->receive_wound("qi", damage);
}
            msg += HIR"���$n��$N��"YEL"�粿"HIR"һײ�����������ܵ�һ���ش�����ǰ��������������\n"NOR;
            p = (int)target->query("qi")*100/(int)target->query("max_qi");
            msg += "( $n"+eff_status_msg(p)+" )\n";
          }
          else{
            dodge_skill = target->query_skill_mapped("dodge");
            if( !dodge_skill ) dodge_skill = "dodge";
            msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
          }
          message_vision(msg, me, target);
        }
        else {

          if( me->query_temp("shlf/sh")){
            me->add_temp("apply/attack", -f);
            me->add_temp("apply/damage", -j);   
            me->delete_temp("shlf/sh");
          }
          me->start_busy(2);

          return 1;
        }
        if(present(target,environment(me)) && me->is_fighting(target)){
          msg = CYN"\n$N����$n��ȥʽ������"HIR"Ǭ����Ų����"CYN"���굽$n����ǰ��������������$n�ĸ�����ȥ��\n"NOR;
          if (random(me->query("combat_exp")) > target->query("combat_exp")/3 && living(target)){
            me->start_busy(2);
            damage = (int)me->query_skill("force");  //�Ի����ڹ��;����񹦵ĸߵͣ�ȡ��ɱ�����Ĵ�С��
            damage +=(int)me->query_skill("shenghuo-ling", 1);
            damage +=(int)me->query_skill("jiuyang-shengong", 1);
            damage = damage + random(damage/2);
if (damage < target->query("qi") || userp(target))
{
            target->receive_damage("qi", damage*2);
            target->receive_wound("qi", damage);
}
            msg += HIR"���$nһ���Һ���$N�ѽ�$n��"HIY"��������"HIR"���飬��������$n��"HIY"С��"HIR"����$n���߹Ǹ����ʶϣ�\n"NOR;
            p = (int)target->query("qi")*100/(int)target->query("max_qi");
            msg += "( $n"+eff_status_msg(p)+" )\n";
          }
          else {
            me->start_busy(1);
            dodge_skill = target->query_skill_mapped("dodge");
            if( !dodge_skill ) dodge_skill = "dodge";
            msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
          }
          message_vision(msg, me, target);
        }
        else {

          if( me->query_temp("shlf/sh")){
            me->add_temp("apply/attack", -f);
            me->add_temp("apply/damage", -j);   
            me->delete_temp("shlf/sh");
          }
          me->start_busy(2);

          return 1;
        }

        if( me->query_temp("shlf/sh")){
          me->add_temp("apply/attack", -f);
          me->add_temp("apply/damage", -j);   
          me->delete_temp("shlf/sh");
        }
        me->start_busy(2);
        return 1;
}
