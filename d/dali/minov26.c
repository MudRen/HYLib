//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�˴�ɽ����խ����ľ�ر�ï�ܣ�ɽ��̤������С�����ݺύ���
��ľ�ڵ��谭�ţ���·�߲�ͣ���õ�������·������˳��ǰ��������
��ɽ������������ʱ�������޾��ߣ�ż�����ܿ��������Ŀ�ȸ�ɹ���
LONG
        );

	set("exits", ([
		"northeast" : __DIR__"minov21",
		"southup" : __DIR__"minov27",
		]));

//	set("objects", ([
//		"/d/foshan/npc/zsnake.c" : 1,
//		]));

	set("outdoors","dali");
	set("cost", 5);
	setup();
}
