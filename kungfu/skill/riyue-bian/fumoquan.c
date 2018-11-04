#include <ansi.h>

inherit F_SSERVER;
int check_fight(object me, int amount, object weapon);
private int remove_effect(object me, int amount);
int perform(object me)
{
    object weapon = me->query_temp("weapon");  
    int skill;
    
    if(!me->is_fighting() )
                return notify_fail("����շ�ħȦ��ֻ����ս����ʹ�á�\n");

    if ( (int)me->query_skill("yijinjing", 1) < 150 )
        return notify_fail("����ڹ��ȼ�����������ʹ�á���շ�ħȦ����\n");
    
    if ( (int)me->query_skill("riyue-bian", 1) < 150 )
        return notify_fail("������±޷�������죬�����������ӡ���շ�ħȦ����\n");

	if((int)me->query_skill("hunyuan-yiqi",1) < 100)
		return notify_fail("���Ԫһ�����Ĺ�������!\n");
    
    if (!weapon || weapon->query("skill_type") != "whip"
    || me->query_skill_mapped("whip") != "riyue-bian")
        return notify_fail("�������޷�ʹ�á���շ�ħȦ������߷�������\n");
    
    if ( (int)me->query("neili") < 500 )
        return notify_fail("����������̫��������ʹ�á���շ�ħȦ����\n");
    
    if ( (int)me->query_temp("ryb_fumo") ) 
        return notify_fail("������ʹ�á���շ�ħȦ����\n");
    
//    if (me->query_skill_mapped("force") != "yijinjing")
//        return notify_fail("����ڹ������޷�ʹ�á���շ�ħȦ����\n");

    message_vision(HIY "$N��ʱһ���ߺȣ����������Ѫ��ɮ�۶���������������"+weapon->name()+"����ת���������ն̣���
���൱���ܡ�"+weapon->name()+"����������������ƻã����۵�����ô�������������Ǳ����˳�ȥ��\n"NOR, me);
    me->start_busy(2);
    me->add("neili", -300);          
    
    skill = me->query_skill("riyue-bian")/2;
    
    me->add_temp("apply/parry",  skill);
    me->add_temp("apply/attack",  skill/2);
    me->set_temp("ryb_fumo", 1);

    check_fight(me, skill, weapon);
    return 1;
}

int check_fight(object me, int amount, object weapon)
{  
    object wep;    
    if(!me) return 0;
    wep = me->query_temp("weapon");  
    if(!me->is_fighting() || !living(me) || me->is_ghost() || !wep || weapon != wep )
        remove_effect(me, amount);

    else {
	call_out("check_fight", 1, me, amount, weapon);
//	me->start_perform(1, "��ħȦ");
    }
    return 1;
}

private int remove_effect(object me, int amount)
{
    me->add_temp("apply/parry", -amount);
    me->add_temp("apply/attack", -amount/2);
    me->delete_temp("ryb_fumo");
    if(living(me) && !me->is_ghost())
      message_vision(GRN"���ã�$N��ʹ��շ�ħȦ����������ƽϢ��һ���ָֻ���ԭ״��\n"NOR, me);
    return 0;
}
