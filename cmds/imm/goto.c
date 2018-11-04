// goto.c
//����2000/4/8
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int goto_inventory = 0;
	object obj;
	string msg;

	if( !arg ) return notify_fail("��Ҫȥ���\n");

	if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;

	if( !arg ) return notify_fail("��Ҫȥ���\n");

	obj = find_player(arg);
	if(!obj) obj = find_living(arg);
	if(!obj || !me->visible(obj)) {
		arg = resolve_path(me->query("cwd"), arg);
		if( !sscanf(arg, "%*s.c") ) arg += ".c";
		if( !(obj = find_object(arg)) ) {
			if( file_size(arg)>=0 )
				return me->move(arg);
			return notify_fail("û�������ҡ������ط���\n");
		}
	}

	if(!goto_inventory && environment(obj))
		obj = environment(obj);

	if( !obj ) return notify_fail("������û�л������� goto��\n");

//    if( stringp(msg = me->query("env/msg_mout")) )
//        message_vision(msg+"\n", me);
//	else
//		message_vision(HIW"ֻ��һ�����ε�"HIM"�ǹ�"HIW"����֮��$N����Ӱ��Ϊһ�����Ƿ����ˡ�����һ����ʫ������⡣\n"NOR, me);

	me->move(obj);

//	if( stringp(msg = me->query("env/msg_min")) )
//        message_vision(msg+"\n", me);
//	else
//		message_vision(HIW"��ͻȻ������߷����˿����ǣ����ų���������������$N����ӰͻȻ������"HIM"�ǹ�"HIW"֮�С�\n"NOR, me);

	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : goto [-i] <Ŀ��>
 
���ָ��Ὣ�㴫�͵�ָ����Ŀ��. Ŀ�������һ��living �򷿼�
�ĵ���. ���Ŀ����living , ��ᱻ�Ƶ����Ǹ���ͬ���Ļ���.
����м��� -i ������Ŀ���� living, ����ᱻ�Ƶ��� living ��
�� inventory ��.
 
HELP
    );
    return 1;
}
