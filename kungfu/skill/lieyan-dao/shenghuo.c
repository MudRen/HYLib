// guangming.c  ʥ�����

#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";
inherit F_SSERVER;


string *xue_name = ({ 
"�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
"����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",
}); 

string *limb=({
"����","����","����","ͷ��","С��","�ؿ�","����","�ɲ�","�Ҽ�","�ұ�","�ҽ�",
});

int perform(object me, object target)
{
        object weapon;
        int damage,p;
        string msg,name,dodge_skill,limbs;

        if(!target) target = offensive_target(me);

        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("��ʥ�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
         ||(string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");
                
        if((int)me->query_skill("lieyan-dao", 1) < 100 )
                return notify_fail("������浶��������죬����ʹ�á�ʥ���������\n");
                                        
        if ((int)me->query_skill("jiuyang-shengong", 1) < 120)
                return notify_fail("��ľ����񹦻��̫ǳ��\n");
                        
//        if((int)me->query_skill("piaoyi-shenfa", 1) < 100 )
//                return notify_fail("���Ʈ���������ߣ�����ʹ�á�ʥ���������\n");

        if((int)me->query("max_neili", 1) < 800 )
                return notify_fail("���������Ϊ����������ʹ�á�ʥ���������\n");

        if( me->query_skill_mapped("blade") != "lieyan-dao")
                return notify_fail("�����ڵ�״̬�޷�ʹ�á�ʥ���������\n");

        if ((int)me->query("neili",1) < 500)
                return notify_fail("��������������޷�ʹ�á�ʥ���������\n");

        msg = HIC"\n$N���һ����"HIR"Ϊ�Ƴ���Ω�����ʣ�ϲ�ֱ���Թ鳾��"HIC"��"+weapon->query("name")+HIC"���˺϶�Ϊһ����������ɱ������$n��\n"NOR;

        if(((random(me->query("combat_exp",1)) > target->query("combat_exp",1)/4)
         &&(random(me->query_skill("blade")) > target->query_skill("parry")/4 ))
         ||!living(target)){
              limbs= limb[random(sizeof(limb))];
              msg +=CYN"$nֻ����������·��������˵�ɱ�����֣����޿ɱܣ����ɴ�ʧɫ����ʱ��ǰһ����"+weapon->query("name")+CYN"�Ѵ���"+limbs+"����������\n"NOR;
              damage = (int)me->query_skill("blade");
              damage += (int)me->query_skill("dodge");
              damage *= 2;
              if(damage > 2500) damage = 2500;
              target->receive_damage("qi", damage);
              target->receive_wound("qi", damage/3);
              me->add("neili", -damage/4);
              me->add("jing", -20);
              p = (int)target->query("qi")*100/(int)target->query("max_qi");
              msg += "( $n"+eff_status_msg(p)+" )\n";
         if( random(5)>2          && me->query_skill("sougu",1 ) > 100
          && me->query_skill_mapped("claw") == "sougu"
          && me->query_skill_prepared("claw") == "sougu"){
              name = xue_name[random(sizeof(xue_name))];
              msg += HIC"\n$N��������ǰһ�����˶Է�����֮�ʣ����ֱ���Ϊӥצ֮�ƣ���������ץ��$n��"+name+"��\n"NOR;
           if( random(me->query_skill("claw")) > target->query_skill("dodge")/2
            ||!living(target) ){
               me->add("neili", -150);
               target->start_busy((int)me->query_skill("lieyan-dao")/30 + 1);
               msg +=CYN"���$n��"+name+"��ץ�����ţ�ȫ����������һ������ʱ���ɶ�����\n"NOR;
           }
           else{
               dodge_skill = target->query_skill_mapped("dodge");
               if( !dodge_skill ) dodge_skill = "dodge";
               msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
               me->add("neili", -50);
           }
           message_vision(msg, me, target);
//           me->start_perform(5,"��ʥ�������");
           me->start_busy(2);
           return 1;         
         }
         }
        else{
              dodge_skill = target->query_skill_mapped("dodge");
              if( !dodge_skill ) dodge_skill = "dodge";
              msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
              me->add("neili", -100);
              me->start_busy(2);
        }
        message_vision(msg, me, target);
//        me->start_perform(4,"��ʥ�������");
        return 1;
}
