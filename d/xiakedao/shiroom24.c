// /d/xiakedao/shishi24.c ���͵� ʯ��24

inherit ROOM;

//int do_study(string arg);
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
������谵��ֻ������������ľ������ϥ���ڽ���֮�ϣ����
ʯ��(wall)�������˼����ʯ������ɽ�������ȴ�����ߴ����
���½����ˡ����л�������������Ķ�����֮�ࡣ
LONG );
        set("exits", ([
                "east" : __DIR__"shihole6",
        ]));
        set("item_desc", ([
                "wall" : @WALL
ǽ�����Ϸ����š�����̫�������������֡��ֵ��·��̵�����������
������ģ���ǧ�������������������룬����������ֱ��б����
�µĴ�Ƭ�������һ���ѷִ���ίʵ���Ա��ϡ�
WALL
        ]));
        set("objects", ([
                CLASS_D("xiakedao")+"/long" : 1,
                CLASS_D("xiakedao")+"/mu"   : 1,
        ]));
        set("no_clean_up", 0);
        set("no_fight", 1);
        set("no_beg", 1);
        setup();
}

void init()
{
        add_action("do_study","think");
}
int do_study(string arg)
{
        object me, where;
        int jing_cost, learn_pot, item, times, i, success=0;
        string skillname;

        me = this_player();
        if( !arg ) return notify_fail("��Ҫ����ʲôѽ��\n");
	if( sscanf(arg, "%s %d", arg, times)!=2)
		return notify_fail("ָ���ʽ��think wall <����>\n");
        if( ( arg != "wall" ) )
		return notify_fail("ָ���ʽ��think wall <����>\n");
	if (times < 1 || times > 20)
		return notify_fail("�����������һ�Σ����Ҳ���ܳ�����ʮ�Ρ�\n");
        if ((int)me->query("combat_exp")<500000)
                return notify_fail("��ľ���̫��, û������ʯ�����ݡ�\n");
        if ((int)me->query_skill("literate",1)<1)
                return notify_fail("�����˰�! ������ȥѧ���Ļ��ɡ�\n");
        jing_cost = 30 + random(me->query_int());
        if( me->query("jing") < jing_cost * times)
                return notify_fail("������̫���ˣ���������ô��Σ���Ϣһ��������ɡ�\n");

        message_vision("$N��������ʯ���ϵ�ͼ����ע�͡�\n",me);
	for (i = 1; i<=times; i++)
	{
		me->receive_damage("jing",jing_cost);
//		if (!me->query_skill("taixuan-gong"))
//		{
//			write("������ʯ��ڤ˼������һ�ᣬ��������Ķ���������˵̫����ˡ�\n");
//			return 1;
//		}
		if (me->query_skill("taixuan-gong",1)>=250)
		{
			write("������ʯ��ڤ˼������һ�ᣬ��������Ķ���������˵̫ǳ���ˡ�\n");
			return 1;
		}
		else
		{
			if( !SKILL_D("taixuan-gong")->valid_learn(me) )
			return SKILL_D("taixuan-gong")->valid_learn(me);
		}
		if((int)(me->query_skill("taixuan-gong",1) * 
			me->query_skill("taixuan-gong",1) * 
			me->query_skill("taixuan-gong",1)) /5 >= me->query("combat_exp"))
		{
			write("�����ʯ��ڤ˼������һ�ᣬ�����ջ�\n");
			return 1;
		}
		learn_pot = (int)(me->query("combat_exp")/10000) + random(me->query("int"))
			- (int)(me->query_skill("literate",1)/2);
		if (learn_pot > 0)
		{
			me->improve_skill("taixuan-gong", learn_pot);
			success=1;
		}
	}
	if (success == 1)
		write("�����ʯ��ڤ˼������"+chinese_number(times)+"�أ��ƺ�"+CHINESE_D->chinese("taixuan-gong")+"��Щ�ĵá�\n");
	else write("�����ʯ��ڤ˼������һ�ᣬ��������̫��ƺ�ûɶ�ĵá�\n");
	success=0;
	return 1;
}

