// touxi.c ͵Ϯ
// by King 97.05

#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object obj;
	int skill, count;

        if (userp(me) && !query_heart_beat(me))
        {
         "/cmds/usr/quithy"->main(me);
         write("������û�������������µ�½!!\n");
        }

	if( environment(me)->query("no_fight") )
		return notify_fail("�����ֹս����\n");

	if( environment(me)->query("outdoors")=="12gong" )
		return notify_fail("��12���ڲ�����ʹ��������\n");

	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("����͵Ϯ˭��\n");

	if( !obj->is_character() )
		return notify_fail("�����һ�㣬�ǲ��������\n");

        if (me->is_fighting()) 
        return notify_fail("���������������!\n");

	if( obj->is_fighting(me) )
		return notify_fail("���Ѿ���ս�����ˣ�����͵Ϯ��\n");

	if( !living(obj) )
		return notify_fail(obj->name() + "���Ѿ������ˣ��㻹�õ���͵Ϯ��\n"); 

	if((int)obj->query("age") <= 19 && userp(obj))
		return notify_fail("Ϊ����������ã��Ź�С���Ӱ�.\n");

	if(obj->query("tasknpc"))
		return notify_fail("����͵Ϯ˭��\n");

	if(obj->query_temp("no_kill"))
		return notify_fail("�㲻��ɱ����ˡ�\n");
	if(obj->query("no_touxi"))
		return notify_fail("͵Ϯ�۷��ʲô?\n");
//	if(me->query("combat_exp") < obj->query("combat_exp")/3  && userp(obj))
//		return notify_fail("����˼Ҳ���ô�࣬��ʲô��?\n");

	if(obj==me)
		return notify_fail("͵Ϯ�Լ�������ô�벻����\n");

if(obj->query_temp("owner/id") && obj->query_temp("owner/id") != me->query("id"))
		return notify_fail("����˺ͱ��˵������йأ��㲻��ɱ����ˡ�\n");

	if( me->is_busy() )
		return notify_fail("��Ķ�����û����ɣ�����͵Ϯ��\n");
//pk
    if( userp(obj) && me->query_condition("killer"))
        return notify_fail("���Ѿ���ͨ���ˣ���Ҫ����ɱ����ˣ�\n");
    if( userp(obj) && obj->query("combat_exp") < me->query("combat_exp") && me->query_condition("killer"))
        return notify_fail("���Ѿ���ͨ���ˣ���Ҫ����ɱ����ˣ�\n");

       if( userp(me) && userp(obj) && obj->query("combat_exp")/2 > me->query("combat_exp") )
	return notify_fail("����Ҫɱ���ˣ���������ǿ̫�࣬�㲻�Ҷ��֡�\n");

	
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


	
        me->fight_ob(obj);
        obj->fight_ob(me);
        me->fight_ob(obj);

	me->start_busy(2);
	tell_object(me, "�������������" + obj->name() +"��\n");
	tell_object(obj, CYN"\n" + me->name() + "��Ȼ����������\n\n"NOR);
	message("vision", CYN"\n" + me->name() + "��Ȼ��" + obj->name() +"��ȥ��\n\n"NOR, environment(me), ({me, obj}) );

	count = me->query_str();

	if( random(me->query("combat_exp")) < (int)obj->query("combat_exp")/2 )
	{
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
	me->start_busy(3);
	}

	else
	{
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
	me->start_busy(3);
	}


	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : touxi <����>
 
���ָ�����������͵Ϯ��͵Ϯ����ʱ���������������
�ر��ʺ��ھ���͵��������ߵ����������:)

�������ָ��: fight, kill, hit
HELP
    );
    return 1;
}                                                                                                                                                                                                                                                                                                                    