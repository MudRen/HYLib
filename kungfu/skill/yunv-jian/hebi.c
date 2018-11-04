// hebi.c
// by dubei

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
private int remove_effect(object me, int skill);
int perform(object me, string arg)
{
    object weapon, weapon1, target;
    object victim;
    int skill, skill1;

    if(!arg) return notify_fail("�����˭һ��˫����赣�\n");
    if(!objectp(target = present(arg, environment(me))))
             return notify_fail("����û������ˡ�\n");

        if( !victim ) victim = offensive_target(me);

        if( !victim || !victim->is_character() || !me->is_fighting(victim) )
                return notify_fail("˫��������һ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");


    if(!living(target))
                return notify_fail(target->name()+"�Ѿ��޷�ս���ˡ�\n"); 
    if(target==me) return notify_fail("����Լ���赣�\n"); 
    if(me->is_fighting(target))
                return notify_fail("�����ں�"+target->name()+"����ء�\n");            

    weapon = me->query_temp("weapon");  
    weapon1 = target->query_temp("weapon");  

    if(!weapon || weapon->query("skill_type") != "sword"
      || me->query_skill_mapped("sword") != "yunv-jian"
      )
        return notify_fail("��Ҫ����Ů����Ϊ���������á�˫����赡���\n");

    if(me->query_skill_mapped("force") != "yunv-xinfa" )
        return notify_fail("��Ҫ����Ů�ķ���Ϊ�ڹ������á�˫����赡���\n");
    if(me->query_skill_mapped("force") != "yunv-xinfa" )
        return notify_fail("��Ҫ����Ů�ķ���Ϊ�ڹ������á�˫����赡���\n");
if (me->query("gender")=="����")
        return notify_fail("һ��һŮ����˫����赡�\n");

if (me->query("gender")=="����" && target->query("gender")=="����")
        return notify_fail("һ��һŮ����˫����赡�\n");
if (me->query("gender")=="Ů��" && target->query("gender")=="Ů��")
        return notify_fail("һ��һŮ����˫����赡�\n");
        
    if(!weapon1 || weapon1->query("skill_type") != "sword"
      || target->query_skill_mapped("sword") != "yunv-jian"
      )
        return notify_fail(target->name()+"Ҫ����Ů����Ϊ���������á�˫����赡���\n");

    skill = me->query_skill("yunv-jian", 1);
    skill1 = target->query_skill("yunv-jian", 1);
    
    if(skill < 160 )
        return notify_fail("�����Ů�����ȼ�����������ʹ�á�˫����赡���\n");
    
    if( skill1 < 160 )
	return notify_fail( target->name()+"����Ů�����������죬�޷��������ʹ�á�˫����赡���\n");

    if((int)me->query_skill("yunv-xinfa", 1) < 160 )
        return notify_fail("�����Ů�ķ��ȼ�����������ʹ�á�˫����赡���\n");       

    if((int)target->query_skill("yunv-xinfa", 1) < 160 )
        return notify_fail(target->name()+"����Ů�����������죬�޷��������ʹ�á�˫����赡���\n");       
    
    if((int)me->query("neili") < 300 )
        return notify_fail("����������̫��������ʹ�á�˫����赡���\n");

    if((int)target->query("neili") < 300 )
        return notify_fail( target->name()+"��������̫��������ʹ�á�˫����赡���\n");

    if((int)me->query("max_neili") < 500 )
        return notify_fail("����������̫��������ʹ�á�˫����赡���\n");

    if((int)target->query("max_neili") < 500 )
        return notify_fail(target->name()+"��������̫��������ʹ�á�˫����赡���\n");

    if(me->query_temp("gumu_hebi")) 
        return notify_fail("���Ѿ���ʹ�á�˫����赡��ˡ�\n");

    if(target->query_temp("gumu_hebi")) 
        return notify_fail(target->name()+"�Ѿ���ʹ�á�˫����赡��ˡ�\n");
    
    if(me->query_temp("gmhebi_target")){
          if(me->query_temp("gmhebi_target")==target)
                return notify_fail("���Ѿ����ú�"+target->name()+"˫����赵�׼���ˡ�\n");
          else{               
               tell_object(me->query_temp("gmhebi_target"), YEL+me->name()+"�������������˫������ˡ�\n"NOR); 
               me->delete_temp("gmhebi_target");
               }
          }
    if(target->query_temp("prepare_gmhebi")) {
	message_vision(HIC"$N��Хһ����������"+weapon->name()+HIC"һ�ڣ��������$nһ���źš�\n"NOR,me,target);
        message_vision(HIC"$n������"+weapon1->name()+HIC"һ�ڣ�����$N��"+weapon->name()+HIC"�ϣ�˫����ӣ���ʱ��â���䣬������أ�\n"NOR,me,target);
        me->delete_temp("prepare_gmhebi", 1);     
        me->delete_temp("gmhebi_target", 1);
        me->set_temp("gumu_hebi", target); 
        target->set_temp("gumu_hebi", 1); 
        me->add("neili", -300);
        target->add("neili", -300);
        me->add("jing", -50);
        target->add("jing", -50);
        me->add_temp("apply/attack", skill);
        me->add_temp("apply/dexerity", skill/15);
        target->add_temp("apply/attack", skill1);
        target->add_temp("apply/dexerity", skill1/15);
if (random(3)==0) target->start_busy(5);
message_combatd(HIC "$N"HIC"��$n" HIC "��������һ����������"
                        "Ȼ��ͨ�����ɵĻ���һЦ��ֻ����������һ����ʱ\n"
                        "�Ѿ���" + victim->name() + HIC"�������У�\n" NOR,
                        me, target);
        target->start_busy(5);
        message_vision(HIG"$Nʹ��"HIW"��Ů����!"HIG" ��ߴ�һ����\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
        message_vision(HIC"$nʹ��"HIR"ȫ�潣��!"HIC" �ұߴ�һ������\n" NOR,me,target);
        COMBAT_D->do_attack(target, victim, target->query_temp("weapon"));
        message_vision(HIG"$Nʹ��"HIW"��Ů����!"HIG" �ϱߴ�һ����\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
        message_vision(HIC"$nʹ��"HIR"ȫ�潣��!"HIC" �±ߴ�һ������\n" NOR,me,target);
        COMBAT_D->do_attack(target, victim, target->query_temp("weapon"));
        message_vision(HIG"$Nʹ��"HIW"��Ů����!"HIG" �ߴ�����һ����\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
if (me->query("qi") < me->query("max_qi"))
{
message_vision(HIC"$N���˺�����˺ܶ࣡��\n" NOR,me,target);
me->add("qi", me->query("max_qi")/3);
if (me->query("eff_qi") < me->query("max_qi"))
me->add("eff_qi", me->query("max_qi")/3);
}
if (target->query("qi") < target->query("max_qi"))
{
message_vision(HIC"$n���˺�����˺ܶ࣡��\n" NOR,me,target);
target->add("qi", target->query("max_qi")/3);
if (target->query("eff_qi") < me->query("max_qi"))
target->add("eff_qi", me->query("max_qi")/3);
}


        me->start_call_out( (: call_other, __FILE__, "check_fight", me, target, skill :), 1);
        target->start_call_out( (: call_other, __FILE__, "check_fight", target, me, skill1 :), 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), (skill+skill1)/2);
        target->start_call_out( (: call_other, __FILE__, "remove_effect", target, skill1 :), (skill+skill1)/2);
        return 1;
        }
    message_vision(YEL"$N������"+weapon->name()+"һ�ᣬ��ʾ$n��$Pһ������˫����赡�\n"NOR,me,target);
    tell_object(target, YEL"�����Ը���"+me->name()+"����˫���ͱڣ���Ҳ��"+me->name()+"��һ�� ( perform hebi player<name> ) �����\n"NOR); 
    me->set_temp("prepare_gmhebi", 1);     
    me->set_temp("gmhebi_target", target);
    return 1;
}

void check_fight(object me, object target, int skill, int skill1)
{
    object weapon;      
    object victim;
        if( !victim ) victim = offensive_target(me);
if (victim && random(2)==0)
{
if (!target->is_busy()) target->start_busy(3);
        message_vision(HIG"$Nʹ��"HIW"��Ů����!"HIG"��ߴ�һ����\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
        message_vision(HIC"$nʹ��"HIR"ȫ�潣��!"HIC"�ұߴ�һ������\n" NOR,me,target);
        COMBAT_D->do_attack(target, victim, target->query_temp("weapon"));
if (me->query("qi") < me->query("max_qi"))
{
message_vision(HIC"$N���˺�����˺ܶ࣡��\n" NOR,me,target);
me->add("qi", me->query("qi")/6);
if (me->query("eff_qi") < me->query("max_qi"))
me->add("eff_qi", target->query("qi")/6);
}
if (target->query("qi") < target->query("max_qi"))
{
message_vision(HIC"$n���˺�����˺ܶ࣡��\n" NOR,me,target);
target->add("qi", target->query("qi")/6);
if (target->query("eff_qi") < me->query("max_qi"))
target->add("eff_qi", target->query("qi")/6);
}
}
    if(!objectp(weapon = me->query_temp("weapon")) 
     || !objectp(weapon = target->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword")
    {
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), 1);
    target->start_call_out( (: call_other, __FILE__, "remove_effect", target, skill :), 1);
    remove_effect(target, 1);
    remove_effect(me, 1);
	}
    else if( !present(target->query("id"), environment(me)) 
	  || !me->is_fighting() 
	  || !living(target) 
	  || !target->is_fighting()
          || target->is_ghost() 
	  || me->is_ghost() 
	  || !living(me)) {

    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), 1);
    target->start_call_out( (: call_other, __FILE__, "remove_effect", target, skill1 :), 1);
    remove_effect(target, 1);
    remove_effect(me, 1);
	}
    else {
	call_out("check_fight", 1, me, target, skill);
	 return;
	}
}
private int remove_effect(object me, object target)
{
    int skill, skill1;
     skill = me->query_skill("yunv-jian", 1);
    if(me->query_temp("gumu_hebi")) 
{
    me->delete_temp("gumu_hebi");
    me->delete_temp("gmhebi_target");
    me->delete_temp("prepare_gmhebi");     
   me->add_temp("apply/attack", -skill);
    me->add_temp("apply/dexerity", -skill/15);
	message_vision(HIR"$N˫�������ᣬ����Ҳ�ָ������ˡ�\n"NOR, me);
tell_object(me, "���˫�������ᣬ����Ҳ�ָ������ˡ�\n");
}
}
 