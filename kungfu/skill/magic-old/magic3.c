// invocation.c
#include <ansi.h>
inherit F_SSERVER;
#define MAX_GUARD 15
int perform(object me, object target)
{
	object soldier;
	int	spells;

        spells = me->query_skill("spells");
        if(spells < 30 )
                return notify_fail("��ķ��������ߣ�\n");

	if( !me->is_fighting() )
		return notify_fail("ֻ��ս���в����ٻ��콫��\n");
	
	if( (int)me->query("neili") < 100 )
		return notify_fail("��ķ��������ˣ�\n");

	if( (int)me->query("jing") < 60 )
		return notify_fail("��ľ����޷����У�\n");
        if( me->query_temp("max_guard") > MAX_GUARD )
		return notify_fail("���Ѿ��ٻ�̫����������ˣ�\n");
        if (present("yin long",environment(me)))
		return notify_fail("���Ѿ��ٻ����ˣ�\n");

	message_vision(HIM"$N"HIM"�૵����˼��������\n", me);

	me->add("qi", -20);
	me->receive_damage("jing", 20);

	if( random(me->query("max_jing")) < 100 ) {
		message("vision", "����ʲ��Ҳû�з�����\n", environment(me));
		return 1;
	}

	seteuid(getuid());
	if( random(spells) > (spells/2))
		soldier = new("/d/migong/lev15/npc/lev4");
	else
		soldier = new("/d/migong/lev15/npc/lev4");
message_vision(HIB"$N"HIB"�������,һ���޴�Ļ��������ˣ���\n", me);
	soldier->move(environment(me));
	soldier->invocation(me, spells);
	soldier->set("possessed", me);
	me->add_temp("max_guard",1);
	return 1;
}
