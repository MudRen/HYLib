// Room: /d/gaochang/shulin14.c

inherit ROOM;




void create()
{
	set("short", "�߲��Թ�");
	set("long", @LONG
������������ĳ���,��ǰ���������������
�Թ�֮�ڲ����㼣ָ�����㲻֪��Ҫ������·�ߡ�
����ϸ���������ף����׺�ǰ������·�϶��е������㼣��
���ƺ���ʧ�˷�����ûͷ��Ӭ�㵽���Ҵ���
LONG
	);

	set("exits", ([
		"east" : __DIR__"shulin"+(random(10)+2),
		"south" : __DIR__"kongdi",
		"west" : __DIR__"shulin8",
		"north" : __DIR__"shulin"+(random(10)+2),
	]));

        set("no_acc_drop",1);
	set("outdoors", "gaochang");
	setup();
	replace_program(ROOM);
}



