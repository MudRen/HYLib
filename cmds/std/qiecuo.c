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

	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("���빥��˭��\n");

	if( !obj->is_character() )
		return notify_fail("�����һ�㣬�ǲ��������\n");

  
  
        if (userp(me) && userp(obj)
         && obj->query_temp("nokill") )
        return notify_fail("������������ս�ƣ�\n");

        if (userp(me) && userp(obj)
         && me->query_temp("nokill") )
        return notify_fail("����������ս�ƣ�\n");

    if( userp(me) && userp(obj) && obj->query_condition("nokill")
    && !obj->query_condition("killer"))
        return notify_fail("�Ǹ��˸ձ�ɱ�����Ź����ɣ�\n");

        
    if( userp(obj) && me->query_condition("killer"))
        return notify_fail("���Ѿ���ͨ���ˣ���Ҫ����ɱ����ˣ�\n");
    if( userp(obj) && obj->query("combat_exp") < me->query("combat_exp") && me->query_condition("killer"))
        return notify_fail("���Ѿ���ͨ���ˣ���Ҫ����ɱ����ˣ�\n");

  
        if (!userp(me)){
        if( obj->query_temp("no_kill") )
        return notify_fail("���ܴ򣬴򲻵ð���\n");
        }
	if( obj->is_fighting(me) )
		return notify_fail("���ͣ����ͣ����ͣ�\n");

	if( !living(obj) )
		return notify_fail(obj->name() + "�Ѿ��޷�ս���ˡ�\n"); 

	if(obj==me)	return notify_fail("�㲻�ܹ����Լ���\n");

        if (userp(obj) && !query_heart_beat(obj))
        {
         write("������ʲô��\n");
        return notify_fail("������������\n");
//         write("���˲���beg��\n");
        }


	if( userp(obj) && (object)obj->query_temp("pending/fight")!=me ) {
		message_vision("\n$N����$n˵����" 
			+ RANK_D->query_self(me) 
			+ me->name() + "�����"
			+ RANK_D->query_respect(obj) + "�ĸ��У�\n\n", me, obj);
		if( objectp(old_target = me->query_temp("pending/fight")) )
			tell_object(old_target, YEL + me->name() + "ȡ���˺�����Ե���ͷ��\n" NOR);
		me->set_temp("pending/fight", obj);
		tell_object(obj, YEL "�����Ը��ͶԷ����б��ԣ�����Ҳ��" + me->name() + "("+(string)me->query("id")+")"+ "��һ�� fight ָ�\n" NOR);
		write(YEL "���ڶԷ�������ҿ��Ƶ���������ȶԷ�ͬ����ܽ��б��ԡ�\n" NOR);
		return 1;
	}

	if( obj->query("can_speak") ) {
		message_vision("\n$N����$n˵����" 
			+ RANK_D->query_self(me) 
			+ me->name() + "�����"
			+ RANK_D->query_respect(obj) + "�ĸ��У�\n\n", me, obj);

		notify_fail("������" + obj->name() + "��������������\n");
		if( !userp(obj) && !obj->accept_fight(me) ) return 0;

		me->fight_ob(obj);
		obj->fight_ob(me);
	} else {
		message_vision("\n$N���һ������ʼ��$n����������\n\n", me, obj);
		me->fight_ob(obj);
		obj->kill_ob(me);
	}

	return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : fight <����>
 
���ָ��������һ������ֽ̡������ǡ��д����ա���������ʽ��ս��������
�㵽Ϊֹ�����ֻ����������������������ˣ����ǲ��������е�  NPC ��ϲ��
��ܣ���������״����ı���Ҫ��ᱻ�ܾ���
 
�������ָ��: kill

PS. ����Է���Ը����������ս������Ȼ���������� kill ָ�ʼս������
    �� fight �� kill �������뿴 'help combat'.
HELP
    );
    return 1;
}
 
