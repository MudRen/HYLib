// ң����� (by xbd)

#include <ansi.h>

inherit SKILL;

string *cmds = ({"give", "wield", "unwield", "wear", "remove", "enable", "jifa", "prepare", "bei", "exert",
"yun", "perform", "yong", "enforce", "jiali", "ask", "drop", "l", "look", "go","say"});

void do_control(object me, object ob, string cmd);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object ob;
	string type, cmd;
	int i, flag = 0;

	if (!me->query("guard/flag"))
		return notify_fail("ƾ�����ڵ���������û���ʸ�ӵ������أ�\n");
	
	if (!me->query("guard/active"))
		return notify_fail("�����ڻ�û���չ���ӣ������Ҫ�Ļ������Ե�������ʿ����ȥҪһ����\n");

	if (!(ob = me->query_temp("guard_ob")))
		return notify_fail("�����ڻ�û���ٻ�����أ�\n");

	if (!arg || arg == "")
		return notify_fail("����ң������ʲô��\n");

	if ((sscanf(arg, "%s %s", type, cmd) < 2 ))
		type = arg;
	
	for (i = 0; i < sizeof(cmds); i++)
		if (cmds[i] == type) {
			flag = 1;
			break;
		}
	if (!flag)
		return notify_fail("����ң������ʲô��\n");

	if (me->is_busy())
		return notify_fail("����æ���أ�\n");

	if (me->query("neili") < 500)
		return notify_fail("�������ڵ��������޷�ʩչ����ͨ��\n");
	if (me->query("jing") < 200)
		return notify_fail("�������ڵľ������޷�ʩչ����ͨ��\n");
	if (ob->query("neili") < 500)
		return notify_fail("�������ڵ��������޷������Ӧ��\n");
	if (ob->query("jing") < 200)
		return notify_fail("�������ڵľ������޷������Ӧ��\n");

	message_vision(HIM"$N��Ŀڤ˼����ͼ�������$n��ͨ��\n"NOR, me, ob);
	me->start_busy(3);
	me->add("neili", -500);
	me->add("jing", - 200);
	call_out("do_control", 2, me, ob, arg);	
		
	return 1;

}

void do_control(object me, object ob, string cmd)
{
	message_vision(HIG"�����ģ�$N��������$n��ϣ����ڴﵽ����ͨ�ľ��磡\n"NOR, me, ob);
	message_vision(HIG"$N�ƺ��ܵ���$n�ĸ��٣�����͸¶��һ˿���ص�Ц�ݣ�\n"NOR, ob, me);
	ob->add("neili", -500);
	ob->add("jing", - 200);
	exec(ob, me);
	ob->force_me(cmd);
//	me->force_me(cmd);
	exec(me, ob);
	message_vision(HIG"$N������һɢ������������һ������\n"NOR, me, ob);
}

int help(object me)
{
	write(@HELP
ָ���ʽ : zhaohuan
 
���ָ����������ٻ������ӡ�
 
HELP
    );
    return 1;
}
