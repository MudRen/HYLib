inherit ROOM;

void create()
{
  set("short","����");
  set("long",@LONG
���������ң���Ϊ���ơ����������ǰ��������Ϸ��Ÿ�ʽ����ǩ
��ǩ��qian)�����λ�÷��У���������Ű��԰��ϡ�
LONG);
  set("outdoors","yinju");
set("exits",([
   "north"  : __DIR__"maowu",
      ]));
  set("item_desc", ([
                "qian" : "ͨ����ǩ������ѧϰһ�����Ź���study)��\n",
]));
  setup();
}
void init()
{
        add_action("do_study","study");
}
int do_study(string arg)
{
        object me = this_player();

	if (arg != "qian" && arg != "bei")
		return 0;

	if (me->is_busy())
      {
		write("��������æ���ء�\n");
		return 1;
	}

	if( me->is_fighting() )
       {
		write("���޷���ս����ר�������о�ǩ�ϵ����֣�\n");
		return 1;
	}

	if (me->query("jing") < 30) {
		write("��̫���ˣ��޷����о������о�ǩ�ϵ����֡�\n");
		return 1;
	}
	if (me->query_skill("count", 1) > 60) 
      {
		write("����ϸ�ض���һ��ǩ�ϵ����֣������Ѿ�̫ǳ���ˣ��޷�ѧ���µ�֪ʶ��\n");
		return 1;
	}
	
	me->receive_damage("jing", 25);
	message_vision("$N��ϸ��ע������ǩ������λ�á�\n", me);
	write("�������������֮ѧ���˽�һ������ʶ��\n");
	me->improve_skill("count", me->query("int") / 2 + random(me->query("int") / 2));
	return 1;
}
