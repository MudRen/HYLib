// lead.c
// write by ccbwh 98.3.10
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg ) return notify_fail("ָ���ʽ��lead <ĳ��>��\n");


	if( !objectp(ob = present(arg, environment(me))) )
		return notify_fail("����û�� " + arg + "��\n");

	if( !ob->is_character() )
		return notify_fail("ʲô�������...." + ob->name() + "��\n");

	if( ob==me )
		return notify_fail("�����Լ���\n");
	if (me == ob->query_leader())
          	return notify_fail( ob->name() + "�Ѿ��������ˡ�\n");

	message_vision("\n$N����$n˵�����������߰ɣ��Ҵ���ȥ���ط���\n" , me , ob );

	write( YEL +"\n�����ȶԷ�ͬ��������ŶԷ��ߡ�\n" NOR );
	
        tell_object( ob, YEL + "\n�����Ը�����" + me->name() + "һ���ж�,����� follow " 
		+ me->query("id") + " ���\n" NOR );

	return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ : lead [<����>]
 
���ָ������Ҫ��ĳ�˻���������ߡ�
 
HELP
);
        return 1;
}
