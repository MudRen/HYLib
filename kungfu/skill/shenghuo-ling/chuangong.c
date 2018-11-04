#include <ansi.h>

inherit F_SSERVER;
void remove_effect(object me, int i);

int perform(object me, object target)
{
        int skill;

        if(!objectp(target)) return notify_fail("��Ҫ������˭��\n"); 
        if(target == me)
                return notify_fail("��Ҫ������˭��\n");                
        if((int)me->query("neili") < 500  ) 
                return notify_fail("�������������\n");
        if((int)target->query_temp("yinfeng") > 2) 
                return notify_fail("�Է��Ѿ������ٳ��ܸ���Ĺ����ˡ�\n");
        if((int)me->query_temp("chuangong"))
                return notify_fail("����Ѿ������ô����ˡ�\n");
        if((int)me->query_skill("force") < 150 )
                return notify_fail("����ڹ��ȼ������������ܴ��������ˡ�\n");
        if((int)me->query_skill("shenghuo-shengong", 1) < 100 )
                return notify_fail("���ʥ���񹦵ȼ������������ܴ��������ˡ�\n");
        if((int)me->query("max_neili") < 1000 )
                return notify_fail("�������������ǿ�������ܴ��������ˡ�\n");
        if((int)me->query("neili") < 500 )
                return notify_fail("������������ˣ����ܴ��������ˡ�\n");
        if((int)target->query_skill("shenghuo-shengong", 1) < 130 )
                return notify_fail("�Է���ʥ���񹦵ȼ����������ܽ����������Ĺ�����\n");
        skill = me->query_skill("force")/3;
        me->add("neili", -400);
        me->receive_damage("qi", 150);
        me->receive_damage("jing", 150);
        me->receive_damage("jing", 150);
        message_vision(HIR"\n$N����������$n���Ĵ�Ѩ�ϣ�����"RED"���"HIR"ʱ��ʱ�ԣ�����������$n��\n\n"NOR, me, target);
        target->add_temp("yinfeng", 1);
        me->set_temp("chuangong", 1);
        tell_object(target, YEL+me->name()+"�Ĺ���������������ڣ����ÿ���������ǿ���絶��������\n"NOR);
        me->start_call_out( (: call_other, this_object(), "remove_effect", me :), skill);
        target->start_call_out( (: call_other, this_object(), "remove_effect", target, 1 :), skill);              
        if(userp(me))
            me->start_busy(10);
        else me->start_busy(5);
        return 1;
}

void remove_effect(object me, int i)
{        
	if(i) me->delete_temp("chuangong");
	else{
            me->add_temp("yinfeng", -1);
            tell_object(me, YEL"\n�����ڱ��˵Ĺ����Ѿ����꣬���絶�����ָֻ������ˣ�\n"NOR);
            }
}
