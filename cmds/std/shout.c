// shout.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !wizardp(me) )
{
if (me->query("neili") <4000)
		return notify_fail("����������㡣\n");
if (me->query("combat_exp") < 2000000)
		return notify_fail("��ľ��鲻�㲻�㡣\n");
if (me->query_condition("killer"))
 return notify_fail("����ͨ������������ˡ�\n");
if (me->is_busy())
 return notify_fail("����æ���ء�\n");
me->add("neili",-1000);
me->start_busy(12);
}

	if (!arg) return notify_fail("����Ҫ���ʲô��\n");
        shout(HIW + me->name() + "������Х��" + arg + "\n" + NOR);
        write(HIW +"��������Х��" + arg + "\n" + NOR);
	return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : shout <ѶϢ>
 
���ָ�����㽫 <ѶϢ> ���ͳ�ȥ, ����������Ϸ�е��˶�
��������Ļ�.
 
see also : tune
HELP
    );
    return 1;
}
 
