// liandu.c ��Һ��ҩ

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        mapping p;
	string msg;
        object ob;
        int amount;
        int exp;
	int lvl,b1,b2;
 
        if (! target)
		return notify_fail("��Ҫȡ�����ߵĶ�Һ��ҩ��\n");

        if ( target->query("race")!="Ұ��")
                return notify_fail("�����Щ���ǲ����ߣ���Ϲ��ʲô��\n");

	if( strsrch(target->query("name"), "��")<0)
                return notify_fail("�����Щ���ǲ����ߣ���Ϲ��ʲô��\n");		
        //if ( target->query("name")!="Ұ��")
        //        return notify_fail("�����Щ���ǲ����ߣ���Ϲ��ʲô��\n");
	if( target->query("owner"))
                return notify_fail("�����Щ���ǲ����ߣ���Ϲ��ʲô��\n");		

        if (living(target))
                return notify_fail("�����߻��������أ�����������\n");
                
                
        if (living(target))
                return notify_fail("�����߻��������أ�����������\n");

	if ((int)me->query_skill("shedu-qiqiao", 1) < 80)
		return notify_fail("����߶����ɻ��������, �������ƶ�ҩ !\n");

        if( (int)me->query_skill("wudu-shengong",1) < 50 )
                return notify_fail("����嶾����Ϊ��������\n");

	if ((int)me->query("neili") < 200)
		return notify_fail("�����ڵ�����������\n");

        me->add("neili", -50);
        me->start_busy(random(3));

        msg = HIG "\n$N���˫ָ����ס" +
              target->name() + "����ͣ��������ȳ���Һ��ҩ��\n" NOR;

        p = target->query("snake_poison");
        lvl = (int) me->query_skill("poison", 1) / 2 +
              (int) me->query_skill("shedu-qiqiao", 1);


        target->apply_condition("poison-supply", 1);

        if (random(3)==1)
        {
                msg += WHT "$N���˰��죬���ɶҲû�м����������ǰ�æ���ˡ�\n\n" NOR;
                message_vision(msg, me);
destruct(target);
                return 1;
        }

        if (random(3)==1)
        {
                msg += WHT "$N����һ�㶾Һ������\n\n" NOR;
                message_vision(msg, me);
                tell_object(me, "��ϧ��㶾Һ����һ�Ŷ�ҩ��������\n");
destruct(target);
                return 1;
        }

        msg += HIM "$N��" + target->name() + "�Ķ�ҺϤ����������������"
               "�����»�����һ�ž�Ө��͸��ҩ�衣\n\n" NOR;
        message_vision(msg, me);
        tell_object(me, "��������һ���߶�ҩ�衣\n");
destruct(target);
        // improve skill
        exp = lvl / 5;
        me->improve_skill("poison", 2 + exp + random(exp));
	if (me->can_improve_skill("shedu-qiqiao"))
        	me->improve_skill("shedu-qiqiao", 2 + exp + random(exp));

	if (me->can_improve_skill("wudu-shengong"))
        	me->improve_skill("wudu-shengong", 2 + exp / 6 + random(exp / 6), 1);

        // create the object
        ob = new("/clone/misc/shedu");
        ob->set("poison", ([
                "level" : lvl,
                "id"    : me->query("id"),
                "name"  : "�߶�",
                "duration" : 10,
        ]));
        ob->move(me);
b1=8+random(18);
b2=8+random(18);
me->add("combat_exp", b1);
me->add("potential", b2);
message_vision("$N�ľ������"+chinese_number(b1)+"�㡣\n", me);
message_vision("$N��Ǳ�ܼ���"+chinese_number(b2)+"�㡣\n", me);

	return 1;
}
