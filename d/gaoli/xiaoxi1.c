// /d/gaoli/xuanwumen
// Room in ����
inherit ROOM;

int do_jump(string arg);

void create()
{
	set("short", "СϪ");
	set("long", @LONG
����һ����ɽ����������Ϫ����СϪ����������һԾ�ƺ��Ϳɱ�
���԰���Ϫ����������ݳ��ü���ïʢ����������֮�У�����������
����Ϫ����ˮ���峺�����������Ŀ���ˮ�׵Ķ��Ѻ������ζ���С�㡣
һ�������С·��֪��ͨ�����
LONG
	);

	set("exits", ([
				

                "southdown":__DIR__"xiaoxi",
	]));
	set("objects",([
	   "/clone/npc/man":2,
	]));

	set("outdoors", "/d/gaoli");
	setup();
      
}

void init()
{
	
	add_action("do_jump", "jump");
	add_action("do_jump", "yue");
}

int do_jump(string arg)
{
	object me = this_player();

	if (arg == "river" || arg == "xiaoxi") {
		if (me->query_skill("dodge", 1) >= 200) {
			message("vision", me->name() + "���˿��������������Ծȥ��\n",
				environment(me), ({me}) );
			write("�����˿��������������Ծȥ��\n");
			me->move(__DIR__"xiaoxi");
			message("vision", "ֻ����Ӱһ����" + me->name() +  "����Ծ�˹�����\n",
				environment(me), ({me}) );
			
			return 1;
		}
		else {
			message("vision", me->name() + "���������Ծȥ��ֻ������ͨ��һ����" + me->name() + "ˤ��Ϫ�У��Ǳ������˻�����\n",
                                environment(me), ({me}) );
			write("�����������Ծȥ��ֻ������ͨ��һ������ˤ��Ϫ�У��Ǳ������˻�����\n");
                        me->receive_damage("qi",30);
                        return 1;
		}
	}
	return 0;
}




