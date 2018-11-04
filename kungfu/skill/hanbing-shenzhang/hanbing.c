// snowman

#include <ansi.h>
inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
        string msg, dodge_skill;
        int p;
        
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) 
        || !living(target))
                return notify_fail("�㲻��ս���С�\n");
               
        if(me->query_temp("weapon"))
                return notify_fail("�������ֲ���ʹ�õĺ������ơ�\n");
        if( (int)me->query_skill("hanbing-shenzhang", 1) < 150 )
                return notify_fail("��ĺ���������Ϊ������\n");

        if( (int)me->query_skill("force", 1) < 150 )
                return notify_fail("��Ļ����ڹ���Ϊ������\n");
 

 
        if (me->query_skill_prepared("strike") != "hanbing-shenzhang"
        || me->query_skill_mapped("strike") != "hanbing-shenzhang")
                return notify_fail("��û�����ú������ƣ�\n");
                
        if( me->query("max_neili") <= 3500 )
                return notify_fail("���������Ϊ������\n");
                
        if( me->query("neili") <= 1000 )
                return notify_fail("�������������\n");

        if( me->query("shen") > -10000 )
                return notify_fail("��ѧ��������Ҳ���ˣ�������ʹ���������֮������\n");
                
        if( target->query_condition("cold_poison") || me->query("hanbing_target") == target->query("id"))
                return notify_fail("�������������к������㲻���ٶ��һ���ˡ�\n");

        message_vision(BLU "\n$N����������ʮ����ġ�����������ע��ʳָ֮�ϣ����Ŵ����������ָһ�죬�ɵ�$n���ؿڣ�\n\n" NOR, me,target);
        me->add("neili", -350);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")*6/11){ 
             me->add("max_neili", - (1+random(3)));
             message_vision("���$n�ٲ���������$Pһָ������ǰ��Ѩ�ϣ�\n", me, target);
             if( me->query_skill("hanbing-shenzhang", 1) < target->query_skill("hanbing-shenzhang", 1) * 2){
                 tell_object(me, HIR "��һָ����" +target->query("name") +"�ؿڣ����ϴ��˾�ȻҲ���к������ƣ���������ָ����Ч�ˡ�\n"NOR);
                 tell_object(target, HIY "��ֻ��һ�ɺ���Ϯ�أ�����ȫ���˹�����Ȼ��ס�˺�������Ϯ��\n" NOR);
                 return 1;
                 }
             else {
                 tell_object(me, BLU "��һָ����" +target->query("name") +"�ؿڣ������������ֿ���������˳�������Ѩ��ֱ�ƹ�ȥ��" +target->query("name") +"���ڡ�\n"NOR);
                 tell_object(target, HIW "��ֻ��һ�ɺ���Ϯ�أ�����ȫ���˹�������һ˲֮�䣬�����ѽ���ȫ������\n"NOR);
                 target->receive_damage("qi", me->query_skill("strike")*2);
                 target->receive_wound("jing", me->query_skill("hanbing-shenzhang",1));
                 target->apply_condition("cold_poison", me->query_skill("hanbing-shenzhang", 1)*2);
                 //target->apply_condition("no_force", me->query_skill("hanbing-shenzhang", 1)/10);
                 p = (int)target->query("qi")*100/(int)target->query("max_qi");
                 msg = damage_msg(me->query_skill("strike"), "����");
                 msg += "( $n"+eff_status_msg(p)+" )\n";          
                 message_vision(msg, me, target);
                 return 1;
                 }
        }
        else {
             dodge_skill = target->query_skill_mapped("dodge");
	     if( !dodge_skill ) dodge_skill = "dodge";
             message_vision(SKILL_D(dodge_skill)->query_dodge_msg(target, 1), me, target);
        }
        me->start_busy(2+random(3));
        return 1;
}
