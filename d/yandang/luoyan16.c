// Room: /d/yandang/luoyan16
inherit ROOM;
int jian=5,dao=5,fu=5,tongjia=5,gangjia=5;

void create()
{
  set ("short", "������");
  set ("long", @LONG
����ׯ��ϲ����Ѱ���¸�������,��������ɽׯ������ڽ�����һֱ
����Ʒ����ȫ������,�������,����һ���ŵļ���,��������˸��ָ�����
����,�������������˵������.���������(list)�鿴һ��,Ȼ����ȡ(naqu).
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"luoyan9",
]));
  setup();
}
void init()
{
	add_action("do_list","list");
	add_action("do_naqu","naqu");
}

int do_list()
{
	string msg;
	object me;
	me=this_player();
	if(! living(me))	return 0;
	msg="Ŀǰ�ⷿ����������Ʒ������ȡ(naqu)\n";
	msg +="----------------------------------\n";
	if( jian)
	msg +="  ����(jian)             "+chinese_number(jian)+"��\n";
	if( dao)
	msg +="  ����(dao)              "+chinese_number(dao)+"��\n";
	if(fu)
	msg +="  �師(fu)               "+chinese_number(fu)+"��\n";
	if(tongjia)
	msg +="  ͭ��(tongjia)          "+chinese_number(tongjia)+"��\n";
	if(gangjia)
	msg +="  �ּ�(gangjia)          "+chinese_number(gangjia)+"��\n";
	msg +="----------------------------------\n";
	write(msg);
	return 1;
}

int do_naqu(string arg)
{
	object me,sth;
	mapping data;
	me=this_player();
	if(! living(me))	return 0;
	if(! arg)	return notify_fail("��Ҫ��ȡʲô��\n");
	if(me->query("family/family_name")!="�㵴��")
		return notify_fail("������˼ҵĶ������ðɡ�\n");
	if( me->query_temp("have_naqu"))
		return notify_fail("���Ѿ��ù���ѽ,��һ�������ɡ�\n");
	if(arg=="jian" && jian)	{
		sth=new("/obj/weapon/sword");
		if( me->query_encumbrance() + sth->query_weight()
			> me->query_max_encumbrance())
		return notify_fail("��ѽ��������̫���ˡ�\n");
		jian --;
		sth->move(me);
		message_vision("$N�Ӽ��������˰ѳ�����\n",me);
	}	else if(arg=="dao" && dao)	{
		sth=new("/obj/weapon/blade");
                if( me->query_encumbrance() + sth->query_weight()
                        > me->query_max_encumbrance())
		return notify_fail("��ѵ��������̫���ˡ�\n");
                dao --;
		sth->move(me);
		message_vision("$N�Ӽ��������˰ѵ�����\n",me);
	}	else if(arg=="fu" && fu)	{
		sth=new("/obj/weapon/banfu");
                if( me->query_encumbrance() + sth->query_weight()
                        > me->query_max_encumbrance())
		return notify_fail("��Ѹ��������̫���ˡ�\n");
                fu --;
		sth->move(me);
		message_vision("$N�Ӽ��������˰Ѱ師��\n",me);
	}	else if(arg=="tongjia" && tongjia) {
sth=new("/obj/std/armor/tongjia");
                if( me->query_encumbrance() + sth->query_weight()
                        > me->query_max_encumbrance())
		return notify_fail("���ͭ�׶������̫���ˡ�\n");
                tongjia --;
		sth->move(me);
		message_vision("$N�Ӽ��������˼�ͭ�ס�\n",me);
	}	else if(arg=="gangjia" && gangjia) {
sth=new("/d/yeyangzai/npc/obj/gangjia");
                if( me->query_encumbrance() + sth->query_weight()
                        > me->query_max_encumbrance())
		return notify_fail("����ּ׶������̫���ˡ�\n");
                gangjia--;
		sth->move(me);
		message_vision("$N�Ӽ��������˼��ּס�\n",me);
	}	else	return notify_fail("���û������������\n");
	sth->set("no_sell",1);
	me->set_temp("have_naqu",1);
	return 1;
}
