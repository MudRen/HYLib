#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int check_pfm(object me, object target, object ob);
int perform(object me, object target)
{
	object soldier,weapon;
	int zhaosheshu,yangsheshu, exp, MAX_GUARD;
        if ( me->is_busy() )
        return notify_fail("��������æ���޷����������");
        if( !me->is_fighting() )
        return notify_fail("����û����Ҫɱ�㣡\n");
	if((int)me->query("neili")< 300)
	return notify_fail("�������̫���ˣ�\n");
	zhaosheshu = (int)me->query_skill("huagang-dafa");
	yangsheshu = (int)me->query_skill("xuantian-strike");
	exp = (int)me->query("combat_exp");
//	if(huagang-dafa < 10 || chousui-zhang < 10)
//	return notify_fail("�������书̫������������л��棡\n");	
	MAX_GUARD = zhaosheshu * yangsheshu / 5000 + 1;
	if( me->query_temp("max_guard") > MAX_GUARD )
                return notify_fail("�������ڵ����������Ѿ�û���������Ƹ���Ļ����ˣ�\n");
	seteuid(getuid());
	me->add("neili",-150);
	soldier= new("d/xingxiu/obj/huoyan");
	soldier->move(environment(me));
//        soldier->invocation(me, (zhaosheshu+yangsheshu));
//        soldier->set("possessed", me);
        me->add_temp("max_guard",1);
//        me->remove_all_killer();
	message_vision(RED "\n$N��ȫ�������ע����ϣ����ŵ���һָ..\n" NOR, me);	
	message_vision(RED "\n$N����������\n" NOR, soldier);
	return 1;
}
