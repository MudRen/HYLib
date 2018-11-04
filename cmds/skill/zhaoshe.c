#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object soldier;
	int zhaosheshu,yangsheshu, exp, MAX_GUARD;
        if ( me->is_busy() )
        return notify_fail("��������æ���޷������������ߡ�\n");
        if( !me->is_fighting() )
        return notify_fail("����û����Ҫɱ�㣡\n");
	if((int)me->query("neili")< 50)
	return notify_fail("�������̫���ˣ�\n");
	if((int)me->query("combat_exp")< 100000)
	return notify_fail("��ľ��鲻����\n");
        if( me->is_busy() )
        return notify_fail("����æ���أ�\n");   
	zhaosheshu = (int)me->query_skill("zhaosheshu");
	yangsheshu = (int)me->query_skill("yangsheshu");
	exp = (int)me->query("combat_exp");
	if(zhaosheshu < 10 || yangsheshu < 10)
	return notify_fail("������֮��������֮��̫���ˣ�û���߹�����\n");	
	MAX_GUARD = zhaosheshu * yangsheshu / 5000 + 1;
        if ((int)me->query_condition("zdizi_busy"))  
        return notify_fail("����й���.\n");

	if( me->query_temp("max_guard") > 30 )
                return notify_fail("�������ڵ����������Ѿ�û���������Ƹ�������ˣ�\n");
	seteuid(getuid());
        me->add("neili",-50);
	soldier= new("clone/misc/jinshe");
	soldier->move(environment(me));
        soldier->invocation(me, (zhaosheshu+yangsheshu));
        soldier->set("possessed", me);
        soldier->set("combat_exp",me->query("combat_exp")/2);
        soldier->set("str",me->query("str"));
        soldier->set("dex",me->query("dex"));
        soldier->set("max_qi",me->query("max_qi"));
        soldier->set("qi",me->query("max_qi"));
        soldier->set("eff_qi",me->query("max_qi"));
        soldier->set("neili",me->query("max_qi"));
        soldier->set("max_neili",me->query("max_qi"));
        soldier->set("eff_jing",me->query("max_jing")/2);
        soldier->set("max_jing",me->query("max_jing")/2);
        soldier->set("jing",me->query("max_qi")/2);
        soldier->set_skill("unarmed",zhaosheshu);
        soldier->set_skill("parry",yangsheshu);
        soldier->set_skill("dodge",zhaosheshu);
        soldier->set("apply/attack",zhaosheshu/2);
        soldier->set("apply/defense",yangsheshu/2);
        soldier->set("apply/damage",zhaosheshu);
        soldier->set("apply/armor",yangsheshu);
        me->add_temp("max_guard",1);
//        me->remove_all_killer();
	me->apply_condition("zdizi_busy",3);
	message_vision(HIR "\n$N����һ���ֽ� ��\n" NOR, me);	
	message_vision(HIR "\n$N�Ӹ������˳�����\n" NOR, soldier);
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��alert
 
���ָ���û����ߵĵ��Ӻ��������Ľ����������Լ���
�ܷ��к������ߣ���������ˮƽ�ĸߵ;�Ҫ���Լ�
��ˮƽ�ˡ�
 
HELP
    );
    return 1;
}
