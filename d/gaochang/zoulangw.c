// Room: /d/gaochang/zoulang1.c

inherit ROOM;


string look_writing();


void create()
{
	set("short", "����");
	set("long", @LONG
�����ǵ������ȡ�����һ��֧������ĸ�ǽ�ϣ���һ������
���ߵ��õ��ݶ�����������������������Ҳ�ò�������˸���
�����ͼ�Σ�ÿ�����ƺ�������˵һ���渶��˵ķ𾭹��¡���
��ǽ������һ����(writing)��
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"wroom3",
		"northeast" : __DIR__"zoulang2",
	]));

	set("item_desc",([
		"writing"		:	(: look_writing :),
	]));
	setup();
}


string look_writing()
{
	return
	"\n"
"              ����������������������������������\n"
"              ��������������    ����������������\n"
"              ����������������    ��������������\n"
"              ����                          ����\n"
"              ����������  ����������  ����������\n"
"              ������������  ������  ������������\n"
"              ��������������  ��  ��������������\n"
"              ��������������    ����������������\n"
"              ������������  ����  ��������������\n"
"              ����������  ��������  ������������\n"
"              ������    ������������    ��������\n"
"              ��    ������������������    ������\n"
"              ����������������������������������\n"
"              ����������������������������������\n";
}

void init()
{
	add_action("do_study", "study");
}


int do_study(string arg)
{
	object me;
	int    jing_cost;

	me = this_player();

	if ( !arg || ( arg != "qiangbi" ) )
		return notify_fail("ʲô��\n");

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");

	jing_cost = 0;
	if((int)me->query("jing") < jing_cost)
		return notify_fail("�����ھ����޷����У�\n");

	me->add("jing", jing_cost);

	message_vision("$N��ר���ж�ǽ���ϵĹŹ�ͼ�Ρ�\n", me);

//	switch( random(5) ) 
//	{
//	    case 0:
		if ( (int)me->query_skill("literate", 1) < 100)
		{
			me->improve_skill("literate", me->query("int"));
			write("�����ǽ����ĥ��һ�ض����ƺ��Զ���ʶ���е��ĵá�\n");
			me->set_temp("stone_learned",1);
		}


	if ( !me->query_temp("stone_learned") )
	{
		write("�����ǽ����ĥ��һ�ض�������������˵��̫��ǳ�ԣ�������˵�Ѻ��������ˡ�\n");
	}
	return 1;
}