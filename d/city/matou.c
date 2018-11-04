// Room: /yanziwu/matou.c
// Date: Jan.28 2000 by Winder

#include <ansi.h>
#define MAX_EXP 80000
#define MIN_EXP 5000
inherit ROOM;
int do_go(string);
void create()
{
	set("short","��������ͷ");
	set("long",@LONG
���������ݳ���������ͷ���Ϸ�����ʳ�������������ڴ�ж����
������Ĺ�Ա��飬��ת�˻���ʱ���档������Ա���ӣ���С���ڽ�����
�й����ڰ����������й�Ա�ֳֳ����ڼ๤���м�����Ƥ��ת��תȥ��
��֪��Щʲô���⡣�ϱ߾��������𡣶����Ǵ�ʿ�֣��¿��˼��ҵ��̡�
    ����ͣ����һ���ʹ���
LONG );
	set("outdoors", "yangzhoue");
	set("worktimes", 20);
	set("exits", ([
		"north" : __DIR__"beiliuxiang",
		"south" : __DIR__"zhuqidian",
		"east"  : __DIR__"dashixijie",
		"west"  : __DIR__"ninghaiqiao",
	]));
	set("objects", ([
		__DIR__+"npc/jiangong" :1,
	]));
	set("coor/x", 40);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_work", ({"work", "ganhuo"}) );
}

int do_work()
{
	object me = this_player();
//	if ( query("worktimes") < 0)
//		return notify_fail("��ͷ�����ڲ���Ҫ�˸ɻ�´ΰɣ�\n");

	if (me->query("gender") == "Ů��") 
	return notify_fail("��ͷ�����ڲ���ҪŮ���ӼҸɻ\n");
//	if ( me->query_temp("working") )
//		return notify_fail("���Ѿ��ڸɻ��ˣ���\n");
	if ( !objectp( present ("jian gong", environment(me) ) ) )
		return notify_fail("��ͷ�����ڲ���Ҫ�˸ɻ�´ΰɣ�\n");
	if (me->query("combat_exp")<MIN_EXP)
	{
		tell_object(me,"���ﶼ���ػ�����ڻ��ɲ��ˡ�\n");
		return 1;
	}
	

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���أ�\n");
	if ( (int)me->query("jing") < 10 || (int)me->query("qi") < 10 )
	{
		message_vision(
"�๤����$N����һ���ӣ�$N���϶�ʱ����һ��Ѫ�ۣ�$N�������Ķ㵽һ\n"
"��ȥ�ˡ�����ģ���С���⸱ή�Ҳ�������ӻ���ɻ�������๤��\n"
"��������������\n", me);
		me->receive_damage("qi", 11);
		me->receive_wound("qi", 11);
		return 1;
	}
if (me->query_temp("working") >=1)
{
	write(""+me->query("name")+"����һ������������Ӳֿ�ᵽ����ͷ��\n");
}
else
{
	write("�๤�ñ���ָ��ָ��˵������ȥ���������ɡ���\n");
	write(""+me->query("name")+"����һ���������ʼ�ɻ\n");
}
	add("worktimes", -1);
	me->start_busy(5);
	me->add_temp("working",1);
//	remove_call_out("work_end");
if (me->query_temp("working") >=6)
	call_out("work_end", 1, me);

	return 1;
}

int work_end(object me)
{
	object ob1;
	int add_exp,add_pot,add_score;
	me->delete_temp("working");
	write("��������๤�ˣ�����һ���������۸�������\n"
"�๤����������"+me->query("name")+"�ļ��˵������С�ӣ������ģ�������Ĺ�Ǯ����\n");
	me->receive_damage("jing",me->query("jing")/8);
	me->receive_damage("qi",me->query("qi")/8);
	me->receive_damage("jing",10);
	me->receive_damage("qi",10);
		add_exp=3+random(3);
		add_pot=1+random(2);
		add_score=1+random(1);
		me->add("combat_exp",add_exp);
		me->add("potential",add_pot);
		me->add("score",add_score);
		ob1 = new("/clone/money/silver");
		ob1->set_amount(add_score);
		ob1->move(me);	
		tell_object(me,HIW"��õ���:"
			+ chinese_number(add_exp) + "��ʵս���飬"
			+ chinese_number(add_pot) + "��Ǳ�ܣ�"
			+ chinese_number(add_score) + "�㽭��������\n"NOR);				
	if ( me->query_temp("working") ) me->delete_temp("working");
	return 1;
}

