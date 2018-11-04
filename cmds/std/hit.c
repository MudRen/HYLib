// fight.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj, old_target;

        if (userp(me) && !query_heart_beat(me))
        {
         "/cmds/usr/quithy"->main(me);
return notify_fail("������û�������������µ�½!!\n");
        }

	if( environment(me)->query("no_fight") )
		return notify_fail("�����ֹս����\n");

	if( environment(me)->query("outdoors")=="12gong" )
		return notify_fail("��12���ڲ�����ʹ��������\n");

	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("���빥��˭��\n");

	if( !obj->is_character() )
		return notify_fail("�����һ�㣬�ǲ��������\n");

        if (me->is_fighting()) 
        return notify_fail("���������������!\n");

	if(obj->query_temp("no_kill"))
		return notify_fail("�㲻��ɱ����ˡ�\n");

     if( obj->query("env/no_fight") )
        return notify_fail("���ܴ򣬴򲻵ð���\n");

	if( obj->is_fighting(me) )
		return notify_fail("���ͣ����ͣ����ͣ�\n");

        if (userp(obj) && !query_heart_beat(obj))
        {
         write("������ʲô��\n");
        return notify_fail("������������\n");
        }

	if( me->query_temp("hitting") )
		return notify_fail("���ͣ����ͣ����ͣ�\n");
	if(obj==me)	return notify_fail("���Լ�������ô�벻����\n");

    if(me->is_busy())
        return notify_fail("��������æ��û��ɱ�ˡ�\n");

    if(obj->is_fighting())
        return notify_fail("�Ǹ������ڴ�����!\n");

if(obj->query_temp("owner/id") && obj->query_temp("owner/id") != me->query("id"))
		return notify_fail("����˺ͱ��˵������йأ��㲻��ɱ����ˡ�\n");

    if(me->is_fighting())
        return notify_fail("���������ͱ��˴����� ��û��ɱ�ˡ�\n");

	if((int)me->query("age") <= 17 && userp(obj))
		return notify_fail("�����ڻ���С���ӣ����ܶ���ҷ��𹥻�!\n");

	if(me->query("combat_exp") < obj->query("combat_exp")/2  && userp(obj))
		return notify_fail("����˼Ҳ���ô�࣬��ʲô��?\n");

	if((int)obj->query("age") <= 17 && userp(obj))
		return notify_fail("Ϊ����������ã��Ź�С���Ӱ�.\n");
//	if( !userp(obj) || wizardp(obj) )
//		return notify_fail("ֻ�ܶ����ʹ�á�\n");

//pk
    if( userp(obj)  && me->query_condition("killer"))
        return notify_fail("���Ѿ���ͨ���ˣ���Ҫ����ɱ����ˣ�\n");
    if( userp(obj) && obj->query("combat_exp") < me->query("combat_exp") && me->query_condition("killer"))
        return notify_fail("���Ѿ���ͨ���ˣ���Ҫ����ɱ����ˣ�\n");

if( !living(obj) && userp(obj) && obj->query("combat_exp")/2 > me->query("combat_exp") )
	return notify_fail("����Ҫɱ���ˣ���������ǿ̫�࣬�㲻�Ҷ��֡�\n");

if( obj->query("combat_exp") > 5000000 && userp(obj) && (obj->query("combat_exp")-2000000) > 
me->query("combat_exp") )
	return notify_fail("����˼Ҳ���ô�࣬��ʲô��?\n");

//��սϵͳ
        if (userp(me) && userp(obj)
         && obj->query_temp("nokill") )
        return notify_fail("������������ս�ƣ�\n");

        if (userp(me) && userp(obj)
         && me->query_temp("nokill") )
        return notify_fail("����������ս�ƣ�\n");

    if( userp(me) && userp(obj) && obj->query_condition("nokill")
    && !obj->query_condition("killer"))
        return notify_fail("�Ǹ��˸ձ�ɱ�����Ź����ɣ�\n");
if( !living(obj) && userp(obj) && obj->query("combat_exp")/2 > me->query("combat_exp") )
	return notify_fail("����Ҫɱ���ˣ���������ǿ̫�࣬�㲻�Ҷ��֡�\n");

if( obj->query("combat_exp") > 5000000 && userp(obj) && (obj->query("combat_exp")-2000000) > 
me->query("combat_exp") )
	return notify_fail("����˼Ҳ���ô�࣬��ʲô��?\n");
	if( userp(obj) ) {
		message_vision("\n$N����$n���һ�������У�\n\n", me, obj);
		me->set_temp("hitting");
		remove_call_out("do_hit");
		call_out("do_hit", 1, me, obj);
		return 1;
	}

	if( obj->query("can_speak") ) {
		message_vision("\n$N����$n���һ�������У�\n\n", me, obj);
if( (int)obj->query("jing") * 100 / (int)obj->query("max_jing") >= 90
||(int)obj->query("qi") * 100 / (int)obj->query("max_qi") >= 90 ) 
{
		me->fight_ob(obj);
		obj->fight_ob(me);
if (!userp(obj))
{
              obj->set("neili",obj->query("max_neili"));
}
}
else {
        me->fight_ob(obj);
        obj->fight_ob(me);
		me->kill_ob(obj);
		obj->kill_ob(me);
if (!userp(obj))
{
              obj->set("neili",obj->query("max_neili"));
}
}
		me->fight_ob(obj);
		obj->fight_ob(me);
                me->start_busy(2);
	} else {
		message_vision("\n$N���һ������ʼ��$n����������\n\n", me, obj);
        me->fight_ob(obj);
        obj->fight_ob(me);

		me->kill_ob(obj);
		obj->kill_ob(me);
                me->start_busy(2);
	}

	return 1;
}

void do_hit(object me, object obj)
{
	if(objectp(present(obj, environment(me)))) {
		me->fight_ob(obj);
                obj->fight_ob(me);
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
		COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
	}
        me->start_busy(2);
	me->delete_temp("hitting");
	return;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : hit <����>
 
���ָ������ֱ����һ��������С���������ʽ��ս���Ǽ�ʱ�ģ�ֻҪ���һ
��������ս���ͻῪʼ��ֱ��ĳһ������50% ����Ϊֹ�����ָ�����Щ��
ϲ��fight��NPC�����ã���Ϊ�ܶ�ʱ����ı���Ҫ��ᱻ�ܾ���
 
�������ָ��: fight, kill

HELP
    );
    return 1;
}
 
